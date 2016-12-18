//
//  Semantic.cpp
//  Created by David on 8/20/16.
//

#include "Semantic.h"
#include "Project.h"
#include "Apply.h"
#include <set>

void FirstPass(Semantic&self, Blck& ast){
    self.scopes.push_back(&ast);
    for (auto node : ast.childrenAppended)
    {
        if(auto def = dynamic_cast<Variable*>(node))
        {
            def->top = true;
            Declare(self, *def);
        }
    }
    for (auto node : ast.children) {
        if(auto def = dynamic_cast<Variable*>(node))
        {
            def->top = true;
            Declare(self, *def);
        }
    }
    self.scopes.pop_back();
}

void AddFileToSet(std::set<File*>& files, File* file){
    if(files.count(file) == 0)
    {
        files.insert(file);
        for (auto import : file->Imported()) {
            AddFileToSet(files, import);
        }
    }
}
Semantic::Semantic(Project& project){
    for (auto file : project.Files())
    {
        FirstPass(*this, file->ast);
        
        std::set<File*> files; files.insert(&project.base);
        AddFileToSet(files, file);
        
        for (auto import : files) {
            file->ast.includes.push_back(&import->ast);
        }
    }
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
    
    if(typeid(decl) == typeid(TypeList))
    {
        return true;
    }
    if(typeid(decl) == typeid(TypePtr))
    {
        TypePtr &type = (TypePtr&)decl;
        return DeclareConstraints(*type.pointed, constraint, block);
    }
    
    if(typeid(decl) == typeid(TypeVar))
    {
        TypeVar &type = (TypeVar&)decl;
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

AnnotateEvent AnnotateParam(Semantic&self, Dec&decl, bool declareAny, bool findAny){
    if(typeid(decl) == typeid(TypeVar))
    {
        TypeVar &type = (TypeVar&)decl;
        auto innerType = Find(self, type.ident, decl.coord);
        type.type = cast<Dec>(innerType);
        assert(type.type);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if(typeid(decl) == typeid(TypeGen))
    {
        TypeGen &type = (TypeGen&)decl;
        AnnotateParam(self, *type.typeGeneric, declareAny, findAny);
        if(type.constraints.size()){
            TypeList l;
            l.list.resize(type.constraints.size(), DecName("", nullptr));
            for(int i = 0; i < type.constraints.size(); i++){
                l.list[i].dec = type.constraints[i];
            }
            auto annotate = int(AnnotateParam(self, *new TypeList(l), declareAny, findAny));
            Struct*s = &cast<Struct>(RemoveSugar(*type.typeGeneric));
            self.IsStruct(*s);
            type.generic = s;
            type.type = nullptr;

            if(annotate & int(AnnotateEvent::AnyDecl))
            {
                return AnnotateEvent::AnyDecl;
            }


            assert(type.generic);
            for(auto spec : s->specializations){
                TypeList ll;
                ll.list.resize(spec->constraints.size(), DecName("", nullptr));
                for(int i = 0; i < spec->constraints.size(); i++){
                    ll.list[i].dec = spec->constraints[i];
                }
                
                if (TypeCheck(*new TypeList(ll), *new TypeList(l), false)) {
                    type.type = spec;
                    assert(type.type);
                    return AnnotateEvent::None;
                }
            }
            Struct *def = s->Copy();
            def->generic = s;
            assert(DeclareConstraints(def->constraints, type.constraints, def->block));
            s->specializations.push_back(def);
            def->specialization = true;
            def->ident = s->ident + std::to_string(s->specializations.size());
            self.IsStruct(*def);
            
            type.type = def;
        }
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(DecAny))
    {
        DecAny &type = cast<DecAny>(decl);
        if(!type.type){

            return AnnotateEvent::AnyDecl;
        }
        return AnnotateEvent::None;
    }

    if(typeid(decl) == typeid(TypePtr))
    {
        TypePtr &type = cast<TypePtr>(decl);
        return AnnotateParam(self, *type.pointed, declareAny, findAny);
    }
    if(typeid(decl) == typeid(TypeType))
    {
        TypeType &type = cast<TypeType>(decl);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if(typeid(decl) == typeid(TypeList))
    {
        TypeList &list = cast<TypeList>(decl);
        auto ret = AnnotateEvent::None;
        for(auto decl : list.list){
            ret = AnnotateEvent(int(ret) | int(AnnotateParam(self, *decl.dec, declareAny, findAny)));
        }
        if(ret != AnnotateEvent::None)
            return ret;
        
        if(list.list.size() == 0){
            list.type = &TypeList::Empty;
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
    if(typeid(decl) == typeid(Struct))
    {
        self.IsStruct(cast<Struct>(decl));
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(Enum))
    {
        self.IsEnum(cast<Enum>(decl));
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(IntrinsicStruct))
    {
        return AnnotateEvent::None;
    }

    if(typeid(decl) == typeid(TypeFn))
    {
        TypeFn &type = (TypeFn&)decl;
        AnnotateEvent status = AnnotateEvent::None;
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.results, declareAny, findAny)));
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.params, declareAny, findAny)));
        return status;
    }
    if(typeid(decl) == typeid(TypeArray))
    {
        TypeArray &type = (TypeArray&)decl;
        AnnotateEvent status = AnnotateParam(self, *type.type);
        return status;
    }
    assert(false && "Unhandled type");
    return AnnotateEvent::Failed;
}

void Declare(Semantic &self, const string& name, Variable& variable)
{
    assert(!IsDeclared(variable));
    variable.annotated = AnnotatedState::Declared;
    if(typeid(variable) == typeid(Func) || typeid(variable) == typeid(IntrinsicFunc))
    {
        self.scopes.back()->functions[name].push_back((Func*)&variable);
    }
    else if(variable.IsFn())
    {
        self.scopes.back()->functions[name].push_back((Func*)&variable);
    }
    else
    {
        auto back = self.scopes.back()->variables[name];
        if(typeid(variable) == typeid(Struct) && back && typeid(*back) == typeid(Struct))
        {
            Struct &bStruct = (Struct&)*back;
            Struct &aStruct = (Struct&)variable;
            if (bStruct.incomplete && aStruct.incomplete)
            {
                return;
            }
            else if(bStruct.incomplete && !aStruct.incomplete)
            {
                self.scopes.back()->variables[name] = &aStruct;
                return;
            }
            else if(!bStruct.incomplete && aStruct.incomplete)
            {
                self.scopes.back()->variables[name] = &bStruct;
                return;
            }
        }
        if(self.scopes.back()->variables[name]){
            throw ParseError("Variable '" + name + "' was already declared" , variable.coord);
        }
        self.scopes.back()->variables[name] =(&variable);
    }
}

void Redeclare(Semantic &self, const string& name, Variable& variable)
{
    variable.annotated = AnnotatedState::Declared;
    if(typeid(variable) == typeid(Func) || typeid(variable) == typeid(IntrinsicFunc))
    {
        assert(false);
    }
    else if(variable.IsFn())
    {
        assert(false);
    }
    else
    {
        self.scopes.back()->variables[name] =(&variable);
    }
}

void Semantic::IsBlck(Blck &self)
{
    scopes.push_back(&self);

    VisitChildren(self);
    scopes.pop_back();
    if(scopes.size())
        scopes.back()->didReturn |= self.didReturn;
}
void Semantic::IsExprList(ExprList &self) {
    VisitChildren(self);
    vector<DecName> types;
    types.reserve(self.list.size());
    for(int i = 0; i < self.list.size(); i++){
        types.push_back({"", self.list[i]->type});
    }
    auto type = new TypeList;
    type->list = types;
    self.type = type;
}

void Semantic::IsCastExpr(CastExpr &cast) {
    cast.expr->Visit(*this);
    AnnotateParam(*this, *cast.type);
}

void Semantic::IsCall(Call &call){

    call.params->Visit(*this);
    if (typeid(*call.operand) == typeid(Access))
    {
        Access& access = (Access&)*call.operand;
        IsAccess(access, true);
        if (!access.type) {
            auto var = new Var;
            var->name = access.field;
            call.operand = var;
            call.params->list.insert(call.params->list.begin(), access.operand);
        }
    }
    
    if (typeid(*call.operand) != typeid(Var)) {
        Visit(*call.operand);
        if(!call.operand->type->IsFn())
        {
            Error("Operand of type '" + String(*call.operand->type) + "' is not callable", call.coord);
        }
        return;
    }
    
    auto var = (Var*)call.operand;
    IsAnnotated(call.params);
    assert(typeid(ExprList) == typeid(*call.params));
    
    auto fn = FindExactMatch(var->name, *this, *call.params);
    Assert(fn, call, "");
    call.fn = fn;
    call.type = fn->type;
    
    IsAnnotated(call.type);
}

void Semantic::IsAccess(Access &field, bool silent) {
    field.operand->Visit(*this);
    IsAnnotated(field.operand->type);
    auto type = &RemoveSugar(*field.operand->type);
    
    if(auto t = type->IsType())
    {
        auto var = new Var;
        var->def = FindTypeInfo(*this, *t->type);
        var->type = var->def->type;
        field.operand = var;
        type = var->type;
    }
    auto record = dynamic_cast<Struct*>(type);
    auto list = dynamic_cast<TypeList*>(type);
    auto ptr = dynamic_cast<TypePtr*>(type);
    
    if(!record && !list && !ptr){
        throw ParseError("Expected structure, list or a singly indirected pointer, found " + String(*type), field.coord);
    }
    
    if(ptr){
        record = dynamic_cast<Struct*>(&RemoveSugar(*ptr->pointed));
        auto deref = new Unary;
        deref->op = Lexer::Caret;
        deref->expr = field.operand;
        deref->type = ptr->pointed;
        field.operand = deref;
        if(!record){
            throw ParseError("Expected structure, list or a singly indirected pointer", field.coord);
        }
    }
    if(record){
        
        for(auto var : record->fields){
            if(var->ident == field.field){
                Visit(*record);
                field.type = var->type;
                IsAnnotated(field.type);
                return;
            }
        }
    }
    if(!silent){
        throw ParseError("No field named '" + field.field + "' on " + String(*record), field.coord);
    }
}
void Semantic::IsAccess(Access &field) {
    Semantic::IsAccess(field, false);
}

void Semantic::IsBinary(Binary &op) {
    if(op.op == Lexer::Assign)
    {
        if(typeid(*op.left) == typeid(Access))
        {
            Access& access = (Access&)*op.left;
            IsAccess(access, true);
            if(!access.type)
            {
                op.args = new ExprList;
                op.args->list.push_back(access.operand);
                Visit(*op.right);
                op.args->list.push_back(op.right);
                op.fn = FindExactMatch(access.field, *this, *op.args);
                op.type = op.fn->type;
                return;
            }
        }
        
        Visit(*op.left);
        if(auto dec = op.left->type->IsFn())
        {
            auto var = dynamic_cast<Var*>(op.right);
            if(var){
                var->def = ::FindExactMatch(var->name, *this, dec->params);
                return;
            }
        }
        Visit(*op.right);
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
        
        if(!TypeCheck(*op.left->type, *op.right->type)){
            throw ParseError("Cannot assign " +
                                String(*op.right->type) + " to " +
                                String(*op.left->type), op.coord);
        }
        // Assert(IsAnnotated(op.type), op);

        return;
    }

    VisitChildren(op);
    ExprList args;
    args.list = {op.left, op.right};
    args.coord = op.coord;
    assert(op.coord);
    
    Variable *def = nullptr;
    if(op.op == Lexer::Add){
        if(typeid(*op.left->type) == typeid(TypePtr)){
            op.type = op.left->type;
            op.fn = &Instrinsic::pointerAdd;
            op.args = new ExprList(args);
            IsAnnotated(op.type);
            return;
        }

        def = FindExactMatch("add", *this, args);
    }
    else if(op.op == Lexer::Mul){
        def = FindExactMatch("mul", *this, args);
    }
    else if(op.op == Lexer::Div){
        def = FindExactMatch("div", *this, args);
    }
    else if(op.op == Lexer::Sub){
        def = FindExactMatch("sub", *this, args);
    }
    else if(op.op == Lexer::Or){
        def = FindExactMatch("bitOr", *this, args);
    }
    else if(op.op == Lexer::And){
        def = FindExactMatch("bitAnd", *this, args);
    }
    // else if(op.op == Op::Array){
    //     def = FindExactMatch("opArray", scopes, args);
    // }
    else if(op.op == Lexer::Mod){
        def = FindExactMatch("mod", *this, args);
    }
    else if(op.op == Lexer::Equal){
        def = FindExactMatch("equal", *this, args);
    }
    else if(op.op == Lexer::NotEqual){
        def = FindExactMatch("notEqual", *this, args);
    }
    else if(op.op == Lexer::Less){
        def = FindExactMatch("less", *this, args);
    }
    else if(op.op == Lexer::LessEq){
        def = FindExactMatch("lessEqual", *this, args);
    }
    else if(op.op == Lexer::Greater){
        def = FindExactMatch("greater", *this, args);
    }
    else if(op.op == Lexer::GreaterEq){
        def = FindExactMatch("greaterEqual", *this, args);
    }
    else if(op.op == Lexer::AndAnd){
        def = FindExactMatch("and", *this, args);
    }
    else if(op.op == Lexer::OrOr){
        def = FindExactMatch("or", *this, args);
    }
    else
        assert(false);
        
    op.args = new ExprList(args);
    if(def){
        op.type = def->type;
        op.fn = def;
    }
    assert(typeid(ExprList) != typeid(*op.type));

    Assert(op.fn, op);
}
void Semantic::IsUnary(Unary &op) {
    VisitChildren(op);
    
    if(op.op == Lexer::Caret){
        if(!RemoveSugar(*op.expr->type).IsPtr()){
            throw ParseError("Cannot dereference non pointer type", op.coord);
        }
        op.type = cast<TypePtr>(RemoveSugar(*op.expr->type)).pointed;
        assert(op.type);
    }
    else if(op.op == Lexer::And){
         if(op.expr->type->temporary){
             throw ParseError("Cannot take address of temporary", op.coord);
         }
         auto ptr = new TypePtr;
         ptr->pointed = op.expr->type;
         ptr->coord = op.expr->coord;
         op.type = ptr;
         assert(op.type);
     }
     else if(op.op == Lexer::Negated || op.op == Lexer::Sub){
        op.type = op.expr->type;
        assert(op.type);
    }
    else assert(false);
}

void Semantic::IsStruct(Struct &def) {
    
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
            def.typeinfo->type = cast<Dec>(Find(*this, "TypeInfo", def.coord));
            IsAnnotated(def.typeinfo->type);
            def.annotated = AnnotatedState::Annotated;
            defs.push_back(&def);
        }
    }
}
void Semantic::IsEnum(Enum &def) {
}
void Semantic::IsFunc(Func &def) {
    if(!IsDeclared(def)){
        Declare(*this, def);
    }
    
    if(RequiresAnnotating(def))
    {
        def.annotated = AnnotatedState::Annotating;
        
        if(def.body)
            scopes.push_back(def.body);
        
        for (auto iter : def.unknown) {
            Declare(*this, iter.first, *iter.second);
        }
        
        for(auto arg : def.params.list){
            if(int(AnnotateParam(*this, *arg.dec, def.body)) & int(AnnotateEvent::AnyDecl)){
                def.generic = true;
            }
        }
        if(def.body)
            scopes.pop_back();

        if(def.generic) return;
        
        AnnotateParam(*this, def.results);
        def.results.temporary = def.results.ref ? false : true;
        def.type = def.results.type;
        assert(def.results.type);

        if(def.body){
            scopes.push_back(def.body);
            for(auto arg : def.params){
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
        if(def.results.list.size() && def.body && !def.body->didReturn){
            throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
        }
        def.annotated = AnnotatedState::Annotated;
    }
}

void Semantic::IsVariable(Variable &def) {
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
        if(typeid(type) == typeid(Struct)){
            Struct& str = cast<Struct>(type);
            if(str.Generic()){
                throw ParseError("Cannot declare generic structure of type " + String(str), def.coord);
            }
        }
        def.annotated = AnnotatedState::Annotated;
        
    }
}
void Semantic::IsVar(Var &var) {
    var.def = Find(*this, var.name, var.coord);

    if(!var.def){
        throw ParseError("Use of undeclared variable '" + var.name + "'", var.coord);
    }

    
    Visit(*var.def);
    var.type = var.def->type;
    
    Dec& type = RemoveSugar(*var.def);
    if(typeid(type) != typeid(Variable) && typeid(type) != typeid(TypeFns)){
        auto t = new TypeType;
        t->type = &type;
        var.type = t;
    }
    
    IsAnnotated(var.def);
    IsAnnotated(&var);
}
void Semantic::IsConstNumber(ConstNumber &num) {
    num.type = &Types::Num;
}
void Semantic::IsReturn(Return &ret) {
    scopes.back()->didReturn = true;
    if(ret.expr)
        Visit(*ret.expr);
}
void Semantic::IsIf(If &statement) {
    VisitChildren(statement);
    if(statement.falseBody){
        scopes.back()->didReturn = statement.trueBody->didReturn && statement.falseBody->didReturn;
    }
    else{
        scopes.back()->didReturn = statement.trueBody->didReturn;
    }
}
void Semantic::IsFor(For &loop) {
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
void Semantic::IsConstString(ConstString &str) {
    str.type = cast<Dec>(Find(*this, "str", str.coord));
    assert(str.type);
}
void Semantic::IsIntrinsicFunc(IntrinsicFunc &def) {
    if(!IsDeclared(def)){
        Declare(*this, def);
    }
    
    if(RequiresAnnotating(def))
    {
        def.annotated = AnnotatedState::Annotating;
        AnnotateParam(*this, def.results);
        AnnotateParam(*this, def.params);
        def.annotated = AnnotatedState::Annotated;
        def.type = def.results.type;
        assert(def.results.type);
    }
}
void Semantic::IsIntrinsicStruct(IntrinsicStruct &def) {
        def.typeinfo = new Variable;
        def.typeinfo->ident = "typeInfo" + def.ident;
        def.typeinfo->type = cast<Dec>(Find(*this, "TypeInfo", def.coord));
        assert(def.typeinfo->type);
        def.typeinfo->annotated = AnnotatedState::Annotated;

}
