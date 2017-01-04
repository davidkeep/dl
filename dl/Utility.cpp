//
//  Utility.cpp
//  Created by David on 12/18/16.
//

#include "Utility.h"
#include "Ast.h"

void Visit(CopyVisitor& visitor, Call& self)
{
    auto &out = Create<Call>(self.coord);
    out.coord = self.coord;
    out.operand = Copy(self.operand);
    out.params = Copy(self.params);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Binary& self)
{
    auto &out = Create<Binary>(self.coord);
    out.op = self.op;
    out.left = Copy(self.left);
    out.right = Copy(self.right);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Unary& self)
{
    auto &out = Create<Unary>(self.coord);
    out.op = self.op;
    out.expr = Copy(self.expr);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Access& self)
{
    auto &out = Create<Access>(self.coord);
    out.operand = Copy(self.operand);
    out.field = self.field;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, For& self)
{
    auto &out = Create<For>(self.coord);
    out.it = self.it;
    out.from = Copy(self.from);
    out.to = Copy(self.to);
    out.body = Copy(self.body);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, If& self)
{
    auto &out = Create<If>(self.coord);
    out.condition = Copy(self.condition);
    out.trueBody = Copy(self.trueBody);
    out.falseBody = Copy(self.falseBody);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Blck& self)
{
    auto &out = Create<Blck>(self.coord);
    out.didReturn = self.didReturn;
    out.childrenAppended = Copy(self.childrenAppended);
    out.children = Copy(self.children);
    out.includes = Copy(self.includes);
    out.variables = self.variables;
    for(auto& element : out.variables){
        element.second = ::Copy(element.second);
    }
    out.functions = self.functions;
    for(auto& element : out.functions){
        element.second = ::Copy(element.second);
    }
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Enum& self)
{
    auto &out = Create<Enum>(self.coord);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Func& self)
{
    auto &out = Create<Func>(self.coord);
    out.external = self.external;
    out.generic = self.generic;
    out.unknown = self.unknown;
    out.body = Copy(self.body);

    for (int i = 0; i < self.results.list.length; i++){
        out.results.list.Push({self.results.list[i].ident, Copy(self.results.list[i].dec)});
    }
    for (int i = 0; i < self.params.list.length; i++){
        out.params.list.Push({self.params.list[i].ident, Copy(self.params.list[i].dec)});
    }
    for(auto &item : out.unknown){
        item.second = Copy(item.second);
    }

    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Struct& self)
{
    auto &out = Create<Struct>(self.coord);
    out.fields = ::Copy(self.fields);
    out.constraints = ::Copy(self.constraints);
    out.generic = self.generic;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, StructIntrins& self)
{
    assert(false);
}
void Visit(CopyVisitor& visitor, FuncIntrins& self)
{
    assert(false);
}
void Visit(CopyVisitor& visitor, ExprList& self)
{
    auto &out = Create<ExprList>(self.coord);
    out.list = Copy(self.list);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Directive& self)
{
    assert(false);
}
void Visit(CopyVisitor& visitor, Return& self)
{
    auto &out = Create<Return>(self.coord);
    out.expr = Copy(self.expr);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, CastExpr& self)
{
    auto &out = Create<CastExpr>(self.coord);
    out.expr = Copy(self.expr);
    out.type = Copy(self.type);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, ConstNumber& self)
{
    auto &out = Create<ConstNumber>(self.coord);
    out.value = self.value;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, ConstString& self)
{
    auto &out = Create<ConstString>(self.coord);
    out.value = self.value;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeArray& self)
{
    auto &out = Create<TypeArray>(self.coord);
    out.type = Copy(self.type);
    out.ref = self.ref;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeVar& self)
{
    auto &out = Create<TypeVar>(self.coord);
    out.ident = self.ident;
    out.ref = self.ref;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeType& self)
{
    auto &out = Create<TypeType>(self.coord);
    out.type = Copy(self.type);
    out.ref = self.ref;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypePtr& self)
{
    auto &out = Create<TypePtr>(self.coord);
    out.pointed = Copy(self.pointed);
    out.ref = self.ref;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeFn& self)
{
    auto &out = Create<TypeFn>(self.coord);
    out.ref = self.ref;
    out.params.list.Reserve(self.params.list.capacity);
    out.results.list.Reserve(self.results.list.capacity);

    for (int i = 0; i < self.params.list.length; i++){
        out.params.list.Push({self.params.list[i].ident, Copy(self.params.list[i].dec)});
    }
    for (int i = 0; i < self.results.list.length; i++){
        out.results.list.Push({self.results.list[i].ident, Copy(self.results.list[i].dec)});
    }
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeFns& self)
{
    assert(false);
}
void Visit(CopyVisitor& visitor, TypeGen& self)
{
    auto &out = Create<TypeGen>(self.coord);
    out.ref = self.ref;
    out.generic = nullptr;
    out.type = Copy(self.type);
    out.typeGeneric = Copy(self.typeGeneric);
    out.constraints = self.constraints;
    for(auto &item : out.constraints){
        item = Copy(item);
    }
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeAny& self)
{
    auto &out = Create<TypeAny>(self.coord);
    out.ref = self.ref;
    out.type = Copy(self.type);
    out.ident = self.ident;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, TypeList& self)
{
    auto &out = Create<TypeList>(self.coord);
    out.ref = self.ref;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Var& self)
{
    auto &out = Create<Var>(self.coord);
    out.name = self.name;
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Variable& self)
{
    auto &out = Create<Variable>(self.coord);
    out.ref = self.ref;
    out.ident = self.ident;
    out.type = Copy(self.type);
    out.assign = Copy(self.assign);
    visitor.value = &out;
}
void Visit(CopyVisitor& visitor, Using& self)
{
    auto &out = Create<Using>(self.coord);
    out.as = self.as;
    out.operand = Copy(self.operand);
    visitor.value = &out;
}
void CopyVisitor::Visit(Expr& node)
{
    VISTOR(*this, node);
}

