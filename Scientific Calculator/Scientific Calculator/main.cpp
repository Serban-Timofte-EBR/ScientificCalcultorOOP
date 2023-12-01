/*
	3 clase
	Dynamic char vector
	Dynamic int/float/double vector
	Const value
v	Static value 
v	Static method
	Setters & Getters for everything: Token	v	Parser		Eval
	At least 2 methods per class: Token	v	Parser		Eval
	At least 1 default constructor and one constructor with params: Token v		Parser		Eval
	Operators << and >>: Token	v	Parser		Eval
	Other 2 operators per class: Token	v	Parser		Eval
	Implementation in header and cpp file: Token	v	Parser		Eval
*/
#include <iostream>
#include "Token.h"
using namespace std;

class Util {

};

int main() {
	cout << "Testing the Token Class!" << endl;
	Token token1("10", TokenType::NUMBER);
	cout << "Token 1: ";
	cout << token1;

	Token token2 = token1;
	cout << "Token 2 (copy of Token 1): ";
	cout << token2;

	Token token3;
	cout << "Enter the values for Token 3: ";
	cin >> token3;
	token3.set_type(TokenType::NUMBER); 
	cout << "Token 3: ";
	cout << token3;

	cout << "Number of Token instances: " << Token::get_counter() << endl;

	cout << endl << endl << "Testing Custom Class Methods: " << endl << endl;
	Token numberToken("5", TokenType::NUMBER);
	Token plusToken("+", TokenType::OPERATOR);
	Token bracketToken("(", TokenType::PARENTHESIS);

	cout << "Is numberToken an operator? " << (numberToken.isOperator() ? "Yes" : "No") << endl;
	cout << "Is plusToken an operator? " << (plusToken.isOperator() ? "Yes" : "No") << endl;
	cout << "Is bracketToken an operator? " << (bracketToken.isOperator() ? "Yes" : "No") << endl;

	try {
		cout << "Precedence of plusToken: " << plusToken.precedence() << endl;
		cout << "Precedence of bracketToken: " << bracketToken.precedence() << endl; 
	}
	catch (const exception e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	cout << endl << "End of testing Custom Class Methods" << endl;
	
	cout << endl << endl << "Testing Custom Class Operators: " << endl << endl;
	Token numberToken1("5", TokenType::NUMBER);
	Token numberToken2("5", TokenType::NUMBER);
	Token operatorToken("+", TokenType::OPERATOR);

	cout << "Is numberToken1 equal to numberToken2? " << (numberToken1 == numberToken2 ? "Yes" : "No") << endl;
	cout << "Is numberToken1 different from operatorToken? " << (numberToken1 != operatorToken ? "Yes" : "No") << endl;

	cout << endl << "End of testing Custom Class Operators" << endl;
	
	cout << endl << "End of testing the Token Class" << endl;
	cout << "------------------------------------------------" << endl;
	return 0;
}