#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;
enum ENPrintTur {buyukHarf=1 ,kucukHarf=2,karakter=3 ,rakam=4};
int ReadNumber(int form, int to)
{

    int RastgeleNumber = rand() % (to - form + 1) + form;
    return RastgeleNumber;
}
char secim(ENPrintTur charTybe)
{
         switch (charTybe)
         {
         case buyukHarf:
             return  char(ReadNumber(65, 90));
             break;
         case kucukHarf:
             return char(ReadNumber(97, 122));
             break;
         case karakter:
             return char(ReadNumber(33, 47));
             break;
         case rakam:
             return char(ReadNumber(48, 57));
             break;
         }
}
void Print()
{
    cout << "buyuk harf :" << secim(ENPrintTur::buyukHarf) << endl;
    cout << "kuçuk harf : " << secim(ENPrintTur::kucukHarf) << endl;
    cout << "karakter : " << secim(ENPrintTur::karakter)  << endl;
    cout << "rakam :  " << secim(ENPrintTur::rakam)     << endl;


}

int main()
{
    srand(time(0));
    Print();
    
}
