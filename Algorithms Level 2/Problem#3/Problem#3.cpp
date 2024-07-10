#include <iostream>
using namespace std;
enum ENsayininTuru {mukemmelSayi,mukemmelDegil};
int ReadNumber(string Messaj)
{
    int number;
    cout << Messaj << endl;
    cin >> number;
    return number;
}

ENsayininTuru KontrolNoktasi(int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
    }
    if (sum == number)
        return mukemmelSayi;
    else
       return mukemmelDegil;
}

void PrintMukemmelMiDegilmi(int number)
{
    ENsayininTuru sonucu = KontrolNoktasi(number);
    
    if (sonucu==mukemmelSayi)
        cout << number << " is mukemmeldir \n";
    else 
        cout << number << " is mukemmel degil \n";

}
int main()
{
    while (1) {
        int number = ReadNumber("enter a number ");
        PrintMukemmelMiDegilmi(number);
    }
}