//
//  Semantic.cpp
//  Created by David on 8/20/16.
//

#include "Semantic.h"
#include "Project.h"
#include "Apply.h"
#include <set>

void FirstPass(Semantic&semantic, Blck& ast){
    semantic.scopes.last().Push(ast);
    for (int i = 0; i < ast.childrenAppended.length; i++) {
        Expr& expr = ast.childrenAppended[i];
        if(expr == Ast::Struct || expr == Ast::StructIntrins || expr == Ast::Enum)
        {
            cast<Variable>(expr).top = true;
            cast<Variable>(expr).outer = &ast;
            Declare(semantic, cast<Variable>(expr));
        }
    }
    for (int i = 0; i < ast.children.length; i++) {
        Expr& expr = ast.children[i];
        if(expr == Ast::Struct || expr == Ast::StructIntrins || expr == Ast::Enum)
        {
            cast<Variable>(expr).top = true;
            cast<Variable>(expr).outer = &ast;
            Declare(semantic, cast<Variable>(expr));
        }
    }
    semantic.scopes.last().Pop();
}

void SecondPass(Semantic&semantic, Blck& ast){
    semantic.scopes.last().Push(ast);
    for (int i = 0; i < ast.childrenAppended.length; i++) {
        Expr& expr = ast.childrenAppended[i];
        if(expr == Ast::Variable || expr == Ast::Func  || expr == Ast::FuncIntrins || expr == Ast::TypeFns)
        {
            cast<Variable>(expr).top = true;
            cast<Variable>(expr).outer = &ast;
            Declare(semantic, cast<Variable>(expr));
        }
    }
    for (int i = 0; i < ast.children.length; i++) {
        Expr& expr = ast.children[i];
        if(expr == Ast::Variable || expr == Ast::Func  || expr == Ast::FuncIntrins || expr == Ast::TypeFns)
        {
            cast<Variable>(expr).top = true;
            cast<Variable>(expr).outer = &ast;
            Declare(semantic, cast<Variable>(expr));
        }
    }
    semantic.scopes.last().Pop();
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
    Scope scope;
    scopes.Push(scope);
    for (auto file : project.Files())
    {
        FirstPass(*this, file->ast);
        
        std::set<File*> files; files.insert(&project.base);
        AddFileToSet(files, file);
        
        for (auto import : files) {
            file->ast.includes.push_back(&import->ast);
        }
    }
    for (auto file : project.Files())
    {
        SecondPass(*this, file->ast);
    }
    
    for (auto file : project.Files()) {
        Visit(file->ast);
    }
}

bool DeclareConstraints(Type&decl, Type&c, Blck&block){
    
    Type& constraint = RemoveSugar(c);
    assert((constraint) != Ast::TypeAny);
    
    if((decl) == Ast::TypeAny)
    {
        TypeAny &type = (TypeAny&)decl;
        if(type.type) return true;
        type.type = &constraint;
        block.variables[type.ident] = (&type);
        return true;
    }
    
    if(decl == Ast::TypeList)
    {
        return true;
    }
    if(decl == Ast::TypePtr)
    {
        TypePtr &type = (TypePtr&)decl;
        return DeclareConstraints(*type.pointed, constraint, block);
    }
    if(decl == Ast::TypeVar)
    {
        TypeVar &type = (TypeVar&)decl;
        return DeclareConstraints(*type.type, constraint, block);
    }
    
    assert(false);
    return false;
}

bool DeclareConstraints(const vector<Type*>& decl, const vector<Type*>& constraints, Blck&block){
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

AnnotateEvent AnnotateParam(Semantic&self, Type&decl, bool declareAny, bool findAny){
    if((decl) == Ast::TypeVar)
    {
        TypeVar &type = (TypeVar&)decl;
        auto innerType = Find(self, type.ident, decl.coord);
        type.type = cast<Type>(innerType);
        assert(type.type);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if((decl) == Ast::TypeGen)
    {
        TypeGen &type = (TypeGen&)decl;
        AnnotateParam(self, *type.typeGeneric, declareAny, findAny);
        if(type.constraints.size()){
            TypeList& l = *new TypeList;
            l.list.Reserve((int)type.constraints.size());
            for(int i = 0; i < type.constraints.size(); i++){
                l.list.Push({"", type.constraints[i]});
            }
            auto annotate = int(AnnotateParam(self, l, declareAny, findAny));
            Struct*s = &cast<Struct>(RemoveSugar(*type.typeGeneric));
            self.Visit(*s);
            type.generic = s;
            type.type = nullptr;

            if(annotate & int(AnnotateEvent::Any))
            {
                return AnnotateEvent::Any;
            }


            assert(type.generic);
            for(auto spec : s->specializations){
                TypeList& ll = *new TypeList;
                ll.list.Reserve((int)spec->constraints.size());
                for(int i = 0; i < spec->constraints.size(); i++){
                    ll.list.Push({"", spec->constraints[i]});
                }
                
                if (TypeCheck(ll, l, false)) {
                    type.type = spec;
                    assert(type.type);
                    return AnnotateEvent::None;
                }
            }
            Struct *def = Copy(s);
            def->generic = s;
            assert(DeclareConstraints(def->constraints, type.constraints, def->block));
            s->specializations.push_back(def);
            def->specialization = true;
            def->ident = s->ident + std::to_string(s->specializations.size());
            self.Visit(*def);
            type.type = def;
        }
        return AnnotateEvent::None;
    }
    if((decl) == Ast::TypeAny)
    {
        TypeAny &type = cast<TypeAny>(decl);
        if(!type.type){

            return AnnotateEvent::Any;
        }
        return AnnotateEvent::None;
    }

    if((decl) == Ast::TypePtr)
    {
        TypePtr &type = cast<TypePtr>(decl);
        return AnnotateParam(self, *type.pointed, declareAny, findAny);
    }
    if((decl) == Ast::TypeType)
    {
        TypeType &type = cast<TypeType>(decl);
        return AnnotateParam(self, *type.type, declareAny, findAny);
    }
    
    if((decl) == Ast::TypeList)
    {
        TypeList &list = cast<TypeList>(decl);
        auto ret = AnnotateEvent::None;
        for(int i = 0; i < list.list.length; i++){
            auto &decl = list.list[i];
            ret = AnnotateEvent(int(ret) | int(AnnotateParam(self, *decl.dec, declareAny, findAny)));
        }
        if(ret != AnnotateEvent::None)
            return ret;
        
        if(list.list.length == 0){
            list.type = &TypeList::Empty;
            return ret;
        }
        if(list.list.length == 1){
            list.type = list.list[0].dec;
            assert(list.type);
            return ret;
        }

        for(int i = 0; i < self.listDefs.length; i++){
            if(TypeCheck(*self.listDefs[i], list)){
                list.type = self.listDefs[i];
            }
        }
        if(!list.type){
            self.listDefs.Push(&list);
            self.defs.Push(&list);
            list.type = &list;
        }
        return ret;
    }
    if((decl) == Ast::Struct)
    {
        self.Visit(cast<Struct>(decl));
        return AnnotateEvent::None;
    }
    if((decl) == Ast::Enum)
    {
        self.Visit(cast<Enum>(decl));
        return AnnotateEvent::None;
    }
    if((decl) == Ast::StructIntrins)
    {
        return AnnotateEvent::None;
    }

    if((decl) == Ast::TypeFn)
    {
        TypeFn &type = (TypeFn&)decl;
        AnnotateEvent status = AnnotateEvent::None;
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.results, declareAny, findAny)));
        status = AnnotateEvent(int(status) | int(AnnotateParam(self, type.params, declareAny, findAny)));
        return status;
    }
    if((decl) == Ast::TypeArray)
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
    if((variable) == Ast::Func || (variable) == Ast::FuncIntrins)
    {
        Func& def = cast<Func>(variable);
        if(def.body)
            self.scopes.last().Push(*def.body);
        
        for (auto iter : def.unknown) {
            Declare(self, iter.first, *iter.second);
        }
        
        for(int i = 0; i < def.params.list.length; i++)
        {
            if(int(AnnotateParam(self, *def.params.list[i].dec, def.body)) & int(AnnotateEvent::Any))
            {
            }
        }
        
    
        AnnotateParam(self, def.results);
        def.results.temporary = def.results.ref ? false : true;
        def.type = def.results.type;
        if(def.body)
            self.scopes.last().Pop();
        
        self.scopes.last().Current().functions[name].push_back((Func*)&variable);
    }
    else if(variable == Ast::TypeFn)
    {
        self.scopes.last().Current().functions[name].push_back((Func*)&variable);
    }
    else
    {
        auto back = self.scopes.last().Current().variables[name];
        if((variable) == Ast::Struct && back && (*back) == Ast::Struct)
        {
            Struct &bStruct = (Struct&)*back;
            Struct &aStruct = (Struct&)variable;
            if (bStruct.incomplete && aStruct.incomplete)
            {
                return;
            }
            else if(bStruct.incomplete && !aStruct.incomplete)
            {
                self.scopes.last().Current().variables[name] = &aStruct;
                return;
            }
            else if(!bStruct.incomplete && aStruct.incomplete)
            {
                self.scopes.last().Current().variables[name] = &bStruct;
                return;
            }
        }
        if(self.scopes.last().Current().variables[name]){
            throw ParseError("Variable '" + name + "' was already declared" , variable.coord);
        }
        self.scopes.last().Current().variables[name] =(&variable);
    }
}

void Redeclare(Semantic &self, const string& name, Variable& variable)
{
    variable.annotated = AnnotatedState::Declared;
    if((variable) == Ast::Func || (variable) == Ast::FuncIntrins)
    {
        assert(false);
    }
    else if(variable == Ast::Func)
    {
        assert(false);
    }
    else
    {
        self.scopes.last().Current().variables[name] =(&variable);
    }
}

void Visit(Semantic& semantic, Blck &self)
{
    semantic.scopes.last().Push(self);

    for (int i = 0; i < self.childrenAppended.length; i++) {
        semantic.Visit(self.childrenAppended[i]);
    }
    for (int i = 0; i < self.children.length; i++) {
        semantic.Visit(self.children[i]);
    }
    semantic.scopes.last().Pop();
    if(semantic.scopes.last().blocks.length)
        semantic.scopes.last().Current().didReturn |= self.didReturn;
}
void Visit(Semantic& semantic, ExprList &self) {
    for (int i = 0; i < self.list.length; i++) {
        semantic.Visit(self.list[i]);
    }

    auto type = new TypeList;
    type->list.Reserve(self.list.length);
    for(int i = 0; i < self.list.length; i++){
        type->list.Push({"", self.list[i].type});
    }
    self.type = type;
}

void Visit(Semantic& semantic, CastExpr &self) {
    semantic.Visit(*self.expr);
    AnnotateParam(semantic, *self.type);
}
void Visit(Semantic& semantic, Access &field, bool silent);

void Visit(Semantic& semantic, Call &call){

    semantic.Visit(*call.params);
    if ((*call.operand) == Ast::Access)
    {
        Access& access = (Access&)*call.operand;
        Visit(semantic, access, true);
        if (!access.type) {
            auto var = new Var;
            var->name = access.field;
            call.operand = var;
            call.params->list.Insert(0, access.operand);
        }
    }
    
    if ((*call.operand) != Ast::Var) {
        semantic.Visit(*call.operand);
        if(*call.operand->type != Ast::TypeFn)
        {
            Error("Operand of type '" + String(*call.operand->type) + "' is not callable", call.coord);
        }
        return;
    }
    
    auto var = (Var*)call.operand;
    AssertAnnotated(call.params);
    auto fn = FindExactMatch(var->name, semantic, *call.params);
    Assert(fn, call, "");
    call.fn = fn;
    call.type = fn->type;
    
    AssertAnnotated(call.type);
}

void Visit(Semantic& semantic, Access &field, bool silent) {
    semantic.Visit(*field.operand);
    AssertAnnotated(field.operand->type);
    
    Type *type = &RemoveSugar(*field.operand->type);
    if(*type == Ast::TypeType)
    {
        TypeType &typeType = cast<TypeType>(*type);
        auto var = new Var;
        var->def = FindTypeInfo(semantic, *typeType.type);
        var->type = var->def->type;
        field.operand = var;
        type = var->type;
    }
    auto record = (*type == Ast::Struct || *type == Ast::StructIntrins) ? cast<Struct>(type) : nullptr;
    auto list = (*type == Ast::TypeList) ? cast<TypeList>(type) : nullptr;
    auto ptr = (*type == Ast::TypePtr) ? cast<TypePtr>(type) : nullptr;
    
    if(!record && !list && !ptr){
        throw ParseError("Expected structure, list or a singly indirected pointer, found " + String(*type), field.coord);
    }
    
    if(ptr){
        record = cast<Struct>(&RemoveSugar(*ptr->pointed));
        auto deref = &Create<Unary>(ptr->coord);
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
                semantic.Visit(*record);
                field.type = var->type;
                AssertAnnotated(field.type);
                return;
            }
        }
    }
    if(!silent){
        throw ParseError("No field named '" + field.field + "' on " + String(*record), field.coord);
    }
}
void Visit(Semantic& semantic, Access &field) {
    Visit(semantic, field, false);
}

void Visit(Semantic& semantic, Binary &op) {
    if(op.op == Lexer::Assign)
    {
        if((*op.left) == Ast::Access)
        {
            Access& access = (Access&)*op.left;
            Visit(semantic, access, true);
            if(!access.type)
            {
                op.args = new ExprList;
                op.args->list.Push(*access.operand);
                semantic.Visit(*op.right);
                op.args->list.Push(*op.right);
                op.fn = FindExactMatch(access.field, semantic, *op.args);
                op.type = op.fn->type;
                return;
            }
        }
        
        semantic.Visit(*op.left);
        if(*op.left->type == Ast::TypeFn)
        {
            TypeFn &fn = cast<TypeFn>(*op.left->type);
            auto var = (*op.right == Ast::Var) ? cast<Var>(op.right) : nullptr;
            if(var){
                var->def = FindExactMatch(var->name, semantic, fn.params);
                return;
            }
        }
        semantic.Visit(*op.right);
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
        // Assert(AssertAnnotated(op.type), op);

        return;
    }

    semantic.Visit(*op.left);
    semantic.Visit(*op.right);

    ExprList args;
    args.list.Push(*op.left);
    args.list.Push(*op.right);
    args.coord = op.coord;
    assert(op.coord);
    
    Variable *def = nullptr;
    
    if(op.op == Lexer::Add){
        if((*op.left->type) == Ast::TypePtr){
            op.type = op.left->type;
            op.fn = &Instrinsic::pointerAdd;
            op.args = new ExprList(args);
            AssertAnnotated(op.type);
            return;
        }

        def = FindExactMatch("add", semantic, args);
    }
    else if(op.op == Lexer::Mul){
        def = FindExactMatch("mul", semantic, args);
    }
    else if(op.op == Lexer::Div){
        def = FindExactMatch("div", semantic, args);
    }
    else if(op.op == Lexer::Sub){
        def = FindExactMatch("sub", semantic, args);
    }
    else if(op.op == Lexer::Or){
        def = FindExactMatch("bitOr", semantic, args);
    }
    else if(op.op == Lexer::And){
        def = FindExactMatch("bitAnd", semantic, args);
    }
    else if(op.op == Lexer::Mod){
        def = FindExactMatch("mod", semantic, args);
    }
    else if(op.op == Lexer::Equal){
        def = FindExactMatch("equal", semantic, args);
    }
    else if(op.op == Lexer::NotEqual){
        def = FindExactMatch("notEqual", semantic, args);
    }
    else if(op.op == Lexer::Less){
        def = FindExactMatch("less", semantic, args);
    }
    else if(op.op == Lexer::LessEq){
        def = FindExactMatch("lessEqual", semantic, args);
    }
    else if(op.op == Lexer::Greater){
        def = FindExactMatch("greater", semantic, args);
    }
    else if(op.op == Lexer::GreaterEq){
        def = FindExactMatch("greaterEqual", semantic, args);
    }
    else if(op.op == Lexer::AndAnd){
        def = FindExactMatch("and", semantic, args);
    }
    else if(op.op == Lexer::OrOr){
        def = FindExactMatch("or", semantic, args);
    }
    else
        assert(false);
        
    op.args = new ExprList(args);
    if(def){
        op.type = def->type;
        op.fn = def;
    }
    assert((*op.type) != Ast::ExprList);

    Assert(op.fn, op);
}
void Visit(Semantic& semantic, Unary &op) {
    semantic.Visit(*op.expr);
    
    if(op.op == Lexer::Caret){
        if(RemoveSugar(*op.expr->type) != Ast::TypePtr){
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

void Visit(Semantic& semantic, Struct &def) {
    
    if(!IsDeclared(def)){
        Declare(semantic, def);
    }
    
    if(RequiresAnnotating(def))
    {
        def.annotated = AnnotatedState::Annotating;
        
        if(def.Generic()){
        }
        else{
            semantic.scopes.last().Push(def.block);
            for (auto field : def.fields) {
                semantic.Visit(*field);
            }
            semantic.scopes.last().Pop();
            
            def.typeinfo = new Variable;
            def.typeinfo->ident = "typeInfo" + def.ident;
            def.typeinfo->type = cast<Type>(Find(semantic, "TypeInfo", def.coord));
            AssertAnnotated(def.typeinfo->type);
            def.annotated = AnnotatedState::Annotated;
            semantic.defs.Push(&def);
        }
    }
}
void Visit(Semantic& semantic, Enum &def) {
}
void Visit(Semantic& semantic, Func &def) {
    if(!IsDeclared(def)){
        Declare(semantic, def);
    }
    
    if(RequiresAnnotating(def))
    {
        if(def.unknown.size() && !def.generic) return;
        
        def.annotated = AnnotatedState::Annotating;
        if(def.body){
            semantic.scopes.last().Push(*def.body);
            for(int i = 0; i < def.params.list.length; i++){
                auto& arg = def.params.list[i];
                auto var = new Variable;
                var->ident = arg.ident;
                var->type = arg.dec;
                var->coord = arg.dec->coord;
                Declare(semantic, arg.ident, *var);
                var->annotated = AnnotatedState::Annotated;
            }
            semantic.scopes.last().Pop();
            semantic.Visit(*def.body);
        }
        if(def.results.list.length && def.body && !def.body->didReturn){
            throw ParseError("Function '" + def.ident + "' requires return value", def.body->coord);
        }
        def.annotated = AnnotatedState::Annotated;
    }
}

void Visit(Semantic& semantic, Variable &def) {
    if(!IsDeclared(def))
    {
        Declare(semantic, def.ident, def);
        assert(def.type);
    }
    if(RequiresAnnotating(def)){
        if(def.assign){
            semantic.Visit(*def.assign);
        }
        if(def.top){
            semantic.varDefs.Push(&def);
            if(def.ident == "int"){
                printf("i");
            }

        }
        assert(def.annotated == AnnotatedState::Declared);
        def.annotated = AnnotatedState::Annotating;
        AnnotateParam(semantic, *def.type, true);
        Type& type = RemoveSugar(*def.type);
        if((type) == Ast::Struct){
            Struct& str = cast<Struct>(type);
            if(str.Generic()){
                throw ParseError("Cannot declare generic structure of type " + String(str), def.coord);
            }
        }
        def.annotated = AnnotatedState::Annotated;
        
    }
}
void Visit(Semantic& semantic, Var &var) {
    
    auto expr = FindVariable(semantic, var.name, var.coord);
    if (*expr == Ast::Struct ||
        *expr == Ast::StructIntrins ||
        *expr == Ast::Func ||
        *expr == Ast::FuncIntrins ||
        *expr == Ast::Variable ||
        *expr == Ast::TypeFns ||
        *expr == Ast::TypeAny ||
        *expr == Ast::Var)
    {
        var.def = cast<Variable>(expr);
    }
    else
    {
        var.expr = expr;
    }
    if(!var.def && !var.expr){
        throw ParseError("Use of undeclared variable '" + var.name + "'", var.coord);
    }

    
    semantic.Visit(*var.def);
    var.type = var.def->type;
    
    Type& type = RemoveSugar(*var.def);
    if((type) != Ast::Variable && (type) != Ast::TypeFns){
        auto t = new TypeType;
        t->type = &type;
        var.type = t;
    }
    
    AssertAnnotated(var.def);
    AssertAnnotated(&var);
}
void Visit(Semantic& semantic, ConstNumber &num) {
    num.type = &Types::Num;
}
void Visit(Semantic& semantic, Return &ret) {
    semantic.scopes.last().Current().didReturn = true;
    if(ret.expr)
        semantic.Visit(*ret.expr);
}
void Visit(Semantic& semantic, If &statement) {

    if(statement.condition) semantic.Visit(*statement.condition);
    if(statement.trueBody) semantic.Visit(*statement.trueBody);
    if(statement.falseBody) semantic.Visit(*statement.falseBody);

    if(statement.falseBody){
        semantic.scopes.last().Current().didReturn = statement.trueBody->didReturn && statement.falseBody->didReturn;
    }
    else{
        semantic.scopes.last().Current().didReturn = statement.trueBody->didReturn;
    }
}
void Visit(Semantic& semantic, For &loop) {
    semantic.Visit(*loop.from);
    if(loop.to && loop.from){
        semantic.Visit(*loop.to);
        auto it = new Variable;
        it->ident = loop.it;
        it->type = loop.from->type;
        loop.body->childrenAppended.Push(*it);
    }
    semantic.Visit(*loop.body);
    semantic.scopes.last().Current().didReturn |= loop.body->didReturn;
}
void Visit(Semantic& semantic, ConstString &str) {
    str.type = cast<Type>(Find(semantic, "str", str.coord));
    assert(str.type);
}
void Visit(Semantic& semantic, FuncIntrins &def) {
    if(!IsDeclared(def)){
        Declare(semantic, def);
    }
    
    if(RequiresAnnotating(def))
    {
        def.annotated = AnnotatedState::Annotating;
        AnnotateParam(semantic, def.results);
        AnnotateParam(semantic, def.params);
        def.annotated = AnnotatedState::Annotated;
        def.type = def.results.type;
        assert(def.results.type);
    }
}
void Visit(Semantic& semantic, StructIntrins &def) {
        def.typeinfo = new Variable;
        def.typeinfo->ident = "typeInfo" + def.ident;
        def.typeinfo->type = cast<Type>(Find(semantic, "TypeInfo", def.coord));
        assert(def.typeinfo->type);
        def.typeinfo->annotated = AnnotatedState::Annotated;

}

void Visit(Semantic& semantic, Type &def) {
    assert(false);
}

void Visit(Semantic& semantic, Directive &def) {
    assert(false);
}
void Visit(Semantic& semantic, Using& self) {
    semantic.Visit(*self.operand);
    semantic.scopes.last().Current().usings.Push(self);
}

void Semantic::Visit(Expr& node)
{   
    VISTOR(*this, node);
}

