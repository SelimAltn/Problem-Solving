#include <iostream>
using namespace std;

short ReadNumber(string message,short from,short to,string Error_message) {
    short number;
    do
    {
        cout << message << endl;
        cin >> number;
        if (number<from || number>to)
            cout << Error_message<<endl;
    } while (number<from||number>to);
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
bool IsLastDayInMonth(short day,short month ,short year) {
    return day == NumberOfDayesInMonth(month, year) ? 1 : 0;
}
bool IsLastMonthInYear(short month) {
    return month == 12 ? 1 : 0;
}

int main()
{
    Sdate date;
    date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    IsLastDayInMonth(date.Day,date.Month,date.Year) ? cout << "yes, Day is Last day in month \n" : cout << "No, Day is not Last day in month \n ";
    IsLastMonthInYear(date.Month) ? cout << "yes, month is Last month in Year \n" : cout << "No, month is not Last month in year \n ";
}

