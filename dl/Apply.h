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

struct Known
{
    struct Selected
    {
        DecFns& fns;
        Variable& selected;
        Selected(DecFns& fns, Variable& selected):
        fns(fns),
        selected(selected){
        }
    };
    
    //Types that have been resolved
    table<string, Dec*> resolved;
    
    //Types that have been selected
    vector<Selected> selected;
};

//Apply returns false if unsolveable otherwise it returs true
//Apply will fill in any generic Dec that it deduced adding them to the known table
//Apply is often run on a number of parameters
//Failure is if any Apply fails or the set of known variables is the same as on the last iteration

bool Apply(Dec& arg, Dec& param, Known &known);
bool Apply(StructDef& arg, DecGen& param, Known &known);
bool Apply(DecFn& arg, DecFn& param, Known &known);
bool Apply(DecFns& arg, DecFn& param, Known &known);
