#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Elements{NUMBER, OPERATOR, PARANTHESIS};

class Token {
private: 
	Elements type = Elements::NUMBER;
	string value = " ";

	static const int before;
	static int counter;

public:
	Token() :type(Elements::NUMBER), value("0") {};
	Token(Elements type, string& value) : type(type), value(value) {};
	Token(const Token& copy):type(copy.type), value(copy.value) {};
	Token& operator=(const Token& copy) {
		if (this != &copy) {
			type = copy.type;
			value = copy.value;
		}
		return *this;
	}

	~Token() {};

	Elements get_type() { return this->type; }

	string get_value() { return this->value; }
	
	void set_type(Elements type) {
		this->type = type;
	}

	void set_value(string value) {
		this->value = value;
	}

	static int get_before(const Token& token) {
		if (token.type != Elements::OPERATOR) { throw exception("THIS IS NOT AN OPERATION TO HAVE A BEFORE"); }

		switch (token.value[0]) { 
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		case '#': return 4;
		default: 
			throw exception("NOT AN OPERATOR");
		}
	}

	// @TODO: Supraincarcare Operatori
};

class Parser {
private:
	string inp = " ";
	Token* tokens = nullptr;
	int capacitate, dimensiune;

public:
	Parser() {};
};