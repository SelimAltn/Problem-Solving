#include <iostream>
using namespace std;

short ReadNumber(string message, short from, short to, string Error_message) {
    short number;
    do
    {
        cout << message << endl;
        cin >> number;
        if (number<from || number>to)
            cout << Error_message << endl;
    } while (number<from || number>to);
    return number;
}

struct Sdate
{
    short Day, Month, Year;
};
bool IsLeapYear(short year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}
short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}
bool IsLastDayInMonth(short day, short month, short year) {
    return day == NumberOfDayesInMonth(month, year) ? 1 : 0;
}
bool IsLastMonthInYear(short month) {
    return month == 12 ? 1 : 0;
}
void NewYear(Sdate& date) {
    date.Day = 01;
    date.Month = 01;
    date.Year++;
}

Sdate AddOneDay(Sdate date) {
    if (IsLastDayInMonth(date.Day, date.Month, date.Year)) {
        if (IsLastMonthInYear(date.Month)) {
            NewYear(date);
        }
        else {
            date.Day = 01;
            date.Month++;
        }

    }
    else {
        date.Day++;
    }
    return date;
}
Sdate AddOneDay2(Sdate date) {
    IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
    return date;
}
bool IsDate1EqualDate2(Sdate date1, Sdate date2) {
    return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day != date2.Day ? 0 : 1));
}
bool IsDate1AfterDate2(Sdate date1, Sdate date2) {
    return date1.Year > date2.Year ? 1 : (date1.Month > date2.Month ? 1 : (date1.Day > date2.Day ? 1 : 0));
}


Sdate ReadDate() {
    Sdate date;
    date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    return date;
}
short CalculateDate(Sdate date1, Sdate date2) {
    short number = 0;
    for (int i = date2.Year; i < date1.Year; i++)
        IsLeapYear(i) ? number += 366 : number += 365;
    for (int i = date2.Month; i < date1.Month; i++)
        number += NumberOfDayesInMonth(i, date1.Year);
    number += (date1.Day - date2.Day);
    return number;
}
short GetDifferenceInDays(Sdate date1,Sdate date2) {
    if (IsDate1EqualDate2(date1, date2))
        return 0;
    else if (IsDate1AfterDate2(date1, date2)) {
        return  CalculateDate(date1, date2);
    }
    else {
        return CalculateDate(date2, date1);
    }
}
int main()
{
    Sdate date1, date2;
    date1 = ReadDate();
    date2 = ReadDate();
    cout << "Diffrence is " << GetDifferenceInDays(date1, date2)<<" Day (s)"<<endl;
}

