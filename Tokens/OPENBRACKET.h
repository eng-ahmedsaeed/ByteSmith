#ifndef OPENBRACKET_H
#define OPENBRACKET_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class OPENBRACKET : public Tokens {
public:
    OPENBRACKET(const string& value) : Tokens(value, TokenType::OPENBRACKET) {}
};

#endif
