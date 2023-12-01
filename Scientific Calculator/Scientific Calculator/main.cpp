/*
	3 clase
	Dynamic char vector
	Dynamic int/float/double vector
	Const value
v	Static value 
v	Static method
	Setters & Getters for everything: Token	v	Parser		Eval		Expression
	At least 2 methods per class: Token	v	Parser		Eval
	At least 1 default constructor and one constructor with params: Token v		Parser		Eval		Expression
	Operators << and >>: Token	v	Parser		Eval
	Other 2 operators per class: Token	v	Parser		Eval		Expression
	Implementation in header and cpp file: Token	v	Parser		Eval		Expression
*/
#include "Expression.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Welcome to the Scientific Calculator!" << endl;
    cout << "Enter an expression to evaluate, or type 'exit' to quit." << endl;

    string input;
    while (true) {
        cout << "Enter expression: ";
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        Expression expr(input);
        if (expr.evaluate()) {
            cout << "Result: " << expr.getResult() << endl;
        }
        else {
            cout << "Invalid expression or error during evaluation." << endl;
        }
    }

    cout << "Calculator terminated." << endl;
    return 0;
}
