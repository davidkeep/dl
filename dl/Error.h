//
//  Error.hpp
//  lan
//
//  Created by David on 5/21/16.
//  Copyright © 2016 David Leroy Futscher. All rights reserved.
//

#pragma once
#include "Symbol.h"


class Node;
class QualifiedType;

void Assert(bool cond, const Node &node, const string&str = "");
void Assert(bool cond, const QualifiedType &node, const string&str = "");
struct Blck;

class File;
extern std::vector<File*> g_files;

