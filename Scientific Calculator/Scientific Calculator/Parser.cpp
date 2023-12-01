#include "Parser.h"
#include <cctype>
#include <sstream>

Parser::Parser() : expression(""), tokens(nullptr), tokenCount(0), capacity(0) {
    tokens = new Token[capacity];
}

Parser::Parser(const string& expr) : expression(expr), tokens(nullptr), tokenCount(0), capacity(10) {
    tokens = new Token[capacity];
}

Parser::Parser(const Parser& other) : expression(other.expression), tokenCount(other.tokenCount), capacity(other.capacity) {
    tokens = new Token[capacity];
    for (int i = 0; i < tokenCount; ++i) {
        tokens[i] = other.tokens[i];
    }
}

Parser::~Parser() {
    delete[] tokens;
}

Parser& Parser::operator=(const Parser& other) {
    if (this != &other) {
        delete[] tokens;
        expression = other.expression;
        tokenCount = other.tokenCount;
        capacity = other.capacity;
        tokens = new Token[capacity];
        for (int i = 0; i < tokenCount; ++i) {
            tokens[i] = other.tokens[i];
        }
    }
    return *this;
}

void Parser::resize() {
    int newCapacity = capacity * 2;
    Token* newTokens = new Token[newCapacity];
    for (int i = 0; i < tokenCount; ++i) {
        newTokens[i] = tokens[i];
    }
    delete[] tokens;
    tokens = newTokens;
    capacity = newCapacity;
}

void Parser::addToken(const string& value, TokenType type) {
    if (tokenCount == capacity) {
        resize();
    }
    tokens[tokenCount] = Token(value, type);
    cout << "Added token: " << tokens[tokenCount].get_value() << " Type: " << (type == TokenType::NUMBER ? "Number" : "Operator") << endl;
    tokenCount++;
}

bool Parser::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Parser::isNumber(char c) {
    return isdigit(c) || c == '.';
}

void Parser::parse() {
    stringstream ss(expression);
    char ch;
    string temp;

    while (ss >> noskipws >> ch) { 
        if (isspace(ch)) {
            if (!temp.empty()) {
                addToken(temp, TokenType::NUMBER);
                temp.clear();
            }
            continue;
        }

        if (isNumber(ch)) {
            temp += ch;
        }
        else {
            if (!temp.empty()) {
                addToken(temp, TokenType::NUMBER);
                temp.clear();
            }
            if (isOperator(ch)) {
                string op(1, ch);
                addToken(op, TokenType::OPERATOR);
            }
        }
    }

    if (!temp.empty()) {
        addToken(temp, TokenType::NUMBER);
    }
}


Token* Parser::getTokens() const {
    return tokens;
}

int Parser::getTokenCount() const {
    return tokenCount;
}

string Parser::get_expression() {
    return this->expression;
}

void Parser::set_expression(const string& expr) {
    this->expression = expr;
}

int Parser::get_tokenCount() {
    return this->tokenCount;
}
void Parser::set_tokenCount(int count) {
    this->tokenCount = count;
}

int Parser::get_capacity(){
    return this->capacity;
}

void Parser::set_capacity(int cap) {
    this->capacity = cap;
}

ostream& operator<<(ostream& cons, const Parser& parser) {
    cons << "Current Expression: " << parser.expression;
    return cons;
}

istream& operator>>(istream& cons, Parser& parser) {
    cout << "Enter expression: ";
    getline(cons, parser.expression);
    return cons;
}

Token& Parser::operator[](int index) {
    if (index < 0 || index >= tokenCount) {
        throw out_of_range("Index out of range");
    }
    return tokens[index];
}

Parser::operator string() {
    return expression;
}