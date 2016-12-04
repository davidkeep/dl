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

struct Types{
    static IntrinsicStructDef Int;
    static IntrinsicStructDef Int32;
    static IntrinsicStructDef Int16;
    static IntrinsicStructDef Int8;
    
    static IntrinsicStructDef Uint;
    static IntrinsicStructDef Uint32;
    static IntrinsicStructDef Uint16;
    static IntrinsicStructDef Uint8;
    
    static IntrinsicStructDef VoidPtr;

    static IntrinsicStructDef Float;
    static IntrinsicStructDef Float32;
    
    static IntrinsicStructDef Num;
};

struct Instrinsic{
    
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
    
    static void Init(){
        
        Types::Num.ident= "Num";
        
        Types::Int.ident= "i64";
        Types::Int32.ident= "i32";
        Types::Int16.ident= "i16";
        Types::Int8.ident= "i8";
        
        Types::Uint.ident= "u64";
        Types::Uint32.ident= "u32";
        Types::Uint16.ident= "u16";
        Types::Uint8.ident= "u8";
        
        Types::Float.ident= "f64";
        Types::Float32.ident= "f32";
        
        Types::VoidPtr.ident= "voidptr";
        
        auto create = [](IntrinsicFuncDef*& def, const string& name, IntrinsicStructDef& type){
            def = new IntrinsicFuncDef;
            def->ident= name;
            def->params.list = {{"",&type}, {"",&type}};
            def->results.list = {{"",&type}};
            intrinsics.push_back(def);
        };
        auto Create = [](IntrinsicFuncDef*& def, const string& name, IntrinsicStructDef& type, IntrinsicStructDef&result){
            def = new IntrinsicFuncDef;
            def->ident= name;
            def->params.list = {{"",&type}, {"",&type}};
            def->results.list = {{"",&result}};
            intrinsics.push_back(def);
        };
        

        
        create(bitAndi, "bitAnd", Types::Int);
        create(bitOri, "bitOr", Types::Int);
        
        create(bitShiftLeft, "BitShiftLeft", Types::Int);
        create(bitShiftRight, "BitShiftRight", Types::Int);

        create(andi32, "and", Types::Int32);
        create(andi, "and", Types::Int);
        create(andf, "and", Types::Float);
        create(andf32, "and", Types::Float32);
        create(andu, "and", Types::Uint);
        create(andu32, "and", Types::Uint32);
        
        create(ori32, "or", Types::Int32);
        create(ori, "or", Types::Int);
        create(orf, "or", Types::Float);
        create(orf32, "or", Types::Float32);
        create(oru, "or", Types::Uint);
        create(oru32, "or", Types::Uint32);
        
        create(addi32, "add", Types::Int32);
        create(addi, "add", Types::Int);
        create(addf, "add", Types::Float);
        create(addf32, "add", Types::Float32);
        create(addu32, "add", Types::Uint32);
        create(addu, "add", Types::Uint);

        create(subi32, "sub", Types::Int32);
        create(subi, "sub", Types::Int);
        create(subf, "sub", Types::Float);
        create(subf32, "sub", Types::Float32);
        create(subu, "sub", Types::Uint);
        create(subu32, "sub", Types::Uint32);
        
        create(divi32, "div", Types::Int32);
        create(divi, "div", Types::Int);
        create(divf, "div", Types::Float);
        create(divf32, "div", Types::Float32);
        create(divu, "div", Types::Uint);
        create(divu32, "div", Types::Uint32);
        
        create(multi32, "mul", Types::Int32);
        create(multi, "mul", Types::Int);
        create(multf, "mul", Types::Float);
        create(multf32, "mul", Types::Float32);
        create(multu, "mul", Types::Uint);
        create(multu32, "mul", Types::Uint32);
        
        create(modi, "mod", Types::Int);

        Create(equalsi, "equal", Types::Int, Types::Int8);
        Create(equalsi32, "equal", Types::Int32, Types::Int8);
        Create(equalsu, "equal", Types::Uint, Types::Int8);
        Create(equalsu32, "equal", Types::Uint32, Types::Int8);
        Create(equalf32, "equal", Types::Float, Types::Int8);
        Create(equalf64, "equal", Types::Float32, Types::Int8);
        
        Create(notequali, "notEqual", Types::Int, Types::Int8);
        Create(notequali32, "notEqual", Types::Int32, Types::Int8);
        Create(notequalu, "notEqual", Types::Uint, Types::Int8);
        Create(notequalu32, "notEqual", Types::Uint32, Types::Int8);
        
        Create(lessequalsi, "lessEqual", Types::Int, Types::Int8);
        Create(lessequalsi32, "lessEqual", Types::Int32, Types::Int8);
        Create(lessequalsu, "lessEqual", Types::Uint, Types::Int8);
        Create(lessequalsu32, "lessEqual", Types::Uint32, Types::Int8);
        Create(lessequalsf32, "lessEqual", Types::Float, Types::Int8);
        Create(lessequalsf64, "lessEqual", Types::Float32, Types::Int8);
        
        Create(greaterequalsi, "greaterEqual", Types::Int, Types::Int8);
        Create(greaterequalsi32, "greaterEqual", Types::Int32, Types::Int8);
        Create(greaterequalsu, "greaterEqual", Types::Uint, Types::Int8);
        Create(greaterequalsu32, "greaterEqual", Types::Uint32, Types::Int8);
        Create(greaterequalsf32, "greaterEqual", Types::Float, Types::Int8);
        Create(greaterequalsf64, "greaterEqual", Types::Float32, Types::Int8);
        
        Create(lessequalsi, "lessEqual", Types::Int, Types::Int8);
        Create(lessequalsi32, "lessEqual", Types::Int32, Types::Int8);
        Create(lessequalsu, "lessEqual", Types::Uint, Types::Int8);
        Create(lessequalsu32, "lessEqual", Types::Uint32, Types::Int8);
        Create(lessequalsf32, "lessEqual", Types::Float, Types::Int8);
        Create(lessequalsf64, "lessEqual", Types::Float32, Types::Int8);
        
        Create(greateri, "greater", Types::Int, Types::Int8);
        Create(greateri32, "greater", Types::Int32, Types::Int8);
        Create(greateru, "greater", Types::Uint, Types::Int8);
        Create(greateru32, "greater", Types::Uint32, Types::Int8);
        Create(greaterf32, "greater", Types::Float, Types::Int8);
        Create(greaterf64, "greater", Types::Float32, Types::Int8);
        
        Create(lessi, "less", Types::Int, Types::Int8);
        Create(lessi32, "less", Types::Int32, Types::Int8);
        Create(lessu, "less", Types::Uint, Types::Int8);
        Create(lessu32, "less", Types::Uint32, Types::Int8);
        Create(lessf32, "less", Types::Float, Types::Int8);
        Create(lessf64, "less", Types::Float32, Types::Int8);
        
    }
};

inline void InsertBuiltin(Blck* ast){
    Instrinsic::Init();
    
    ast->Add(&Types::VoidPtr);
    
    ast->Add(&Types::Int);
    ast->Add(&Types::Int32);
    ast->Add(&Types::Int16);
    ast->Add(&Types::Int8);
    
    ast->Add(&Types::Uint);
    ast->Add(&Types::Uint32);
    ast->Add(&Types::Uint16);
    ast->Add(&Types::Uint8);
    
    ast->Add(&Types::Float);
    ast->Add(&Types::Float32);
    
    auto typeinfo = new StructDef;
    typeinfo->ident = "TypeInfo";
    typeinfo->AddField("size", Types::Uint32);
    ast->Add(typeinfo);
    
    for (auto fn : Instrinsic::intrinsics) {
        ast->Add(fn);
    }
}

