#ifndef WRITE_H
#define WRITE_H

#include "Tokens.h"

using namespace std;
using namespace TokenLibrary;

class WRITE : public Tokens {
public:
    WRITE(const string& value) : Tokens(value, TokenType::WRITE) {}
};

#endif
