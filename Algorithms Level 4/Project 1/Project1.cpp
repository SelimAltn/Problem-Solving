#include <iostream>
#include "../../Libraries/User Library/UserDB.h"
#include "../../Libraries/User Library/UserDB.cpp"
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"


#include <cstdlib> 


const string FileName = "D:\programing\\Algorithms & Problem-Solving\\Problem-Solving\\Algorithms Level 4\\Project 1\\User.txt";
const string AdminUserName = "Selim";
enum class AppState {
    Login,
    Bank,
    ManageUsers,
    Transactions,
    Exit
};


void PrintMenu() {

    ClientDB::PrintPageInformation("Main Menue Screen");
    cout << "\t [1] Show Client List." << endl;
    cout << "\t [2] Add New Client." << endl;
    cout << "\t [3] Delete Client." << endl;
    cout << "\t [4] Update Client Info." << endl;
    cout << "\t [5] Find Client." << endl;
    cout << "\t [6] Transactions." << endl;
    cout << "\t [7] Mange Users." << endl;
    cout << "\t [8] Logout." << endl;
    cout << "=======================================================================\n";
}   
void PrintTransactionsMenu() {
    system("cls");
    ClientDB::PrintPageInformation("Transactions Menue Screen");
    cout << "\t [1] Depostit." << endl;
    cout << "\t [2] Withdraw." << endl;
    cout << "\t [3] Total Balances." << endl;
    cout << "\t [4] Main Menue." << endl;
    cout << "=======================================================================\n";
}
void PrintMangeUserMenu() {
    ClientDB::PrintPageInformation("Mange User Screen");
    cout << "\t [1] List User." << endl;
    cout << "\t [2] Add New User." << endl;
    cout << "\t [3] Delete User." << endl;
    cout << "\t [4] Update User." << endl;
    cout << "\t [5] Find User." << endl;
    cout << "\t [6] Main Menue." << endl;
    cout << "=======================================================================\n";
}


AppState MangeUsersScreen(UserDB::sUser AktivUser, vector<UserDB::sUser> &vUser) {
    short choice;
    PrintMangeUserMenu();
    choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 6]", 1, 6, "Only [1-7]");
    switch (choice)
    {
    case 1:
        system("cls"); UserDB::ListUserScreen();            break;
    case 2:
        system("cls"); UserDB::AddUsers();                  break;
    case 3:
        system("cls"); UserDB::DeleteUserScreen(AktivUser); break;
    case 4:
        system("cls"); UserDB::UpdetUserScreen(AktivUser);  break;
    case 5:
        system("cls"); UserDB::FindUserScreen();            break;
    case 6:
        system("cls");
        return AppState::Bank;
    }
    system("pause");
    system("cls");
    vUser = UserDB::LoadUserDataFromFileToVector();
    return AppState::ManageUsers;

}
AppState LoginScreen(UserDB::sUser &ActiveUser,vector<UserDB::sUser>&vUser) {
    string UserName, Password;
    system("cls");
    ClientDB::PrintPageInformation("Login Screen");
    bool chek=false;
    do {
        UserName = UserDB::ReadUserName(false);
        Password = ClientDB::ReadString("Enter Password ? ");
        chek = UserDB::FindUser(UserName, Password, vUser, ActiveUser);
        if (!chek) {
            cout << "Invaild password / User Name" << endl;
        }

    } while (!chek);
    return  AppState::Bank;
}

AppState Transactions(UserDB::sUser AktivUser) {
    short choice;
    PrintTransactionsMenu();
    choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 4]", 1, 4, "Only [1-4]");
    switch (choice) {
    case 1:
        system("cls"); ClientDB::DepositProcess(); break;
    case 2:
        system("cls"); ClientDB::PullingProcess(); break;
    case 3:
        system("cls"); ClientDB::TotalBalances() ; break;
    case 4:
        system("cls"); return AppState::Bank;
    }
    system("pause");
    system("cls");
    return AppState::Transactions;
}

AppState BankScreen(UserDB::sUser &AktivUser , vector<ClientDB::sClientData> &vClientData) {
    short choice;
    system("cls");
    PrintMenu();
    choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 8]", 1, 8, "Only [1-8]");
    vClientData = ClientDB::LoadCleintsDataFromFileToVector();
    switch (choice) {
    case 1:
        system("cls");
        UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::ShowClientList)) ? ClientDB::ShowAllClientsScreen(vClientData) : UserDB::AccessDenied();
        break;
    case 2:
        system("cls");
        UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::AddNewClient)) ? ClientDB::AddClients() : UserDB::AccessDenied();
        break;
    case 3:
        system("cls");
        UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::DeleteClient)) ? ClientDB::DeleteClient(vClientData) : UserDB::AccessDenied();
        break;
    case 4:
        system("cls");
        UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::UpdateClient)) ? ClientDB::UpdateClient(vClientData) : UserDB::AccessDenied();
        break;
    case 5:
        system("cls");
        UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::FindClient)) ? ClientDB::FindClient() : UserDB::AccessDenied();
        break;
    case 6:
        system("cls");
        if (UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::Transactions))) {
            return AppState::Transactions;
        }
        else
            UserDB::AccessDenied();
        break;
    case 7:
        system("cls");
        if (UserDB::HasUserPermission(AktivUser, static_cast<unsigned int>(UserDB::Permissions::ManageUsers))) {
            return AppState::ManageUsers;
        }
        else {
            UserDB::AccessDenied();
        }
        break;
    case 8:
        return AppState::Login;
    }
    vClientData = ClientDB::LoadCleintsDataFromFileToVector();
    system("pause");
    system("cls");
    return AppState::Bank;
}
void RunApp() {
    AppState State = AppState::Login;
    UserDB::sUser ActiveUser;
    vector<UserDB::sUser> users = UserDB::LoadUserDataFromFileToVector();
    vector<ClientDB::sClientData> vClientData = ClientDB::LoadCleintsDataFromFileToVector();
    while (State != AppState::Exit) {
        switch (State)
        {
        case AppState::Login:
            State = LoginScreen(ActiveUser, users); break;
        case AppState::Bank:
            State = BankScreen(ActiveUser,vClientData); break;
        case AppState::ManageUsers:
            State = MangeUsersScreen(ActiveUser,users); break;
        case AppState::Transactions:
            State = Transactions(ActiveUser); break;
            break;
        case AppState::Exit:
            break;
        default:
            break;
        }
    }
}

int main() {
    RunApp();
}

