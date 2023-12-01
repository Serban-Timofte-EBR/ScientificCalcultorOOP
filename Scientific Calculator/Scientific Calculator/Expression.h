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

    const int MAX_LEN = 1000;
public:
    Expression();
    explicit Expression(const string& expr);
    void setExpression(const string& expr);
    bool evaluate();
    double getResult();
    bool isValidExpression();

    string get_rawExpression();
    double get_result();
    bool get_isValid();

    void set_rawExpression(const string& expr);
    void set_result(double res);
    void set_isValid(bool val);

    friend ostream& operator<<(ostream& os, const Expression& expr);
    friend istream& operator>>(istream& is, Expression& expr);

    Expression operator+(const Expression& rhs) const;
    Expression& operator++();  
    Expression operator++(int);
};
