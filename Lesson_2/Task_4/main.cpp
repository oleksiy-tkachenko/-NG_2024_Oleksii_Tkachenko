#include <iostream>

using namespace std;

int main()
{
    string wordCheckString;
    cout << "Enter string to check for words:" << endl;
    getline(cin, wordCheckString);

    int wordCount, currentWordIndex = 0;
    for(int currentWordIndex= 0, nextWordIndex =  1; wordCheckString[currentWordIndex]; currentWordIndex++, nextWordIndex++){
        bool isCurrentLetter = wordCheckString[currentWordIndex] >= 65 && wordCheckString[currentWordIndex]<= 90
                        || wordCheckString[currentWordIndex] >= 97 && wordCheckString[currentWordIndex]<= 122;
        bool isNextLetter = wordCheckString[nextWordIndex] >= 65 && wordCheckString[nextWordIndex]<= 90
                               || wordCheckString[nextWordIndex] >= 97 && wordCheckString[nextWordIndex]<= 122;
        if(isCurrentLetter && !isNextLetter){
            wordCount++;
        }
    }

    cout << "Word count of your string is " << wordCount << endl;
    system("pause");
}
