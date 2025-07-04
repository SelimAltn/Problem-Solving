#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 
#include <cmath>  
const string FileName = "D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 3\\Problem #50\\file.txt";
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
const double MaximumAmounTCanBeWithdrawnFromAnATM = 10000;
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
    cout << "[9] : Press to return to the main menu " << endl;
    cout << "[10] : Logout " << endl;
}
AppState QuickWithdrawScreen(ClientDB::sClientData &Client, vector<ClientDB::sClientData> &vClient) {
    ClientDB::PrintPageInformation("Quick Withdraw Screen");
    ClientDB::sClientData tempClient;
    PrintQuickWithdrawalAmounts();
    short choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 10]", 1, 10, "Only [1-10]");
    double Balance = QuikWithdrawOptions[choice - 1];
    Balance *= -1;
    if (choice == 9)
        return AppState::ATM;
    if (choice == 10)
        return AppState::LogOut;
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
double ReadTheAmountToBeDepositedForATM(int MultiplesToBeChecked) {
    double Balance = 0.0;
    double result;
    do {
        cout << "Click on the amount you want to deposit" << endl;
        cin >> Balance;
        if (Balance < MultiplesToBeChecked || Balance > MaximumAmounTCanBeWithdrawnFromAnATM)
            cout << "The maximum amount that can be deposited from an ATM is "<<MaximumAmounTCanBeWithdrawnFromAnATM << endl;
        result = fmod(Balance, MultiplesToBeChecked);
        if (result !=0)
            cout << "The amount that can be withdrawn must only be a multiple of " << MultiplesToBeChecked << endl;


    } while (Balance < MultiplesToBeChecked || Balance > MaximumAmounTCanBeWithdrawnFromAnATM || result != 0);
    return Balance;
}
AppState DepozitScreen(ClientDB::sClientData &client, vector<ClientDB::sClientData>& vClient) {
    ClientDB::PrintPageInformation("Depozit Screen ");
    double Balance = ReadTheAmountToBeDepositedForATM(50);
    ClientDB::sClientData tempClient;
    tempClient = ClientDB::DepositClient(client, Balance);
    client.AccountBalance = tempClient.AccountBalance;
    cout << "Your deposit has been completed successfully." << endl;
    ClientDB::AfterDepositWithdrawalProcess(vClient, client, client.AccountNumber); 
    return AppState::ATM;
}
double ReadBalanceForATM(string message, short from, short to, string ErorMessage,int MultiplesToBeChecked) {
    double Balance = 0.0;
    double result;
    do {
        cout << message << endl;
        cin >> Balance;
        if (Balance < from || Balance > to) 
              cout << ErorMessage << to << endl;
        result = fmod(Balance, MultiplesToBeChecked);
        if (result != 0)
            cout << "The amount that can be withdrawn must only be a multiple of " << MultiplesToBeChecked << endl;
        if (to == 0) {
            if (ClientDB::GetAnswer("Would you like to return to the main menu?")) {

                return 0;
            }
        }
        
        
    } while (Balance < from || Balance > to||result!=0);
    if (Balance > MaximumAmounTCanBeWithdrawnFromAnATM) {
        cout << "You can withdraw a maximum of " << MaximumAmounTCanBeWithdrawnFromAnATM << " from an ATM.";
        if (ClientDB::GetAnswer("Press y to withdraw " + to_string(MaximumAmounTCanBeWithdrawnFromAnATM)))
            return MaximumAmounTCanBeWithdrawnFromAnATM;
        else 
            return 0;
            
    }

    return Balance;
}
AppState NormalWithdrawScreen(ClientDB::sClientData &Client, vector<ClientDB::sClientData>& vClient) {
    ClientDB::PrintPageInformation("Normal Withdraw Screen ");
    ClientDB::sClientData tempClient;
    double balance = ReadBalanceForATM("Enter the pie you want to shoot", 0,Client.AccountBalance , "insufficient balance",50);
    if (balance == 0) {
        cout << "You are directed to the main menu"<<endl;
        return AppState::ATM;
    }
    balance *= -1;
    // 50 nin katları kontrolu ekle
    tempClient = ClientDB::DepositClient(Client, balance);
    Client.AccountBalance = tempClient.AccountBalance;
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
    while (State != AppState::Exit) {
        vector<ClientDB::sClientData> vClient = ClientDB::LoadCleintsDataFromFileToVector();
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
        case AppState::Deposit:
            system("cls");
            State = DepozitScreen(ActiveClient, vClient);
            system("pause");
            break;
        case AppState::CheckBalance:
            system("cls");
            State = CheckBalanceScreen(ActiveClient);
            system("pause");
            break;
        case AppState::LogOut :
            system("cls");
            State = AppState::Login;
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
