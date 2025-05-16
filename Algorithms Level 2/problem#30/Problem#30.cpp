#include <iostream>
using namespace std;
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
void Arry3Olusturma(int arry1[100], int arry2[100],int arry3[100], int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        arry3[i] = arry1[i] + arry2[i];
    }
}
void PrintDiziler(int arry1[100], int arry2[100], int arry3[100], int boyut)
{
    for (int i = 0; i < boyut; i++)
    {
        cout << arry1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < boyut; i++)
    {
        cout << arry2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < boyut; i++)
    {
        cout << arry3[i] << " ";
    }
    cout << endl;

}

int main()
{
    srand(time(0));
    int Size = ReadNumber("enter a number ", 0, 100);
    int Arry1[100], Arry2[100], Arry3[100];
    ArrySayileri(Arry1, Size);
    ArrySayileri(Arry2, Size);
    Arry3Olusturma(Arry1, Arry2, Arry3, Size);
    PrintDiziler(Arry1, Arry2, Arry3, Size);
}
