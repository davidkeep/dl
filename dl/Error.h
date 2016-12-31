//
//  Error.h
//  Created by David on 5/21/16.
//

#pragma once
#include "Symbol.h"


class Expr;
class Coord;

void Assert(bool cond, const Expr &node, const string&str = "");
void Print(const Coord& coord);

struct Blck;

class File;
extern vector<File*> g_files;

