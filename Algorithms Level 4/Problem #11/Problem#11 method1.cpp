#include <iostream>
using namespace std;

short ReadNumber(string message, short from, short to, string Error_message) {
    short number;
    do {
        cout << message << endl;
        cin >> number;
        if (number<from || number>to)
            cout << Error_message << endl;
    } while (number<from || number>to);

    return number;
}
bool IsLeapYear(short year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);

}

short NumberOfDayesInMonth(short month,short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

short calculateDayOfYear(short day ,short month , short year) {
    short Total = 0;
    for (int i = 1; i <= month-1; i++) {
        Total += NumberOfDayesInMonth(i, year);
    }
    Total += day;
    return Total;
}

void calculateDateFromDayOfYear(short dayOfYear,short year) {
    short day, month;
    short accumulatedDays =0;
    for (int i = 1; i <= 12; i++) {
        accumulatedDays += NumberOfDayesInMonth(i, year);
        if (accumulatedDays >= dayOfYear) {
            accumulatedDays -= NumberOfDayesInMonth(i, year);
            month = i;
            day = dayOfYear - accumulatedDays;
            break;
        }
    }
    cout << "Date for [" << dayOfYear << "] is " << day << "/" << month << "/"<<year<<endl;
}


int main()
{
    short day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    short month = ReadNumber("Please enter a month", 1, 12,  "month must be between 1 and 12. Please try again.");
    short year = ReadNumber("Please enter a year", 1, 3000,  "year must be between 1 and 3000. Please try again.");
    short Dayes = calculateDayOfYear(day, month, year);
    cout << "Number of days the begining of the year is " << Dayes<<endl;
    calculateDateFromDayOfYear(Dayes, year);
}

 