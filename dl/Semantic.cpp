//
//  Semantic.cpp
//  Created by David on 8/20/16.
//

#include "Semantic.h"

Variable* FindTypeInfo(Semantic &self, Dec&dec){
    IsAnnotated(&dec);
    Dec *ptr = &RemoveSugar(dec);
    int i = 0;
    while (auto next = ptr->IsPtr()) {
        i++;
        ptr = &RemoveSugar(*next->pointed);
    }
    
    TypeInfo info;
    info.indirection = i;
    info.type = cast<StructDef>(ptr);
    //Do we already have a type info for this type?
    for(auto& type : self.typeinfo){
        if(type.indirection == info.indirection && type.type == info.type){
            return type.def;
        }
    }
    //Register the new type info
    info.def = new Variable;
    info.def->ident = "typeinfo" + String((int)self.typeinfo.size());
    info.def->type = Find(self, "TypeInfo");
    self.typeinfo.push_back(info);
    return info.def;
}
bool DeclareConstraints(Dec&decl, Dec&c, Blck&block){
    
    Dec& constraint = RemoveSugar(c);
    assert(typeid(constraint) != typeid(DecAny));
    
    if(typeid(decl) == typeid(DecAny))
    {
        DecAny &type = (DecAny&)decl;
        if(type.type) return true;
        
        type.type = &constraint;
        
        block.variables[type.ident] = (&type);
        //Print("Declared " + type.ident + " as " +String(constraint) + "\n");
//        if(String(constraint) =="Transform" && type.name == "T")
//            Assert(false, decl);
//        
        return true;
    }
    
    assert(typeid(decl) == typeid(constraint));
    
    if(typeid(decl) == typeid(DecList))
    {
        return true;
    }
    if(typeid(decl) == typeid(DecPtr))
    {
        DecPtr &type = (DecPtr&)decl;
        return DeclareConstraints(*type.pointed, constraint, block);
    }
    
    if(typeid(decl) == typeid(DecVar))
    {
        DecVar &type = (DecVar&)decl;
        return DeclareConstraints(*type.type, constraint, block);
    }
    
    assert(false);
    return false;
}

bool DeclareConstraints(const vector<Dec*>& decl, const vector<Dec*>& constraints, Blck&block){
    if(decl.size() != constraints.size()) {
        return false;
    }
    
    for (int i = 0; i < decl.size(); i++) {
        if(!DeclareConstraints(*decl[i], *constraints[i], block)){
            return false;
        }
    }
    return true;
}



bool AnnotateConstraint(Dec&dd, Dec&cc, Blck& block){
    
    Dec& decl = RemoveSugarConstraint(dd);
    Dec& constraint = RemoveSugarConstraint(cc);

    if(typeid(decl) == typeid(DecAny))
    {
        DecAny &type = (DecAny&)decl;
        if(type.type) return true;
        
        type.type = &constraint;
        block.variables[type.ident] = (&type);
        return true;
    }
    
    if(typeid(decl) != typeid(constraint)){
        return true;
    }
    
    
//    if(typeid(decl) == typeid(DeclList))
//    {
//        DeclList &list = (DeclList&)decl;
//        for(auto decl : list.list){
//            if(!Annotate(*decl, scopes))
//                return false;
//        }
//        return true;
//    }
    if(typeid(decl) == typeid(DecPtr))
    {
        DecPtr &type = (DecPtr&)decl;
        DecPtr &constr = (DecPtr&)constraint;
        return AnnotateConstraint(*type.pointed, *constr.pointed, block);
    }

    if(typeid(decl) == typeid(DecVar))
    {
//        if(decl.type) return true;
//        TypeDecl &type = (TypeDecl&)decl;
//        TypeDecl &typeConstraint = (TypeDecl&)constraint;
//        for (int i = 0; i < type.constraints->list.size(); i++) {
//            auto r = type.constraints->list[i];
//            auto c = typeConstraint.constraints->list[i];
//            Annotate(*r, *c, block);
//        }
//        assert(Annotate(type, scopes));
//        assert(type.type);
        return true;
    }
    if(typeid(decl) == typeid(DecGen))
    {
        DecGen &type = (DecGen&)decl;
        DecGen &typeConstraint = (DecGen&)constraint;
        for (int i = 0; i < type.constraints.size(); i++) {
            type.type = typeConstraint.type;
            auto r = type.constraints[i];
            auto c = typeConstraint.constraints[i];
            AnnotateConstraint(*r, *c, block);
        }
       // assert(Annotate(type, scopes));
       // assert(type.type);
        return true;
    }
    if(typeid(decl) == typeid(DecType))
    {
        DecType &type = (DecType&)decl;
        DecType &typeConstraint = (DecType&)constraint;
        return AnnotateConstraint(*type.type, *typeConstraint.type, block);
    }
    assert(false);
    return false;
}

AnnotateEvent AnnotateParam(Semantic&self, Dec&decl, bool declareAny){
    if(typeid(decl) == typeid(DecVar))
    {
        DecVar &type = (DecVar&)decl;
//        if(type.type) {
//            return AnnotateEvent::None;
//        }
        
        for(int i = int(self.scopes.size()-1); i >= 0; i--){
            Blck &scope = *self.scopes[i];
            if(scope.variables.count(type.ident)){
                type.type = cast<Dec>(scope.variables[type.ident]);
                assert(type.type);
                AnnotateParam(self, *type.type);
                return AnnotateEvent::None;
            }
        }
        throw ParseError("Unknown type '" + type.ident + "'", decl.coord);
        return AnnotateEvent::Failed;
    }
    if(typeid(decl) == typeid(DecGen))
    {
        DecGen &type = (DecGen&)decl;
        AnnotateParam(self, *type.typeGeneric);
        if(type.constraints.size()){
            DecList l;
            l.list.resize(type.constraints.size(), DecName("", nullptr));
            for(int i = 0; i < type.constraints.size(); i++){
                l.list[i].dec = type.constraints[i];
            }
            auto annotate = int(AnnotateParam(self, *new DecList(l)));
            StructDef*s = &cast<StructDef>(RemoveSugar(*type.typeGeneric));
            self.IsStructDef(*s);
            type.generic = s;
            type.type = nullptr;

            if(annotate & int(AnnotateEvent::AnyDecl))
            {
                return AnnotateEvent::AnyDecl;
            }


            assert(type.generic);
            for(auto spec : s->specializations){
                DecList ll;
                ll.list.resize(spec->constraints.size(), DecName("", nullptr));
                for(int i = 0; i < spec->constraints.size(); i++){
                    ll.list[i].dec = spec->constraints[i];
                }
                
                if (TypeCheck(*new DecList(ll), *new DecList(l))) {
                    type.type = spec;
                    assert(type.type);
                    return AnnotateEvent::None;
                }
            }
            StructDef *def = s->Copy();
            def->generic = s;
            DeclareConstraints(def->constraints, type.constraints, def->block);
            s->specializations.push_back(def);
            def->specialization = true;
            def->ident = s->ident + std::to_string(s->specializations.size());
            self.IsStructDef(*def);
            
            type.type = def;
        }
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(DecAny))
    {
        DecAny &type = cast<DecAny>(decl);
        if(!type.type && declareAny){
            self.scopes.back()->variables[type.ident] = (&type);

            type.annotated = AnnotatedState::Annotated;
            return AnnotateEvent::AnyDecl;
        }
        return AnnotateEvent::None;
    }

    if(typeid(decl) == typeid(DecPtr))
    {
        DecPtr &type = cast<DecPtr>(decl);
        return AnnotateParam(self, *type.pointed);
    }
    if(typeid(decl) == typeid(DecType))
    {
        DecType &type = cast<DecType>(decl);
        return AnnotateParam(self, *type.type);
    }
    
    if(typeid(decl) == typeid(DecList))
    {
        DecList &list = cast<DecList>(decl);
        auto ret = AnnotateEvent::None;
        for(auto decl : list.list){
            ret = AnnotateEvent(int(ret) | int(AnnotateParam(self, *decl.dec)));
        }
        if(ret != AnnotateEvent::None)
            return ret;
        
        if(list.list.size() == 0){
            return ret;
        }
        if(list.list.size() == 1){
            list.type = list.list[0].dec;
            assert(list.type);
            return ret;
        }

        for(auto def : self.listDefs){
            if(TypeCheck(*def->list, list)){
                list.type = def;
            }
        }
        if(!list.type){
            auto def = new ListDef;
            def->list = &list;
            self.listDefs.push_back(def);
            self.defs.push_back(def);
            list.type = def;
        }
        return ret;
    }
    if(typeid(decl) == typeid(StructDef))
    {
        self.IsStructDef(cast<StructDef>(decl));
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(IntrinsicStructDef))
    {
        return AnnotateEvent::None;
    }

//    if(typeid(decl) == typeid(FuncDecl))
//    {
//        FuncDecl &type = (FuncDecl&)decl;
//        AnnotateEvent status = AnnotateEvent::None;
//        for(auto var : type.args->list){
//            status = AnnotateEvent(int(status) | int(AnnotateParam(*var->type, scopes)));
//        }
//        if(type.ret)
//            status = AnnotateEvent(int(status) | int(AnnotateParam(*type.ret, scopes)));
//        return status;
//    }
    assert(false);
    return AnnotateEvent::Failed;
}

void Declare(Semantic &self, const string& name, Variable& variable)
{
    assert(!IsDeclared(variable));
    variable.annotated = AnnotatedState::Declared;
    if(typeid(variable) == typeid(FuncDef) || typeid(variable) == typeid(IntrinsicFuncDef)){
        self.scopes.back()->functions[name].push_back((FuncDef*)&variable);
    }
    else{
        if(self.scopes.back()->variables[name]){
            throw ParseError("Variable '" + name + "' was already declared" , variable.coord);
        }
        self.scopes.back()->variables[name] =(&variable);
    }
}

 Variable* Find(Semantic &self, const string& name){
    for(int i = (int)self.scopes.size()-1; i >= 0; i--){
        Blck &scope = *self.scopes[i];
        if(scope.variables.count(name)){
            assert(scope.variables[name]);
            return scope.variables[name];
        }
    }
    throw ParseError("Use of undeclared variable '" + name);
    return nullptr;
}
