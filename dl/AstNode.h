//
//  AstNode.h
//  Created by David on 12/17/16.
//

#pragma once

#include "Ast.h"
#include "Def.h"

enum class AstKind
{
    //Operators
    Call,   // ()
    Binary, // +, -, *, /, %, &, &&, |, ||,
    Unary,  // -, ^, &
    Access, // .
    
    //Control
    For,    // for <Expression> {} or for <Expression> .. <Expression> {}
    If,     // if <Expression> {} else {}
    
    //Definitions
    Enum,   // enum <Identifier> {}
    Func,   // fn <Identifier>(<Type>, ...) {}
    Struct, // struct <Identifier> {} or struct <Identifier>(<Type>, ...) {}
    
    //Types
    TypeArray,
    TypeVar,
    TypeType,
    TypePtr,
    TypeFn,
    TypeFns,
    TypeGen,
    TypeList,
};

#define VISIT_IF(Type, visitor, node) case AstKind::Type: Visit(visitor, node.Type)
#define VISTOR(visitor, node) switch (node.kind) {\
VISIT_IF(Call, visitor, node);\
VISIT_IF(Binary, visitor, node);\
VISIT_IF(Unary, visitor, node);\
VISIT_IF(Access, visitor, node);\
\
VISIT_IF(Enum, visitor, node);\
VISIT_IF(Func, visitor, node);\
VISIT_IF(Struct, visitor, node);\
\
VISIT_IF(For, visitor, node);\
VISIT_IF(If, visitor, node);\
\
VISIT_IF(TypeArray, visitor, node);\
VISIT_IF(TypeVar, visitor, node);\
VISIT_IF(TypeType, visitor, node);\
VISIT_IF(TypePtr, visitor, node);\
VISIT_IF(TypeFn, visitor, node);\
VISIT_IF(TypeFns, visitor, node);\
VISIT_IF(TypeGen, visitor, node);\
VISIT_IF(TypeList, visitor, node);\
}

struct AstNode
{
    AstKind kind;
    union
    {
        Call Call;
        Binary Binary;
        Unary Unary;
        Access Access;
        
        Enum Enum;
        Func Func;
        Struct Struct;
        
        For For;
        If If;
        
        TypeArray TypeArray;
        TypeVar TypeVar;
        TypeType TypeType;
        TypePtr TypePtr;
        TypeFn TypeFn;
        TypeFns TypeFns;
        TypeGen TypeGen;
        TypeList TypeList;
    };
};


