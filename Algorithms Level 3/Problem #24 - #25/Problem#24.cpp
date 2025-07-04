#include <iostream>
#include <string>
using namespace std;

string UpperFirstLetterOfEachWord(string Word) {
    bool IsFirstLetter = true;
    for (int i = 0; i < Word.length(); i++) {
        if (Word[i] != ' ' && IsFirstLetter)
            Word[i] = toupper(Word[i]);
        IsFirstLetter = (Word[i] == ' ' ? true : false);
    }
    return Word;
}
string LowerFirstLetterOfEachWord(string Word) {
    bool IsFirstLetter = true;
    for (int i = 0; i < Word.length(); i++) {
        if (Word[i] != ' ' && IsFirstLetter)
            Word[i] = tolower(Word[i]);
        IsFirstLetter = (Word[i] == ' ' ? true : false);
    }
    return Word;
}
int main()
{
    
    string Word = "mohammed saqer abu-Hahdoud";

    cout << Word << endl;
    cout << "\nString after conversion:\n";
    Word = UpperFirstLetterOfEachWord(Word);
    cout<<Word<<endl;
    Word = LowerFirstLetterOfEachWord(Word);
    cout << Word<<endl;
}