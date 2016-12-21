//
//  Decl.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Expr.h"

struct Enum;
struct Struct;
struct Func;
struct Dec;
struct Variable;
struct ConstNumber;

struct Var : public Expr {
    
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

struct Dec : public Expr
{
    bool temporary = false;
    bool ref = false;
    bool mut = true;
protected:
    Dec(){};
};
struct Def {};
struct Variable: public Dec {
    Variable(){
        kind = Ast::Variable;
    }

    string ident;
    bool ref = false;
    Dec *type = nullptr;
    Expr *assign = nullptr;
    bool top = false;
    AnnotatedState annotated = AnnotatedState::None;
};

struct TypeVar: public Dec {
    TypeVar(){
        kind = Ast::TypeVar;
    }

    string ident;
    Dec *type = nullptr;
};

struct DecName{
    string ident;
    Dec *dec = nullptr;
};
struct TypeList : public Dec {
    static TypeList Empty;
    TypeList(){
        kind = Ast::TypeList;
    }
    void Add(const string& ident, Dec& type){
        list.Push({ident, &type});
    }

    Dec *type = nullptr;
    Array<DecName> list;
    
    DecName operator[](int index){
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

struct TypeGen : public Dec {
    TypeGen(){
        kind = Ast::TypeGen;
    }
    Struct *generic = nullptr;
    
    Dec* type = nullptr;
    Dec* typeGeneric = nullptr;
    vector<Dec*> constraints;
};

struct TypeType : public Dec {
    TypeType(){
        kind = Ast::TypeType;
    }
    Dec* type = nullptr;
};

struct TypePtr : public Dec {
    TypePtr(){
        kind = Ast::TypePtr;
    }
    Dec* pointed = nullptr;
};

struct TypeArray : public Dec {
    TypeArray(){
        kind = Ast::TypeArray;
    }
    Dec* type = nullptr;
    ConstNumber* size = nullptr;
};

struct TypeAny : public Variable {
    TypeAny(){
        kind = Ast::TypeAny;
    }
};

struct TypeFn : public Dec {
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
