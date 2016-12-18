//
//  Annotate.cpp
//  Created by David on 12/17/16.
//

#include "Annotate.h"
#include "Decl.h"
#include "Def.h"
#include "Intrinsics.h"

Dec& RemoveAnyVar(Dec& dec){
    if(auto any = dec.IsAny()){
        return any->type ? RemoveAnyVar(*any->type) : dec;
    }
    if(auto var = dec.IsVar()){
        return RemoveAnyVar(*var->type);
    }
    if(auto list = dec.IsList()){
        return list->list.size() == 1 ? RemoveAnyVar(*list->list[0].dec) : dec;
    }
    return dec;
}

Dec& RemoveSugar(Dec& dec){
    if(auto any = dec.IsAny()){
        return any->type ? RemoveSugar(*any->type) : dec;
    }
    if(auto gen = dec.IsGen()){
        return gen->type ? RemoveSugar(*gen->type) : dec;
    }
    if(auto var = dec.IsVar()){
        return RemoveSugar(*var->type);
    }
    if(auto list = dec.IsList()){
        return list->list.size() == 1 ? RemoveSugar(*list->list[0].dec) : dec;
    }
    return dec;
}

bool Equal(Dec& left, Dec& right)
{
    return TypeCheck(left, right, false);
}
bool Convertable(Dec& from, Dec& to)
{
    return TypeCheck(to, from, true);
}
bool TypeCheck(Dec&ll, Dec&rr, bool convert){
    
    Dec &l = RemoveAnyVar(ll);
    Dec &r = RemoveAnyVar(rr);
    
    if(typeid(l) == typeid(DecAny))
    {
        return true;
    }
    
    
    if(typeid(l) != typeid(r))
    {
        if(typeid(l) == typeid(TypeGen))
        {
            if(!cast<TypeGen>(l).type) return false;
            return TypeCheck(RemoveSugar(l), r, convert);
        }
        if(typeid(r) == typeid(TypeGen))
        {
            if(!cast<TypeGen>(r).type) return false;
            return TypeCheck(l, RemoveSugar(r), convert);
        }
        return false;
    }
    if(typeid(l) == typeid(TypeGen))
    {
        TypeGen &ll = (TypeGen&)l;
        TypeGen &rr = (TypeGen&)r;
        if(ll.generic != rr.generic){
            return false;
        }
        if(ll.constraints.size() != rr.constraints.size()){
            return false;
        }
        for(int i = 0; i < ll.constraints.size(); i++){
            if(!TypeCheck(*ll.constraints[i], *rr.constraints[i], false)){
                return false;
            }
        }
        
        return true;
    }
    if(typeid(l) == typeid(TypePtr))
    {
        TypePtr &ll = (TypePtr&)l;
        TypePtr &rr = (TypePtr&)r;
        return TypeCheck(*ll.pointed, *rr.pointed, convert);
    }
    if(typeid(l) == typeid(Struct))
    {
        Struct &ll = (Struct&)l;
        Struct &rr = (Struct&)r;
        return &ll == &rr;
    }
    if(typeid(l) == typeid(IntrinsicStruct))
    {
        IntrinsicStruct &ll = (IntrinsicStruct&)l;
        IntrinsicStruct &rr = (IntrinsicStruct&)r;
        if(&rr == &Types::Num){
            //@TODO actually check that this conversion is allowed
            return true;
        }
        
        if(convert){
            //An intger with less bits can be coerced into an integer with more bits
            if(&ll <= &Types::Int8 && &ll >= &Types::Int){
                if(&rr >= &ll && &rr <= &Types::Int8){
                    return true;
                }
            }
            if(&ll <= &Types::Uint8 && &ll >= &Types::Uint){
                if(&rr >= &ll && &rr <= &Types::Uint8){
                    return true;
                }
            }
        }
        return &ll == &rr;
    }
    if(typeid(l) == typeid(TypeList))
    {
        TypeList &ll = (TypeList&)l;
        TypeList &rr = (TypeList&)r;
        if(ll.list.size() != rr.list.size())
            return false;
        
        for(int i = 0; i < ll.list.size(); i++){
            if(!TypeCheck(*ll.list[i].dec, *rr.list[i].dec, convert)){
                return false;
            }
        }
        return true;
    }
    if(typeid(l) == typeid(TypeType))
    {
        TypeType &ll = (TypeType&)l;
        TypeType &rr = (TypeType&)r;
        
        return TypeCheck(*ll.type, *rr.type, convert);
    }
    if(typeid(l) == typeid(TypeFn))
    {
        TypeFn &ll = (TypeFn&)l;
        TypeFn &rr = (TypeFn&)r;
        if(!TypeCheck(ll.params, rr.params))
            return false;
        
        if(!TypeCheck(ll.results, rr.results))
            return false;
        return true;
    }
    assert(false);
    return false;
}


void IsAnnotated(Dec* type){
    if(!type) {
        assert(false);
        return;
    }
    if(typeid(*type) == typeid(Variable)){
        return IsAnnotated(((Variable*)type)->type);
    }
    if(typeid(*type) == typeid(TypeArray)){
        return IsAnnotated(((TypeArray*)type)->type);
    }
    if(typeid(*type) == typeid(TypeVar)){
        return IsAnnotated(((TypeVar*)type)->type);
    }
    if(typeid(*type) == typeid(TypePtr)){
        return IsAnnotated(((TypePtr*)type)->pointed);
    }
    if(typeid(*type) == typeid(DecAny))
    {
        return IsAnnotated(((DecAny*)type)->type);
    }
    if(typeid(*type) == typeid(TypeType))
    {
        return IsAnnotated(((TypeType*)type)->type);
    }
    if(typeid(*type) == typeid(TypeGen))
    {
        return IsAnnotated(((TypeGen*)type)->type);
    }
    if(typeid(*type) == typeid(TypeFn))
    {
        IsAnnotated(&((TypeFn*)type)->results);
        IsAnnotated(&((TypeFn*)type)->params);
        return;
    }
    if(typeid(*type) == typeid(TypeList))
    {
        if(((TypeList*)type)->list.size()){
            assert(((TypeList*)type)->type);
            return;
        }
        return;
    }
    if(typeid(*type) == typeid(TypeFns))
    {
        return;
    }
    assert(
           (typeid(*type) == typeid(Struct)) ||
           (typeid(*type) == typeid(Enum)) ||
           (typeid(*type) == typeid(IntrinsicStruct)) ||
           false
           );
    
}

void IsAnnotated(Expr* expr){
    if(typeid(ExprList) == typeid(*expr)){
        auto list = (ExprList*)expr;
        for(auto exp : list->list)
        {
            IsAnnotated(exp);
        }
    }
    else
    {
        IsAnnotated(expr->type);
    }
}
//

bool TypeCheck(TypeList&l, ExprList&r){
    if(l.list.size() != r.list.size()){
        return false;
    }
    
    for(int i = 0 ; i < l.list.size(); i++){
        if(!TypeCheck(*l.list[i].dec, *r.list[i]->type)){
            return false;
        }
    }
    return true;
}
