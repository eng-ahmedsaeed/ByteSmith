#ifndef MULT_H
#define MULT_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class MULT : public Tokens {
public:
    MULT(const string& value) : Tokens(value, TokenType::MULT) {}
};

#endif
