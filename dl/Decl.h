//
//  Decl.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Node.h"

struct Enum;
struct Struct;
struct Func;
struct Dec;

struct Expr : public Node {
    Dec *type = nullptr;
    Expr *Copy() const override {
        assert(false);
    }
};

struct Var : public Expr {
    
    string name;
    Variable *def = nullptr;
    Var *Copy() const override {
        Var& self = *new Var(*this);
        self.def = nullptr;
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsVar(*this); }
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

class DecAny;
class Variable;
class TypeList;
class TypePtr;
class TypeGen;
class TypeVar;
class TypeType;
class TypeFn;

struct Dec : public Node {
    virtual Dec *Copy() const override {
        assert(false);
        return nullptr;
    }

    bool temporary = false;
    bool ref = false;
    bool mut = true;
    
    enum Kind {
        None,
        Var,
        List,
        Type,
        Gen,
        Ptr,
        Any,
        Fn,
        Fns,
        Array
    } is;
    
    bool operator == (Kind is) const {
        return Dec::is == is;
    }
    
    TypeVar* IsVar(){
        if(is == Var) return (TypeVar*)this;
        return nullptr;
    }
    DecAny* IsAny(){

        if(is == Any) return (DecAny*)this;
        return nullptr;
    }
    TypeList* IsList(){
        if(is == List) return (TypeList*)this;
        return nullptr;
    }
    TypeGen* IsGen(){
        if(is == Gen) return (TypeGen*)this;
        return nullptr;
    }
    TypePtr* IsPtr(){
        if(is == Ptr) return (TypePtr*)this;
        return nullptr;
    }
    const TypeVar* IsVar() const{
        if(is == Var) return (const TypeVar*)this;
        return nullptr;
    }
    const DecAny* IsAny() const{
        if(is == Any) return (const DecAny*)this;
        return nullptr;
    }
    const TypeList* IsList() const{
        if(is == List) return (const TypeList*)this;
        return nullptr;
    }
    const TypeGen* IsGen() const{
        if(is == Gen) return (const TypeGen*)this;
        return nullptr;
    }
    const TypePtr* IsPtr() const{
        if(is == Ptr) return (const TypePtr*)this;
        return nullptr;
    }
    TypeFn* IsFn() {
        if(is == Fn) return (TypeFn*)this;
        return nullptr;
    }
     const TypeFn* IsFn() const{
        if(is == Fn) return (const TypeFn*)this;
        return nullptr;
    }
    TypeType* IsType(){
        if(is == Type) return (TypeType*)this;
        return nullptr;
    }
    const TypeType* IsType() const{
        if(is == Type) return (const TypeType*)this;
        return nullptr;
    }
protected:
    Dec(){};
};
struct Def {};
struct Variable: public Dec {
    Variable(){
    }
    Variable *Copy() const override {
        auto variable = new Variable(*this);
        variable->type = ::Copy(type);
        variable->assign = ::Copy(assign);
        return variable;
    }
    string ident;
    bool ref = false;
    Dec *type = nullptr;
    Expr *assign = nullptr;
    bool top = false;
    AnnotatedState annotated = AnnotatedState::None;
    void Visit(IVisitor& visit)override{ visit.IsVariable(*this); }
};

struct TypeVar: public Dec {
    TypeVar(){
        is = Var;
    }

    string ident;
    Dec *type = nullptr;
    
    TypeVar *Copy() const override {
        TypeVar& self = *new TypeVar(*this);
        self.type = nullptr;
        return &self;
    }
};

struct DecName{
    DecName(const string&ident, Dec* dec):
    ident(ident),
    dec(dec)
    {}
    string ident;
    Dec *dec = nullptr;
};
struct ListDef;
struct TypeList : public Dec {
    static TypeList Empty;
    TypeList(){
        is = List;
    }
    void Add(const string& ident, Dec& type){
        list.emplace_back(ident, &type);
    }

    Dec *type = nullptr;
    vector<DecName> list;
    
    DecName operator[](int index){
        return list[index];
    }
    struct iterator : public vector<DecName>::iterator{
        iterator(vector<DecName>::iterator v):
        vector<DecName>::iterator(v){
        }
    };
    iterator begin(){
        return list.begin();
    }
    iterator end(){
        return list.end();
    }
    TypeList *Copy() const override {
        TypeList& self = *new TypeList(*this);
        self.type = nullptr;
        for(auto &item : self.list){
            item.dec = item.dec->Copy();
        }
        return &self;
    }
};

struct ExprList : public Expr {
    ExprList(){
    }
    
    Def *def = nullptr;
    vector<Expr*> list;
    
    Expr& operator[](int index){
        return *list[index];
    }
    struct iterator : public vector<Expr*>::iterator {
        iterator(vector<Expr*>::iterator v):
        vector<Expr*>::iterator(v){
        }
        Expr& operator*(){
            return *vector<Expr*>::iterator::operator*();;
        }
    };
    iterator begin() {
        return list.begin();
    }
    iterator end() {
        return list.end();
    }

    void Visit(IVisitor& visit)override{ visit.IsExprList(*this); }
    void VisitChildren(IVisitor& visitor){
        for(auto expr : list){
            expr->Visit(visitor);
        }
    }
    ExprList *Copy() const override {
        ExprList& self = *new ExprList(*this);
        self.list = ::Copy(list);
        return &self;
    }
};

struct TypeGen : public Dec {
    TypeGen(){
        is = Gen;
    }
    Struct *generic = nullptr;
    
    Dec* type = nullptr;
    Dec* typeGeneric = nullptr;
    vector<Dec*> constraints;
    TypeGen *Copy() const override {
        TypeGen& self = *new TypeGen(*this);
        self.generic = nullptr;
        self.type = ::Copy(type);
        self.typeGeneric = ::Copy(typeGeneric);
        for(auto &item : self.constraints){
            item = ::Copy(item);
        }
        return &self;
    }
};

struct TypeType : public Dec {
    TypeType(){
        is = Type;
    }
    Dec* type = nullptr;
    TypeType *Copy() const override {
        TypeType& self = *new TypeType(*this);
        self.type = ::Copy(type);
        return &self;
    }
};

struct TypePtr : public Dec {
    TypePtr(){
        is = Ptr;
    }
    Dec* pointed = nullptr;
    TypePtr *Copy() const override {
        TypePtr& self = *new TypePtr(*this);
        self.pointed = ::Copy(pointed);
        return &self;
    }
};

struct TypeArray : public Dec {
    TypeArray(){
        is = Array;
    }
    Dec* type = nullptr;
    ConstNumber* size = nullptr;
};

struct DecAny : public Variable {
    DecAny(){
        is = Any;
    }
    DecAny *Copy() const override {
        DecAny& self = *new DecAny(*this);
        self.type = ::Copy(type);
        return &self;
    }
};

struct TypeFn : public Dec {
    TypeFn(){
        is = Fn;
    }

    TypeList params;
    TypeList results;

    TypeFn *Copy() const override {
        TypeFn& self = *new TypeFn(*this);
        for (auto& item : self.params){
            item.dec = item.dec->Copy();
        }
        for (auto& item : self.results){
            item.dec = item.dec->Copy();
        }
        return &self;
    }
};

struct TypeFns : public Variable {
    TypeFns(){
        is = Fns;
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
