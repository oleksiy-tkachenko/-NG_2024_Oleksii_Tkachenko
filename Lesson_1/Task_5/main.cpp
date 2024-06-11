#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cout << "Input a, b and c of quadratic equation, separating them either by pressing enter or spacebar:" << endl;
    cin >> a >> b >> c;

    double discriminant = b*b - 4*a*c;
    double realPart = -b/(2*a);
    if(discriminant > 0) {
        cout << "Discriminant is higher than 0, so\n";
        double realDiscriminantPart = sqrt(discriminant / (2*a));
        cout << "First root = " << realPart + realDiscriminantPart << endl
             << "Second root = " << realPart - realDiscriminantPart << endl;
    } else if (discriminant == 0) {
        cout << "Discriminant is 0, so\n"
             << "Only root = " << realPart << endl;
    } else {
        cout << "Discriminant is less than 0, so\n";
        double imaginaryDiscriminantPart = sqrt(-discriminant)/(2*a);
        cout << "Fisrt root = " << realPart << showpos << imaginaryDiscriminantPart<< "i" << endl;
        cout << "Secound root = " <<  realPart << showpos << -imaginaryDiscriminantPart << "i"  << endl;
    }
    system("pause");
}
