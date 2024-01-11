#pragma once
#include "Token.h"
#include <string>

using namespace std;

class Evaluator {
private:
    Token* tokens;
    int tokenCount;
    double* operands;
    string* operators;
    int operandsSize, operandsCapacity;
    int operatorsSize, operatorsCapacity;

    void resizeOperands();
    void resizeOperators();
    void pushOperand(double value);
    void pushOperator(const string& op);
    double popOperand();
    string popOperator();
    void applyOperator(const string& op);
    int getPrecedence(const string& op);

public:
    Evaluator();
    Evaluator(Token* tokens, int count);
    ~Evaluator();
    double evaluate();

    Token* get_tokens();
    void setTokens(Token* tokens, int count);

    int get_tokenCount();
    void setTokenCount(int count);

    double* get_operands();
    void setOperands(double* operands, int size, int capacity);

    string* get_operators();
    void set_operators(string* operators, int size, int capacity);

    int get_operandsSize();
    void set_operandsSize(int size);

    int get_operandsCapacity();
    void set_operandsCapacity(int capacity);

    int get_operatorsSize();
    void set_operatorsSize(int size);

    int get_operatorsCapacity();
    void set_operatorsCapacity(int capacity);

    friend ostream& operator<<(ostream& os, const Evaluator& evaluator);
    friend istream& operator>>(istream& is, Evaluator& evaluator);

    bool operator<=(const Evaluator& rhs);
    bool operator>=(const Evaluator& rhs);
};