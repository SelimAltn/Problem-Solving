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

    const string ClientFileName ="D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #50\\file.txt";
    const double MaximumAmounTCanBeWithdrawnFromAnATM = 10000;


    struct sClientData {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
    };
    

    double ReadNumber(string Message);
    void PrintPageInformation(string message);
    string ReadString(string Message);
    short ReadNumber(string message, short from, short to, string ErorMessage);
    void FindClient();
    bool ChekClientPinCode(string AccountNumber, string PinCode, vector<sClientData> vClients);
    string ReadAccountNumber(bool Check = true);
    sClientData ReadClient();
    void PrintClientRecord(sClientData Client, bool ShortVersion = false);
    string ConvertRecordToLine(sClientData Client, string Seperator = "#//#");

    sClientData ConvertLinetoRecord(string LineData, string Seperator = "#//#");

    void PrintClientData(sClientData data);
    void AddDataLineToFile(string ClientLine, string FileName);
    void AddNewClient();
    void AddClients();
    void ShowAllClientsScreen(vector<sClientData> vClients);
    void ShowAllClientsFromFile(vector<sClientData> vClients, bool ShortVersion=false);
    vector<sClientData> LoadCleintsDataFromFileToVector();
    vector<sClientData> SaveCleintsDataToFile(vector<sClientData> vClients);

    bool FindClientByAccountNumber(string AccountNumber, vector<sClientData> vClients, sClientData& client);
    bool IsAccountNumberExists(string AccountNumber, vector<sClientData> vClients);
    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClientData>& vClients);
    void DeleteClient(vector<sClientData>& vClients);
    bool DeleteClientByAccountNumber(vector<sClientData>& vClients);
    bool GetAnswer(string message);
    sClientData ChangeClientRecord(string AccountNumber);
    void UpdateClient(vector<sClientData>& vClients);
    bool UpdateClientByAccountNumber(vector<sClientData>& vClients);
    sClientData DepositClient(sClientData Client, double Balance);
    bool HasSufficientBalance(sClientData client, double Balance);
    double ReadBalance(string message, short from, short to, string ErorMessage, bool forMaxBalance = false);
    double CheckBalance(sClientData client);
    void AfterDepositWithdrawalProcess(vector<sClientData> vClients, sClientData client, string AccountNumber, bool PrintClientInformation = false);
    void DepositProcess();
    void PullingProcess();
    double CalculateTotalBalances(vector<sClientData> vClients);
    void TotalBalances();
}

#endif // CLIENT_DB_H