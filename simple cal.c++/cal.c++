#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to parse the user input and extract operator and operands
void parse_input(string input, char& op, float& num1, float& num2) {
    stringstream ss(input);
    ss >> op >> num1 >> num2;
}

// Function to perform the calculation based on operator and operands
float calculate(char op, float num1, float num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error! Division by zero." << endl;
                return 0;
            }
        default:
            cout << "Error! Operator is not correct." << endl;
            return 0;
    }
}

int main() {
    string input;
    cout << "Enter a mathematical operation in the format 'operator number1 number2': ";
    getline(cin, input);

    char op;
    float num1, num2;
    parse_input(input, op, num1, num2);

    float result = calculate(op, num1, num2);
    cout << "Result: " << result << endl;

return 0;
}