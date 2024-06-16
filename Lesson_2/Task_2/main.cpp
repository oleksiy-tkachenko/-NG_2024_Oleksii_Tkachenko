#include <iostream>

using namespace std;

int main()
{
    int sizes[20];
    int maxSize = 0;
    int stopIndex = 19;
    for(int i_row = 0; i_row<20; i_row++) {
        cout << "Enter size of the section(enter only odd numbers, 0 to stop): ";
        cin >> sizes[i_row];
        if(sizes[i_row] > maxSize) {
            maxSize = sizes[i_row];
        }
        if(sizes[i_row] % 2 == 0) {
            stopIndex = i_row;
            break;
        }
    }

    for (int i_row = 0; i_row < stopIndex; i_row++) {
        for (int i_index = 0; i_index < (maxSize - sizes[i_row]) / 2.0; i_index++) {
            cout << " ";
        }
        for (int i_index = (maxSize - sizes[i_row]) / 2.0; i_index < (maxSize - sizes[i_row]) / 2.0 + sizes[i_row]; i_index++) {
            cout << "*";
        }
        cout << endl;
    }
    system("pause");
}
