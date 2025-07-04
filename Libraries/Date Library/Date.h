#ifndef DATE_H
#define DATE_H
#include <string>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

namespace Date {

    struct stDate {
        short Day;
        short Month;
        short Year;
    };
    struct stPeriod {
	    stDate StartDate, EndDate;
    };
    enum enDateCompare { Before = -1, Equal = 0, After = 1 };


    short ReadNumber(string message, short from, short to, string Error_message);
    stDate ReadFullDate(string message);
    stPeriod ReadPeriod(string message);
    bool IsLeapYear(short year);
    bool IsDate1EqualDate2(stDate date1, stDate date2);
    bool IsDate1AfterDate2(stDate date1, stDate date2);
    bool ISDate1BeforeDate2(stDate date1, stDate date2);
    short NumberOfDaysInMonth(short month, short year);
    short NumberOfHouresInMonth(short year,short month);
    int NumberOfMinInMonth(short year, short month);
    int NumberOfSecInMonth(short year, short month);
    short DayOfWeekOrder(short day, short month, short year);
    short DayOfWeekOrder(stDate date);
    string DayShortName(short day);
    string MonthName(short month);
    void PrintMonthCalendar(short month,short year);
    void PrintYearCalendar(short year);
    short NumberOfDaysFromBeginningOfYear(short day, short month, short year);
    stDate calculateDateFromDayOfYear(short dayOfYear, short year);
    void SwapDates(stDate &date1, stDate &date2);
    int GetDifferenceInDays(stDate date1, stDate date2);
    int GetDifferenceInDays(stDate date1, stDate date2, bool IncludeEndDay = false);
    short NumberOfDaysInYear(short year);
    int DeferenceBetweenDate1AndDate(stDate Date1, stDate Date2, bool IncludeEndDay = false);
    stDate GetTodayDate();
    stDate IncreaseDateByOneDays(stDate date);
    stDate IncreaseDateByXDays(stDate date, int X);

    stDate IncreaseDateByOneWeek(stDate date);
    stDate IncreaseDateByXWeeks(stDate date, int X);

    stDate IncreaseDateByOneMonth(stDate date);
    stDate IncreaseDateByXMonths(stDate date, int X);

    stDate IncreaseDateByXyears(stDate date, short X);
    stDate IncreaseDateByOneyearFaster(stDate date);
    stDate IncreaseDateByXyearsFaster(stDate date, int X);

    stDate IncreaseDateByOneDecade(stDate date);
    stDate IncreaseDateByXDecades(stDate date, int X);
    stDate IncreaseDateByXDecadesFaster(stDate date, int X);

    stDate IncreaseDateByOneCentury(stDate date);
    stDate IncreaseDateByOneMillennium(stDate date);

    void PrintDate(string message, stDate date);
    bool IsFirstDayInMonth(short day, short month, short year);
    bool IsFirstMonthInYear(short month);
   
    stDate DecreaseDateByOneDay(stDate date);
    stDate DecreaseDateByXDays(stDate date, int X);

   
    stDate DecreaseDateByOneWeek(stDate date);
    stDate DecreaseDateByXWeeks(stDate date, int X);

   
    stDate DecreaseDateByOneMonth(stDate date);
    stDate DecreaseDateByXMonths(stDate date, int X);

    
    stDate DecreaseDateByXyears(stDate date, short X);
    stDate DecreaseDateByOneyearFaster(stDate date);
    stDate DecreaseDateByXyearsFaster(stDate date, int X);

    
    stDate DecreaseDateByOneDecade(stDate date);
    stDate DecreaseDateByXDecades(stDate date, int X);
    stDate DecreaseDateByXDecadesFaster(stDate date, int X);

    
    stDate DecreaseDateByOneCentury(stDate date);
    stDate DecreaseDateByOneMillennium(stDate date);
    bool IsWeekEnd(stDate date);
    bool IsEndOfWeek(stDate date);
    bool IsBusinessDay(stDate date);
    short DaysUntilTheEndOfWeek(stDate date);
    short DaysUntilTheEndOfMonth(stDate date);
    short DaysUntilTheEndOfYear(stDate date);
    short ActionVactationDays(stDate date1, stDate date2);
    stDate CalculateVacationReturnDate(stDate dateFrom,short VacationDays);
    enDateCompare CompareDates(stDate date1, stDate date2);
    bool IsPeriodOverlap(stPeriod Period1, stPeriod Period2);
    int PeriodLength(stPeriod Period,bool IncludeEndDay = false);
    bool IsDateWithinPeriod(stDate date, stPeriod Period);
    int OverlapDaysCount(stPeriod period1, stPeriod period2);
    bool IsValidDate(stDate date);
}

#endif // DATE_H
