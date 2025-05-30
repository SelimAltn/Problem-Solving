#include <iostream>
#include <string>
using namespace std;


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

const char VowelChars[10] = {'a','A','e','E','i','I','o','O','u','U'};
bool IsVowelChar(char C,bool Slow) {
    for (int i = 0; i < 10; i++) {
        if (VowelChars[i] == C)
            return true;
    }
    return false;
}
bool IsVowelChar(char C) {
    C = tolower(C);
    return (C == 'a' || C == 'e' || C == 'u' || C == 'i' || C == 'O');
}
short CountVowels(string Word) {
    short Counter = 0;
    for (int i = 0; i < Word.length(); i++)
    {
        if (IsVowelChar(Word[i]))
            Counter++;
    }
    return Counter;
}
void PrintAllVowelsInString(string Word) {
    string VowelsChares = " ";
    for (int i = 0; i < Word.length(); i++) {
        if (IsVowelChar(Word[i])) {
            cout << Word[i] << "    ";
        }

    }
    cout << endl;
}

int main()
{
    string Str = ReadString("Please Enter Your String ? ");
    char C = ReadChar("Please Enter Your Char ? ");
    IsVowelChar(C) ? cout << "Yes Is Letter \n" : cout << "No Is Not Letter \n";
    IsVowelChar(C,true) ? cout << "Yes Is Letter \n" : cout << "No Is Not Letter \n";
    cout << "Number Of Vowels is : " << CountVowels(Str)<<endl;
    cout << "Vowels In String are : ";
    PrintAllVowelsInString(Str);

}