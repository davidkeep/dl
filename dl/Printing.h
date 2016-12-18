//
//  Printing.h
//  Created by David on 6/30/16.
//

#pragma once
#include "Ast.h"
#include "Decl.h"
#include "Def.h"

static inline string String(const Dec&dec){
    
    if(auto any = dec.IsAny())
    {
        if(any->type) return String(*any->type);
        return any->ident + "?";
    }

    if(dynamic_cast<const StructDef*>(&dec))
    {
        StructDef &d = (StructDef&)dec;
        return d.ident;
    }
    if(auto var = dec.IsVar())
    {
        return String(*var->type);
    }
    if(auto ptr = dec.IsPtr())
    {
        return String(*ptr->pointed) + "^";
    }
    if(auto type = dec.IsType())
    {
        return "type." + String(*type->type);
    }
    if(auto list = dec.IsList())
    {
        string r = "(";
        for (auto& decName : list->list) {
            r += String(*decName.dec);
            r += " ";
            r += decName.ident;
            if(&decName != &list->list.back()){
                r += ",";
            }
        }
        r += ")";
        return r;
    }
    if(auto var = dec.IsGen())
    {
        string r = String(*var->typeGeneric) + ":(";
        for(auto c : var->constraints){
            r += String(*c);
        }
        return r + ")";
    }
    if(auto var = dec.IsFn())
    {
        string r = "fn" + String(var->params) + String(var->results);
        return r;
    }
    if(dec == Dec::Fns)
    {
        DecFns &fns = (DecFns&)dec;
        string r = "";
        for(auto fn : fns.functions)
        {
            r += String(*fn) + "\n";
        }
        return r;
    }
    if(auto var= dec.IsVar())
    {
        return var->ident;
    }
    return "Can't print";
    //assert(false);
}
static inline string String(const ExprList&list){
    string r = "(";
    for(auto exp : list.list){
        r += String(*exp->type);
        if(exp != list.list.back())
            r += ",";
        
    }
    r += ")";
    return r;
}

static void Print(const Dec&decl){
    Print(String(decl));
}

static void Print(Dec*dec){
    if(!dec){
        Print("()");
        return;
    }
    Print("("); Print(*dec); Print(")");
}
struct pass {
    template<typename ...T> pass(T...) {}
};
template<class ...Args>
void Print(const Args&...args)
{
    pass((Print(args), 1)...);
}

template<class ...Args>
void Println(const Args&...args)
{
    pass((Print(args), 1)...);
    Print("\n");
}


class AstPrinter : public Visitor
{
public:
    int indent = 0;
    
    AstPrinter(){
    }
    
    template<class T>
    void VisitChildren(T &self){
        indent++;
        self.VisitChildren(*this);
        indent--;
    }
    
    void Indent()
    {
        Print("\n");
        for(int i = 0; i < indent; i++)
            Print("   ");
    }
    void IsBlck(Blck &self) override
    {
        Indent(); Print("<block>");
        VisitChildren(self);
    }
    void IsExprList(ExprList &self) override
    {
        Indent(); Print("<ExprList>");
        VisitChildren(self);
    }
    void IsStructDef(StructDef &def)override {
        Indent(); Print("<struct> " + def.ident);
    }
    void IsEnumDef(EnumDef &def)override {
        Indent(); Print("<block>");
    }
    void IsFuncDef(FuncDef &def)override {
        Indent(); Print("<FuncDef> ", def.ident);
        //VisitChildren(def);
    }
    void IsVariable(Variable &decl)override {
        Indent(); Print("<VarDecl> ", decl.ident);
        Print(decl.type);
    }
    void IsVar(Var &var)override {
        Indent(); Print("<Var> ", var.name);
        Print(var.type);
    }
    void IsBinaryOp(BinaryOp &op)override {
        Indent(); Print("<BinaryOp> " + String(op.op) + " ");
        Print(op.type);
        VisitChildren(op);
    }
    void IsUnaryOp(UnaryOp &op)override {
        Indent(); Print("<UnaryOp> " + String(op.op) + " ");
        Print(op.type);
        VisitChildren(op);
    }
    void IsFor(For &op)override {
        Indent(); Print("<For>");
        VisitChildren(op);
    }
    void IsConstNumber(ConstNumber &num)override {
        Indent(); Print("<ConstNumber> " + num.value);
    }
    void IsConstString(ConstString &str)override {
        Indent(); Print("<ConstString> " + str.value);
    }
};
