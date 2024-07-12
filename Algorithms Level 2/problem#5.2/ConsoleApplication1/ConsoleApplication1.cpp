#include <iostream>
using namespace std;


int  ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
void PrintSayilarinRakamlari(int number)
{
    int kalan;
    while (number > 0)
    {
        kalan = number % 10;
        number = number / 10;
        cout << kalan<<endl;
    }
}
int main()
{
   
    PrintSayilarinRakamlari(ReadNumber("enter a number "));
    
   
}

