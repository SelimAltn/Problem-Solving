#include <iostream>
#include <string>
using namespace std;
string TrimLeft(string Word) {
    for (int i = 0; i < Word.length(); i++) {
        if (Word[i] != ' ')
            return Word.substr(i, Word.length()-1);
    }
    return "";
}
string TrimRight(string Word) {
    for (int i = Word.length()-1; i >=0; i--) {
        if (Word[i] != ' ')
            return Word.substr(0, i + 1);
    }
    return "";
}
string Trim(string Word) {
    return TrimRight(TrimLeft(Word));
}
int main()
{
    
    string Word = "        Selim Altin       ";
    cout << Word << endl;
    cout << "Trim Left :  " << TrimLeft(Word) << endl;
    cout << "Trim Right :  " << TrimRight(Word) << endl;
    cout << "Trim  :  "<<Trim(Word)<<endl;

}