#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include <vector>
#include <stdexcept>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);

    void parse(); // Entry point for parsing

private:
    std::vector<Token> tokens;
    size_t current;

    const Token& peek() const;
    const Token& advance();
    bool match(TokenType type);
    void expect(TokenType type);

    void expr();
    void term();
    void factor();
};

#endif
