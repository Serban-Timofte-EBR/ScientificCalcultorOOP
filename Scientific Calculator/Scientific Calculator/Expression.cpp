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

double Expression::getResult() const {
    return result;
}

bool Expression::isValidExpression() const {
    return isValid;
}
