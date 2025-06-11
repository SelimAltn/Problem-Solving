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
    Bank,
    ManageUsers,
    Transactions,
    Exit
};
enum class Permissions : unsigned int {
    None = 0,
    ShowClientList = 1 << 0, // 1
    AddNewClient = 1 << 1, // 2
    DeleteClient = 1 << 2, // 4
    UpdateClient = 1 << 3, // 8
    FindClient = 1 << 4, // 16
    Transactions = 1 << 5, // 32
    ManageUsers = 1 << 6, // 64
    FullAccess = static_cast<unsigned int>(-1) // 4294967295
};
struct sUser {
    string UserName, Password;
    int permissions;
    bool MarkForDelete = false;
};
// Authorization control function
bool HasUserPermission(sUser user, unsigned int permission) {
    return (user.permissions & static_cast<unsigned int>(permission)) != 0
        || user.permissions == static_cast<unsigned int>(Permissions::FullAccess);
}
// Add authorization
void GrantPermission(sUser& user, unsigned int permission) {
    user.permissions |= permission;
}
// Remove authorization
void RevokePermission(sUser& user, unsigned int permission) {
    user.permissions &= ~permission;
}
void ListUser();
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



bool FindUser(string UserName, string Password, vector <sUser> vUser, sUser& user) {
    for (sUser U : vUser) {
        if (U.Password == Password) {
            if (StringLib::AreStringsEqual(U.UserName, UserName)) {
                user = U;
                return true;
            }
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

    if (StringLib::AreStringsEqual(UserName, AdminUserName) && !StringLib::AreStringsEqual(AktivUser.UserName, AdminUserName)) {
        cout << "\a \a \a \n " << endl;
        cout << "You cannot delete the admin account. Please do not attempt such nonsense again, and this matter will be reported to the admin. \n";
        return false;
    }
    if (StringLib::AreStringsEqual(UserName, AdminUserName) && StringLib::AreStringsEqual(AktivUser.UserName, AdminUserName)) {
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
            return true;
        }
    }
    else {
        cout << "\ User Name (" << UserName << ") is Not Found!";
        return false;
    }
}

void DeleteUserScreen( sUser AktivUser) {
    vector<sUser> vUser = LoadUserDataFromFileToVector();
    ClientDB::PrintPageInformation("Delete User Screen");
    ListUser();
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
    sUser tempUser;
    tempUser.permissions = 0;

    if (GetAnswer("Do yo want to give full accsess (y/n) ? ")) {
        tempUser.permissions = static_cast<unsigned int>(Permissions::FullAccess);
        return tempUser.permissions;
    }
    cout << "Do yo want to give to " << endl;
    if (GetAnswer("Show Client List (y/n) ? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::ShowClientList));
    if (GetAnswer("Add New Client (y/n) ? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::AddNewClient));
    if (GetAnswer("Delete Client (y/n) ? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::DeleteClient));
    if (GetAnswer("Update Client (y/n)? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::UpdateClient));
    if (GetAnswer("Find Client (y/n)? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::FindClient));
    if (GetAnswer("Transactions (y/n)? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::Transactions));
    if (GetAnswer("Manage Users (y/n)? "))
        GrantPermission(tempUser, static_cast<unsigned int>(Permissions::ManageUsers));
    return tempUser.permissions;

}
sUser ReadUser() {
    sUser user;
    user.UserName = ReadUserName();
    user.Password = ClientDB::ReadString("Enter Password ? ");
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
    ClientDB::PrintPageInformation("Add Users Screen");
    char AddMore;
    do
    {
        AddNewUser();
        cout << "Client Added Successfully do you want to add more clients ? Y / N ? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}


vector<sUser> LoadUserDataFromFileToVector();

void PrintUserRecord(sUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(20) << left << User.Password;
    cout << "| " << setw(20) << left << User.permissions;
    

}
void ListUserScreen() {
    ClientDB::PrintPageInformation("List User Screen");
    ListUser();
}
void ListUser() {
    vector<sUser>vUser = LoadUserDataFromFileToVector();
    cout << "\n\t\t \tClient List (" << vUser.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "__________________\n" << endl;
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(20) << "Password";
    cout << "| " << left << setw(20) << "Permission";
    
    cout << "\n_______________________________________________________";
    cout << "__________________\n"
        << endl;
    for (sUser User : vUser)
    {
        PrintUserRecord(User);
        cout << endl;
    }
    cout << "\n_______________________________________________________";
    cout << "__________________\n";

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
void FindUserScreen() {
    vector<sUser> vUser = LoadUserDataFromFileToVector();
    ClientDB::PrintPageInformation("Find User Screen");
    sUser FoundUser;
    string UserName = ReadUserName(false);
    if (FindUserWithUserName(UserName, vUser, FoundUser)) {
        PrintUserData(FoundUser);
    }
    else {
        cout << "\ User Name (" << UserName << ") is Not Found!";
        
    }
}
sUser ChangeUserRecord(sUser& orig) {
    sUser UpdatedUser= orig;

    if (GetAnswer("Do you want to change all information?")) {
        return ReadUser();
    }
    if (GetAnswer("Do you want to change account name ?")) {
        UpdatedUser.UserName = ReadUserName();
    }
    if (GetAnswer("Do you want to change Password ?")) {
        UpdatedUser.Password = ClientDB::ReadString("Enter Password ? ");
    }
    if (GetAnswer("Do you want to change permissions ?")) {
        UpdatedUser.permissions = ReadPermission();
    }
    return UpdatedUser;
}
bool UpateUser(vector<sUser>& vUser, sUser& AktivUser) {
    string UserName = ReadUserName(false);
    string Password;
    sUser UpdatedUser;

    if (StringLib::AreStringsEqual(UserName, AdminUserName) && !StringLib::AreStringsEqual(AktivUser.UserName, AdminUserName)) {
        cout << "\a \a \a \n " << endl;
        cout << "You cannot Update the admin account. Please do not attempt such nonsense again, and this matter will be reported to the admin. \n";
        return false;
    }
    if (StringLib::AreStringsEqual(UserName, AdminUserName) && StringLib::AreStringsEqual(AktivUser.UserName, AdminUserName)) {
        cout << "Only the password can be updated for the admin account. \n";
        Password = ClientDB::ReadString("Enter Password ? ");
        if (GetAnswer("Are you sure you want Updated this User? y/n ? ")) {
            AktivUser.Password = Password;
            for (sUser& U : vUser)
            {
                if (U.UserName == AdminUserName)
                {
                    U.Password = Password;
                    break;
                }
            }
            SaveUserDataToFile(vUser);
            cout << "\n Admin Password Updated Successfully.";
            return true;
        }
        else
            return false;
    }
    if (FindUserWithUserName(UserName, vUser, UpdatedUser)) {
        if (UpdatedUser.UserName == AktivUser.UserName) {
            cout << "It is not possible for us to Update your account from the account you logged in to." << endl;
            return false;
        }
        char Answer;

        PrintUserData(UpdatedUser);
        
        if (GetAnswer("Are you sure you want Updated this User? y/n ? "))
        {
            for (sUser& U : vUser)
            {
                if (StringLib::AreStringsEqual(U.UserName,UserName))
                {
                    U = ChangeUserRecord(U);
                    break;
                }
            }
            SaveUserDataToFile(vUser);
            // Refresh Clients
            vUser = LoadUserDataFromFileToVector();
            cout << "\n User Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\ User Name (" << UserName << ") is Not Found!";
        return false;
    }
}

void UpdetUserScreen(sUser& AktivUser) {
    vector<sUser> vUser = LoadUserDataFromFileToVector();
    ClientDB::PrintPageInformation("Update User Screen");
    UpateUser(vUser, AktivUser);

}
AppState MangeUsersScreen(sUser AktivUser, vector<sUser> &vUser) {
    short choice;
    PrintMangeUserMenu();
    choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 6]", 1, 6, "Only [1-7]");
    switch (choice)
    {
    case 1:
        system("cls"); ListUserScreen();            break;
    case 2:
        system("cls"); AddUsers();                  break;
    case 3:
        system("cls"); DeleteUserScreen(AktivUser); break;
    case 4:
        system("cls"); UpdetUserScreen(AktivUser);  break;
    case 5:
        system("cls"); FindUserScreen();            break;
    case 6:
        system("cls");
        return AppState::Bank;
    }
    system("pause");
    system("cls");
    vUser = LoadUserDataFromFileToVector();
    return AppState::ManageUsers;

}
AppState LoginScreen(sUser &ActiveUser,vector<sUser>&vUser) {
    string UserName, Password;
    system("cls");
    ClientDB::PrintPageInformation("Login Screen");
    bool chek=false;
    do {
        UserName = ReadUserName(false);
        Password = ClientDB::ReadString("Enter Password ? ");
        chek = FindUser(UserName, Password, vUser, ActiveUser);
        if (!chek) {
            cout << "Invaild password / User Name" << endl;
        }

    } while (!chek);
    return  AppState::Bank;
}

AppState Transactions(sUser AktivUser) {
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

AppState BankScreen(sUser &AktivUser , vector<ClientDB::sClientData> &vClientData) {
    short choice;
    system("cls");
    PrintMenu();
    choice = ClientDB::ReadNumber("Choose What do you want to do [1 to 8]", 1, 8, "Only [1-8]");
    vClientData = ClientDB::LoadCleintsDataFromFileToVector();
    switch (choice) {
    case 1:
        system("cls");
        HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::ShowClientList)) ? ClientDB::ShowAllClientsScreen(vClientData) : AccessDenied();
        break;
    case 2:
        system("cls");
        HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::AddNewClient)) ? ClientDB::AddClients() : AccessDenied();
        break;
    case 3:
        system("cls");
        HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::DeleteClient)) ? ClientDB::DeleteClient(vClientData) : AccessDenied();
        break;
    case 4:
        system("cls");
        HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::UpdateClient)) ? ClientDB::UpdateClient(vClientData) : AccessDenied();
        break;
    case 5:
        system("cls");
        HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::FindClient)) ? ClientDB::FindClient() : AccessDenied();
        break;
    case 6:
        system("cls");
        if (HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::Transactions))) {
            return AppState::Transactions;
        }
        else
            AccessDenied();
        break;
    case 7:
        system("cls");
        if (HasUserPermission(AktivUser, static_cast<unsigned int>(Permissions::ManageUsers))) {
            return AppState::ManageUsers;
        }
        else {
            AccessDenied();
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
    sUser ActiveUser;
    vector<sUser> users = LoadUserDataFromFileToVector();
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

