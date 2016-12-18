//
//  Intrinsics.h
//  Created by David on 8/24/16.
//

#pragma once
#include "Def.h"

struct IntrinsicFunc : public Func {
    void Visit(IVisitor& visit)override{
        visit.IsIntrinsicFunc(*this);
    }
};

struct IntrinsicStruct : public Struct {
    void Visit(IVisitor& visit)override{
        visit.IsIntrinsicStruct(*this);
    }
};

struct Types{
    static IntrinsicStruct Int;
    static IntrinsicStruct Int32;
    static IntrinsicStruct Int16;
    static IntrinsicStruct Int8;
    
    static IntrinsicStruct Uint;
    static IntrinsicStruct Uint32;
    static IntrinsicStruct Uint16;
    static IntrinsicStruct Uint8;
    
    static IntrinsicStruct VoidPtr;

    static IntrinsicStruct Float;
    static IntrinsicStruct Float32;
    
    static IntrinsicStruct Num;
};

struct Instrinsic{
    
    static IntrinsicFunc pointerAdd;
    static IntrinsicFunc pointerSub;
    static vector<IntrinsicFunc*> intrinsics;

    static IntrinsicFunc *bitOri;
    static IntrinsicFunc *bitAndi;
    
    static IntrinsicFunc *ori;
    static IntrinsicFunc *ori32;
    static IntrinsicFunc *oru;
    static IntrinsicFunc *oru32;
    static IntrinsicFunc *orf;
    static IntrinsicFunc *orf32;
    
    static IntrinsicFunc *andi;
    static IntrinsicFunc *andi32;
    static IntrinsicFunc *andu;
    static IntrinsicFunc *andu32;
    static IntrinsicFunc *andf;
    static IntrinsicFunc *andf32;
    
    static IntrinsicFunc *addi;
    static IntrinsicFunc *addi32;
    static IntrinsicFunc *addu;
    static IntrinsicFunc *addu32;
    static IntrinsicFunc *addf;
    static IntrinsicFunc *addf32;
    
    static IntrinsicFunc *subi;
    static IntrinsicFunc *subi32;
    static IntrinsicFunc *subu;
    static IntrinsicFunc *subu32;
    static IntrinsicFunc *subf;
    static IntrinsicFunc *subf32;
    
    static IntrinsicFunc *multi;
    static IntrinsicFunc *multi32;
    static IntrinsicFunc *multu;
    static IntrinsicFunc *multu32;
    static IntrinsicFunc *multf;
    static IntrinsicFunc *multf32;
    
    static IntrinsicFunc *divi;
    static IntrinsicFunc *divi32;
    static IntrinsicFunc *divu;
    static IntrinsicFunc *divu32;
    static IntrinsicFunc *divf;
    static IntrinsicFunc *divf32;
    
    static IntrinsicFunc *bitShiftLeft;
    static IntrinsicFunc *bitShiftRight;
    
    static IntrinsicFunc *modi;
    
    static IntrinsicFunc *equalsi;
    static IntrinsicFunc *equalsi32;
    static IntrinsicFunc *equalsu;
    static IntrinsicFunc *equalsu32;
    static IntrinsicFunc *equalf32;
    static IntrinsicFunc *equalf64;
    
    static IntrinsicFunc *lessequalsi;
    static IntrinsicFunc *lessequalsi32;
    static IntrinsicFunc *lessequalsu;
    static IntrinsicFunc *lessequalsu32;
    static IntrinsicFunc *lessequalsf32;
    static IntrinsicFunc *lessequalsf64;
    
    static IntrinsicFunc *notequali;
    static IntrinsicFunc *notequali32;
    static IntrinsicFunc *notequalu;
    static IntrinsicFunc *notequalu32;
    
    static IntrinsicFunc *greaterequalsi;
    static IntrinsicFunc *greaterequalsi32;
    static IntrinsicFunc *greaterequalsu;
    static IntrinsicFunc *greaterequalsu32;
    static IntrinsicFunc *greaterequalsf32;
    static IntrinsicFunc *greaterequalsf64;
    
    static IntrinsicFunc *lessi;
    static IntrinsicFunc *lessi32;
    static IntrinsicFunc *lessu;
    static IntrinsicFunc *lessu32;
    static IntrinsicFunc *lessf32;
    static IntrinsicFunc *lessf64;

    static IntrinsicFunc *greateri;
    static IntrinsicFunc *greateri32;
    static IntrinsicFunc *greateru;
    static IntrinsicFunc *greateru32;
    static IntrinsicFunc *greaterf32;
    static IntrinsicFunc *greaterf64;
    
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
        
        auto create = [](IntrinsicFunc*& def, const string& name, IntrinsicStruct& type){
            def = new IntrinsicFunc;
            def->ident= name;
            def->params.list = {{"",&type}, {"",&type}};
            def->results.list = {{"",&type}};
            intrinsics.push_back(def);
        };
        auto Create = [](IntrinsicFunc*& def, const string& name, IntrinsicStruct& type, IntrinsicStruct&result){
            def = new IntrinsicFunc;
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
    
    auto typeinfo = new Struct;
    typeinfo->ident = "TypeInfo";
    typeinfo->AddField("size", Types::Uint32);
    ast->Add(typeinfo);
    
    for (auto fn : Instrinsic::intrinsics) {
        ast->Add(fn);
    }
}

