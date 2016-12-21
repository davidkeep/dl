//
//  Intrinsics.h
//  Created by David on 8/24/16.
//

#pragma once
#include "Def.h"
#include "Utility.h"

struct Types
{
    static StructIntrins Int;
    static StructIntrins Int32;
    static StructIntrins Int16;
    static StructIntrins Int8;
    
    static StructIntrins Uint;
    static StructIntrins Uint32;
    static StructIntrins Uint16;
    static StructIntrins Uint8;
    
    static StructIntrins VoidPtr;

    static StructIntrins Float;
    static StructIntrins Float32;

    static StructIntrins Num;
};

struct Instrinsic{
    
    static FuncIntrins pointerAdd;
    static FuncIntrins pointerSub;
    static vector<FuncIntrins*> intrinsics;

    static FuncIntrins *bitOri;
    static FuncIntrins *bitAndi;
    
    static FuncIntrins *ori;
    static FuncIntrins *ori32;
    static FuncIntrins *oru;
    static FuncIntrins *oru32;
    static FuncIntrins *orf;
    static FuncIntrins *orf32;
    
    static FuncIntrins *andi;
    static FuncIntrins *andi32;
    static FuncIntrins *andu;
    static FuncIntrins *andu32;
    static FuncIntrins *andf;
    static FuncIntrins *andf32;
    
    static FuncIntrins *addi;
    static FuncIntrins *addi32;
    static FuncIntrins *addu;
    static FuncIntrins *addu32;
    static FuncIntrins *addf;
    static FuncIntrins *addf32;
    
    static FuncIntrins *subi;
    static FuncIntrins *subi32;
    static FuncIntrins *subu;
    static FuncIntrins *subu32;
    static FuncIntrins *subf;
    static FuncIntrins *subf32;
    
    static FuncIntrins *multi;
    static FuncIntrins *multi32;
    static FuncIntrins *multu;
    static FuncIntrins *multu32;
    static FuncIntrins *multf;
    static FuncIntrins *multf32;
    
    static FuncIntrins *divi;
    static FuncIntrins *divi32;
    static FuncIntrins *divu;
    static FuncIntrins *divu32;
    static FuncIntrins *divf;
    static FuncIntrins *divf32;
    
    static FuncIntrins *bitShiftLeft;
    static FuncIntrins *bitShiftRight;
    
    static FuncIntrins *modi;
    
    static FuncIntrins *equalsi;
    static FuncIntrins *equalsi32;
    static FuncIntrins *equalsu;
    static FuncIntrins *equalsu32;
    static FuncIntrins *equalf32;
    static FuncIntrins *equalf64;
    
    static FuncIntrins *lessequalsi;
    static FuncIntrins *lessequalsi32;
    static FuncIntrins *lessequalsu;
    static FuncIntrins *lessequalsu32;
    static FuncIntrins *lessequalsf32;
    static FuncIntrins *lessequalsf64;
    
    static FuncIntrins *notequali;
    static FuncIntrins *notequali32;
    static FuncIntrins *notequalu;
    static FuncIntrins *notequalu32;
    
    static FuncIntrins *greaterequalsi;
    static FuncIntrins *greaterequalsi32;
    static FuncIntrins *greaterequalsu;
    static FuncIntrins *greaterequalsu32;
    static FuncIntrins *greaterequalsf32;
    static FuncIntrins *greaterequalsf64;
    
    static FuncIntrins *lessi;
    static FuncIntrins *lessi32;
    static FuncIntrins *lessu;
    static FuncIntrins *lessu32;
    static FuncIntrins *lessf32;
    static FuncIntrins *lessf64;

    static FuncIntrins *greateri;
    static FuncIntrins *greateri32;
    static FuncIntrins *greateru;
    static FuncIntrins *greateru32;
    static FuncIntrins *greaterf32;
    static FuncIntrins *greaterf64;
    
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
        
        auto create = [](FuncIntrins*& def, const string& name, StructIntrins& type){
            def = &Create<FuncIntrins>({});
            def->ident= name;
            def->params.list = {{"",&type}, {"",&type}};
            def->results.list = {{"",&type}};
            intrinsics.push_back(def);
        };
        auto Ccreate = [](FuncIntrins*& def, const string& name, StructIntrins& type, StructIntrins&result){
            def = &Create<FuncIntrins>({});
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

        Ccreate(equalsi, "equal", Types::Int, Types::Int8);
        Ccreate(equalsi32, "equal", Types::Int32, Types::Int8);
        Ccreate(equalsu, "equal", Types::Uint, Types::Int8);
        Ccreate(equalsu32, "equal", Types::Uint32, Types::Int8);
        Ccreate(equalf32, "equal", Types::Float, Types::Int8);
        Ccreate(equalf64, "equal", Types::Float32, Types::Int8);
        
        Ccreate(notequali, "notEqual", Types::Int, Types::Int8);
        Ccreate(notequali32, "notEqual", Types::Int32, Types::Int8);
        Ccreate(notequalu, "notEqual", Types::Uint, Types::Int8);
        Ccreate(notequalu32, "notEqual", Types::Uint32, Types::Int8);
        
        Ccreate(lessequalsi, "lessEqual", Types::Int, Types::Int8);
        Ccreate(lessequalsi32, "lessEqual", Types::Int32, Types::Int8);
        Ccreate(lessequalsu, "lessEqual", Types::Uint, Types::Int8);
        Ccreate(lessequalsu32, "lessEqual", Types::Uint32, Types::Int8);
        Ccreate(lessequalsf32, "lessEqual", Types::Float, Types::Int8);
        Ccreate(lessequalsf64, "lessEqual", Types::Float32, Types::Int8);
        
        Ccreate(greaterequalsi, "greaterEqual", Types::Int, Types::Int8);
        Ccreate(greaterequalsi32, "greaterEqual", Types::Int32, Types::Int8);
        Ccreate(greaterequalsu, "greaterEqual", Types::Uint, Types::Int8);
        Ccreate(greaterequalsu32, "greaterEqual", Types::Uint32, Types::Int8);
        Ccreate(greaterequalsf32, "greaterEqual", Types::Float, Types::Int8);
        Ccreate(greaterequalsf64, "greaterEqual", Types::Float32, Types::Int8);
        
        Ccreate(lessequalsi, "lessEqual", Types::Int, Types::Int8);
        Ccreate(lessequalsi32, "lessEqual", Types::Int32, Types::Int8);
        Ccreate(lessequalsu, "lessEqual", Types::Uint, Types::Int8);
        Ccreate(lessequalsu32, "lessEqual", Types::Uint32, Types::Int8);
        Ccreate(lessequalsf32, "lessEqual", Types::Float, Types::Int8);
        Ccreate(lessequalsf64, "lessEqual", Types::Float32, Types::Int8);
        
        Ccreate(greateri, "greater", Types::Int, Types::Int8);
        Ccreate(greateri32, "greater", Types::Int32, Types::Int8);
        Ccreate(greateru, "greater", Types::Uint, Types::Int8);
        Ccreate(greateru32, "greater", Types::Uint32, Types::Int8);
        Ccreate(greaterf32, "greater", Types::Float, Types::Int8);
        Ccreate(greaterf64, "greater", Types::Float32, Types::Int8);
        
        Ccreate(lessi, "less", Types::Int, Types::Int8);
        Ccreate(lessi32, "less", Types::Int32, Types::Int8);
        Ccreate(lessu, "less", Types::Uint, Types::Int8);
        Ccreate(lessu32, "less", Types::Uint32, Types::Int8);
        Ccreate(lessf32, "less", Types::Float, Types::Int8);
        Ccreate(lessf64, "less", Types::Float32, Types::Int8);
        
    }
};

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
    
    auto typeinfo = &Create<Struct>({});
    typeinfo->ident = "TypeInfo";
    typeinfo->AddField("size", Types::Uint32);
    ast->Add(*typeinfo);
    
    for (auto fn : Instrinsic::intrinsics) {
        ast->Add(*fn);
    }
}

