//
//  Constants.h
//  Created by David on 5/25/16.
//

#pragma once
#include "SyntaxTree.h"

class Constant : public Expression
{};

class ConstantNumber : public Constant
{
public:
    ConstantNumber(const std::string &value, LineInformation source) :
    value(value)
    {
        this->source = source;
    }
    ConstantNumber*Clone() const override
    {
        return new ConstantNumber(*this);
    }

    std::string value;
    void Visit(Visitor &visitor) override{
        visitor.Accept(*this);
    }
};

class ConstantString : public Constant
{
public:
    std::string value;

    ConstantString(const std::string &value, LineInformation source):
    value(value){
        Node::source = source;
    }
    
    ConstantString* Clone() const override{
        return new ConstantString(*this);
    }
    
    void Visit(Visitor &visitor) override{
        visitor.Accept(*this);
    }
};