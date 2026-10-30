#ifndef NUMBER_H
#define NUMBER_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class NUMBER : public Tokens {
public:
    NUMBER(const string& value) : Tokens(value, TokenType::NUMBER) {}
};

#endif
