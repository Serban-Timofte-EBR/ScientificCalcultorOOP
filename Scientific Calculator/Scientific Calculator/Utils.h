#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Elements { NUMBER, OPERATOR, PARANTHESIS };

class Parser {
private:
	string inp = " ";
	//Token* tokens = nullptr;
	int capacitate, dimensiune;

public:
	Parser() {};
};