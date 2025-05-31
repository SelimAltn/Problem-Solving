#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string fileName = "D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #48\\file.txt";

string ReadString(string Message) {
    string Str;
    cout << Message << endl;
    getline(cin, Str);
    return Str;
}
struct sClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
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

vector<sClientData> LoadCleintsDataFromFileToVector() {
    vector<sClientData> vClients;
    fstream MyFile;

    MyFile.open(fileName, ios::in);

    if (MyFile.is_open()) {
        string Line;

        while (getline(MyFile, Line)) {
            vClients.push_back(ConvertLinetoRecord(Line));
        }

        MyFile.close(); 
    }
    else {
        cout << "Unable to open file." << endl;
    }
    return vClients;
}
void PrintClientRecord(sClientData Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowAllClientsFromFile(vector<sClientData> vClients) {
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    for (sClientData client : vClients) {
        PrintClientRecord(client);
        cout << endl;
    }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

bool FindClientByAccountNumber(string AccountNumber, vector<sClientData> vClients, sClientData &client) {

    for (sClientData c : vClients) {
        if (c.AccountNumber == AccountNumber) {
            client = c;
            return true;
        }
    }
    return false;
   
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
    vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
    ShowAllClientsFromFile(vClients);
    cout << endl << endl << endl;
    cout << "------------------------------------------------------------\n";
    cout << " " << endl;
    sClientData client;
    string AccountNumber  = ReadString("Please enter AccountNumber?");
    if (FindClientByAccountNumber(AccountNumber, vClients, client)) {
        PrintClientData(client);
    }
    else
        cout << "\nClient with Account Number (" << AccountNumber <<") is Not Found!";
    
}
