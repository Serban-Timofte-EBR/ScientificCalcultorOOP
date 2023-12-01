#include "Token.h"
#include <iostream>
using namespace std;

int Token::COUNTER = 0;

int Token::get_counter() {
	return Token::COUNTER;
}

void Token::set_increment_counter() {
	Token::COUNTER += 1;
}

void Token::set_decrement_counter() {
	Token::COUNTER -= 1;
}

TokenType Token::get_type() {
	return this->type;
}

void Token::set_type(TokenType type) {
	if (type != TokenType::NUMBER && type != TokenType::OPERATOR && type != TokenType::PARENTHESIS) { throw exception("Invalid Token Type!"); }
	this->type = type;
}

string Token::get_value() {
	return this->value;
}

void Token::set_value(string& value) {
	if (value == "") { throw exception("Invalid Value!"); }
	this->value = value;
}

void Token::set_const_value(const string value) {
	if (value == "") { throw exception("Invalid Value!"); }
	this->value = value;
}

Token::Token() { set_increment_counter(); }

Token::Token(string value, TokenType type) {
	set_value(value);
	set_type(type);
	set_increment_counter();
}

Token::Token(const Token& t) {
	set_const_value(t.value);
	set_type(t.type);
	set_increment_counter();
}

Token::~Token() {
	set_decrement_counter();
}

bool Token::isOperator() {
	bool flag;
	if (this->type == TokenType::OPERATOR) { flag = true; }
	else { flag = false; }
	return flag;
}

int Token::precedence() {
	//implement isOperator first!!!!!!!!!!
	if (!isOperator()) { throw exception("Cannot use precedence for a non-operator!"); }

	if (value == "(" || value == ")" || value == "[" || value == "]") return 4;
	if (value == "^" || value == "#") return 3;
	if (value == "*" || value == "/") return 2;
	if (value == "+" || value == "-") return 1;

	else {
		throw exception(("Invalid operator: " + string(this->value)).c_str());
	}
}


Token& Token::operator=(const Token& t) {
	if (this == &t) { return *this; }

	set_const_value(t.value);
	set_type(t.type);
	set_increment_counter();

	return *this;
}

void operator<<(ostream& console, Token& t) {
	console << endl;
	console << "Token Nr: " << t.get_counter() << endl;
	console << "Token Type: ";
	switch (t.get_type()) {
	case TokenType::NUMBER:
		console << "NUMBER" << endl;
		break;
	case TokenType::OPERATOR:
		console << "OPERATOR" << endl;
		break;
	case TokenType::PARENTHESIS:
		console << "PARENTHESIS" << endl;
		break;
	}

	console << "Token Value: " << t.get_value() << endl;
	console << endl;
}

istream& operator>>(istream& console, Token& t) {
	string value;
	cout << endl << "Enter Token Value: " << endl;
	console >> value;
	t.set_value(value);

	int typeInput;
	cout << "Enter token type (0 for NUMBER, 1 for OPERATOR, 2 for PARENTHESIS): ";
	console >> typeInput;
	TokenType type = TokenType(typeInput);
	t.set_type(type);

	return console;
}

bool Token::operator==(const Token& t) {
	bool flag;
	if (this->value == t.value && this->type == t.type) {
		flag = true;
		return flag;
	}
	return false;
}

bool Token::operator!=(const Token& t) {
	if (this->value == t.value && this->type == t.type) {
		return false;
	}
	return true;
}

