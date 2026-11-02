#ifndef ELSE_H
#define ELSE_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class ELSE : public Tokens {
public:
    ELSE(const string& value) : Tokens(value, TokenType::ELSE) {}
};

#endif