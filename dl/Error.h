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
    {}
    
    ParseError(const std::string &error):
    error(error)
    {}
    
    virtual const char* what() const throw() {
        return error.c_str();
    }
    void Print();
};

namespace Lexer
{
    enum Symbol
    {
        
        End = 0,
        Illegal,        // Doesn't match any of the following tokens
        
        BracketOpen,    // {
        BracketClose,   // }
        ParenOpen,      // (
        ParenClose,     // )

        // primary
        Identifier, // abc
        Number,     // 123.123
        String,     // "..."

        // Keywords
        Struct,     // struct
        Enum,       // enum

        Return,     // return
        Fn,         // fn
        Directive,  // @
        
        Type,       // type
        Cast,       // cast
        
        Const,      // const
        Ref,        // ref

        If,         // if
        Else,       // else
        For,        // for
        Comma,      // ,
        Any,        // ?
        Caret,      // ^
        Constrain,  // :
        Dot,        // .
        DotDot,     // ..

        // Operators
        OperatorsBegin,
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
