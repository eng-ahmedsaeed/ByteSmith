#ifndef THEN_H
#define THEN_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class THEN : public Tokens {
public:
    THEN(const string& value) : Tokens(value, TokenType::THEN) {}
};

#endif
