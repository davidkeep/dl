//
//  Utility.h
//  Created by David on 12/18/16.
//

#pragma once

#include "Expr.h"

static char* ptr = new char[1024 * 1024 * 25];

struct CopyVisitor
{
    Expr *value;
    void Visit(Expr& node);
};

template<class T>
vector<T> Copy(vector<T>& vec) {
    auto len = vec.size();
    vector<T> v(len);
    for(auto i = 0; i < len; i++){
        v[i] = Copy(vec[i]);
    }
    return std::move(v);
}

template<class T>
Array<T> Copy(Array<T>& vec) {
    Array<T> v;
    v.Reserve(vec.length);
    for(auto i = 0; i < vec.length; i++){
        v.Push(Copy(vec[i]));
    }
    return v;
}

template <class T>
T* Copy(T* self){
    if(self == nullptr) {
        return nullptr;
    }
    CopyVisitor copy;
    copy.Visit(*self);
    return cast<T>(copy.value);
}

template <class T>
T& Copy(T& self){
    CopyVisitor copy;
    copy.Visit(self);
    return cast<T>(*copy.value);
}

template<class T>
T& Create(Coord coord){
    T* arg = (T*)ptr;
    new(arg) T{};
    assert(arg->kind != Ast::None);
    ptr += sizeof(T);
    arg->coord = coord;
    return *arg;
}

