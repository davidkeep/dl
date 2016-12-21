//
//  Match.h
//  Created by David on 12/17/16.
//

#pragma once
#include "Token.h"

struct Variable;
struct Semantic;
struct Dec;
struct TypeList;
struct ExprList;

Variable* Find(Semantic &self, const string& name,  Coord coord);
Variable* FindTypeInfo(Semantic &self, Dec&dec);

Variable* FindExactMatch(const string& name, Semantic& semantic, ExprList& args);
Variable* FindExactMatch(const string& name, Semantic& semantic, TypeList& args);
