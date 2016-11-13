//
//  Intrinsics.cpp
//  Created by David on 8/24/16.
//

#include "Intrinsics.h"

IntrinsicStructDef* Types::Int;
IntrinsicStructDef* Types::Int32;
IntrinsicStructDef* Types::Int16;
IntrinsicStructDef* Types::Int8;
    
IntrinsicStructDef* Types::Uint;
IntrinsicStructDef* Types::Uint32;
IntrinsicStructDef* Types::Uint16;
IntrinsicStructDef* Types::Uint8;
    
IntrinsicStructDef* Types::VoidPtr;

IntrinsicStructDef* Types::Float;
IntrinsicStructDef* Types::Float32;
    
IntrinsicStructDef* Types::Num;


    
IntrinsicFuncDef Instrinsic::pointerAdd;
IntrinsicFuncDef Instrinsic::pointerSub;

vector<IntrinsicFuncDef*> Instrinsic::intrinsics;

IntrinsicFuncDef *Instrinsic::bitOri;
IntrinsicFuncDef *Instrinsic::bitAndi;
    
IntrinsicFuncDef *Instrinsic::ori;
IntrinsicFuncDef *Instrinsic::ori32;
IntrinsicFuncDef *Instrinsic::oru;
IntrinsicFuncDef *Instrinsic::oru32;
IntrinsicFuncDef *Instrinsic::orf;
IntrinsicFuncDef *Instrinsic::orf32;
    
IntrinsicFuncDef *Instrinsic::andi;
IntrinsicFuncDef *Instrinsic::andi32;
IntrinsicFuncDef *Instrinsic::andu;
IntrinsicFuncDef *Instrinsic::andu32;
IntrinsicFuncDef *Instrinsic::andf;
IntrinsicFuncDef *Instrinsic::andf32;
    
IntrinsicFuncDef *Instrinsic::addi;
IntrinsicFuncDef *Instrinsic::addi32;
IntrinsicFuncDef *Instrinsic::addu;
IntrinsicFuncDef *Instrinsic::addu32;
IntrinsicFuncDef *Instrinsic::addf;
IntrinsicFuncDef *Instrinsic::addf32;
    
IntrinsicFuncDef *Instrinsic::subi;
IntrinsicFuncDef *Instrinsic::subi32;
IntrinsicFuncDef *Instrinsic::subu;
IntrinsicFuncDef *Instrinsic::subu32;
IntrinsicFuncDef *Instrinsic::subf;
IntrinsicFuncDef *Instrinsic::subf32;
    
IntrinsicFuncDef *Instrinsic::multi;
IntrinsicFuncDef *Instrinsic::multi32;
IntrinsicFuncDef *Instrinsic::multu;
IntrinsicFuncDef *Instrinsic::multu32;
IntrinsicFuncDef *Instrinsic::multf;
IntrinsicFuncDef *Instrinsic::multf32;
    
IntrinsicFuncDef *Instrinsic::divi;
IntrinsicFuncDef *Instrinsic::divi32;
IntrinsicFuncDef *Instrinsic::divu;
IntrinsicFuncDef *Instrinsic::divu32;
IntrinsicFuncDef *Instrinsic::divf;
IntrinsicFuncDef *Instrinsic::divf32;
    
IntrinsicFuncDef *Instrinsic::bitShiftLeft;
IntrinsicFuncDef *Instrinsic::bitShiftRight;
    
IntrinsicFuncDef *Instrinsic::modi;
    
IntrinsicFuncDef *Instrinsic::equalsi;
IntrinsicFuncDef *Instrinsic::equalsi32;
IntrinsicFuncDef *Instrinsic::equalsu;
IntrinsicFuncDef *Instrinsic::equalsu32;
IntrinsicFuncDef *Instrinsic::equalf32;
IntrinsicFuncDef *Instrinsic::equalf64;
    
IntrinsicFuncDef *Instrinsic::lessequalsi;
IntrinsicFuncDef *Instrinsic::lessequalsi32;
IntrinsicFuncDef *Instrinsic::lessequalsu;
IntrinsicFuncDef *Instrinsic::lessequalsu32;
IntrinsicFuncDef *Instrinsic::lessequalsf32;
IntrinsicFuncDef *Instrinsic::lessequalsf64;
    
IntrinsicFuncDef *Instrinsic::notequali;
IntrinsicFuncDef *Instrinsic::notequali32;
IntrinsicFuncDef *Instrinsic::notequalu;
IntrinsicFuncDef *Instrinsic::notequalu32;
    
IntrinsicFuncDef *Instrinsic::greaterequalsi;
IntrinsicFuncDef *Instrinsic::greaterequalsi32;
IntrinsicFuncDef *Instrinsic::greaterequalsu;
IntrinsicFuncDef *Instrinsic::greaterequalsu32;
IntrinsicFuncDef *Instrinsic::greaterequalsf32;
IntrinsicFuncDef *Instrinsic::greaterequalsf64;
    
IntrinsicFuncDef *Instrinsic::lessi;
IntrinsicFuncDef *Instrinsic::lessi32;
IntrinsicFuncDef *Instrinsic::lessu;
IntrinsicFuncDef *Instrinsic::lessu32;
IntrinsicFuncDef *Instrinsic::lessf32;
IntrinsicFuncDef *Instrinsic::lessf64;

IntrinsicFuncDef *Instrinsic::greateri;
IntrinsicFuncDef *Instrinsic::greateri32;
IntrinsicFuncDef *Instrinsic::greateru;
IntrinsicFuncDef *Instrinsic::greateru32;
IntrinsicFuncDef *Instrinsic::greaterf32;
IntrinsicFuncDef *Instrinsic::greaterf64;