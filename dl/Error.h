//
//  Error.hpp
//  lan
//
//  Created by David on 5/21/16.
//  Copyright © 2016 David Leroy Futscher. All rights reserved.
//

#pragma once
#include <exception>
#include <string>
#include <vector>
#include <assert.h>

class Node;
class QualifiedType;

void Assert(bool cond, const Node &node, const std::string&str = "");
void Assert(bool cond, const QualifiedType &node, const std::string&str = "");
struct Blck;
struct FileDescription {
    std::string directory; //directory wrt the applications current working directory
    std::string name;
    int fileparent = -1;
    int file = -1;
    Blck* ast = nullptr;
};

extern std::vector<FileDescription> g_files;

struct Coord
{
    operator bool() const { return !(file == 0 && line == 0 && column == 0); }
    int file = 0;
    int line = 0;
    int column = 0;
};


struct ParseError: public std::exception
{
    Coord line;
    std::string error;
    
    ParseError(const std::string &error, Coord line):
    line(line),
    error(error)
    {
        
    }
    
    ParseError(const std::string &error):
    error(error)
    {}
    
    virtual const char* what() const throw()
    {
        return error.c_str();
    }
    
    void Print();
};

enum SyntaxError
{
    Other = 0,
    Undeclared,
    ExpectedIdentifier,
    CastError
};

struct Error
{
    static constexpr auto UnclosedExpression = "Expected ';' after expression";
    static constexpr auto UnclosedDefinition = "Expected ';' after Definition";
    static constexpr auto UnclosedBlock = "Expected '}' after block";
    
    static constexpr auto UnclosedStructure = "Expected '}' at end of structure";
    
    static constexpr auto ExpectedExpression = "Expected expression";
    static constexpr auto ExpectedIdentifier = "Expected identifier";

    static constexpr auto UnclosedFunctionCall = "Expected ')' to close function call";
    static constexpr auto UnclosedFunctionDefinition = "Expected ')' to close function definition";

    static constexpr auto UnopenedStructureDefinition = "Expected '{' after function Definition";
    static constexpr auto UnopenedFunctionDefinition = "Expected '{' after function Definition";

    static constexpr auto MissingReturnType = "Missing function return type";
    static constexpr auto UnknownSymbol = "Unknown symbol ";
};


namespace Lexer
{
    enum Symbol
    {
        
        End = 0,
        Illegal,
        
        BracketOpen,
        BracketClose,
        ParenOpen,
        ParenClose,

        // primary
        Identifier,
        Number,
        String,

        // Keywords
        Struct,
        Enum,

        Return,
        Fn,
        Directive,
        
        Type,
        Cast,
        
        Const,
        Ref,

        If,
        Else,
        For,
        Comma,

        OperatorsBegin,
        // Operators
        Less,       // < 
        LessEq,     // <=
        Greater,    // >
        GreaterEq,  // >=
        Equal,      // ==
        NotEqual,   // !=

        Assign,     // =
        Negated,    // !

        AndAnd,     // &&
        OrOr,       // ||
        And,        // &
        Or,         // |
        
        Add,        // +
        Sub,        // -
        Div,        // /
        Mul,        // *
        Mod,        // %
       
        Dot,        // .
        DotDot,     // ..
        Constrain,  // :
        Any,        // ?
        OperatorsEnd,

    };
}

struct Token
{
    bool Identifier() const {
        return type == Lexer::Identifier;
    }
    bool Operator() const {
        return type < Lexer::OperatorsEnd && type > Lexer::OperatorsBegin;
    } 
    bool Is(Lexer::Symbol type) const {
        return Token::type == type;
    }

    bool operator==(Lexer::Symbol type) const {
        return Is(type); 
    }
    bool operator!=(Lexer::Symbol type) const {
        return !Is(type); 
    }

    int type = 0;
    bool isFirst = false;
    
    Coord previous;
    Coord line;
    Coord lineEnd;
    
    std::string value;
};