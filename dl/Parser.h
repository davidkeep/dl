//
//  Parser.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Token.h"


[[ noreturn ]] inline void Error(const string& msg, Token token){
    throw ParseError(msg, token.line);
}

[[ noreturn ]] inline void Error(const string& msg, Coord line){
    throw ParseError(msg, line);
}


class Lex;
class File;
void Parse(Lex &lexer, File& file);
