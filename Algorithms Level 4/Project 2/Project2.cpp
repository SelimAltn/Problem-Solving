#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 
const string FileName = "D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication5\\User.txt";
const string AdminUserName = "Selim";
enum class AppState {
    Login,
    ATM,
    QuickWithdraw,
    NormalWithdraw,
    Deposit,
    CheckBalance,
    LogOut,
    Exit
};

AppState ChekClientPinCodeForLogin(ClientDB::sClientData& ActiveClient, vector<ClientDB::sClientData>& vClient) {
    for (int i = 3; i > 0; --i) {
        string PinCode = ClientDB::ReadString("Enter Pin Code ? ");
        if (ClientDB::ChekClientPinCode(ActiveClient.AccountNumber, PinCode, vClient)) {
            return AppState::ATM;
        }
        else {
            if (i > 1)
                cout << "Invalid PIN code! You have " << (i - 1) << " attempt(s) left.\a\n";
            else 
                cout << "Invalid PIN code! No attempts left. Returning to the previous menu...\a\n";
        }
    }
    return AppState::Exit;
}
AppState LoginScreen(ClientDB::sClientData & ActiveClient, vector<ClientDB::sClientData>& vClient) {
    string AccountNumber, PinCode;
    system("cls");
    ClientDB::PrintPageInformation("Login Screen");
    bool chek = false;
    do {
        AccountNumber = ClientDB::ReadAccountNumber(false);
        chek = ClientDB::FindClientByAccountNumber(AccountNumber,vClient, ActiveClient);
        if (chek) {
            return ChekClientPinCodeForLogin(ActiveClient, vClient);
        }
        else if (!chek) {
            cout << "Invaild Account Number" << endl;
        }

    } while (!chek);
}
void RunApp() {
    AppState State = AppState::Login;
    ClientDB::sClientData ActiveClient;
    vector<ClientDB::sClientData> vClient = ClientDB::LoadCleintsDataFromFileToVector();
    while (State != AppState::Exit) {
        switch (State)
        {
        case AppState::Login:
            State = LoginScreen(ActiveClient, vClient); break;
        case AppState::ATM:
            cout << "ATM";
        
        default:
            break;
        }
    }
}
int main()
{
    RunApp();

}
