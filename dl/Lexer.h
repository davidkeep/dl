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
    virtual int Next() = 0;
    virtual int Current() = 0;
    virtual void Eat() = 0;
    int line = 0;
    int character = 0;
};

struct ParserFileInput : public ParserInput
{
    FILE *file;
    ParserFileInput(const string &filename)
    {
        file = fopen(filename.c_str(), "r");
        if(!file){
            printf("Error: File failed to open '%s' reason: %s\n", filename.c_str(), strerror(errno));
            next = 0;
            return;
        }
        //
        current = fgetc(file);
        next = fgetc(file);
        if(next == EOF)
            next = 0;
        if(current == EOF)
            next = 0;
    };
    
    int current = 0;
    int next = 0;

    int Next() override
    {
        return next;
    }
    int Current() override
    {
        return current;
    }
    void Eat() override
    {
        character++;
        current = next;
        if(file){
            next = fgetc(file);
            if(next == EOF)
                next = 0;
        }
        else {
            next = 0;
        }
    }
};

struct ParserStringInput : public ParserInput
{
    const char* string;
    int at = 0;

    ParserStringInput(const char* string):
    string(string)
    {}

    int Current() override {
        return string[at];
    }
    int Next() override {
        return string[at+1];
    }
    void Eat() override {
        at++;
    }
};

struct Lex
{
    int file;
    
    ParserInput &input;
    Lex(ParserInput &input, int file);
    
    void PrintTokens(){
        for(auto token : tokens){
            Println(token);
        }
    }
    Token &GetToken(int at){return tokens[index + at]; }
    Token &operator[](int at){ return tokens[index + at]; }
    
    void Eat(int count = 1);
    bool done;
    
    int index = 0;    
    std::vector<Token> tokens;
};
