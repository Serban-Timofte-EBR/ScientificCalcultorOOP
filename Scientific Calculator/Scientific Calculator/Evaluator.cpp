#include "Evaluator.h"
#include <stdexcept>

Evaluator::Evaluator(Token* tokens, int count) : tokens(tokens), tokenCount(count) {}

double Evaluator::evaluate() {
    stack<double> values;

    for (int i = 0; i < tokenCount; ++i) {
        if (tokens[i].getType() == TokenType::NUMBER) {
            values.push(stod(tokens[i].getValue()));
        }
        else if (tokens[i].getType() == TokenType::OPERATOR) {
            if (values.size() < 2) {
                throw runtime_error("Invalid expression");
            }
            double right = values.top();
            values.pop();
            double left = values.top();
            values.pop();

            switch (tokens[i].getValue()[0]) {
            case '+': values.push(left + right); break;
            case '-': values.push(left - right); break;
            case '*': values.push(left * right); break;
            case '/':
                if (right == 0) throw runtime_error("Division by zero");
                values.push(left / right);
                break;
            default: throw runtime_error("Unknown operator");
            }
        }
    }

    if (values.size() != 1) {
        throw runtime_error("Invalid expression");
    }

    return values.top();
}
