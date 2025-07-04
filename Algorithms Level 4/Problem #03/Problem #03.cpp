#include <iostream>
using namespace std;

int ReadNumber(string message) {
    cout << message << endl;
    int number;
    cin >> number;
    return number;
}

bool IsLeapYear(int number) {
    
    return number % 400 == 0 || (number % 4 == 0 && number % 100 != 0) ;
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

