#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Tokens {
public:
    static std::string TokenType;
    std::string TokenValue;

    void setTokenValue(const std::string& tokenValue);
    std::string getTokenValue() const;
    static std::string getTokenType();
};

#endif
