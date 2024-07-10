#include <iostream>
#include <string>
using namespace std;
int  ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
string donusturme(int number )
{
    string sayiSTR = to_string (number);
    return sayiSTR;
}
void PrintSayilarinRakamlari(string sayı)
{
    for (char rakam :sayı)
    {
        cout << rakam << endl;

    }
}
int main()
{
    PrintSayilarinRakamlari(donusturme(ReadNumber("enter a number ")));
}
