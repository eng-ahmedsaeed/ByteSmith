#ifndef CLOSEDBRACKET_H
#define CLOSEDBRACKET_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class CLOSEDBRACKET : public Tokens {
public:
    CLOSEDBRACKET(const string& value) : Tokens(value, TokenType::CLOSEDBRACKET) {}
};

#endif
