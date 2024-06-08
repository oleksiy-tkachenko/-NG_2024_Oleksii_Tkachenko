#include <iostream>
#include <cmath>
#include <ccomplex>

using namespace std;

int main()
{
    double a, b, c, discriminant, root1, root2;
    cout << "Input a, b and c of quadratic equation, separating them either by pressing enter or spacebar:" << endl;
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    if(discriminant > 0) {
        cout << "Discriminant is higher than 0, so\n";
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "First root = " << root1 << endl
             << "Second root = " << root2 << endl;
    } else if (discriminant == 0) {
        cout << "Discriminant is 0, so\n";
        root1 = -b/(2*a);
        cout << "Only root = " << root1 << endl;
    } else {
        cout << "Discriminant is less than 0, so\n";
        complex<double> root1;
        root1.real(-b/2*a);
        root1.imag(sqrt(-discriminant)/(2*a));
        complex<double> root2;
        root2.real(-b/2*a);
        root2.imag(-sqrt(-discriminant)/(2*a));
        cout << "Fisrt root = " << root1 << endl;
        cout << "Secound root = " << root2 << endl;
    }
    system("pause");
}
