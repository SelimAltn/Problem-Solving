#include <iostream>
using namespace std;
int Readnumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}

void ArryUlıstirma(int boyu,int arry[100])
{
    
    for (int i = 0; i <= boyu-1; i++)
    {
        cout <<"[" << i + 1<<"]";
        arry[i] = Readnumber(". Sayıgiriniz");
    }
    
}
void PrintArrySayileri(int boyu, int arry[100])
{
    cout << "{ ";
    for (int i = 0; i <= boyu - 1; i++)
    {
        cout << arry[i];
        if (i == boyu - 1)
            break;
        cout << ",";
    }cout << " }"<<endl;
}
int İstenenSayiKacKereTekrarlandi(int boyu, int arry[100],int number)
{
    int tekrarMiktari=0;
   
    for (int i = 0; i <= boyu - 1; i++)
    {
        if (number == arry[i])
        {
            tekrarMiktari++;
        }
    }
    
    return tekrarMiktari;

}
void PrintSonuc(int tekrar,int istenenSayi)
{
    cout << "giridiniz : " << istenenSayi << " tekrar sayisi : " << tekrar<<endl;
}
int main()
{
    int arry[100];
    int ArryBoyutu = Readnumber("enter a Arry Boyutu");
    ArryUlıstirma(ArryBoyutu, arry);
    PrintArrySayileri(ArryBoyutu,arry);
    int number = Readnumber("aramka istediniz sayi giriniz : ");
    PrintSonuc(İstenenSayiKacKereTekrarlandi(ArryBoyutu, arry,number), number);
}

