#include <iostream>
#include <string>
using namespace std;


string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
}

void PrintEachWordInString(string Word){
    string delim=" ";
    short pos=0;
    string Sword;
    while((pos==Word.find(delim))!=std::string::npos){
        Sword = Word.substr(0,pos);
        if(Sword!="")
            cout<<Sword<<endl;
        Word.erase(0,pos+delim.length());
    }
    if(Sword !="")
    cout<<Word<<endl;
}

short CountWords(string Word) {
    short Counter = 0;
    string delim = " ";
    short pos = 0;
    string sWord;
    while ((pos = Word.find(delim)) != std::string::npos) {
        sWord = Word.substr(0, pos);
        if (sWord != "")
            Counter++;
        Word.erase(0, pos + delim.length());
    }
    if (Word != "")
        Counter++;
    return Counter;
}

int main()
{
    string Str = ReadString("Please Enter Your String ? ");
    PrintEachWordInString(Str);
    cout << "\nThe number of words in your string is: " << CountWords(Str) << endl;


    
}