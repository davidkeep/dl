//
//  CodeGen.h
//  Created by David on 8/22/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
#include "Decl.h"
#include <fstream>
#include "Printing.h"
#include <sstream>
#include "Semantic.h"
#include <typeinfo>
#include <iostream>
#include "Compiler.h"
#include <unistd.h>

struct Project;
struct CodeGen : public Visitor
{
    CodeGen(Project& project, Semantic &semantic);

    void IsUnhandled(Node &self) override;
    void IsBlck(Blck &self) override;
    
    void IsExprList(ExprList &self) override;
    void IsCastExpr(CastExpr &cast) override;
    void IsCall(Call &call) override;

    void IsBinaryOp(BinaryOp &op) override;
    void IsUnaryOp(UnaryOp &op) override;
    void IsFieldAccess(FieldAccess &field) override;
    
    void IsVariable(Variable &decl)override;
    void IsStructDef(StructDef &def) override;
    void IsEnumDef(EnumDef &def) override;
    void IsFuncDef(FuncDef &def) override;

    void IsFor(For &loop) override;
    void IsIf(If &ifStatement) override;
    void IsReturn(Return &ret) override;
    void IsVar(Var &var)override;
    void IsConstNumber(ConstNumber &num)override;
    void IsConstString(ConstString &str)override;
    void IsIntrinsicFuncDef(IntrinsicFuncDef &def)override;
    void IsIntrinsicStructDef(IntrinsicStructDef &def)override;
    
private:
    void GenerateCodeFor(IntrinsicFuncDef &def, ExprList&args);
    string CodeFor(Dec&decl);
    void CodeFor(Dec&decl, string &result);

    std::stringstream fns;
    std::stringstream structs;
    int fnptrCount = 0;
    
    table<DecList*,int> tuples;

    vector<Blck*> scopes;
    Blck *parent;
    std::ofstream out;
    std::ofstream header;
    int level = 0;
    string inset;
    Semantic &semantic;
    bool top = true;
    
};
