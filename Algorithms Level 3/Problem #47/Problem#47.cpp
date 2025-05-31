#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string fileName = "D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #47\\file.txt";


struct sClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
double ReadNumber(string Message) {
    double Number;
    cout << Message << endl;
    cin >> Number;
    return Number;
}
string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
}
sClientData ReadClient() {
    sClientData Client;
    cout << "Enter Client Account Number"<<endl;
    getline(cin >> ws, Client.AccountNumber);
    Client.Name = ReadString("Enter Client Name");
    Client.PinCode = ReadString("Enter Client Pin Code");
    Client.Phone = ReadString("Enter Client Phone");
    Client.AccountBalance = ReadNumber("Enter Client Account Balance");
    return Client;
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

string ConvertRecordToLine(sClientData Client,string Seperator ="#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}



void AddDataLineToFile(string ClientLine) {
    fstream MyFile;
    MyFile.open(fileName, ios::out| ios::app);
    if (MyFile.is_open()) {
        MyFile << ClientLine << endl;
        MyFile.close();
    }
    else {
        cout << "Unable to open the file";
    }
}
void AddNewClient() {
    cout << "Adding New Client \n";
    sClientData data = ReadClient();
    string LineData = ConvertRecordToLine(data);
    AddDataLineToFile(LineData);

}
void AddClients() {
    char AddMore;
    do {
        AddNewClient();
        cout<<"Client Added Successfully do you want to add more clients ? Y / N ? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');

}
int main()
{
    AddClients();
}
