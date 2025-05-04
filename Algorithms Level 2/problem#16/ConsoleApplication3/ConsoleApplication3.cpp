#include <iostream>
using namespace std;
void PrintHarfTekrari()
//AAA AAB AAC .........ZZZ
{
    string Kelime = "";
    for (int i = 65; i < 91; i++)
    {
       
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                Kelime = Kelime + char(i);
                Kelime = Kelime + char(j);
                Kelime = Kelime + char(k);
                cout << Kelime<<"  ";
                Kelime = "";// unutma en önemli şey.
            }
        }
    }
}
int main()
{
    PrintHarfTekrari();
}
    