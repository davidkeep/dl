//
//  Expr.h
//  Created by David on 5/27/16.
//

#pragma once
#include "Symbol.h"
#include "Token.h"

struct Blck;

enum class Ast
{
    None,
    //Operators
    Call,   // ()
    Binary, // +, -, *, /, %, &, &&, |, ||,
    Unary,  // -, ^, &
    Access, // .
    
    //Control
    For,    // for <Expression> {} or for <Expression> .. <Expression> {}
    If,     // if <Expression> {} else {}
    Blck,
    Using,

    
    //Definitions
    Enum,   // enum <Identifier> {}
    Func,   // fn <Identifier>(<Type>, ...) {}
    Struct, // struct <Identifier> {} or struct <Identifier>(<Type>, ...) {}
    
    StructIntrins,
    FuncIntrins,
    
    ExprList,
    Directive,
    Return,
    CastExpr,
    ConstNumber,
    ConstString,
    Var,
    Variable,
    
    //Types
    TypeArray,
    TypeVar,
    TypeType,
    TypePtr,
    TypeFn,
    TypeFns,
    TypeGen,
    TypeAny,
    TypeList,
};

inline bool IsType(Ast kind) {
    return kind >= Ast::TypeArray && kind <= Ast::TypeList;
}

#define VISIT_IF(Type, visitor, node) case Ast::Type: ::Visit(visitor, cast<Type>(node)); break;
#define VISTOR(visitor, node) switch (node.kind) {\
VISIT_IF(Call, visitor, node);\
VISIT_IF(Binary, visitor, node);\
VISIT_IF(Unary, visitor, node);\
VISIT_IF(Access, visitor, node);\
\
VISIT_IF(Enum, visitor, node);\
VISIT_IF(Func, visitor, node);\
VISIT_IF(Struct, visitor, node);\
VISIT_IF(StructIntrins, visitor, node);\
VISIT_IF(FuncIntrins, visitor, node);\
\
VISIT_IF(For, visitor, node);\
VISIT_IF(If, visitor, node);\
VISIT_IF(Return, visitor, node);\
VISIT_IF(Directive, visitor, node);\
VISIT_IF(CastExpr, visitor, node);\
VISIT_IF(ConstNumber, visitor, node);\
VISIT_IF(ConstString, visitor, node);\
VISIT_IF(Blck, visitor, node);\
VISIT_IF(ExprList, visitor, node);\
VISIT_IF(Variable, visitor, node);\
VISIT_IF(Var, visitor, node);\
VISIT_IF(Using, visitor, node);\
\
VISIT_IF(TypeArray, visitor, node);\
VISIT_IF(TypeVar, visitor, node);\
VISIT_IF(TypeType, visitor, node);\
VISIT_IF(TypeAny, visitor, node);\
VISIT_IF(TypePtr, visitor, node);\
VISIT_IF(TypeFn, visitor, node);\
VISIT_IF(TypeFns, visitor, node);\
VISIT_IF(TypeGen, visitor, node);\
VISIT_IF(TypeList, visitor, node);\
default: printf("%d", node.kind); assert(false && "Unhandled type");\
}

#define VISIT_IF_PARENT(Type, visitor, node, parent) case Ast::Type: ::Visit(visitor, cast<Type>(node), parent); break;
#define VISTOR_PARENT(visitor, node, parent) switch (node.kind) {\
VISIT_IF_PARENT(Call, visitor, node, parent);\
VISIT_IF_PARENT(Binary, visitor, node, parent);\
VISIT_IF_PARENT(Unary, visitor, node, parent);\
VISIT_IF_PARENT(Access, visitor, node, parent);\
\
VISIT_IF_PARENT(Enum, visitor, node, parent);\
VISIT_IF_PARENT(Func, visitor, node, parent);\
VISIT_IF_PARENT(Struct, visitor, node, parent);\
VISIT_IF_PARENT(StructIntrins, visitor, node, parent);\
VISIT_IF_PARENT(FuncIntrins, visitor, node, parent);\
\
VISIT_IF_PARENT(For, visitor, node, parent);\
VISIT_IF_PARENT(If, visitor, node, parent);\
VISIT_IF_PARENT(Return, visitor, node, parent);\
VISIT_IF_PARENT(Directive, visitor, node, parent);\
VISIT_IF_PARENT(CastExpr, visitor, node, parent);\
VISIT_IF_PARENT(ConstNumber, visitor, node, parent);\
VISIT_IF_PARENT(ConstString, visitor, node, parent);\
VISIT_IF_PARENT(Blck, visitor, node, parent);\
VISIT_IF_PARENT(ExprList, visitor, node, parent);\
VISIT_IF_PARENT(Variable, visitor, node, parent);\
VISIT_IF_PARENT(Var, visitor, node, parent);\
VISIT_IF_PARENT(Using, visitor, node, parent);\
\
VISIT_IF_PARENT(TypeArray, visitor, node, parent);\
VISIT_IF_PARENT(TypeVar, visitor, node, parent);\
VISIT_IF_PARENT(TypeType, visitor, node, parent);\
VISIT_IF_PARENT(TypeAny, visitor, node, parent);\
VISIT_IF_PARENT(TypePtr, visitor, node, parent);\
VISIT_IF_PARENT(TypeFn, visitor, node, parent);\
VISIT_IF_PARENT(TypeFns, visitor, node, parent);\
VISIT_IF_PARENT(TypeGen, visitor, node, parent);\
VISIT_IF_PARENT(TypeList, visitor, node, parent);\
default: printf("%d", node.kind); assert(false && "Unhandled type");\
}

struct Type;
struct Expr
{
    Ast kind = Ast::None;
    Coord coord;
    Type* type = nullptr;
    
    bool operator == (Ast kind) const {
        return Expr::kind == kind;
    }
    bool operator != (Ast kind) const {
        return !operator==(kind);
    }
#ifdef DEBUG
    virtual ~Expr(){} //This can be removed along with the assert(dynamic_cast) check in cast<T>
#endif
};

template<class T, class F>
T* cast(F* t){
#ifdef DEBUG
    assert(dynamic_cast<T*>(t) && "failed cast");
#endif
    return (T*)t;
}

template<class T, class F>
T& cast(F& t){
#ifdef DEBUG
    assert(dynamic_cast<T*>(&t) && "failed cast");
#endif
    return (T&)t;
}

template<class T, class F>
T& is(const F& t){
#ifdef DEBUG
    assert(dynamic_cast<const T*>(&t) && "failed cast");
#endif
    return (T&)t;
}

template<class T, class F>
T* is(F* t){
#ifdef DEBUG
    assert(dynamic_cast<T*>(t) && "failed cast");
#endif
    return (T*)t;
}





