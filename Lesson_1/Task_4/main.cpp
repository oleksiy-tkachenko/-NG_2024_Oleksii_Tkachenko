#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    double a, b, result;
    int operation;
    bool isSuccessful = true;

    cout << "Calculator\n\nEnter two numbers to do math operations with, separating them either by pressing enter or spacebar\n";
    cin >> a >> b;
    cout << "\nChoose the math operation(enter the number of available operation)\n"
            "List of available operations\n0. addition\n1. subtraction\n2. multiplication\n"
            "3. division\n4. square(using first)\n5. squareroot(using first)\n";
    cin >> operation;
    switch(operation){
        case(0): // addition
            result = a + b;
            break;
        case(1): // subtraction
            result = a - b;
            break;
        case(2): // multiplication
            result = a * b;
            break;
        case(3): // division
            if(b == 0){
                cout << "Infinity\n";
                isSuccessful = false;
                break;
            }
            result = a / b;
            break;
        case(4): // square of first number
            result = a * a;
            break;
        case(5): // square root of first number
            result = sqrt(a);
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
