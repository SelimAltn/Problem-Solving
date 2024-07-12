#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
//12321
bool Analiz(int Number )
{
    int number = Number;
    int kalan,tersNumber=0;
    while (number > 0)
    {
        kalan = number % 10;
        number = number / 10;
        tersNumber = tersNumber * 10 + kalan;
    }

    if (tersNumber == Number)
        return 1;
    else 
        return 0;
 
   


}
string PrintSonucu(bool cevab,int number )
{
    if (cevab)
        return " is polindrome " ;
    else
      return " is not polindrome " ;
}
int main()
{
    int number = ReadNumber("enter a number ");
    cout << number << PrintSonucu(Analiz(number), number);
}

