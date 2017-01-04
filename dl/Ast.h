//
//  Ast.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Type.h"

struct Using;

struct ExprList : public Expr {
    ExprList(){
        kind = Ast::ExprList;
    }
    
    Array<Expr&> list;
    
    Expr& operator[](int index){
        return list[index];
    }
    struct iterator : public vector<Expr*>::iterator {
        iterator(vector<Expr*>::iterator v):
        vector<Expr*>::iterator(v){
        }
        Expr& operator*(){
            return *vector<Expr*>::iterator::operator*();;
        }
    };
    Expr** begin() {
        return list.data;
    }
    Expr** end() {
        return list.data + list.length;
    }
    Expr* const* begin()const {
        return list.data;
    }
    Expr* const* end()const {
        return list.data + list.length;
    }
};

struct Blck : public Expr {
    Blck(){
        kind = Ast::Blck;
    }
    bool didReturn = false;
    void operator = (Blck) = delete;
    Blck(Blck const &) = delete;
    Blck *outer = nullptr;

    Array<Expr&> childrenAppended;
    Array<Expr&> children;
    vector<Blck*> includes;
    
    Array<Using&> usings;
    
    //Variable, Structure, Enum
    table<string, Variable*> variables;
    
    //Function
    table<string, vector<Variable*>> functions;
    
    void Add(Expr& child){
        children.Push(child);
    }
};

struct For : public Expr {

    string it;
    
    Expr *from = nullptr;
    Expr *to = nullptr;

    Blck *body = nullptr;
    
    void SetFromTo(Expr *from, Expr *to){
        For::from = from;
        For::to = to;
        assert(from && to);
    }
    void SetExpr(Expr *expr){
        from = expr;
        assert(!to);
    }
    For(){
        kind = Ast::For;
    }
};

struct If : public Expr {
    Expr *condition = nullptr;
    Blck *trueBody = nullptr;
    Blck *falseBody = nullptr;
    If(){
        kind = Ast::If;
    }
};

struct Return : public Expr {
    Expr *expr = nullptr;
    Return()
    {
        kind = Ast::Return;
    }
};

struct CastExpr : public Expr {
    Expr *expr = nullptr;
    CastExpr(){
        kind = Ast::CastExpr;
    }
};

struct ConstNumber : public Expr {
    string value;
    ConstNumber(){
        kind = Ast::ConstNumber;
    }
};

struct ConstString : public Expr {
    string value;
    ConstString(){
        kind = Ast::ConstString;
    }
};

struct Directive : public Expr {
    string value;
    Directive(){
        kind = Ast::Directive;
    }
};

inline bool IsBinaryerator(const Token& token) {
    if (token.type < Lexer::OperatorsEnd && token.type > Lexer::OperatorsBegin){
        return true;
    }
    return false;
}

struct Binary : public Expr {
    
    Lexer::Symbol op = Lexer::Illegal;
    Expr* left = nullptr;
    Expr* right = nullptr;
    Variable *fn = nullptr;
    ExprList *args = nullptr;
    
    bool operator==(Lexer::Symbol op) const {
        return Binary::op == op;
    }
    Binary(){
        kind = Ast::Binary;
    }
};

struct Unary : public Expr {
    Lexer::Symbol op = Lexer::Illegal;
    Expr* expr = nullptr;
    Unary(){
        kind = Ast::Unary;
    }
};

struct Access : public Expr {
    Expr* operand = nullptr;
    string field;
    Access(){
        kind = Ast::Access;
    }
};

struct Using : public Expr {
    Expr* operand = nullptr;
    string as;
    Using(){
        kind = Ast::Using;
    }
};

struct Call : public Expr {
    Expr* operand = nullptr;
    ExprList *params = nullptr;
    Variable *fn = nullptr;
    Call(){
        kind = Ast::Call;
    }
};

static int definitonCount = 0;

struct Func : public Variable {
    
    TypeList params;
    TypeList results;
    Blck* body = nullptr;
    bool external = false;
    Func* generic = nullptr;
    int id = definitonCount++;
    table<string, TypeAny*> unknown;
    Func(){
        kind = Ast::Func;
    }
    
    vector<Func*> specializations;
};

struct Enum : public Variable
{
    Enum(){
        kind = Ast::Enum;
    }
    void Add(const string& value){
    }
};

struct Struct : public Variable {
    
    bool Generic()const{ return constraints.size() && !specialization; }
    bool specialization = false;
    bool stub = false;
    bool incomplete = false;
    bool Empty() {
        return fields.size() == 0;
    }
    int id = definitonCount++;
    
    Struct(){
        kind = Ast::Struct;
    }
    
    Struct *generic = nullptr;
    Variable *typeinfo = nullptr;
    
    vector<Type*> constraints;
    
    Blck block;
    
    void AddField(string ident, Type& type){
        auto var = new Variable;
        var->type = &type;
        var->ident = ident;
        fields.push_back(var);
    }
    
    vector<Variable*> fields;
    
    vector<Struct*> specializations;
};


struct FuncIntrins : public Func {
    FuncIntrins() {
        kind = Ast::FuncIntrins;
    }
};

struct StructIntrins : public Struct {
    StructIntrins(){
        kind = Ast::StructIntrins;
    }
};

