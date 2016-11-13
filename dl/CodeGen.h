//
//  CodeGen.h
//  Created by David on 8/22/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
#include "Op.h"
#include "Decl.h"
#include <fstream>
#include "Printing.h"
#include <sstream>
#include "Semantic.h"
#include <typeinfo>
#include <iostream>
#include "Compiler.h"
#include <unistd.h>

template <class T, class From>
T& Cast(From &type) {
    assert(dynamic_cast<T*>(&type));
    return (T&)type;
}

inline std::string get_working_path()
{
    char temp[1024];
    return ( getcwd(temp, 1024) ? std::string( temp ) : std::string("") );
}

class CodeGen : public Visitor
{
public:
    std::stringstream fns;
    std::stringstream structs;
    int fnptrCount = 0;

    table<string,DecList*> tuples;
    
    vector<Blck*> scopes;
    Blck *parent;
    std::ofstream out;
    std::ofstream header;
    int level = 0;
    string inset;
    Semantic &semantic;
    bool top = true;

    CodeGen(const string& file, Semantic &semantic);
    
    void GenerateCodeFor(IntrinsicFuncDef &def, ExprList&args);
    string CodeFor(Dec&decl);

    void IsUnhandled(Node &self) override;
    void IsBlck(Blck &self) override;
    void IsExprList(ExprList &self) override;
    void IsCast(struct Cast &cast) override;
    void IsBinaryOp(BinaryOp &op) override;
    void IsUnaryOp(UnaryOp &op) override;
    void IsStructDef(StructDef &def) override;
    void IsEnumDef(EnumDef &def) override;
    void IsFor(For &loop) override;
    void IsIf(If &ifStatement) override;
    void IsReturn(Return &ret) override;
    void IsFuncDef(FuncDef &def) override;
    void IsVariable(Variable &decl)override;
    void IsVar(Var &var)override;
    void IsConstNumber(ConstNumber &num)override;
    void IsConstString(ConstString &str)override;
    void IsIntrinsicFuncDef(IntrinsicFuncDef &def)override;
    void IsIntrinsicStructDef(IntrinsicStructDef &def)override;
                
};
