#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
int PrintTekrar(int number, int rakam)
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
void Tekrarhesaplama(int number)
{
    for (int i = 0; i < 10; i++)
    {
        short tekrar = PrintTekrar(number, i);
        if (tekrar > 0)
            cout << i << " sayinin tekrari = " << tekrar <<  endl;
    }
}


int main()
{
    int Number = ReadNumber("enter a number ");
    Tekrarhesaplama(Number);


 

}

