#include <iostream>
using namespace std;

void EnterAnumber(string Message,int &number)
{
    cout << Message << endl;
    do
    {
        cin >> number;
        if (number > 100 || number < 0)
            cout << "enter a number betwin 0-100";

    } while (number > 100 || number < 0);
    
}
int RandumNamber(int form ,int to)
{
    return rand() % (to - form + 1) + form;

}
void DiziOlusturma(int length ,int Dizi[])
{
    for (int i = 0; i < length; i++)
    {
        Dizi[i] = RandumNamber(1, 100);

    }
}
void DiziYazdirma(int Dizi[],int length)
{
    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << Dizi[i] << " ";
    }
    cout << "}" << endl;

}

void TekSayilarinSayisini(int Dizi[],int length)
{
    int Sayac=0;
    int sum=0;
    int TekSayilarinDizisi[100];
    int TekIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (Dizi[i] % 2 != 0)
        {
            Sayac++;
            sum += Dizi[i];
            TekSayilarinDizisi[TekIndex++] = Dizi[i];

        }

    }
    cout << "Tek Sayilarin Dizisi : ";
    DiziYazdirma(TekSayilarinDizisi, Sayac);
    cout << "Bu dizide Tek Sayilarin Sayısının : " << Sayac << endl;
    cout << "Bu dizide Tek Sayilarin Toplami : " << sum << endl;


}
void CiftSayilarinSayisini(int Dizi[], int length)
{
    int Sayac = 0;
    int sum = 0;
    int CiftSayilarinDizisi[100];
    int CiftIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (Dizi[i] % 2 == 0)
        {
            Sayac++;
            sum += Dizi[i];
            CiftSayilarinDizisi[CiftIndex++] = Dizi[i];

        }

    }
    cout << "Cift Sayilarin Dizisi : ";
    DiziYazdirma(CiftSayilarinDizisi, Sayac);
    cout << "Bu dizide Cift Sayilarin Sayısının : " << Sayac << endl;
    cout << "Bu dizide Cift Sayilarin Toplami : " << sum << endl;


}
int main()
{
    
    int Number ,Arr[100];
    EnterAnumber("İstediniz Matrisin Sayisini Giriniz", Number);
    DiziOlusturma(Number, Arr);
    DiziYazdirma(Arr, Number);
    TekSayilarinSayisini(Arr, Number);
    cout << endl<<endl;
    CiftSayilarinSayisini(Arr, Number);
   
}

