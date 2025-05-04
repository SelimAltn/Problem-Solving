#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;
    cout << "enter a number \n";
    do
    {
        cin >> number;
        if (number <= 0 || number >= 26)
            cout << "enter a number is 1-26\n\a";

    } while (number <= 0 || number >= 26);
    return number;
}
void PrintTekrar(int number)
{
    for (int i = 65 ; i <= 65+number-1; i++)
    {
        for (int j = 1; j <= number - (65 + number - 1 - i); j++)
        {
            cout << char(i);
        }
        cout << endl;

    }
}
int main()
{
    PrintTekrar(ReadNumber());
}
