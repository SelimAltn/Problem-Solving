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

short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

short calculateDayOfYear(short day, short month, short year) {
    short Total = 0;
    for (int i = 1; i <= month - 1; i++) {
        Total += NumberOfDayesInMonth(i, year);
    }
    Total += day;
    return Total;
}

struct Sdate
{
    short day, month, year;
};
Sdate ReadFullDate() {
    Sdate Date;
    Date.day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    Date.month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    Date.year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    return Date;
}
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

Sdate DateAddDayes(short Days,Sdate Date) {
    short RemainingDays = Days + calculateDayOfYear(Date.day, Date.month, Date.year);
    short monthDays = 0;
    Date.month = 1;
    while (1) {
        monthDays = NumberOfDayesInMonth(Date.month, Date.year);
        if (RemainingDays > monthDays) {
            RemainingDays -= monthDays;
            Date.month++;
            if (Date.month > 12) {
                Date.month = 1;
                Date.year++;
            }
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
    Sdate Date;
    Date = ReadFullDate();
    short manyDayes = ReadNumber("How many dayes to add ? ",1,30000,"Many Dayes must be between 1 and 3000. Please try again.");
    Date = DateAddDayes(manyDayes, Date);
    cout << "\nDate after adding [" << manyDayes << "] days is: ";
    cout << Date.day << "/" << Date.month << "/" << Date.year;
}

