//
//  Completetion.h
//  Created by David on 12/24/16.
//

#pragma once
#include "Token.h"

struct Expr;
struct Type;
struct Func;

struct Completions {
    struct Def
    {
        Func* func = nullptr;
        string hint;
        string paste;
    };
    
    vector<Def> functions;
    vector<Def> variables;
    
    void Visit(Expr& expr);
    void PrintSuggestions(const string& filter);
    void PrintFunctionSuggestionsForExpr(Expr& expr);
};

struct FindExpressionAt
{
    //The list of expressions found
    //The last object in the list is the specific expression followed by the nodes parents
    //Since a node could have many parents we don't track them
    Array<Expr&> expressions;
    
    int targetLine;
    int targetColumn;
    
    FindExpressionAt(Expr& file, int line, int column);
    void Visit(Expr& expr);
};
