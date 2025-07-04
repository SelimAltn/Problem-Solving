#include <iostream>
using namespace std;
short NumberOfDayesInMonth(short month, short year);

struct stDate
{
    short Day, Month, Year;
};

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

stDate ReadDate() {
    stDate date;
    date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    return date;
}

bool IsLeapYear(short year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}
bool IsLastDayInMonth(short day, short month, short year) {
    return day == NumberOfDayesInMonth(month, year) ? 1 : 0;
}

bool IsLastMonthInYear(short month) {
    return month == 12 ? 1 : 0;
}

bool IstDate1EqualDate2(stDate date1, stDate date2) {
    return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day != date2.Day ? 0 : 1));
}

bool IstDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
        Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
            Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

stDate AddOneDay(stDate date) {
    IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
    return date;
}

int GetDifferenceInDays(stDate date1,stDate date2,bool IncludeEndDay=false) {
    int days = 0;
    while (IstDate1BeforeDate2(date1, date2)) {
        days++;
        date1=AddOneDay(date1);
    }

    return IncludeEndDay ? ++days : days;   
}

int main()
{
    stDate date1, date2;
    date1 = ReadDate();
    date2 = ReadDate();
    cout << "Diffrence is " << GetDifferenceInDays(date1, date2) << " Day (s)" << endl;
    cout << "Diffrence (Including End Day) is: " << GetDifferenceInDays(date1, date2,true)<<" Day (s) "<<endl;
}

