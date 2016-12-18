//
//  Apply.cpp
//  Created by Davie on 12/8/16.
//

#include "Apply.h"
#include "Semantic.h"

bool Apply(Dec& arg, Dec& param, Known &known)
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
        assert(paramAny->type == nullptr);
        auto& any = known.resolved[paramAny->ident];
        if(!any)
            any = &argc; //@TODO remove hack known can only be overriden when Num otherwise must be the same
        return true;
    }
    
    if(argc == Dec::Fns && paramc == Dec::Fn)
    {
        return Apply(cast<DecFns>(argc), cast<DecFn>(paramc), known);
    }
    
    DecFn* argFn = argc.IsFn();
    DecFn* paramFn = paramc.IsFn();
    if(argFn && paramFn){
        return Apply(*argFn, *paramFn, known);
    }
    else if(argFn || paramFn){
        return false;
    }
    


 
    StructDef* argGen = dynamic_cast<StructDef*>(&argc);
    DecGen* paramGen = paramc.IsGen();
    if(argGen && paramGen){
        return Apply(*argGen, *paramGen, known);
    }
    else if(paramGen){
        return false;
    }
    
    DecType* argType = argc.IsType();
    DecType* paramType = paramc.IsType();
    if(argType && paramType){
        return Apply(*argType->type, *paramType->type, known);
    }
    DecPtr* argPtr = argc.IsPtr();
    DecPtr* paramPtr = paramc.IsPtr();
    if(argPtr && paramPtr)
    {
        return Apply(*argPtr->pointed, *paramPtr->pointed, known);
    }
    else if(argPtr || paramPtr){
        return false;
    }
    
    if (TypeCheck(param, arg, true))
    {
        return true;
    }
    return false;
}
bool Apply(DecFn& arg, DecFn& param, Known &known)
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
bool Apply(StructDef& arg, DecGen& param, Known &known)
{
    if(!arg.generic || arg.generic != param.generic){
        return false;
    }
    if(arg.constraints.size() != param.constraints.size()){
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

bool Apply(DecFns& arg, DecFn& param, Known &known)
{
    for (auto var : arg.functions) {
        auto fn = cast<FuncDef>(var);
        if(fn->params.list.size() != param.params.list.size())
        {
            continue;
        }
        bool match = true;
        for(auto i = 0; i < fn->params.list.size(); i++){
            match &= Apply(*fn->params.list[i].dec, *param.params.list[i].dec, known);
        }
        if (match) {
            known.selected.push_back({arg, *fn});
            return true;
        }
    }
    return false;
}
