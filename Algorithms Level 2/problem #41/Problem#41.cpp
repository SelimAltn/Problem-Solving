#include <iostream>
using namespace std;

int EnterAnumber(short NumaraSayisi)
{
    int number = 0;

    do
    {
        cout << "Enter a " << NumaraSayisi << ". number\n";
        cin >> number;
        if (number < 10 || number > 99)
        {
            cout << "Girilcek Numaralar Yalnız 10-99 Arasında Olucak !" << endl;
        }

    } while (number < 10 || number > 99);

    return number;
}

void Dizi(int Dizi[], short& Sayac)
{
    for (int i = 0; i < 6; i++)
    {
        Dizi[i] = EnterAnumber(i + 1);
        Sayac++;
    }
}

void DiziYazma(int Dizi[])
{
    for (int i = 0; i < 6; i++)
    {
        cout << Dizi[i] << " ";
    }
    cout << endl;
}

void KontrolEdici(int Dizi[], short Length)
{
    for (int i = 0; i < Length / 2; i++)
    {
        if (Dizi[i] != Dizi[Length - i - 1])
        {
            cout << "Bu Dizi Mukemmel Sayilara Sahip Değil  ! \n";
            return;
        }
    }
    cout << "Bu Dizi Mukemmel Sayilara Sahip Hem Baştan Hemde Tersten Ayni Şekilde okunuyorlar ! \n";
}

int main()
{
    short sayac = 0;
    int dizi[6];

    Dizi(dizi, sayac);
    DiziYazma(dizi);
    KontrolEdici(dizi, 6);

    return 0;
}
