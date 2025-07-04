#include <iostream>
#include <ctime>

using namespace std;

int RandomNumber(int form, int to)
{
    int randum = rand() % (to - form + 1) + form;
    return randum;

}
void ArriOlusturma(int arr1[100], int &size)
{
    cout << "enter arri size ? "<<endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        arr1[i] = RandomNumber(1, 100);
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
void AriiEkleme(int Number, int arr2[100], int& arrLength)
{
    arrLength++;
    arr2[arrLength - 1] = Number;
}
void Kobyala(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{

     for (int i = 0; i < arrLength; i++)
     {
         AriiEkleme(arrSource[i], arrDestination, arrDestinationLength);
     }
}
int main()
{
    srand(time(0));
    int arri1[100],size1=0,arii2[100],size2=0;

    ArriOlusturma(arri1, size1);
    cout << "matris 1 : " << endl;
    PrintMatris(arri1, size1);
    Kobyala(arri1, arii2, size1, size2);
    cout << "matris 2 : " << endl;
    PrintMatris(arii2, size2);
    return 0;
}


