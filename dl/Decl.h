//
//  Decl.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Node.h"

struct EnumDef;
struct StructDef;
struct FuncDef;
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
class DecList;
class DecPtr;
class DecGen;
class DecVar;
class DecType;
class DecFn;

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
    } is;
    
    DecVar* IsVar(){
        if(is == Var) return (DecVar*)this;
        return nullptr;
    }
    DecAny* IsAny(){
        if(is == Any) return (DecAny*)this;
        return nullptr;
    }
    DecList* IsList(){
        if(is == List) return (DecList*)this;
        return nullptr;
    }
    DecGen* IsGen(){
        if(is == Gen) return (DecGen*)this;
        return nullptr;
    }
    DecPtr* IsPtr(){
        if(is == Ptr) return (DecPtr*)this;
        return nullptr;
    }
    const DecVar* IsVar() const{
        if(is == Var) return (const DecVar*)this;
        return nullptr;
    }
    const DecAny* IsAny() const{
        if(is == Any) return (const DecAny*)this;
        return nullptr;
    }
    const DecList* IsList() const{
        if(is == List) return (const DecList*)this;
        return nullptr;
    }
    const DecGen* IsGen() const{
        if(is == Gen) return (const DecGen*)this;
        return nullptr;
    }
    const DecPtr* IsPtr() const{
        if(is == Ptr) return (const DecPtr*)this;
        return nullptr;
    }
     const DecFn* IsFn() const{
        if(is == Fn) return (const DecFn*)this;
        return nullptr;
    }
    DecType* IsType(){
        if(is == Type) return (DecType*)this;
        return nullptr;
    }
    const DecType* IsType() const{
        if(is == Type) return (const DecType*)this;
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


struct DecVar: public Dec {
    DecVar(){
        is = Var;
    }

    string ident;
    Dec *type = nullptr;
    
    DecVar *Copy() const override {
        DecVar& self = *new DecVar(*this);
        self.type = nullptr;
        return &self;
    }
};

struct VariableType {
    VariableType(const string&ident, Dec& type):
    ident(ident),
    type(&type)
    {}
    string ident;
    Dec *type = nullptr;
};

struct IdentifiedType {
    IdentifiedType(const string&ident, Dec& type):
    ident(ident),
    type(&type)
    {}
    string ident;
    Dec *type = nullptr;
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
struct DecList : public Dec {
    DecList(){
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
    DecList *Copy() const override {
        DecList& self = *new DecList(*this);
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
    struct iterator : public vector<Expr*>::iterator{
        iterator(vector<Expr*>::iterator v):
        vector<Expr*>::iterator(v){
        }
        Expr& operator*(){
            return *vector<Expr*>::iterator::operator*();;
        }
    };
    iterator begin(){
        return list.begin();
    }
    iterator end(){
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

struct DecGen : public Dec {
    DecGen(){
        is = Gen;
    }
    StructDef *generic = nullptr;
    
    Dec* type = nullptr;
    Dec* typeGeneric = nullptr;
    vector<Dec*> constraints;
    DecGen *Copy() const override {
        DecGen& self = *new DecGen(*this);
        self.type = ::Copy(type);
        self.typeGeneric = ::Copy(typeGeneric);
        for(auto &item : self.constraints){
            item = ::Copy(item);
        }
        return &self;
    }
};

struct DecType : public Dec {
    DecType(){
        is = Type;
    }
    Dec* type = nullptr;
    DecType *Copy() const override {
        DecType& self = *new DecType(*this);
        self.type = ::Copy(type);
        return &self;
    }
};

struct DecPtr : public Dec {
    DecPtr(){
        is = Ptr;
    }
    Dec* pointed = nullptr;
    DecPtr *Copy() const override {
        DecPtr& self = *new DecPtr(*this);
        self.pointed = ::Copy(pointed);
        return &self;
    }
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

struct DecFn : public Dec {
    DecFn(){
        is = Fn;
    }

    DecList args;
    DecList ret;

    DecFn *Copy() const override {
        DecFn& self = *new DecFn(*this);
        for (auto& item : self.args){
            item.dec = item.dec->Copy();
        }
        for (auto& item : self.ret){
            item.dec = item.dec->Copy();
        }
        return &self;
    }
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
