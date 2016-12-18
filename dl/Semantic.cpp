//
//  Semantic.cpp
//  Created by David on 8/20/16.
//

#include "Semantic.h"
#include "Project.h"
#include "Apply.h"
#include <set>

struct Match {
    int strength = 100;
    Variable* func = nullptr;
};

inline vector<Match> MatchesForName(Semantic& semantic, const string& name, Coord coord){
    for(int i = (int)semantic.scopes.size()-1; i >= 0; i--){
        Blck &scope = *semantic.scopes[i];
        vector<Match> matches;
        if(scope.functions.count(name))
        {
            auto& fns = scope.functions[name];
            for (auto func : fns) {
                matches.push_back({100, func});
            }
        }
        
        for(auto include : scope.includes){
            if(include->functions.count(name))
            {
                auto& fns = include->functions[name];
                for (auto func : fns) {
                    matches.push_back({100, func});
                }
            }
        }
        
        if(matches.size()){
            return matches;
        }
    }
    throw ParseError("Couldnt find any functions named '" + name + " fn()'", coord);
}

DecList& Params(Variable& func) {
    FuncDef* fn = dynamic_cast<FuncDef*>(&func);
    if (fn) {
        return fn->params;
    }
    
    auto decfn = func.IsFn();
    if(decfn){
        return decfn->params;
    }
    assert(false);
}
FuncDef& Specialize(Semantic& semantic, FuncDef& fn, const table<string, Dec*>& known) {
    assert(known.size() > 0);
    assert(fn.generic);
    assert(fn.unknown.size());

    for(auto spec : fn.specializations){
        bool equal = true;
        for(auto know : known){
            equal &= TypeCheck(*know.second, *spec->unknown[know.first], false);
        }
        if(equal)
            return *spec;
    }
    FuncDef& def = *Copy(&fn);
    def.ident = fn.ident + std::to_string(fn.specializations.size());
    def.generic = false;
    semantic.scopes.push_back(def.body);

    assert(known.size() == def.unknown.size());
    for (auto iter : known) {
        auto at = def.unknown.find(iter.first);
        assert(at != def.unknown.end());
        (*at).second->type = iter.second;
        
        Dec* type = &RemoveSugar(*iter.second);
        if(typeid(type) != typeid(Variable) && typeid(type) != typeid(DecFns)){
            auto t = new DecType;
            t->type = type;
            type = t;
        }
        assert(iter.first != "");
        auto any = new DecAny;
        any->ident = iter.first;
        any->type = iter.second;
        Redeclare(semantic, any->ident, *any);
    }
    
    auto retParams = AnnotateParam(semantic, def.params, false, true);
    auto retResults = AnnotateParam(semantic, def.results, false, true);
    semantic.scopes.pop_back();
    
    //Both of these can only return None since they should be fully annotated and all Any decls should be completely known
    assert(retParams == AnnotateEvent::None);
    assert(retResults == AnnotateEvent::None);

    def.results.temporary = def.results.ref ? false : true;
    assert(def.body);
    semantic.scopes.push_back(def.body);
    for(auto arg : def.params.list){
        auto var = new Variable;
        var->ident = arg.ident;
        var->type = arg.dec;
        var->coord = arg.dec->coord;
        Declare(semantic, arg.ident, *var);
        var->annotated = AnnotatedState::Annotated;
    }
    semantic.scopes.pop_back();
    
    def.body->Visit(semantic);
    if(def.results.list.size() && def.body && !def.body->didReturn){
        throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
    }
    def.type = def.results.type;
    assert(def.type);
    
    fn.specializations.push_back(&def);
    return def;
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

    for(auto& match : matches){
        semantic.Visit(*match.func);
        Known known;

        DecList& params = Params(*match.func);
        if(params.list.size() != args.list.size()){
            continue;
        }
        bool matched = true;
        for(int i = 0; i < params.list.size(); i++){
            Dec& paramAt = RemoveSugar(*params.list[i].dec);
            Dec& argAt = RemoveSugar(*args.list[i]->type);
            matched &= Apply(argAt, paramAt, known);
        }
        if (matched) {
            foundMatch += matched;
            found.push_back({match.func, known});
            assert(known.resolved.size() == cast<FuncDef>(match.func)->unknown.size());
        }
    }
    
    if(foundMatch == 0){
        string error = "Failed to find match for function \n" + name + " fn" + String(args) + "\n--------Possible Matches-------\n";
        for(auto match : matches)
        {
            DecList& params = Params(*match.func);
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
    
    FuncDef& fn = *cast<FuncDef>(found[0].fn);
    if (!fn.generic){
        assert(found[0].known.resolved.size() == 0);
        return &fn;
    }
    
    return &Specialize(semantic, fn, found[0].known.resolved);
}

Variable* FindExactMatch(const string& name, Semantic& semantic, DecList& args)
{
    auto matches = MatchesForName(semantic, name, args.coord);
    int foundMatch = 0;
    struct Matched {
        Variable* fn;
        Known known;
    };
    vector<Matched> found;
    
    for(auto& match : matches){
        semantic.Visit(*match.func);
        Known known;
        
        DecList& params = Params(*match.func);
        if(params.list.size() != args.list.size()){
            continue;
        }
        bool matched = true;
        for(int i = 0; i < params.list.size(); i++){
            Dec& paramAt = RemoveSugar(*params.list[i].dec);
            Dec& argAt = RemoveSugar(*args.list[i].dec);
            matched &= Apply(argAt, paramAt, known);
        }
        if (matched) {
            foundMatch += matched;
            found.push_back({match.func, known.resolved});
            assert(known.resolved.size() == cast<FuncDef>(match.func)->unknown.size());
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
    FuncDef& fn = *cast<FuncDef>(found[0].fn);
    if (!fn.generic){
        assert(found[0].known.resolved.size() == 0);
        return &fn;
    }
    return &Specialize(semantic, fn, found[0].known.resolved);
}


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
    info.def->type = Find(self, "TypeInfo", dec.coord);
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




AnnotateEvent AnnotateParam(Semantic&self, Dec&decl, bool declareAny, bool findAny){
    if(typeid(decl) == typeid(DecVar))
    {
        DecVar &type = (DecVar&)decl;
        auto innerType = Find(self, type.ident, decl.coord);
        type.type = cast<Dec>(innerType);
        assert(type.type);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if(typeid(decl) == typeid(DecGen))
    {
        DecGen &type = (DecGen&)decl;
        AnnotateParam(self, *type.typeGeneric, declareAny, findAny);
        if(type.constraints.size()){
            DecList l;
            l.list.resize(type.constraints.size(), DecName("", nullptr));
            for(int i = 0; i < type.constraints.size(); i++){
                l.list[i].dec = type.constraints[i];
            }
            auto annotate = int(AnnotateParam(self, *new DecList(l), declareAny, findAny));
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
                
                if (TypeCheck(*new DecList(ll), *new DecList(l), false)) {
                    type.type = spec;
                    assert(type.type);
                    return AnnotateEvent::None;
                }
            }
            StructDef *def = s->Copy();
            def->generic = s;
            assert(DeclareConstraints(def->constraints, type.constraints, def->block));
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
        if(!type.type){

            return AnnotateEvent::AnyDecl;
        }
        return AnnotateEvent::None;
    }

    if(typeid(decl) == typeid(DecPtr))
    {
        DecPtr &type = cast<DecPtr>(decl);
        return AnnotateParam(self, *type.pointed, declareAny, findAny);
    }
    if(typeid(decl) == typeid(DecType))
    {
        DecType &type = cast<DecType>(decl);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if(typeid(decl) == typeid(DecList))
    {
        DecList &list = cast<DecList>(decl);
        auto ret = AnnotateEvent::None;
        for(auto decl : list.list){
            ret = AnnotateEvent(int(ret) | int(AnnotateParam(self, *decl.dec, declareAny, findAny)));
        }
        if(ret != AnnotateEvent::None)
            return ret;
        
        if(list.list.size() == 0){
            list.type = &DecList::Empty;
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
    if(typeid(decl) == typeid(EnumDef))
    {
        self.IsEnumDef(cast<EnumDef>(decl));
        return AnnotateEvent::None;
    }
    if(typeid(decl) == typeid(IntrinsicStructDef))
    {
        return AnnotateEvent::None;
    }

    if(typeid(decl) == typeid(DecFn))
    {
        DecFn &type = (DecFn&)decl;
        AnnotateEvent status = AnnotateEvent::None;
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.results, declareAny, findAny)));
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.params, declareAny, findAny)));
        return status;
    }
    if(typeid(decl) == typeid(DecArray))
    {
        DecArray &type = (DecArray&)decl;
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
    if(typeid(variable) == typeid(FuncDef) || typeid(variable) == typeid(IntrinsicFuncDef))
    {
        self.scopes.back()->functions[name].push_back((FuncDef*)&variable);
    }
    else if(variable.IsFn())
    {
        self.scopes.back()->functions[name].push_back((FuncDef*)&variable);
    }
    else
    {
        auto back = self.scopes.back()->variables[name];
        if(typeid(variable) == typeid(StructDef) && back && typeid(*back) == typeid(StructDef))
        {
            StructDef &bStruct = (StructDef&)*back;
            StructDef &aStruct = (StructDef&)variable;
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
    if(typeid(variable) == typeid(FuncDef) || typeid(variable) == typeid(IntrinsicFuncDef))
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

Variable* Find(Semantic &self, const string& name, Coord coord){
    for(int i = (int)self.scopes.size()-1; i >= 0; i--){
        Blck &scope = *self.scopes[i];
        if(scope.variables.count(name)){
            assert(scope.variables[name]);
            return scope.variables[name];
        }
        
        for (auto include : scope.includes) {
            if(include->variables.count(name)){
                assert(include->variables[name]);
                return include->variables[name];
            }
        }
    }
    auto matches = MatchesForName(self, name, coord);
    if(matches.size()){
        auto fns = new DecFns;
        fns->type = fns;
        fns->annotated = AnnotatedState::Annotated;
        for(auto match :matches){
            fns->functions.push_back(match.func);
            self.Visit(*match.func);
        }
        return fns;
    }
    throw ParseError("Use of undeclared variable '" + name, coord);
    return nullptr;
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
    auto type = new DecList;
    type->list = types;
    self.type = type;
}

void Semantic::IsCastExpr(CastExpr &cast) {
    cast.expr->Visit(*this);
    AnnotateParam(*this, *cast.type);
}

void Semantic::IsCall(Call &call){

    call.params->Visit(*this);
    if (typeid(*call.operand) == typeid(FieldAccess))
    {
        FieldAccess& access = (FieldAccess&)*call.operand;
        IsFieldAccess(access, true);
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
    assert(IsAnnotated(call.params));
    assert(typeid(ExprList) == typeid(*call.params));
    
    auto fn = FindExactMatch(var->name, scopes, *call.params);
    Assert(fn, call, "");
    call.fn = fn;
    call.type = fn->type;
    
    IsAnnotated(call.type);
}

void Semantic::IsFieldAccess(FieldAccess &field, bool silent) {
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
    auto record = dynamic_cast<StructDef*>(type);
    auto list = dynamic_cast<DecList*>(type);
    auto ptr = dynamic_cast<DecPtr*>(type);
    
    if(!record && !list && !ptr){
        throw ParseError("Expected structure, list or a singly indirected pointer, found " + String(*type), field.coord);
    }
    
    if(ptr){
        record = dynamic_cast<StructDef*>(&RemoveSugar(*ptr->pointed));
        auto operand = field.operand;
        auto deref = new UnaryOp;
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
void Semantic::IsFieldAccess(FieldAccess &field) {
    Semantic::IsFieldAccess(field, false);
}

void Semantic::IsBinaryOp(BinaryOp &op) {
    if(op.op == Lexer::Assign)
    {
        if(typeid(*op.left) == typeid(FieldAccess))
        {
            FieldAccess& access = (FieldAccess&)*op.left;
            IsFieldAccess(access, true);
            if(!access.type)
            {
                op.args = new ExprList;
                op.args->list.push_back(access.operand);
                Visit(*op.right);
                op.args->list.push_back(op.right);
                op.fn = FindExactMatch(access.field, scopes, *op.args);
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
        if(typeid(*op.left->type) == typeid(DecPtr)){
            op.type = op.left->type;
            op.fn = &Instrinsic::pointerAdd;
            op.args = new ExprList(args);
            IsAnnotated(op.type);
            return;
        }

        def = FindExactMatch("add", scopes, args);
    }
    else if(op.op == Lexer::Mul){
        def = FindExactMatch("mul", scopes, args);
    }
    else if(op.op == Lexer::Div){
        def = FindExactMatch("div", scopes, args);
    }
    else if(op.op == Lexer::Sub){
        def = FindExactMatch("sub", scopes, args);
    }
    else if(op.op == Lexer::Or){
        def = FindExactMatch("bitOr", scopes, args);
    }
    else if(op.op == Lexer::And){
        def = FindExactMatch("bitAnd", scopes, args);
    }
    // else if(op.op == Op::Array){
    //     def = FindExactMatch("opArray", scopes, args);
    // }
    else if(op.op == Lexer::Mod){
        def = FindExactMatch("mod", scopes, args);
    }
    else if(op.op == Lexer::Equal){
        def = FindExactMatch("equal", scopes, args);
    }
    else if(op.op == Lexer::NotEqual){
        def = FindExactMatch("notEqual", scopes, args);
    }
    else if(op.op == Lexer::Less){
        def = FindExactMatch("less", scopes, args);
    }
    else if(op.op == Lexer::LessEq){
        def = FindExactMatch("lessEqual", scopes, args);
    }
    else if(op.op == Lexer::Greater){
        def = FindExactMatch("greater", scopes, args);
    }
    else if(op.op == Lexer::GreaterEq){
        def = FindExactMatch("greaterEqual", scopes, args);
    }
    else if(op.op == Lexer::AndAnd){
        def = FindExactMatch("and", scopes, args);
    }
    else if(op.op == Lexer::OrOr){
        def = FindExactMatch("or", scopes, args);
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
void Semantic::IsUnaryOp(UnaryOp &op) {
    VisitChildren(op);
    
    if(op.op == Lexer::Caret){
        if(!RemoveSugar(*op.expr->type).IsPtr()){
            throw ParseError("Cannot dereference non pointer type", op.coord);
        }
        op.type = cast<DecPtr>(RemoveSugar(*op.expr->type)).pointed;
        assert(op.type);
    }
    else if(op.op == Lexer::And){
         if(op.expr->type->temporary){
             throw ParseError("Cannot take address of temporary", op.coord);
         }
         auto ptr = new DecPtr;
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

void Semantic::IsStructDef(StructDef &def) {
    
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
void Semantic::IsEnumDef(EnumDef &def) {
}
void Semantic::IsFuncDef(FuncDef &def) {
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
        if(typeid(type) == typeid(StructDef)){
            StructDef& str = cast<StructDef>(type);
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
    if(typeid(type) != typeid(Variable) && typeid(type) != typeid(DecFns)){
        auto t = new DecType;
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
void Semantic::IsIntrinsicFuncDef(IntrinsicFuncDef &def) {
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
void Semantic::IsIntrinsicStructDef(IntrinsicStructDef &def) {
        def.typeinfo = new Variable;
        def.typeinfo->ident = "typeInfo" + def.ident;
        def.typeinfo->type = cast<Dec>(Find(*this, "TypeInfo", def.coord));
        assert(def.typeinfo->type);
        def.typeinfo->annotated = AnnotatedState::Annotated;

}
