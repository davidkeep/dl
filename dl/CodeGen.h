//
//  CodeGen.h
//  Created by David on 8/22/16.
//

#pragma once
#include "Ast.h"
#include "Type.h"
#include <fstream>
#include "Printing.h"
#include <sstream>
#include "Semantic.h"
#include <typeinfo>
#include <iostream>
#include "Compiler.h"
#include <unistd.h>

struct Project;
string WorkingDirectory();

struct CodeGen
{
    CodeGen(Project& project, Semantic &semantic);
    void Visit(Expr& expr);
    
    void GenerateCodeFor(FuncIntrins &def, ExprList&args);
    string CodeFor(Type&decl);
    void CodeFor(Type&decl, string &result);

    std::stringstream fns;
    std::stringstream structs;
    int fnptrCount = 0;
    
    table<TypeList*,int> tuples;

    vector<Blck*> scopes;
    Blck *parent;
    std::ofstream out;
    std::ofstream header;
    int level = 0;
    string inset;
    Semantic &semantic;
    bool top = true;
};
