#include "Evaluator.h"
#include <stdexcept>
#include <cmath>

Evaluator::Evaluator(Token* tokens, int count)
    : tokens(tokens), tokenCount(count), operands(nullptr), operators(nullptr),
    operandsSize(0), operandsCapacity(10), operatorsSize(0), operatorsCapacity(10) {
    operands = new double[operandsCapacity];
    operators = new string[operatorsCapacity];
}

Evaluator::~Evaluator() {
    delete[] operands;
    delete[] operators;
}

void Evaluator::resizeOperands() {
    int newCapacity = operandsCapacity * 2;
    double* newOperands = new double[newCapacity];
    for (int i = 0; i < operandsSize; ++i) {
        newOperands[i] = operands[i];
    }
    delete[] operands;
    operands = newOperands;
    operandsCapacity = newCapacity;
}

void Evaluator::resizeOperators() {
    int newCapacity = operatorsCapacity * 2;
    string* newOperators = new string[newCapacity];
    for (int i = 0; i < operatorsSize; ++i) {
        newOperators[i] = operators[i];
    }
    delete[] operators;
    operators = newOperators;
    operatorsCapacity = newCapacity;
}

void Evaluator::pushOperand(double value) {
    if (operandsSize == operandsCapacity) {
        resizeOperands();
    }
    operands[operandsSize++] = value;
}

void Evaluator::pushOperator(const string& op) {
    if (operatorsSize == operatorsCapacity) {
        resizeOperators();
    }
    operators[operatorsSize++] = op;
}

double Evaluator::popOperand() {
    if (operandsSize == 0) {
        throw runtime_error("Invalid expression");
    }
    return operands[--operandsSize];
}

string Evaluator::popOperator() {
    if (operatorsSize == 0) {
        throw runtime_error("Invalid expression");
    }
    return operators[--operatorsSize];
}

void Evaluator::applyOperator(const string& op) {
    if (operandsSize < 2) {
        throw runtime_error("Invalid expression");
    }
    double right = popOperand();
    double left = popOperand();

    if (op == "+") pushOperand(left + right);
    else if (op == "-") pushOperand(left - right);
    else if (op == "*") pushOperand(left * right);
    else if (op == "/") {
        if (right == 0) throw runtime_error("Division by zero");
        pushOperand(left / right);
    }
    else {
        throw runtime_error("Unknown operator");
    }
}

int Evaluator::getPrecedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0; 
}

double Evaluator::evaluate() {
    for (int i = 0; i < tokenCount; ++i) {
        if (tokens[i].get_type() == TokenType::NUMBER) {
            pushOperand(stod(tokens[i].get_value()));
        }
        else if (tokens[i].get_type() == TokenType::OPERATOR) {
            string op = tokens[i].get_value();
            while (operatorsSize > 0 && getPrecedence(operators[operatorsSize - 1]) >= getPrecedence(op)) {
                applyOperator(popOperator());
            }
            pushOperator(op);
        }
    }

    while (operatorsSize > 0) {
        applyOperator(popOperator());
    }

    if (operandsSize != 1) {
        throw runtime_error("Invalid expression");
    }

    return popOperand();
}
