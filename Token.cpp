#include "Token.h"

std::string Token::TokenType = "";

void Token::setTokenValue(const std::string& tokenValue) {
    TokenValue = tokenValue;
}

std::string Token::getTokenValue() const {
    return TokenValue;
}

std::string Token::getTokenType() {
    return TokenType;
}
