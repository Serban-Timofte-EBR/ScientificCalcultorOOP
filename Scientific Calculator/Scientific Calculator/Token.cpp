#include "Token.h"
#include <iostream>
using namespace std;

const int Token::before = 0;
int Token::counter = 0;

Token::Token() :type(Elements::NUMBER), value("0") {}
Token::Token(Elements type, string& value) : type(type), value(value) {}
Token::Token(const Token& copy) :type(copy.type), value(copy.value) {}

Token::~Token() {};

Elements Token::get_type() { return this->type; };

string Token::get_value() { return this->value; }

void Token::set_value(string value) {
	this->value = value;
}

int Token::get_before(const Token& token) {
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

Token& Token::operator=(const Token& other) {
	if (this != &other) {
		type = other.type;
		value = other.value;
	}
	return *this;
}