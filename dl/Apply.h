//
//  Apply.h
//  Created by David on 12/8/16.
//

#pragma once
#include "Symbol.h"

class Dec;
class DecFn;
class DecFns;
class DecGen;
class DecAny;

//Apply returns false if unsolveable otherwise it returs true
//Apply will fill in any generic Dec that it deduced adding them to the known table
//Apply is often run on a number of parameters
//Failure is if any Apply fails or the set of known variables is the same as on the last iteration

bool Apply(Dec& arg, Dec& param, table<string, Dec*> &known);
bool Apply(DecFn& arg, DecFn& param, table<string, Dec*> &known);
bool Apply(DecFns& arg, DecFn& param, table<string, Dec*> &known);
bool Apply(DecGen& arg, DecGen& param, table<string, Dec*> &known);
