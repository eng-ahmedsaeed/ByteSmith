#ifndef READ_H
#define READ_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class READ : public Tokens {
public:
    READ(const string& value) : Tokens(value, TokenType::READ) {}
};

#endif
