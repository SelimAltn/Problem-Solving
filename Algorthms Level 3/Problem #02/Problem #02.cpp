#include <iostream>
using namespace std;

int ReadNumber(string message) {
    cout << message << endl;
    int number;
    cin >> number;
    return number;
}

bool IsLeapYear(int number) {
    if (number % 400 == 0)
        return 1;
    else if (number % 4 == 0 && number % 100 != 0)
        return 1;
    else return false;
}
void SonucYazdir() {
    if (IsLeapYear(ReadNumber("Enter a Year")))
        cout << "year is Leap year\n";
    else
        cout << "is not leap year\n";
}

int main()
{
    while (1)
        SonucYazdir();
}