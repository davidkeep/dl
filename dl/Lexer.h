//
//  Tokens.h
//  Created by David on 5/23/16.
//

#pragma once
#include "Error.h"
#include "Printing.h"

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

struct Lex; struct ParserInput;


string String(const Token &token);
int PrecedenceToken(Token token);

struct ParserInput
{
    char *chars = nullptr;
    long length = 0;
    int at = 0;
    int line = 0;
    int character = 0;
    
    ParserInput()
    {
        chars = (char*)malloc(100000); // 100k chars for start
        length = 100000;
        assert(chars);
    };
    
    bool FromFile(const string &filename)
    {
        at = 0;
        line = 0;
        character = 0;
        
        FILE *file = fopen(filename.c_str(), "r");
        if(!file){
            printf("Error: File failed to open '%s' reason: %s\n", filename.c_str(), strerror(errno));
            return false;
        }
        fseek (file, 0, SEEK_END);
        auto nlength = ftell (file);
        fseek (file, 0, SEEK_SET);
        if (length < nlength)
        {
            chars = (char*)realloc(chars, length + 1);
            length = nlength;
        }
        
        fread (chars, sizeof(char), length, file);
        fclose (file);
        chars[nlength] = '\0';
        return true;
    }
    
    inline int Next()
    {
        return chars[at + 1];
    }
    inline int Current()
    {
        return chars[at];
    }
    inline void Eat()
    {
        at++;
        character++;
    }
};

struct Lex
{
    int file;
    
    Lex();
    void Tokenize(ParserInput &input, int file);
    
    void PrintTokens(){
        for(auto token : tokens){
            Println(token);
        }
    }
    inline Token &GetToken(int at){return tokens[index + at]; }
    inline Token &operator[](int at){ return tokens[index + at]; }
    
    void Eat(int count = 1);
    bool done;
    
    int index = 0;    
    vector<Token> tokens;
};
