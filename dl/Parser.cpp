//
//  Parser.cpp
//  Created by David on 8/18/16.
//

#include "Parser.h"

std::set<string> g_complete;
table<string, Blck*> g_modules;
vector<FileDescription> g_importedFiles;

//Parses these
// (5,5,5)
// (T^,T^)
// (exp, expr)
// (T^, expr)
// ()
// T^
// expr

Dec *ParseDec(Lex &lexer, int& i){
    bool mut = true;
    bool ref = false;
    if(Peek(lexer, Lexer::Ref, i)){
        i++;
        ref = true;
    }
    if(Peek(lexer, Lexer::Const, i)){
        i++;
        mut = false;
    }
    
    if(Peek(lexer, Lexer::Identifier, i) && Get(lexer, i+1).idName == "?"){
        auto type = new DecAny;
        type->ident = Get(lexer, i).idName;
        type->coord = Get(lexer, i).line;
        type->mut = mut;
        type->ref = ref;
        i += 2;
        Dec* ret = type;
        while(Peek(lexer, "^", i)){
            auto ptr = new DecPtr;
            ptr->coord = Get(lexer, i).line;
            ptr->pointed = ret;
            ret = ptr;
            i++;
        }
        return ret;
    }
    if(Peek(lexer, Lexer::Identifier, i) && Get(lexer, i+1).idName == ":"){
        auto type = new DecVar;
        type->ident = Get(lexer, i).idName;
        type->coord = Get(lexer, i).line;
        type->mut = mut;
        i += 2;
        if(!Peek(lexer, "(", i)){
            throw ParseError("Expected '('", lexer[0].line);
        }
        i++;
        
        vector<Dec*> list;
        while(auto decl = ParseDec(lexer, i)){
            list.push_back(decl);
            if(!Peek(lexer, ",", i)){
                break;
            }
            i++;
        }
        
        auto genericType = new DecGen;
        genericType->constraints = list;
        genericType->typeGeneric = type;
        
        if(!Peek(lexer, ")", i)){
            throw ParseError("Expected ')'", lexer[0].line);
        }
        i++;
        
        return genericType;
    }
    if(Peek(lexer, Lexer::Identifier, i)){
        auto type = new DecVar;
        type->ident = Get(lexer, i).idName;
        type->coord = Get(lexer, i).line;
        type->mut = mut;
        
        i++;
        
        Dec* ret = type;
        while(Peek(lexer, "^", i)){
            auto ptr = new DecPtr;
            ptr->coord = Get(lexer, i).line;
            ptr->pointed = ret;
            ret = ptr;
            i++;
        }
        return ret;
    }
    return nullptr;
}

ExprList *ParseExprList(Lex &lexer){
    
    auto list = new ExprList;
    list->coord = lexer[0].previous;
    
    while(auto expr = ParseExpr(lexer, false))
    {
        list->list.push_back(expr);

        if(Remove(lexer, ","))
            continue;
    }
    list->coord = lexer[0].previous;
    return list;
}

inline DecList *ParseDecList(Lex &lexer){
    
    auto list = new DecList;
    list->coord = lexer[0].previous;
    
    int i = 0;
    while(auto dec = ParseDec(lexer, i))
    {
        lexer.Advance(i); i = 0;
        string ident;
        if(Peek(lexer, Lexer::Identifier)){
            ident = Get(lexer, 0).idName;
            lexer.Advance(1);
        }
        
        list->list.push_back(DecName{ident, dec});
        
        if(Remove(lexer, ","))
            continue;
    }

    list->coord = lexer[0].previous;
    return list;
}

//
//  Parses the following expressions
//
//  (int) name      ==> as VariableDef of DecList
//   int name       ==> as VariableDef of Variable
//  (int,int)       ==> as ExprList of Variable
//  (int,1)         ==> as ExprList of Constant
//   expr           ==> from ParseExpression()
//

Node* ParseFnDecl(Lex &lexer){
    if(Get(lexer, 0).idName != "fn"){
        return nullptr;
    }
    
    if(Peek(lexer, Lexer::Identifier)) {
        Error("Expected identifier following 'fn' ", lexer[1]);
    }
    auto name = Get(lexer, 1).idName;
    if(Peek(lexer, "(", 2)) {
        Error("Expected argument list '(' following 'fn ident'", lexer[2]);
    }
    lexer.Advance(3);
    
    ParseExprList(lexer);
    if(Remove(lexer, "(", 0)) {
        Error("Expected ')' to close function parameters", lexer[2]);
    }
    return nullptr;
}

Node* ParseVariableOrExpression(Lex &lexer){
    
    int i = 0;
    //Handle () and ()name
    if(Get(lexer, i).idName == "("){
        while(Get(lexer, i++).idName != ")"){
        }
    
        //I'm a variable definition
        if(Peek(lexer, Lexer::Identifier, i)){
            assert(lexer[0].idName == "(");
            lexer.Advance(1); //Eat '('
            
            auto type = ParseDecList(lexer);
            assert(lexer[0].idName == ")");
            lexer.Advance(1); //Eat ')'
            assert(Peek(lexer, Lexer::Identifier));
            string name = Remove(lexer).idName;
            auto variable = new Variable;
            variable->ident = name;
            variable->coord = lexer[0].line;
            variable->type = type;
            return variable;
        }
        
        //I'm an expression list
    }
    else{
        int i = 0;
        auto type = ParseDec(lexer, i);
        if(type && Peek(lexer, Lexer::Identifier, i)){
            auto variable = new Variable;
            variable->type = type;
            variable->ident = Get(lexer, i).idName;
            variable->coord = Get(lexer, i).line;
            i += 1;
            lexer.Advance(i);
            
            if(Remove(lexer, "=")){
            
                variable->assign = ParseExpr(lexer);
                if(!variable->assign){
                    throw ParseError("Expected expression assignment", lexer[0].line);
                }
                
            }
            else {
                RequireEnd(lexer);
            }
            return variable;
        }
    }
    return nullptr;
}


