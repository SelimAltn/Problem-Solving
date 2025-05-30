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
string UpperAllString(string Word) {
    for (int i = 0; i < Word.length(); i++) {
            Word[i] = toupper(Word[i]);
    }
    return Word;
}
char InvertLetterCase(char C) {
    return islower(C) ? toupper(C) : tolower(C);
}

string LowerAllString(string Word) {
    for (int i = 0; i < Word.length(); i++) {
        Word[i] = tolower(Word[i]);
    }
    return Word;
}
short CountSmallLetters(string Word) {
    short Count = 0;
    for (int i = 0; i < Word.length(); i++) {
        if(islower(Word[i]))
            Count++;
    }
    return Count;
}

short CountCapitalLetters(string Word) {
    short Count = 0;
    for (int i = 0; i < Word.length(); i++) {
        if (isupper(Word[i]))
            Count++;
    }
    return Count;
}
short CountLetter(string Word, char C,bool MatchCase=true) {
    short Count = 0;
    if(!MatchCase)
        islower(C) ? Word = LowerAllString(Word) : Word = UpperAllString(Word);
    for (int i = 0; i < Word.length(); i++) {
        if (Word[i] == C)
            Count++;
        
    }
    return Count;
}
int main()
{
   
    string Word = ReadString("Please Enter Your String ? ");
    cout << "String Length is : " << Word.length() << endl;
    cout << "Capital Letters Count = " << CountCapitalLetters(Word) << endl;
    cout << "Small  Letters Count = " << CountSmallLetters(Word) << endl;

    char C = ReadChar("Please Enter Your Char ? ");
    cout << "Latter '" << C << "' Count : " << CountLetter(Word, C)<<endl;
    cout << "Latter '" << C << "' Or '"<< InvertLetterCase(C)<<"'Count : " << CountLetter(Word, C,false)<<endl;

    
    
}