//
//  Ast.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Decl.h"

struct Blck : public Expr {
    Blck(){
        kind = Ast::Blck;
    }
    bool didReturn = false;
    void operator = (Blck) = delete;
    Blck(Blck const &) = delete;

    Array<Expr&> childrenAppended;
    Array<Expr&> children;
    vector<Blck*> includes;
    
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
};

struct If : public Expr {
    Expr *condition = nullptr;
    Blck *trueBody = nullptr;
    Blck *falseBody = nullptr;
};

struct Return : public Expr {
    Expr *expr = nullptr;
};

struct CastExpr : public Expr {
    Expr *expr = nullptr;
};

struct ConstNumber : public Expr {
    string value;
};

struct ConstString : public Expr {
    string value;
};

struct Directive : public Expr {
    string value;
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
};

struct Unary : public Expr {
    Lexer::Symbol op = Lexer::Illegal;
    Expr* expr = nullptr;
};

struct Access : public Expr {
    Expr* operand = nullptr;
    string field;
};

struct Call : public Expr {
    Expr* operand = nullptr;
    ExprList *params = nullptr;
    Variable *fn = nullptr;
};

#include "Def.h"
