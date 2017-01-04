//
//  Parser.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Token.h"

struct Lex;
struct File;

void Parse(Lex &lexer, File& file);
