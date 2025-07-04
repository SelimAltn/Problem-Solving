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
int NumberRandum(int form, int to)
{
    return rand() % (to - form + 1) + form;
}
string TEST()
{
    string kelime = "";
    for (int i = 1; i <= 4; i++)
    {
        kelime += char(NumberRandum(65, 90));    

    }

    return kelime;
}

void PrintDizi(string arri[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int J = 1; J <= 4; J++)
        {
            arri[i] += TEST();
                if (J == 4)
                    break;
                else
                    arri[i] += "-";

        }
    }
}
void PrintWindosAnahtrarlari(string arri[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i+1 << "] : " << arri[i]<<endl;
    }
      
}
int main()
{
    srand(time(0));
    string ArriAnahtar[100];
    short number = ReadNumber("Enter a number ",1,100);
    PrintDizi(ArriAnahtar, number);
    PrintWindosAnahtrarlari(ArriAnahtar, number);

}

