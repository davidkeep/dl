//
//  Intrinsics.h
//  Created by David on 8/24/16.
//

#pragma once
#include "Def.h"

struct IntrinsicFuncDef : public FuncDef {
    void Visit(IVisitor& visit)override{
        visit.IsIntrinsicFuncDef(*this);
    }
};

struct IntrinsicStructDef : public StructDef {
    void Visit(IVisitor& visit)override{
        visit.IsIntrinsicStructDef(*this);
    }
};

namespace Types{
    static IntrinsicStructDef* Int;
    static IntrinsicStructDef* Int32;
    static IntrinsicStructDef* Int16;
    static IntrinsicStructDef* Int8;
    
    static IntrinsicStructDef* Uint;
    static IntrinsicStructDef* Uint32;
    static IntrinsicStructDef* Uint16;
    static IntrinsicStructDef* Uint8;
    
    static IntrinsicStructDef* VoidPtr;

    static IntrinsicStructDef* Float;
    static IntrinsicStructDef* Float32;
    
    static IntrinsicStructDef* Num;
}

namespace Instrinsic{
    
    static IntrinsicFuncDef pointerAdd;
    static IntrinsicFuncDef pointerSub;
    static vector<IntrinsicFuncDef*> intrinsics;

    static IntrinsicFuncDef *bitOri;
    static IntrinsicFuncDef *bitAndi;
    
    static IntrinsicFuncDef *ori;
    static IntrinsicFuncDef *ori32;
    static IntrinsicFuncDef *oru;
    static IntrinsicFuncDef *oru32;
    static IntrinsicFuncDef *orf;
    static IntrinsicFuncDef *orf32;
    
    static IntrinsicFuncDef *andi;
    static IntrinsicFuncDef *andi32;
    static IntrinsicFuncDef *andu;
    static IntrinsicFuncDef *andu32;
    static IntrinsicFuncDef *andf;
    static IntrinsicFuncDef *andf32;
    
    static IntrinsicFuncDef *addi;
    static IntrinsicFuncDef *addi32;
    static IntrinsicFuncDef *addu;
    static IntrinsicFuncDef *addu32;
    static IntrinsicFuncDef *addf;
    static IntrinsicFuncDef *addf32;
    
    static IntrinsicFuncDef *subi;
    static IntrinsicFuncDef *subi32;
    static IntrinsicFuncDef *subu;
    static IntrinsicFuncDef *subu32;
    static IntrinsicFuncDef *subf;
    static IntrinsicFuncDef *subf32;
    
    static IntrinsicFuncDef *multi;
    static IntrinsicFuncDef *multi32;
    static IntrinsicFuncDef *multu;
    static IntrinsicFuncDef *multu32;
    static IntrinsicFuncDef *multf;
    static IntrinsicFuncDef *multf32;
    
    static IntrinsicFuncDef *divi;
    static IntrinsicFuncDef *divi32;
    static IntrinsicFuncDef *divu;
    static IntrinsicFuncDef *divu32;
    static IntrinsicFuncDef *divf;
    static IntrinsicFuncDef *divf32;
    
    static IntrinsicFuncDef *bitShiftLeft;
    static IntrinsicFuncDef *bitShiftRight;
    
    static IntrinsicFuncDef *modi;
    
    static IntrinsicFuncDef *equalsi;
    static IntrinsicFuncDef *equalsi32;
    static IntrinsicFuncDef *equalsu;
    static IntrinsicFuncDef *equalsu32;
    static IntrinsicFuncDef *equalf32;
    static IntrinsicFuncDef *equalf64;
    
    static IntrinsicFuncDef *lessequalsi;
    static IntrinsicFuncDef *lessequalsi32;
    static IntrinsicFuncDef *lessequalsu;
    static IntrinsicFuncDef *lessequalsu32;
    static IntrinsicFuncDef *lessequalsf32;
    static IntrinsicFuncDef *lessequalsf64;
    
    static IntrinsicFuncDef *notequali;
    static IntrinsicFuncDef *notequali32;
    static IntrinsicFuncDef *notequalu;
    static IntrinsicFuncDef *notequalu32;
    
    static IntrinsicFuncDef *greaterequalsi;
    static IntrinsicFuncDef *greaterequalsi32;
    static IntrinsicFuncDef *greaterequalsu;
    static IntrinsicFuncDef *greaterequalsu32;
    static IntrinsicFuncDef *greaterequalsf32;
    static IntrinsicFuncDef *greaterequalsf64;
    
    static IntrinsicFuncDef *lessi;
    static IntrinsicFuncDef *lessi32;
    static IntrinsicFuncDef *lessu;
    static IntrinsicFuncDef *lessu32;
    static IntrinsicFuncDef *lessf32;
    static IntrinsicFuncDef *lessf64;

    static IntrinsicFuncDef *greateri;
    static IntrinsicFuncDef *greateri32;
    static IntrinsicFuncDef *greateru;
    static IntrinsicFuncDef *greateru32;
    static IntrinsicFuncDef *greaterf32;
    static IntrinsicFuncDef *greaterf64;
    
    inline void Init(){
        using namespace Types;
        
        Num = new IntrinsicStructDef;
        Num->ident= "Num";
        
        Int = new IntrinsicStructDef;
        Int->ident= "int";
        Int32 = new IntrinsicStructDef;
        Int32->ident= "int32";
        Int16 = new IntrinsicStructDef;
        Int16->ident= "int16";
        Int8 = new IntrinsicStructDef;
        Int8->ident= "int8";
        
        Uint = new IntrinsicStructDef;
        Uint->ident= "uint";
        Uint32 = new IntrinsicStructDef;
        Uint32->ident= "uint32";
        Uint16 = new IntrinsicStructDef;
        Uint16->ident= "uint16";
        Uint8 = new IntrinsicStructDef;
        Uint8->ident= "uint8";
        
        Float = new IntrinsicStructDef;
        Float->ident= "float64";
        Float32 = new IntrinsicStructDef;
        Float32->ident= "float32";
        
        VoidPtr = new IntrinsicStructDef;
        VoidPtr->ident= "voidptr";
        
        auto create = [](IntrinsicFuncDef*& def, const string& name, IntrinsicStructDef*type){
            def = new IntrinsicFuncDef;
            def->ident= name;
            def->args = new DecList;
            def->args->list = {{"",type}, {"",type}};
            def->ret = new DecList;
            def->ret->list = {{"",type}};
            intrinsics.push_back(def);
        };
        

        
        create(bitAndi, "bitAnd", Int);
        create(bitOri, "bitOr", Int);
        
        create(bitShiftLeft, "BitShiftLeft", Int);
        create(bitShiftRight, "BitShiftRight", Int);

        create(andi32, "and", Int32);
        create(andi, "and", Int);
        create(andf, "and", Float);
        create(andf32, "and", Float32);
        create(andu, "and", Uint);
        create(andu32, "and", Uint32);
        
        create(ori32, "or", Int32);
        create(ori, "or", Int);
        create(orf, "or", Float);
        create(orf32, "or", Float32);
        create(oru, "or", Uint);
        create(oru32, "or", Uint32);
        
        create(addi32, "add", Int32);
        create(addi, "add", Int);
        create(addf, "add", Float);
        create(addf32, "add", Float32);
        create(addu, "add", Uint);
        create(addu32, "add", Uint32);
        
        create(subi32, "sub", Int32);
        create(subi, "sub", Int);
        create(subf, "sub", Float);
        create(subf32, "sub", Float32);
        create(subu, "sub", Uint);
        create(subu32, "sub", Uint32);
        
        create(divi32, "div", Int32);
        create(divi, "div", Int);
        create(divf, "div", Float);
        create(divf32, "div", Float32);
        create(divu, "div", Uint);
        create(divu32, "div", Uint32);
        
        create(multi32, "mul", Int32);
        create(multi, "mul", Int);
        create(multf, "mul", Float);
        create(multf32, "mul", Float32);
        create(multu, "mul", Uint);
        create(multu32, "mul", Uint32);
        
        create(modi, "mod", Int);

        create(equalsi, "equal", Int);
        create(equalsi32, "equal", Int32);
        create(equalsu, "equal", Uint);
        create(equalsu32, "equal", Uint32);
        create(equalf32, "equal", Float);
        create(equalf64, "equal", Float32);
        
        create(notequali, "notEqual", Int);
        create(notequali32, "notEqual", Int32);
        create(notequalu, "notEqual", Uint);
        create(notequalu32, "notEqual", Uint32);
        
        create(lessequalsi, "lessEqual", Int);
        create(lessequalsi32, "lessEqual", Int32);
        create(lessequalsu, "lessEqual", Uint);
        create(lessequalsu32, "lessEqual", Uint32);
        create(lessequalsf32, "lessEqual", Float);
        create(lessequalsf64, "lessEqual", Float32);
        
        create(greaterequalsi, "greaterEqual", Int);
        create(greaterequalsi32, "greaterEqual", Int32);
        create(greaterequalsu, "greaterEqual", Uint);
        create(greaterequalsu32, "greaterEqual", Uint32);
        create(greaterequalsf32, "greaterEqual", Float);
        create(greaterequalsf64, "greaterEqual", Float32);
        
        create(lessequalsi, "lessEqual", Int);
        create(lessequalsi32, "lessEqual", Int32);
        create(lessequalsu, "lessEqual", Uint);
        create(lessequalsu32, "lessEqual", Uint32);
        create(lessequalsf32, "lessEqual", Float);
        create(lessequalsf64, "lessEqual", Float32);
        
        create(greateri, "greater", Int);
        create(greateri32, "greater", Int32);
        create(greateru, "greater", Uint);
        create(greateru32, "greater", Uint32);
        create(greaterf32, "greater", Float);
        create(greaterf64, "greater", Float32);
        
        create(lessi, "less", Int);
        create(lessi32, "less", Int32);
        create(lessu, "less", Uint);
        create(lessu32, "less", Uint32);
        create(lessf32, "less", Float);
        create(lessf64, "less", Float32);
        
    }
}

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
    
    ast->Add(Types::Float);
    ast->Add(Types::Float32);
    
    
    for (auto fn : Instrinsic::intrinsics) {
        ast->Add(fn);
    }
}

