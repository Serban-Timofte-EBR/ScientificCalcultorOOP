#include "Expression.h"

Expression::Expression() : rawExpression(""), result(0.0), isValid(false) {}

Expression::Expression(const string& expr) : rawExpression(expr), result(0.0), isValid(false) {}

void Expression::setExpression(const string& expr) {
    rawExpression = expr;
    isValid = false;
}

bool Expression::evaluate() {
    try {
        Parser parser(rawExpression);
        parser.parse();
        Evaluator evaluator(parser.getTokens(), parser.getTokenCount());
        result = evaluator.evaluate();
        isValid = true;
    }
    catch (const exception& e) {
        cerr << "Error in expression: " << e.what() << endl;
        isValid = false;
    }
    return isValid;
}

double Expression::getResult() {
    return result;
}

bool Expression::isValidExpression() {
    return isValid;
}

string Expression::get_rawExpression() {
    return this->rawExpression;
}

double Expression::get_result() {
    return this->result;
}

bool Expression::get_isValid() {
    return this->isValid;
}

void Expression::set_rawExpression(const string& expr) {
    if (expr.length() <= MAX_LEN) {
        this->rawExpression = expr;
    }
    else { throw exception("Invalid expresion tried to be assigned!"); }
}

void Expression::set_result(double res) {
    this->result = res;
}

void Expression::set_isValid(bool val) {
    this->isValid = val;
}

ostream& operator<<(ostream& cons, const Expression& expr) {
    cons << "Expression: " << expr.rawExpression << ", Result: " << expr.result << ", IsValid: " << expr.isValid;
    return cons;
}

istream& operator>>(istream& cons, Expression& expr) {
    cout << "Enter expression: ";
    getline(cons, expr.rawExpression);
    expr.isValid = false;
    return cons;
}

Expression Expression::operator+(const Expression& e) const {
    return Expression(this->rawExpression + e.rawExpression);
}

Expression& Expression::operator++() {
    ++result;
    return *this;
}

Expression Expression::operator++(int) {
    Expression temp = *this;
    result++;
    return temp;
}