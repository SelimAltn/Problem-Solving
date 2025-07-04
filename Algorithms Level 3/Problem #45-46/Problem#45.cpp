#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
    Client.Name = ReadString("Enter Client Name");
    Client.AccountNumber = ReadString("Enter Client Account Number");
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
sClientData ConvertLinetoRecord(string LineData, string Seperator = "#//#") {
    sClientData Client;
    vector<string>vString;
    vString = SplitString(LineData, Seperator);
    Client.AccountNumber = vString[0];
    Client.PinCode = vString[1];
    Client.Name = vString[2];
    Client.Phone = vString[3];
    Client.AccountBalance = stod(vString[4]);
    return Client;

}

void PrintClientData(sClientData data) {
    cout << "Account Number : " << data.AccountNumber << endl;
    cout << "Pin Code : " << data.PinCode << endl;
    cout << "Name : " << data.Name << endl;
    cout << "Phone : " << data.Phone << endl;
    cout << "Account Balance : " << data.AccountBalance << endl;

}
int main()
{
    sClientData data = ReadClient();
    string LineData = ConvertRecordToLine(data);
    cout << LineData << endl;
    sClientData data2 = ConvertLinetoRecord(LineData);
    PrintClientData(data2);
}
