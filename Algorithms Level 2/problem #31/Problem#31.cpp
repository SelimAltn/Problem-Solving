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

void Swap(int& a, int& b)
{
    int simdilk;
    simdilk = a;
    a = b;
    b = simdilk;
}
void Arry1Sayileri(int size, int arry1[100])
{
    for (int i = 0; i < size; i++)
    {
        arry1[i] = i + 1;
    }
}
int RandomNumber(int form, int to)
{
    int randum = rand() % (to - form + 1) + form;
    return randum;

}
void Arry2(int arry1[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(arry1[RandomNumber(1, size) - 1], arry1[RandomNumber(1, size) - 1]);

    }
}

void PrintMatris(int size,int arry[100])
{
    for (int i = 0; i < size; i++)
    {
        cout<< arry[i]<<" ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int arry1[100];
    int size = ReadNumber("enter a number ", 1, 100);
    Arry1Sayileri(size, arry1);
    cout << "Arri1 :"<< endl;
    PrintMatris(size, arry1);
    Arry2(arry1,size);
    cout << "Arri2 :" << endl;
    PrintMatris(size, arry1);
   

}
