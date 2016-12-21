//
//  Printing.h
//  Created by David on 6/30/16.
//

#pragma once
#include "Ast.h"
#include "Decl.h"
#include "Def.h"

static inline string String(const int&v){
    return std::to_string(v);
}

static inline string String(const i64&v){
    return std::to_string(v);
}

inline void Print(const char* str){
    fputs(str, stdout);
    fflush(stdout);
}
inline void Print(const string &str){
    Print(str.c_str());
}

template<class T>
void Print(const T &type)
{
    Print(String(type));
}


static inline string String(const Dec&dec){
    
    if(dec == Ast::TypeAny)
    {
        const TypeAny &any = cast<const TypeAny>(dec);
        if(any.type) return String(*any.type);
        return any.ident + "?";
    }

    if(dec == Ast::Struct || dec == Ast::StructIntrins)
    {
        const Struct &structure = cast<const Struct>(dec);
        if(structure.generic)
        {
            string r = String(*structure.generic);
            r += "(";
            for(auto c : structure.constraints){
                r += String(*c);
            }
            r += ")";
            return r;
        }
        return structure.ident;
    }
    if(dec == Ast::TypeVar)
    {
        const TypeVar &var = cast<const TypeVar>(dec);
        return var.type ? String(*var.type) : var.ident;
    }
    if(dec == Ast::TypePtr)
    {
        const TypePtr &ptr = cast<const TypePtr>(dec);
        return String(*ptr.pointed) + "^";
    }
    if(dec == Ast::TypeType)
    {
        const TypeType &type = cast<const TypeType>(dec);
        return "type." + String(*type.type);
    }
    if(dec == Ast::TypeList)
    {
        const TypeList &list = cast<const TypeList>(dec);
        string r = "(";
        for (int i = 0; i < list.list.length; i++) {
            auto& decName = list.list[i];
            r += String(*decName.dec);
            r += " ";
            r += decName.ident;
            if(i != list.list.length-1){
                r += ",";
            }
        }
        r += ")";
        return r;
    }
    if(dec == Ast::TypeGen)
    {
        const TypeGen &gen = cast<const TypeGen>(dec);
        string r = String(*gen.typeGeneric) + "(";
        for(auto c : gen.constraints){
            r += String(*c);
        }
        return r + ")";
    }
    if(dec == Ast::TypeFn)
    {
        const TypeFn &fn = cast<const TypeFn>(dec);
        string r = "fn" + String(fn.params) + String(fn.results);
        return r;
    }
    if(dec == Ast::TypeFns)
    {
        const TypeFns &fns = cast<const TypeFns>(dec);
        string r = "";
        for(auto fn : fns.functions)
        {
            r += String(*fn) + "\n";
        }
        return r;
    }
    if(dec == Ast::TypeVar)
    {
        const TypeVar &var = cast<const TypeVar>(dec);
        return var.ident;
    }
    return "Can't print";
}
static inline string String(const ExprList&list){
    string r = "(";
    for(int i = 0; i < list.list.length; i++){
        const Expr& expr = list.list[i];
        r += String(*expr.type);
        if(i != list.list.length-1)
            r += ",";
        
    }
    r += ")";
    return r;
}

string DemangleCppAbi(const char* abiName);

template<class T>
string String(const T& type)
{
    return DemangleCppAbi(typeid(T).name());
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


struct AstPrint
{
    int indent = 0;
    
    AstPrint(){
    }
    void Visit(Expr& node);
};
