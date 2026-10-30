#ifndef DIV_H
#define DIV_H
#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;
class DIV : public Tokens {
public:
    DIV(const string& value) : Tokens(value, TokenType::DIV) {}
};

#endif
