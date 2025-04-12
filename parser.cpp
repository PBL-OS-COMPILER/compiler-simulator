#include "parser.h"
#include <iostream>

Parser::Parser(const std::vector<Token>& tokens)
    : tokens(tokens), current(0) {}

void Parser::parse() {
    expr();
    if (peek().type != TokenType::END) {
        throw std::runtime_error("Unexpected tokens after expression");
    }
}

const Token& Parser::peek() const {
    if (current < tokens.size())
        return tokens[current];
    static Token endToken = {TokenType::END, ""};
    return endToken;
}

const Token& Parser::advance() {
    if (current < tokens.size())
        return tokens[current++];
    static Token endToken = {TokenType::END, ""};
    return endToken;
}

bool Parser::match(TokenType type) {
    if (peek().type == type) {
        advance();
        return true;
    }
    return false;
}

void Parser::expect(TokenType type) {
    if (!match(type)) {
        throw std::runtime_error("Unexpected token: expected different type");
    }
}

void Parser::expr() {
    term();
    while (match(TokenType::PLUS) || match(TokenType::MINUS)) {
        term();
    }
}

void Parser::term() {
    factor();
    while (match(TokenType::MUL) || match(TokenType::DIV)) {
        factor();
    }
}

void Parser::factor() {
    if (match(TokenType::NUMBER)) {
        // Valid number
    } else if (match(TokenType::LPAREN)) {
        expr();
        expect(TokenType::RPAREN);
    } else {
        throw std::runtime_error("Expected number or '('");
    }
}
