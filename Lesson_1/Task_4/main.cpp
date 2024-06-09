#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    double number1, number2, result;
    int operation;
    bool isSuccessful = true;

    cout << "Calculator\n\nEnter two numbers to do math operations with, separating them either by pressing enter or spacebar\n";
    cin >> number1 >> number2;
    cout << "\nChoose the math operation(enter the number of available operation)\n"
            "List of available operations\n0. addition\n1. subtraction\n2. multiplication\n"
            "3. division\n4. square(using first)\n5. squareroot(using first)\n";
    cin >> operation;
    switch(operation){
        case(0): // addition
            result = number1 + number2;
            break;
        case(1): // subtraction
            result = number1 - number2;
            break;
        case(2): // multiplication
            result = number1 * number2;
            break;
        case(3): // division
            if(number2 == 0){
                cout << "Infinity\n";
                isSuccessful = false;
                break;
            }
            result = number1 / number2;
            break;
        case(4): // square of first number
            result = number1 * number1;
            break;
        case(5): // square root of first number
            result = sqrt(number1);
            break;
        default: // invalid number
            cout << "No such operation!\n";
            isSuccessful = false;
            break;
    }
    if(isSuccessful){
        cout << result << endl;
    }
    system("pause");
}
