#ifndef IF_H
#define IF_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class IF : public Tokens {
public:
    IF(const string& value) : Tokens(value, TokenType::IF) {}
};

#endif
