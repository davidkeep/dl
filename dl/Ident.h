//
//  Ident.h
//  Created by David on 8/21/16.
//

#pragma once
#include "Node.h"
struct IdentMapper;
struct Ident{
    bool operator==(const Ident&lhs)const{
        return index == lhs.index;
    }
    bool operator!=(const Ident&lhs)const{
        return !operator==(lhs);
    }
    operator bool()const{
        return index;
    }
    const string& Name() const { return name; }
private:
    friend IdentMapper;
    int index;
    Ident(int index = 0):
    index(index){
    }
    string name;
};

struct IdentMapper {
    IdentMapper(int length = 1000){
        toIdent.reserve(length);
        toIdent.emplace_back();
    }
    
    const string& Name(Ident id){
        assert(id.index);
        return toIdent[id.index];
    }
    Ident IdentForName(const string&str){
        auto &value = fromIdent[str];
        
        if(value == 0){
            toIdent.push_back(str);
            value = (int)toIdent.size()-1;
        }
        Ident r(value);
        r.name = str;
        return r;
    }
private:
    vector<string> toIdent;
    table<string, int> fromIdent;
};
