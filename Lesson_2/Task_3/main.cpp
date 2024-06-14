#include <iostream>

using namespace std;

int main()
{
    int columns[5];
    int maxNumber = 0;
    for (int column = 0; column < 5; column++) {
        cout << "Enter amount in column " << column << ": ";
        cin >> columns[column];
        if(columns[column] > maxNumber) {
            maxNumber = columns[column];
        }
    }

    for (int row = 0; row < maxNumber; row++) {
        for (int column = 0; column < 5; column++) {
            if(columns[column] > row) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    system("pause");
}
