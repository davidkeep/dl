//
//  Parser.h
//  Created by David on 8/18/16.
//

#pragma once
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <unistd.h>
#include <sstream>
#include <set>
#include "Lexer.h"
#include "Decl.h"
#include "Def.h"
#include "Op.h"
#include "Printing.h"


inline void Error(const string& msg, Token token){
    throw ParseError(msg, token.line);
}

extern vector<FileDescription> g_importedFiles;
extern std::set<string> g_complete;
extern table<string, Blck*> g_modules;

Node* ParseVariableOrExpression(Lex &lexer);

inline bool ParseEndExpression(Parser &parser)
{
    if(parser.Expect(';', 0))
    {
        parser.Advance(1);
        return true;
    }
    
    return parser.Expect('}', 0);
}

inline bool ExpectAndRemove(Parser &parser, const std::string &name)
{
    if(parser[0].idName == name)
    {
        parser.Advance(1);
        return true;
    }
    return false;
}
inline void ExpectBlockBegin(Parser &parser)
{
    if(!parser.Remove('{'))
    {
        throw ParseError("Expected {", parser[0].line);
    }
}
inline void ExpectBlockEnd(Parser &parser)
{
    if(!parser.Remove('}'))
    {
        throw ParseError("Expected }", parser[0].line);
    }
}

inline bool Remove(Lex &lexer, const string& str){
    if(lexer[0].idName == str)
    {
        lexer.Advance(1);
        return true;
    }
    return false;
}
inline bool Remove(Lex &lexer, const string& str, int at){
    if(lexer[at].idName == str)
    {
        lexer.RemoveAt(at);
        return true;
    }
    return false;
}

inline Token Get(Lex &lexer, int i){
    Token r = lexer[i];
    return r;
}

inline Token Remove(Lex &lexer){
    Token r = lexer[0];
    lexer.Advance(1);
    return r;
}

inline bool Peek(Lex &lexer, Lexer::Symbol type, int at = 0){
    if(lexer[at].sym == type)
    {
        return true;
    }
    return false;
}
inline bool Peek(Lex &lexer, Lexer::Symbol type, const string& str, int at = 0){
    if(lexer[at].sym == type && lexer[at].idName == str)
    {
        return true;
    }
    return false;
}
inline bool IsEndOfLine(Parser&parser, int offset = 0)
{
    return parser.Remove(';', offset) ||  parser[offset].isFirst || parser.Expect('}', offset);
}
inline void RequireEnd(Parser&parser, int offset = 0)
{
    if(!parser.Remove(';', offset) && !parser[offset].isFirst && !parser.Expect('{', offset))
    {
        throw ParseError("Expected ';' found '" +  parser[offset].idName + "'", parser[offset].previous);
    }
}

inline bool Peek(Lex &lexer, const string& str, int at = 0){
    if(lexer[at].idName == str)
    {
        return true;
    }
    
    return false;
}

inline bool RemoveEnd(Parser& lexer, int at = 0)
{
    if(Remove(lexer, ";", at))
        return true;

    if(lexer[at].isFirst)
        return true;
    
    if(Peek(lexer, "{", at)){
        return true;
    }
    if(Peek(lexer, "}", at)){
        return true;
    }
    return false;
}

//inline DecList* ParseDecList(Lex &lexer){
//    
//    auto list = new DecList;
//    list->list.push_back(<#const_reference __x#>)
//    
//    vector<Decl*> list;
//    auto coord = Get(lexer, 0).line;
//    
//    while (auto decl = ParseVariable(lexer, false)) {
//        list.push_back(decl);
//        if(!Remove(lexer, ",")){
//            break;
//        }
//    }
//    auto ret = new VarDeclList(std::move(list));
//    ret->coord = coord;
//    return ret;
//}

inline DecList *ParseDecList(Lex &lexer);
inline Dec *ParseDeclaration(Lex &lexer);

//namedfn. If this fn requires a name check that namedfn was set if namedfn is null its an error to parse one
inline Dec *ParseFnDecl(Lex &lexer, string *namedfn){
    if(Peek(lexer, Lexer::Fn)){
        if(!namedfn && Peek(lexer, Lexer::Identifier, 1)){
            return nullptr;
        }

        lexer.Advance(1);
        
        if(namedfn){
            if(Peek(lexer, Lexer::Identifier)){
                *namedfn = Remove(lexer).idName;
            }
        }
        if(!Remove(lexer, "(")){
            throw ParseError("Expected '('", lexer[0].line);
        }
//        FuncDecl *fn = new FuncDecl;
//        fn->coord = lexer[0].line;
//        fn->args =
        auto list = ParseDecList(lexer);;
        if(!Remove(lexer, ")")){
            throw ParseError("Expected '('", lexer[0].line);
        }
        auto ret =  ParseDeclaration(lexer);
        auto r = new DecVar;
        r->ident = "int";
        return r;
    }
    return nullptr;
}

Dec *ParseDec(Lex &lexer, int& i);
Node* ParseVariableOrExpression(Lex &lexer);

inline Dec *ParseDeclaration(Lex &lexer){
    if(auto type = ParseFnDecl(lexer, nullptr)){
        return type;
    }
    int i = 0;
    if(auto type = ParseDec(lexer, i)){
        lexer.Advance(i);
        return type;
    }
    return nullptr;
}

inline Variable *ParseVariable(Lex &lexer, bool requireName){
    bool ref = false;
    int i = 0;

    if(Peek(lexer, Lexer::Ref)){
        i++;
        ref = true;
    }
    string fnname;
    auto fndecl = ParseFnDecl(lexer, &fnname);
    if(fndecl){
        if(requireName && fnname.empty()){
            Assert(false, *fndecl);
        }
        auto var = new Variable;
        auto type = new DecVar;
        type->ident = "int";
        var->type = type;
        var->ident = fnname;
        var->ref = ref;
        var->coord = Get(lexer, 0).line;
        return var;
    }
    
    auto type = ParseDec(lexer, i);
    if(type && Peek(lexer, Lexer::Identifier, i)){
        auto var = new Variable;
        var->type = type;
        var->ident = Get(lexer, i).idName;
        var->coord = Get(lexer, i).line;
        var->ref = ref;
        var->type->ref = ref;
        i += 1;
        lexer.Advance(i);
        return var;
    }
    return nullptr;
    
}

inline Expr* ParseExpr(Parser &parser, bool close = true);
ExprList *ParseExprList(Lex &lexer);

inline Blck *ParseBlockn(Lex &lexer);

inline DecName ParseParameter(Lex &lexer){
    if (Remove(lexer, "type"))
    {
        auto dec = ParseDeclaration(lexer);
        auto decType = new DecType;
        decType->type = dec;
        return {"", decType};
    }
    auto var = ParseVariable(lexer, true);
    if(var)
        return {var->ident, var->type};
    return {"", nullptr};
}
inline FuncDef *ParseFuncDef(Lex &lexer, bool external = false){
    if (Remove(lexer, "fn"))
    {
        if(!Peek(lexer, Lexer::Identifier)){
            throw ParseError("Expected Identifier", lexer[0].previous);
        }
        string name = Remove(lexer).idName;
        if(!Remove(lexer, "(")){
            throw ParseError("Expected '('", lexer[0].previous);
        }
        vector<DecName> args;
        while(true){
            auto var = ParseParameter(lexer);
            if(!var.dec){
                break;
            }
            args.push_back(var);
            if(!Remove(lexer, ",")){
                break;
            }
        }
        if(!Remove(lexer, ")")){
            throw ParseError("Expected ')'", lexer[0].previous);
        }
        
        auto ref = Peek(lexer, Lexer::Ref);
        if(ref)
            lexer.Advance(1);
        
        vector<DecName> list;
        while (true) {
            
            auto decl = ParseDeclaration(lexer);
            if(!decl){
                break;
            }
            list.push_back({"", decl});
            if(!Remove(lexer, ",")){
                break;
            }
        }

        auto fn = new FuncDef;

        fn->ret = new DecList;
        fn->ret->list = list;
        fn->ret->ref = ref;
        
        
        auto body = ParseBlockn(lexer);
        if(!external && !body){
            throw ParseError("Expected '{'", lexer[0].previous);
        }
        
        fn->external = external;
        fn->body = body;
        fn->args = new DecList;
        fn->args->list = args;
        fn->ident = name;
        return fn;
    }
    return nullptr;
}

inline bool ParseDirective(Lex &lexer, Blck *block){
    if(Remove(lexer, "@")){
        if(!Peek(lexer, Lexer::Identifier)){
            throw ParseError("Expected identifier after '@' directive'", lexer[0].previous);
        }
        auto id = Remove(lexer).idName;
    
        if(!Remove(lexer, "{")){
            throw ParseError("Exected '{' after @directive", lexer[0].previous);
        }

        if(id == "extern"){
            while(auto fn = ParseFuncDef(lexer, true)){
                block->children.push_back(fn);
            }
        }
        else if(id == "import"){
            while(Peek(lexer, Lexer::ConstantString)){
                auto import = Remove(lexer).idName;
                
                FileDescription file;
                auto end = import.find_last_of('/');
                if(end != std::string::npos){
                    file.directory =  import.substr(0, end + 1);
                    file.name =  import.substr(end+1, import.size());
                }
                else{
                    file.name = import;
                }
                file.directory = g_files[lexer.file].directory + file.directory;
                file.file = int(g_importedFiles.size());
                file.fileparent = lexer.file;
                g_importedFiles.push_back(file);
                
                if(!Remove(lexer, ","))
                    break;
            }
        }
        else{
            throw ParseError("Unhandled directed @" + id , lexer[0].previous);
        }
        
        if(!Remove(lexer, "}")){
            throw ParseError("Exected '}' to close @directive{", lexer[0].previous);
        }
        return true;
    }
    return false;
}

inline StructDef *ParseStruct(Lex &lexer){
    
    if(Remove(lexer, "struct"))
    {
        if(!Peek(lexer, Lexer::Identifier))
            throw ParseError("Expected '{'", lexer[0].line);
        StructDef *def = new StructDef;
        def->ident = Remove(lexer).idName;
        def->coord = Get(lexer, 0).line;

        if(Remove(lexer, ":")){
            while(Peek(lexer, Lexer::Identifier) && Peek(lexer, "?", 1))
            {
                auto decl = new DecAny;
                decl->ident = Get(lexer, 0).idName;
                decl->coord = Get(lexer, 0).line;

                def->constraints.push_back(decl);
                lexer.Advance(2);
                if (!Remove(lexer, ","))
                    break;
            }
        }

        if(!Remove(lexer, "{"))
            throw ParseError("Expected '{'", lexer[0].line);

        while (auto decl = ParseVariable(lexer, true)) {
            def->fields.push_back(decl);
            if(!RemoveEnd(lexer)){
                break;
            }
        }
        if(!Remove(lexer, "}"))
            throw ParseError("Expected '}'", lexer[0].line);
        
        return def;
    }
    return nullptr;
}

inline For *ParseFor(Lex &lexer){
    if(!Peek(lexer, Lexer::For))
        return nullptr;
    Remove(lexer);
    
    For *loop = new For;
    
    //for expr .. expr
    //for expr
    auto expr = ParseExpr(lexer, false);
    if(expr)
    {
        if(Peek(lexer, "..")){
            Remove(lexer);
            auto rhs = ParseExpr(lexer, false);
            if(!rhs)
                throw ParseError("Expected expr after .. in for loop", lexer[0].previous);
            loop->it = "it";
            loop->SetFromTo(expr, rhs);
        }
        else
        {
            loop->SetExpr(expr);
        }
        
        loop->body = ParseBlockn(lexer);
        if(!loop->body)
            throw ParseError("Expected '{' following for loop", lexer[0].previous);
        
        return loop;
    }
 
    throw ParseError("Unexpected symbol in for loop", lexer[0].previous);
    return loop;
}
inline If *ParseIf(Lex &lexer){
    if(Peek(lexer, Lexer::If)){
        Remove(lexer);
        auto ifStatement = new If;
        ifStatement->condition = ParseExpr(lexer);
        if(!ifStatement->condition){
            throw ParseError("Expected expression following if", lexer[0].previous);
        }
        ifStatement->trueBody = ParseBlockn(lexer);
        if(!ifStatement->trueBody){
            throw ParseError("Expected '{'", lexer[0].previous);
        }
        if(Peek(lexer, Lexer::Else)){
            Remove(lexer);
            ifStatement->falseBody = ParseBlockn(lexer);
        }
        return ifStatement;
    }

    return nullptr;
}
inline Return *ParseReturn(Lex &lexer){
    if(!Peek(lexer, Lexer::Return))
        return nullptr;
    Remove(lexer);

    auto ret = new Return;
    if(!IsEndOfLine(lexer)){
        ret->expr = ParseExpr(lexer);
    }
    return ret;
}

inline Blck *ParseBlockn(Lex &lexer){
    if(!Remove(lexer, "{"))
        return nullptr;
    
    Blck *block = new Blck;
    Node *node = nullptr;
    while(true){
        if(//(node = ParseFuncDef(lexer)) ||
           (node = ParseVariableOrExpression(lexer)) ||
           (node = ParseExpr(lexer))    ||
           (node = ParseFor(lexer))     ||
           (node = ParseReturn(lexer))  ||
           (node = ParseIf(lexer))      ||
           (node = ParseBlockn(lexer))      ||
           0)
        {
            block->children.push_back(node);
        }
        else
            break;
    }
    if(!Remove(lexer, "}"))
        throw ParseError("Expected '}'", lexer[0].line);
    return block;
}

inline void Parse(Lex &lexer, Blck*module){
    
    while(true){
        Node *node = nullptr;
        if(
           (node = ParseVariableOrExpression(lexer)) ||
           (node = ParseFuncDef(lexer)) ||
           (node = ParseStruct(lexer))  ||
           false
           )
        {
            module->children.push_back(node);
        }
        else if(ParseDirective(lexer, module)){
            //
        }
        else{
            break;
        }
    }
    
    
    if(!lexer.done){
        throw ParseError("Unexpected symbol", lexer[0].line);
    }
}
inline Blck* Parse(Lex &lexer){
    
    Blck *module = new Blck;
    Parse(lexer, module);
    return module;
}

inline Expr* ParseExpr(Parser &parser, bool close, int presidence);
inline Expr* ParseOperand(Lex &lexer, bool close, int presidence)
{
    if(Peek(lexer, Lexer::Identifier))
    {
        auto decl = new Var;
        decl->coord = lexer[0].line;
        decl->name = Remove(lexer).idName;
        return decl;
    }
    if(Peek(lexer, Lexer::ConstantString))
    {
        auto str = new ConstString;
        str->coord = lexer[0].line;
        str->value = Remove(lexer).idName;
        return str;
    }
    if(Peek(lexer, Lexer::Number))
    {
        auto num = new ConstNumber;
        num->coord = lexer[0].line;
        num->value = Remove(lexer).idName;
        return num;
    }
    if(Peek(lexer, Lexer::Cast))
    {
        auto cast = new Cast;
        cast->coord = Remove(lexer).line;

        if(!Remove(lexer, "(")){
            throw ParseError("Expected '(' following cast", lexer[0].previous);
        }
        cast->expr = ParseExpr(lexer, false,presidence);
        if(!cast->expr){
            throw ParseError("Expected expression to cast from", lexer[0].previous);
        }
        if(!Remove(lexer, ",")){
            throw ParseError("Expected ',' following cast from expression", lexer[0].previous);
        }
        cast->type = ParseDeclaration(lexer);

        if(!cast->type){
            throw ParseError("Expected type", lexer[0].previous);
        }
        if(!Remove(lexer, ")")){
            throw ParseError("Expected ')' to close cast expression", lexer[0].previous);
        }
        return cast;
    }
    if(Peek(lexer, "("))
    {
        Remove(lexer);
        auto expr = ParseExpr(lexer, false);
        if(Remove(lexer).idName != ")"){
            throw ParseError("Expected ')'", lexer[0].previous);
        }
        return expr;
    }

    if(Peek(lexer, "^")){
        UnaryOp *unary = new UnaryOp;
        unary->coord = Remove(lexer).line;
        unary->op = Op::PointerOperator;
        OpType opType = Type(Op::PointerOperator);
        int q = opType.right ? opType.precedence : opType.precedence - 1;
        unary->expr = ParseExpr(lexer, false, q);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '^'", lexer[0].previous);

        return unary;
    }
    if(Peek(lexer, "&")){
        UnaryOp *unary = new UnaryOp;
        unary->coord = Remove(lexer).line;
        unary->op = Op::AddressOperator;
        unary->expr = ParseExpr(lexer, false);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '&'", lexer[0].previous);
        
        return unary;
    }
    if(Peek(lexer, "-")){
        UnaryOp *unary = new UnaryOp;
        unary->coord = Remove(lexer).line;
        unary->op = Op::Minus;
        unary->expr = ParseExpr(lexer, false);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].previous);
        
        return unary;
    }
    if(Peek(lexer, "!")){
        UnaryOp *unary = new UnaryOp;
        unary->coord = Remove(lexer).line;
        unary->op = Op::Negated;
        unary->expr = ParseExpr(lexer, false);
        if(!unary->expr)
            throw ParseError("Expected operand after unary operator '-'", lexer[0].previous);
        
        return unary;
    }
    return nullptr;
}

inline Expr* ParseExpr(Lex &lexer, bool close, int presidence)
{
    auto t = ParseOperand(lexer, false, presidence);
    while(t)
    {
        Op op;
        int i = 1;
        if(Peek(lexer, "=") && Peek(lexer, "=", 1)){
            i = 2;
            op = Op::Equality;
        }
        else if(Peek(lexer, "!") && Peek(lexer, "=", 1)){
            i = 2;
            op = Op::EqualityNegated;
        }
        else if(Peek(lexer, "<") && Peek(lexer, "=", 1)){
            i = 2;
            op = Op::LessEqual;
        }else if(Peek(lexer, ">") && Peek(lexer, "=", 1)){
            i = 2;
            op = Op::GreaterEqual;
        }else if(Peek(lexer, "&") && Peek(lexer, "&", 1)){
            i = 2;
            op = Op::And;
        }else if(Peek(lexer, "|") && Peek(lexer, "|", 1)){
            i = 2;
            op = Op::Or;
        }else if(Peek(lexer, "=")){
            op = Op::Assign;
        }else if(Peek(lexer, "+")){
            op = Op::Plus;
        }else if(Peek(lexer, "-")){
            op = Op::Minus;
        }else if(Peek(lexer, "*")){
            op = Op::Mul;
        }else if(Peek(lexer, "/")){
            op = Op::Div;
        }else if(Peek(lexer, "<")){
            op = Op::Less;
        }else if(Peek(lexer, ">")){
            op = Op::Greater;
        }else if(Peek(lexer, "(")){
            op = Op::Call;
        }else if(Peek(lexer, "[")){
            op = Op::Array;
        }else if(Peek(lexer, ".")){
            op = Op::Dot;
        }else if(Peek(lexer, "&")){
            op = Op::BitAnd;
        }else if(Peek(lexer, "|")){
            op = Op::BitOr;
        }else if(Peek(lexer, "%")){
            op = Op::Mod;
        }
        else {
            break;
        }
        
        OpType opType = Type(op);
        if(opType.precedence > presidence) break;
        Coord coord = lexer[0].line;
        lexer.Advance(i);
        
        int q = opType.right ? opType.precedence : opType.precedence - 1;        
        if(op == Op::Array){
            q = 100;
        }
        
        Expr* r = nullptr;
        if(op == Op::Call){
            r = ParseExprList(lexer);
            if(!Remove(lexer, ")")){
                throw ParseError("Expected ')' to close call operator", lexer[0].previous);
            }
        }
        if(!r)
            r =  ParseExpr(lexer, false, q);
        
        if(!r){
            throw ParseError("Expected expression following binary operator", lexer[0].previous);
        }
        BinaryOp *binary = new BinaryOp;
        assert(t); assert(r);
        binary->op = op;
        binary->left = t;
        binary->right = r;
        binary->coord = coord;
        t = binary;
        
        if(binary->op == Op::Array)
        {
            if(!lexer.Remove(']'))
            {
                throw ParseError("Expected ']'",  lexer[0].previous);
            }
        }
    }
    return t;
}

inline Expr* ParseExpr(Parser &parser, bool close)
{
    auto r =  ParseExpr(parser, close, 100);
    if(r && close) RequireEnd(parser);
    return r;
}

