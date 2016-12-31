//
//  Printing.cpp
//  Created by David on 6/30/16.
//

#include "Printing.h"
#include <cxxabi.h>

string DemangleCppAbi(const char* abiName)
{
    string retval;
    int status;
    char *ret = abi::__cxa_demangle(abiName, 0, 0, &status);
    retval = string(ret);
    free(ret);
    return retval;
}

void Indent(AstPrint& visitor)
{
    for(int i = 1; i < visitor.indent; i++)
        Print("\t");
}

void Visit(AstPrint& visitor, Call& self)
{
    visitor.Visit(*self.operand);
    visitor.Visit(*self.params);
}
void Visit(AstPrint& visitor, Binary& self)
{}
void Visit(AstPrint& visitor, Unary& self)
{}
void Visit(AstPrint& visitor, Access& self)
{}
void Visit(AstPrint& visitor, For& self)
{}
void Visit(AstPrint& visitor, If& self)
{}
void Visit(AstPrint& visitor, Blck& self)
{
    visitor.indent++;
    for (int i =0; i < self.childrenAppended.length; i++) {
        visitor.Visit(self.childrenAppended[i]);
    }
    for (int i =0; i < self.children.length; i++) {
        visitor.Visit(self.children[i]);
    }
    visitor.indent--;
}
void Visit(AstPrint& visitor, Enum& self)
{}
void Visit(AstPrint& visitor, Func& self)
{}
void Visit(AstPrint& visitor, Struct& self)
{
    Indent(visitor); Print(self.ident, " ", "struct ");
    if (self.constraints.size()) {
        Print("(");
        for (int i = 0; i < self.constraints.size() - 1; i++) {
            Print(*self.constraints[i], ", ");
        }
        Print(*self.constraints.back(), ")");
    }
    if(!self.incomplete)
    {
        Print(self.constraints.size() ? " {\n" : "{\n");
        visitor.indent++;
        for (auto field : self.fields) {
            visitor.Visit(*field);
        }
        visitor.indent--;
        Indent(visitor); Print("}\n");
    }
    else
    {
        Print("\n");
    }
}
void Visit(AstPrint& visitor, StructIntrins& self)
{}
void Visit(AstPrint& visitor, FuncIntrins& self)
{}
void Visit(AstPrint& visitor, ExprList& self)
{}
void Visit(AstPrint& visitor, Directive& self)
{}
void Visit(AstPrint& visitor, Return& self)
{}
void Visit(AstPrint& visitor, CastExpr& self)
{}
void Visit(AstPrint& visitor, ConstNumber& self)
{
    Print(self.value);
}
void Visit(AstPrint& visitor, ConstString& self)
{
    Print(self.value);
}
void Visit(AstPrint& visitor, Variable& self)
{
    Indent(visitor); Print(self.ident, " "); visitor.Visit(*self.type);
    if(self.assign)
    {
        Print(" = "); visitor.Visit(*self.assign);
    }
    Print("\n");
}
void Visit(AstPrint& visitor, Var& self)
{
    Print(self.name);
}
void Visit(AstPrint& visitor, Type& self)
{
    Print(self);
}

void AstPrint::Visit(Expr& node)
{
    VISTOR(*this, node);
}
