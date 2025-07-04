#include <iostream>
#include <string>
using namespace std;

string UpperAllString(string Word) {
    for (int i = 0; i < Word.length(); i++) {
            Word[i] = toupper(Word[i]);
    }
    return Word;
}
string LowerAllString(string Word) {
    for (int i = 0; i < Word.length(); i++) {
        Word[i] = tolower(Word[i]);
    }
    return Word;
}
string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
}
char ReadChar(string message) {
    char C;
    cout << message << endl;
    cin >> C;
    return C;
}
char InvertLetterCase(char C) {
    return islower(C) ? toupper(C) : tolower(C);
}
string InvertAllStringLettersCase(string Word) {
    for (int i = 0; i < Word.length(); i++) {
        Word[i] = InvertLetterCase(Word[i]);
    }
    return Word;
}
int main()
{
    string Word = "Mohammed Saqer Abu-Hahdoud";

    cout << Word << endl;
    cout << "String after Upper : " << endl;
    Word = UpperAllString(Word);
    cout << Word<<endl;
    cout << endl;
    cout << "String after Lower : " << endl;
    Word = LowerAllString(Word);
    cout << Word << endl;

    char C = ReadChar("Please Enter Your Char ?");
    cout << InvertLetterCase(C)<<endl;

    string Word = ReadString("Please Enter Your String ? ");
    cout << "\nString after Inverting All Letters Case:\n";
    cout << InvertAllStringLettersCase(Word)<<endl;
}