#include <iostream>
using namespace std;

void EnterAnumber(string Message, int& number)
{
    cout << Message << endl;
    do
    {
        cin >> number;
        if (number > 100 || number < 0)
            cout << "enter a number betwin 0-100";

    } while (number > 100 || number < 0);

}



int RandumNamber(int form, int to)
{
    int randum;
    do
    {
        randum = rand() % (to - form + 1) + form;

        
    } while (randum == 0);
    return randum;

}


void DiziOlusturma(int length, int Dizi[])
{
    for (int i = 0; i < length; i++)
    {
        Dizi[i] = RandumNamber(-100, 100);

    }
}


void DiziYazdirma(int Dizi[], int length)
{
    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << Dizi[i] << " ";
    }
    cout << "}" << endl;

}
void PozitifSayilerininSayaci(int arr[], int length)
{
    int sayac = 0;
    int pozitifİndex=0;
    int Pozitif[100];
    int sum=0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0)
        {
            sayac++;
            Pozitif[pozitifİndex ++] = arr[i];
            sum += arr[i];

        }

    }

    cout << "Pozitif Sayilar : ";
    DiziYazdirma(Pozitif, pozitifİndex);
    cout << endl;
    cout << "pozitif Sayıların Sayısı : " << sayac << endl;
    cout << "Poziti Sayıların Toplamı : " << sum << endl;

}
void NegatifSayilerininSayaci(int arr[], int length)
{
    int sayac = 0;
    int Negatifİndex=0;
    int Negatif[100];
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
        {
            sayac++;
            Negatif[Negatifİndex ++] = arr[i];
            sum += arr[i];

        }

    }

    cout << "Negatif Sayilar : ";
    DiziYazdirma(Negatif, Negatifİndex);
    cout << endl;
    cout << "Negatif Sayıların Sayısı : " << sayac << endl;
    cout << "Negatif Sayıların Toplamı : " << sum << endl;

}


int main()
{
    int Length;
    int arr[100];
    EnterAnumber("istediniz Arri Uzunlu Giriniz :\n ", Length);
    DiziOlusturma(Length, arr);
    DiziYazdirma(arr, Length);
    PozitifSayilerininSayaci(arr, Length);
    NegatifSayilerininSayaci(arr, Length);
}

 