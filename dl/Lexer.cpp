//
//  Tokens.cpp
//  Created by David on 5/23/16.
//

#include "Lexer.h"
#include <string>

std::string IdentifierStr;  // Filled in if tok_identifier
double NumVal;              // Filled in if tok_number

/// gettok - Return the next token from standard input.

static int lineCount = 0;
int GetLineNumber()
{
    return lineCount;
}


Token Token::Next(Parser &parser)
{
    Token token;
    
    
    int &LastChar = parser.LastChar;
    token.previous.line = parser.lineNumber;
    token.previous.file = parser.file;
    token.previous.column = parser.character;
    
    // Skip any whitespace.
    while (isspace(LastChar))
    {
        if (LastChar == '\n'){
            if(parser.tokens.size()){
                token.isFirst = true;
            }
            parser.lineNumber++;
            parser.character = 0;
            
        }
        LastChar = parser.Get();
        
    }
    
    token.line.line = parser.lineNumber;
    token.line.file = parser.file;
    token.line.column = parser.character;
    
    // identifier: [a-zA-Z][a-zA-Z0-9]*
    if (LastChar == '"')
    {
        IdentifierStr = "";
        while ((LastChar = parser.Get()) && (LastChar != '"' || (IdentifierStr.size() > 0 && IdentifierStr.back() == '\\')))
            IdentifierStr += LastChar;
        
        LastChar = parser.Get();
        token.idName = IdentifierStr;
        token.sym = Lexer::ConstantString;
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        
        return token;
    }
    if (isalpha(LastChar) || LastChar == '_')
    {
        IdentifierStr = LastChar;
        while (isalnum((LastChar = parser.Get())) || LastChar == '_')
            IdentifierStr += LastChar;
        
        token.idName = IdentifierStr;
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        
        if (IdentifierStr == "struct")
        {
            token.sym = Lexer::Struct;
            return token;
        }
        if (IdentifierStr == "return")
        {
            token.sym = Lexer::Return;
            return token;
        }
        if (IdentifierStr == "fn")
        {
            token.sym = Lexer::Fn;
            return token;
        }
        if (IdentifierStr == "if")
        {
            token.sym = Lexer::If;
            return token;
        }
        if (IdentifierStr == "else")
        {
            token.sym = Lexer::Else;
            return token;
        }
        if (IdentifierStr == "for")
        {
            token.sym = Lexer::For;
            return token;
        }
        if(IdentifierStr == "type")
        {
            token.sym = Lexer::Type;
            return token;
        }
        if(IdentifierStr == "cast")
        {
            token.sym = Lexer::Cast;
            return token;
        }
        if(IdentifierStr == "const")
        {
            token.sym = Lexer::Const;
            return token;
        }
        if(IdentifierStr == "val")
        {
            token.sym = Lexer::Val;
            return token;
        }
        if(IdentifierStr == "ref")
        {
            token.sym = Lexer::Ref;
            return token;
        }
        if(IdentifierStr == "var")
        {
            token.sym = Lexer::Var;
            return token;
        }
        if(IdentifierStr == "enum")
        {
            token.sym = Lexer::Enum;
            return token;
        }
        
        token.sym = Lexer::Identifier;
        return token;
    }
    
    if ((LastChar == '0') && (parser.Peek() == 'x'))
    {
        parser.Get();
        LastChar = parser.Get();
        
        std::string NumStr;
        do
        {
            NumStr += LastChar;
            LastChar = parser.Get();
        }
        while (isxdigit(LastChar));
        auto hex = strtoul(NumStr.c_str(), NULL, 16);
        token.idName = std::to_string(hex);
        token.sym = Lexer::Number;
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        return token;
    }
    
    // Number: [0-9.]+
    //This is needed for tuple access such as id.0 etc
    bool lastId = parser.tokens.size() ? parser.tokens.back().sym == Lexer::Identifier : false;
    if (isdigit(LastChar) || (LastChar == '.' && !lastId && isdigit(parser.Peek())))
    {
        std::string NumStr = "";
        do
        {
            NumStr += LastChar;
            LastChar = parser.Get();
            
        }
        while (isdigit(LastChar) || LastChar == '.');
        
        NumVal = strtod(NumStr.c_str(), 0);
        token.idName = NumStr;
        token.sym = Lexer::Number;
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        return token;
    }
    
    if (LastChar == '/' && parser.Peek() == '/')
    {
        // Comment until end of line.
        do {LastChar = parser.Get();
            
        }
        while (LastChar && LastChar != '\n' && LastChar != '\r');
        
        if (LastChar )
            return Next(parser);
    }
    
    
    token.idName = LastChar;
    
    
    
    // Check for end of file.  Don't eat the EOF.
    if (LastChar == 0)
    {
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        token.sym = Lexer::End;
        return token;
    }
    
    if (LastChar == '@')
    {
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        LastChar = parser.Get();
        token.sym = Lexer::Directive;
        return token;
    }
    
  
    
    
    // Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = parser.Get();

    
    if(ThisChar == '.' && LastChar == '.'){
        LastChar = parser.Get();
        token.lineEnd.line = parser.lineNumber;
        token.lineEnd.file = parser.file;
        token.lineEnd.column = parser.character;
        token.idName = "..";
        return token;
    }
   
    token.sym = ThisChar;
    if(token.sym == '}')
        token.isFirst = true;
    
    return token;
}


int Parser::RemoveAt(int at)
{
    int index = start + at;
    
    if (index >= 0 && index < tokens.size())
    {
        for (int i = index; i < tokens.size()-1; i++)
        {
            
            tokens[i] = tokens[i+1];
        }
        
        tokens.pop_back();
        Advance(0);
        return true;
    }
    return false;
}

int Parser::Remove(int symbol, int at)
{
    int index = start + at;
    
    if (index >= 0 && index < tokens.size() && symbol == tokens[index].sym)
    {
        for (int i = index; i < tokens.size()-1; i++)
        {
            
            tokens[i] = tokens[i+1];
        }
        
        tokens.pop_back();
        Advance(0);
        return true;
    }
    return false;
}


int Parser::Expect(int symbol, int at)
{
    int index = start + at;
    
    if (index >= 0 && index < tokens.size() && symbol == tokens[index].sym)
    {
        //PrintTokens("");
        return true;
    }
    return false;
}

void Parser::Advance(int count)
{
    position += count;
    
    
    //
    if(position < (int)tokens.size())
    {
        start = position;
    }
    else
    {
        // printf(".");
        position = start = 0;
        
        tokens.clear();
        
        
        bool endl = false;
        while (!done && !endl)
        {
            Token token = Token::Next(*this);
            
            tokens.push_back(token);
            
            if (token.sym == Lexer::End)
            {
                done = true;
            }
            if (token.sym == ';' || token.sym == '}')
            {
                endl = true;
            }
        }
        
    }
}


