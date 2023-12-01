#pragma once
#include "Token.h"
#include <string>
#include <iostream>

using namespace std;

class Parser {
private:
    string expression;
    Token* tokens;
    int tokenCount;
    int capacity;

    void resize();
    void addToken(const string& value, TokenType type);
    bool isOperator(char c);
    bool isNumber(char c);

public:
    Parser(const string& expr);
    Parser(const Parser& other);
    ~Parser();

    Parser& operator=(const Parser& other);

    void parse();
    Token* getTokens() const;
    int getTokenCount() const;
};
