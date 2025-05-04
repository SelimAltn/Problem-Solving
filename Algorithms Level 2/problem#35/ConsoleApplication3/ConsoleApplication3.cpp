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
void ArriOlusturma(int arri[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        arri[i] = RandomNumber(1, 100);
    }
}

void PrintArri(int arri[100], int size)
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
int ElemanArama(int arri[100], int size, int eleman)
{
    for (int i = 0; i < size; i++)
    {
        if (arri[i] == eleman)
            return i;
    }
    return -1;

}

bool kontrol(int arri[100], int size, int eleman)
{
    return ElemanArama(arri, size, eleman) != -1;
}
void PrintSonuc(bool kontrol)
{
    if (kontrol == 1)
        cout << " elemani bulduk (:\n";
    else
        cout << "elemanı yok :(\n";
}

int main()
{


    bool Kontrol;
    srand(time(0));
    int Arri[100];
    int size = ReadNumber("istediniz eleman sayisi giriniiz ?  ", 1, 100);
    ArriOlusturma(Arri, size);
    PrintArri(Arri, size);
    while (1)
    {
        int İstenenEleman = ReadNumber("aramak istediniz sayi giriniz ", 1, 100);
        PrintSonuc(kontrol(Arri, size, İstenenEleman));
    }
   






}

