//
//  Semantic.h
//  Created by David on 8/20/16.
//

#pragma once
#include "Ast.h"
#include "Printing.h"
#include "Intrinsics.h"
#include "Annotate.h"
#include "Match.h"

enum TypeCheck {
    Failed = 0,     //Fully failed type test
    RequiresAny,    //This is a failure in many cases
    Conversion,     //Required a conversion to pass
    Passed,         //Types are fully equal
};

enum class AnnotateEvent
{
    None            = 0,
    Failed          = 1 << 1,
    Any         = 1 << 2,
};


struct Project;
struct Semantic;

void Declare(Semantic &self, const string& name, Variable& variable);
inline void Declare(Semantic &self, Variable& variable){
    Declare(self, variable.ident, variable);
}

AnnotateEvent AnnotateParam(Semantic &self, Type&decl, bool declareAny = true, bool findAny = false);
bool AnnotateConstraint(Type&dec, Type&constraint, Blck& block);

struct TypeInfo
{
    int indirection = 0;
    Struct *type = nullptr;
    Variable *def = nullptr;
};

void Redeclare(Semantic &self, const string& name, Variable& variable);

struct Scope
{
    Blck& Current() { return blocks[blocks.length - 1]; }
    
    void Push(Blck& block) { return blocks.Push(block); }
    void Pop() { return blocks.Pop(); }
    
    Array<Blck&> blocks;
};

struct Semantic
{
    Array<TypeList*> listDefs;
    Array<Variable*> varDefs;
    Array<Type*> defs;
    Array<TypeInfo> typeinfo;
    bool firstPass = true;
    void Visit(Expr& node);
    Semantic(Project& project);    
    Array<Scope&> scopes;
};

