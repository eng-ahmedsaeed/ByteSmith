#ifndef SCANNER_H
#define SCANNER_H
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <fstream>
#include <string>
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
    bool hasError;

    // Constructor
    Scanner(ifstream &infile, ofstream &outfile) : infile(infile), outfile(outfile), hasError(false) {
        Tokenize();
        TokenizeExport();
    }

public:
    bool encounteredError() const
    {
        return hasError;
    }

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

            outfile << token.tokenValue << " , " << tokenTypeToString(token.tokenType) << '\n';
        }

        if (hasError)
            outfile << "Error: undefined\nWrong syntax\n";
    }

private:
    bool addIdentifierToken(const string& identifier)
    {
        string keyword = toLowerCase(identifier);
        if (identifier != keyword)
        {
            hasError = true;
            return false;
        }

        if (keyword == "if")
            tokens.push(IF(identifier));
        else if (keyword == "then")
            tokens.push(THEN(identifier));
        else if (keyword == "end")
            tokens.push(END(identifier));
        else if (keyword == "repeat")
            tokens.push(REPEAT(identifier));
        else if (keyword == "until")
            tokens.push(UNTIL(identifier));
        else if (keyword == "read")
            tokens.push(READ(identifier));
        else if (keyword == "write")
            tokens.push(WRITE(identifier));
        else if (keyword == "else")
            tokens.push(ELSE(identifier));
        else
            tokens.push(IDENTIFIER(identifier));

        return true;
    }

private:
    void Tokenize()
    {
        state = STATE::START;
        char c;
        string st;
        while (true)
        {
            // if (state == STATE::DONE)
            // {
            //     const Tokens& token = tokens.back();
            //     cout << "Scanner identified token: " << token.tokenValue
            //          << ", type: " << tokenTypeToString(token.tokenType) << '\n';
            //     state = STATE::START;
            //     continue;
            // }

            if (!infile.get(c))
            {
                if (state == STATE::INNUM)
                {
                    tokens.push(NUMBER(st));
                    st.clear();
                    state = STATE::DONE;
                    continue;
                }
                if (state == STATE::INID)
                {
                    if (!addIdentifierToken(st))
                        return;
                    st.clear();
                    state = STATE::DONE;
                    continue;
                }
                break;
            }

            switch (state)
            {
            case STATE::START:
                if (c == '{')
                    state = STATE::INCOMMENT;
                else if (c == ':')
                    state = STATE::INASSIGN;
                else if (isspace(static_cast<unsigned char>(c)))
                    break;
                else if (isdigit(static_cast<unsigned char>(c)))
                {
                    st = c;
                    state = STATE::INNUM;
                }
                else if (isalpha(static_cast<unsigned char>(c)))
                {
                    state = STATE::INID;
                    st = c;
                }
                else if (c == ';')
                {
                    tokens.push(SEMICOLON(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '<')
                {
                    tokens.push(LESSTHAN(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '=')
                {
                    tokens.push(EQUAL(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '+')
                {
                    tokens.push(PLUS(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '-')
                {
                    tokens.push(MINUS(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '*')
                {
                    tokens.push(MULT(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '/')
                {
                    tokens.push(DIV(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == '(')
                {
                    tokens.push(OPENBRACKET(string(1, c)));
                    state = STATE::DONE;
                }
                else if (c == ')')
                {
                    tokens.push(CLOSEDBRACKET(string(1, c)));
                    state = STATE::DONE;
                }

            
                break;
            case STATE::INCOMMENT:
                if (c == '}')
                    state = STATE::START;
                break;
            case STATE::INNUM:
                if (isdigit(static_cast<unsigned char>(c)))
                    st += c;
                else
                {
                    tokens.push(NUMBER(st));
                    st.clear();
                    infile.unget();
                    state = STATE::DONE;
                }
                break;
            case STATE::INID:
                if (isalpha(static_cast<unsigned char>(c)))
                    st += c;
                else
                {
                    if (!addIdentifierToken(st))
                        return;
                    st.clear();
                    infile.unget();
                    state = STATE::DONE;
                }
                break;
            case STATE::INASSIGN:
                if (c == '=')
                {
                    tokens.push(ASSIGN(":="));
                    state = STATE::DONE;
                }
                else
                {
                    infile.unget();
                    state = STATE::DONE;
                }
                break;
            case STATE::DONE:
            infile.unget();
            cout<<"=================================================="<<endl;
            cout<<"The scanner had identified a token  [ token type:  = "<<tokenTypeToString(tokens.back().tokenType)<<" token value: "<<tokens.back().tokenValue<<" ]"<<endl;
            
                    state= STATE::START;
                break;
            }
        }
    }
};

#endif
