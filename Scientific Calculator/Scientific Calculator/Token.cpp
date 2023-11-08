#include "Token.h"
#include <iostream>
using namespace std;

int Token::counter = 0;

Token::Token() : type(TokenType::NUMBER), value("0") {
    counter++;
}

Token::Token(TokenType type, const string& val) : type(type), value(val) {
    counter++;
}

Token::Token(const Token& other) : type(other.type), value(other.value) {
    counter++;
}

Token& Token::operator=(const Token& other) {
    if (this != &other) {
        type = other.type;
        value = other.value;
    }
    return *this;
}

Token::~Token() {
    counter--;
}

TokenType Token::getType() const {
    return type;
}

const string& Token::getValue() const {
    return value;
}

void Token::setType(TokenType newType) {
    type = newType;
}

void Token::setValue(const string& newValue) {
    value = newValue;
}

int Token::getTokenCount() {
    return counter;
}

int Token::getPrecedence(const Token& token) {
    if (token.getType() != TokenType::OPERATOR) {
        throw invalid_argument("Non-operator tokens do not have precedence.");
    }

    string operators = "+-*/^#";
    size_t found = operators.find(token.getValue());
    if (found == string::npos) {
        throw invalid_argument("Unknown operator.");
    }

    switch (found) {
    case 0: // '+' or '-'
    case 1:
        return 1;
    case 2: // '*' or '/'
    case 3:
        return 2;
    case 4: // '^'
        return 3;
    case 5: // '#'
        return 4;
    default:
        return -1;
    }
}