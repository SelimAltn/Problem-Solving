#include "ClientDB.h"
#include "../../Libraries/String Library/StringLib.h"


namespace ClientDB
{
    double ReadNumber(string Message)
    {
        double Number;
        cout << Message << endl;
        cin >> Number;
        return Number;
    }
    string ReadString(string Message)
    {
        string Str;
        cout << Message << endl;
        getline(cin, Str);
        return Str;
    }
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
    sClientData ReadClient()
    {
        sClientData Client;
        
        Client.AccountNumber = ReadAccountNumber();
        Client.Name = ReadString("Enter Client Name");
        Client.PinCode = ReadString("Enter Client Pin Code");
        Client.Phone = ReadString("Enter Client Phone");
        Client.AccountBalance = ReadNumber("Enter Client Account Balance");
        return Client;
    }
    string ConvertRecordToLine(sClientData Client, string Seperator)
    {
        string stClientRecord = "";
        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += Client.Name + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;
    }
    sClientData ConvertLinetoRecord(string LineData, string Seperator)
    {
        sClientData Client;
        vector<string> vString;
        vString = StringLib::SplitString(LineData, Seperator);
        Client.AccountNumber = vString[0];
        Client.PinCode = vString[1];
        Client.Name = vString[2];
        Client.Phone = vString[3];
        Client.AccountBalance = stod(vString[4]);
        return Client;
    }
    

    void PrintClientData(sClientData data)
    {
        cout << "---------------------------------------------\n";
        cout << "Account Number : " << data.AccountNumber << endl;
        cout << "Pin Code : " << data.PinCode << endl;
        cout << "Name : " << data.Name << endl;
        cout << "Phone : " << data.Phone << endl;
        cout << "Account Balance : " << data.AccountBalance << endl;
        cout << "---------------------------------------------\n";
    }

    void AddDataLineToFile(string ClientLine,string FileName)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << ClientLine << endl;
            MyFile.close();
        }
        else
        {
            cout << "Unable to open the file";
        }
    }
    void AddNewClient()
    {
        cout << "Adding New Client \n";
        sClientData data = ReadClient();
        string LineData = ConvertRecordToLine(data);
        AddDataLineToFile(LineData, ClientFileName);
    }
    void AddClients()
    {
        char AddMore;
        do
        {
            AddNewClient();
            cout << "Client Added Successfully do you want to add more clients ? Y / N ? ";
            cin >> AddMore;
        } while (toupper(AddMore) == 'Y');
    }
    vector<sClientData> LoadCleintsDataFromFileToVector()
    {
        vector<sClientData> vClients;
        fstream MyFile;

        MyFile.open(ClientFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                vClients.push_back(ConvertLinetoRecord(Line));
            }

            MyFile.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
        return vClients;
    }
    void PrintClientRecord(sClientData Client,bool ShortVersion)
    {
        if (!ShortVersion) {
            cout << "| " << setw(15) << left << Client.AccountNumber;
            cout << "| " << setw(10) << left << Client.PinCode;
            cout << "| " << setw(40) << left << Client.Name;
            cout << "| " << setw(12) << left << Client.Phone;
            cout << "| " << setw(12) << left << Client.AccountBalance;
        }
        else {
            cout << "| " << setw(15) << left << Client.AccountNumber;
            cout << "| " << setw(40) << left << Client.Name;
            cout << "| " << setw(12) << left << Client.AccountBalance;
        }
        
    }
    void ShowAllClientsFromFile(vector<sClientData> vClients, bool ShortVersion)
    {
        if (!ShortVersion) {
            cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(10) << "Pin Code";
            cout << "| " << left << setw(40) << "Client Name";
            cout << "| " << left << setw(12) << "Phone";
            cout << "| " << left << setw(12) << "Balance";
        }
        else {
            cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
            cout << "\n_______________________________________________________";
            cout << "_________________________________________\n" << endl;
            cout << "| " << left << setw(15) << "Accout Number";
            cout << "| " << left << setw(40) << "Client Name";
            cout << "| " << left << setw(12) << "Balance";

        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
        for (sClientData client : vClients)
        {
            PrintClientRecord(client, ShortVersion);
            cout << endl;
        }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }

    vector<sClientData> SaveCleintsDataToFile(vector<sClientData> vClints)
    {
        fstream MyFile;
        MyFile.open(ClientFileName, ios::out);
        string DataLine;
        if (MyFile.is_open())
        {
            for (sClientData s : vClints)
            {
                if (s.MarkForDelete == false)
                {
                    DataLine = ConvertRecordToLine(s);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
        return vClints;
    }
    void FindClient() {
        sClientData client;
        vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
        string AccountNumber = ReadAccountNumber(false);
        if (FindClientByAccountNumber(AccountNumber, vClients, client)) {
            PrintClientData(client);
        }
        else
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    bool FindClientByAccountNumber(string AccountNumber, vector<sClientData> vClients, sClientData &client)
    {
        for (sClientData c : vClients)
        {
            if (c.AccountNumber == AccountNumber)
            {
                client = c;
                return true;
            }
        }
        return false;
    }
    bool IsAccountNumberExists(string AccountNumber, vector<sClientData> vClients)
    {
        for (sClientData c : vClients)
        {
            if (StringLib::AreStringsEqual(c.AccountNumber,AccountNumber))
            {
       
                return true;
            }
        }
        return false;
    }
    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClientData> &vClients)
    {
        for (sClientData &c : vClients)
        {
            if (c.AccountNumber == AccountNumber)
            {
                c.MarkForDelete = true;
                return true;
            }
        }
        return false;
    }
    string ReadAccountNumber(bool Check) {
        string AccountNumber;

        if (Check) {
            bool IsExists;
            vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
            do {
                cout << "Enter Client Account Number" << endl;
                getline(cin >> ws, AccountNumber);
                IsExists = IsAccountNumberExists(AccountNumber, vClients);
                if (IsExists)
                    cout << "This account number already exists. Please enter a unique account number." << endl;
            } while (IsExists);
        }
        else {
            cout << "Enter Client Account Number" << endl;
            getline(cin >> ws, AccountNumber);
        }
        return AccountNumber;
        
    }
    void DeleteClient(vector<sClientData>& vClients) {
        cout << "========================================\n";
        cout << "\t\Delete Screen\n";
        cout << "========================================\n";
        DeleteClientByAccountNumber(vClients);
    }
    bool DeleteClientByAccountNumber(vector<sClientData> &vClients)
    {
        sClientData client;
        string AccountNumber =ReadAccountNumber(false);
        char Answer;
        if (FindClientByAccountNumber(AccountNumber, vClients, client))
        {
            PrintClientData(client);
            cout << "Are you sure you want delete this client? y/n \n ?";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                SaveCleintsDataToFile(vClients);
                // Refresh Clients
                vClients = LoadCleintsDataFromFileToVector();
                cout << "\n\nClient Deleted Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        }
    }

    sClientData ChangeClientRecord(string AccountNumber)
    {
        sClientData Client;
        Client.AccountNumber = AccountNumber;
        cout << "\n\nEnter PinCode? ";
        getline(cin >> ws, Client.PinCode);
        cout << "Enter Name? ";
        getline(cin, Client.Name);
        cout << "Enter Phone? ";
        getline(cin, Client.Phone);
        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;
        return Client;
    }
    void UpdateClient(vector<sClientData>& vClients) {
        cout << "========================================\n";
        cout << "\t\ Update Screen\n";
        cout << "========================================\n";
        UpdateClientByAccountNumber(vClients);
    }
    bool UpdateClientByAccountNumber(vector<sClientData> &vClients)
    {
        sClientData client, newClient;
        string AccountNumber =ReadAccountNumber(false);
        char Answer;
        if (FindClientByAccountNumber(AccountNumber, vClients, client))
        {
            PrintClientData(client);
            cout << "Are you sure you want Update this client? y/n \n ?";
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                for (sClientData &C : vClients)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientRecord(AccountNumber);
                        break;
                    }
                }
                SaveCleintsDataToFile(vClients);
                cout << "\n\nClient Updated Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        }
    }
    sClientData DepositClient(sClientData Client, double Balance) {

        Client.AccountBalance += Balance;
        return Client;
    }
    double ReadBalance(string message, short from, short to, string ErorMessage, bool forMaxBalance) {
        double Balance = 0.0;
        do {
            cout << message << endl;
            cin >> Balance;
            if (Balance < from || Balance > to) {
                if (forMaxBalance)
                    cout << ErorMessage << to << endl;
                else
                    cout << ErorMessage << endl;
            }
        } while (Balance < from || Balance > to);
        return Balance;
    }
    void AfterDepositWithdrawalProcess(vector<sClientData> vClients, sClientData client, string AccountNumber) {
        for (sClientData& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C = client;
                break;
            }
        }
        SaveCleintsDataToFile(vClients);
        PrintClientData(client);
    }
    void DepositProcess() {
        cout << "========================================\n";
        cout << "\t\Deposit Screen\n";
        cout << "========================================\n";
        string AccountNumber = ReadAccountNumber(false);

        sClientData client;
        vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
        if (FindClientByAccountNumber(AccountNumber, vClients, client)) {
            cout << "The Following are the Client details : \n";
            PrintClientData(client);
            client = DepositClient(client,ReadBalance("Place Enter deposit amount", 1, 1000000, "Enter an amount greater than zero"));
            cout << "Transaction completed \n";
            cout << endl;
            AfterDepositWithdrawalProcess(vClients, client, AccountNumber);

        }
        else
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    void PullingProcess() {
        cout << "========================================\n";
        cout << "\t\Pulling Screen\n";
        cout << "========================================\n";
        string AccountNumber = ReadAccountNumber(false);

        sClientData client;
        vector<sClientData> vClients = LoadCleintsDataFromFileToVector();
        if (FindClientByAccountNumber(AccountNumber, vClients, client)) {
            cout << "The Following are the Client details : \n";
            PrintClientData(client);
            double Balance = ReadBalance("Place Enter Pulling amount", 1, client.AccountBalance, "Amount Exceeds the balance, you can withdraw up to : ", true);
            Balance *= -1;
            client = DepositClient(client, Balance);
            cout << "Transaction completed \n";
            cout << endl;
            AfterDepositWithdrawalProcess(vClients, client, AccountNumber);
        }
        else
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    double CalculateTotalBalances(vector<sClientData> vClients) {
        double total = 0.0;
        for (sClientData client : vClients)
        {
            total += client.AccountBalance;
        }
        return total;
    }

    void TotalBalances() {
        vector<sClientData> vClientData = LoadCleintsDataFromFileToVector();
        ShowAllClientsFromFile(vClientData, true);
        cout << "\t\t\t\tTotal Balcese = " << CalculateTotalBalances(vClientData) << endl;
    }
}
