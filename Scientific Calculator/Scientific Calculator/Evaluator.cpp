#include "Evaluator.h"
#include <stdexcept>
#include <cmath>

Evaluator::Evaluator() : tokens(nullptr), tokenCount(0), operands(nullptr), operators(nullptr), operandsSize(0), operandsCapacity(0), operatorsSize(0), operatorsCapacity(0) {}

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
    else if (op == "^") pushOperand(pow(left, right));
    else if (op == "#") {
        if (left < 0) throw runtime_error("Negative number under root");
        if (right == 0) throw runtime_error("Zero as root order");
        pushOperand(pow(left, 1.0 / right));
    }
    else {
        throw runtime_error("Unknown operator");
    }
}


int Evaluator::getPrecedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^" || op == "#") return 3;
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
                if (operators[operatorsSize - 1] == "(" || operators[operatorsSize - 1] == "[" || operators[operatorsSize - 1] == "{") {
                    break;
                }
                applyOperator(popOperator());
            }
            pushOperator(op);
        }
        else if (tokens[i].get_type() == TokenType::PARENTHESIS) {
            string par = tokens[i].get_value();
            if (par == "(" || par == "[" || par == "{") {
                pushOperator(par);
            }
            else {
                while (operatorsSize > 0 && operators[operatorsSize - 1] != "(" && operators[operatorsSize - 1] != "[" && operators[operatorsSize - 1] != "{") {
                    applyOperator(popOperator());
                }
                if (operatorsSize > 0) {
                    popOperator();
                }
            }
        }
    }

    while (operatorsSize > 0) {
        if (operators[operatorsSize - 1] == "(" || operators[operatorsSize - 1] == "[" || operators[operatorsSize - 1] == "{") {
            popOperator();
            continue;
        }
        applyOperator(popOperator());
    }

    if (operandsSize != 1) {
        throw runtime_error("Invalid expression");
    }

    return popOperand();
}


Token* Evaluator::get_tokens() {
    return this->tokens;
}

int Evaluator::get_tokenCount() {
    return this->tokenCount;
}

double* Evaluator::get_operands() {
    return this->operands;
}

string* Evaluator::get_operators() {
    return this->operators;
}

int Evaluator::get_operandsSize() {
    return this->operandsSize;
}

int Evaluator::get_operandsCapacity() {
    return this->operandsCapacity;
}

int Evaluator::get_operatorsSize() {
    return this->operatorsSize;
}

int Evaluator::get_operatorsCapacity() {
    return this->operatorsCapacity;
}

void Evaluator::setTokens(Token* newTokens, int count) {
    delete[] tokens;
    tokens = new Token[count];
    memcpy(tokens, newTokens, count * sizeof(Token));
    tokenCount = count;
}

void Evaluator::setTokenCount(int count) {
    tokenCount = count;
}

void Evaluator::setOperands(double* newOperands, int size, int capacity) {
    delete[] operands;
    operands = new double[capacity];
    memcpy(operands, newOperands, size * sizeof(double));
    operandsSize = size;
    operandsCapacity = capacity;
}

void Evaluator::set_operators(string* newOperators, int size, int capacity) {
    delete[] operators;
    operators = new string[capacity];
    for (int i = 0; i < size; ++i) {
        operators[i] = newOperators[i];
    }
    operatorsSize = size;
    operatorsCapacity = capacity;
}

void Evaluator::set_operandsSize(int size) {
    operandsSize = size;
}

void Evaluator::set_operandsCapacity(int capacity) {
    operandsCapacity = capacity;
}

void Evaluator::set_operatorsSize(int size) {
    operatorsSize = size;
}

void Evaluator::set_operatorsCapacity(int capacity) {
    operatorsCapacity = capacity;
}

ostream& operator<<(ostream& cons, const Evaluator& evaluator) {
    cons << "Evaluator State:" << endl;
    cons << "Token Count: " << evaluator.tokenCount << endl;
    cons << "Operands Size: " << evaluator.operandsSize << endl;
    cons << "Operators Size: " << evaluator.operatorsSize << endl;
    return cons;
}

istream& operator>>(istream& cons, Evaluator& evaluator) {
    cout << "Enter the number of tokens for evaluation: ";
    cons >> evaluator.tokenCount;

    return cons;
}

bool Evaluator::operator<=(const Evaluator& rhs) {
    return this->tokenCount <= rhs.tokenCount;
}

bool Evaluator::operator>=(const Evaluator& rhs) {
    return this->tokenCount >= rhs.tokenCount;
}