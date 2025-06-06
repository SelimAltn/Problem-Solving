#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include <cstdlib> 


const string FileName ="D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication5\\User.txt" ;


void Bank();

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
    cout << "\t [1] List User." << endl;
    cout << "\t [2] Add New User." << endl;
    cout << "\t [3] Delete User." << endl;
    cout << "\t [4] Update User." << endl;
    cout << "\t [5] Find User." << endl;
    cout << "\t [6] Main Menue." << endl;
    cout << "========================================\n";
}

//**------------------- Bank 3 ----------------------**

struct sUser {
    string UserName, Password;
    int Permissions;
};

void MangeUsersScreen() {
    cout << "========================================\n";
    cout << "\t\Mange User Screen\n";
    cout << "========================================\n";
    PrintMangeUserMenu();
}
sUser ConvertUserLinetoRecord(string LineData, string Seperator = "#//#")
{
    sUser User;
    vector<string> vString;
    vString = StringLib::SplitString(LineData, Seperator);
    User.UserName = vString[0];
    User.Password = vString[1];
    User.Permissions = stoi(vString[2]);
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

bool FindUser(string UserName,string Password,vector <sUser> vUser){ 
    for (sUser U : vUser) {
        if (U.UserName == UserName && U.Password == Password) {
            return true;
        }
    }
    return false;
}
void Login(vector<sUser>vUser) {
    string UserName, Password;
    bool chek=false;
    do {
        UserName = ClientDB::ReadString("Enter User Name ? ");
        Password = ClientDB::ReadString("Enter Password ? ");
        chek = FindUser(UserName, Password, vUser);
        if (!chek) {
            cout << "Invaild password / User Name" << endl;
        }

    } while (!chek);
    Bank();
}

void LoginScreen() {
    vector<sUser>vUser = LoadUserDataFromFileToVector();
    system("cls");
    cout << "========================================\n";
    cout << "\t\Login Screen\n";
    cout << "========================================\n";
    Login(vUser);
}




void Transactions() {
    short choice;
    while (1) {
        PrintSubMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 4]", 1, 7, "Only [1-7]");
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
        system("cls");
        PrintMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 7]", 1, 8, "Only [1-8]");
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
            system("cls");
            MangeUsersScreen();
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
