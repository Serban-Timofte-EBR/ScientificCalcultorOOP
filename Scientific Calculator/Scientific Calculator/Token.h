#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class TokenType {
    NUMBER,
    OPERATOR,
    PARENTHESIS,
    UNKNOWN
};

class Token {
private:
    string value = "";
    TokenType type = TokenType::NUMBER;

    static int COUNTER;

public:
    Token();
    Token(string value, TokenType type);
    Token(const Token& t);
    ~Token();

    TokenType get_type();
    void set_type(TokenType type);

    string get_value();
    void set_value(string& value);
    void set_const_value(const string value);

    static int get_counter();
    static void set_increment_counter();
    static void set_decrement_counter();

    bool isOperator();
    int precedence();

    Token& operator=(const Token& t);

    friend void operator<<(ostream& console, Token& t);
    friend istream& operator>>(istream& console, Token& t);

    bool operator==(const Token& t);
    bool operator!=(const Token& t);
    bool operator!();
};