//
//  Token.h
//  Created by David on 11/19/16.
//

#pragma once
#include "Symbol.h"

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
    string error;
    
    ParseError(const string &error, Coord line):
    line(line),
    error(error)
    {}
    
    ParseError(const string &error):
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
        BraceOpen,      // [
        BraceClose,     // ]
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
    
    string value;
};
