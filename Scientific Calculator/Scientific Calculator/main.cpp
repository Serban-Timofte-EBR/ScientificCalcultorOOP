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
