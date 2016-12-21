//
//  Symbol.h
//  Created by David on 5/21/16.
//

#pragma once
#include <string>
#include <map>
#include <vector>
#include <exception>
#include <assert.h>

using string = std::string;

template<class T>
using vector = std::vector<T>;

template<class Key, class Value>
using table = std::map<Key, Value>;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

template<class T, class Enable = void>
struct Array {};

template<class T>
struct Array<T, typename std::enable_if<!std::is_reference<T>::value>::type> {
    
    Array(){}
    Array(std::initializer_list<T> list){
        Reserve(list.size());
        for (auto &t : list) {
            Push(t);
        }
    }
    void operator=(std::initializer_list<T> list)
    {
        length = 0;
        Reserve((int)list.size());
        for (auto &t : list) {
            Push(t);
        }
    }

    void operator=(Array&& t){
        for (int i = 0; i < 10; i++) {
            local[i] = t.local[i];

        }
        if(t.capacity) data = t.data;
        length = t.length;
        capacity = t.capacity;
        t.data = nullptr;
        t.capacity = -1;
        t.length = -1;
    }
    Array(Array &&t)
    {
        for (int i = 0; i < 10; i++) {
            local[i] = t.local[i];
            
        }
        if(t.capacity) data = t.data;
        length = t.length;
        capacity = t.capacity;
        t.data = nullptr;
        t.capacity = -1;
        t.length = -1;
    }
    Array(Array &t)
    {
        for (int i = 0; i < 10; i++) {
            local[i] = t.local[i];
            
        }
        if(t.capacity) data = t.data;
        length = t.length;
        capacity = t.capacity;
        t.data = nullptr;
        t.capacity = -1;
        t.length = -1;
    }
    
    
    T local[10];
    T* data = local;

    int length = 0;
    int capacity = 0;
    T& operator[](int index){
        return data[index];
    }
    const T& operator[](int index) const {
        return data[index];
    }
    void Push(T& t){
        if (capacity == 0 && length < 10)
        {
            data[length++] = t;
            return;
        }
        
        if(capacity <= length)
        {
            Reserve(length * 2);
        }
        data[length++] = t;
    }
    void Push(T&& t){
        if (capacity == 0 && length < 10)
        {
            data[length++] = t;
            return;
        }
        
        if(capacity <= length)
        {
            Reserve(length * 2);
        }
        data[length++] = t;
    }
    void Push(const T& t){
        if (capacity == 0 && length < 10)
        {
            data[length++] = t;
            return;
        }
        
        if(capacity <= length)
        {
            Reserve(length * 2);
        }
        data[length++] = t;
    }
    void Insert(int index, const T& t){
        if(capacity <= length)
        {
            Reserve(length * 2);
        }
        for (int i = length-1; i >= index; i--) {
            data[i+1] = data[i];
        }
        data[index] = t;
        length++;
    }
    void Reserve(int size){
        if (size > 10)
        {
            T* newdata = (T*)malloc(size * sizeof(T));
            memcpy(newdata, data, length * sizeof(T));
            if(capacity) free(data);
            data = newdata;
            capacity = size;
        }
    }
    
    void Pop(){
        length--;
    }
};


template<class T>
struct Array<T, typename std::enable_if<std::is_reference<T>::value>::type>:
public Array<typename std::add_pointer<typename std::remove_reference<T>::type>::type>
{
    using TypePtr = typename std::add_pointer<typename std::remove_reference<T>::type>::type;
    void Push(const T& t){
        Array<TypePtr>::Push(&t);
    }
    T operator[](int index){
        return *Array<TypePtr>::operator[](index);
    }
    const T operator[](int index) const {
        return *Array<TypePtr>::operator[](index);
    }
    
};
