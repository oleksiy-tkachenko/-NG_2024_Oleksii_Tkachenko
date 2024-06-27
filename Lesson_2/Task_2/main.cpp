#include <iostream>

using namespace std;

int main()
{
    // i_ means iterable
    int sizes[20];
    int maxSizeValue = 0;
    int stopIndex = 19;
    for(int i_row = 0; i_row < 20; i_row++) {
        cout << "Enter size of the section(enter only odd numbers, 0 to stop): ";
        cin >> sizes[i_row];
        if(sizes[i_row] > maxSizeValue) {
            maxSizeValue = sizes[i_row];
        }
        if(sizes[i_row] % 2 == 0) {
            stopIndex = i_row;
            break;
        }
    }

    for (int i_row = 0; i_row < stopIndex; i_row++) {
        int startPoint =  (maxSizeValue - sizes[i_row]) / 2.0;
        int endPoint = startPoint + sizes[i_row];
        for (int i_column = 0; i_column < startPoint; i_column++) {
            cout << " ";
        }
        for (int i_column = startPoint; i_column < endPoint; i_column++) {
            cout << "*";
        }
        cout << endl;
    }
    system("pause");
}
