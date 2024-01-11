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
    Parser();
    Parser(const string& expr);
    Parser(const Parser& other);
    ~Parser();

    Parser& operator=(const Parser& other);

    void parse();
    Token* getTokens() const;
    int getTokenCount() const;

    string get_expression();
    void set_expression(const string& expr);

    int get_tokenCount();
    void set_tokenCount(int count);

    int get_capacity();
    void set_capacity(int cap);

    friend ostream& operator<<(ostream& cons, const Parser& parser);
    friend istream& operator>>(istream& cons, Parser& parser);

    Token& operator[](int index);
    explicit operator string();
};