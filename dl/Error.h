//
//  Error.h
//  Created by David on 5/21/16.
//

#pragma once
#include "Symbol.h"


class Node;
class QualifiedType;
class Coord;

void Assert(bool cond, const Node &node, const string&str = "");
void Assert(bool cond, const QualifiedType &node, const string&str = "");
void Print(const Coord& coord);

struct Blck;

class File;
extern std::vector<File*> g_files;

