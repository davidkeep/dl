//
//  CodeGen.h
//  Created by David on 8/22/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
#include "Op.h"
#include "Decl.h"
#include <fstream>
#include "Printing.h"
#include <sstream>
#include "Intrinsics.h"
#include "Semantic.h"
#include <typeinfo>
#include <iostream>
#include "Compiler.h"
#include <unistd.h>

template <class T, class From>
T& Cast(From &type) {
    assert(dynamic_cast<T*>(&type));
    return (T&)type;
}
inline std::string get_working_path()
{
    char temp[1024];
    return ( getcwd(temp, 1024) ? std::string( temp ) : std::string("") );
}
class CodeGen : public Visitor
{
public:
    std::stringstream fns;
    std::stringstream structs;
    int fnptrCount = 0;
    
    string CodeFor(Dec&decl){
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
            if(d.ident == "int"){
                r = "i64";
            }
            if(d.ident == "int32"){
                r = "i32";
            }
            if(d.ident == "int16"){
                r = "i16";
            }
            if(d.ident == "int8"){
                r = "i8";
            }
            
            if(d.ident == "uint"){
                r = "u64";
            }
            if(d.ident == "uint32"){
                r = "u32";
            }
            if(d.ident == "uint16"){
                r = "u16";
            }
            if(d.ident == "uint8"){
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

    table<string,DecList*> tuples;
    
    vector<Blck*> scopes;
    Blck *parent;
    std::ofstream out;
    std::ofstream header;
    int level = 0;
    CodeGen(const string& file, Semantic &semantic):
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
    string inset;
    Semantic &semantic;
    void IsUnhandled(Node &self) override{
        out << "\"}";

    }
    bool top = true;
    void IsBlck(Blck &self) override{
        level++;
        auto t = top;
        top = false;
        
        if(t){
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
            out<<inset;
            if(node->coord.file >= 0)
                out << "#line " << node->coord.line << " \"" << get_working_path() << "/"<< g_files[node->coord.file].directory + g_files[node->coord.file].name << "\"\n";
            if(typeid(*node) == typeid(Blck)) out << "{\n";

            Visit(*node);
            if(typeid(*node) != typeid(IntrinsicStructDef) &&
               typeid(*node) != typeid(IntrinsicFuncDef) &&
               typeid(*node) != typeid(FuncDef) &&
               (typeid(*node) != typeid(Variable) || !t))

            {
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
    void IsExprList(ExprList &self) override{
        out << "{";
        for(int i = 0; i < self.list.size(); i++){
            self.list[i]->Visit(*this);
            if(i != self.list.size()-1){
                out << ",";
            }
        }
        out << "}";
    }

    void IsCast(struct Cast &cast)override {
        out << "(";
        out << CodeFor(*cast.type);
        out << ")";

        Visit(*cast.expr);
    }
    void IsBinaryOp(BinaryOp &op)override {
        if(op.fn){
            if(auto fn = dynamic_cast<IntrinsicFuncDef*>(op.fn)){
                if(op.op == Op::Call){
                    GenerateCodeFor(*fn, *(ExprList*)op.args);
                }
                else{
                    GenerateCodeFor(*fn, *op.args);
                }
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
        else if(op.op == Op::Assign){
            Visit(*op.left);
            out << " = ";
            Visit(*op.right);
        }
        else if(op.op == Op::Dot){
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
    void IsUnaryOp(UnaryOp &op)override {
        if(op.op == Op::PointerOperator){
            out << "(*";
            Visit(*op.expr);
            out << ")";
        }
        else if(op.op == Op::AddressOperator){
            out << "(&";
            Visit(*op.expr);
            out << ")";
        }
        else if(op.op == Op::Minus){
            out << "(-";
            Visit(*op.expr);
            out << ")";
        }
        else if(op.op == Op::Negated){
            out << "(!";
            Visit(*op.expr);
            out << ")";
        }
    }
 
    void IsStructDef(StructDef &def)override {

    }
    void IsEnumDef(EnumDef &def)override {
        
    }
    void IsFor(For &loop)override {
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
    void IsIf(If &ifStatement)override {
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
    void IsReturn(Return &ret)override {
        out << "return ";
        if(ret.expr)
            Visit(*ret.expr);
    }
                
    void IsFuncDef(FuncDef &def)override {
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

        if(def.ret){
            fn +=  CodeFor(*def.ret);
            if(def.ret->ref)
                fn += "&";
        }
        else
            fn += "void";
        
        fn += " ";
        fn += def.ident;
        if(!def.external & def.ident != "main")
            fn += String(def.id);
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
    void IsVariable(Variable &decl)override {
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
    void IsVar(Var &var)override {
        if(typeid(*var.def) == typeid(StructDef) || typeid(*var.def) == typeid(IntrinsicStructDef))
            return;
    
        
        out << var.def->ident;
    }
    void IsConstNumber(ConstNumber &num)override {
        out << num.value;
    }
                
    void IsConstString(ConstString &str)override {
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
    void IsIntrinsicFuncDef(IntrinsicFuncDef &def)override {
        
    }
    void IsIntrinsicStructDef(IntrinsicStructDef &def)override {

    }
                
    void GenerateCodeFor(IntrinsicFuncDef &def, ExprList&args){
    
        using namespace Instrinsic;
        
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
};
