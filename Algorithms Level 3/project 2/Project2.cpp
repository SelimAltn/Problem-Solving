#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 

void Bank();
short ReadNumber(string message, short from, short to, string ErorMessage) {
    short number;
    do {
        cout << message << endl;
        cin >> number;
        if (number < from || number > to)
            cout << ErorMessage << endl;
    } while (number < from || number > to);
    return number;
}
void PrintMenu() {
    cout << "========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "========================================\n";
    cout << "\t [1] Show Client List." << endl;
    cout << "\t [2] Add New Client." << endl;
    cout << "\t [3] Delete Client." << endl;
    cout << "\t [4] Update Client Info." << endl;
    cout << "\t [5] Find Client." << endl;
    cout << "\t [6] Transactions." << endl;
    cout << "\t [7] Exit." << endl;
    cout << "========================================\n";
}   
void PrintSubMenu() {
    system("cls");
    cout << "========================================\n";
    cout << "\t\Transactions Menue Screen\n";
    cout << "========================================\n";
    cout << "\t [1] Depostit." << endl;
    cout << "\t [2] Withdraw." << endl;
    cout << "\t [3] Total Balances." << endl;
    cout << "\t [4] Main Menue." << endl;
    cout << "========================================\n";
}

void Deposit() {
    cout << "========================================\n";
    cout << "\t\Deposit Screen\n";
    cout << "========================================\n";
    string AccountNumber =  ClientDB::ReadAccountNumber(false);
    cout << "The Following are the Client details : \n";
    
        ClientDB::sClientData client;
        vector<ClientDB::sClientData> vClients = ClientDB::LoadCleintsDataFromFileToVector();
        if (ClientDB::FindClientByAccountNumber(AccountNumber, vClients, client)) {
            ClientDB::PrintClientData(client);
        }
        else
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";



}
void Transactions() {
    short choice;
    while (1) {
        PrintSubMenu();
        choice = ReadNumber("Choose What do you want to do [1 to 4]", 1, 7, "Only [1-7]");
        switch (choice) {
        case 1:
            system("cls");
            Deposit();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");

            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");

            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            Bank();
            system("pause");
            system("cls");
            break;
        }
    }
}

void Bank() {
    short choice;
    while (1) {

        PrintMenu();
        choice = ReadNumber("Choose What do you want to do [1 to 7]", 1, 7, "Only [1-7]");
        vector<ClientDB::sClientData> vClientData = ClientDB::LoadCleintsDataFromFileToVector();
        switch (choice) {
        case 1:
            system("cls");   
            ClientDB::ShowAllClientsFromFile(vClientData);
            system("pause"); 
            system("cls");  
            break;
        case 2:
            system("cls");  
            ClientDB::AddClients();
            system("pause"); 
            system("cls");
            break;
        case 3:
            system("cls");
            ClientDB::DeleteClientByAccountNumber(vClientData);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            ClientDB::UpdateClientByAccountNumber(vClientData);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            ClientDB::FindClient();
            system("pause");
            system("cls");
            break;
        case 6:
            PrintSubMenu();
            Transactions();
            system("pause");
            break;
        case 7:
            cout << "The program is ending" << endl;
            return;
        default:
            break;
        }
    }

}

int main() {

    Bank();

}
