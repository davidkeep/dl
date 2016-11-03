//
//  Control.h
//  Created by David on 5/28/16.
//

#pragma once
#include "Block.h"

struct If : public Node
{
    Expression *condition;
    Block thenBlock;
    Block elseBlock;
    bool clone = false;
    
    If(Expression *condition):
    condition(condition)
    {}
    
    If* Clone() const override;
    void Scope(Block *parent) override;
    
    void VisitChildren(Visitor &visitor)
    {
        condition->Visit(visitor);
        thenBlock.Visit(visitor);
        elseBlock.Visit(visitor);
    }
    void Visit(Visitor &visitor) override{
        visitor.Accept(*this);
    }
};

struct For : public Node
{
    Node *pre = nullptr;
    Expression *condition = nullptr;
    Expression *post = nullptr;
    Node *block = nullptr;

    For* Clone() const override
    {
        auto r = new For(condition->Clone());
        if(post){
            r->post = post->Clone();
        }
        if(block){
            r->block = block->Clone();
        }
        return r;
    }
    
    For(Expression *condition):
    condition(condition)
    {
        
    }
    
    void Scope(Block *parent) override
    {
        assert(parent);
        Node::Scope(parent);
        if(post)
            post->Scope(parent);
        condition->Scope(parent);
        if(pre)
            pre->Scope(parent);
        
        block->Scope(parent);
    }

    void VisitChildren(Visitor &visitor)
    {
        if(pre)
            pre->Visit(visitor);
        condition->Visit(visitor);
        if(post)
            post->Visit(visitor);
        
        block->Visit(visitor);
    }
    
    void Visit(Visitor &visitor) override{
        visitor.Accept(*this);
    }
};
