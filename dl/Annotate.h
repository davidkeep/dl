//
//  Annotate.h
//  Created by David on 12/17/16.
//

#pragma once

struct Dec;
struct TypeList;
struct ExprList;
struct Expr;

bool Equal(Dec& left, Dec& right);
bool Convertable(Dec& from, Dec& to);

//@TODO remove this, replace with Equal or Convertable, they are very differn't beasts
//In the future convertable will also perform some extra work indentifiying the conversion required
bool TypeCheck(Dec&ll, Dec&rr, bool convert = true);
bool TypeCheck(TypeList&l, ExprList&r);

bool Annotate(Dec& from);

Dec& RemoveAnyVar(Dec& dec);
Dec& RemoveSugar(Dec& dec);

//@TODO rename, both of these are asserts
//Add these to more places
void IsAnnotated(Expr* expr);
void IsAnnotated(Dec* type);
