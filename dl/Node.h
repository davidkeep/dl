//
//  Node.h
//  Created by David on 5/27/16.
//

#pragma once
#include "Error.h"
#include "Symbol.h"

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

static inline string String(const int&v){
    return std::to_string(v);
}

static inline string String(const i64&v){
    return std::to_string(v);
}

inline void Print(const char* str){
    fputs(str, stdout);
    fflush(stdout);
}
inline void Print(const string &str){
    Print(str.c_str());
}

template<class T>
void Print(const T &type)
{
    Print(String(type));
}

struct Blck;
struct Visitor;
struct Node
{
    Coord coord;
    Blck *parent = nullptr;
    
    virtual Node *Copy() const { assert(false); };
    virtual void Visit(IVisitor &visitor){
        assert(false && "No visitor for derived type");
        visitor.IsNode(*this);
    }
    virtual ~Node(){}
};

template<class T>
vector<T> Copy(const vector<T>& vec) {
    auto len = vec.size();
    vector<T> v(len);
    for(auto i = 0; i < len; i++){
        v[i] = vec[i]->Copy();
    }
    return std::move(v);
}

template<class T>
T* Copy(T* t){
    return t ? t->Copy() : nullptr;
}

template<class T, class F>
T* cast(F* t){
    assert(dynamic_cast<T*>(t));
    return (T*)t;
}

template<class T, class F>
T& cast(F& t){
    assert(dynamic_cast<T*>(&t));
    return (T&)t;
}


