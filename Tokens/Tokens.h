#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Token.h"

using namespace std;
using namespace TokenLibrary;

class Tokens {
public:
    static TokenType tokenType;
    static string tokenValue;

    Tokens(string value, TokenType type) {
        tokenType = type;
        tokenValue = value;
    }

    Tokens() {

    }
    void setTokenValue(const std::string& tokenValue) {
        Tokens::tokenValue = tokenValue;
    }
    string getTokenValue() {
        return tokenValue;
    }
    static TokenType getTokenType() {
        return tokenType;
    }
};

#endif
