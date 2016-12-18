//
//  Ast.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Node.h"
#include "Decl.h"

struct Blck : public Node {
    bool didReturn = false;
    
    vector<Node*> childrenAppended;
    vector<Node*> children;
    
    vector<Blck*> includes;
    
    //Variable, Structure, Enum
    table<string, Variable*> variables;
    
    //Function
    table<string, vector<Variable*>> functions;

    Blck *Copy() const override;
    
    void Add(Node*child){
        assert(child);
        children.push_back(child);
    }
    
    void Visit(IVisitor& visit)override{ visit.IsBlck(*this); }
    void VisitChildren(IVisitor& visitor){
        for(auto child : childrenAppended){
            child->Visit(visitor);
        }
        for(auto child : children){
            child->Visit(visitor);
        }
    }
};

struct For : public Node {

    string it;
    
    Expr *from = nullptr;
    Expr *to = nullptr;

    Blck *body = nullptr;
    For *Copy() const override {
        For& self = *new For(*this);
        self.from = ::Copy(from);
        self.to = ::Copy(to);
        self.body = ::Copy(body);
        return &self;
    }
    void SetFromTo(Expr *from, Expr *to){
        For::from = from;
        For::to = to;
        assert(from && to);
    }
    void SetExpr(Expr *expr){
        from = expr;
        assert(!to);
    }
    
    void Visit(IVisitor& visit)override{
        assert(from || (from && to) && body);
        visit.IsFor(*this);
    }
    void VisitChildren(IVisitor& visitor){
        assert(from || (from && to) && body);
        from->Visit(visitor);
        to->Visit(visitor);
        body->Visit(visitor);
    }
};

struct If : public Node {
    Expr *condition = nullptr;
    Blck *trueBody = nullptr;
    Blck *falseBody = nullptr;
    If *Copy() const override {
        If& self = *new If;
        self.condition = ::Copy(condition);
        self.trueBody = ::Copy(trueBody);
        self.falseBody = ::Copy(falseBody);
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsIf(*this); }
    void VisitChildren(IVisitor& visitor){
        condition->Visit(visitor);
        trueBody->Visit(visitor);
        if(falseBody)
            falseBody->Visit(visitor);
    }
};

struct Return : public Node {
    Expr *expr = nullptr;
    Return *Copy() const override {
        Return& self = *new Return;
        self.expr = ::Copy(expr);
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsReturn(*this); }
    void VisitChildren(IVisitor& visitor){
        expr->Visit(visitor);
    }
};

struct CastExpr : public Expr {
    Expr *expr = nullptr;
    CastExpr *Copy() const override {
        CastExpr& self = *new CastExpr;
        self.expr = ::Copy(expr);
        self.type = ::Copy(type);
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsCastExpr(*this); }
};

struct ConstNumber : public Expr {
    string value;
    ConstNumber *Copy() const override {
        ConstNumber& self = *new ConstNumber;
        self.value = value;
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsConstNumber(*this); }
};

struct ConstString : public Expr {
    string value;
    ConstString *Copy() const override {
        ConstString& self = *new ConstString;
        self.value = value;
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsConstString(*this); }
};

struct Directive : public Node {
    string value;
    void Visit(IVisitor& visit)override{ visit.IsNode(*this); }
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
    
    Binary *Copy() const override {
        Binary& self = *new Binary;
        self.op = op;
        self.coord = coord;
        self.left = ::Copy(left);
        self.right = ::Copy(right);
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsBinary(*this); }
    void VisitChildren(IVisitor& visitor){
        left->Visit(visitor);
        right->Visit(visitor);
    }
};

struct Unary : public Expr {
    Lexer::Symbol op = Lexer::Illegal;
    Expr* expr = nullptr;
    Unary *Copy() const override {
        Unary& self = *new Unary;
        self.coord = coord;
        self.op = op;
        self.expr = ::Copy(expr);
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsUnary(*this); }
    void VisitChildren(IVisitor& visitor){
        expr->Visit(visitor);
    }
};

struct Access : public Expr {
    Expr* operand = nullptr;
    string field;
    
    Access *Copy() const override {
        Access& self = *new Access;
        self.coord = coord;
        self.operand = ::Copy(operand);
        self.field = field;
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsAccess(*this); }
};

struct Call : public Expr {
    Expr* operand = nullptr;
    ExprList *params = nullptr;

    Variable *fn = nullptr;

    Call *Copy() const override {
        Call& self = *new Call;
        self.coord = coord;
        self.operand = ::Copy(operand);
        self.params = ::Copy(params);
        return &self;
    }
    
    void Visit(IVisitor& visit)override{ visit.IsCall(*this); }
};

