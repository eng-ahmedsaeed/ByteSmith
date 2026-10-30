#ifndef LESSTHAN_H
#define LESSTHAN_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class LESSTHAN : public Tokens {
public:
    LESSTHAN(const string& value) : Tokens(value, TokenType::LESSTHAN) {}
};

#endif
