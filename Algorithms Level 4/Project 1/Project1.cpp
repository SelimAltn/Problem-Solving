#include <iostream>
#include "../../Libraries/Client Libaray/ClientDB.h"
#include "../../Libraries/Client Libaray/ClientDB.cpp"
#include "../../Libraries/String Library/StringLib.h"
#include "../../Libraries/String Library/StringLib.cpp"
#include <cstdlib> 
const string FileName = "D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication5\\User.txt";
const string AdminUserName = "Selim";
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
void PrintTransactionsMenu() {
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



bool IsPowerOfTwo(unsigned int n) {
    return n != 0 && (n & (n - 1)) == 0;
}
struct sUser {
    string UserName, Password;
    int permissions;
    bool MarkForDelete = false;
};
bool FindUser(string UserName, string Password, vector <sUser> vUser, sUser& user) {
    for (sUser U : vUser) {
        if (U.UserName == UserName && U.Password == Password) {
            user = U;
            return true;
        }
    }
    return false;
}
bool FindUserWithUserName(string UserName, vector <sUser> vUser, sUser& user) {
    for (sUser U : vUser) {
        if (StringLib::AreStringsEqual(UserName, U.UserName)) {
            user = U;
            return true;
        }
    }
    return false;
}

sUser ConvertUserLinetoRecord(string LineData, string Seperator = "#//#")
{
    sUser User;
    vector<string> vString;
    vString = StringLib::SplitString(LineData, Seperator);
    User.UserName = vString[0];
    User.Password = vString[1];
    if (stoi(vString[2]) == -1) {
        User.permissions = -1;
    }
    else {
        unsigned int Permissions = stoi(vString[2]);
        User.permissions = Permissions;
    }
    
    return User;
}
bool MarkClientForDeleteByUserName(string UserName, vector<sUser>& vUsers)
{
    for (sUser& c : vUsers)
    {
        if (c.UserName == UserName)
        {
            c.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
string ConvertUserRecordToLine(sUser User, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += User.UserName + Seperator;
    stClientRecord += User.Password + Seperator;
    stClientRecord += to_string(User.permissions);
    return stClientRecord;
}

vector<sUser> SaveUserDataToFile(vector<sUser> vUser)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;
    if (MyFile.is_open())
    {
        for (sUser s : vUser)
        {
            if (s.MarkForDelete == false)
            {
                DataLine = ConvertUserRecordToLine(s);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vUser;
}
void PrintUserData(sUser data)
{
    cout << "---------------------------------------------\n";
    cout << "User Name : " << data.UserName << endl;
    cout << "Password : " << data.Password << endl;
    cout << "Permissions : " << data.permissions << endl;
    cout << "---------------------------------------------\n";
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
bool IsUserNameExists(string UserName, vector<sUser> vUser)
{
    for (sUser u : vUser)
    {
        if (StringLib::AreStringsEqual(u.UserName, UserName))
        {

            return true;
        }
    }
    return false;
}
string ReadUserName(bool Check=true) {
    string UserName;

    if (Check) {
        bool IsExists;
        vector<sUser> vClients = LoadUserDataFromFileToVector();
        do {
            cout << "Enter User Name" << endl;
            getline(cin >> ws, UserName);
            IsExists = IsUserNameExists(UserName, vClients);
            if (IsExists)
                cout << "This User Name already exists. Please enter a unique Name." << endl;
        } while (IsExists);
    }
    else {
        cout << "Enter User Name" << endl;
        getline(cin >> ws, UserName);
    }
    return UserName;
}
bool DeleteUser(vector<sUser> vUser, sUser AktivUser) {
    string UserName = ReadUserName(false);
    sUser DeletedUser;
    if (UserName == AdminUserName && AktivUser.UserName!= AdminUserName) {
        cout << "\a \a \a \n " << endl;
        cout << "You cannot delete the admin account. Please do not attempt such nonsense again, and this matter will be reported to the admin. \n";
        return false;
    }
    if (UserName == AdminUserName && AktivUser.UserName == AdminUserName) {
        cout << "Admin account Indeliblen \n";
        return false;
    }
    if (FindUserWithUserName(UserName, vUser, DeletedUser)) {
        if (DeletedUser.UserName == AktivUser.UserName) {
            cout << "It is not possible for us to delete your account from the account you logged in to." << endl;
            return false;
        }
        char Answer;

        PrintUserData(DeletedUser);
        cout << "Are you sure you want delete this client? y/n \n ?";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            MarkClientForDeleteByUserName(DeletedUser.UserName, vUser);
            SaveUserDataToFile(vUser);
            // Refresh Clients
            vUser = LoadUserDataFromFileToVector();
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else {
        cout << "\ User Name (" << UserName << ") is Not Found!";
        return false;
    }
}

void DeleteUserScreen(vector<sUser> vUser, sUser AktivUser) {
    cout << "========================================\n";
    cout << "\t\Delete User Screen\n";
    cout << "========================================\n";
    DeleteUser(vUser,AktivUser);
    

}


bool GetAnswer(string message) {

    string input;
    char Answer;
    do {
        cout << message << endl;
        getline(cin, input);
        if (!input.empty()) {
            Answer = tolower(input[0]);
        }
        else {
            Answer = ' ';
        }

        if (Answer != 'y' && Answer != 'n')
            cout << "Only (Y/y) or (N/n) allowed!" << endl;

    } while (Answer != 'y' && Answer != 'n');
    return Answer == 'y';
}
int ReadPermission() {
    unsigned int Permissions=0 ;
    cout << "Do yo want to give to " << endl;
    if (GetAnswer("Show Client List (y/n) ? "))
        Permissions += PERMISSION_ShowClientList;
    if (GetAnswer("Add New Client (y/n) ? "))
        Permissions += PERMISSION_AddNewClient;
    if (GetAnswer("Delete Client (y/n) ? "))
        Permissions += PERMISSON_DeleteClient;
    if (GetAnswer("Update Client (y/n) ? "))
        Permissions += PERMISSON_UpdateClient;
    if (GetAnswer("FindClient Client (y/n) ? "))
        Permissions += PERMISSON_FindClient;
    if (GetAnswer("Transactions (y/n) ? "))
        Permissions += PERMISSON_Transactions;
    if (GetAnswer("MangeUser (y/n) ? "))
        Permissions += PERMISSON_ManageUsers;
    return Permissions;
         
}
sUser ReadUser() {
    sUser user;
    user.UserName = ReadUserName();
    user.Password = ClientDB::ReadString("Enter Password ? ");
    if (GetAnswer("Do yo want to give full accsess (y/n) ? "))
        user.permissions = -1;
    else 
        user.permissions = ReadPermission();
    
    return user;
}

void AddNewUser() {
    cout << "Adding New User \n";
    sUser data = ReadUser();
    string LineData = ConvertUserRecordToLine(data);
    ClientDB::AddDataLineToFile(LineData, FileName);
}
void AddUsers() {
    cout << "========================================\n";
    cout << "\t\Add User Screen\n";
    cout << "========================================\n";
    char AddMore;
    do
    {
        AddNewUser();
        cout << "Client Added Successfully do you want to add more clients ? Y / N ? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}


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
void FindUserScreen(vector<sUser> vUser) {
    cout << "========================================\n";
    cout << "\t\Find User Screen\n";
    cout << "========================================\n";
    sUser FoundUser;
    string UserName = ReadUserName(false);
    if (FindUserWithUserName(UserName, vUser, FoundUser)) {
        PrintUserData(FoundUser);
    }
    else {
        cout << "\ User Name (" << UserName << ") is Not Found!";
        
    }
}
void MangeUsersScreen(sUser AktivUser) {
    vector<sUser> vUser = LoadUserDataFromFileToVector();
    short choice;
    while (1) {
        PrintMangeUserMenu();
        choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 6]", 1, 6, "Only [1-7]");
        switch (choice)
        {
        case 1:
            system("cls");
            ListUser();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            AddUsers();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            DeleteUserScreen(vUser,AktivUser);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            FindUserScreen(vUser);
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





void Login(vector<sUser>vUser) {
    string UserName, Password;
    bool chek=false;
    sUser AktivUser;
    do {
        UserName = ReadUserName(false);
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
        PrintTransactionsMenu();
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
            HasUserPermission(AktivUser, 1) ? ClientDB::ShowAllClientsFromFile(vClientData) : AccessDenied();
            system("pause"); 
            system("cls");  
            break;
        case 2:
            system("cls");  
            HasUserPermission(AktivUser, 2) ? ClientDB::AddClients() : AccessDenied();
            system("pause"); 
            system("cls");
            break;
        case 3:
            system("cls");
            HasUserPermission(AktivUser, 4) ? ClientDB::DeleteClient(vClientData) : AccessDenied();

            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            HasUserPermission(AktivUser, 8) ? ClientDB::UpdateClient(vClientData) : AccessDenied();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            HasUserPermission(AktivUser, 16) ? ClientDB::FindClient() : AccessDenied();
            system("pause");
            system("cls");
            break;
        case 6:
            PrintTransactionsMenu();
            HasUserPermission(AktivUser, 32) ? Transactions(AktivUser) : AccessDenied();
            system("pause");
            break;
        case 7:
            system("cls");
            HasUserPermission(AktivUser, 64) ? MangeUsersScreen(AktivUser) : AccessDenied();
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
