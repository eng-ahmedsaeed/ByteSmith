#ifndef SEMICOLON_H
#define SEMICOLON_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class SEMICOLON : public Tokens {
public:
    SEMICOLON(const string& value) : Tokens(value, TokenType::SEMICOLON) {}
};

#endif
