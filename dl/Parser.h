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
#include "Printing.h"

[[ noreturn ]] inline void Error(const string& msg, Token token){
    throw ParseError(msg, token.line);
}

void Parse(Lex &lexer, File& file);
