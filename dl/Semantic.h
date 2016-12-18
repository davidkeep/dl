//
//  Semantic.h
//  Created by David on 8/20/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
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
    AnyDecl         = 1 << 2,
};


struct Project;
class Semantic;
void Declare(Semantic &self, const string& name, Variable& variable);
inline void Declare(Semantic &self, Variable& variable){
    Declare(self, variable.ident, variable);
}

AnnotateEvent AnnotateParam(Semantic &self, Dec&decl, bool declareAny = true, bool findAny = false);
bool AnnotateConstraint(Dec&dec, Dec&constraint, Blck& block);

struct TypeInfo
{
    int indirection = 0;
    Struct *type = nullptr;
    Variable *def = nullptr;
};

void Redeclare(Semantic &self, const string& name, Variable& variable);

class Semantic : public Visitor
{
public:
    vector<ListDef*> listDefs;
    vector<Variable*> varDefs;
    vector<Dec*> defs;
    vector<TypeInfo> typeinfo;
    vector<Func*> Funcs;

    vector<Blck*> scopes;
    
    bool firstPass = true;
    
    Semantic(Project& project);
    
    void IsBlck(Blck &self) override;
    void IsExprList(ExprList &self) override;
    void IsCastExpr(CastExpr &cast) override;
    void IsBinary(Binary &op) override;
    void IsUnary(Unary &op) override;
    void IsAccess(Access &field, bool silent);
    void IsAccess(Access &field) override;
    void IsCall(Call &call) override;
    void IsStruct(Struct &def) override;
    void IsEnum(Enum &def) override;
    void IsFunc(Func &def) override;
    void IsIntrinsicFunc(IntrinsicFunc &def) override;
    void IsIntrinsicStruct(IntrinsicStruct &def) override;
    void IsVariable(Variable &def) override;
    void IsVar(Var &var) override;
    void IsConstNumber(ConstNumber &num) override;
    void IsConstString(ConstString &str) override;
    void IsReturn(Return &ret) override;
    void IsIf(If &statement) override;
    void IsFor(For &loop) override;
};
