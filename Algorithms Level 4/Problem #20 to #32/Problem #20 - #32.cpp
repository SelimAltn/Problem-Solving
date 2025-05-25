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



short NumberOfDayesInMonth(short month, short year) {
    if (month < 0 || month>12)
        return 0;
    short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
}

stDate IncreaseDateByOneDays(stDate date) {
    IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
    return date;
}

stDate IncreaseDateByXDays(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = IncreaseDateByOneDays(date);
    }
    return date;
}

stDate IncreaseDateByOneWeek(stDate date) {
    for (int i = 0; i < 7; i++) {
        IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
    }
    return date;
}

stDate IncreaseDateByXWeeks(stDate date,int X) {
    for (int i = 0; i < X; i++) {
        date = IncreaseDateByOneWeek(date);
    }
    return date;
}

stDate IncreaseDateByOneMonth(stDate date) {
    
    IsLastMonthInYear(date.Month) ? (date.Month = 01,date.Year++) : date.Month++;
    short NumberOfDaysInCurrentMonth = NumberOfDayesInMonth(date.Month, date.Year);
    if (date.Day > NumberOfDaysInCurrentMonth) {
        date.Day = NumberOfDaysInCurrentMonth;
    }
    return date;
}

stDate IncreaseDateByXMonths(stDate date,int X) {

    for (int i = 0; i < X; i++) {
        date=IncreaseDateByOneMonth(date);
    }
    return date;
}

stDate IncreaseDateByXyears(stDate date,short X) {
    if (date.Day == 29 && date.Month == 2&&!IsLeapYear(date.Year+X))
        date.Day = 01, date.Month = 03;
    date = IncreaseDateByXMonths(date, X * 12);
    return date;
}

stDate IncreaseDateByOneyearFaster(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(++date.Year))
        date.Day = 01, date.Month = 03;
    date.Year++;
    return date;
}

stDate IncreaseDateByXyearsFaster(stDate date,int X) {
    for (int i = 0; i < X; i++) {
        date = IncreaseDateByOneyearFaster(date);
    }
    return date;
}

stDate IncreaseDateByOneDecade(stDate date) {
    date = IncreaseDateByXyearsFaster(date, 10);
    return date;
}

stDate IncreaseDateByXDecades(stDate date,int X) {
    for (int i = 0; i < X; i++) {
        date = IncreaseDateByXyears(date,10);
    }
    return date;
}

stDate IncreaseDateByXDecadesFaster(stDate date, int X) {
    for (int i = 0; i < X; i++) {
        date = IncreaseDateByOneDecade(date);
    }
    return date;
}

stDate IncreaseDateByOneCentury(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(date.Year + 100))
        date.Day = 01, date.Month = 03;
    date.Year += 100;
    return date;
}

stDate IncreaseDateByOneMillennium(stDate date) {
    if (date.Day == 29 && date.Month == 2 && !IsLeapYear(date.Year+1000))
        date.Day = 01, date.Month = 03;
    date.Year += 1000;
    return date;
}


void PrintDate(string message,stDate date) {
    cout << message;
    cout << " " << date.Day << "/" << date.Month << "/" << date.Year << endl;
}

int main()
{
    stDate date1;
    date1 = ReadDate();
    cout << "Date After : " << endl;

    date1 = IncreaseDateByOneDays(date1);
    PrintDate("01-Adding one day is : ", date1);

    date1 = IncreaseDateByXDays(date1,10);
    PrintDate("02-Adding 10 day is : ", date1);

    date1 = IncreaseDateByOneWeek(date1);
    PrintDate("03-Adding One Week is : ", date1);

    date1 = IncreaseDateByXWeeks(date1,10);
    PrintDate("04-Adding 10 Week is : ", date1);

    date1 = IncreaseDateByOneMonth(date1);
    PrintDate("05-Adding One Month is : ", date1);

    date1 = IncreaseDateByXMonths(date1,5);
    PrintDate("06-Adding 10 Month is : ", date1);

    date1 = IncreaseDateByOneyearFaster(date1);
    PrintDate("07-Adding One Year is : ", date1);

    date1 = IncreaseDateByXyears(date1, 10);
    PrintDate("08-Adding 10 Years is : ", date1);

    date1 = IncreaseDateByXyearsFaster(date1,10);
    PrintDate("09-Adding 10 Years is (faster) : ", date1);

    date1 = IncreaseDateByOneDecade(date1);
    PrintDate("10-Adding One Decade is : ", date1);

    date1 = IncreaseDateByXDecades(date1, 10);
    PrintDate("11-Adding 10 Decade is : ", date1);

    date1 = IncreaseDateByXDecadesFaster(date1, 10);
    PrintDate("12-Adding 10 Decade is (faster): ", date1);

    date1 = IncreaseDateByOneCentury(date1);
    PrintDate("13-Adding One Century is : ", date1);

    date1 = IncreaseDateByOneMillennium(date1);
    PrintDate("14-Adding One Millennium is : ", date1);
   
}