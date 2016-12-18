//
//  Symbol.h
//  Created by David on 5/21/16.
//

#pragma once
#include <string>
#include <map>
#include <vector>

#include <exception>
#include <assert.h>

using string = std::string;

template<class T>
using vector = std::vector<T>;

template<class Key, class Value>
using table = std::map<Key, Value>;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define _visit_fns_empty(TYPE)virtual void Is##TYPE(TYPE &node) = 0
#define _visit_fns(TYPE) void Is##TYPE(TYPE &node) override { IsUnhandled((Node&)node); }
#define _visit_Def(TYPE)struct TYPE

#define _visit_types(Do)\
Do(Node);\
Do(If);\
Do(For);\
Do(Return);\
\
Do(Binary);\
Do(Unary);\
Do(Call);\
Do(Access);\
\
Do(ConstString);\
Do(ConstNumber);\
\
Do(Var);\
Do(Blck);\
Do(ExprList);\
Do(CastExpr);\
\
Do(Variable);\
Do(Func);\
Do(Enum);\
Do(Struct);\
Do(IntrinsicFunc);\
Do(IntrinsicStruct);\

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
