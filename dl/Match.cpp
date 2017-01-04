//
//  Match.cpp
//  Created by David on 12/17/16.
//

#include "Match.h"
#include "Annotate.h"
#include "Semantic.h"
#include "Apply.h"
#include "Error.h"

Variable* FindTypeInfo(Semantic &self, Type&dec){
    AssertAnnotated(&dec);
    Type *ptr = &RemoveSugar(dec);
    int i = 0;
    while (*ptr == Ast::TypePtr) {
        
        i++;
        ptr = &RemoveSugar(*cast<TypePtr>(ptr)->pointed);
    }
    
    TypeInfo info;
    info.indirection = i;
    info.type = cast<Struct>(ptr);
    //Do we already have a type info for this type?
    for(int i = 0; i < self.typeinfo.length; i++){
        TypeInfo &type = self.typeinfo[i];
        if(type.indirection == info.indirection && type.type == info.type){
            return type.def;
        }
    }
    //Register the new type info
    info.def = new Variable;
    info.def->ident = "typeinfo" + String((int)self.typeinfo.length);
    info.def->type = Find(self, "TypeInfo", dec.coord);
    self.typeinfo.Push(info);
    return info.def;
    return nullptr;
}


struct Match {
    int strength = 100;
    Variable* func = nullptr;
};

inline Array<Match> MatchesForName(Semantic& semantic, const string& name, Coord coord){
    Array<Match> matches;

    for(int i = (int)semantic.scopes.last().blocks.length-1; i >= 0; i--){
        Blck &scope = semantic.scopes.last().blocks[i];
        if(scope.functions.count(name))
        {
            auto& fns = scope.functions[name];
            for (auto func : fns) {
                assert(func);
                matches.Push({100, func});
            }
        }
        
        for(auto include : scope.includes){
            if(include->functions.count(name))
            {
                auto& fns = include->functions[name];
                for (auto func : fns) {
                    assert(func);
                    matches.Push({100, func});
                }
            }
        }
        
        if(matches.length){
            return matches;
        }
    }
    throw ParseError("Couldnt find any functions named '" + name + " fn()'", coord);
}

TypeList& Params(Variable& func) {
    if (func == Ast::Func || func == Ast::FuncIntrins) {
        return cast<Func>(func).params;
    }
    
    if(func == Ast::TypeFn){
        return cast<TypeFn>(func).params;
    }
    assert(false);
}
Func& Specialize(Semantic& semantic, Func& fn, const table<string, Type*>& known) {
    assert(known.size() > 0);
    assert(fn.unknown.size());
    
    for(auto spec : fn.specializations){
        bool equal = true;
        for(auto know : known){
            equal &= TypeCheck(*know.second, *spec->unknown[know.first], false);
        }
        if(equal)
            return *spec;
    }
    Scope scope;
    scope.Push(semantic.scopes[0].blocks[0]);
    semantic.scopes.Push(scope);
    Func& def = *Copy(&fn);
    def.ident = fn.ident + std::to_string(fn.specializations.size());
    def.generic = &fn;
    
    semantic.scopes.last().Push(*def.body);
    
    assert(known.size() == def.unknown.size());
    for (auto iter : known) {
        auto at = def.unknown.find(iter.first);
        assert(at != def.unknown.end());
        (*at).second->type = iter.second;
        
        Type* type = &RemoveSugar(*iter.second);
        if(*type != Ast::Variable && *type != Ast::TypeFns) {
            auto t = new TypeType;
            t->type = type;
            type = t;
        }
        assert(iter.first != "");
        auto any = new TypeAny;
        any->ident = iter.first;
        any->type = iter.second;
        Redeclare(semantic, any->ident, *any);
    }
    
    auto retParams = AnnotateParam(semantic, def.params, false, true);
    auto retResults = AnnotateParam(semantic, def.results, false, true);
    semantic.scopes.last().Pop();
    
    //Both of these can only return None since they should be fully annotated and all Any decls should be completely known
    assert(retParams == AnnotateEvent::None);
    assert(retResults == AnnotateEvent::None);
    
    def.results.temporary = def.results.ref ? false : true;
    assert(def.body);
    semantic.scopes.last().Push(*def.body);
    for(int i = 0; i < def.params.list.length; i++){
        TypeName &arg = def.params.list[i];
        auto var = new Variable;
        var->ident = arg.ident;
        var->type = arg.dec;
        var->coord = arg.dec->coord;
        Redeclare(semantic, arg.ident, *var);
        var->annotated = AnnotatedState::Annotated;
    }
    semantic.scopes.last().Pop();
    
    semantic.Visit(*def.body);
    
    if(def.results.list.length && def.body && !def.body->didReturn){
        throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
    }
    def.type = def.results.type;
    assert(def.type);
    semantic.scopes.Pop();

    fn.specializations.push_back(&def);
    return def;
    assert(false);
}

Variable* FindExactMatch(const string& name, Semantic& semantic, ExprList& args)
{
    auto matches = MatchesForName(semantic, name, args.coord);
    int foundMatch = 0;
    struct Matched {
        Variable* fn;
        Known known;
    };
    vector<Matched> found;
    
    for(int i = 0; i < matches.length; i++){
        Match &match = matches[i];
        Known known;
        
        TypeList& params = Params(*match.func);
        if(params.list.length != args.list.length){
            continue;
        }
        bool matched = true;
        for(int i = 0; i < params.list.length; i++){
            Type& paramAt = RemoveSugar(*params.list[i].dec);
            Type& argAt = RemoveSugar(*args.list[i].type);
            matched &= Apply(argAt, paramAt, known);
        }
        if (matched) {
            foundMatch += matched;
            found.push_back({match.func, known});
            assert(known.resolved.size() == cast<Func>(match.func)->unknown.size());
        }
    }
    
    if(foundMatch == 0){
        string error = "Failed to find match for function \n" + name + " fn" + String(args) + "\n--------Possible Matches-------\n";
        for(int i = 0; i < matches.length; i++){
            Match &match = matches[i];
            TypeList& params = Params(*match.func);
            error += match.func->ident +" fn" + String(params) + "\n";
        }
        Error(error, args.coord);
    }
    else if(foundMatch > 1){
        //        Println("Matched multiple");
        //        for (auto f: found) {
        //            ParseError("Matched: ", f->coord).Print();
        //        }
        //        Error("sFasf", args.coord);
        
    }
    
    for (auto& selected : found[0].known.selected) {
        selected.fns.type = &selected.selected;
    }
    
    Func& fn = *cast<Func>(found[0].fn);
    if (fn.unknown.size() == 0){
        assert(found[0].known.resolved.size() == 0);
        return &fn;
    }
    
    return &Specialize(semantic, fn, found[0].known.resolved);
}

Variable* FindExactMatch(const string& name, Semantic& semantic, TypeList& args)
{
    auto matches = MatchesForName(semantic, name, args.coord);
    int foundMatch = 0;
    struct Matched {
        Variable* fn;
        Known known;
    };
    vector<Matched> found;
    
    for(int i = 0; i < matches.length; i++){
        Match &match = matches[i];
        Known known;
        
        TypeList& params = Params(*match.func);
        if(params.list.length != args.list.length){
            continue;
        }
        bool matched = true;
        for(int i = 0; i < params.list.length; i++){
            Type& paramAt = RemoveSugar(*params.list[i].dec);
            Type& argAt = RemoveSugar(*args.list[i].dec);
            matched &= Apply(argAt, paramAt, known);
        }
        if (matched) {
            foundMatch += matched;
            found.push_back({match.func, known.resolved});
            assert(known.resolved.size() == cast<Func>(match.func)->unknown.size());
        }
    }
    
    if(foundMatch == 0){
        Print("Failed to find " + name);
    }
    else if(foundMatch > 1){
        //        Println("Matched multiple");
        //        for (auto f: found) {
        //            ParseError("Matched: ", f->coord).Print();
        //        }
        //        Error("sFasf", args.coord);
        
    }
    for (auto& selected : found[0].known.selected) {
        selected.fns.type = &selected.selected;
    }
    Func& fn = *cast<Func>(found[0].fn);
    if (fn.unknown.size() == 0){
        assert(found[0].known.resolved.size() == 0);
        return &fn;
    }
    return &Specialize(semantic, fn, found[0].known.resolved);
}

Variable* Find(Semantic &self, const string& name, Coord coord){
    for(int i = (int)self.scopes.last().blocks.length-1; i >= 0; i--)
    {
        Blck &scope = self.scopes.last().blocks[i];
        if(scope.variables.count(name))
        {
            assert(scope.variables[name]);
            return scope.variables[name];
        }
        for (auto include : scope.includes)
        {
            if(include->variables.count(name))
            {
                assert(include->variables[name]);
                return include->variables[name];
            }
        }
    }
    auto matches = MatchesForName(self, name, coord);
    if(matches.length){
        auto fns = new TypeFns;
        fns->type = fns;
        fns->annotated = AnnotatedState::Annotated;
        for(int i = 0; i < matches.length; i++){
            Match &match = matches[i];
            fns->functions.push_back(match.func);
           // self.Visit(*match.func);
        }
        return fns;
    }
    throw ParseError("Use of undeclared variable '" + name, coord);
    return nullptr;
}

Expr* FindVariable(Semantic &self, const string& name, Coord coord){
    for(int i = (int)self.scopes.last().blocks.length-1; i >= 0; i--)
    {
        Blck &scope = self.scopes.last().blocks[i];
        if(scope.variables.count(name))
        {
            assert(scope.variables[name]);
            return scope.variables[name];
        }
        for (auto& use : scope.usings) {
            if(RemoveSugar(*use.operand->type) == Ast::Struct)
            {
                Struct& structure = cast<Struct>(RemoveSugar(*use.operand->type));
                bool contain = false;
                for (auto &field : structure.fields) {
                    if(field->ident == name){
                        contain = true;
                    }
                }
                if(contain)
                {
                    Access& access = Create<Access>(coord);
                    access.operand = use.operand;
                    access.field = name;
                    self.Visit(access);
                    return &access;
                }
            }
        }
        for (auto include : scope.includes)
        {
            if(include->variables.count(name))
            {
                assert(include->variables[name]);
                return include->variables[name];
            }
        }
    }
    auto matches = MatchesForName(self, name, coord);
    if(matches.length){
        auto fns = new TypeFns;
        fns->type = fns;
        fns->annotated = AnnotatedState::Annotated;
        for(int i = 0; i < matches.length; i++){
            Match &match = matches[i];
            fns->functions.push_back(match.func);
            //self.Visit(*match.func);
        }
        return fns;
    }
    throw ParseError("Use of undeclared variable '" + name, coord);
    return nullptr;
}
