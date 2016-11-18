//
//  Symbol.h
//  Created by David on 5/21/16.
//

#pragma once
#include "Error.h"
#include <map>

using string = std::string;

template<class T>
using vector = std::vector<T>;

template<class Key, class Value>
using table = std::map<Key, Value>;

#define _visit_fns_empty(TYPE)virtual void Is##TYPE(TYPE &node) = 0
#define _visit_fns(TYPE) void Is##TYPE(TYPE &node) override { IsUnhandled((Node&)node); }
#define _visit_Def(TYPE)struct TYPE

#define _visit_types(Do)\
Do(Node);\
Do(If);\
Do(For);\
Do(Return);\
\
Do(BinaryOp);\
Do(UnaryOp);\
Do(Call);\
Do(FieldAccess);\
\
Do(ConstString);\
Do(ConstNumber);\
\
Do(Var);\
Do(Blck);\
Do(ExprList);\
Do(Cast);\
\
Do(Variable);\
Do(FuncDef);\
Do(EnumDef);\
Do(StructDef);\
Do(IntrinsicFuncDef);\
Do(IntrinsicStructDef);\


_visit_types(_visit_Def);

struct IVisitor
{
    _visit_types(_visit_fns_empty);
    template<class T>
    void VisitChildren(T &node)
    {
        node.VisitChildren(*this);
    }
    template<class T>
    void Visit(T &node)
    {
        node.Visit(*this);
    }
    virtual ~IVisitor(){}
};

struct Visitor : public IVisitor
{
    _visit_types(_visit_fns);
    virtual void IsUnhandled(Node &self) {
    }
};


