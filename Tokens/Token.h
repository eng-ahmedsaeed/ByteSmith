#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

namespace TokenLibrary {

    enum class TokenType {
        IF,
        LESSTHAN,
        MINUS,
        MULT,
        NUMBER,
        OPENBRACKET,
        CLOSEDBRACKET,
        ASSIGN,
        PLUS,
        READ,
        REPEAT,
        SEMICOLON,
        THEN,
        UNTIL,
        WRITE,
        DIV,
        END,
        EQUAL,
        ELSE,
        IDENTIFIER
    };

}

#endif