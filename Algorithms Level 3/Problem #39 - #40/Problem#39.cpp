#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vString,string delim = " ") {
    if (vString.empty())
        return "";
    string Word; 
    for (string& S : vString) {
        Word += (S+delim);
    }
    return Word.substr(0,Word.length()-delim.length());
}
string JoinString(string arrString[],short length, string delim = " ") {
    string Word;
    for(int i=0;i<length;i++)
        Word += (arrString[i] + delim);
    return Word.substr(0, Word.length() - delim.length());
}
int main()
{
    vector<string> vString = { "Mohammed","Faid","Ali","Maher" };
    string arrString[] = { "Mohammed","Faid","Ali","Maher" };
    cout << "\nVector after join: \n";
    cout << JoinString(vString," | ");
    cout << "\n\nArray after join: \n";
    cout << JoinString(arrString,4, " | ");

}
