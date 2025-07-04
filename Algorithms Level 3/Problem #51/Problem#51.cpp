#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string fileName = "D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #51\\file.txt";

struct sClientData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
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

vector<sClientData> SaveCleintsDataToFile(vector<sClientData> vClints) {
    fstream MyFile;
    MyFile.open(fileName, ios::out);
    string DataLine;
    if (MyFile.is_open()) {
        for (sClientData s : vClints) {
            if (s.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(s);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClints;
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



sClientData ChangeClientRecord(string AccountNumber) {
    sClientData Client;
    Client.AccountNumber = AccountNumber;
    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);
    cout << "Enter Name? ";
    getline(cin, Client.Name);
    cout << "Enter Phone? ";
    getline(cin, Client.Phone);
    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;
    return Client;
}

bool UpdateClientByAccountNumber(vector<sClientData>& vClients) {
    sClientData client,newClient;
    string AccountNumber = ReadString("Please enter AccountNumber?");
    char Answer;
    if (FindClientByAccountNumber(AccountNumber, vClients, client)) {
        PrintClientData(client);
        cout << "Are you sure you want Update this client? y/n \n ?";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y') {
            for (sClientData& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
           
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    
}
int main()
{
    vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
    ShowAllClientsFromFile(vClients);
    cout << endl << endl << endl;
    cout << "------------------------------------------------------------\n";
    cout << " " << endl;
    UpdateClientByAccountNumber(vClients);
    cout << endl << endl << endl;
    cout << "------------------------------------------------------------\n";
    ShowAllClientsFromFile(vClients);
}
