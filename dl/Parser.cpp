//
//  Parser.cpp
//  Created by David on 8/18/16.
//

#include "Parser.h"

#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unistd.h>
#include <sstream>
#include <set>
#include "Lexer.h"
#include "Type.h"
#include "Printing.h"
#include "Project.h"
#include "Utility.h"

Token Get(Lex &lexer, int i = 0){
    if(i + lexer.index >= lexer.tokens.size()){
        return Token();
    }
    Token r = lexer[i];
    return r;
}

void Eat(Lex &lexer, int count = 1){
    lexer.Eat(count);
}

Expr* ParseNone(Lex &lexer){
    return nullptr;
}

template<class R = Expr*,
        class F1, 
        class F2 = decltype(ParseNone), 
        class F3 = decltype(ParseNone), 
        class F4 = decltype(ParseNone), 
        class F5 = decltype(ParseNone), 
        class F6 = decltype(ParseNone), 
        class F7 = decltype(ParseNone), 
        class F8 = decltype(ParseNone)>
R Parse(Lex& lexer, F1 f1, F2 f2 = ParseNone, F3 f3 = ParseNone, F4 f4 = ParseNone, F5 f5 = ParseNone, F6 f6 = ParseNone, F7 f7 = ParseNone,  F8 f8 = ParseNone){
    Expr *node = nullptr;
   ((node = f1(lexer))  ||
    (node = f2(lexer))  ||
    (node = f3(lexer))  ||
    (node = f4(lexer))  ||
    (node = f5(lexer))  ||
    (node = f6(lexer))  ||
    (node = f7(lexer))  ||
    (node = f7(lexer)));
    return node;
}

bool EatBlockOpen(Lex &lexer){
    if(Get(lexer) == Lexer::BracketOpen){
        Eat(lexer);
        return true;
    } 
    return false;
}

bool IsEndStmt(Lex &lexer){
    if(Get(lexer).isFirst)
        return true;
    return false;
}

bool EatBlockClose(Lex &lexer){
     if(Get(lexer) == Lexer::BracketClose){
        Eat(lexer);
        return true;
    } 
    return false;   
}

struct ParseUtil {
    static constexpr const char* constfn = "identifier fn(variable Type,...)";
    static void Require(Lex& lexer, Lexer::Symbol symbol){
        if(Get(lexer) == symbol)
            Eat(lexer);
        Error("Expected '" + String(symbol) + "' found, " + String(Get(lexer)), Get(lexer));
    }
    
    
    template<class T>
    static auto Require(Lex& lexer, T fn, string expected)->decltype(fn(lexer)){
        auto type = fn(lexer);
        if(!type)
            Error("Expected '" + expected + "' found, " + String(Get(lexer)), Get(lexer));

        return type;
    }
    
    template<class T, class F>
    void Range(Lex& lexer, Lexer::Symbol start, Lexer::Symbol end, F func)
    {
        ParseUtil::Require(lexer, start);
        while (true) {
            if(Get(lexer) == end){
                Eat(lexer);
                return;
            }
            func(lexer);
        }
    }
};

Variable* ParseFunction(Lex &lexer, bool external, bool variable = false);
Variable ParseVariable(Lex &lexer);
Expr* ParseDef(Lex &lexer);

Expr* ParseDirective(Lex &lexer, File& file){
    if(Get(lexer) == Lexer::Directive) {
        
        Eat(lexer); //'@'

        if(Get(lexer) !=  Lexer::Identifier){
            Error("Expected identifier after '@' directive', found " + String(Get(lexer)), Get(lexer));
        }
        Directive& directive = Create<Directive>(Get(lexer).line);
        directive.value = Get(lexer).value;
        Eat(lexer); //ident

        if(Get(lexer) != Lexer::BracketOpen){
            Error("Exected '{' after @directive, found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer); // '{'

        if (directive.value == "extern"){
            while(true){
                if(auto fn = ParseFunction(lexer, true))
                {
                    file.ast.children.Push(*fn);
                }
                else if(auto structure = ParseDef(lexer))
                {
                    file.ast.children.Push(*structure);
                }
                else break;
            }
        }
        else if (directive.value == "build"){
            while(Get(lexer) == Lexer::Identifier){
                string field = Get(lexer).value;
                Eat(lexer);
                if(field == "link"){
                    if(Get(lexer) != Lexer::Assign)
                        Error("Expected '=', found" + String(Get(lexer)), Get(lexer));

                    Eat(lexer);
                    
                    if(Get(lexer) != Lexer::ParenOpen)
                        Error("Expected '(', found" + String(Get(lexer)), Get(lexer));
                    Eat(lexer);
                    
                    while (Get(lexer) == Lexer::String){
                        
                        file.project->settings.linkerFlags.push_back(Get(lexer).value);
                        Eat(lexer);
                        if(Get(lexer) != Lexer::Comma){
                            break;
                        }
                        Eat(lexer);
                    }
                    if(Get(lexer) != Lexer::ParenClose)
                        Error("Expected ')', found" + String(Get(lexer)), Get(lexer));
                    Eat(lexer);
                }
                else
                {
                    Error("Unhandled field in @build, " + field, Get(lexer));
                }
            }
        }
        else if(directive.value == "import"){
            while(Get(lexer) == Lexer::String){
                auto import = Get(lexer).value;
                Eat(lexer);

                auto &importedFile = file.project->ImportFile(file.directory + import);
                file.AddImported(importedFile);
                if(Get(lexer) != Lexer::Comma)
                    break;
                Eat(lexer);
            }
        }
        else{
            Error("Unhandled directed @" + directive.value , Get(lexer));
        }
        
        if(Get(lexer) != Lexer::BracketClose) {
            Error("Exected '}' to close @<ident>, found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer); // }

        return &directive;
    }
    return nullptr;
}
Variable* ParseVar(Lex &lexer, bool requireIdentifier = true);
Variable* ParseVar(Lex &lexer, table<string, TypeAny*>& unknown, bool requireIdentifier = true);
inline Expr* ParseExpr(Lex &lexer, bool close, int prescedence);
inline Expr* ParseExpr(Lex &lexer) {
    return ParseExpr(lexer, false, 0);
}
inline Expr* ParseExpression(Lex &lexer) {
    return ParseExpr(lexer, false, 0);
}


Using* ParseUsing(Lex &lexer){
    if(Get(lexer) == Lexer::Using)
    {
        Using& node = Create<Using>(Get(lexer).line);
        Eat(lexer);
        
        if(Get(lexer) != Lexer::Identifier)
        {
            Error("Expected identifier following 'using', found ", Get(lexer));
        }
        
        node.operand = ParseExpr(lexer);
        return &node;
    }
    return nullptr;
}

Type& ParseType(Lex& lexer, table<string, TypeAny*>& unknown){
    bool ref = false;
    if (Get(lexer) == Lexer::Ref) {
        Eat(lexer);
        ref = true;
    }
    if (Get(lexer) == Lexer::Identifier) {
        
        auto var = &Create<TypeVar>(Get(lexer).line);
        Type *dec = var;
        var->ident = Get(lexer).value; 
        var->coord = Get(lexer).line;
        Eat(lexer);

        if (Get(lexer) == Lexer::Any){
            auto any = &Create<TypeAny>(Get(lexer).line);
            any->coord = Get(lexer).line;
            any->ident = var->ident;
            if(unknown.count(any->ident)) {
                Error("Type was alrady declared as any?, did you mean '" + any->ident + "'", any->coord);
            }
            unknown[any->ident] = any;
            Eat(lexer);
        }
        else if(Get(lexer) == Lexer::ParenOpen){
            auto gen = &Create<TypeGen>(Get(lexer).line);
            gen->coord = Get(lexer).line;
            gen->typeGeneric = dec;
            Eat(lexer); // (

            while(true)
            {                
                gen->constraints.push_back(&ParseType(lexer, unknown));
                if (Get(lexer) != Lexer::Comma){
                    break;
                }
                Eat(lexer);
            }
            if (Get(lexer) != Lexer::ParenClose){
                    Error("Expected ')' after constrain type, found " + String(Get(lexer)), Get(lexer));
            }
            Eat(lexer); // )
            dec = gen;
        }

        while(true){
            if (Get(lexer) == Lexer::Caret)
            {
                auto ptr = &Create<TypePtr>(Get(lexer).line);
                ptr->coord = Get(lexer).line;
                ptr->pointed = dec;
                dec = ptr;
                Eat(lexer);
            }
            else if(Get(lexer) == Lexer::BraceOpen)
            {
                Eat(lexer);
                if (Get(lexer) != Lexer::Number) {
                    Error("Expected number, found " + String(Get(lexer)), Get(lexer));
                }
                auto array = &Create<TypeArray>(Get(lexer).line);
                array->coord = Get(lexer).line;
                array->type = dec;
                array->size = &Create<ConstNumber>(Get(lexer).line);
                array->size->value = Get(lexer).value;
                assert(array->type);
                dec = array;
                Eat(lexer);
                
                if (Get(lexer) != Lexer::BraceClose) {
                    Error("Expected ']', found " + String(Get(lexer)), Get(lexer));
                }
                Eat(lexer);
                
            } else break;
        }
        
        dec->ref = ref;
        return *dec;
    }
    if (Get(lexer) == Lexer::Fn) {

        Eat(lexer); // fn
        
        TypeFn& typeFn = Create<TypeFn>(Get(lexer).line);
        
        // (
        if (Get(lexer, 0) != Lexer::ParenOpen) {
            Error("Expected '(' following fn, found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer);
        
        while(true) {
            if (Get(lexer) == Lexer::ParenClose){
                break;
            }
            Variable* variable = ParseVar(lexer);
            if(!variable){
                Error("Expected Variable, found " + String(Get(lexer)), Get(lexer));
            }
            typeFn.params.Add(variable->ident, *variable->type);
            if(Get(lexer) != Lexer::Comma){
                break;
            }
            Eat(lexer);
            //@TODO get rid of Variable
        }
        if (Get(lexer, 0) != Lexer::ParenClose) {
            Error("Expected ')' following fn(..., found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer); // )
        
        //Eat comma seperated variable list
        while(true) {
            if (Get(lexer) == Lexer::Comma || Get(lexer) == Lexer::BracketOpen || Get(lexer) == Lexer::ParenClose || Get(lexer) == Lexer::BracketClose || Get(lexer).isFirst){
                break;
            }
            
            Variable variable = ParseVariable(lexer);
            typeFn.results.Add(variable.ident, *variable.type);
        }
        return typeFn;
    }
    Error("Couldn't parse type", Get(lexer));
}

Type& ParseType(Lex& lexer){
    table<string, TypeAny*> unknown;
    auto &ret = ParseType(lexer, unknown);
    assert(unknown.size() == 0);
    return ret;
}
Variable* ParseEnum(Lex &lexer);

Variable* ParseVar(Lex &lexer, bool requireIdentifier) {
    if (Get(lexer, 0) == Lexer::Identifier &&
       (Get(lexer, 1) == Lexer::Identifier ||
        Get(lexer, 1) == Lexer::Ref ||
        Get(lexer, 1) == Lexer::Fn))
    {
        if (!Get(lexer, 1).isFirst) {
            Variable& var = Create<Variable>(Get(lexer).line);
            var.ident = Get(lexer).value;
            Eat(lexer);
            
            Type& type = ParseType(lexer);
            var.type = &type;
            return &var;
        }
    }
    
    if (!requireIdentifier)
    {
        
        Type& type = ParseType(lexer);
        Variable& var = Create<Variable>(Coord{});
        var.type = &type;
        var.coord = Get(lexer).line;
        return &var;
    }

    if (Get(lexer, 0) == Lexer::Type && Get(lexer, 1) == Lexer::Identifier)
    {
        Eat(lexer);
        TypeType& type = Create<TypeType>(Get(lexer).line);
        type.type = &ParseType(lexer);
        Variable& var = Create<Variable>(Coord{});
        var.type = &type;
        var.coord = Get(lexer).line;
        return &var;
    }
    return nullptr;
}
Variable* ParseVar(Lex &lexer, table<string, TypeAny*>& unknown, bool requireIdentifier)
{
    if (Get(lexer, 0) == Lexer::Identifier &&
        (Get(lexer,1) == Lexer::Identifier ||
         Get(lexer,1) == Lexer::Ref ||
         Get(lexer,1) == Lexer::Fn))
    {
        string ident = Get(lexer).value; Eat(lexer);
        Type& type = ParseType(lexer, unknown);
        Variable& var = Create<Variable>(Coord{});
        var.type = &type;
        var.ident = ident;
        var.coord = Get(lexer).line;
        return &var;
    }
    
    if (!requireIdentifier)
    {
        Type& type = ParseType(lexer, unknown);
        Variable& var = Create<Variable>(Coord{});
        var.type = &type;
        var.coord = Get(lexer).line;
        return &var;
    }
    
    if (Get(lexer, 0) == Lexer::Type && Get(lexer, 1) == Lexer::Identifier)
    {
        Eat(lexer);
        TypeType& type = Create<TypeType>(Get(lexer).line);
        type.type = &ParseType(lexer, unknown);
        Variable& var = Create<Variable>(Coord{});
        var.type = &type;
        var.coord = Get(lexer).line;
        return &var;
    }
    return nullptr;
}

Variable* ParseVariableTypelaration(Lex &lexer){
    if (auto node = ParseVar(lexer, true)) {
        if (Get(lexer) == Lexer::Assign) {
            Eat(lexer);
            node->assign = ParseExpression(lexer);
            if (!node->assign){
                Error("Expected expression after =, found", Get(lexer));
            }
        }
        return node;
    }
    return nullptr;
}

Variable ParseVariable(Lex &lexer){
    Variable variable;
    if (Get(lexer, 0) == Lexer::Identifier && Get(lexer, 1) == Lexer::Identifier && !Get(lexer, 1).isFirst) {
        variable.ident = Get(lexer).value; Eat(lexer);
        Type& type = ParseType(lexer);
        variable.type = &type;
        return variable;
    }

    Type& type = ParseType(lexer);
    variable.type = &type;
    return variable;
}

Expr* ParseControl(Lex &lexer);

Blck* ParseBasicBlock(Lex &lexer){
    if (!EatBlockOpen(lexer))
        return nullptr;

    Blck &block = Create<Blck>(Get(lexer).line);

    while(auto node = Parse(lexer, ParseControl, ParseVariableTypelaration, ParseExpression, ParseBasicBlock, ParseUsing)){
        block.Add(*node);
    }
    
    if(!EatBlockClose(lexer)){
        Error("Expected '}', found " + String(Get(lexer)), Get(lexer));
    }
    return &block;
}
Blck& BasicBlock(Lex &lexer){
    Blck &block = Create<Blck>(Get(lexer).line);
    if (!EatBlockOpen(lexer)){
             Error("Expected '{', found " + String(Get(lexer)), Get(lexer));

            return block;
    } 
    while(auto node = Parse(lexer, ParseControl, ParseVariableTypelaration, ParseExpression, ParseBasicBlock, ParseUsing)){
        block.Add(*node);
    }
    
    if(!EatBlockClose(lexer)){
        Error("Expected '}', found " + String(Get(lexer)), Get(lexer));
    }
    return block;
}

Expr* ParseControl(Lex &lexer){
    // return ...
    if (Get(lexer) == Lexer::Return){
        Return &ret = Create<Return>(Get(lexer).line);
        ret.coord = Get(lexer).line;
        Eat(lexer);

        ret.expr = ParseExpr(lexer);

        return &ret;
    }
    // if ... {} else {}
    if (Get(lexer) == Lexer::If){
        If &ifelse = Create<If>(Get(lexer).line);
        ifelse.coord = Get(lexer).line;
        Eat(lexer);
        ifelse.condition = ParseExpr(lexer);
        if (!ifelse.condition){
            Error("Expected expression following if, found " + String(Get(lexer)), Get(lexer));
        }
        ifelse.trueBody = &BasicBlock(lexer);

        if (Get(lexer) == Lexer::Else){
            Eat(lexer);
            if(Get(lexer) == Lexer::If){
                ifelse.falseBody = &Create<Blck>(Get(lexer).line);
                ifelse.falseBody->Add(*ParseControl(lexer));
            }
            else {
                ifelse.falseBody = &BasicBlock(lexer);
            }
        }
        return &ifelse;
    }
    if (Get(lexer) == Lexer::For) {
        Eat(lexer);
        
        For *loop = &Create<For>(Get(lexer).line);
        
        auto expr = ParseExpr(lexer);
        if(expr)
        {
            if (Get(lexer) == Lexer::DotDot) {
                Eat(lexer);
                auto rhs = ParseExpr(lexer);
                if(!rhs)
                    Error("Expected expr after .. in for loop", Get(lexer));
                loop->it = "it";
                loop->SetFromTo(expr, rhs);
            }
            else
            {
                loop->SetExpr(expr);
            }
            
            loop->body = &BasicBlock(lexer);

            return loop;
        }
    
        throw ParseError("Unexpected symbol in for loop", lexer[0].line);
        return loop;
        }
    return nullptr;
}

Expr* ParseDef(Lex &lexer){
    if (Get(lexer, 1) == Lexer::Struct && Get(lexer, 0) == Lexer::Identifier) {
        Struct& structure = Create<Struct>(Get(lexer).line);
        structure.ident = Get(lexer).value;
        Eat(lexer, 2); // ident Struct

       if(Get(lexer) == Lexer::ParenOpen){
           Eat(lexer); // (
            while(Get(lexer) == Lexer::Identifier)
            {
                auto decl = &Create<TypeAny>(Get(lexer).line);
                decl->ident = Get(lexer).value;
                decl->coord = Get(lexer).line;
                Eat(lexer);
                if (Get(lexer) != Lexer::Any){
                    Error("Expected '?' after constrain type, found " + String(Get(lexer)), Get(lexer));
                }
                Eat(lexer);

                structure.constraints.push_back(decl);
                if (Get(lexer) != Lexer::Comma){
                    break;
                }
                Eat(lexer); // ,
            }
           if(Get(lexer) != Lexer::ParenClose){
               Error("Expected ')', found " + String(Get(lexer)), Get(lexer));
           }
            Eat(lexer); // )
        }

        // {
        if (!EatBlockOpen(lexer)){
            if(!IsEndStmt(lexer)){
                Error("Expected '{' or ';' following <identifier> struct, found " + String(Get(lexer)), Get(lexer));
            }
            structure.incomplete = true;
            return &structure;
        } 

        while(true) {
            if(Variable *variable = ParseVar(lexer)) {
                structure.AddField(variable->ident, *variable->type);
                continue;
            }
            if(Variable *variable = ParseFunction(lexer,false)) {
                structure.AddField(variable->ident, *variable->type);
                continue;
            }
            break;
        }

         // }
        if(!EatBlockClose(lexer)){
            Error("Expected '}' to close struct definition, found " + String(Get(lexer)), Get(lexer));
        }
        return &structure;
    }
    if (Get(lexer, 1) == Lexer::Fn && Get(lexer, 0) == Lexer::Identifier) {
        return ParseFunction(lexer, false);
    }
    if (Get(lexer, 1) == Lexer::Enum && Get(lexer, 0) == Lexer::Identifier) {
        return ParseEnum(lexer);
    }
    if (Get(lexer, 1) == Lexer::Identifier && Get(lexer, 0) == Lexer::Identifier) {
        return ParseVariableTypelaration(lexer);
    }
    return nullptr;
}

void Parse(Lex &lexer, File& file){
    while(true){
        if (auto node = Parse(lexer, ParseDef, ParseExpression)){
            file.ast.Add(*node);
        }
        else if(ParseDirective(lexer, file)){
            //Nothing to do here
        }
        else break; //End
    }
    
    if(!lexer.done && Get(lexer) != Lexer::End){
        throw ParseError("Unexpected symbol '" + String(Get(lexer)) + "'", Get(lexer).line);
    }
}


inline Expr* ParseOperand(Lex &lexer, bool close, int presidence)
{
    if(Get(lexer) == Lexer::Identifier){
        auto decl = &Create<Var>(Get(lexer).line);
        decl->coord = lexer[0].line;
        decl->name = Get(lexer).value;
        Eat(lexer);
        return decl;
    }
    if(Get(lexer) == Lexer::String){
        auto str = &Create<ConstString>(Get(lexer).line);
        str->coord = lexer[0].line;
        str->value = Get(lexer).value;
        Eat(lexer);
        return str;
    }
    if(Get(lexer) == Lexer::Number){
        auto num = &Create<ConstNumber>(Get(lexer).line);
        num->coord = Get(lexer).line;
        num->value = Get(lexer).value;
        Eat(lexer);
        return num;
    }
    if(Get(lexer) == Lexer::Cast) {
        auto cast = &Create<CastExpr>(Get(lexer).line);
        cast->coord = Get(lexer).line;
        Eat(lexer);

        if (Get(lexer) != Lexer::ParenOpen) {
            Error("Expected '(' following cast", Get(lexer));
        }
        Eat(lexer); // (


        cast->type = &ParseType(lexer);

  
        if(Get(lexer) != Lexer::Comma){
            Error("Expected ',' following cast from expression, found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer); // ,

        cast->expr = ParseExpr(lexer, false,presidence);
        if(!cast->expr){
            Error("Expected expression to cast from, found " + String(Get(lexer)), Get(lexer));
        }

        if (Get(lexer) != Lexer::ParenClose){
            throw ParseError("Expected ')' to close cast expression", lexer[0].line);
        }
        Eat(lexer); // )
        return cast;
    }
    if(Get(lexer) == Lexer::ParenOpen) {
        Eat(lexer); // (
        auto expr = ParseExpr(lexer);
        if(Get(lexer) != Lexer::ParenClose) {
            Error("Expected ')'", Get(lexer));
        }
        Eat(lexer); // )
        return expr;
    }
    if(Get(lexer) == Lexer::Caret) {
        
        Unary *unary = &Create<Unary>(Get(lexer).line);
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Caret;
        
        Eat(lexer);

        unary->expr = ParseExpr(lexer, false, 10);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '^'", Get(lexer).line);

        return unary;
    }
    if(Get(lexer) == Lexer::And) {
        Unary *unary = &Create<Unary>(Get(lexer).line);
        unary->coord = Get(lexer).line;
        unary->op = Lexer::And;
        Eat(lexer);

        unary->expr = ParseExpr(lexer, false, 10);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '&'", Get(lexer).line);
        return unary;
     }
    if(Get(lexer) == Lexer::Sub) {
        Unary *unary = &Create<Unary>(Get(lexer).line);
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Sub;
        Eat(lexer);
        
        unary->expr = ParseExpr(lexer);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].line);
        
        return unary;
    }
    if(Get(lexer) == Lexer::Negated) {
        Unary *unary = &Create<Unary>(Get(lexer).line);
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Negated;
        Eat(lexer);

        unary->expr = ParseExpr(lexer);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].line);
        
        return unary;
    }
    return nullptr;
}

inline Expr* ParseExpr(Lex &lexer, bool close, int precedence)
{
    auto t = ParseOperand(lexer, false, precedence);
    while(t)
    {
        if(Get(lexer) == Lexer::ParenOpen){
            Eat(lexer); // (
            
            Call *call = &Create<Call>(Get(lexer).line);
            call->operand = t;
            call->params = &Create<ExprList>(Get(lexer).line);
            call->coord = Get(lexer, -1).line;
            call->params->coord = call->coord;
            t = call;
            while (auto node = ParseExpr(lexer)){
                call->params->list.Push(*node);
                if (Get(lexer) != Lexer::Comma){
                    break;
                }
                Eat(lexer);
            }
            if (Get(lexer) != Lexer::ParenClose){
                Error("Expected ')' to close call operator, found " + String(Get(lexer)), Get(lexer));
            }
            Eat(lexer); // )
            if((Get(lexer).isFirst))
            {
                break;
            }
            continue;
        }
        if (Get(lexer) == Lexer::Dot){
            auto acess = &Create<Access>(Get(lexer).line);
            acess->coord = Get(lexer).line;
            Eat(lexer);
            if (Get(lexer) != Lexer::Identifier){
                Error("Expected field name after '.', found '" + String(Get(lexer)), Get(lexer));
            }
            acess->field = Get(lexer).value;
            acess->operand = t;
            t = acess;
            Eat(lexer);
            continue;
        }
        if(Get(lexer) == Lexer::BraceOpen){
            Eat(lexer); // [
            
            Call *call = &Create<Call>(Get(lexer).line);
            
            auto var = &Create<Var>(Get(lexer).line);
            var->name = "OpArray";
            call->operand = var;
            call->params = &Create<ExprList>(Get(lexer).line);
            call->coord = Get(lexer).line;
            call->params->list.Push(*t);
            
            t = call;
            while (auto node = ParseExpr(lexer)){
                call->params->list.Push(*node);
                if (Get(lexer) != Lexer::Comma){
                    break;
                }
                Eat(lexer);
            }
            if (Get(lexer) != Lexer::BraceClose){
                Error("Expected ']' to close call operator, found " + String(Get(lexer)), Get(lexer));
            }
            Eat(lexer); // ]
            continue;
        }
        if(!IsBinaryerator(Get(lexer))){
            return t;
        }
        int nextPrecedence = PrecedenceToken(Get(lexer));
        if (nextPrecedence < precedence) {
			return t;
		}
        Lexer::Symbol op = (Lexer::Symbol)Get(lexer).type;
        
        Coord coord = Get(lexer).line;
        lexer.Eat();
        
        int q = nextPrecedence + 1;
        
        Expr* r =  ParseExpr(lexer, false, q);
        
        if(!r){
            throw ParseError("Expected expression following binary operator", lexer[0].line);
        }
        Binary& binary = Create<Binary>(coord);
        assert(t); assert(r);
        binary.op = op;
        binary.left = t;
        binary.right = r;
        t = &binary;
    }
    return t;
}

Variable* ParseEnum(Lex &lexer) {
    if (Get(lexer, 1) == Lexer::Enum && Get(lexer, 0) == Lexer::Identifier) {
        Enum& enums = Create<Enum>(Get(lexer).line);
        enums.ident = Get(lexer).value;
        enums.coord = Get(lexer).line;
        Eat(lexer, 2); // ident Struct
        
        if(Get(lexer) != Lexer::BracketOpen)
        {
            Error("Expected '{'", Get(lexer));
        }
        Eat(lexer);
        
        while (Get(lexer) == Lexer::Identifier) {
            enums.Add(Get(lexer).value);
            Eat(lexer);
            if(Get(lexer) == Lexer::Assign)
            {
                Eat(lexer);
                if(Get(lexer) == Lexer::Number)
                {
                    Eat(lexer);
                }
                else Error("Expected number", Get(lexer));
            }
        }
        
        if(Get(lexer) != Lexer::BracketClose)
        {
            Error("Expected '}'", Get(lexer));
        }
        Eat(lexer);
        return &enums;
    }
    return nullptr;
}
Variable* ParseFunction(Lex &lexer, bool external, bool variable) {
    if (Get(lexer, 1) == Lexer::Fn && Get(lexer, 0) == Lexer::Identifier) {
        Func& fn = Create<Func>(Get(lexer).line);
        fn.ident = Get(lexer).value;
        fn.coord = Get(lexer).line;
        Eat(lexer, 2); // ident Struct
        
        TypeFn& typeFn = Create<TypeFn>(Get(lexer).line);

        // (
        if (Get(lexer, 0) != Lexer::ParenOpen) {
            Error("Expected '(' following fn, found " + String(Get(lexer)), Get(lexer));
            return nullptr;
        }
        
        Eat(lexer);
        
        while(true) {
            if (Get(lexer) == Lexer::ParenClose){
                break;
            }
            Variable* variable = ParseVar(lexer, fn.unknown);
            if(!variable){
                Error("Expected Variable, found " + String(Get(lexer)), Get(lexer));
            }
            fn.params.Add(variable->ident, *variable->type);
            typeFn.params.Add(variable->ident, *variable->type);
            if(Get(lexer) != Lexer::Comma){
                break;
            }
            Eat(lexer);
            //@TODO get rid of Variable
        }
        if (Get(lexer, 0) != Lexer::ParenClose) {
            Error("Expected ')' following fn(..., found " + String(Get(lexer)), Get(lexer));
            return nullptr;
        }
        Eat(lexer); // )
        
        //Eat comma seperated variable list
        while(true) {
            if (Get(lexer) == Lexer::Comma || Get(lexer) == Lexer::BracketOpen || Get(lexer).isFirst || Get(lexer) == Lexer::ParenClose || Get(lexer) == Lexer::BraceClose || Get(lexer) == Lexer::Assign){
                break;
            }
            
            Variable variable = ParseVariable(lexer);
            if (Get(lexer) == Lexer::Comma){
                Eat(lexer);
            }
            fn.results.Add(variable.ident, *variable.type);
            typeFn.results.Add(variable.ident, *variable.type);
        }
        
        if(external){
            if(Get(lexer) == Lexer::BracketOpen)
            {
                fn.body = &BasicBlock(lexer);
            }
            fn.external = true;
        }
        else if(!variable && Get(lexer) == Lexer::BracketOpen)
        {
            fn.body = &BasicBlock(lexer);
        }
        else{
            
            Variable& var = Create<Variable>(Coord{});
            var.type = &typeFn;
            var.ident = fn.ident;
            var.coord = Get(lexer).line;
            return &var;
        }
        return &fn;
    }
    return nullptr;
}
