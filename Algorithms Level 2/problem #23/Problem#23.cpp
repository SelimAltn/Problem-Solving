#include <iostream>
using namespace std;
int ReadNumber(string messaj,int form ,int to)
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
void PrintSayiler(int arry[100],int boyut)
{
    cout << "[";
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
int main()
{
    int Arry[100];
    int ArrySize = ReadNumber("enter a Arry size ? ",1,100);
    srand(time(0));
    ArrySayileri(Arry, ArrySize);
    PrintSayiler(Arry, ArrySize);
    return 0;

}
