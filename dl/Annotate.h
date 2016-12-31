//
//  Annotate.h
//  Created by David on 12/17/16.
//

#pragma once

struct Type;
struct TypeList;
struct ExprList;
struct Expr;

bool Equal(Type& left, Type& right);
bool Convertable(Type& from, Type& to);

//@TODO remove this, replace with Equal or Convertable, they are very differn't beasts
//In the future convertable will also perform some extra work indentifiying the conversion required
bool TypeCheck(Type&ll, Type&rr, bool convert = true);
bool TypeCheck(TypeList&l, ExprList&r);

bool Annotate(Type& from);

Type& RemoveAnyVar(Type& dec);
Type& RemoveSugar(Type& dec);

//@TODO rename, both of these are asserts
//Add these to more places
void AssertAnnotated(Expr* expr);
void AssertAnnotated(Type* type);
