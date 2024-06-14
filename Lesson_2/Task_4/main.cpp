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
    for(int i = 0; wordCheckString[i] != 0; i++) {
        if(wordCheckString[i] == ' ' && !isPreviousSpace) {
            wordCount++;
            isPreviousSpace = true;
        } else if(wordCheckString[i] != ' ' && isPreviousSpace) {
            isPreviousSpace = false;
        }
    }
    cout << "Word count of your string is " << wordCount << endl;
    system("pause");
}
