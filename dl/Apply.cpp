//
//  Apply.cpp
//  Created by David on 12/8/16.
//

#include "Apply.h"
#include "Semantic.h"

bool Apply(Type& arg, Type& param, Known &known)
{
    Type& argc = RemoveSugar(arg);
    Type& paramc = RemoveSugar(param);
    
    if (argc == Ast::TypeAny && paramc == Ast::TypeAny)
    {
        return false;
    }
    else if(argc == Ast::TypeAny)
    {
        return false;
    }
    else if(paramc == Ast::TypeAny){
        TypeAny& paramAny = cast<TypeAny>(paramc);
        assert(paramAny.type == nullptr);
        auto& any = known.resolved[paramAny.ident];
        if(!any)
            any = &argc; //@TODO remove hack known can only be overriden when Num otherwise must be the same
        return true;
    }
    if(argc == Ast::TypeFns && paramc == Ast::TypeFn)
    {
        return Apply(cast<TypeFns>(argc), cast<TypeFn>(paramc), known);
    }
    if(argc == Ast::TypeFn && paramc == Ast::TypeFn){
        return Apply(cast<TypeFn>(argc), cast<TypeFn>(paramc), known);
    }
    else if(argc == Ast::TypeFns || paramc == Ast::TypeFn){
        return false;
    }
    
    if(argc == Ast::Struct && paramc == Ast::TypeGen){
        return Apply(cast<Struct>(argc), cast<TypeGen>(paramc), known);
    }
    else if(paramc == Ast::TypeGen){
        return false;
    }
    
    if(argc == Ast::TypeType && paramc == Ast::TypeType){
        return Apply(*cast<TypeType>(argc).type, *cast<TypeType>(paramc).type, known);
    }
    if(argc == Ast::TypePtr && paramc == Ast::TypePtr){
        return Apply(*cast<TypePtr>(argc).pointed, *cast<TypePtr>(paramc).pointed, known);
    }
    else if(argc == Ast::TypePtr || paramc == Ast::TypePtr){
        return false;
    }

    if (TypeCheck(param, arg, true))
    {
        return true;
    }
    return false;
}
bool Apply(TypeFn& arg, TypeFn& param, Known &known)
{
    if (arg.params.list.length != param.params.list.length) {
        return false;
    }
    
    bool ret = true;
    for (int i = 0; i < arg.params.list.length; i++) {
        Type& argParam = *arg.params[i].dec;
        Type& paramParam = *param.params[i].dec;
        ret = ret && Apply(argParam, paramParam, known);
    }
    return ret;
}
bool Apply(Struct& arg, TypeGen& param, Known &known)
{
    if(!arg.generic || arg.generic != param.generic){
        return false;
    }
    if(arg.constraints.size() != param.constraints.size()){
        return false;
    }
    
    auto ret = true;
    for(int i = 0; i < arg.constraints.size(); i++){
        Type& argc = RemoveSugar(*arg.constraints[i]);
        Type& paramc = RemoveSugar(*param.constraints[i]);
        ret = ret && Apply(argc, paramc, known);
    }
    return ret;
}

bool Apply(TypeFns& arg, TypeFn& param, Known &known)
{
    for (auto var : arg.functions) {
        auto fn = cast<Func>(var);
        if(fn->params.list.length != param.params.list.length)
        {
            continue;
        }
        bool match = true;
        for(auto i = 0; i < fn->params.list.length; i++){
            match &= Apply(*fn->params.list[i].dec, *param.params.list[i].dec, known);
        }
        if (match) {
            known.selected.push_back({arg, *fn});
            return true;
        }
    }
    return false;
}
