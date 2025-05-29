#include <iostream>
#include <string>
using namespace std;

void PrintFirstLiterInString(string Word) {
    cout << "First Leter Of this string : " << endl;
    bool IsFirstLetter = true;
    for (int i = 0; i < Word.length(); i++) {
        if (Word[i] != ' ' && IsFirstLetter)
            cout << Word[i] << endl;
        IsFirstLetter = (Word[i] == ' ' ? true : false);
    }
}
string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
}
int main()
{
    string Str = ReadString("Please Enter Your String ? ");
    PrintFirstLiterInString(Str);
}