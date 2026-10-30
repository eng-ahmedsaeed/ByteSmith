#ifndef UNTIL_H
#define UNTIL_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class UNTIL : public Tokens {
public:
    UNTIL(const string& value) : Tokens(value, TokenType::UNTIL) {}
};

#endif
