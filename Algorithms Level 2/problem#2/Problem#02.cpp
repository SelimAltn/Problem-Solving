#include <iostream>
using namespace std;
enum ENasalmıdeğilmi { asal = 1, asaldeğil = 2 };
int ReadNumber()
{
    int number;
    do
    {
        cout << "enter a number : \n";
        cin >> number;
        if (number <= 0)
            cout << "enter a pozitif number ! ";
    } while (number <= 0);

    return number;
}
ENasalmıdeğilmi kontrolnoktası(int number)
{
    int m = round(number / 2);//--> sayı asalmı değilmi anlamak için kullanır kodta en zor şey burda (:
    for (int x = 2; x <= m; x++)
    {
        if (number % x == 0)
            return ENasalmıdeğilmi::asaldeğil;


    }
    return ENasalmıdeğilmi::asal;

}
void PrintAsalSayilar(int number)
{
    cout << "\n" << "asal sayilar 1 den " << number << " kadar : " << endl;
    for (int i = 1; i <= number; i++)
    {
        if (kontrolnoktası(i) == ENasalmıdeğilmi::asal)
            cout << i << "\n";
    }

}

int main()
{
    PrintAsalSayilar(ReadNumber());

}
