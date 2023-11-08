#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Elements { NUMBER, OPERATOR, PARANTHESIS };

class Token {
private:
	Elements type = Elements::NUMBER;
	string value = " ";

	static const int before;
	static int counter;

public:
	Token();
	Token(Elements type, string& value);
	Token(const Token& copy);
	Token& operator=(const Token& copy);

	~Token();

	Elements get_type();

	string get_value();

	void set_type(Elements type);

	void set_value(string value);

	static int get_before(const Token& token);

	// @TODO: Supraincarcare Operatori
};