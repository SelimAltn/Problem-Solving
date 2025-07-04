#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include <cstdlib> 



using namespace std;


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
    cout << "\t\tMain Menue Scre\n";
    cout << "========================================\n";
    cout << "\t [1] Show Client List." << endl;
    cout << "\t [2] Add New Client." << endl;
    cout << "\t [3] Delete Client." << endl;
    cout << "\t [4] Update Client Info." << endl;
    cout << "\t [5] Find Client." << endl;
    cout << "\t [6] Exit." << endl;
    cout << "========================================\n";
}


void Bank() {
    short choice;
    while (1) {

        PrintMenu();
        choice = ReadNumber("Choose What do you want to do [1 to 6]", 1, 6, "Only [1-6]");
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
            cout << "The program is ending" << endl;
            return ;
        default:
            break;
        }
    }

}

int main() {

    Bank();

}