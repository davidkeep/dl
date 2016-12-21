//
//  Intrinsics.cpp
//  Created by David on 8/24/16.
//

#include "Intrinsics.h"

StructIntrins Types::Int;
StructIntrins Types::Int32;
StructIntrins Types::Int16;
StructIntrins Types::Int8;
    
StructIntrins Types::Uint;
StructIntrins Types::Uint32;
StructIntrins Types::Uint16;
StructIntrins Types::Uint8;
    
StructIntrins Types::VoidPtr;

StructIntrins Types::Float;
StructIntrins Types::Float32;
    
StructIntrins Types::Num;


    
FuncIntrins Instrinsic::pointerAdd;
FuncIntrins Instrinsic::pointerSub;

vector<FuncIntrins*> Instrinsic::intrinsics;

FuncIntrins *Instrinsic::bitOri;
FuncIntrins *Instrinsic::bitAndi;
    
FuncIntrins *Instrinsic::ori;
FuncIntrins *Instrinsic::ori32;
FuncIntrins *Instrinsic::oru;
FuncIntrins *Instrinsic::oru32;
FuncIntrins *Instrinsic::orf;
FuncIntrins *Instrinsic::orf32;
    
FuncIntrins *Instrinsic::andi;
FuncIntrins *Instrinsic::andi32;
FuncIntrins *Instrinsic::andu;
FuncIntrins *Instrinsic::andu32;
FuncIntrins *Instrinsic::andf;
FuncIntrins *Instrinsic::andf32;
    
FuncIntrins *Instrinsic::addi;
FuncIntrins *Instrinsic::addi32;
FuncIntrins *Instrinsic::addu;
FuncIntrins *Instrinsic::addu32;
FuncIntrins *Instrinsic::addf;
FuncIntrins *Instrinsic::addf32;
    
FuncIntrins *Instrinsic::subi;
FuncIntrins *Instrinsic::subi32;
FuncIntrins *Instrinsic::subu;
FuncIntrins *Instrinsic::subu32;
FuncIntrins *Instrinsic::subf;
FuncIntrins *Instrinsic::subf32;
    
FuncIntrins *Instrinsic::multi;
FuncIntrins *Instrinsic::multi32;
FuncIntrins *Instrinsic::multu;
FuncIntrins *Instrinsic::multu32;
FuncIntrins *Instrinsic::multf;
FuncIntrins *Instrinsic::multf32;
    
FuncIntrins *Instrinsic::divi;
FuncIntrins *Instrinsic::divi32;
FuncIntrins *Instrinsic::divu;
FuncIntrins *Instrinsic::divu32;
FuncIntrins *Instrinsic::divf;
FuncIntrins *Instrinsic::divf32;
    
FuncIntrins *Instrinsic::bitShiftLeft;
FuncIntrins *Instrinsic::bitShiftRight;
    
FuncIntrins *Instrinsic::modi;
    
FuncIntrins *Instrinsic::equalsi;
FuncIntrins *Instrinsic::equalsi32;
FuncIntrins *Instrinsic::equalsu;
FuncIntrins *Instrinsic::equalsu32;
FuncIntrins *Instrinsic::equalf32;
FuncIntrins *Instrinsic::equalf64;
    
FuncIntrins *Instrinsic::lessequalsi;
FuncIntrins *Instrinsic::lessequalsi32;
FuncIntrins *Instrinsic::lessequalsu;
FuncIntrins *Instrinsic::lessequalsu32;
FuncIntrins *Instrinsic::lessequalsf32;
FuncIntrins *Instrinsic::lessequalsf64;
    
FuncIntrins *Instrinsic::notequali;
FuncIntrins *Instrinsic::notequali32;
FuncIntrins *Instrinsic::notequalu;
FuncIntrins *Instrinsic::notequalu32;
    
FuncIntrins *Instrinsic::greaterequalsi;
FuncIntrins *Instrinsic::greaterequalsi32;
FuncIntrins *Instrinsic::greaterequalsu;
FuncIntrins *Instrinsic::greaterequalsu32;
FuncIntrins *Instrinsic::greaterequalsf32;
FuncIntrins *Instrinsic::greaterequalsf64;
    
FuncIntrins *Instrinsic::lessi;
FuncIntrins *Instrinsic::lessi32;
FuncIntrins *Instrinsic::lessu;
FuncIntrins *Instrinsic::lessu32;
FuncIntrins *Instrinsic::lessf32;
FuncIntrins *Instrinsic::lessf64;

FuncIntrins *Instrinsic::greateri;
FuncIntrins *Instrinsic::greateri32;
FuncIntrins *Instrinsic::greateru;
FuncIntrins *Instrinsic::greateru32;
FuncIntrins *Instrinsic::greaterf32;
FuncIntrins *Instrinsic::greaterf64;
