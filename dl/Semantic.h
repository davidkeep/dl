

//
//  Semantic.h
//  Created by David on 8/20/16.
//

#pragma once
#include "Ast.h"
#include "Def.h"
#include "Printing.h"
#include "Intrinsics.h"

enum TypeCheck {
    Failed = 0,     //Types are fully equal
    
    RequiresAny,    //This is a failure in many cases
    Conversion,     //Required a conversion to pass
    Passed,         //Fully failed type test
};

enum class AnnotateEvent {
    None            = 0,
    Failed          = 1 << 1,
    AnyDecl         = 1 << 2,
};

inline Dec& RemoveAnyVar(Dec& dec){
    if(auto any = dec.IsAny()){
        return any->type ? RemoveAnyVar(*any->type) : dec;
    }
    if(auto var = dec.IsVar()){
        return RemoveAnyVar(*var->type);
    }
    if(auto list = dec.IsList()){
        return list->list.size() == 1 ? RemoveAnyVar(*list->list[0].dec) : dec;
    }
    return dec;
}

inline Dec& RemoveSugarConstraint(Dec& dec){
    if(auto any = dec.IsAny()){
        return any->type ? RemoveSugarConstraint(*any->type) : dec;
    }
    if(auto var = dec.IsVar()){
        return  var->type ? RemoveSugarConstraint(*var->type) : dec;
    }
    if(auto list = dec.IsList()){
        return list->list.size() == 1 ? RemoveSugarConstraint(*list->list[0].dec) : dec;
    }
    return dec;
}

inline Dec& RemoveSugar(Dec& dec){
    if(auto any = dec.IsAny()){
        return any->type ? RemoveSugar(*any->type) : dec;
    }
    if(auto gen = dec.IsGen()){
        return gen->type ? RemoveSugar(*gen->type) : dec;
    }
    if(auto var = dec.IsVar()){
        return RemoveSugar(*var->type);
    }
    if(auto list = dec.IsList()){
        return list->list.size() == 1 ? RemoveSugar(*list->list[0].dec) : dec;
    }
    return dec;
}

static bool TypeCheck(Dec&ll, Dec&rr, bool convert = true){
    
    Dec &l = RemoveAnyVar(ll);
    Dec &r = RemoveAnyVar(rr);

    if(typeid(l) == typeid(DecAny))
    {
        return true;
    }
   
    
    if(typeid(l) != typeid(r))
    {
        if(typeid(l) == typeid(DecGen))
        {
            if(!cast<DecGen>(l).type) return false;
            return TypeCheck(RemoveSugar(l), r, convert);
        }
        if(typeid(r) == typeid(DecGen))
        {
            if(!cast<DecGen>(r).type) return false;
            return TypeCheck(l, RemoveSugar(r), convert);
        }
        return false;
    }
    if(typeid(l) == typeid(DecGen))
    {
        DecGen &ll = (DecGen&)l;
        DecGen &rr = (DecGen&)r;
        if(ll.generic != rr.generic){
            return false;
        }
        if(ll.constraints.size() != rr.constraints.size()){
            return false;
        }
        for(int i = 0; i < ll.constraints.size(); i++){
            if(!TypeCheck(*ll.constraints[i], *rr.constraints[i], false)){
                return false;
            }
        }
        
        return true;
    }
    if(typeid(l) == typeid(DecPtr))
    {
        DecPtr &ll = (DecPtr&)l;
        DecPtr &rr = (DecPtr&)r;
        return TypeCheck(*ll.pointed, *rr.pointed, convert);
    }
    if(typeid(l) == typeid(StructDef))
    {
        StructDef &ll = (StructDef&)l;
        StructDef &rr = (StructDef&)r;
        return &ll == &rr;
    }
    if(typeid(l) == typeid(IntrinsicStructDef))
    {
        IntrinsicStructDef &ll = (IntrinsicStructDef&)l;
        IntrinsicStructDef &rr = (IntrinsicStructDef&)r;
        if(&rr == &Types::Num){
            //@TODO actually check that this conversion is allowed
            return true;
        }
        
        if(convert){
            //An intger with less bits can be coerced into an integer with more bits
            if(&ll <= &Types::Int8 && &ll >= &Types::Int){
                if(&rr >= &ll && &rr <= &Types::Int8){
                    return true;
                }
            }
            if(&ll <= &Types::Uint8 && &ll >= &Types::Uint){
                if(&rr >= &ll && &rr <= &Types::Uint8){
                    return true;
                }
            }
        }
        return &ll == &rr;
    }
    if(typeid(l) == typeid(DecList))
    {
        DecList &ll = (DecList&)l;
        DecList &rr = (DecList&)r;
        if(ll.list.size() != rr.list.size())
            return false;
        
        for(int i = 0; i < ll.list.size(); i++){
            if(!TypeCheck(*ll.list[i].dec, *rr.list[i].dec, convert)){
                return false;
            }
        }
        return true;
    }
    if(typeid(l) == typeid(DecType))
    {
        DecType &ll = (DecType&)l;
        DecType &rr = (DecType&)r;
        
        return TypeCheck(*ll.type, *rr.type, convert);
    }
    assert(false);
    return false;
}

struct Project;
static inline void IsAnnotated(Dec* type){
    if(!type) {
        assert(false);
        return;
    }
    if(typeid(*type) == typeid(Variable)){
        return IsAnnotated(((Variable*)type)->type);
    }
    if(typeid(*type) == typeid(DecVar)){
        return IsAnnotated(((DecVar*)type)->type);
    }
    if(typeid(*type) == typeid(DecPtr)){
        return IsAnnotated(((DecPtr*)type)->pointed);
    }
    if(typeid(*type) == typeid(DecAny))
    {
        return IsAnnotated(((DecAny*)type)->type);
    }
    if(typeid(*type) == typeid(DecType))
    {
        return IsAnnotated(((DecType*)type)->type);
    }
    if(typeid(*type) == typeid(DecGen))
    {
        return IsAnnotated(((DecGen*)type)->type);
    }
    if(typeid(*type) == typeid(DecFn))
    {
        IsAnnotated(&((DecFn*)type)->results);
        IsAnnotated(&((DecFn*)type)->params);
        return;
    }
    if(typeid(*type) == typeid(DecList))
    {
        if(((DecList*)type)->list.size()){
            assert(((DecList*)type)->type);
            return;
        }
        return;
    }
    assert(
           (typeid(*type) == typeid(StructDef)) ||
           (typeid(*type) == typeid(IntrinsicStructDef)) ||
           false
           );
    
}
//
static inline bool IsAnnotated(Expr* expr){
    if(typeid(ExprList) == typeid(*expr)){
        auto list = (ExprList*)expr;
        for(auto exp : list->list)
        {
            IsAnnotated(exp);
        }
    }
    else
    {
        IsAnnotated(expr->type);
    }
    return true;
}
//
//static inline Decl* StripTypes(Decl* type){
//    assert(type);
//    if(typeid(*type) == typeid(PtrDecl)){
//        return StripTypes(type->type);
//    }
//    if(typeid(*type) == typeid(AnyDecl))
//    {
//        return StripTypes(type->type);
//    }
//    if(typeid(*type) == typeid(TypeDecl))
//    {
//        return StripTypes(type->type);
//    }
//    return type;
//}
//static inline Decl* StripBasic(Decl* type){
//    if(typeid(*type) == typeid(AnyDecl)){
//        return StripBasic(type->type);
//    }
//    if(typeid(*type) == typeid(TypeDecl))
//    {
//        return StripBasic(type->type);
//    }
//    return type;
//}
static bool TypeCheck(DecList&l, ExprList&r){
    if(l.list.size() != r.list.size()){
        return false;
    }
    
    for(int i = 0 ; i < l.list.size(); i++){
        if(!TypeCheck(*l.list[i].dec, *r.list[i]->type)){
            return false;
        }
    }
    return true;
}

class Semantic;
void Declare(Semantic &self, const string& name, Variable& variable);
inline void Declare(Semantic &self, Variable& variable){
    Declare(self, variable.ident, variable);
}

AnnotateEvent AnnotateParam(Semantic &self, Dec&decl, bool declareAny = true);
bool AnnotateConstraint(Dec&dec, Dec&constraint, Blck& block);


Variable* Find(Semantic &self, const string& name,  Coord coord);


Variable* FindTypeInfo(Semantic &self, Dec&dec);


struct TypeInfo {
    int indirection = 0;
    StructDef *type = nullptr;
    Variable *def = nullptr;
};

inline vector<Variable*> MatchesForName(const vector<Blck*>& scopes, const string& name){
    for(int i = (int)scopes.size()-1; i >= 0; i--){
        Blck &scope = *scopes[i];
        vector<Variable*> defs;
        if(scope.functions.count(name))
        {
            auto& fns = scope.functions[name];
            defs.insert(defs.end(), fns.begin(), fns.end());
        }
        
        for(auto include : scope.includes){
            if(include->functions.count(name))
            {
                auto& fns = include->functions[name];
                defs.insert(defs.end(), fns.begin(), fns.end());
            }
        }

        if(defs.size()){
            return defs;
        }
    }
    throw ParseError("Couldnt find any functions named '" + name + " fn()'");
}
class Semantic : public Visitor
{
public:
    vector<ListDef*> listDefs;
    vector<Variable*> varDefs;
    vector<Dec*> defs;
    vector<TypeInfo> typeinfo;
    vector<FuncDef*> funcDefs;

    vector<Blck*> scopes;
    Variable* FindExactMatch(const string& name, const vector<Blck*>& scopes, ExprList&args){
      
        auto decls = MatchesForName(scopes, name);
        for(auto func : decls)
        {
            auto fn = dynamic_cast<FuncDef*>(func);
            if(!fn) {
                auto decfn = func->IsFn();
                if(TypeCheck(decfn->params, args)){
                    return func;
                }
                continue;
            }
            
            Visit(*fn);
            if(fn->generic)
            {
                auto any = TypeCheck(fn->params, args);
                if(any){
                    FuncDef& def = *Copy(fn);
                    def.ident = fn->ident + std::to_string(fn->specializations.size());
                    
                    def.generic = false;
                    
                    Semantic::scopes.push_back(def.body);
                    for(int i = 0; i < def.params.list.size(); i++){
                        auto &arg = def.params.list[i];
                        auto &input = args.list[i];
                        AnnotateConstraint(*arg.dec, *input->type, *def.body);
                        AnnotateParam(*this, *arg.dec);
                    }
                    Semantic::scopes.pop_back();
                    this->scopes.push_back(def.body);
                    AnnotateParam(*this, def.results);
                    this->scopes.pop_back();
                    def.results.temporary = def.results.ref ? false : true;

                    if(def.body){
                        Semantic::scopes.push_back(def.body);
                        for(auto arg : def.params.list){
                            auto var = new Variable;
                            var->ident = arg.ident;
                            var->type = arg.dec;
                            var->coord = arg.dec->coord;
                            Declare(*this, arg.ident, *var);
                            var->annotated = AnnotatedState::Annotated;

                        }
                        Semantic::scopes.pop_back();

                        def.body->Visit(*this);
                    }
                    if(def.results.list.size() && def.body && !def.body->didReturn){
                        throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
                    }
                    def.type = def.results.type;
                    assert(def.type);

                    fn->specializations.push_back(&def);
                    return &def;
                }
            }
            else if(TypeCheck(fn->params, args)){
                return fn;
            }
        }
        
        Println("Couldn't find function:\nfn " + name + String(args));
        Println("Possible matches:");
        for(int i = (int)scopes.size()-1; i >= 0; i--){
            Blck &scope = *scopes[i];
            if(scope.functions.count(name)){
                for(auto fn : scope.functions[name]){
                    Println("fn " + name + String(*fn));
                }
            }
        }
    
        throw ParseError("", args.coord);
        return nullptr;
    }
    bool firstPass = true;
    
    Semantic(Project& project);
    
    void IsBlck(Blck &self) override;
    void IsExprList(ExprList &self) override;
    void IsCastExpr(CastExpr &cast) override;

    void IsBinaryOp(BinaryOp &op) override;
    void IsUnaryOp(UnaryOp &op) override;
    void IsFieldAccess(FieldAccess &field) override;
    void IsCall(Call &call) override;

    void IsStructDef(StructDef &def) override;
    void IsEnumDef(EnumDef &def) override;
    void IsFuncDef(FuncDef &def) override;
    void IsIntrinsicFuncDef(IntrinsicFuncDef &def) override;
    void IsIntrinsicStructDef(IntrinsicStructDef &def) override;

    void IsVariable(Variable &def) override;
    void IsVar(Var &var) override;

    void IsConstNumber(ConstNumber &num) override;
    void IsConstString(ConstString &str) override;

    void IsReturn(Return &ret) override;
    void IsIf(If &statement) override;
    void IsFor(For &loop) override;
};
