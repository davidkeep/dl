//
//  Tokens.cpp
//  Created by David on 5/23/16.
//

#include "Lexer.h"
#include <string>

std::string String(const Token &token){
    using namespace Lexer;

    switch(token.type){
        case End:
        return "End";
        case Illegal:
        return "Illegal";

        case BracketOpen:
        return "{";
        case BracketClose:
        return "}";

        case ParenOpen:
        return "(";
        case ParenClose:
        return ")";

        case Lexer::Identifier:
        return token.value;
        case Lexer::String:
        return "\"" +token.value + "\"";
        case Lexer::Number:
        return token.value;

        case Lexer::Struct:
        return "struct";
        case Lexer::Enum:
        return "enum";
        case Lexer::Fn:
        return "fn";

        case Lexer::Return:
        return "return";

        case Lexer::Directive:
        return "@";
        case Lexer::Type:
        return "type";
        case Lexer::Cast:
        return "cast";
        case Const:
        return "const";
        case Ref:
        return "ref";

        case Lexer::If:
        return "if";
        case Lexer::Else:
        return "else";
        case Lexer::For:
        return "for";

        case Comma:
        return ",";
        
        case Less:
        return "<";
        case LessEq:
        return "<=";
        case Greater:
        return ">";
        case GreaterEq:
        return ">=";
        case Equal:
        return "==";
        case NotEqual:
        return "!=";

        case Assign:
        return "=";
        case Negated:
        return "!";

        case AndAnd:
        return "&&";
        case OrOr:
        return "||";
        case And:
        return "&";
        case Or:
        return "|";

        case Add:
        return "+";
        case Sub:
        return "-";
        case Div:
        return "/";
        case Mul:
        return "*";
        case Mod:
        return "%";

        case Dot:
        return ".";
        case DotDot:
        return "..";
        case Constrain:
        return ":";
    }
    return "Unkown";
}

int PrecedenceToken(Token token){
    assert(token.Operator());
    switch(token.type){
        case Lexer::Or:
        return 1;
        break;

        case Lexer::And:
        return 2;
        break;

        case Lexer::Equal:
        case Lexer::Less:
        case Lexer::LessEq:
        case Lexer::Greater:
        case Lexer::GreaterEq:
        case Lexer::NotEqual:
        return 3;
        break;

        case Lexer::Add:
        case Lexer::Sub:
        case Lexer::OrOr:
        return 4;
        break;

        case Lexer::Mul:
        case Lexer::Div:
        case Lexer::Mod:
        case Lexer::AndAnd:
        return 5;
        break;
    }
    return 0;
}

int Current(ParserInput& self) {
	return self.Current();
}

int Next(ParserInput& self) {
	return self.Current();
}

void Eat(ParserInput& self) {
	self.Eat();
}

Token NextToken(Lex& lexer, ParserInput &input)
{    
    Token token;
    
    // Skip any whitespace.
    while (isspace(Current(input)))
    {
        if (Next(input) == '\n'){
            token.isFirst = true;
            input.line++;
            input.character = 0;
        }
        Eat(input);
    }
    
    token.line.line = input.line + 1; //1 Based lines
    token.line.file = lexer.file;
    token.line.column = input.character;
    
    // identifier: [a-zA-Z][a-zA-Z0-9]*
    if (Current(input) == '"')
    {
        Eat(input); // Eat "

        while (Current(input) != '"'){
            token.value += Current(input);
            Eat(input);
        }
        
        Eat(input); // Eat "
        token.type = Lexer::String;        
        return token;
    }

    //Identifiers and keywords
    if (isalpha(Current(input)) || Current(input) == '_')
    {
        token.value = Current(input);
        Eat(input);

        while (isalnum(Current(input))){
            token.value += Current(input);
            Eat(input);
        }

        if (token.value == "struct"){
            token.type = Lexer::Struct; return token;
        }
        if (token.value == "return"){
            token.type = Lexer::Return; return token;
        }
        if (token.value == "fn"){
            token.type = Lexer::Fn; return token;
        }
        if (token.value == "if"){
            token.type = Lexer::If; return token;
        }
        if (token.value == "else"){
            token.type = Lexer::Else; return token;
        }
        if (token.value == "for"){
            token.type = Lexer::For; return token;
        }
        if(token.value == "type"){
            token.type = Lexer::Type; return token;
        }
        if(token.value == "cast"){
            token.type = Lexer::Cast; return token;
        }
        if(token.value == "const"){
            token.type = Lexer::Const; return token;
        }
        if(token.value == "ref"){
            token.type = Lexer::Ref; return token;
        }
        if(token.value == "enum"){
            token.type = Lexer::Enum; return token;
        }
        token.type = Lexer::Identifier;
        return token;
    }

    if ((Current(input) == '0') && (Next(input) == 'x'))
    {
        Eat(input); //0
        Eat(input); //x

        std::string NumStr;
        while (isxdigit(Current(input))){
            NumStr += Current(input);
            Eat(input);
        }

        auto hex = strtoul(NumStr.c_str(), NULL, 16);
        token.value = std::to_string(hex);
        token.type = Lexer::Number;
        return token;
    }
    
    // Number: 123.123 or .123
    if (isdigit(Current(input)) || (Current(input) == '.' && isdigit(Next(input))))
    {
        while (isdigit(Current(input)) || Current(input) == '.'){
            token.value += Current(input);
            Eat(input);
        }
        token.type = Lexer::Number;
        return token;
    }
    
    if (Current(input) == '/' && Next(input) == '/')
    {
        // Comment until end of line.
        do {
            Eat(input);
        }
        while (Current(input) && Current(input) != '\n' && Current(input) != '\r');
        
        return NextToken(lexer, input);
    }
    
    // Check for end of file.  Don't eat the EOF.
    if (Current(input) == 0) {
        Eat(input);
        token.type = Lexer::End;
        return token;
    }
    
    // @
    if (Current(input)  == '@') {
        Eat(input);
        token.type = Lexer::Directive;
        return token;
    }

    // ,
    if (Current(input)  == ',') {
        Eat(input);
        token.type = Lexer::Comma;
        return token;
    }

    if (Current(input) == '=') {
        Eat(input);

        if(Next(input) == '=') {
            Eat(input);
            token.type = Lexer::Equal;
            return token;
        }
        token.type = Lexer::Assign;
        return token;
    }

    if (Current(input) == '<') {
        Eat(input);
        if(Next(input) == '=') {
            Eat(input);
            token.type = Lexer::LessEq;
            return token;
        }
        token.type = Lexer::Less;
        return token;
    }

    if (Current(input) == '>') {
        Eat(input);
        if(Next(input) == '=') {
            Eat(input);
            token.type = Lexer::GreaterEq;
            return token;
        }
        token.type = Lexer::Greater;
        return token;
    }

    if(Current(input) == '.') {
        Eat(input);
        if(Current(input) == '.') {
            Eat(input);
            token.type = Lexer::DotDot;
            return token;
        }
        token.type = Lexer::Dot;
        return token;
    }
   
    if(Current(input) == '{') {
        Eat(input);
        token.type = Lexer::BracketOpen;
        return token;
    }
    if(Current(input) == '}') {
        Eat(input);
        token.isFirst = true;
        token.type = Lexer::BracketClose;
        return token;
    }
    if(Current(input) == '(') {
        Eat(input);
        token.type = Lexer::ParenOpen;
        return token;
    }
    if(Current(input) == ')') {
        Eat(input);
        token.type = Lexer::ParenClose;
        return token;
    }
    if(Current(input) == '+') {
        Eat(input);
        token.type = Lexer::Add;
        return token;
    }
    if(Current(input) == '-') {
        Eat(input);
        token.type = Lexer::Sub;
        return token;
    }
    if(Current(input) == '*') {
        Eat(input);
        token.type = Lexer::Mul;
        return token;
    } 
    if(Current(input) == '/') {
        Eat(input);
        token.type = Lexer::Div;
        return token;
    }   
    if(Current(input) == '%') {
        Eat(input);
        token.type = Lexer::Mod;
        return token;
    }
    if(Current(input) == ':') {
        Eat(input);
        token.type = Lexer::Constrain;
        return token;
    }
    if(Current(input) == '?') {
        Eat(input);
        token.type = Lexer::Any;
        return token;
    }
    if(Current(input) == '!') {
        Eat(input);
        if(Current(input) == '=') {
            Eat(input);
            token.type = Lexer::NotEqual;
            return token;
        }
        token.type = Lexer::Negated;
        return token;
    }
    token.type = Lexer::Illegal;
    assert(false && "Illegal character");
    return token;
}

Lex::Lex(ParserInput &input):
input(input),
done(false)
{
    //Tokenize whole file
    while(true){
        auto token = NextToken(*this, input);
        tokens.push_back(token);
        if(token.type == Lexer::End){
            break;
        }
    }
}

void Lex::Eat(int count)
{
    index += count;
}
