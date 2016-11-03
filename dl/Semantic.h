

//
//  Semantic.h
//  Created by David on 8/20/16.
//

#pragma once
#include "Ast.h"
#include "Op.h"
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

static bool TypeCheck(Dec&ll, Dec&rr){
    
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
            if(!cast<DecGen>(l).type) return nullptr;
            return TypeCheck(RemoveSugar(l), r);
        }
        if(typeid(r) == typeid(DecGen))
        {
            if(!cast<DecGen>(r).type) return nullptr;
            return TypeCheck(l, RemoveSugar(r));
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
            if(!TypeCheck(*ll.constraints[i], *rr.constraints[i])){
                return false;
            }
        }
        
        return true;
    }
    if(typeid(l) == typeid(DecPtr))
    {
        DecPtr &ll = (DecPtr&)l;
        DecPtr &rr = (DecPtr&)r;
        return TypeCheck(*ll.pointed, *rr.pointed);
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
        if(&rr == Types::Num){
            //@TODO actually check that this conversion is allowed
            return true;
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
            if(!TypeCheck(*ll.list[i].dec, *rr.list[i].dec)){
                return false;
            }
        }
        return true;
    }
    if(typeid(l) == typeid(DecType))
    {
        DecType &ll = (DecType&)l;
        DecType &rr = (DecType&)r;
        
        return TypeCheck(*ll.type, *rr.type);
    }
    assert(false);
    return false;
}


static inline Dec* IsAnnotated(Dec* type){
    if(!type) return nullptr;
    
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
    if(typeid(*type) == typeid(DecList))
    {
        if(((DecList*)type)->list.size()){
            assert(((DecList*)type)->type);
            return ((DecList*)type)->type;
        }
        return type;
    }
    assert(
           (typeid(*type) == typeid(StructDef)) ||
           (typeid(*type) == typeid(IntrinsicStructDef)) ||
           false
           );
    
    return type;
}
//
static inline bool IsAnnotated(Expr* expr){
    if(typeid(ExprList) == typeid(*expr)){
        auto list = (ExprList*)expr;
        for(auto exp : list->list)
            if(!IsAnnotated(exp))
                return false;
    }
    else
    {
        if(!IsAnnotated(expr->type))
            return false;
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


Variable* Find(Semantic &self, const string& name);


Variable* FindTypeInfo(Semantic &self, Dec&dec);


struct TypeInfo {
    int indirection = 0;
    StructDef *type = nullptr;
    Variable *def = nullptr;
};

class Semantic : public Visitor
{
public:
    vector<ListDef*> listDefs;
    vector<Variable*> varDefs;

    vector<Dec*> defs;

    vector<TypeInfo> typeinfo;
    
    vector<FuncDef*> funcDefs;

    vector<Blck*> scopes;
    FuncDef* FindExactMatch(const string& name, const vector<Blck*>& scopes, ExprList&args){        
        for(int i = (int)scopes.size()-1; i >= 0; i--){
            Blck &scope = *scopes[i];
            if(scope.functions.count(name))
            {
                auto& decls = scope.functions[name];
                for(auto decl : decls){
                    if(auto fn = dynamic_cast<FuncDef*>(decl->type)){
                        Visit(*fn);
                        if(fn->generic)
                        {
                            auto any = TypeCheck(*fn->args, args);
                            if(any){
                                FuncDef& def = *Copy(fn);
                                def.ident = fn->ident + std::to_string(fn->specializations.size());
                                
                                def.generic = false;
                                
                                if(def.args){
                                    Semantic::scopes.push_back(def.body);
                                    for(int i = 0; i < def.args->list.size(); i++){
                                        auto &arg = def.args->list[i];
                                        auto &input = args.list[i];
                                        AnnotateConstraint(*arg.dec, *input->type, *def.body);
                                        AnnotateParam(*this, *arg.dec);
                                    }
                                    Semantic::scopes.pop_back();
                                }
                                if(def.ret){
                                    this->scopes.push_back(def.body);
                                    AnnotateParam(*this, *def.ret);
                                    this->scopes.pop_back();
                                    def.ret->temporary = def.ret->ref ? false : true;
                                }
                                if(def.body){
                                    Semantic::scopes.push_back(def.body);
                                    for(auto arg : def.args->list){
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
                                if(def.ret->list.size() && def.body && !def.body->didReturn){
                                    throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
                                }
                                fn->specializations.push_back(&def);
                                return &def;
                            }
                        }
                        else if(TypeCheck(*fn->args, args)){
                            return fn;
                        }
                    }
                }

            }
        }
        
        Println("Couldn't find function:\nfn " + name + String(args));
        Println("Possible matches:");
        for(int i = (int)scopes.size()-1; i >= 0; i--){
            Blck &scope = *scopes[i];
            if(scope.functions.count(name)){
                for(auto fn : scope.functions[name]){
                    Println("fn " + name + String(*fn->args) + String(*fn->ret));
                }
            }
        }
    
        throw ParseError("", args.coord);
        return nullptr;
    }
    
    void IsUnhandled(Node &self) override{
    }

    bool firstPass = true;
    void IsBlck(Blck &self) override{
        if(firstPass){
            scopes.push_back(&self);

            for(auto child : self.childrenAppended){
                if(auto def = dynamic_cast<Variable*>(child)){
                    def->top = true;
                    Declare(*this, *def);
                }
                if(auto def = dynamic_cast<Blck*>(child)){
                    Visit(*def);
                }
            }
            for(auto child : self.children){
                if(auto def = dynamic_cast<Variable*>(child)){
                    def->top = true;
                    Declare(*this, *def);
                }
                if(auto def = dynamic_cast<Blck*>(child)){
                    Visit(*def);
                }
            }
            scopes.pop_back();

            if(scopes.size() == 0){
                firstPass = false;
            }
            else{
                return;
            }
        }
        
        scopes.push_back(&self);

        VisitChildren(self);
        scopes.pop_back();
        if(scopes.size())
            scopes.back()->didReturn |= self.didReturn;
    }
    void IsExprList(ExprList &self) override{
        VisitChildren(self);
        vector<DecName> types;
        types.reserve(self.list.size());
        for(int i = 0; i < self.list.size(); i++){
            types.push_back({"", self.list[i]->type});
        }
        auto type = new DecList;
        type->list = types;
        self.type = type;
    }

    void IsCast(Cast &cast)override {
        cast.expr->Visit(*this);
        AnnotateParam(*this, *cast.type);
    }
    void IsBinaryOp(BinaryOp &op)override {
        if(op.op == Op::Assign)
        {
            VisitChildren(op);
            if(!op.left->type->mut){
                throw ParseError("Cannot assign to const type" +
                                 String(*op.right->type) + " to " +
                                 String(*op.left->type), op.coord);
            }
            
            if(op.left->type->temporary){
                throw ParseError("Cannot assign to temporary" +
                                 String(*op.right->type) + " to " +
                                 String(*op.left->type), op.coord);
            }
            
            if(!TypeCheck(*op.left->type,*op.right->type)){
                throw ParseError("Cannot assign " +
                                 String(*op.right->type) + " to " +
                                 String(*op.left->type), op.coord);
            }
           // Assert(IsAnnotated(op.type), op);

            return;
        }
        if(op.op == Op::Call)
        {
            op.right->Visit(*this);
            auto var = (Var*)op.left;
            assert(IsAnnotated(op.right));
            assert(typeid(ExprList) == typeid(*op.right));
            
            auto fn = FindExactMatch(var->name, scopes, *(ExprList*)op.right);
            Assert(fn, op, "");
            op.fn = fn;
            op.type = fn->ret;
            op.args = new ExprList(*(ExprList*)op.right);
            
            IsAnnotated(op.type);

            return;
        }
        if(op.op == Op::Dot){
            op.left->Visit(*this);
            assert(IsAnnotated(op.left->type));
            auto type = &RemoveSugar(*op.left->type);

            if(auto t = type->IsType())
            {
                auto var = new Var;
                var->def = FindTypeInfo(*this, *t->type);
                var->type = var->def->type;
                op.left = var;
                type = var->type;
                
            }
            
            auto record = dynamic_cast<StructDef*>(type);
            auto list = dynamic_cast<DecList*>(type);
            auto ptr = dynamic_cast<DecPtr*>(type);
            
            if(!record && !list && !ptr){
                throw ParseError("Expected structure, list or a singly indirected pointer, found " + String(*type), op.coord);
            }
    
            if(ptr){
                record = dynamic_cast<StructDef*>(&RemoveSugar(*ptr->pointed));
                if(!record){
                    throw ParseError("Expected structure, list or a singly indirected pointer", op.coord);
                }
            }
            if(record){
                auto var = dynamic_cast<Var*>(op.right);
                if(!var){
                    throw ParseError("Expected field name", op.coord);
                }
                for(auto field : record->fields){
                    if(field->ident == var->name){
                        Visit(*record);
                        op.type = field->type;
                        Assert(IsAnnotated(op.type), op);
                        return;
                    }
                }
                throw ParseError("No field named '" + var->name + "' on " + String(*record), op.coord);
            }
            
            else
            {
                auto num = dynamic_cast<ConstNumber*>(op.right);
                auto n = atoi(num->value.c_str());
                if(n < 0 || n >= list->list.size()){
                    throw ParseError("List access out of bounds", op.coord);
                }
                op.type = list->list[n].dec;
            }
            Assert(IsAnnotated(op.type), op);
            return;
        }
        
        VisitChildren(op);
        ExprList args;
        args.list = {op.left, op.right};
        args.coord = op.coord;
        
        FuncDef *def = nullptr;
        if(op.op == Op::Plus){
            if(typeid(*op.left->type) == typeid(DecPtr)){
                op.type = op.left->type;
                op.fn = &Instrinsic::pointerAdd;
                op.args = new ExprList(args);
                Assert(IsAnnotated(op.type), op);
                return;
            }
    
            def = FindExactMatch("add", scopes, args);
        }
        else if(op.op == Op::Mul){
            def = FindExactMatch("mul", scopes, args);
        }
        else if(op.op == Op::Div){
            def = FindExactMatch("div", scopes, args);
        }
        else if(op.op == Op::Minus){
            def = FindExactMatch("sub", scopes, args);
        }
        else if(op.op == Op::BitOr){
            def = FindExactMatch("bitOr", scopes, args);
        }
        else if(op.op == Op::BitAnd){
            def = FindExactMatch("bitAnd", scopes, args);
        }
        else if(op.op == Op::Array){
            def = FindExactMatch("opArray", scopes, args);
        }
        else if(op.op == Op::Mod){
            def = FindExactMatch("mod", scopes, args);
        }
        else if(op.op == Op::Equality){
            def = FindExactMatch("equal", scopes, args);
        }
        else if(op.op == Op::EqualityNegated){
            def = FindExactMatch("notEqual", scopes, args);
        }
        else if(op.op == Op::Less){
            def = FindExactMatch("less", scopes, args);
        }
        else if(op.op == Op::LessEqual){
            def = FindExactMatch("lessEqual", scopes, args);
        }
        else if(op.op == Op::Greater){
            def = FindExactMatch("greater", scopes, args);
        }
        else if(op.op == Op::GreaterEqual){
            def = FindExactMatch("greaterEqual", scopes, args);
        }
        else if(op.op == Op::And){
            def = FindExactMatch("and", scopes, args);
        }
        else if(op.op == Op::Or){
            def = FindExactMatch("or", scopes, args);
        }
        else
            assert(false);
            
        op.args = new ExprList(args);
        if(def){
            op.type = def->ret->type;
            op.fn = def;
        }
        assert(typeid(ExprList) != typeid(*op.type));

        Assert(op.fn, op);
        if(((FuncDef*)op.fn)->ret)
            Assert(IsAnnotated(op.type), op);
    }
    void IsUnaryOp(UnaryOp &op)override {
        VisitChildren(op);
        
        if(op.op == Op::PointerOperator){
            if(typeid(RemoveSugar(*op.expr->type)) != typeid(DecPtr)){
                throw ParseError("Cannot dereference non pointer type", op.coord);
            }
            op.type = cast<DecPtr>(RemoveSugar(*op.expr->type)).pointed;
            assert(op.type);
        }
        else if(op.op == Op::AddressOperator){
            if(op.expr->type->temporary){
                throw ParseError("Cannot take address of temporary", op.coord);
            }
            auto ptr = new DecPtr;
            ptr->pointed = op.expr->type;
            ptr->coord = op.expr->coord;
            op.type = ptr;
            assert(op.type);
        }
        else if(op.op == Op::Negated || op.op == Op::Minus){
            op.type = op.expr->type;
            assert(op.type);
        }
        else assert(false);
    }

    void IsStructDef(StructDef &def)override {
        
        if(!IsDeclared(def)){
            Declare(*this, def);
        }

        if(RequiresAnnotating(def))
        {
            def.annotated = AnnotatedState::Annotating;
            
            if(def.Generic()){
            }
            else{
                scopes.push_back(&def.block);
                VisitChildren(def);
                scopes.pop_back();
                
                def.typeinfo = new Variable;
                def.typeinfo->ident = "typeInfo" + def.ident;
                def.typeinfo->type = cast<Dec>(Find(*this, "TypeInfo"));
                assert(IsAnnotated(def.typeinfo->type));
                def.annotated = AnnotatedState::Annotated;
                defs.push_back(&def);
            }
        }
    }
    void IsEnumDef(EnumDef &def)override {
    }
    void IsFuncDef(FuncDef &def)override {
        if(!IsDeclared(def)){
            Declare(*this, def);
        }
        
        if(RequiresAnnotating(def))
        {
            def.annotated = AnnotatedState::Annotating;
            
            if(def.args){
                if(def.body)
                    scopes.push_back(def.body);
                for(auto arg : def.args->list){
                    if(int(AnnotateParam(*this, *arg.dec, def.body)) & int(AnnotateEvent::AnyDecl)){
                        def.generic = true;
                    }
                }
                if(def.body)
                    scopes.pop_back();
            }
            if(def.generic) return;
            
            if(def.ret){
                AnnotateParam(*this, *def.ret);
                def.ret->temporary = def.ret->ref ? false : true;
            }
            if(def.body){
                scopes.push_back(def.body);
                for(auto arg : def.args->list){
                    auto var = new Variable;
                    var->ident = arg.ident;
                    var->type = arg.dec;
                    var->coord = arg.dec->coord;
                    Declare(*this, arg.ident, *var);
                    var->annotated = AnnotatedState::Annotated;
                }
                scopes.pop_back();
                def.body->Visit(*this);
            }
            if(def.ret->list.size() && def.body && !def.body->didReturn){
                throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
            }
            def.annotated = AnnotatedState::Annotated;
        }
    }

    void IsVariable(Variable &def)override {
        if(!IsDeclared(def))
        {
            Declare(*this, def.ident, def);
            assert(def.type);
        }
        if(RequiresAnnotating(def)){
            if(def.assign){
                Visit(*def.assign);
            }
            if(def.top){
                varDefs.push_back(&def);
                if(def.ident == "int"){
                    printf("i");
                }

            }
            assert(def.annotated == AnnotatedState::Declared);
            def.annotated = AnnotatedState::Annotating;
            AnnotateParam(*this, *def.type, true);
            Dec& type = RemoveSugar(*def.type);
            if(typeid(type) == typeid(StructDef)){
                StructDef& str = cast<StructDef>(type);
                if(str.Generic()){
                    throw ParseError("Cannot declare generic structure of type " + String(str), def.coord);
                }
            }
            def.annotated = AnnotatedState::Annotated;
            
        }
    }
    void IsVar(Var &var)override {
        var.def = Find(*this, var.name);

        if(!var.def){
            throw ParseError("Use of undeclared variable '" + var.name + "'", var.coord);
        }
    
     
        Visit(*var.def);
        var.type = var.def->type;
        
        Dec& type = RemoveSugar(*var.def);
        if(typeid(type) != typeid(Variable)){
            auto t = new DecType;
            t->type = &type;
            var.type = t;
        }
        
        assert(IsAnnotated(var.def));
        assert(IsAnnotated(&var));
    }
    void IsConstNumber(ConstNumber &num)override {
        num.type = Types::Num;
    }
    void IsReturn(Return &ret)override {
        scopes.back()->didReturn = true;
        if(ret.expr)
            Visit(*ret.expr);
    }
    void IsIf(If &statement)override {
        VisitChildren(statement);
        if(statement.falseBody){
            scopes.back()->didReturn = statement.trueBody->didReturn && statement.falseBody->didReturn;
        }
        else{
            scopes.back()->didReturn = statement.trueBody->didReturn;
        }
    }
    void IsFor(For &loop)override {
        loop.from->Visit(*this);
        if(loop.to && loop.from){
            loop.to->Visit(*this);
            auto it = new Variable;
            it->ident = loop.it;
            it->type = loop.from->type;
            loop.body->childrenAppended.push_back(it);
        }
        loop.body->Visit(*this);
        scopes.back()->didReturn |= loop.body->didReturn;
    }
    void IsConstString(ConstString &str)override {
        str.type = cast<Dec>(Find(*this, "str"));
        assert(str.type);
    }
    void IsIntrinsicFuncDef(IntrinsicFuncDef &def)override {
        if(!IsDeclared(def)){
            Declare(*this, def);
        }
        
        if(RequiresAnnotating(def))
        {
            def.annotated = AnnotatedState::Annotating;
            AnnotateParam(*this, *def.ret);
            AnnotateParam(*this, *def.args);
            def.annotated = AnnotatedState::Annotated;
        }
    }
    void IsIntrinsicStructDef(IntrinsicStructDef &def)override {
            def.typeinfo = new Variable;
            def.typeinfo->ident = "typeInfo" + def.ident;
            def.typeinfo->type = cast<Dec>(Find(*this, "TypeInfo"));
            assert(def.typeinfo->type);
            def.typeinfo->annotated = AnnotatedState::Annotated;

    }
};
