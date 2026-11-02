#ifndef ASSIGN_H
#define ASSIGN_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class ASSIGN : public Tokens {
public:
    ASSIGN(const string& value) : Tokens(value, TokenType::ASSIGN) {}
};

#endif