#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    do
    {
        cin >> number;
        if (number <= 0)
            cout << "enter a pozitif number "<<endl;
    } while (number <= 0);
        return number;
}
void PrintSonuç(int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << " \n ";
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        
    }

}
int main()
{
    int number = ReadNumber("enter a number ");
    PrintSonuç(number);
}

