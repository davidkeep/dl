//
//  Parser.h
//  Created by David on 8/18/16.
//

#pragma once
#include "Token.h"

class Lex;
class File;
void Parse(Lex &lexer, File& file);
