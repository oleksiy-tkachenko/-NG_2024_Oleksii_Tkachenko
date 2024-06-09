#include <iostream>
#include <cmath>
#include <ccomplex>

using namespace std;

int main()
{
    double a, b, c, discriminant, root1, root2, realPart, realDiscriminantPart, imaginaryDiscriminantPart;
    cout << "Input a, b and c of quadratic equation, separating them either by pressing enter or spacebar:" << endl;
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    realPart = -b/(2*a);
    if(discriminant > 0) {
        cout << "Discriminant is higher than 0, so\n";
        realDiscriminantPart = sqrt(discriminant / (2*a));
        root1 = realPart + realDiscriminantPart;
        root2 = realPart - realDiscriminantPart;
        cout << "First root = " << root1 << endl
             << "Second root = " << root2 << endl;
    } else if (discriminant == 0) {
        cout << "Discriminant is 0, so\n";
        root1 = realPart;
        cout << "Only root = " << root1 << endl;
    } else {
        cout << "Discriminant is less than 0, so\n";
        imaginaryDiscriminantPart = sqrt(-discriminant)/(2*a);
        complex<double> root1;
        root1.real(realPart);
        root1.imag(imaginaryDiscriminantPart);
        complex<double> root2;
        root2.real(realPart);
        root2.imag(-imaginaryDiscriminantPart);
        cout << "Fisrt root = " << root1.real() << showpos << root1.imag() << "i"  << endl;
        cout << "Secound root = " << root2.real() << showpos << root2.imag() << "i"  << endl;
    }
    system("pause");
}
