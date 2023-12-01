#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Expression {
private:
	char* expression = nullptr;
	int length = 0;

	const int MAX_LENGTH = 1000;
public:
	Expression();
	Expression(char* ex);
	Expression(const Expression& e);
	~Expression();

	void set_expression(char* ex);
	char* get_expression();
	
	int get_length;
	void set_length(int length);

	void clear();
	bool isEmpty();

	Expression& operator=(const Expression& e);

};