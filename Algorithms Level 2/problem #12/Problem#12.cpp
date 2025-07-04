#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    do
    {
        cin >> number;
        if (number <= 0)
            cout << "enter a pozitif number \n";
    } while (number <= 0);
    return number;
}
void IslemTekrar(int number)
{

    for (int i = number; i>=1;i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i<<"    ";
        }
        cout << endl;
    }

}
int main()
{
   IslemTekrar( ReadNumber("enter a number "));
}

