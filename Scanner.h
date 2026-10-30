#ifndef SCANNER_H
#define SCANNER_H

#include <queue>
#include "Token.h"

class Scanner {
public:
    std::queue<Token> tokens;
};

#endif
