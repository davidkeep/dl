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
    
    table<string, Variable*> variables;
    table<string, vector<FuncDef*>> functions;

    Blck *Copy() const override;
    
    void Add(Node*child){ assert(child); children.push_back(child); }
    
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
        For& self = *new For;
        self.from = ::Copy(from);
        self.to = ::Copy(to);
        self.body = ::Copy(body);
        return &self;
    }
    void SetFromTo(Expr *from, Expr *to){
        For::from = from;
        For::to = to;
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

struct Cast : public Expr {
    Expr *expr = nullptr;
    Cast *Copy() const override {
        Cast& self = *new Cast;
        self.expr = ::Copy(expr);
        self.type = ::Copy(type);
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsCast(*this); }
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