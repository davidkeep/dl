//
//  Annotate.cpp
//  Created by David on 12/17/16.
//

#include "Annotate.h"
#include "Type.h"
#include "Intrinsics.h"

Type& RemoveAnyVar(Type& dec){
    if(dec == Ast::TypeAny){
        TypeAny& any = cast<TypeAny>(dec);
        return any.type ? RemoveAnyVar(*any.type) : dec;
    }
    if(dec == Ast::TypeVar){
        TypeVar& var = cast<TypeVar>(dec);
        assert(var.type);
        return RemoveAnyVar(*var.type);
    }
    if(dec == Ast::TypeList){
        TypeList& list = cast<TypeList>(dec);
        if(list.list.length == 1)
        {
            assert(list.list[0].dec);
        }
        return list.list.length == 1 ? RemoveAnyVar(*list.list[0].dec) : dec;
    }
    return dec;
}

Type& RemoveSugar(Type& dec){
    if(dec == Ast::TypeAny){
        TypeAny& any = cast<TypeAny>(dec);
        return any.type ? RemoveSugar(*any.type) : dec;
    }
    if(dec == Ast::TypeGen){
        TypeGen& gen = cast<TypeGen>(dec);
        return gen.type ? RemoveSugar(*gen.type) : dec;
    }
    if(dec == Ast::TypeVar){
        TypeVar& var = cast<TypeVar>(dec);
        assert(var.type && "This TypeVar has not been annotated");
        return RemoveSugar(*var.type);
    }
    if(dec == Ast::TypeList){
        TypeList& list = cast<TypeList>(dec);
        return list.list.length == 1 ? RemoveSugar(*list.list[0].dec) : dec;
    }
    return dec;
}

bool Equal(Type& left, Type& right)
{
    return TypeCheck(left, right, false);
}
bool Convertable(Type& from, Type& to)
{
    return TypeCheck(to, from, true);
}
bool TypeCheck(Type&ll, Type&rr, bool convert){
    
    Type &l = RemoveAnyVar(ll);
    Type &r = RemoveAnyVar(rr);
    
    if(l == Ast::TypeAny)
    {
        return true;
    }
    
    
    if(l.kind != r.kind)
    {
        if(l == Ast::TypeGen)
        {
            if(!cast<TypeGen>(l).type) return false;
            return TypeCheck(RemoveSugar(l), r, convert);
        }
        if(r == Ast::TypeGen)
        {
            if(!cast<TypeGen>(r).type) return false;
            return TypeCheck(l, RemoveSugar(r), convert);
        }
        return false;
    }
    if(l == Ast::TypeGen)
    {
        TypeGen &ll = cast<TypeGen>(l);
        TypeGen &rr = cast<TypeGen>(r);
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
    if(l == Ast::TypePtr)
    {
        TypePtr &ll = (TypePtr&)l;
        TypePtr &rr = (TypePtr&)r;
        return TypeCheck(*ll.pointed, *rr.pointed, convert);
    }
    if(l == Ast::Struct)
    {
        Struct &ll = (Struct&)l;
        Struct &rr = (Struct&)r;
        return &ll == &rr;
    }
    if(l == Ast::StructIntrins)
    {
        StructIntrins &ll = cast<StructIntrins>(l);
        StructIntrins &rr = cast<StructIntrins>(r);
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
    if(l == Ast::TypeList)
    {
        TypeList &ll = cast<TypeList>(l);
        TypeList &rr = cast<TypeList>(r);
        if(ll.list.length != rr.list.length)
            return false;
        
        for(int i = 0; i < ll.list.length; i++){
            //assert(ll.type && rr.type && "Internal Error: Type was not annotated");
            if(!TypeCheck(*ll.list[i].dec, *rr.list[i].dec, convert)){
                return false;
            }
        }
        return true;
    }
    if(l == Ast::TypeType)
    {
        TypeType &ll = cast<TypeType>(l);
        TypeType &rr = cast<TypeType>(r);
        
        return TypeCheck(*ll.type, *rr.type, convert);
    }
    if(l == Ast::TypeFn)
    {
        TypeFn &ll = cast<TypeFn>(l);
        TypeFn &rr = cast<TypeFn>(r);
        if(!TypeCheck(ll.params, rr.params))
            return false;
        
        if(!TypeCheck(ll.results, rr.results))
            return false;
        return true;
    }
    assert(false);
    return false;
}


void AssertAnnotated(Type* type){
    if(!type) {
        assert(false);
        return;
    }
    if(*type == Ast::Variable){
        return AssertAnnotated(((Variable*)type)->type);
    }
    if(*type == Ast::TypeArray){
        return AssertAnnotated(((TypeArray*)type)->type);
    }
    if(*type == Ast::TypeVar){
        return AssertAnnotated(((TypeVar*)type)->type);
    }
    if(*type == Ast::TypePtr){
        return AssertAnnotated(((TypePtr*)type)->pointed);
    }
    if(*type == Ast::TypeAny)
    {
        return AssertAnnotated(((TypeAny*)type)->type);
    }
    if(*type == Ast::TypeType)
    {
        return AssertAnnotated(((TypeType*)type)->type);
    }
    if(*type == Ast::TypeGen)
    {
        return AssertAnnotated(((TypeGen*)type)->type);
    }
    if(*type == Ast::TypeFn)
    {
        AssertAnnotated(&((TypeFn*)type)->results);
        AssertAnnotated(&((TypeFn*)type)->params);
        return;
    }
    if(*type == Ast::TypeList)
    {
        if(((TypeList*)type)->list.length){
            assert(((TypeList*)type)->type);
            return;
        }
        return;
    }
    if(*type == Ast::TypeFns)
    {
        return;
    }
    assert(
           (*type == Ast::Struct) ||
           (*type == Ast::Enum) ||
           (*type == Ast::StructIntrins) ||
           false
           );
}

void AssertAnnotated(Expr* expr){
    if(*expr == Ast::ExprList) {
        auto list = (ExprList*)expr;
        for(int i =0; i < list->list.length; i++)
        {
            Expr &expr = list->list[i];
            AssertAnnotated(&expr);
        }
    }
    else
    {
        AssertAnnotated(expr->type);
    }
}
//

bool TypeCheck(TypeList&l, ExprList&r){
    if(l.list.length != r.list.length){
        return false;
    }
    
    for(int i = 0 ; i < l.list.length; i++){
        if(!TypeCheck(*l.list[i].dec, *r.list[i].type)){
            return false;
        }
    }
    return true;
}
