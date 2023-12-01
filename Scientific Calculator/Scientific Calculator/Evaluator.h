#pragma once
#include "Token.h"
#include <stack>
#include <string>

using namespace std;

class Evaluator {
private:
    Token* tokens;
    int tokenCount;

public:
    Evaluator(Token* tokens, int count);
    double evaluate();
};
