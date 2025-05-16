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
void PrintSayilerForArry1(int arry[100], int boyut)
{
    cout << "ARRY 1 : [";
    for (int i = 0; i < boyut; i++)
    {
        cout << arry[i];
        if (i == boyut - 1)
            break;
        else
            cout << " , ";
    }
    cout << "]\n";
}
void YeniArri(int Arry[100],int boyut,int Arry2[100])
{
    for (int i = 0; i < boyut; i++)
    {
        Arry2[i] = Arry[i];
    }
}
void PrintSayilerForArry2(int arry2[100], int boyut)
{
    cout << "ARRY 2 : [";
    for (int i = 0; i < boyut; i++)
    {
        cout << arry2[i];
        if (i == boyut - 1)
            break;
        else
            cout << " , ";
    }
    cout << "]\n";
}
int main()
{
    int Arry[100],Arry2[100];
    int ArrySize = ReadNumber("enter a Arry size ? ", 1, 100);
    srand(time(0));
    ArrySayileri(Arry, ArrySize);
    PrintSayilerForArry1(Arry, ArrySize);
    YeniArri(Arry, ArrySize, Arry2);
    PrintSayilerForArry2(Arry2, ArrySize);
    return 0;

}
