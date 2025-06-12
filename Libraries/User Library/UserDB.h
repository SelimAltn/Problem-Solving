//  UserDB.h

#ifndef User_DB_H
#define User_DB_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../../Libraries/String Library/StringLib.h"

using namespace std;

namespace UserDB
{
    const string FileName = "D:\\programing\\c++\\programing kurslar\\c++ kurs 8\\ConsoleApplication5\\User.txt";
    const string AdminUserName = "Selim";
    

        enum class Permissions : unsigned int {
        None = 0,
        ShowClientList = 1 << 0,
        AddNewClient   = 1 << 1,
        DeleteClient   = 1 << 2,
        UpdateClient   = 1 << 3,
        FindClient     = 1 << 4,
        Transactions   = 1 << 5,
        ManageUsers    = 1 << 6,
        FullAccess     = static_cast<unsigned int>(-1)
    };

    struct sUser {
        std::string UserName;
        std::string Password;
        int permissions = 0;
        bool MarkForDelete = false;
    };

    // Fonksiyon prototipleri
    bool HasUserPermission(sUser user, unsigned int permission);
    void GrantPermission(sUser& user, unsigned int permission);
    void RevokePermission(sUser& user, unsigned int permission);

    std::vector<sUser> LoadUserDataFromFileToVector();
    std::vector<sUser> SaveUserDataToFile(std::vector<sUser> vUser);

    bool FindUser(std::string UserName, std::string Password, std::vector<sUser> vUser, sUser& user);
    bool FindUserWithUserName(std::string UserName, std::vector<sUser> vUser, sUser& user);
    bool IsUserNameExists(std::string UserName, std::vector<sUser> vUser);

    std::string ReadUserName(bool Check = true);
    std::string ConvertUserRecordToLine(sUser User, std::string Seperator = "#//#");
    sUser ConvertUserLinetoRecord(std::string LineData, std::string Seperator = "#//#");

    bool GetAnswer(std::string message);
    int ReadPermission();

    sUser ReadUser();
    sUser ChangeUserRecord(sUser& orig);

    void AddUsers();
    void AddNewUser();
    void ListUser();
    void ListUserScreen();
    void FindUserScreen();
    void DeleteUserScreen(sUser AktivUser);
    void UpdetUserScreen(sUser& AktivUser);

    void PrintUserData(sUser data);
    void PrintUserRecord(sUser User);
    void AccessDenied();

    bool DeleteUser(std::vector<sUser> vUser, sUser AktivUser);
    bool MarkClientForDeleteByUserName(std::string UserName, std::vector<sUser>& vUsers);
    bool UpateUser(std::vector<sUser>& vUser, sUser& AktivUser);
}

#endif // User_DB_H