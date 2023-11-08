#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class TokenType {
    NUMBER,
    OPERATOR,
    PARENTHESIS
};

// Token class to represent elements in mathematical expressions.
class Token {
private:
    TokenType type;
    string value;
    static int counter;

public:
    Token();
    Token(TokenType type, const std::string& value);
    Token(const Token& other);
    Token& operator=(const Token& other);
    ~Token();

    TokenType getType() const;
    void setType(TokenType newType);
    const string& getValue() const;
    void setValue(const std::string& newValue);
    static int getTokenCount();
    static int getPrecedence(const Token& token);
};