//
//  Apply.cpp
//  Created by Davie on 12/8/16.
//

#include "Apply.h"
#include "Semantic.h"

bool Apply(Dec& arg, Dec& param, table<string, Dec*> &known)
{
    Dec& argc = RemoveSugar(arg);
    Dec& paramc = RemoveSugar(param);
    
    DecAny* argAny = argc.IsAny();
    DecAny* paramAny = paramc.IsAny();
    
    if (argAny && paramAny)
    {
        return false;
    }
    else if(argAny)
    {
        return false;
    }
    else if(paramAny){
        known[paramAny->ident] = &argc;
        return true;
    }
    
    DecFn* argFn = argc.IsFn();
    DecFn* paramFn = paramc.IsFn();
    if(argFn && paramFn){
        return Apply(*argFn, *paramFn, known);
    }
    else if(argFn || paramFn){
        return false;
    }
    
    DecGen* argGen = argc.IsGen();
    DecGen* paramGen = paramc.IsGen();
    if(argGen && paramGen){
        return Apply(*argGen, *paramGen, known);
    }
    else if(argGen || paramGen){
        return false;
    }
    
    if (TypeCheck(arg, param, true))
    {
        return true;
    }
    return false;
}
bool Apply(DecFn& arg, DecFn& param, table<string, Dec*> &known)
{
    if (arg.params.list.size() != param.params.list.size()) {
        return false;
    }
    
    bool ret = true;
    for (int i = 0; i < arg.params.list.size(); i++) {
        Dec& argParam = *arg.params[i].dec;
        Dec& paramParam = *param.params[i].dec;
        ret = ret && Apply(argParam, paramParam, known);
    }
    return ret;
}
bool Apply(DecGen& arg, DecGen& param, table<string, Dec*> &known)
{
    assert(arg.generic && param.generic);
    if(arg.generic != param.generic){
        Print("Can't applym two differn't generic types", arg.coord);
        return false;
    }
    if(arg.constraints.size() != param.constraints.size()){
        Print("Can't apply, Generic constraint size mismatch", arg.coord);
        return false;
    }
    
    auto ret = true;
    for(int i = 0; i < arg.constraints.size(); i++){
        Dec& argc = RemoveSugar(*arg.constraints[i]);
        Dec& paramc = RemoveSugar(*param.constraints[i]);
        ret = ret && Apply(argc, paramc, known);
    }
    return ret;
}
