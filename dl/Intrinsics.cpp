//
//  Intrinsics.cpp
//  Created by David on 8/24/16.
//

#include "Intrinsics.h"

IntrinsicStruct Types::Int;
IntrinsicStruct Types::Int32;
IntrinsicStruct Types::Int16;
IntrinsicStruct Types::Int8;
    
IntrinsicStruct Types::Uint;
IntrinsicStruct Types::Uint32;
IntrinsicStruct Types::Uint16;
IntrinsicStruct Types::Uint8;
    
IntrinsicStruct Types::VoidPtr;

IntrinsicStruct Types::Float;
IntrinsicStruct Types::Float32;
    
IntrinsicStruct Types::Num;


    
IntrinsicFunc Instrinsic::pointerAdd;
IntrinsicFunc Instrinsic::pointerSub;

vector<IntrinsicFunc*> Instrinsic::intrinsics;

IntrinsicFunc *Instrinsic::bitOri;
IntrinsicFunc *Instrinsic::bitAndi;
    
IntrinsicFunc *Instrinsic::ori;
IntrinsicFunc *Instrinsic::ori32;
IntrinsicFunc *Instrinsic::oru;
IntrinsicFunc *Instrinsic::oru32;
IntrinsicFunc *Instrinsic::orf;
IntrinsicFunc *Instrinsic::orf32;
    
IntrinsicFunc *Instrinsic::andi;
IntrinsicFunc *Instrinsic::andi32;
IntrinsicFunc *Instrinsic::andu;
IntrinsicFunc *Instrinsic::andu32;
IntrinsicFunc *Instrinsic::andf;
IntrinsicFunc *Instrinsic::andf32;
    
IntrinsicFunc *Instrinsic::addi;
IntrinsicFunc *Instrinsic::addi32;
IntrinsicFunc *Instrinsic::addu;
IntrinsicFunc *Instrinsic::addu32;
IntrinsicFunc *Instrinsic::addf;
IntrinsicFunc *Instrinsic::addf32;
    
IntrinsicFunc *Instrinsic::subi;
IntrinsicFunc *Instrinsic::subi32;
IntrinsicFunc *Instrinsic::subu;
IntrinsicFunc *Instrinsic::subu32;
IntrinsicFunc *Instrinsic::subf;
IntrinsicFunc *Instrinsic::subf32;
    
IntrinsicFunc *Instrinsic::multi;
IntrinsicFunc *Instrinsic::multi32;
IntrinsicFunc *Instrinsic::multu;
IntrinsicFunc *Instrinsic::multu32;
IntrinsicFunc *Instrinsic::multf;
IntrinsicFunc *Instrinsic::multf32;
    
IntrinsicFunc *Instrinsic::divi;
IntrinsicFunc *Instrinsic::divi32;
IntrinsicFunc *Instrinsic::divu;
IntrinsicFunc *Instrinsic::divu32;
IntrinsicFunc *Instrinsic::divf;
IntrinsicFunc *Instrinsic::divf32;
    
IntrinsicFunc *Instrinsic::bitShiftLeft;
IntrinsicFunc *Instrinsic::bitShiftRight;
    
IntrinsicFunc *Instrinsic::modi;
    
IntrinsicFunc *Instrinsic::equalsi;
IntrinsicFunc *Instrinsic::equalsi32;
IntrinsicFunc *Instrinsic::equalsu;
IntrinsicFunc *Instrinsic::equalsu32;
IntrinsicFunc *Instrinsic::equalf32;
IntrinsicFunc *Instrinsic::equalf64;
    
IntrinsicFunc *Instrinsic::lessequalsi;
IntrinsicFunc *Instrinsic::lessequalsi32;
IntrinsicFunc *Instrinsic::lessequalsu;
IntrinsicFunc *Instrinsic::lessequalsu32;
IntrinsicFunc *Instrinsic::lessequalsf32;
IntrinsicFunc *Instrinsic::lessequalsf64;
    
IntrinsicFunc *Instrinsic::notequali;
IntrinsicFunc *Instrinsic::notequali32;
IntrinsicFunc *Instrinsic::notequalu;
IntrinsicFunc *Instrinsic::notequalu32;
    
IntrinsicFunc *Instrinsic::greaterequalsi;
IntrinsicFunc *Instrinsic::greaterequalsi32;
IntrinsicFunc *Instrinsic::greaterequalsu;
IntrinsicFunc *Instrinsic::greaterequalsu32;
IntrinsicFunc *Instrinsic::greaterequalsf32;
IntrinsicFunc *Instrinsic::greaterequalsf64;
    
IntrinsicFunc *Instrinsic::lessi;
IntrinsicFunc *Instrinsic::lessi32;
IntrinsicFunc *Instrinsic::lessu;
IntrinsicFunc *Instrinsic::lessu32;
IntrinsicFunc *Instrinsic::lessf32;
IntrinsicFunc *Instrinsic::lessf64;

IntrinsicFunc *Instrinsic::greateri;
IntrinsicFunc *Instrinsic::greateri32;
IntrinsicFunc *Instrinsic::greateru;
IntrinsicFunc *Instrinsic::greateru32;
IntrinsicFunc *Instrinsic::greaterf32;
IntrinsicFunc *Instrinsic::greaterf64;
