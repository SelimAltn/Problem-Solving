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
int RandomNumber(int form, int to)
{
    int randum = rand() % (to - form + 1) + form;
    return randum;

}
void ArriOlusturma(int arr1[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = RandomNumber(1, 100);
    }
}
void Arri2Olusturma(int arr1[100], int size,int arri2[100])
{
    int simdilik = size;
    for (int i = 0; i < size; i++)
    {
        simdilik--;
        arri2[i] = arr1[simdilik ];
       
    }
}
void PrintMatris(int arri[100], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << arri[i];
        if (i == size - 1)
            break;
        else
            cout << ",";
    }cout << " ]\n";
}
int main()
{
    srand(time(0));
    int arri1[100], arri2[100];
    int size = ReadNumber("enter a number", 1, 100);
    ArriOlusturma(arri1, size);
    PrintMatris(arri1, size);
    Arri2Olusturma(arri1, size, arri2);
    PrintMatris(arri2, size);

}
