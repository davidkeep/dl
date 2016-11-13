//
//  CodeGen.cpp
//  Created by David on 8/22/16.
//

#include "CodeGen.h"
#include "Intrinsics.h"

//This isn't needed but it is nice to have demangled names
#include <cxxabi.h>
string DemangleCppAbi(const string& abiName)
{
  string retval;  
  int status;
  char *ret = abi::__cxa_demangle(abiName.c_str(), 0, 0, &status);  
  retval = string(ret);
  free(ret);
  return retval;
}

string CodeGen::CodeFor(Dec&decl){
    string r;
    if(typeid(decl) == typeid(DecVar))
    {
        DecVar &d = cast<DecVar>(decl);
        r += CodeFor(*d.type);
        if(d.ref)
            r += "&";
    }
    else if(typeid(decl) == typeid(DecAny))
    {
        DecAny &d = cast<DecAny>(decl);
        if(d.ref)
            r += "&";
        r += CodeFor(*d.type);
    }

    else if(typeid(decl) == typeid(StructDef))
    {
        StructDef &d = cast<StructDef>(decl);
        r = (d.ident);
        assert(!r.empty());
    }
    else if(typeid(decl) == typeid(IntrinsicStructDef))
    {
        IntrinsicStructDef &d = cast<IntrinsicStructDef>(decl);
        r = (d.ident);
        if(d.ident == "i64"){
            r = "i64";
        }
        if(d.ident == "i32"){
            r = "i32";
        }
        if(d.ident == "i16"){
            r = "i16";
        }
        if(d.ident == "i8"){
            r = "i8";
        }
        
        if(d.ident == "u64"){
            r = "u64";
        }
        if(d.ident == "u32"){
            r = "u32";
        }
        if(d.ident == "u16"){
            r = "u16";
        }
        if(d.ident == "u8"){
            r = "u8";
        }
        if(d.ident == "voidptr"){
            r = "voidptr";
        }
    }
    else if(typeid(decl) == typeid(DecPtr))
    {
        DecPtr &d = cast<DecPtr>(decl);
        r += CodeFor(*d.pointed);
        r += "*";
        if(d.ref)
            r += "&";
    }
    else if(typeid(decl) == typeid(DecList))
    {
        
        DecList &d = cast<DecList>(decl);
        if(!d.list.size()) return "void";
        
        for (auto decl : d.list) {
            r += CodeFor(*decl.dec);
            if(decl.dec->ref)
                r += "&";
        }
        auto &t = tuples[r];
        if(!t){
            t = &d;
        }
        return r;
    }
    else if(typeid(decl) == typeid(Variable))
    {
        Variable &d = cast<Variable>(decl);
        r = CodeFor(*d.type);
        if(d.ref)
            r += "&";
        r += " " + d.ident;
    }
    else if(typeid(decl) == typeid(DecGen))
    {
        DecGen &d = cast<DecGen>(decl);
        r = CodeFor(*d.type);
        if(d.ref)
            r += "&";
    }
    else if(typeid(decl) == typeid(Dec))
    {
        assert(false);
    }
    else{
        std::cout << typeid(decl).name() << '\n';
        assert(false && typeid(decl).name());
    }

//        if(typeid(decl) == typeid(FuncDecl))
//        {
//            FuncDecl &d = (FuncDecl&)decl;
//            r = "FnPtr";
//        }
    return r;
}

CodeGen::CodeGen(const string& file, Semantic &semantic):
out(file + ".cc"),
header(file + ".h"),
semantic(semantic)
{
    if(!out.is_open()){
        Print("Failed to open file '" + file + "'");
    }
    header << "#include \"" << cheaderFile << "\"\n";
    out << "#include \"" << file << ".h\"\n";
}

void CodeGen::IsUnhandled(Node &self) {
    out << "\"}";
}
void CodeGen::IsBlck(Blck &self) {
    level++;
    auto t = top;
    top = false;
    
    if(t){

        for(auto file : g_files){
           out << "#define f" << file.file << "__ \"" << get_working_path() << "/"<<  file.directory + file.name << "\"\n";
        }

        for(auto defi : semantic.defs){
            if(auto def = dynamic_cast<StructDef*>(defi)){
                header << "struct " << def->ident << ";\n";

            }
            if(auto tuple = dynamic_cast<ListDef*>(defi)){
                header << "struct " << CodeFor(*tuple->list) << ";\n";
            }
        }

        for(auto defi : semantic.defs){
            if(auto def = dynamic_cast<StructDef*>(defi)){
                if(def->Empty()) continue;
                header << "struct " << def->ident << "{\n";
                for(auto field : def->fields){
                    header <<'\t' <<CodeFor(*field->type) <<" " << field->ident<<";\n";
                }
                header << "};\n";
            }
            else if(auto tuple = dynamic_cast<ListDef*>(defi)){
                header << "struct " << CodeFor(*tuple->list) << "{\n";
                int i = 0;
                for(auto decl : *tuple->list){
                    header << '\t' << CodeFor(*decl.dec) << " " << "i" << i++ << ";\n";
                }
                header<< "};\n";
            }
            else if(auto def = dynamic_cast<IntrinsicStructDef*>(defi)){
            }
            if(typeid(Variable) == typeid(*defi)){
                auto decl = cast<Variable>(defi);
                out << CodeFor(*decl->type);
                out << " ";
                out << decl->ident;
                out << "=";
                if(decl->assign){
                    Visit(*decl->assign);
                }
                else{
                    out << "{0}";
                }
                out << ";\n";
            }
        }
                
        for(auto type : semantic.typeinfo){
                out << "TypeInfo " << type.def->ident << "=" << "{sizeof(" + CodeFor(*type.type) + ")};\n";
        }
        for(auto decl : semantic.varDefs){
            out << CodeFor(*decl->type);
            out << " ";
            out << decl->ident;
            out << "=";
            if(decl->assign){
                Visit(*decl->assign);
            }
            else{
                out << "{0}";
            }
            out << ";\n";
        }
    }
            
    if(!t) inset += '\t';
    for(auto node : self.children){

        bool nl = (typeid(*node) != typeid(IntrinsicStructDef) &&
            typeid(*node) != typeid(IntrinsicFuncDef) &&
            typeid(*node) != typeid(FuncDef) &&
            typeid(*node) != typeid(StructDef) &&
            (typeid(*node) != typeid(Variable) || !t));

        bool lineDirective = (typeid(*node) != typeid(IntrinsicStructDef) &&
            typeid(*node) != typeid(IntrinsicFuncDef) &&
            typeid(*node) != typeid(StructDef) &&
            (typeid(*node) != typeid(Variable) || !t));

        if(lineDirective && node->coord.file >= 0){
            out<<inset;
            out << "#line " << node->coord.line << " f" << String(node->coord.file) << "__ //" << DemangleCppAbi(typeid(*node).name()) << '\n';
        }

        out<<inset;
        if(typeid(*node) == typeid(Blck)) out << "{\n";

        Visit(*node);
        if(nl){
            out << ";\n";
        }

        if(typeid(*node) == typeid(Blck)){ out<<inset; out << "}\n";}
    }
    if(!t)
        inset = inset.substr(0, inset.size()-1);

    if(t)
    {
        header << fns.str();
    }
    level--;
}
void CodeGen::IsExprList(ExprList &self) {
    out << "{";
    for(int i = 0; i < self.list.size(); i++){
        self.list[i]->Visit(*this);
        if(i != self.list.size()-1){
            out << ",";
        }
    }
    out << "}";
}

void CodeGen::IsCast(struct Cast &cast) {
    out << "(";
    out << CodeFor(*cast.type);
    out << ")";

    Visit(*cast.expr);
}
void CodeGen::IsBinaryOp(BinaryOp &op) {
    if(op.fn){
        if(auto fn = dynamic_cast<IntrinsicFuncDef*>(op.fn)){
            // if(op.op == Op::Call){
            //     GenerateCodeFor(*fn, *(ExprList*)op.args);
            // }
            // else{
                GenerateCodeFor(*fn, *op.args);
            //}
        }
        else{
            out << op.fn->ident;
            if(!((FuncDef*)op.fn)->external)
                out << ((FuncDef*)op.fn)->id;
            auto &list = Cast<ExprList>(*op.args);
            out << "(";
            for(int i = 0; i < list.list.size(); i++){
                if(list.list[i]->type->IsType())
                    continue;
                
                list.list[i]->Visit(*this);
                if(i != list.list.size()-1){
                    out << ",";
                }
            }
            out << ")";
        }
    }
    else if(op.op == Lexer::Assign){
        Visit(*op.left);
        out << " = ";
        Visit(*op.right);
    }
    else if(op.op == Lexer::Dot){
        Visit(*op.left);
        if(typeid(RemoveSugar(*op.left->type)) == typeid(DecPtr))
            out << "->";
        else
            out << ".";
        if(dynamic_cast<DecList*>(op.left->type)){
            out << "i";
        }
        out << ((Var*)op.right)->name;
    }
    else{
        Assert(false, op, "");
    }
}
void CodeGen::IsUnaryOp(UnaryOp &op) {
    // if(op.op == Lexer::PointerOperator){
    //     out << "(*";
    //     Visit(*op.expr);
    //     out << ")";
    // }
    // else if(op.op == Lexer::AddressOperator){
    //     out << "(&";
    //     Visit(*op.expr);
    //     out << ")";
    // }
    // else 
    if(op.op == Lexer::Sub){
        out << "(-";
        Visit(*op.expr);
        out << ")";
    }
    else if(op.op == Lexer::Negated){
        out << "(!";
        Visit(*op.expr);
        out << ")";
    }
}

void CodeGen::IsStructDef(StructDef &def) {

}
void CodeGen::IsEnumDef(EnumDef &def) {
    
}
void CodeGen::IsFor(For &loop) {
    if(loop.from && loop.to){
        out << "for(";
        out << CodeFor(*loop.from->type);
        out << " " << loop.it;
        out << " = ";
        Visit(*loop.from);
        out << "; ";
        out << loop.it << "<";
        Visit(*loop.to);
        out << ";" << loop.it << "++){\n";
        Visit(*loop.body);
        out << inset << "}";
    }
    else{
        out << "while(";
        Visit(*loop.from);
        out << "){\n";
        Visit(*loop.body);
        out << inset << "}";
    }
}

void CodeGen::IsIf(If &ifStatement) {
    out << "if(";
    Visit(*ifStatement.condition);
    out << "){\n";
    Visit(*ifStatement.trueBody);
    out << inset << "}";
    if(ifStatement.falseBody)
    {
        out << "else{\n";
        Visit(*ifStatement.falseBody);
        out << inset << "}";
    }
}

void CodeGen::IsReturn(Return &ret) {
    out << "return ";
    if(ret.expr)
        Visit(*ret.expr);
}
            
void CodeGen::IsFuncDef(FuncDef &def) {
    if(def.generic){
        for(auto specialization : def.specializations){
            Visit(*specialization);
        }
        return;
    }
    
    string fn;
    if(!def.body){
        fn = "extern \"C\" ";
    }

    fn +=  CodeFor(def.results);
    if(def.results.ref){
        fn += "&";
    }
    
    fn += " ";
    
    if(def.ident == "Main"){
        fn += "main";
    }
    else if(!def.external){
        fn += def.ident;
        fn += String(def.id);
    }
    else
        fn += def.ident;

    fn += '(';
    if(def.args){
        for(auto i = 0; i < def.args->list.size(); i++){
            if(def.args->list[i].dec->IsType())
                continue;
            
            fn += CodeFor(*def.args->list[i].dec);
            fn += " ";
            fn += def.args->list[i].ident;
            
            if(i != def.args->list.size()-1){
                fn += ',';
            }
        }
    }
    
    fn += ")";
    fns << fn << ";\n";
    
    if(def.body){
        out << fn << "{\n";
        Visit(*def.body);
        out << "}\n";
    }
}
void CodeGen::IsVariable(Variable &decl) {
    if(level != 1){
        out << CodeFor(*decl.type);
        out << " ";
        out << decl.ident;
        out << "=";
        if(decl.assign){
            Visit(*decl.assign);
        }
        else{
            out << "{0}";
        }
    }
}
void CodeGen::IsVar(Var &var) {
    if(typeid(*var.def) == typeid(StructDef) || typeid(*var.def) == typeid(IntrinsicStructDef))
        return;

    
    out << var.def->ident;
}
void CodeGen::IsConstNumber(ConstNumber &num) {
    out << num.value;
}
            
void CodeGen::IsConstString(ConstString &str) {
    int characters = 0;
    for(int i = 0; i < str.value.size(); i++){
        if(str.value[i] != '\\'){
            characters++;
        }
    }
    out << "str{";
    out << characters;
    out << ",(u8*)\"";
    out << str.value;
    out << "\"}";
}

void CodeGen::IsIntrinsicFuncDef(IntrinsicFuncDef &def) {
}

void CodeGen::IsIntrinsicStructDef(IntrinsicStructDef &def) {
}
            
void CodeGen::GenerateCodeFor(IntrinsicFuncDef &def, ExprList&args){    
    if( &def == Instrinsic::addi    ||
        &def == Instrinsic::addi32  ||
        &def == Instrinsic::addu    ||
        &def == Instrinsic::addu32  ||
        &def == Instrinsic::addf    ||
        &def == Instrinsic::addf32
        )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "+";
        args.list[1]->Visit(*this);
        out << ")";
        return;
    }
    else  if(&def == Instrinsic::equalsi    ||
                &def == Instrinsic::equalsi32  ||
                &def == Instrinsic::equalsu    ||
                &def == Instrinsic::equalsu32  ||
                &def == Instrinsic::equalf32    ||
                &def == Instrinsic::equalf64
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "==";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::andi    ||
                &def == Instrinsic::andi32  ||
                &def == Instrinsic::andu    ||
                &def == Instrinsic::andu32  ||
                &def == Instrinsic::andf    ||
                &def == Instrinsic::andf32
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "&&";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::ori    ||
                &def == Instrinsic::ori32  ||
                &def == Instrinsic::oru    ||
                &def == Instrinsic::oru32  ||
                &def == Instrinsic::orf    ||
                &def == Instrinsic::orf32
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "||";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == Instrinsic::notequali    ||
                &def == Instrinsic::notequali32  ||
                &def == Instrinsic::notequalu    ||
                &def == Instrinsic::notequalu32
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "!=";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::lessequalsi    ||
                &def == Instrinsic::lessequalsi32  ||
                &def == Instrinsic::lessequalsu    ||
                &def == Instrinsic::lessequalsu32  ||
                &def == Instrinsic::lessequalsf32  ||
                &def == Instrinsic::lessequalsf64
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "<=";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::greaterequalsi    ||
                &def == Instrinsic::greaterequalsi32  ||
                &def == Instrinsic::greaterequalsu    ||
                &def == Instrinsic::greaterequalsu32   ||
                &def == Instrinsic::greaterequalsf32  ||
                &def == Instrinsic::greaterequalsf64
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << ">=";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::lessi    ||
                &def == Instrinsic::lessi32  ||
                &def == Instrinsic::lessu    ||
                &def == Instrinsic::lessu32    ||
                &def == Instrinsic::lessf32 ||
                &def == Instrinsic::lessf64
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "<";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else  if(&def == Instrinsic::greateri    ||
                &def == Instrinsic::greateri32  ||
                &def == Instrinsic::greateru    ||
                &def == Instrinsic::greateru32 ||
                &def == Instrinsic::greaterf32 ||
                &def == Instrinsic::greaterf64
                )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << ">";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == Instrinsic::bitOri
        )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "|";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(
            &def == Instrinsic::bitAndi
            )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "&";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(
            &def == Instrinsic::subi    ||
            &def == Instrinsic::subi32  ||
            &def == Instrinsic::subf    ||
            &def == Instrinsic::subf32
            )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "-";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(
            &def == Instrinsic::multi    ||
            &def == Instrinsic::multi32  ||
            &def == Instrinsic::multu    ||
            &def == Instrinsic::multu32  ||
            &def == Instrinsic::multf    ||
            &def == Instrinsic::multf32
        )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "*";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(
            &def == Instrinsic::divi    ||
            &def == Instrinsic::divi32  ||
            &def == Instrinsic::divf    ||
            &def == Instrinsic::divf32
            )
    {
        out << "(";
        args.list[0]->Visit(*this);
        out << "/";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == &Instrinsic::pointerAdd){
        out << "(";
        args.list[0]->Visit(*this);
        out << "+";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == &Instrinsic::pointerSub){
        out << "(";
        args.list[0]->Visit(*this);
        out << "+";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == Instrinsic::bitShiftLeft){
        out << "(";
        args.list[0]->Visit(*this);
        out << "<<";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == Instrinsic::bitShiftRight){
        out << "(";
        args.list[0]->Visit(*this);
        out << ">>";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else if(&def == Instrinsic::modi){
        out << "(";
        args.list[0]->Visit(*this);
        out << "%";
        args.list[1]->Visit(*this);
        out << ")";
    }
    else {
        assert(false && "No code gen for intrinsic operator");
    }
}