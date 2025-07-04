#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
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
void PrintVector(vector<string>vString) {
    for(string &S:vString)
        cout << S << endl;
}
int main()
{
    string Str = ReadString("Please Enter Your String ? ");
    vector <string>vString = SplitString(Str,"#");
    PrintVector(vString);

}
