#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LowerAllString(string Word) {
    for (int i = 0; i < Word.length(); i++) {
        Word[i] = tolower(Word[i]);
    }
    return Word;
}

vector<string> SplitString(string Word,string delim=" ") {
    vector<string>vString;
    short pos = 0;
    string sWord;
    while ((pos = Word.find(delim)) != std::string::npos) {
        sWord = Word.substr(0, pos);
        if (sWord != "")
            vString.push_back(sWord);
        Word.erase(0, pos + delim.length());
    }
    if (Word != "")
        vString.push_back(Word);
    return vString;
}
string JoinString(vector <string> vString,string delim = " ") {
    if (vString.empty())
        return "";
    string Word; 
    for (string& S : vString) {
        Word += (S+delim);
    }
    return Word.substr(0,Word.length()-delim.length());
}

string ReplaceWordInString(string Str, string StringToReplace, string ReplaceTo,bool MatchCase=true) {
    vector<string>vString;
    vString = SplitString(Str);
    string target = MatchCase ? StringToReplace : LowerAllString(StringToReplace);
    for (string &s : vString) {
        string current = MatchCase ? s : LowerAllString(s);
        if (current == target) {
            s = ReplaceTo;
        }
    }
    return JoinString(vString);
}
string ReplaceWordInStringUsingBuiltInFunction(string Str,string StringToReplace, string ReplaceTo) { 
    short Pos = Str.find(StringToReplace);
    while (Pos != std::string::npos) {
        Str = Str.replace(Pos, StringToReplace.length(), ReplaceTo);
        Pos = Str.find(StringToReplace);
    }
    return Str;

}
int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";  
    string StringToReplace = "jordan";
    string ReplaceTo = "USA";
    cout << S1 << endl;
    cout << "\n\nString After Replace (Using Built In Function):\n";
    cout << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);

    cout << "\n\nString After Replace (with match case):\n";
    cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo);

    cout << "\n\nString After Replace (with dont match case):\n";
    cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo, false);

}
