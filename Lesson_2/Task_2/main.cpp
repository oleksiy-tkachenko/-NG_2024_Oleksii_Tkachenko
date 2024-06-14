#include <iostream>

using namespace std;

int main()
{
    int sizes[20];
    int maxSize = 0;
    int stopIndex = 19;
    for(int i = 0; i<20; i++) {
        cout << "Enter size of the section(0 to stop): ";
        cin >> sizes[i];
        if(sizes[i] > maxSize) {
            maxSize = sizes[i];
        } else if(sizes[i] == 0) {
            stopIndex = i;
            break;
        }
    }

    if(maxSize % 2 == 0) {
        maxSize++;
    }

    for (int row = 0; row < stopIndex; row++) {
        for (int index = 0; index < (maxSize - sizes[row]) / 2.0 + sizes[row]; index++) {
            if(index >= (maxSize - sizes[row]) / 2){
                if(sizes[row] % 2 == 0 && maxSize / 2 == index) {
                    cout << " ";
                    continue;
                }
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    system("pause");
}
