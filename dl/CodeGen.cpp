//
//  CodeGen.cpp
//  Created by David on 8/22/16.
//

#include "CodeGen.h"
#include "Intrinsics.h"
#include "Project.h"

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

inline string get_working_path()
{
    char temp[1024];
    return ( getcwd(temp, 1024) ? string( temp ) : string("") );
}

void CodeGen::CodeFor(Dec&decl, string &result){
    if(typeid(decl) == typeid(TypeVar))
    {
        TypeVar &d = cast<TypeVar>(decl);
        if(d.ref) result = "&" + result;
        result = CodeFor(*d.type) + result;
    }
    else if(typeid(decl) == typeid(DecAny))
    {
        DecAny &d = cast<DecAny>(decl);
        assert(!d.ref);
        result = CodeFor(*d.type) + result;
    }
    
    else if(typeid(decl) == typeid(Struct))
    {
        Struct &d = cast<Struct>(decl);
        result = (d.ident) + result;
    }
    else if(typeid(decl) == typeid(Func))
    {
        Func &d = cast<Func>(decl);
        result = "(func)" + (d.ident + String(d.id)) + result;
    }
    else if(typeid(decl) == typeid(IntrinsicStruct))
    {
        IntrinsicStruct &d = cast<IntrinsicStruct>(decl);
        result = (d.ident) + result;
    }
    else if(typeid(decl) == typeid(TypePtr))
    {
        TypePtr &d = cast<TypePtr>(decl);
        if(d.ref) result = "&" + result;
        result = "*" + result;
        result = CodeFor(*d.pointed) + result;
    }
    else if(typeid(decl) == typeid(TypeList))
    {
        TypeList &d = cast<TypeList>(decl);
        if(!d.list.size())
            result = "void" + result;
        else if(d.list.size() == 1){
            result = CodeFor(*d.list[0].dec) + result;
        }
        else
        {
            assert(d.type);
            auto &t = tuples[(TypeList*)d.type];
            if(t == 0)
                t = (int)tuples.size(); //@TODO remove cast
            result += "tuple" + String(t);
        }
    }
    else if(typeid(decl) == typeid(Variable))
    {
        Variable &d = cast<Variable>(decl);
        assert(result.empty());
        result =  " " + d.ident;
        if(d.ref) result = "&" + result;
        CodeFor(*d.type, result);
    }
    else if(typeid(decl) == typeid(TypeGen))
    {
        TypeGen &d = cast<TypeGen>(decl);
        if(d.ref) result = "&" + result;
        result = CodeFor(*d.type) + result;
    }
    else if(typeid(decl) == typeid(TypeFn))
    {
        result = "func" + result;
    }
    else if(typeid(decl) == typeid(TypeType))
    {
        result = "t_" + result;
    }
    else if(decl == Dec::Array)
    {
        TypeArray& array = cast<TypeArray>(decl);
        result = CodeFor(*array.type) + result + "[" + array.size->value + "]";
    }
    else if(typeid(decl) == typeid(Enum))
    {
        result = "i32" + result;
    }
    else
    {
        assert(false && "Unhandled Dec type");
    }
}
string CodeGen::CodeFor(Dec&decl){
    string r;
    CodeFor(decl, r);
    return r;
}

CodeGen::CodeGen(Project& project, Semantic &semantic):
out(project.Files()[1]->directory + "build.cc"),
header(project.Files()[1]->directory + "build.h"),
semantic(semantic)
{
    string file = project.Files()[1]->directory + "build.h";
    if(!out.is_open()){
        Print("Failed to open file '" + file + "'");
    }
    header << "#include \"" << cheaderFile << "\"\n";
    out << "#include \"build.h\"\n";
    
    
    for(auto i = 1; i < project.Files().size(); i++){
        auto file = project.Files()[i];
        
        out << "#define f" << String(i-1) << "__ \"" << get_working_path() << "/"<<  file->directory + file->name << "\"\n";
    }
    
    for(auto defi : semantic.defs){
        if(auto def = dynamic_cast<Struct*>(defi)){
            header << "struct " << def->ident << ";\n";
            
        }
        if(auto tuple = dynamic_cast<ListDef*>(defi)){
            header << "struct " << CodeFor(*tuple->list) << ";\n";
        }
    }
    
    for(auto defi : semantic.defs){
        if(auto def = dynamic_cast<Struct*>(defi)){
            if(def->Empty()) continue;
            header << "struct " << def->ident << "{\n";
            for(auto field : def->fields){
                header <<'\t' <<CodeFor(*field) << ";\n";
            }
            header << "};\n";
        }
        else if(auto tuple = dynamic_cast<ListDef*>(defi)){
            header << "struct " << CodeFor(*tuple->list) << "{\n";
            int i = 0;
            for(auto decl : *tuple->list){
                if(!decl.dec->IsType())
                    header << '\t' << CodeFor(*decl.dec) << " " << "i" << i++ << ";\n";
            }
            header<< "};\n";
        }
        else if(typeid(Variable) == typeid(*defi)){
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
        else if(dynamic_cast<IntrinsicStruct*>(defi)){
        }
        else assert(false);
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

    for (auto file : project.Files()) {
        Visit(file->ast);
    }
    
    header << fns.str();
}

void CodeGen::IsUnhandled(Node &self) {
    out << "\"}";
}
void CodeGen::IsBlck(Blck &self) {
    level++;
    auto t = top;
    top = false;
    

    if(!t) inset += '\t';
    for(auto node : self.children){

        bool nl = (typeid(*node) != typeid(IntrinsicStruct) &&
            typeid(*node) != typeid(IntrinsicFunc) &&
            typeid(*node) != typeid(Func) &&
            typeid(*node) != typeid(Struct) &&
            (typeid(*node) != typeid(Variable) || !t));

        bool lineDirective = (typeid(*node) != typeid(IntrinsicStruct) &&
            typeid(*node) != typeid(IntrinsicFunc) &&
            typeid(*node) != typeid(Struct) &&
            (typeid(*node) != typeid(Variable) || !t));
//        if(typeid(*node) == typeid(Func)){
//            if(cast<Func>(node)->external || cast<Func>(node)->generic)
//                lineDirective = false;
//        }
        if(lineDirective && node->coord.file > 0){
            out<<inset;
            out << "#line " << node->coord.line << " f" << String(node->coord.file-1) << "__ //" << DemangleCppAbi(typeid(*node).name()) << '\n';
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

void CodeGen::IsCastExpr(CastExpr &cast) {
    out << "(";
    out << CodeFor(*cast.type);
    out << ")";

    Visit(*cast.expr);
}

void CodeGen::IsCall(Call& call) {
    if (typeid(*call.operand) != typeid(Var)) {
        TypeFn& fn = cast<TypeFn>(RemoveSugar(*call.operand->type));
        
        out << "((void";
        out << "(*)(";
        
        for(int i = 0; i < fn.params.list.size(); i++) {
            out<< CodeFor(*fn.params.list[i].dec);
            if(i != fn.params.list.size() - 1) out<<", ";
        }
        out<< "))";
        
        Visit(*call.operand);
        auto &list = *call.params;
        out << ")";

        out << "(";
        for(int i = 0; i < list.list.size(); i++){
            if(list.list[i]->type->IsType())
                continue;
            
            list.list[i]->Visit(*this);
            if(i != list.list.size()-1 && !list.list.back()->type->IsType()){
                out << ",";
            }
        }
        out << ")";
        return;
    }
    if(auto fn = dynamic_cast<IntrinsicFunc*>(call.fn)){
        GenerateCodeFor(*fn, *call.params);
        return;
    }
    
    out << call.fn->ident;
    if(!((Func*)call.fn)->external)
        out << ((Func*)call.fn)->id;
    auto &list = *call.params;
    out << "(";
    for(int i = 0; i < list.list.size(); i++){
        if(list.list[i]->type->IsType())
            continue;
        
        list.list[i]->Visit(*this);
        if(i != list.list.size()-1 && !list.list.back()->type->IsType()){
            out << ",";
        }
    }
    out << ")";
}

void CodeGen::IsBinary(Binary &op) {
    if(op.fn){
        if(auto fn = dynamic_cast<IntrinsicFunc*>(op.fn)){
            // if(op.op == Op::Call){
            //     GenerateCodeFor(*fn, *(ExprList*)op.args);
            // }
            // else{
                GenerateCodeFor(*fn, *op.args);
            //}
        }
        else{
            out << op.fn->ident;
            if(!((Func*)op.fn)->external)
                out << ((Func*)op.fn)->id;
            auto &list = cast<ExprList>(*op.args);
            out << "(";
            for(int i = 0; i < list.list.size(); i++){
                if(list.list[i]->type->IsType())
                    continue;
                
                list.list[i]->Visit(*this);
                if(i != list.list.size()-1 && !list.list.back()->type->IsType()){
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
    else{
        Assert(false, op, "");
    }
}
void CodeGen::IsAccess(Access &field) {
    Visit(*field.operand);
    if(RemoveSugar(*field.operand->type).IsPtr())
        out << "->";
    else
        out << ".";
    if(field.operand->type->IsList()){
        out << "i";
    }
    out << field.field;
}
void CodeGen::IsUnary(Unary &op) {
    if(op.op == Lexer::Caret)
    {
        out << "(*";
        Visit(*op.expr);
        out << ")";
    }
    else if(op.op == Lexer::And)
    {
         out << "(&";
         Visit(*op.expr);
         out << ")";
    }
    else if(op.op == Lexer::Sub){
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

void CodeGen::IsStruct(Struct &def) {

}
void CodeGen::IsEnum(Enum &def) {
    
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
            
void CodeGen::IsFunc(Func &def) {
    if(def.generic){
        for(auto specialization : def.specializations){
            Visit(*specialization);
        }
        return;
    }
    
    string fn;
    if(def.external){
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
    for(auto i = 0; i < def.params.list.size(); i++){
        if(def.params.list[i].dec->IsType())
            continue;
        
        fn += CodeFor(*def.params.list[i].dec);
        fn += " ";
        fn += def.params.list[i].ident;
        
        if(i != def.params.list.size()-1 && !def.params.list.back().dec->IsType()){
            fn += ',';
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
        out << CodeFor(decl);
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
    if(typeid(*var.def) == typeid(Struct) || typeid(*var.def) == typeid(IntrinsicStruct))
        return;
    if(*var.def == Dec::Fns){
        out << CodeFor(*((TypeFns*)var.def->type));
    }
    if(dynamic_cast<Func*>(var.def)){
        out << "(func)";
    }
    out << var.def->ident;
    if(auto fn = dynamic_cast<Func*>(var.def)){
        out << fn->id;
    }
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
    out << ",(i8*)\"";
    out << str.value;
    out << "\"}";
}

void CodeGen::IsIntrinsicFunc(IntrinsicFunc &def) {
}

void CodeGen::IsIntrinsicStruct(IntrinsicStruct &def) {
}
            
void CodeGen::GenerateCodeFor(IntrinsicFunc &def, ExprList&args){    
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
