//
//  Def.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Node.h"
#include "Decl.h"
#include "Ast.h"

static int definitonCount = 0;

struct FuncDef : public Variable {
    DecList params;
    DecList results;

    Blck* body = nullptr;
    bool external = false;
    bool generic = false;
    int id = definitonCount++;
    table<string, DecAny*> unknown;
    FuncDef(){
        this->ident = "";
    }
    FuncDef *Copy() const override {
        FuncDef& self = *new FuncDef;

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
    void Visit(IVisitor& visit)override{ visit.IsFuncDef(*this); }

    vector<FuncDef*> specializations;
};

struct EnumDef : public Variable
{
    void Add(const string& value){
    }
    void Visit(IVisitor& visit)override{ visit.IsEnumDef(*this); }
};

struct StructDef : public Variable {

    bool Generic()const{ return constraints.size() && !specialization; }
    bool specialization = false;
    bool stub = false;
    bool incomplete = false;
    bool Empty() {
        return fields.size() == 0;
    }
    int id = definitonCount++;
    
    StructDef(){
       // type = this;
    }
    
    StructDef *generic = nullptr;
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

    void Visit(IVisitor& visit)override{ visit.IsStructDef(*this); }
    void VisitChildren(IVisitor& visitor){
        for(auto field : fields){
            field->Visit(visitor);
        }
    }
    
    StructDef *Copy() const override {
        StructDef& self = *new StructDef;
        self.fields = ::Copy(fields);
        self.constraints = ::Copy(constraints);
        self.generic = generic;
        return &self;
    }
    vector<StructDef*> specializations;
};

struct ListDef : public Dec {
    DecList *list = nullptr;
};
