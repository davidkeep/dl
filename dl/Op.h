//
//  Op.h
//  Created by David on 8/19/16.
//

#pragma once
#include "Decl.h"

using uint32 = uint32_t;
using int32 = int32_t;

enum struct Op
{
    PointerOperator,    // '
    AddressOperator,    // &
    Negated,            // !

    Call,               // ()

    Dot,                // .
    
    Array,              // []
    
    Mul,                // *
    Div,                // /
    Mod,                // %
    
    Plus,               // +
    Minus,              // -
    
    Less,               // <
    LessEqual,          // <=
    Greater,            // >
    GreaterEqual,       // >=
    
    Equality,           // ==
    EqualityNegated,    // !=
    
    And,                // &&
    Or,                 // ||
    
    BitAnd,             // &
    BitOr,              // |
    
    Assign,             // =
    None,
    Max,
};

struct OpType
{
    int precedence;
    bool binary;
    bool unary;
    bool right;
    string name;
    bool list;
};

const static OpType opTable[int(Op::Max)] =
{
    {0, false, true , false, "^" , false},  // ^
    {0, false, true , false, "&" , false},  // &
    {0, false, true , false, "!" , false},  // !
    
    {0, false, true , false, "()", true},    // ()
    
    {1, true , false, false, "." , false},  // .
    
    {1, true , false, false, "[]", true},    // []
    
    {5, true , false, false, "*" , false},  // *
    {5, true , false, false, "/" , false},  // /
    {5, true , false, false, "%" , false},  // %
    
    {6, true , false, false, "+" , false},  // +
    {6, true , false, false, "-" , false},  // -
    
    {8, true , false, false, "<" , false},  // <
    {8, true , false, false, "<=", false},  // <=
    {8, true , false, false, ">" , false},  // >
    {8, true , false, false, ">=", false},  // >=
    
    {9, true , false, false, "==", false},  // ==
    {9, true , false, false, "!" , false},  // !=
    
    {13,true , false, false, "&&", false},  // &&
    {14,true , false, false, "||", false},  // ||
    
    {15,true , false, false, "&", false},  // &
    {15,true , false, false, "|", false},  // |
    
    {16,true , false, true, "=" , false},  // =
    
    {17,true , false, true, "None", false}, // NONE
};

inline int PrecedenceMax(){
    return opTable[int(Op::None)].precedence;
}

inline int Precedence(Op op){
    return opTable[int(op)].precedence;
}

inline const OpType& Type(Op op){
    return opTable[int(op)];
}

struct BinaryOp : public Expr {
    
    Op op = Op::None;
    Expr* left = nullptr;
    Expr* right = nullptr;
    Variable *fn = nullptr;
    ExprList *args = nullptr;
    
    bool operator==(Op op) const {
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
    Op op = Op::None;
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
