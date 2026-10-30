#ifndef EQUAL_H
#define EQUAL_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;
class EQUAL : public Tokens {
public:
    EQUAL(const string& value) : Tokens(value, TokenType::EQUAL) {}
};

#endif
