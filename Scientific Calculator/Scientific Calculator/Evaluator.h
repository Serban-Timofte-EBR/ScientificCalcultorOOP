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
    Evaluator(Token* tokens, int count);
    ~Evaluator();
    double evaluate();
};
