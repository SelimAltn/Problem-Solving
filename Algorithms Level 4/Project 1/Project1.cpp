#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 
const string FileName = "D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication5\\User.txt";

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
    cout << "\t [7] Mange Users." << endl;
    cout << "\t [8] Logout." << endl;
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
void PrintMangeUserMenu() {
    cout << "========================================\n";
    cout << "\t\Mange User Screen\n";
    cout << "========================================\n";
    cout << "\t [1] List User." << endl;
    cout << "\t [2] Add New User." << endl;
    cout << "\t [3] Delete User." << endl;
    cout << "\t [4] Update User." << endl;
    cout << "\t [5] Find User." << endl;
    cout << "\t [6] Main Menue." << endl;
    cout << "========================================\n";
}

//**------------------- Bank 3 ----------------------**
unsigned int allPermissions = -1;
const unsigned int PERMISSION_ShowClientList = 1 << 0;     // 0001 = 1
const unsigned int PERMISSION_AddNewClient   = 1 << 1;     // 0010 = 2
const unsigned int PERMISSON_DeleteClient    = 1 << 2;     // 0100 = 4 
const unsigned int PERMISSON_UpdateClient    = 1 << 3;     // 1000 = 8 
const unsigned int PERMISSON_FindClient      = 1 << 4;     // 00010000 = 16
const unsigned int PERMISSON_Transactions    = 1 << 5;     // 00100000 = 32
const unsigned int PERMISSON_ManageUsers     = 1 << 6;     // 01000000 = 64


struct sUser {
    string UserName, Password;
    unsigned int permissions;
};
void Bank(sUser AktivUser);
vector<sUser> LoadUserDataFromFileToVector();
// Authorization control function
bool HasUserPermission(sUser user, unsigned int permission) {
    return (user.permissions & permission) !=0 ||(user.permissions ==(unsigned int)- 1) ;
}
// Add authorization
void GrantPermission(sUser& user, unsigned int permission) {
    user.permissions |= permission;
}
// Remove authorization
void RevokePermission(sUser& user, unsigned int permission) {
    user.permissions &= ~permission;
}
void PrintUserRecord(sUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(15) << left << User.Password;
    cout << "| " << setw(15) << left << User.permissions;
    

}
void ListUser() {
    vector<sUser>vUser = LoadUserDataFromFileToVector();
    cout << "========================================\n";
    cout << "\t\List User Screen\n";
    cout << "========================================\n";
    cout << "\n\t\t\t\t\tClient List (" << vUser.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(15) << "Password";
    cout << "| " << left << setw(15) << "Permission";
    
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
        << endl;
    for (sUser User : vUser)
    {
        PrintUserRecord(User);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"<< endl;

}
void AccessDenied() {
    cout << "\a\a\a\n";
    cout << "--------------------------------------------\n";
    cout << "Access Denied,\n";
    cout << "You dont have Permission To do this : " << endl;
    cout << "Please connect Your Admin \n";
    cout << "--------------------------------------------\n";
    cout << "\a\a\n";
}
void MangeUsersScreen(sUser AktivUser) {
    
    short choice;
    while (1) {
        PrintMangeUserMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 6]", 1, 6, "Only [1-7]");
        switch (choice)
        {
        case 1:
            system("cls");
            HasUserPermission(AktivUser, 1) ? ListUser() : AccessDenied();
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            Bank(AktivUser);
            system("pause");
            system("cls");
            break;
        }

    }
    

    
}
bool IsPowerOfTwo(unsigned int n) {
    return n != 0 && (n & (n - 1)) == 0;
}
sUser ConvertUserLinetoRecord(string LineData, string Seperator = "#//#")
{
    sUser User;
    vector<string> vString;
    vString = StringLib::SplitString(LineData, Seperator);
    User.UserName = vString[0];
    User.Password = vString[1];
    unsigned int Permissions = stoi(vString[2]);
    if (IsPowerOfTwo(Permissions) || vString[2] == "-1") {
        User.permissions = Permissions;
    }
    else {
        User.permissions = 0;
    }
    return User;
}
vector<sUser> LoadUserDataFromFileToVector()
{
    vector<sUser> vUser;
    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vUser.push_back(ConvertUserLinetoRecord(Line));
        }

        MyFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    return vUser;
}


bool FindUser(string UserName,string Password,vector <sUser> vUser,sUser &user){ 
    for (sUser U : vUser) {
        if (U.UserName == UserName && U.Password == Password) {
            user = U;
            return true;
        }
    }
    return false;
}



void Login(vector<sUser>vUser) {
    string UserName, Password;
    bool chek=false;
    sUser AktivUser;
    do {
        UserName = ClientDB::ReadString("Enter User Name ? ");
        Password = ClientDB::ReadString("Enter Password ? ");
        chek = FindUser(UserName, Password, vUser, AktivUser);
        if (!chek) {
            cout << "Invaild password / User Name" << endl;
        }

    } while (!chek);
    

    Bank(AktivUser);
    
}

void LoginScreen() {
    vector<sUser>vUser = LoadUserDataFromFileToVector();
    system("cls");
    cout << "========================================\n";
    cout << "\t\Login Screen\n";
    cout << "========================================\n";
    Login(vUser);
}




void Transactions(sUser AktivUser) {
    short choice;
    while (1) {
        PrintSubMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 4]", 1, 4, "Only [1-4]");
        switch (choice) {
        case 1:
            system("cls");
            ClientDB::DepositProcess();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            ClientDB::PullingProcess();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            ClientDB::TotalBalances();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            Bank(AktivUser);
            system("pause");
            system("cls");
            break;
        }
    }
}

void Bank(sUser AktivUser) {
    short choice;
    while (1) {
        system("cls");
        PrintMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 8]", 1, 8, "Only [1-8]");
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
            Transactions(AktivUser);
            system("pause");
            break;
        case 7:
            system("cls");
            MangeUsersScreen(AktivUser);
            system("pause");
            break;
        case 8:
            system("cls");
            LoginScreen();
            break;
        }
    }

}


int main() {
    LoginScreen();
}
