#ifndef PLUS_H
#define PLUS_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class PLUS : public Tokens {
public:
    PLUS(const string& value) : Tokens(value, TokenType::PLUS) {}
};

#endif
