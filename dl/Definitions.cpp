//
//  Definitions.cpp
//  Created by David on 5/27/16.
//
#include "Definitions.h"
#include "CodeGenerator.h"

void Declaration::Annotate(Block &block, bool gen)
{
    Validate();
    isComplete = true;
    
    if(IsFunction())
    {
        Procedure *procedure = new Procedure();
        for(auto a : arguments)
        {
            a.Annotate(block);
            procedure->args.push_back(a.type);
            if(!a.isComplete) isComplete = false;
        }
        if (ret.size()) {
            ret[0].Annotate(block);
            procedure->ret = ret[0].type;
            if(!ret[0].isComplete) isComplete = false;

        }
        isComplete = true;
        isAnnotated = true;
        
        {
            TypeFunction *fn = new TypeFunction();
            fn->procedure = procedure;
            type.type = fn;
        }
        if(type.type)
        {
            type.mut = mut;
            type.ref = ref;
            for(int i = 0; i < indirection.count; i++)
            {
                QualifiedType pointer;
                auto p = new TypePointer;
                p->pointed = type;
                pointer.type = p;
                pointer.mut = true;
                type = pointer;
            }
        }
        
        return;
    }
    
    if(IsGeneric())
    {
        for(auto &i : types)
        {
            i.Annotate(block, true);
            isComplete = isComplete && i.isComplete;
        }
        generic = Is<TypeRecord>(block.FindType(typeName).type)->structure;
        assert(generic);
        assert(generic->generic);
        assert(!isAny);
    }
    
    isAnnotated = true;

    //If this type is fully annotated we can find the specific structure...
    if(!isAny && isComplete)
    {
        type = block.FindType(*this);
        if(type.type)
        {
            auto record = Is<TypeRecord>(type.type);

            if(mut){
                type.mut = true;
                if(!val && !gen && record && !indirection.count) type.ref = true;
            }
            if(ref || (!indirection.count && !gen && !val && record && record->structure->isDefaultReference))
                type.ref = true;
            else if(!indirection.count & !gen)
            {
                type.mut = true;
            }
            
            for(int i = 0; i < indirection.count; i++)
            {
                QualifiedType pointer;
                auto p = new TypePointer;
                p->pointed = type;
                pointer.type = p;
                pointer.mut = true;
                pointer.ref = false;
                type = pointer;
            }
        }
        
        
        if(!type.type)
            isComplete = false;
    }
    else
    {
        isComplete = false;
    }
    
    if(array)
    {
        TypeArray *arrayType =new TypeArray;
        arrayType->size = array;
        arrayType->elementType = type;
        type.type = arrayType;
    }
    
}


void TypeCheck(Expression &to, Expression &from)
{
    
    auto t = to.type.type;
    auto f = from.type.type;
    
    TypePointer *ll = Is<TypePointer>(to.type.type);
    TypePointer *rr = Is<TypePointer>(from.type.type);
    
    while(ll && rr)
    {
        
        if(ll->pointed.mut && !rr->pointed.mut)
        {
            throw ParseError(std::string("Cannot introduce mutability to non mutable type '" + ToString(from.type)) + "'", to.source);
        }
        ll = Is<TypePointer>(ll->pointed.type);
        rr = Is<TypePointer>(rr->pointed.type);
    }
    
    
    if(!t && !f)
    {
        return;
    }
    
    if(!t){
        throw ParseError("Can't implicitly convert from 'void' to '" +
                         ToString(*f) + '\'', from.source);
    }
    if(!f){
        throw ParseError("Can't implicitly convert from '" +
                         ToString(*t) + "' to '" +
                         "void" + '\'', to.source);
    }
    
    if(t == f) return;
    
    if(t->is == Type::Record && f->is == Type::Record)
    {
        TypeRecord *fr = (TypeRecord*)f;
        TypeRecord *tr = (TypeRecord*)t;
        for(auto convert : fr->structure->conversions)
        {
            if(convert == tr->structure)
            {
                return;
            }
        }
        
        throw ParseError("Can't implicitly convert from '" +
                         ToString(*fr) + "' to '" +
                         ToString(*tr) + '\'', to.source);

    }
    if(t->is == Type::Function && f->is == Type::Function)
    {
        TypeFunction *fr = (TypeFunction*)f;
        TypeFunction *tr = (TypeFunction*)t;
        if(!Same(*fr->procedure, *tr->procedure))
        {
            throw ParseError("Can't convert from '" +
                             ToString(*fr) + "' to '" +
                             ToString(*tr) + '\'', to.source);
        }
    }
}


