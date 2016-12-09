//
//  Parser.cpp
//  Created by David on 8/18/16.
//

#include "Parser.h"
#include "Project.h"

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

Node* ParseNone(Lex &lexer){
    return nullptr;
}

template<class R = Node*,
        class F1, 
        class F2 = decltype(ParseNone), 
        class F3 = decltype(ParseNone), 
        class F4 = decltype(ParseNone), 
        class F5 = decltype(ParseNone), 
        class F6 = decltype(ParseNone), 
        class F7 = decltype(ParseNone), 
        class F8 = decltype(ParseNone)>
R Parse(Lex& lexer, F1 f1, F2 f2 = ParseNone, F3 f3 = ParseNone, F4 f4 = ParseNone, F5 f5 = ParseNone, F6 f6 = ParseNone, F7 f7 = ParseNone,  F8 f8 = ParseNone){
    Node *node = nullptr;
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

Node* ParseDirective(Lex &lexer, File& file){
    if(Get(lexer) == Lexer::Directive) {
        
        Eat(lexer); //'@'

        if(Get(lexer) !=  Lexer::Identifier){
            Error("Expected identifier after '@' directive', found " + String(Get(lexer)), Get(lexer));
        }
        Directive& directive = *new Directive;
        directive.value = Get(lexer).value;
        Eat(lexer); //ident

        if(Get(lexer) != Lexer::BracketOpen){
            Error("Exected '{' after @directive, found " + String(Get(lexer)), Get(lexer));
        }
        Eat(lexer); // '{'

        if (directive.value == "extern"){
            while(auto fn = ParseFunction(lexer, true)){
                file.ast.children.push_back(fn);
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
                        
                        Println("link lib ", Get(lexer).value);
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

Dec& ParseType(Lex& lexer){
    bool ref = false;
    if (Get(lexer) == Lexer::Ref) {
        Eat(lexer);
        ref = true;
    }
    if (Get(lexer) == Lexer::Identifier) {
        
        auto var = new DecVar;
        Dec *dec = var;
        var->ident = Get(lexer).value; 
        var->coord = Get(lexer).line;
        Eat(lexer);

        if (Get(lexer) == Lexer::Any){
            auto any = new DecAny;
            any->coord = Get(lexer).line;
            any->ident = var->ident;
            dec = any;
            Eat(lexer);
        }
        else if(Get(lexer) == Lexer::ParenOpen){
            auto gen = new DecGen;
            gen->coord = Get(lexer).line;
            gen->typeGeneric = dec;
            Eat(lexer); // (

            while(true)
            {                
                gen->constraints.push_back(&ParseType(lexer));
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

        while(Get(lexer) == Lexer::Caret){
            auto ptr = new DecPtr;
            ptr->coord = Get(lexer).line;
            ptr->pointed = dec;
            dec = ptr;
            Eat(lexer);
        }
        
        dec->ref = ref;
        return *dec;
    }
    if (Get(lexer) == Lexer::Fn) {

        Eat(lexer); // fn
        
        DecFn& decfn = *new DecFn;
        
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
            decfn.params.Add(variable->ident, *variable->type);
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
            if (Get(lexer) == Lexer::BracketOpen || Get(lexer) == Lexer::ParenClose || Get(lexer) == Lexer::BracketClose || Get(lexer).isFirst){
                break;
            }
            
            Variable variable = ParseVariable(lexer);
            if (Get(lexer) == Lexer::Comma){
                Eat(lexer);
            }
            decfn.results.Add(variable.ident, *variable.type);
        }
        return decfn;
    }
    Error("Couldn't parse type", Get(lexer));
}

Variable& NewVariable(string ident, Dec& type){
    Variable& var = *new Variable;
    var.type = &type;
    var.ident = ident;
    return var;
}

inline Expr* ParseExpr(Lex &lexer, bool close, int prescedence);
inline Expr* ParseExpr(Lex &lexer) {
    return ParseExpr(lexer, false, 0);
}
inline Expr* ParseExpression(Lex &lexer) {
    return ParseExpr(lexer, false, 0);
}

Variable* ParseVar(Lex &lexer, bool requireIdentifier) {
    if (Get(lexer, 0) == Lexer::Identifier && 
        (Get(lexer, 1) == Lexer::Identifier || Get(lexer, 1) == Lexer::Ref)) 
    {
        string ident = Get(lexer).value; Eat(lexer);
        Dec& type = ParseType(lexer);
        return &NewVariable(ident, type);
    }
    if (!requireIdentifier){  
        Dec& type = ParseType(lexer);
        return &NewVariable("", type);
    }
    
    if (Get(lexer, 0) == Lexer::Type && Get(lexer, 1) == Lexer::Identifier) {
        Eat(lexer);
        DecType& type = *new DecType;
        type.type = &ParseType(lexer);
        return &NewVariable("", type);
    }
    if (Get(lexer, 0) == Lexer::Identifier && Get(lexer, 1) == Lexer::Fn) {
        return ParseFunction(lexer, false, true);
    }
    return nullptr;
}

Variable* ParseVariableDeclaration(Lex &lexer){
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
        Dec& type = ParseType(lexer);
        variable.type = &type;
        return variable;
    }

    Dec& type = ParseType(lexer);
    variable.type = &type;
    return variable;
}

Node* ParseControl(Lex &lexer);

Blck& BasicBlock(Lex &lexer){
    Blck &block = *new Blck;
    if (!EatBlockOpen(lexer)){
             Error("Expected '{', found " + String(Get(lexer)), Get(lexer));

            return block;
    } 
    while(auto node = Parse(lexer, ParseControl, ParseVariableDeclaration, ParseExpression)){
        block.Add(node);
    }
    
    if(!EatBlockClose(lexer)){
        Error("Expected '}', found " + String(Get(lexer)), Get(lexer));
    }
    return block;
}

Node* ParseControl(Lex &lexer){
    // return ...
    if (Get(lexer) == Lexer::Return){
        Return &ret = *new Return;
        ret.coord = Get(lexer).line;
        Eat(lexer);

        ret.expr = ParseExpr(lexer);

        return &ret;
    }
    // if ... {} else {}
    if (Get(lexer) == Lexer::If){
        If &ifelse = *new If;
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
                ifelse.falseBody = new Blck;
                ifelse.falseBody->Add(ParseControl(lexer));
            }
            else {
                ifelse.falseBody = &BasicBlock(lexer);
            }
        }
        return &ifelse;
    }
    if (Get(lexer) == Lexer::For) {
        Eat(lexer);
        
        For *loop = new For;
        
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
    
        throw ParseError("Unexpected symbol in for loop", lexer[0].previous);
        return loop;
        }
    return nullptr;
}

Node* ParseDef(Lex &lexer){
    if (Get(lexer, 1) == Lexer::Struct && Get(lexer, 0) == Lexer::Identifier) {
        StructDef& Struct = *new StructDef;
        Struct.ident = Get(lexer).value;
        Eat(lexer, 2); // ident Struct

       if(Get(lexer) == Lexer::ParenOpen){
           Eat(lexer); // (
            while(Get(lexer) == Lexer::Identifier)
            {
                auto decl = new DecAny;
                decl->ident = Get(lexer).value;
                decl->coord = Get(lexer).line;
                Eat(lexer);
                if (Get(lexer) != Lexer::Any){
                    Error("Expected '?' after constrain type, found " + String(Get(lexer)), Get(lexer));
                }
                Eat(lexer);

                Struct.constraints.push_back(decl);
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
            Struct.incomplete = true;
            return &Struct;
        } 

        while(true) {
            if(Variable *variable = ParseVar(lexer)) {
                Struct.AddField(variable->ident, *variable->type);
                continue;
            }
            if(Variable *variable = ParseFunction(lexer,false)) {
                Struct.AddField(variable->ident, *variable->type);
                continue;
            }
            break;
        }

         // }
        if(!EatBlockClose(lexer)){
            Error("Expected '}' to close struct definition, found " + String(Get(lexer)), Get(lexer));
        }
        return &Struct;
    }
    if (Get(lexer, 1) == Lexer::Fn && Get(lexer, 0) == Lexer::Identifier) {
        FuncDef& fn = *new FuncDef;
        fn.ident = Get(lexer).value;
        Eat(lexer, 2); // ident Struct

        DecFn decfn;
        
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
            Variable* variable = ParseVar(lexer);
            if(!variable){
                Error("Expected Variable, found " + String(Get(lexer)), Get(lexer));
            }
            fn.params.Add(variable->ident, *variable->type);
            decfn.params.Add(variable->ident, *variable->type);
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
            if (Get(lexer) == Lexer::BracketOpen){
                break;
            }
            
            Variable variable = ParseVariable(lexer);
            if (Get(lexer) == Lexer::Comma){
                Eat(lexer);
            }
            fn.results.Add(variable.ident, *variable.type);
            decfn.results.Add(variable.ident, *variable.type);
        }
         // {
        if (!EatBlockOpen(lexer)){
            if(!IsEndStmt(lexer)){
                return &NewVariable(fn.ident, *new DecFn(decfn));
            }
            return &fn;
        } 
        fn.body = new Blck;
        while(auto node = Parse(lexer, ParseControl, ParseVariableDeclaration, ParseExpression)){
            fn.body->Add(node);
        }
         // }
        if(!EatBlockClose(lexer)){
            Error("Expected '}' to close fn definition, found " + String(Get(lexer)), Get(lexer));
        }
        return &fn;
    }
    if (Get(lexer, 1) == Lexer::Identifier && Get(lexer, 0) == Lexer::Identifier) {
        return ParseVariableDeclaration(lexer);
    }
    return nullptr;
}

void Parse(Lex &lexer, File& file){
    while(true){
        if (auto node = Parse(lexer, ParseDef, ParseExpression)){
            file.ast.Add(node);
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
        auto decl = new Var;
        decl->coord = lexer[0].line;
        decl->name = Get(lexer).value;
        Eat(lexer);
        return decl;
    }
    if(Get(lexer) == Lexer::String){
        auto str = new ConstString;
        str->coord = lexer[0].line;
        str->value = Get(lexer).value;
        Eat(lexer);
        return str;
    }
    if(Get(lexer) == Lexer::Number){
        auto num = new ConstNumber;
        num->coord = Get(lexer).line;
        num->value = Get(lexer).value;
        Eat(lexer);
        return num;
    }
    if(Get(lexer) == Lexer::Cast) {
        auto cast = new CastExpr;
        cast->coord = Get(lexer).line;
        Eat(lexer);

        if (Get(lexer) != Lexer::ParenOpen) {
            Error("Expected '(' following cast", Get(lexer));
        }
        Eat(lexer); // (


        cast->type = &ParseType(lexer);

  
        if(Get(lexer) != Lexer::Comma){
            Error("Expected ',' following cast from expression", Get(lexer));
        }
        Eat(lexer); // ,

        cast->expr = ParseExpr(lexer, false,presidence);
        if(!cast->expr){
            Error("Expected expression to cast from, found " + String(Get(lexer)), Get(lexer));
        }

        if (Get(lexer) != Lexer::ParenClose){
            throw ParseError("Expected ')' to close cast expression", lexer[0].previous);
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
        
        UnaryOp *unary = new UnaryOp;
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Caret;
        
        Eat(lexer);

        unary->expr = ParseExpr(lexer, false, 10);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '^'", Get(lexer).line);

        return unary;
    }
    if(Get(lexer) == Lexer::And) {
        UnaryOp *unary = new UnaryOp;
        unary->coord = Get(lexer).line;
        unary->op = Lexer::And;
        Eat(lexer);

        unary->expr = ParseExpr(lexer, false, 10);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '&'", Get(lexer).line);
        return unary;
     }
    if(Get(lexer) == Lexer::Sub) {
        UnaryOp *unary = new UnaryOp;
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Sub;
        Eat(lexer);
        
        unary->expr = ParseExpr(lexer);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].previous);
        
        return unary;
    }
    if(Get(lexer) == Lexer::Negated) {
        UnaryOp *unary = new UnaryOp;
        unary->coord = Get(lexer).line;
        unary->op = Lexer::Negated;
        Eat(lexer);

        unary->expr = ParseExpr(lexer);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].previous);
        
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
            
            Call *call = new Call;
            call->operand = t;
            call->params = new ExprList;
            call->coord = Get(lexer).line;
            call->params->coord = call->coord;
            t = call;
            while (auto node = ParseExpr(lexer)){
                call->params->list.push_back(node);
                if (Get(lexer) != Lexer::Comma){
                    break;
                }
                Eat(lexer);
            }
            if (Get(lexer) != Lexer::ParenClose){
                Error("Expected ')' to close call operator, found " + String(Get(lexer)), Get(lexer));
            }
            Eat(lexer); // )
            continue;
        }
        if (Get(lexer) == Lexer::Dot){
            auto fieldAccess = new FieldAccess;
            fieldAccess->coord = Get(lexer).line;
            Eat(lexer);
            if (Get(lexer) != Lexer::Identifier){
                Error("Expected field name after '.', found '" + String(Get(lexer)), Get(lexer));
            }
            fieldAccess->field = Get(lexer).value;
            fieldAccess->operand = t;
            t = fieldAccess;
            Eat(lexer);
            continue;
        }
        if(Get(lexer) == Lexer::BraceOpen){
            Eat(lexer); // [
            
            Call *call = new Call;
            
            auto var = new Var;
            var->name = "OpArray";
            call->operand = var;
            call->params = new ExprList;
            call->coord = Get(lexer).line;
            call->params->list.push_back(t);
            
            t = call;
            while (auto node = ParseExpr(lexer)){
                call->params->list.push_back(node);
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
        if(!IsBinaryOperator(Get(lexer))){
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
        BinaryOp *binary = new BinaryOp;
        assert(t); assert(r);
        binary->op = op;
        binary->left = t;
        binary->right = r;
        binary->coord = coord;
        t = binary;
    }
    return t;
}

Variable* ParseFunction(Lex &lexer, bool external, bool variable) {
    if (Get(lexer, 1) == Lexer::Fn && Get(lexer, 0) == Lexer::Identifier) {
        FuncDef& fn = *new FuncDef;
        fn.ident = Get(lexer).value;
        Eat(lexer, 2); // ident Struct
        
        DecFn decfn;
        
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
            Variable* variable = ParseVar(lexer);
            if(!variable){
                Error("Expected Variable, found " + String(Get(lexer)), Get(lexer));
            }
            fn.params.Add(variable->ident, *variable->type);
            decfn.params.Add(variable->ident, *variable->type);
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
            if (Get(lexer) == Lexer::BracketOpen || Get(lexer).isFirst || Get(lexer) == Lexer::ParenClose || Get(lexer) == Lexer::BraceClose || Get(lexer) == Lexer::Assign){
                break;
            }
            
            Variable variable = ParseVariable(lexer);
            if (Get(lexer) == Lexer::Comma){
                Eat(lexer);
            }
            fn.results.Add(variable.ident, *variable.type);
            decfn.results.Add(variable.ident, *variable.type);
        }
        
        if(external){
            if (!EatBlockOpen(lexer)){
                if(!IsEndStmt(lexer)){
                    Error("Expected ';'", Get(lexer));
                }
            }
            fn.external = true;
        }
        else if(!variable && Get(lexer) == Lexer::BracketOpen)
        {
            fn.body = &BasicBlock(lexer);
        }
        else{
            
            return &NewVariable(fn.ident, *new DecFn(decfn));
        
        }
        return &fn;
    }
    return nullptr;
}
