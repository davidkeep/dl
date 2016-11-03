//
//  Annotate.h
//  Created by David on 7/2/16.
//

#pragma once

//
//  CodeGenerator.h
//  Created by David on 6/23/16.
//

#pragma once
#include "SyntaxTree.h"
#include "Definitions.h"
#include "Control.h"
#include "Constants.h"
#include "Operator.h"

class Annotate : public Visitor
{
public:
    Visitor &visitor;
    Annotate():
    visitor(*this)
    {}
    
    void Accept(Block &self) override
    {
        if(!self.ignoreRet)
            self.type = self.parent->type;
        
        if(self.toplevel || self.structure){
            for (auto i = 0; i < self.nodes.size(); i++){
                Node*node = self.nodes[i];
                if(dynamic_cast<StructureDefinition*>(node) || dynamic_cast<VariableDefinition*>(node) || dynamic_cast<Enum*>(node))
                    node->Visit(visitor);
            }
            for (auto i = 0; i < self.nodes.size(); i++){
                Node*node = self.nodes[i];
                if(!(dynamic_cast<StructureDefinition*>(node) || dynamic_cast<VariableDefinition*>(node) || dynamic_cast<Enum
                     *>(node)))
                    node->Visit(visitor);
            }
        }
        else {
            for (auto i = 0; i < self.nodes.size(); i++){
                Node*node = self.nodes[i];
                node->Visit(visitor);
            }
        }
    }
    

    void Accept(CallOperator &self) override
    {
        vector<QualifiedType> types;
        for(auto i : self.arguments){
            i->Visit(visitor);
            types.push_back(i->type);
            assert(i->type.type);
        }
        self.operand->Visit(*this);
        
        Procedure procedure;
        procedure.args = types;
        QualifiedType type;
        TypeFunction f;
        f.procedure = &procedure;
        type.type = &f;
        
        if(!self.operand->Coerce(visitor, type))
        {
            printf("found-----------------------------\n");
            printf("%s\n", ToString(self.operand->type).c_str());
            printf("-----------------------------\n");
            Print(procedure);
            printf("\n");
            
            throw ParseError ("Hm.... ", self.operand->source);
        }
            
        if(auto fn = Is<TypeFunction>(self.operand->type.type))
        {
            self.type = fn->procedure->ret;
            int j = 0;
            for(auto i : self.arguments){
                i->Coerce(visitor, fn->procedure->args[j]);
                j++;
            }
        }
        else
        {
            throw ParseError ("Operand is not callable " + ToString(self.operand->type), self.operand->source);
        }
    }
    void Accept(If &self) override
    {
        self.VisitChildren(visitor);
    }
    void Accept(For &self) override
    {
        self.VisitChildren(visitor);
    }
    void Accept(ConstantNumber &self) override
    {
        self.type = self.parent->FindType("number");
        assert(self.type.type);

    }
    void Accept(ConstantString &self) override
    {
        self.type = self.parent->FindType("String");
        assert(self.type.type);
    }
    
    //@TODO refactor this shit
    void Accept(BinaryOperator &self) override
    {
        self.LHS->Visit(visitor);
        if(self.Operator::kind == Operator::Dot)
        {
            TypeMulti *multi = Is<TypeMulti>(self.LHS->type.type);
            
            if(multi)
            if(TypeEnum* Enum = Is<TypeEnum>(multi->type.type)){
            
                self.LHS->type = multi->type;
                Variable *field = dynamic_cast<Variable*>(self.RHS);
                if(!field)
                {
                    throw ParseError(std::string("Expected field name following '.'"), self.source);
                }
                
                auto value = Enum->enumerated->GetField(field->name);
                if(!value)
                    throw ParseError(std::string("No field '") +field->name + "' on type " + ToString(*Enum), self.source);
                    
                self.type = value->type;
                self.type.mut = self.LHS->type.mut;
                return;
                return;
            }

            TypePointer *pointer = Is<TypePointer>(self.LHS->type.type);
            
            TypeRecord *record = pointer ? Is<TypeRecord>(pointer->pointed.type) : Is<TypeRecord>(self.LHS->type.type);
            if(!record)
            {
                throw ParseError(std::string("Type is not a structure or a pointer to a structure"), self.source);
            }
            
            Variable *field = dynamic_cast<Variable*>(self.RHS);
            if(!field)
            {
                throw ParseError(std::string("Expected field name following '.'"), self.source);
            }
            if(pointer)
            {
            
            }
            auto definition = record->structure->block.FindVariable(field->name);
            field->definition = definition;
            if(!definition){
                throw ParseError(std::string("No field '") +field->name + "' on type " + ToString(*record), self.source);
            }
           // assert(!definition->typeInfo.structure->generic);
            //@TODO Check mut?
//            field->type = definition->type;
//            field->type.mut = self.LHS->type.mut;
//            assert(field->type.type);
//            field->definition = definition;
            self.type = definition->type;
//            assert(!self.type.mut);
//            assert(!self.type.re);            
            self.type.mut = self.LHS->type.mut;
            return;
        }
        else
        {
            self.RHS->Visit(visitor);
        }
        
        
        if(self.Operator::kind == Operator::ArrayOperator)
        {
            std::vector<Expression*> Args = {self.LHS, self.RHS};
            self.function = new CallOperator(new Variable("opArray", self.source), Args, self.source);
            self.function->Scope(self.parent);
        }
        if(self.Operator::kind == Operator::Addition)
        {
            if(Is<TypePointer>(self.LHS->type.type))
            {
                self.pointerArith = true;
            }
            else
            {
                std::vector<Expression*> Args = {self.LHS, self.RHS};
                self.function = new CallOperator(new Variable("add", self.source), Args, self.source);
                self.function->Scope(self.parent);
            }
        }
        if(self.Operator::kind == Operator::Subtraction)
        {
            if(Is<TypePointer>(self.LHS->type.type))
            {
                self.pointerArith = true;
            }
            else
            {
                std::vector<Expression*> Args = {self.LHS, self.RHS};
                self.function = new CallOperator(new Variable("sub", self.source), Args, self.source);
                self.function->Scope(self.parent);
            }
        }
        if(self.Operator::kind == Operator::Division)
        {
            if(Is<TypePointer>(self.LHS->type.type))
            {
                self.pointerArith = true;
            }
            else
            {
                std::vector<Expression*> Args = {self.LHS, self.RHS};
                self.function = new CallOperator(new Variable("div", self.source), Args, self.source);
                self.function->Scope(self.parent);
            }
        }
        if(self.Operator::kind == Operator::Multiplication)
        {
            if(Is<TypePointer>(self.LHS->type.type))
            {
                self.pointerArith = true;
            }
            else
            {
                std::vector<Expression*> Args = {self.LHS, self.RHS};
                self.function = new CallOperator(new Variable("mul", self.source), Args, self.source);
                self.function->Scope(self.parent);
            }
        }
        
        self.type = self.RHS->type;

        if(self.function)
        {
            self.function->Visit(visitor);
            self.type = self.function->type;
        }
        
        
        
        if(self.Operator::kind == Operator::Assignment)
        {
            if(auto var = dynamic_cast<Variable*>(self.RHS))
            {
                if(!var->Coerce(visitor, self.LHS->type))
                {
                    throw ParseError("Cannot assign '" + ToString(self.RHS->type) + "' to '" + ToString(self.LHS->type) + "'", self.source);
                }
               

            }
            if(!self.LHS->type.mut)
                throw ParseError(std::string("Cannot assign to non mutable type  '" + ToString(self.LHS->type)) + "'", self.LHS->source);
                
            TypePointer *ll = Is<TypePointer>(self.LHS->type.type);
            TypePointer *rr = Is<TypePointer>(self.RHS->type.type);
                
            while(ll && rr)
            {
    
                if(ll->pointed.mut && !rr->pointed.mut)
                {
                    throw ParseError(std::string("Cannot introduce mutability to non mutable type '" + ToString(self.RHS->type)) + "'", self.LHS->source);
                }
                ll = Is<TypePointer>(ll->pointed.type);
                rr = Is<TypePointer>(rr->pointed.type);
            }
            

            TypeCheck(*self.LHS, *self.RHS);
            self.type = self.LHS->type;
            
        }

        if(self.pointerArith)
        {
            self.type = self.LHS->type;
        }
        
        assert(self.type.Concrete());
    }
    void Accept(UnaryOperator &self) override
    {
        self.operand->Visit(visitor);
        assert(Operator::Arguments::Unary);
        
        if(self.Operator::kind == Operator::PointerOperator){

            TypePointer *pointer = Is<TypePointer>(self.operand->type.type);
            if(!pointer){
                throw ParseError("Operand is not a pointer", self.source);
            }
            
            self.type = pointer->pointed;
            self.type.ref = true;
        }
        else if(self.Operator::kind == Operator::AddressOperator){
            self.type = self.operand->type;
            
            auto ptr = new TypePointer();
            ptr->pointed = self.type;
            self.type.type = ptr;
            self.type.mut = true;
            self.type.ref = false;
        }
        else if(self.Operator::kind == Operator::Negated){
            self.type = self.operand->type;
        }
        else{
            self.type = self.operand->type;
        }
    }
    void Accept(CastNode &self) override
    {
        self.type.Annotate(*self.parent);
        assert(self.type.isComplete);
        self.Expression::type = self.type.type;

        self.expression->Visit(visitor);
    }
    void Accept(TypeNode &self) override
    {
        self.procedure = self.parent->FindVariable("TypeInfo");
        self.procedure = Is<TypeMulti>(self.procedure->type.type)->functions.front()->function->variable;
        assert(self.procedure);
        self.type.Annotate(*self.parent);
        
        auto fn = Is<TypeFunction>(self.procedure->type.type);
        self.Expression::type = fn->procedure->ret;
    }
    void Accept(Return &self) override
    {
        if(self.value){
            self.value->Visit(visitor);
            TypeCheck(*self.parent, *self.value);
            if(!self.value->type.ref && self.value->type.IsStackMemory() && self.parent->type.ref){
                throw ParseError("Attempting to return a local variable '"+ ToString(self.value->type) +"', return type must be a value type (did you mean 'val type'?", self.source);
            }
        }
    }
    void Accept(Variable &self) override
    {
        self.definition = self.parent->FindVariable(self.name);
        if(!self.definition){
            throw ParseError(std::string("Undeclared symbol '") +self.name + "'", self.source);
        }
        self.type = self.definition->type;
    }
    void Accept(Enum &self) override
    {
        int current = 0;
        for (auto &field : self.fields) {
            if(field.value){
                current = atoi(field.value->value.c_str()) + 1;
            }
            else{
                field.value = new ConstantNumber(std::to_string(current), self.source);
                current++;
            }
        }
        for (const auto &field : self.fields){
            assert(field.value);
        }
        QualifiedType type;
        type.type = &self;
        self.parent->DeclareType(self.name, type);
    }

    void Accept(FieldAccess &self) override
    {
    }
    void Accept(VariableDefinition &self) override
    {
        self.Declare();
        if(self.assignment && self.assignment != &VariableDefinition::Sentinel){
            self.assignment->Visit(visitor);
            TypeCheck(self, *self.assignment);
            if(!self.parent->toplevel && !self.assignment->type.ref)
            {
                self.type.ref = false;
                self.type.mut = true;
                self.type.AddStackMemory();
            }
            
        }
        else if(self.assignment != &VariableDefinition::Sentinel)
        {
            self.type.AddStackMemory();
            self.type.ref = false;
            self.type.mut = true;
        }
        if(self.type.ref && !self.assignment)
            throw ParseError("Reference type must be initalized", self.source);
    }
    void Accept(StructureDefinition &self) override
    {
        if(self.generic)
            return;
        
        for(auto field : self.fields)
        {
            assert(!field->declared);
            field->Visit(visitor);
        }
    }
    void Accept(FunctionDefinition &self) override
    {
        self.Declare();
        
        if(self.generic){
            self.mangled += "g";
            return;
        }
        
        self.ret.Annotate(self.outerBlock);
        
        for(auto &v : self.arguments)
        {
            assert(v.isComplete && v.isAnnotated);
        }
        for(auto v : self.args)
        {
            assert(v->type.Concrete());
        }

        if(self.ret.typeName != "")
        {
            self.ret.Annotate(self.outerBlock);
            
            if(!self.ret.type.type)
            {
                throw ParseError(Error::UnknownSymbol + self.ret.typeName, self.source);
            }            
        }
        
        self.procedure.ret = self.ret.type;
        self.outerBlock.type = self.ret.type;
        self.outerBlock.ignoreRet = true;
        self.outerBlock.Visit(*this);
        if(self.innerBlock){
            assert(self.outerBlock.type.type == self.innerBlock->type.type);
        }
    }
};