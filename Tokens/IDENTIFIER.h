#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;
class IDENTIFIER : public Tokens {
public:
    IDENTIFIER(const string& value) : Tokens(value, TokenType::IDENTIFIER) {}
};

#endif
