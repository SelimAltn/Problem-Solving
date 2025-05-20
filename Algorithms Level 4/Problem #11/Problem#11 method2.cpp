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


struct Sdate
{
    short day, month, year;
};
Sdate calculateDateFromDayOfYear(short dayOfYear, short year) {
    Sdate Date;
    Date.year = year;
    Date.month = 1;
    short RemainingDays = dayOfYear;
    short monthDayes = 0;
    while (1) {
        monthDayes = NumberOfDayesInMonth(Date.month, Date.year);
        if (RemainingDays > monthDayes) {
            RemainingDays -= monthDayes;
            Date.month++;
        }
        else {
            Date.day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main()
{
    short day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    short month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    short year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    short dayOfYear = calculateDayOfYear(day, month, year);
    cout << "Number of days the begining of the year is " << dayOfYear <<endl;
    Sdate Date;
    Date= calculateDateFromDayOfYear(dayOfYear, year);
    cout << "Date for [" << dayOfYear << "] is: ";
    cout << Date.day << "/" << Date.month << "/" << Date.year;
     

}

 