#include <iostream>
#include <ctime>
using namespace std;
int ReadNumber(int form ,int to,string messaj)
{
    int number;
    cout << messaj << endl;
    do
    {
        cin >> number;
        if (number<form || number>to)
            cout << "number is " << form << "-" << to << endl;
    } while (number<form || number>to);
        return number;
 
}
int RastgeleSayiOlusturma()
{
    return rand() % 100 + 1;
}
void ArriOlusturma(int arri[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        arri[i] = RastgeleSayiOlusturma();
    }
}
void ArriPrint(int arri[100], int size)
{
 
    for (int i = 0; i < size; i++)
    {
        cout << arri[i];
        if (i == size - 1)
            cout << "}";
        else
            cout << ",";
      
    }
    cout << endl;
}
void Arri2Olusturma(int arri1[100], int size1,int arri2[100],int &size2)
{
    int j = 0;
    for (int i = 0; i < size1; i++)
    {
        if (arri1[i] % 2 != 0)
        {
            arri2[j] = arri1[i];
            j++;
        }
    }
    size2 = j;
}
int main()
{
    srand(time(0));
    int arri[100], arr2[100];
    int size2;
    int ArriSize = ReadNumber(1, 100, "enter arri size : ");
    ArriOlusturma(arri, ArriSize);
    cout << "Arri 1 :{ ";
    ArriPrint(arri, ArriSize);
    Arri2Olusturma(arri, ArriSize, arr2, size2);
    cout << "Arri 2 :{ ";
    ArriPrint(arr2, size2);


}

