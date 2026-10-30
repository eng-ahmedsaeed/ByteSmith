#ifndef SCANNER_H
#define SCANNER_H

#include <queue>
#include "Token.h"
#include "String"
using namespace std;
class Scanner {
public:
    queue<Token> tokens;
    ifstream file ;
    string state; 
        // Constructor
    Token( ifstream file ) {
        this->file = file 
    }

    void Toknize (ifstream file)
    {
        char c;
        while (file.get(c))
        {
                switch (state)
                {
                    case 
                }


        }

    }
};

#endif
