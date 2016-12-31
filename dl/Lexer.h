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
extern std::atomic_int totalLinesParsed;

extern table<string, const char*> fileAsStrings;

struct ParserInput
{
    const char *chars = nullptr;
    long length = 0;
    int at = 0;
    int line = 0;
    int character = 0;
    
    char *mchars = nullptr;
    int mcharsLength = 0;
    
    ParserInput(int reserved = 100000) {
        mchars = (char*)malloc(reserved); // 100k chars for start
        mcharsLength = reserved;
        chars = mchars;
        length = mcharsLength;
        assert(chars);
    }
    
    //Note this string must stay in scope
    bool FromString(const char* string) {
        chars = string;
        length = strlen(string);
        return true;
    }

    bool FromFile(const string &filename)
    {
        if(fileAsStrings.count(filename))
        {
            chars = fileAsStrings[filename];
            length = strlen(chars);
            return true;
        }
        
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
        if (mcharsLength < nlength)
        {
            mchars = (char*)realloc(mchars, mcharsLength + 1);
            length = nlength;
        }
        
        fread (mchars, sizeof(char), mcharsLength, file);
        fclose (file);
        mchars[nlength] = '\0';
        
        chars = mchars;
        length = mcharsLength;
        return true;
    }
    
    inline int Next() {
        return chars[at + 1];
    }
    inline int Current() {
        return chars[at];
    }
    inline void Eat() {
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
