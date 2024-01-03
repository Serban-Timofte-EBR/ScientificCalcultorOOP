#include "Expression.h"
#include "EquationFileProcessor.h"
#include <iostream>
#include <string>

using namespace std;

void processEquation(const string& input) {
    Expression expr(input);
    if (expr.evaluate()) {
        cout << "Result: " << expr.getResult() << endl;
    }
    else {
        cout << "Invalid expression or error during evaluation." << endl;
    }
}

int main(int argc, char* argv[]) {
    cout << "X Calculator!" << endl;
    EquationFileProcessor fileProcessor;

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            string input = argv[i];
            processEquation(input);
        }
    }
    else {
        while (true) {
            cout << "\nMenu:" << endl;
            cout << "1. Enter an equation" << endl;
            cout << "2. Process equations from a file" << endl;
            cout << "3. Exit" << endl;
            cout << "Choose an option: ";
            string choice;
            getline(cin, choice);

            if (choice == "exit" || choice == "3") {
                break;
            }
            else if (choice == "1") {
                cout << "Enter an equation: ";
                string input;
                getline(cin, input);
                processEquation(input);
            }
            else if (choice == "2") {
                cout << "Enter file path: ";
                string filePath;
                getline(cin, filePath);
                fileProcessor.processFile(filePath);
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    cout << "Finished!" << endl;
    return 0;
}
