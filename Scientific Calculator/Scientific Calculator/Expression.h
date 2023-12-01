#pragma once
#include "Parser.h"
#include "Evaluator.h"
#include <string>

using namespace std;

class Expression {
private:
    string rawExpression;
    double result;
    bool isValid;

public:
    Expression();
    explicit Expression(const string& expr);
    void setExpression(const string& expr);
    bool evaluate();
    double getResult() const;
    bool isValidExpression() const;
};
