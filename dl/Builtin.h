//
//  Builtin.h
//  Created by David on 8/24/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
#include "Intrinsics.h"

inline void InsertBuiltin(Blck* ast){
    Instrinsic::Init();
    
    ast->Add(Types::VoidPtr);

    ast->Add(Types::Int);
    ast->Add(Types::Int32);
    ast->Add(Types::Int16);
    ast->Add(Types::Int8);
    
    ast->Add(Types::Uint);
    ast->Add(Types::Uint32);
    ast->Add(Types::Uint16);
    ast->Add(Types::Uint8);

    
    ast->Add(Instrinsic::addi);
    ast->Add(Instrinsic::addi32);
    ast->Add(Instrinsic::addu);
    ast->Add(Instrinsic::addu32);
    
    ast->Add(Instrinsic::divi);
    ast->Add(Instrinsic::divi32);
    ast->Add(Instrinsic::divu);
    ast->Add(Instrinsic::divu32);
    
    ast->Add(Instrinsic::multi);
    ast->Add(Instrinsic::multi32);
    ast->Add(Instrinsic::multu);
    ast->Add(Instrinsic::multu32);
    
    ast->Add(Types::Float);
    ast->Add(Types::Float32);
    
    ast->Add(Instrinsic::addf);
    ast->Add(Instrinsic::addf32);
    
    ast->Add(Instrinsic::divf);
    ast->Add(Instrinsic::divf32);

    ast->Add(Instrinsic::multf);
    ast->Add(Instrinsic::multf32);
}
