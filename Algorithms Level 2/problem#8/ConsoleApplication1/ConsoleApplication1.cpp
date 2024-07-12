#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
int PrintTekrar(int number,int rakam)
{
    int tekrar = 0;
    int kalan = 0;
    while (number > 0)
    {
        kalan = number % 10;
        if (kalan == rakam)
            tekrar++;
        number /= 10;
    }
    return tekrar;
    
}

int main()
{
    int Number = ReadNumber("enter a number ");
    int rakam = ReadNumber("rakam giriniz ");
    cout << "girdiniz sayinin tekrarı = ";
   cout<< PrintTekrar(Number, rakam);
    
}

