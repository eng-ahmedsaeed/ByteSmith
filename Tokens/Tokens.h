#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Token.h"

using namespace std;
using namespace TokenLibrary;

class Tokens {
public:
    TokenType tokenType;
    string tokenValue;

    Tokens(const string& value, TokenType type) : tokenType(type), tokenValue(value) {}

    Tokens() : tokenType(TokenType::IDENTIFIER) {}

    void setTokenValue(const std::string& value) {
        tokenValue = value;
    }

    string getTokenValue() const {
        return tokenValue;
    }

    TokenType getTokenType() const {
        return tokenType;
    }
};

#endif
