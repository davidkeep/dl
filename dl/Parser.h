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

extern vector<FileDescription> g_importedFiles;
extern std::set<string> g_complete;
extern table<string, Blck*> g_modules;

void Parse(Lex &lexer, Blck*module);
