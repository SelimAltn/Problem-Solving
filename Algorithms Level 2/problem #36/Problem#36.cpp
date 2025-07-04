#include <iostream>
using namespace std;
int ReadNumber(string messaj,int form,int to)
{
    int number;
    do
    {
        cout << messaj << endl;
        cin >> number;
        if (number<form || number>to)
            cout << "a rong input ";
    } while (number<form || number>to);
    return number;
}
bool Soru(string messaj)
{
    bool kontrol;
    cout << messaj << endl;
    while (1)
    {
        cin >> kontrol;
        if (cin.good())
            break;
        else
        {
            cout << "Hatalı giriş! Lütfen bir sayı giriniz." << endl;
            // cin akışını temizle
            cin.clear();

            // Hatalı girdiyi atla
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
    }
    return kontrol==1;
}

void MatrisOlusturma(int Arri[100],short &sayac)
{
    
   do
   {
       Arri[sayac] = ReadNumber("enter a number ", 1, 100);
       sayac++;
   } while (Soru("baska sayi eklemek istermisiniz ? (1,0 ile cevabla)"));
        
  
}
void PrintMatris(int arri[100], short sayac)
{
    
    for (int i = 0; i < sayac; i++)
    {
        cout << arri[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arri[100];
    short sayac=0;
    MatrisOlusturma(arri, sayac);
    PrintMatris(arri, sayac);


}

