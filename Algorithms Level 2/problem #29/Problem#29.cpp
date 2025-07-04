#include <iostream>
using namespace std;
enum ENAsalSayi {asal=1,asaldegl =2};
ENAsalSayi kontrol(int number)
{
    int m = round(number / 2);
    for (int sayac = 2; sayac <= m; sayac++)
    {
        if (number % sayac == 0)
            return ENAsalSayi::asaldegl;
    }
    return ENAsalSayi::asal;
}
int ReadNumber(string messaj, int form, int to)
{
    int number;
    do
    {
        cout << messaj << endl;
        cin >> number;
        if (number<form || number>to)
            cout << "a rong inbut \a\n";
    } while (number<form || number>to);

    return number;
}
void ArrySayileri(int arry[100], int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        arry[i] = rand() % (100 - 1 + 1) + 1;
    }
}
void KopyaAsal(int Arry1[100], int Arry2[100], int size1, int &size2)
{
    int sayac2=0;
    for (int i = 0; i < size1; i++)
    {
        if (kontrol(Arry1[i]) == ENAsalSayi::asal)
        {
            Arry2[sayac2] = Arry1[i];
            sayac2++;
        }
    }
    size2 = --sayac2;
}
void PrintAsal(int arr[100],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    int Arry[100], Arry2[100],ArrySize2=0;
    int ArrySize = ReadNumber("enter a Arry size ? ", 1, 100);
    ArrySayileri(Arry, ArrySize);
    KopyaAsal(Arry, Arry2, ArrySize, ArrySize2);
    cout << "asıl matris : " << endl;
    PrintAsal(Arry, ArrySize);
    cout << "2. : " << endl;
    PrintAsal(Arry2, ArrySize2);
    return 0;

}
