//
//  Op.h
//  Created by David on 8/19/16.
//

#pragma once
#include "Decl.h"
#include "Error.h"

using uint32 = uint32_t;
using int32 = int32_t;

inline bool IsBinaryOperator(const Token& token) {
    if (token.type < Lexer::OperatorsEnd && token.type > Lexer::OperatorsBegin){
        return true;
    }
    return false;
}


struct BinaryOp : public Expr {
    
    Lexer::Symbol op = Lexer::Illegal;
    Expr* left = nullptr;
    Expr* right = nullptr;
    Variable *fn = nullptr;
    ExprList *args = nullptr;
    
    bool operator==(Lexer::Symbol op) const {
        return BinaryOp::op == op;
    }
    
    BinaryOp *Copy() const override {
        BinaryOp& self = *new BinaryOp;
        self.op = op;
        self.coord = coord;
        self.left = ::Copy(left);
        self.right = ::Copy(right);
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsBinaryOp(*this); }
    void VisitChildren(IVisitor& visitor){
        left->Visit(visitor);
        right->Visit(visitor);
    }
};

struct UnaryOp : public Expr {
    Lexer::Symbol op = Lexer::Illegal;
    Expr* expr = nullptr;
    UnaryOp *Copy() const override {
        UnaryOp& self = *new UnaryOp;
        self.coord = coord;
        self.op = op;
        self.expr = ::Copy(expr);
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsUnaryOp(*this); }
    void VisitChildren(IVisitor& visitor){
        expr->Visit(visitor);
    }
};
