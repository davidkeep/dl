//
//  Typel.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Expr.h"

struct Enum;
struct Struct;
struct Func;
struct Type;
struct Variable;
struct ConstNumber;

struct Var : public Expr {
    Var(){
        kind = Ast::Var;
    }
    string name;
    Variable *def = nullptr;
};
struct UninitializedExpr : public Expr {
};

struct NilExpr : public Expr {
};

enum struct AnnotatedState {
    None = 0,
    Declared,
    Annotating,
    Annotated,
};

class TypeAny;
class Variable;
class TypeList;
class TypePtr;
class TypeGen;
class TypeVar;
class TypeType;
class TypeFn;

struct Type : public Expr
{
    bool temporary = false;
    bool ref = false;
    bool mut = true;
protected:
    Type(){};
};
struct Def {};
struct Variable: public Type {
    Variable(){
        kind = Ast::Variable;
    }

    string ident;
    bool ref = false;
    Type *type = nullptr;
    Expr *assign = nullptr;
    bool top = false;
    AnnotatedState annotated = AnnotatedState::None;
};

struct TypeVar: public Type {
    TypeVar(){
        kind = Ast::TypeVar;
    }

    string ident;
    Type *type = nullptr;
};

struct TypeName{
    string ident;
    Type *dec = nullptr;
};
struct TypeList : public Type {
    static TypeList Empty;
    TypeList(){
        kind = Ast::TypeList;
    }
    void Add(const string& ident, Type& type){
        list.Push({ident, &type});
    }

    Type *type = nullptr;
    Array<TypeName> list;
    
    TypeName operator[](int index){
        return list[index];
    }
};

struct ExprList : public Expr {
    ExprList(){
        kind = Ast::ExprList;
    }
    
    Def *def = nullptr;
    Array<Expr&> list;
    
    Expr& operator[](int index){
        return list[index];
    }
    struct iterator : public vector<Expr*>::iterator {
        iterator(vector<Expr*>::iterator v):
        vector<Expr*>::iterator(v){
        }
        Expr& operator*(){
            return *vector<Expr*>::iterator::operator*();;
        }
    };
    Expr** begin() {
        return list.data;
    }
    Expr** end() {
        return list.data + list.length;
    }
    Expr* const* begin()const {
        return list.data;
    }
    Expr* const* end()const {
        return list.data + list.length;
    }
};

struct TypeGen : public Type {
    TypeGen(){
        kind = Ast::TypeGen;
    }
    Struct *generic = nullptr;
    
    Type* type = nullptr;
    Type* typeGeneric = nullptr;
    vector<Type*> constraints;
};

struct TypeType : public Type {
    TypeType(){
        kind = Ast::TypeType;
    }
    Type* type = nullptr;
};

struct TypePtr : public Type {
    TypePtr(){
        kind = Ast::TypePtr;
    }
    Type* pointed = nullptr;
};

struct TypeArray : public Type {
    TypeArray(){
        kind = Ast::TypeArray;
    }
    Type* type = nullptr;
    ConstNumber* size = nullptr;
};

struct TypeAny : public Variable {
    TypeAny(){
        kind = Ast::TypeAny;
    }
};

struct TypeFn : public Type {
    TypeFn(){
        kind = Ast::TypeFn;
    }

    TypeList params;
    TypeList results;
};

struct TypeFns : public Variable {
    TypeFns(){
        kind = Ast::TypeFns;
    }
    vector<Variable*> functions;
};

inline bool IsDeclared(Variable& variable){
    return variable.annotated != AnnotatedState::None;
}
inline bool RequiresAnnotating(Variable& variable){
    return variable.annotated != AnnotatedState::Annotated && variable.annotated != AnnotatedState::Annotating;
}
inline bool IsAnnotating(Variable& variable){
    return variable.annotated == AnnotatedState::Annotating;
}
