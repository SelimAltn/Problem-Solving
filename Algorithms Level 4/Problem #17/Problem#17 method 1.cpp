#include <iostream>
using namespace std;

short ReadNumber(string message, short from, short to, string Error_message);
short NumberOfDayesInMonth(short month, short year);
struct stDate
{
    short Day, Month, Year;
};

stDate ReadDate() {
    stDate date;
    date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    return date;
}

bool IsLastDayInMonth(short day, short month, short year) {
    return day == NumberOfDayesInMonth(month, year) ? 1 : 0;
}

bool IsLeapYear(short year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}

bool IsLastMonthInYear(short month) {
    return month == 12 ? 1 : 0;
}

bool IstDate1EqualDate2(stDate date1, stDate date2) {
    return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day != date2.Day ? 0 : 1));
}

bool IstDate1AfterDate2(stDate date1, stDate date2) {
    return date1.Year > date2.Year ? 1 : (date1.Month > date2.Month ? 1 : (date1.Day > date2.Day ? 1 : 0));
}

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

short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

void SwapDates(stDate &date1, stDate &date2) {
    stDate TempDate;

    TempDate.Day   = date1.Day;
    TempDate.Month = date1.Month;
    TempDate.Year  = date1.Year;

    date1.Day   = date2.Day;
    date1.Month = date2.Month;
    date1.Year  = date2.Year;
    
    date2.Day   = TempDate.Day;
    date2.Month = TempDate.Month;
    date2.Year  = TempDate.Year;
}

short GetDifferenceInDays(stDate date1, stDate date2) {
    short number = 0;
    if (IstDate1EqualDate2(date1, date2))
        return 0;
    if (!IstDate1AfterDate2(date1, date2)) {
        SwapDates(date1, date2);
    }
    for (int i = date2.Year; i < date1.Year; i++)
        IsLeapYear(i) ? number += 366 : number += 365;
    for (int i = date2.Month; i < date1.Month; i++)
        number += NumberOfDayesInMonth(i, date1.Year);
    number += (date1.Day - date2.Day);
    return number;
}

int main()
{
    stDate date1, date2;
    date1 = ReadDate();
    date2 = ReadDate();
    cout << "Diffrence is " << GetDifferenceInDays(date1, date2) << " Day (s)" << endl;
}

