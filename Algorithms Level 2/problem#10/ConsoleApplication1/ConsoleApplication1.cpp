#include <iostream>
using namespace std;


int  ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
int sayinintersi(int number)
{
    int kalan,number2=0;
    while (number > 0)
    {
        kalan = number % 10;
        number = number / 10;
        number2 = number2 * 10 + kalan;
    }
    return number2;
}
void PrintRakamlar(int number)
{
    int kalan;
    while (number > 0)
    {
        kalan = number % 10;
        number = number / 10;
        cout << kalan << endl;
    }
}
int main()
{

   int number = ReadNumber("enter a number ");
   PrintRakamlar(sayinintersi(number));


}

