#ifndef REPEAT_H
#define REPEAT_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class REPEAT : public Tokens {
public:
    REPEAT(const string& value) : Tokens(value, TokenType::REPEAT) {}
};

#endif
