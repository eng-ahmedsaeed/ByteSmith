#ifndef END_H
#define END_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;
class END : public Tokens {
public:
    END(const string& value) : Tokens(value, TokenType::END) {}
};

#endif
