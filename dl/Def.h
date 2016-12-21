//
//  Def.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Decl.h"
#include "Ast.h"

static int definitonCount = 0;

struct Func : public Variable {
    TypeList params;
    TypeList results;

    Blck* body = nullptr;
    bool external = false;
    Func* generic = nullptr;
    int id = definitonCount++;
    table<string, TypeAny*> unknown;
    Func(){
        this->ident = "";
    }

    vector<Func*> specializations;
};

struct Enum : public Variable
{
    void Add(const string& value){
    }
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

    vector<Struct*> specializations;
};


struct FuncIntrins : public Func {
    
};

struct StructIntrins : public Struct {
    StructIntrins(){
        kind = Ast::StructIntrins;
    }
};
