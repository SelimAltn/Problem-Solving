// ClientDB.h

#ifndef CLIENT_DB_H
#define CLIENT_DB_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../../Libraries/String Library/StringLib.h"

using namespace std;

namespace ClientDB {

    const string fileName ="D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #50\\file.txt";


    struct sClientData {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
    };

    double ReadNumber(string Message);
    string ReadString(string Message);
    void FindClient();
    string ReadAccountNumber(bool Check = true);
    sClientData ReadClient();
    void PrintClientRecord(sClientData Client, bool ShortVersion = false);
    string ConvertRecordToLine(sClientData Client, string Seperator = "#//#");
    sClientData ConvertLinetoRecord(string LineData, string Seperator = "#//#");

    void PrintClientData(sClientData data);
    void AddDataLineToFile(string ClientLine);
    void AddNewClient();
    void AddClients();

    void ShowAllClientsFromFile(vector<sClientData> vClients, bool ShortVersion=false);
    vector<sClientData> LoadCleintsDataFromFileToVector();
    vector<sClientData> SaveCleintsDataToFile(vector<sClientData> vClients);

    bool FindClientByAccountNumber(string AccountNumber, vector<sClientData> vClients, sClientData& client);
    bool IsAccountNumberExists(string AccountNumber, vector<sClientData> vClients);
    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClientData>& vClients);
    bool DeleteClientByAccountNumber(vector<sClientData>& vClients);

    sClientData ChangeClientRecord(string AccountNumber);
    bool UpdateClientByAccountNumber(vector<sClientData>& vClients);
}

#endif // CLIENT_DB_H