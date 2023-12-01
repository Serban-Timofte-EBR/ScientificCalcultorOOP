/*
v   3 clase
    Dynamic char vector
v   Dynamic int/float/double vector 
v   Const value
v	Static value
v	Static method
v   Setters & Getters for everything: Token	v	Parser	v	Eval	v	Expression  v
v   At least 2 methods per class: Token	v	Parser	v	Eval	v	Expression  v
v   At least 1 default constructor and one constructor with params: Token v		Parser	v	Eval	v 	Expression  v
v   Operators << and >>: Token	v	Parser	v	Eval	v	Expression  v
v   Other 2 operators per class: Token	v	Parser	v	Eval	v	Expression  v
v   Implementation in header and cpp file: Token	v	Parser	v	Eval	v	Expression  v
*/
#include "Expression.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "X Calculator!" << endl;
    cout << "Enter an expression or type 'exit' to quit." << endl;

    string input;
    while (true) {
        cout << "Enter here: ";
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

    cout << "Finished!" << endl;
    return 0;
}