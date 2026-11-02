#ifndef SCANNER_H
#define SCANNER_H
#include <algorithm>
#include <cctype>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <bits/basic_string.h>
#include "States.h"
#include "Common.h"
using TokenLibrary::TokenType;
using namespace std;
using namespace STATES;

class Scanner
{
public:
    queue<Tokens> tokens;
    ifstream &infile;
    ofstream &outfile;
    STATE state;

    // Constructor
    Scanner(ifstream &infile, ofstream &outfile) : infile(infile), outfile(outfile) {
        Tokenize();
        TokenizeExport();
    }

public:
    Tokens getToken()
    {
        return tokens.back();
    }

private:
    string toLowerCase(string st)
    {
        transform(st.begin(), st.end(), st.begin(),
                  [](unsigned char c)
                  {
                      return tolower(c);
                  });

        return st;
    }

private:
    string tokenTypeToString(TokenType type)
    {
        switch (type)
        {
        case TokenType::IF:
            return "IF";
        case TokenType::LESSTHAN:
            return "LESSTHAN";
        case TokenType::MINUS:
            return "MINUS";
        case TokenType::MULT:
            return "MULT";
        case TokenType::NUMBER:
            return "NUMBER";
        case TokenType::OPENBRACKET:
            return "OPENBRACKET";
        case TokenType::CLOSEDBRACKET:
            return "CLOSEDBRACKET";
        case TokenType::ASSIGN:
            return "ASSIGN";
        case TokenType::PLUS:
            return "PLUS";
        case TokenType::READ:
            return "READ";
        case TokenType::REPEAT:
            return "REPEAT";
        case TokenType::SEMICOLON:
            return "SEMICOLON";
        case TokenType::THEN:
            return "THEN";
        case TokenType::UNTIL:
            return "UNTIL";
        case TokenType::WRITE:
            return "WRITE";
        case TokenType::DIV:
            return "DIV";
        case TokenType::END:
            return "END";
        case TokenType::EQUAL:
            return "EQUAL";
        case TokenType::ELSE:
            return "ELSE";
        case TokenType::IDENTIFIER:
            return "IDENTIFIER";
        default:
            return "UNKNOWN";
        }
    }

private:
    void TokenizeExport()
    {
        queue<Tokens> temp = tokens;
        while (!temp.empty())
        {
            Tokens token = temp.front();
            temp.pop();

            outfile << token.tokenValue << "," << tokenTypeToString(token.tokenType)+"\n";   
        }
    }

private:
    void Tokenize()
    {
        state = STATE::START;
        char c;
        string st;
        while (infile.get(c))

        {
            switch (state)
            {
                //! Start
            case STATE::START:
                if (c == '{')
                    state = STATE::INCOMMENT;
                else if (c == ':')
                    state = STATE::INASSIGN;
                else if (c == ' ')
                    state = STATE::START;
                else if (isdigit(c))
                    state = STATE::INNUM;
                else if (isalpha(c))
                {
                    state = STATE::INID;
                    st += c;
                }
                else if (c == ';')
                {
                    SEMICOLON token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }
                else if (c == '<')
                {
                    LESSTHAN token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }
                else if (c == '=')
                {
                    EQUAL token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }
                else if (c == '+')
                {
                    PLUS token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }

                else if (c == '*')
                {
                    MULT token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }

                else if (c == '/')
                {
                    DIV token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }

                else if (c == '(')
                {
                    OPENBRACKET token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }

                else if (c == ')')
                {
                    CLOSEDBRACKET token(string(1, c));
                    tokens.push(token);
                    state = STATE::DONE;
                }
                break;
            //! INCOMMENT
            case STATE::INCOMMENT:
                if (c == '}')
                    state = STATE::START;
                else
                    state = STATE::INCOMMENT;
                break;

                //! INNUM state
            case STATE::INNUM:
                if (isdigit(c))
                {
                    st += c;
                    state = STATE::INNUM;
                }
                else
                {
                    NUMBER token(st);
                    tokens.push(token);
                    state = STATE::DONE;
                }

                break;

                //! INID

            case STATE::INID:
                if (isalpha(c))
                {
                    st += c;
                    state = STATE::INID;
                }
                else
                {
                    state = STATE::DONE;
                    string keyword = toLowerCase(st);
                    if (keyword == "if")
                    {
                        IF token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "then")
                    {
                        THEN token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "end")
                    {
                        END token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "repeat")
                    {
                        REPEAT token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "until")
                    {
                        UNTIL token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "read")
                    {
                        READ token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "write")
                    {
                        WRITE token(st);
                        tokens.push(token);
                    }
                    else if (keyword == "else")
                    {
                        ELSE token(st);
                        tokens.push(token);
                    }

                    else
                    {
                        IDENTIFIER token(st);
                        tokens.push(token);
                    }
                }

                break;

                //! INASSIGN
            case STATE::INASSIGN:
                if (c == '=')
                {
                    ASSIGN token(":=");
                    tokens.push(token);
                    state = STATE::DONE;
                }
                else
                {
                    state = STATE::DONE;
                }
                break;
            case STATE::DONE:
                printf("Scanner detected token of =%s", tokens.front().tokenType);
                printf("Scanner detected token=%s", tokens.front().tokenValue);
                state = STATE::START;
                st = "";
                break;
            }
        }
    }
};

#endif
