//
//  Ast.cpp
//  Created by David on 8/18/16.
//

#include "Ast.h"
#include "Def.h"

Blck* Blck::Copy() const {
    Blck& self = *new Blck;
    self.didReturn = didReturn;
    self.childrenAppended = ::Copy(childrenAppended);
    self.children = ::Copy(children);
    self.includes = ::Copy(includes);
    
    self.variables = variables;
    for(auto& element : self.variables){
        element.second = ::Copy(element.second);
    }
    self.functions = functions;
    for(auto& element : self.functions){
        element.second = ::Copy(element.second);
    }
    return &self;
}
