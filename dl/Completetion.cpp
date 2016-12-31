//
//  Completetion.cpp
//  Created by David on 12/24/16.
//

#include "Completetion.h"
#include "Ast.h"
#include "Printing.h"
#include "Semantic.h"

void PrintFunction(Func& func, bool dotCall = false)
{
    
    string str;
    string paste;
    
    str += func.ident;
    str += String(func.params);
    str += String(func.results);
    
    paste = func.ident + "(";
    
    int i = 0;
    if(dotCall) i = 1;
    for (; i < func.params.list.length; i++) {
        paste += "${";
        paste += String(i+1);
        paste +=":";
        if (!func.params[i].ident.empty()) {
            paste += func.params[i].ident;
            paste += " ";
        }
        paste += String(*func.params[i].dec);
        paste += "}";
        if(func.params.list.length-1 != i)
        {
            paste += ", ";
        }
    }
    
    paste += ")";
    
    str += "\t|fn|";
    Println("completion:",str, ";", paste);
}

void Visit(Completions &visitor, Func& self)
{
    Completions::Def def;
    string str;
    str += self.ident;
    str += String(self.params);
    str += String(self.results);
    def.hint = str;
    def.paste = self.ident + "(";
    for (int i = 0; i < self.params.list.length; i++) {
        def.paste += "${";
        def.paste += String(i+1);
        def.paste +=":";
        if (!self.params[i].ident.empty()) {
            def.paste += self.params[i].ident;
            def.paste += " ";
        }
        def.paste += String(*self.params[i].dec);
        def.paste += "}";
        if(self.params.list.length-1 != i)
        {
            def.paste += ", ";
        }
    }
    
    def.paste += ")";
    def.hint += "\t|fn|";
    def.func = &self;
    visitor.functions.push_back(def);
}
void Visit(Completions &visitor, Struct& self)
{
    Completions::Def def;
    def.paste += self.ident;
    def.hint += self.ident;
    def.hint += "\t|struct|";
    visitor.functions.push_back(def);
}
void Visit(Completions &visitor, Expr& self)
{
    
}

template <class T>
void VisitChildren(T& visitor, Blck& self)
{
    for (int i = 0; i < self.childrenAppended.length; i++) {
        visitor.Visit(self.childrenAppended[i]);
    }
    for (int i = 0; i < self.children.length; i++) {
        visitor.Visit(self.children[i]);
    }
}

template <class T>
void VisitChildren(T& visitor, Func& self)
{
    if(self.body){
        visitor.Visit(*self.body);
    }
}

void Visit(Completions &visitor, Blck& self)
{
    VisitChildren(visitor, self);
}
void Completions::Visit(Expr& expr)
{
    VISTOR(*this, expr);
}

void Completions::PrintSuggestions(const string& filter)
{
    string out;
    vector<string> matches;
    
    for (auto def : functions) {
        if(def.hint.find(filter) != std::string::npos)
            Println("completion:", def.hint, ";", def.paste);
    }
}


void Visit(FindExpressionAt &visitor, Blck& self)
{
    Coord coord;
    Expr *expression = nullptr;
    for (int i = 0; i < self.childrenAppended.length; i++) {
        if (self.childrenAppended[i].coord.line && visitor.targetLine >= self.childrenAppended[i].coord.line  && visitor.targetColumn >= self.childrenAppended[i].coord.column) {
            expression = &self.childrenAppended[i];
        }
    }
    for (int i = 0; i < self.children.length; i++) {
        if (self.children[i].coord.line && visitor.targetLine >= self.children[i].coord.line && visitor.targetColumn >= self.children[i].coord.column) {
            expression = &self.children[i];
        }
    }
    if (expression) {
        visitor.expressions.Push(self);
        visitor.expressions.Push(*expression);
        visitor.Visit(*expression);
    }
}
void Visit(FindExpressionAt &visitor, ExprList& self)
{
    Expr *expression = nullptr;
    for (int i = 0; i < self.list.length; i++) {
        if (self.list[i].coord && visitor.targetLine >= self.list[i].coord.line && visitor.targetColumn >= self.list[i].coord.column) {
            expression = &self.list[i];
        }
    }
    if (expression) {
        visitor.expressions.Push(*expression);
        visitor.Visit(*expression);
    }
}
void Visit(FindExpressionAt &visitor, Func& self)
{
    VisitChildren(visitor, self);
}
void Visit(FindExpressionAt &visitor, Call& self)
{
    visitor.Visit(*self.operand);
    visitor.Visit(*self.params);
}

void Visit(FindExpressionAt &visitor, Expr& self)
{
    
}

void FindExpressionAt::Visit(Expr& expr)
{
    VISTOR(*this, expr);
}

FindExpressionAt::FindExpressionAt(Expr& file, int line, int column)
{
    
    targetLine = line;
    targetColumn = column;
    Visit(file);
//    
//    for (int i = 0; i < expressions.length; i++) {
//        Expr& expr = expressions[i];
//        AstPrint printer;
//        printer.Visit(expr);
//    }
}

void Completions::PrintFunctionSuggestionsForExpr(Expr& expr)
{
    int found = 0;
    if(expr == Ast::Blck)
    {
        Blck& block = cast<Blck>(expr);
        for (auto n : block.variables) {
            Variable& var = *n.second;
            
            Println("completion:", var.ident, "\t", var.type ? String(*var.type) : "", "|var|;", var.ident);
        }
        return;
    }
    if(!expr.type)
    {
        if(expr == Ast::Var)
        {
            PrintSuggestions(cast<Var>(expr).name);
            return;
        }
        Println("Expression has no type, there was a compilation error");
        return;
    }
    Type& type = RemoveSugar(*expr.type);
    Println(".");
    for (auto &func : functions)
    {
        if(!func.func) continue;
        
        Func&self = cast<Func>(*func.func);
        if (self.params.list.length)
        {
            if (Convertable(*expr.type, *self.params.list[0].dec))
            {
                PrintFunction(self, true);
                found ++;
            }
        }
    }
    if (type == Ast::Struct) {
        for (auto &field : cast<Struct>(type).fields) {
            Println("completion:", field->ident, "\t", *field->type, ";", field->ident);
            found++;
        }
    }
    if( found == 0)
    {
        Println("Couldnt find any completions for expression: ");
        Println("Couldnt find any completions for expression: ");
        Println("Couldnt find any completions for expression: ");

        AstPrint print;
        print.Visit(expr);
    }
    else{
        Println("Found ", found, " completions!");
        Println("Found ", found, " completions!");
        Println("Found ", found, " completions!");

    }


    
}
