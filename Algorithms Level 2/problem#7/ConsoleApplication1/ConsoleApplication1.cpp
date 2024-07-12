#include <iostream>
using namespace std;
int ReadNumber(string messaj)
{
    int number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
int PrintSum(int number)
{
    int sum = 0;
    int simdilik = 0;
    int number2 = 0;
    while (number > 0)
    {
        simdilik = number % 10;
        number /= 10;
        number2 = number2 * 10 + simdilik;
    }
    return number2;
}

int main()
{
    int Number = ReadNumber("enter a number ");
   cout<< PrintSum(Number);
}

