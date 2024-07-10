#include <iostream>
using namespace std;
void PrintBaslik ()
{
    cout << "\n \t \t \t \t \t 1-10 carpim tablosu : \n" <<endl;
    cout << "\t";
    int i, j;
    for (i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n----------------------------------------------------------------------------------------------\n";       
}
string duzCizgiİcinBirKosul(int number)
{
    if (number <= 9)
        return "   | ";
    else
        return "  | ";
}
void PrintCarpimTablosu()
{
    PrintBaslik();
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "  " << duzCizgiİcinBirKosul(i);
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j<<"\t";
        }
        cout << endl;

    }
}
int main()
{
    PrintCarpimTablosu();
}

