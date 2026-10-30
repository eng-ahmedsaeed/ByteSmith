#ifndef SCANNER_H
#define SCANNER_H

#include <queue>
#include <fstream>
#include <string>
#include "Tokens/Token.h"
#include "Tokens/Tokens.h"
#include <bits/basic_string.h>
using TokenLibrary::TokenType;
using namespace std;

class Scanner {
public:
    queue<Tokens> tokens;
    ifstream file;
     TokenType state;

    // Constructor
    Scanner(ifstream& file) : file(file) {}

    void Toknize(ifstream& file)
    {
        state =START;
        char c;
        string st;
        while (file.get(c))
        {
            switch(state){
                case START:break;
                if(c == '{')
                state=INCOMMENT;
                else if(c == ':')
                state = INASIGN;
                case INCOMMENT:break;
                case INNUM:break;
                case INID:break;
                case INASSIGN:break;
                case DONE:
                Tokens token ;
                token.setTokenValue(st);
                 tokens.push(token);
                break;

            }
        }
    }
};

#endif
