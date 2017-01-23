//
//  CodeGen.cpp
//  Created by David on 8/22/16.
//

#include "CodeGen.h"
#include "Intrinsics.h"
#include "Project.h"

static string Identifier(Struct &s)
{
    if(s.incomplete || s.stub || s.fields.size() == 0) {
        return s.ident;
    }
    return s.ident + String(s.id);
}

static string Identifier(Func &s)
{
    if(s.external) {
        return s.ident;
    }
//    static int count = 0;
//    static table<Func*, string> table;
//    
//    if(table.count(&s)) { return table[&s]; }
//    
//    table[&s] = ("F") + String(count++);
    return s.ident + String(s.id);
}


string WorkingDirectory()
{
    char temp[1024];
    return ( getcwd(temp, 1024) ? string( temp ) : string("") );
}

void CodeGen::CodeFor(Type&decl, string &result){
    if((decl) == Ast::TypeVar)
    {
        TypeVar &d = cast<TypeVar>(decl);
        if(d.ref) result = "&" + result;
        result = CodeFor(*d.type) + result;
    }
    else if((decl) == Ast::TypeAny)
    {
        TypeAny &d = cast<TypeAny>(decl);
        assert(!d.ref);
        result = CodeFor(*d.type) + result;
    }
    
    else if((decl) == Ast::Struct)
    {
        Struct &d = cast<Struct>(decl);
        result = Identifier(d) + result;
    }
    else if((decl) == Ast::Func)
    {
        Func &d = cast<Func>(decl);
        result = "(func)" + Identifier(d) + result;
    }
    else if((decl) == Ast::StructIntrins)
    {
        StructIntrins &d = cast<StructIntrins>(decl);
        result = (d.ident) + result;
    }
    else if((decl) == Ast::TypePtr)
    {
        TypePtr &d = cast<TypePtr>(decl);
        if(d.ref) result = "&" + result;
        result = "*" + result;
        result = CodeFor(*d.pointed) + result;
    }
    else if((decl) == Ast::TypeList)
    {
        TypeList &d = cast<TypeList>(decl);
        if(!d.list.length)
            result = "void" + result;
        else if(d.list.length == 1){
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
    else if((decl) == Ast::Variable)
    {
        Variable &d = cast<Variable>(decl);
        assert(result.empty());
        result =  " " + d.ident;
        if(d.ref) result = "&" + result;
        CodeFor(*d.type, result);
    }
    else if((decl) == Ast::TypeGen)
    {
        TypeGen &d = cast<TypeGen>(decl);
        if(d.ref) result = "&" + result;
        result = CodeFor(*d.type) + result;
    }
    else if((decl) == Ast::TypeFn)
    {
        result = "func" + result;
    }
    else if((decl) == Ast::TypeType)
    {
        result = "t_" + result;
    }
    else if(decl == Ast::TypeArray)
    {
        TypeArray& array = cast<TypeArray>(decl);
        result = CodeFor(*array.type) + result + "[" + array.size->value + "]";
    }
    else if((decl) == Ast::Enum)
    {
        result = "i32" + result;
    }
    else
    {
        assert(false && "Unhandled Type type");
    }
}

string CodeGen::CodeFor(Type&decl){
    string r;
    CodeFor(decl, r);
    return r;
}

CodeGen::CodeGen(Project& project, Semantic &semantic):
out(project.Files()[1]->directory + buildDirectory + "/build.cc"),
header(project.Files()[1]->directory + buildDirectory + "/build.h"),
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
        
        out << "#define f" << String(i-1) << "__ \"" << file->directory + file->name << "\"\n";
    }
    
    for (int i = 0; i < semantic.defs.length; i++){
        auto& def = *semantic.defs[i];
        if(def == Ast::Struct){
            header << "struct " << Identifier(cast<Struct>(def)) << ";\n";
            
        }
        else if(def == Ast::TypeList){
            header << "struct " << CodeFor(cast<TypeList>(def)) << ";\n";
        }
    }
    
    for (int i = 0; i < semantic.defs.length; i++){
        auto& def = *semantic.defs[i];
        if(def == Ast::Struct)
        {
            if(cast<Struct>(def).Empty()) continue;
            header << "struct " << Identifier(cast<Struct>(def)) << "{\n";
            for(auto field : cast<Struct>(def).fields){
                header <<'\t' <<CodeFor(*field) << ";\n";
            }
            header << "};\n";
        }
        else if(def == Ast::TypeList){
            header << "struct " << CodeFor(cast<TypeList>(def)) << "{\n";
            for(int i = 0; i < cast<TypeList>(def).list.length; i++) {
                auto&decl = cast<TypeList>(def).list[i];
                if(*decl.dec != Ast::TypeType)
                    header << '\t' << CodeFor(*decl.dec) << " " << "i" << i << ";\n";
            }
            header<< "};\n";
        }
        else if(def == Ast::Variable){
            auto& decl = cast<Variable>(def);
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
            out << ";\n";
        }
        else assert(false);
    }
    
    for (int i = 0; i < semantic.typeinfo.length; i++) {
        auto& type = semantic.typeinfo[i];
        out << Identifier(*cast<Struct>(type.def->type)) << ' ' << type.def->ident << "=" << "{sizeof(" + CodeFor(*type.type) + ")};\n";
    }
    for (int i = 0; i < semantic.varDefs.length; i++)
    {
        auto &decl = semantic.varDefs[i];
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

void Visit(CodeGen& code, Blck &self) {
    code.level++;
    auto t = code.top;
    code.top = false;
    if(!t) code.inset += '\t';
    for(int i = 0; i < self.children.length; i++){
        auto& node = self.children[i];
        bool nl = ((node) != Ast::StructIntrins) &&
            (node) != Ast::FuncIntrins &&
            (node) != Ast::Func &&
            (node) != Ast::Struct &&
            ((node) != Ast::Variable || !t);

        bool lineDirective = ((node) != Ast::StructIntrins) &&
            (node) != Ast::FuncIntrins &&
            (node) != Ast::Struct &&
            ((node) != Ast::Variable || !t);
//        if((*node) == Ast::Func)){
//            if(cast<Func>(node)->external || cast<Func>(node)->generic)
//                lineDirective = false;
//        }
        if(lineDirective && node.coord.file > 0){
            code.out << code.inset;
            code.out << "#line " << node.coord.line << " f" << String(node.coord.file-1) << "__ //" <<  DemangleCppAbi(typeid(node).name()) << '\n';
        }

        code.out << code.inset;
        if((node) == Ast::Blck) code.out << "{\n";

        code.Visit(node);
        if(nl){
            code.out << ";\n";
        }

        if((node) == Ast::Blck) { code.out << code.inset; code.out << "}\n";}
    }
    if(!t)
        code.inset = code.inset.substr(0, code.inset.size()-1);

    if(t)
    {
        code.header << code.fns.str();
    }
    code.level--;
}
void Visit(CodeGen& code, ExprList &self) {
    code.out << "{";
    for(int i = 0; i < self.list.length; i++){
        code.Visit(self.list[i]);
        if(i != self.list.length-1){
            code.out << ",";
        }
    }
    code.out << "}";
}

void Visit(CodeGen& code, CastExpr &cast) {
    code.out << "(";
    code.out << code.CodeFor(*cast.type);
    code.out << ")";

    code.Visit(*cast.expr);
}

void Visit(CodeGen& code, Call& call) {
    if ((*call.operand) != Ast::Var) {
        TypeFn& fn = cast<TypeFn>(RemoveSugar(*call.operand->type));
        
        code.out << "((void";
        code.out << "(*)(";
        
        for(int i = 0; i < fn.params.list.length; i++) {
            code.out<< code.CodeFor(*fn.params.list[i].dec);
            if(i != fn.params.list.length - 1) code.out<<", ";
        }
        code.out<< "))";
        
        code.Visit(*call.operand);
        auto &list = *call.params;
        code.out << ")";

        code.out << "(";
        for(int i = 0; i < list.list.length; i++){
            if(*list.list[i].type == Ast::TypeType)
                continue;
            
            code.Visit(list.list[i]);
            if(i != list.list.length-1 && *list.list[list.list.length-1].type != Ast::TypeType){
                code.out << ",";
            }
        }
        code.out << ")";
        return;
    }
    if(*call.fn == Ast::FuncIntrins){
        code.GenerateCodeFor(cast<FuncIntrins>(*call.fn), *call.params);
        return;
    }
    
    code.out << Identifier(*cast<Func>(call.fn));
    auto &list = *call.params;
    code.out << "(";
    for(int i = 0; i < list.list.length; i++){
        if(*list.list[i].type == Ast::TypeType)
            continue;
        
        code.Visit(list.list[i]);
        if(i != list.list.length-1 && *list.list[list.list.length-1].type != Ast::TypeType){
            code.out << ",";
        }
    }
    code.out << ")";
}

void Visit(CodeGen& code, Binary &op) {
    if(op.fn){
        if(*op.fn == Ast::FuncIntrins){
            // if(op.op == Op::Call){
            //     GenerateCodeFor(*fn, *(ExprList*)op.args);
            // }
            // else{
                code.GenerateCodeFor((FuncIntrins&)(*op.fn), *op.args);
            //}
        }
        else{
            code.out << Identifier(*cast<Func>(op.fn));
            auto &list = cast<ExprList>(*op.args);
            code.out << "(";
            for(int i = 0; i < list.list.length; i++){
                if(*list.list[i].type == Ast::TypeType)
                    continue;
                
                code.Visit(list.list[i]);
                if(i != list.list.length-1 && *list.list[list.list.length-1].type != Ast::TypeType){
                    code.out << ",";
                }
            }
            code.out << ")";
        }
    }
    else if(op.op == Lexer::Assign){
        code.Visit(*op.left);
        code.out << " = ";
        code.Visit(*op.right);
    }
    else{
        Assert(false, op, "");
    }
}
void Visit(CodeGen& code, Access &field) {
    code.Visit(*field.operand);
    if(RemoveSugar(*field.operand->type) == Ast::TypePtr)
        code.out << "->";
    else
        code.out << ".";
    if(*field.operand->type  == Ast::TypeList){
        code.out << "i";
    }
    code.out << field.field;
}
void Visit(CodeGen& code, Unary &op) {
    if(op.op == Lexer::Caret)
    {
        code.out << "(*";
        code.Visit(*op.expr);
        code.out << ")";
    }
    else if(op.op == Lexer::And)
    {
         code.out << "(&";
         code.Visit(*op.expr);
         code.out << ")";
    }
    else if(op.op == Lexer::Sub){
        code.out << "(-";
        code.Visit(*op.expr);
        code.out << ")";
    }
    else if(op.op == Lexer::Negated){
        code.out << "(!";
        code.Visit(*op.expr);
        code.out << ")";
    }
}

void Visit(CodeGen& code, Struct &def) {

}
void Visit(CodeGen& code, Enum &def) {
    
}
void Visit(CodeGen& code, For &loop) {
    if(loop.from && loop.to){
        code.out << "for(";
        code.out << code.CodeFor(*loop.from->type);
        code.out << " " << loop.it;
        code.out << " = ";
        code.Visit(*loop.from);
        code.out << "; ";
        code.out << loop.it << "<";
        code.Visit(*loop.to);
        code.out << ";" << loop.it << "++){\n";
        code.Visit(*loop.body);
        code.out << code.inset << "}";
    }
    else{
        code.out << "while(";
        code.Visit(*loop.from);
        code.out << "){\n";
        code.Visit(*loop.body);
        code.out << code.inset << "}";
    }
}

void Visit(CodeGen& code, If &ifStatement) {
    code.out << "if(";
    code.Visit(*ifStatement.condition);
    code.out << "){\n";
    code.Visit(*ifStatement.trueBody);
    code.out << code.inset << "}";
    if(ifStatement.falseBody)
    {
        code.out << "else{\n";
        code.Visit(*ifStatement.falseBody);
        code.out << code.inset << "}";
    }
}

void Visit(CodeGen& code, Return &ret) {
    code.out << "return ";
    if(ret.expr)
        code.Visit(*ret.expr);
}
            
void Visit(CodeGen& code, Func &def) {
    if(def.unknown.size() && !def.generic){
        for(auto specialization : def.specializations){
            code.Visit(*specialization);
        }
        return;
    }
    
    string fn;
    if(def.external){
        fn = "extern \"C\" ";
    }

    fn +=  code.CodeFor(def.results);
    if(def.results.ref){
        fn += "&";
    }
    
    fn += " ";
    
    if(def.ident == "Main"){
        fn += "main";
    }
    else
        fn += Identifier(def);


    fn += '(';
    for(auto i = 0; i < def.params.list.length; i++){
        if(*def.params.list[i].dec == Ast::TypeType)
            continue;
        
        fn += code.CodeFor(*def.params.list[i].dec);
        fn += " ";
        fn += def.params.list[i].ident;
        
        if(i != def.params.list.length-1 && *def.params.list[def.params.list.length-1].dec != Ast::TypeType){
            fn += ',';
        }
    }

    fn += ")";
    code.fns << fn << ";\n";
    
    if(def.body){
        code.out << fn << "{\n";
        code.Visit(*def.body);
        code.out << "}\n";
    }
}
void Visit(CodeGen& code, Variable &decl) {
    if(code.level != 1){
        code.out << code.CodeFor(decl);
        code.out << "=";
        if(decl.assign){
            code.Visit(*decl.assign);
        }
        else{
            code.out << "{0}";
        }
    }
}
void Visit(CodeGen& code, Var &var) {
    if((*var.def) == Ast::Struct || (*var.def) == Ast::StructIntrins)
        return;
    if(*var.def == Ast::TypeFns){
        code.out << code.CodeFor(*((TypeFns*)var.def->type));
    }
    if(*var.def == Ast::Func){
        code.out << "(func)";
    }
    if(*var.def == Ast::Func){
        code.out << Identifier(*cast<Func>(var.def));
    }
    else
    {
        code.out << var.def->ident;
    }
}
void Visit(CodeGen& code, ConstNumber &num) {
    code.out << num.value;
}
            
void Visit(CodeGen& code, ConstString &str) {
    int characters = 0;
    for(int i = 0; i < str.value.size(); i++){
        if(str.value[i] != '\\'){
            characters++;
        }
    }
    code.out << code.CodeFor(*str.type) << "{";
    code.out << characters;
    code.out << ",(i8*)\"";
    for (auto c : str.value) {
        if (c == '"') code.out << "\\\"";
        else code.out << c;
    }
    code.out << "\"}";
}

void Visit(CodeGen& code, FuncIntrins &def) {
}

void Visit(CodeGen& code, StructIntrins &def) {
}
            
void CodeGen::GenerateCodeFor(FuncIntrins &def, ExprList&args){
    if( &def == Instrinsic::addi    ||
        &def == Instrinsic::addi32  ||
        &def == Instrinsic::addu    ||
        &def == Instrinsic::addu32  ||
        &def == Instrinsic::addf    ||
        &def == Instrinsic::addf32
        )
    {
        out << "(";
        Visit(args.list[0]);
        out << "+";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "==";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "&&";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "||";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == Instrinsic::notequali    ||
                &def == Instrinsic::notequali32  ||
                &def == Instrinsic::notequalu    ||
                &def == Instrinsic::notequalu32
                )
    {
        out << "(";
        Visit(args.list[0]);
        out << "!=";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "<=";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << ">=";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "<";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << ">";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == Instrinsic::bitOri
        )
    {
        out << "(";
        Visit(args.list[0]);
        out << "|";
        Visit(args.list[1]);
        out << ")";
    }
    else if(
            &def == Instrinsic::bitAndi
            )
    {
        out << "(";
        Visit(args.list[0]);
        out << "&";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "-";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "*";
        Visit(args.list[1]);
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
        Visit(args.list[0]);
        out << "/";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == &Instrinsic::pointerAdd){
        out << "(";
        Visit(args.list[0]);
        out << "+";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == &Instrinsic::pointerSub){
        out << "(";
        Visit(args.list[0]);
        out << "+";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == Instrinsic::bitShiftLeft){
        out << "(";
        Visit(args.list[0]);
        out << "<<";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == Instrinsic::bitShiftRight){
        out << "(";
        Visit(args.list[0]);
        out << ">>";
        Visit(args.list[1]);
        out << ")";
    }
    else if(&def == Instrinsic::modi){
        out << "(";
        Visit(args.list[0]);
        out << "%";
        Visit(args.list[1]);
        out << ")";
    }
    else {
        assert(false && "No code gen for intrinsic operator");
    }
}

void Visit(CodeGen&, Directive&){
}
void Visit(CodeGen&, Type&){
}
void Visit(CodeGen&, Using&){
}

void CodeGen::Visit(Expr& expr)
{
    VISTOR(*this, expr);
}
