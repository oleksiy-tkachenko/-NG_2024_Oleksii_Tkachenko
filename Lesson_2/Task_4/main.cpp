#include <iostream>

using namespace std;

int main()
{
    string wordCheckString;
    cout << "Enter string to check for words:" << endl;
    getline(cin, wordCheckString);
    if(wordCheckString == "" || wordCheckString[0] == ' ') {
        cout << "You can't start from nothing or space." << endl;
        system("pause");
        return 1;
    }

    int wordCount = 1;
    bool isPreviousSpace = false;
    for(int i_symbol = 0; wordCheckString[i_symbol] != 0; i_symbol++) {
        if(wordCheckString[i_symbol] == ' ' && !isPreviousSpace) {
            isPreviousSpace = true;
        } else if(wordCheckString[i_symbol] != ' ' && isPreviousSpace) {
            isPreviousSpace = false;
            wordCount++;
        }
    }
    cout << "Word count of your string is " << wordCount << endl;
    system("pause");
}
