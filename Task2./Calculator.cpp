#include <iostream>
using namespace std;

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        throw invalid_argument("Error: Division by zero.");
    }
}

int main() {
    float num1, num2;
    char operation;
    bool continueCalculation = true;

    while (continueCalculation) {
        
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> operation;

        try {
            float result;
            switch (operation) {
                case '+':
                    result = add(num1, num2);
                    cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                    break;
                case '-':
                    result = subtract(num1, num2);
                    cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                    break;
                case '*':
                    result = multiply(num1, num2);
                    cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                    break;
                case '/':
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                    break;
                default:
                    cout << "Invalid operation. Please try again." << endl;
            }
        } catch (const invalid_argument& e) {
            cout << e.what() << endl; 
        }

        
        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        continueCalculation = (choice == 'y' || choice == 'Y');
    }

    cout << "Thank you for using the calculator! Goodbye!" << endl;
    return 0;
}
