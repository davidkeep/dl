//
//  Tokens.h
//  Created by David on 5/23/16.
//

#pragma once
#include "Error.h"

class Parser;
struct Token
{
    static Token Next(Parser &parser);
    
    
    int sym;
    bool isOperator = false;
    bool isFirst = false;
    
    Coord previous;
    Coord line;
    Coord lineEnd;
    
    std::string idName;
    
private:
    int GetToken(Parser &parser);
    
};

namespace Lexer
{
    enum Symbol
    {
        Paren           = '(',
        ParenClose      = ')',
        
        End             = -1,
        
        // commands
        Struct          = -2,
        Enum            = -4,
        
        // primary
        Operator        = -5,
        Identifier      = -6,
        Number          = -7,
        Return          = -8,
        Fn              = -9,
        Directive       = -10,
        
        Type            = -11,
        Cast            = -12,
        ConstantString  = -13,
        
        Const           = -14,
        Ref             = -15,
        Val             = -16,
        Var             = -17,
        
        If              = -18,
        Else            = -19,
        For             = -20,
    };
}

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

struct Parser;
typedef Parser Lex;

struct ParserInput
{
    virtual int Peek() = 0;
    virtual int Get() = 0;
};

struct ParserFileInput : public ParserInput
{
    FILE *file;
    ParserFileInput(const std::string &filename)
    {
        file = fopen(filename.c_str(), "r");
        if(!file){
            printf("Error: File failed to open '%s' reason: %s\n", filename.c_str(), strerror(errno));
            next = 0;
            return;
        }
        //
        next = fgetc(file);
        if(next == EOF)
            next = 0;
    };
    int next = 0;
    
    int Peek() override
    {
        return next;
    }
    int Get() override
    {
        int c = next;
        if(file)
            next = fgetc(file);
        if(next == EOF)
            next = 0;
        
        return c;
    }
};

struct ParserStringInput : public ParserInput
{
    
    const char* string;
    ParserStringInput(const char* string):
    string(string)
    {
        
    };
    int at = 0;
    
    int Peek() override
    {
        return string[at + 1];
    }
    int Get() override
    {
        return string[at++];
    }
};

struct Parser
{
    int LastChar = ' ';
    int file = 0;
    
    ParserInput &input;
    Parser(ParserInput &input):
    input(input),
    done(false)
    {
        
    };
    
    int Peek()
    {
        return input.Peek();
    }
    int Get()
    {
        character++;
        return input.Get();
    }
    
    
    bool Expect(Lexer::Symbol sym0,  int offset = 0)
    {
        return Expect((int)sym0, offset);
    }
    
    bool Expect(Lexer::Symbol sym0, Lexer::Symbol sym1,  int offset = 0)
    {
        return Expect(sym0, offset) && Expect(sym1, offset + 1);
    }
    
    bool Expect(Lexer::Symbol sym0, Lexer::Symbol sym1, Lexer::Symbol sym2, int offset = 0)
    {
        return Expect(sym0, offset) && Expect(sym1, offset + 1) && Expect(sym2, offset + 2);
    }
    int RemoveAt(int at);
    
    bool Remove(Lexer::Symbol sym0, Lexer::Symbol sym1,  int offset = 0)
    {
        return Remove(sym0, offset) && Remove(sym1, offset + 1);
    }
    
    bool Remove(Lexer::Symbol sym0, Lexer::Symbol sym1, Lexer::Symbol sym2, int offset = 0)
    {
        return Remove(sym0, offset) && Remove(sym1, offset + 1) && Remove(sym2, offset + 2);
    }
    
    
    int Remove(int symbol, int at = 0);
    int Expect(int symbol, int at);
    Token &GetToken(int at){return tokens[start + at]; };
    Token& operator[](int at){ return tokens[start + at]; }
    
    void Advance(int count);
    bool done;
    
    void PrintTokens(const char* str)
    {
        printf("%s\t",str);
        
        for (auto i = start; i < tokens.size(); i++)
        {
            printf("%s ", tokens[i].idName.c_str());
        }
        
        printf("\n");
    }
    
    int Expect(const std::string &str, int at)
    {
        int index = start + at;
        
        if (index >= 0 && index < tokens.size() && str == tokens[index].idName)
        {
            //PrintTokens("");
            return true;
        }
        return false;
    }
    
private:
    friend class Token;
    int position = 0; //curent position of buffer
    int start = 0; //start of the buffer allowing access to past elements.
    
    int lineNumber = 1;
    int character = 0;
    
    std::vector<Token> tokens;
};

extern std::string IdentifierStr;  // Filled in if tok_identifier
extern double NumVal;              // Filled in if tok_number

//int GetToken();
int GetLineNumber();
