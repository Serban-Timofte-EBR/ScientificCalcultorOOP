#include "EquationFileProcessor.h"
#include "Expression.h"
#include <iostream>
#include <fstream>
#include <string>

void EquationFileProcessor::processFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "Unable to open file: " << filePath << std::endl;
        return;
    }

    std::cout << "Do you want to display the results on the console or save to a file? (Enter 'console' or 'file'): ";
    std::string choice;
    getline(std::cin, choice);

    std::ofstream outFile;
    if (choice == "file") {
        std::cout << "Enter the output file name: ";
        std::string outputFileName;
        getline(std::cin, outputFileName);
        outFile.open(outputFileName);
        if (!outFile.is_open()) {
            std::cout << "Unable to open file: " << outputFileName << std::endl;
            return;
        }
    }

    std::string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            Expression expr(line);
            if (expr.evaluate()) {
                std::string result = "Result: " + std::to_string(expr.getResult());
                if (choice == "console") {
                    std::cout << result << std::endl;
                }
                else {
                    outFile << result << std::endl;
                }
            }
            else {
                std::string error = "Invalid expression or error during evaluation.";
                if (choice == "console") {
                    std::cout << error << std::endl;
                }
                else {
                    outFile << error << std::endl;
                }
            }
        }
    }

    file.close();
    if (outFile.is_open()) {
        outFile.close();
    }
}
