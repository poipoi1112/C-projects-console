#include <iostream>
using namespace std;

void display() {
    cout << "===============================================================================" << endl;
    cout << "==                             C++ Calculator                                ==" << endl;
    cout << "===============================================================================" << endl;
    cout << "==                             Operators:                                    ==" << endl;
    cout << "==                             Addition +                                    ==" << endl;
    cout << "==                             Subtraction -                                 ==" << endl;
    cout << "==                             Multiplicaton *                               ==" << endl;
    cout << "==                             Division /                                    ==" << endl;
    cout << "==                             Remainder %                                   ==" << endl;
    cout << "===============================================================================" << endl;
}

int main() {
    display();
    
    double num1;
    double num2;
    double ans = 0;
    char op;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operator: ";
    cin >> op;

    switch(op) {
        case '+':
        cout << "Answer: " << num1 << " + " << num2 << " = " << num1 + num2;
        break;

        case '-':
        cout << "Answer: " << num1 << " - " << num2 << " = " << num1 - num2;
        break;
        
        case '*':
        cout << "Answer: " << num1 << " * " << num2 << " = " << num1 * num2;
        break;

        case '/':
            if(num2 != 0){
                cout << "Answer: " << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "ERROR!" << endl;
            }
        break;

        default:
        cout << "Invalid operator!" << endl;
    }

    return 0;
}