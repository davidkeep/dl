//
//  Def.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Node.h"
#include "Decl.h"
#include "Ast.h"

static int definitonCount = 0;

struct Func : public Variable {
    TypeList params;
    TypeList results;

    Blck* body = nullptr;
    bool external = false;
    bool generic = false;
    int id = definitonCount++;
    table<string, DecAny*> unknown;
    Func(){
        this->ident = "";
    }
    Func *Copy() const override {
        Func& self = *new Func;

        self.results = results;
        self.params = params;
        self.unknown = unknown;
        self.coord = coord;
        
        for(auto &item : self.results){
            item.dec = ::Copy(item.dec);
        }
        for(auto &item : self.params){
            item.dec = ::Copy(item.dec);
        }
        for(auto &item : self.unknown){
            item.second = ::Copy(item.second);
        }

        self.body = ::Copy(body);
        
        self.external = external;
        self.generic = generic;
        return &self;
    }
    void Visit(IVisitor& visit)override{ visit.IsFunc(*this); }

    vector<Func*> specializations;
};

struct Enum : public Variable
{
    void Add(const string& value){
    }
    void Visit(IVisitor& visit)override{ visit.IsEnum(*this); }
};

struct Struct : public Variable {

    bool Generic()const{ return constraints.size() && !specialization; }
    bool specialization = false;
    bool stub = false;
    bool incomplete = false;
    bool Empty() {
        return fields.size() == 0;
    }
    int id = definitonCount++;
    
    Struct(){
       // type = this;
    }
    
    Struct *generic = nullptr;
    Variable *typeinfo = nullptr;
    
    vector<Dec*> constraints;
    
    Blck block;
    
    void AddField(string ident, Dec& type){
        auto var = new Variable;
        var->type = &type;
        var->ident = ident;
        fields.push_back(var);
    }
    
    vector<Variable*> fields;

    void Visit(IVisitor& visit)override{ visit.IsStruct(*this); }
    void VisitChildren(IVisitor& visitor){
        for(auto field : fields){
            field->Visit(visitor);
        }
    }
    
    Struct *Copy() const override {
        Struct& self = *new Struct;
        self.fields = ::Copy(fields);
        self.constraints = ::Copy(constraints);
        self.generic = generic;
        return &self;
    }
    vector<Struct*> specializations;
};

struct ListDef : public Dec {
    TypeList *list = nullptr;
};
