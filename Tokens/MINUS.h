#ifndef MINUS_H
#define MINUS_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class MINUS : public Tokens {
public:
    MINUS(const string& value) : Tokens(value, TokenType::MINUS) {}
};

#endif
