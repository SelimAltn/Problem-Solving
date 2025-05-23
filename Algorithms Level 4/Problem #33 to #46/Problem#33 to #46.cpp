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

bool IsFirstDayInMonth(short day, short month, short year) {
    return day == 1 ? 1 : 0;
}

bool IsFirstMonthInYear(short month) {
    return month == 1 ? 1 : 0;
}

short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

stDate DecreaseDateByOneDay(stDate date) {
    if (IsFirstDayInMonth(date.Day, date.Month, date.Year)) {
        if (IsFirstMonthInYear(date.Month)) {
            date.Day = 31;
            date.Month = 12;
            date.Year--;
        }
        else {
            date.Month--;
            date.Day = NumberOfDayesInMonth(date.Month, date.Year);
        }
    }
    else {
        date.Day--;
    }
    return date;

}

stDate DecreaseDateByXDays(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = DecreaseDateByOneDay(date);
    }
    return date;
}

stDate DecreaseDateByOneWeek(stDate date) {
    for (int i = 0; i < 7; i++) {
        date = DecreaseDateByOneDay(date);
    }
    return date;
}

stDate DecreaseDateByXWeeks(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = DecreaseDateByOneWeek(date);
    }
    return date;
}

stDate DecreaseDateByOneMonth(stDate date) {

    IsFirstMonthInYear(date.Month) ? (date.Month = 12, date.Year--) : date.Month--;
    short NumberOfDaysInCurrentMonth = NumberOfDayesInMonth(date.Month, date.Year);
    if (date.Day > NumberOfDaysInCurrentMonth) {
        date.Day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

stDate DecreaseDateByXMonths(stDate date, int X) {

    for (int i = 0; i < X; i++) {
        date = DecreaseDateByOneMonth(date);
    }
    return date;
}

stDate DecreaseDateByXyears(stDate date, short X) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(date.Year - X))
        date.Day = 01, date.Month = 03;
    date = DecreaseDateByXMonths(date, X * 12);
    return date;
}

stDate DecreaseDateByOneyearFaster(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(--date.Year))
        date.Day = 01, date.Month = 03;
    date.Year--;
    return date;
}

stDate DecreaseDateByXyearsFaster(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = DecreaseDateByOneyearFaster(date);
    }
    return date;
}

stDate DecreaseDateByOneDecade(stDate date) {
    date = DecreaseDateByXyearsFaster(date, 10);
    return date;
}

stDate DecreaseDateByXDecades(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = DecreaseDateByXyears(date, 10);
    }
    return date;
}

stDate DecreaseDateByXDecadesFaster(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = DecreaseDateByOneDecade(date);
    }
    return date;
}

stDate DecreaseDateByOneCentury(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(date.Year - 100))
        date.Day = 01, date.Month = 03;
    date.Year -= 100;
    return date;
}

stDate DecreaseDateByOneMillennium(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(date.Year - 1000))
        date.Day = 01, date.Month = 03;
    date.Year -= 1000;
    return date;
}


void PrintDate(string message, stDate date) {
    cout << message;
    cout << " " << date.Day << "/" << date.Month << "/" << date.Year << endl;
}

int main()
{
    stDate date1;
    date1 = ReadDate();
    cout << "Date After : " << endl;

    date1 = DecreaseDateByOneDay(date1);
    PrintDate("01-Subtracting one day is : ", date1);

    date1 = DecreaseDateByXDays(date1, 10);
    PrintDate("02-Subtracting 10 day is : ", date1);

    date1 = DecreaseDateByOneWeek(date1);
    PrintDate("03-Subtracting One Week is : ", date1);

    date1 = DecreaseDateByXWeeks(date1, 10);
    PrintDate("04-Subtracting 10 Week is : ", date1);

    date1 = DecreaseDateByOneMonth(date1);
    PrintDate("05-Subtracting One Month is : ", date1);

    date1 = DecreaseDateByXMonths(date1, 5);
    PrintDate("06-Subtracting 10 Month is : ", date1);

    date1 = DecreaseDateByOneyearFaster(date1);
    PrintDate("07-Subtracting One Year is : ", date1);

    date1 = DecreaseDateByXyears(date1, 10);
    PrintDate("08-Subtracting 10 Years is : ", date1);

    date1 = DecreaseDateByXyearsFaster(date1, 10);
    PrintDate("09-Subtracting 10 Years is (faster) : ", date1);

    date1 = DecreaseDateByOneDecade(date1);
    PrintDate("10-Subtracting One Decade is : ", date1);

    date1 = DecreaseDateByXDecades(date1, 10);
    PrintDate("11-Subtracting 10 Decade is : ", date1);

    date1 = DecreaseDateByXDecadesFaster(date1, 10);
    PrintDate("12-Subtracting 10 Decade is (faster): ", date1);

    date1 = DecreaseDateByOneCentury(date1);
    PrintDate("13-Subtracting One Century is : ", date1);

    date1 = DecreaseDateByOneMillennium(date1);
    PrintDate("14-Subtracting One Millennium is : ", date1);

}

