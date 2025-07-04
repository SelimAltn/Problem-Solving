#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    do
    {
        cin >> number;
        if (number <= 0 || number >= 27)
            cout << "enter a number is 1-26 " << endl;
    } while (number <= 0||number>=27);
    return number;
}
void PrintSonuç(int number)
{
    for (int i = 65+number-1; i >=65; i--)
    {
        cout << " \n ";
        for (int j = 1; j <= number-(65+number-1-i); j++)
        {
            cout << char(i);

        }

    }

}
int main()
{
    int number = ReadNumber("enter a number ");
    PrintSonuç(number);
}

