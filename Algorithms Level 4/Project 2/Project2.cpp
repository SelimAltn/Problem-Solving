#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 
const string FileName = "D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication6\\User.txt";
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
void PrintAtmMenu() {
    ClientDB::PrintPageInformation("ATM main menu scrren");
    cout << "[1] Quik Withdraw. "   << endl;
    cout << "[2] Normal Withdraw. " << endl;
    cout << "[3] Deposit "          << endl;
    cout << "[4] Check Balance "    << endl;
    cout << "[5] Logout "    << endl;
}
constexpr int QuikWithdrawOptions[] = { 50, 100, 150, 200, 300, 400, 500, 1000 };

void PrintQuickWithdrawalAmounts() {
    cout << "[1] : 50"  << "\t\t\t [2] : 100" << endl;
    cout << "[3] : 150" << "\t\t\t [4] : 200" << endl;
    cout << "[5] : 300" << "\t\t\t [6] : 400" << endl;
    cout << "[7] : 500" << "\t\t\t [8] : 1000" << endl;
}
AppState QuickWithdrawScreen(ClientDB::sClientData &Client, vector<ClientDB::sClientData> &vClient) {
    ClientDB::PrintPageInformation("Quick Withdraw Screen");
    ClientDB::sClientData tempClient;
    PrintQuickWithdrawalAmounts();
    short choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 8]", 1, 8, "Only [1-8]");
    double Balance = QuikWithdrawOptions[choice - 1];
    Balance *= -1;
    if (HasSufficientBalance(Client, QuikWithdrawOptions[choice - 1])) {
        tempClient = ClientDB::DepositClient(Client,Balance);
        Client.AccountBalance = tempClient.AccountBalance;
        cout << "Your withdrawal has been completed successfully"<<endl;
        ClientDB::AfterDepositWithdrawalProcess(vClient, Client, Client.AccountNumber);
        return AppState::ATM;
    }
    else {
        cout << "insufficient funds"<<endl;
        return AppState::ATM;
    }
    

}
AppState NormalWithdrawScreen(ClientDB::sClientData Client, vector<ClientDB::sClientData>& vClient) {
    ClientDB::PrintPageInformation("Normal Withdraw Screen ");
    ClientDB::sClientData tempClient;
    double balance = ClientDB::ReadBalance("Enter the pie you want to shoot", 0,Client.AccountBalance , "Maximum amount that can be withdrawn from an ATM is : ", true);
    balance *= -1;
    // 50 nin katları kontrolu ekle
    cout << "Your withdrawal has been completed successfully" << endl;
    ClientDB::AfterDepositWithdrawalProcess(vClient, Client, Client.AccountNumber);
    return AppState::ATM;

}
AppState CheckBalanceScreen(ClientDB::sClientData client) {
    ClientDB::PrintPageInformation("Chek Balance Screen ");
    cout << "Remaining funds in your account :  [ " << ClientDB::CheckBalance(client)<<" ]"<<endl;
    return AppState::ATM;

}
AppState AtmScreen() {
    PrintAtmMenu();
    short choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 5]", 1, 5, "Only [1-5]");
    switch (choice)
    {
    case 1 :
        return AppState::QuickWithdraw;
        break;
    case 2:
        return AppState::NormalWithdraw;
        break;
    case 3:
        return AppState::Deposit;
        break;
    case 4:
        return AppState::CheckBalance;
        break;
    case 5:
        return AppState::LogOut;
        break;
    default:
        return AppState::ATM;
    }
   
}



void RunApp() {
    AppState State = AppState::Login;
    ClientDB::sClientData ActiveClient;
    vector<ClientDB::sClientData> vClient = ClientDB::LoadCleintsDataFromFileToVector();
    while (State != AppState::Exit) {
        switch (State) {
        case AppState::Login:
            system("cls");
            State = LoginScreen(ActiveClient, vClient); 
            break;
        case AppState::ATM:
            system("cls");
            State = AtmScreen();
            break;
        case AppState::QuickWithdraw :
            system("cls");
            State = QuickWithdrawScreen(ActiveClient,vClient);
            system("pause");
            break;
        case AppState::NormalWithdraw:
            system("cls");
            State = NormalWithdrawScreen(ActiveClient, vClient); 
            system("pause");
            break;
        case AppState::CheckBalance:
            system("cls");
            State = CheckBalanceScreen(ActiveClient);
            system("pause");
            break;

        default:
            break;
        }
        system("cls");
    }
}
int main()
{
    RunApp();

}
