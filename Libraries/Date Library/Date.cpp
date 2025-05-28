#include <iostream>
#include "Date.h"


namespace Date {

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

    stDate ReadFullDate(string message) {
        stDate Date;
        cout << message << endl;
        Date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
        Date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
        Date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
        return Date;
    }

    stPeriod ReadPeriod(string message) {
	    stPeriod period;
	    cout << message << endl;
	    period.StartDate = ReadFullDate("Enter Start Date :");
	    period.EndDate   = ReadFullDate("Enter End Date :");
	    return period;
}
    bool IsLeapYear(short year) {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }

    bool IsDate1EqualDate2(stDate date1, stDate date2) {
	    return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day == date2.Day ? 1 : 0));
    }
    bool IsDate1AfterDate2(stDate date1, stDate date2) {
	    return date1.Year > date2.Year ? 1 : (date1.Month > date2.Month ? 1 : date1.Day > date2.Day ? 1 : 0);
    }
    bool ISDate1BeforeDate2(stDate date1, stDate date2) {
	    return !IsDate1AfterDate2(date1, date2) && !IsDate1EqualDate2(date1, date2);
    }

    short NumberOfDaysInMonth(short month, short year) {
        if (month < 1 || month > 12) return 0;
        short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (month == 2 && IsLeapYear(year)) ? 29 : days[month - 1];
    }

    short NumberOfHouresInMonth(short year,short month) {
	    return NumberOfDaysInMonth(year, month) * 24;
    }
    int NumberOfMinInMonth(short year, short month) {
	    return NumberOfHouresInMonth(year, month) * 60;
    }
    int NumberOfSecInMonth(short year, short month) {
	    return NumberOfMinInMonth(year,month) * 60;
    }
    
    short DayOfWeekOrder(short day, short month, short year) {
	    short a = (14 - month) / 12;
	    short y = year - a;
	    short m = month + 12 * a - 2;
	    short dow = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	    return (dow + 6) % 7;
    }

    short DayOfWeekOrder(stDate date) {
	    return DayOfWeekOrder(date.Day, date.Month, date.Year);
    }

    string DayShortName(short day) {
	    string days[7] = {
	    	"Monday",
	    	"Tuesday",
	    	"Wednesday",
	    	"Thursday",
	    	"Friday",
	    	"Saturday",
	    	"Sunday"
	    };
	    return days[day];
    }
    string MonthName(short month) {
        string arrMonth[12] = {
           "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        return arrMonth[month-1];
    }
    void PrintMonthCalendar(short month,short year) {
	
	    printf("------------------%s------------------\n\n", MonthName(month).c_str());
	    printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");
	    short Start = DayOfWeekOrder(1,month,year);
	    short NumberOfDayes = NumberOfDaysInMonth(month, year);
	    int i;
	    for (i = 0; i < Start; i++)
	    	printf("     ");
	    for (int j = 1; j <= NumberOfDayes; j++) {
	    	printf("%5d", j);
	    	if (++i == 7) {
	    		i = 0;
	    		printf("\n");
    		}
	    }
	    printf("\n--------------------------------------\n");
    }
    void PrintYearCalendar(short year) {
    	printf("\n==============================\n");
	    printf("        Calendar - %d\n", year);
	    printf("==============================\n");
	    for (int i = 1; i <= 12; i++)
		    PrintMonthCalendar(i, year);
    }
    short NumberOfDaysFromBeginningOfYear(short day, short month, short year) {
	    short Total=0;
    	for (int i = 1; i <= month - 1; i++) {
		    Total += NumberOfDaysInMonth(i, year);
	    }
    	Total += day;
    	return Total;
    }
    stDate calculateDateFromDayOfYear(short dayOfYear, short year) {
        stDate Date;
        Date.Year = year;
        Date.Month = 1;
        short RemainingDays = dayOfYear;
        short monthDayes = 0;
        while (1) {
            monthDayes = NumberOfDaysInMonth(Date.Month, Date.Year);
            if (RemainingDays > monthDayes) {
                RemainingDays -= monthDayes;
                Date.Month++;
            }
            else {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }
    bool IsLastDayInMonth(short day,short month ,short year) {
        return day == NumberOfDaysInMonth(month, year) ? 1 : 0;
    }
    bool IsLastMonthInYear(short month) {
        return month == 12 ? 1 : 0;
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

    int GetDifferenceInDays(stDate date1, stDate date2) {
        int number = 0;
        if (IsDate1EqualDate2(date1, date2))
            return 0;
        if (!IsDate1AfterDate2(date1, date2)) {
            SwapDates(date1, date2);
        }
        for (int i = date2.Year; i < date1.Year; i++)
            IsLeapYear(i) ? number += 366 : number += 365;
        for (int i = date2.Month; i < date1.Month; i++)
            number += NumberOfDaysInMonth(i, date1.Year);
        number += (date1.Day - date2.Day);
        return number;
    }
    int GetDifferenceInDays(stDate date1, stDate date2, bool IncludeEndDay ) {
	    int days = 0;
	    short SawpFlagValue = 1;
	    if (!ISDate1BeforeDate2(date1, date2)) {
	    	//Swap Dates
	    	SwapDates(date1, date2);
	    }
	    while (ISDate1BeforeDate2(date1, date2)) {
	    	days++;
	    	date1 = IncreaseDateByOneDays(date1);
	    }

	    return IncludeEndDay ? ++days : days * SawpFlagValue;
    }
    short NumberOfDaysInYear(short year) {
        return IsLeapYear(year) ? 366 : 365;
    }
    int DeferenceBetweenDate1AndDate(stDate Date1, stDate Date2, bool IncludeEndDay ) {
        int Diferece = 0;
        short DateDays1 = NumberOfDaysFromBeginningOfYear(Date1.Day, Date1.Month, Date1.Year);
        short DateDays2 = NumberOfDaysFromBeginningOfYear(Date2.Day, Date2.Month, Date2.Year);
        for (Date1.Year; Date1.Year < Date2.Year; Date1.Year++) {
            Diferece += NumberOfDaysInYear(Date1.Year);
        }
        Diferece += DateDays2 - DateDays1;
        return IncludeEndDay ? ++Diferece : Diferece;
    }
    stDate GetTodayDate() {
        stDate LocalDate;
        time_t t = time(0);
        tm* now = localtime(&t);

        LocalDate.Year = 1900 + now->tm_year;
        LocalDate.Month = 1 + now->tm_mon;
        LocalDate.Day = now->tm_mday;
        return LocalDate;
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
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.Month, date.Year);
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

    bool IsFirstDayInMonth(short day, short month, short year) {
        return day == 1 ? 1 : 0;
    }

    bool IsFirstMonthInYear(short month) {
        return month == 1 ? 1 : 0;
    }
    void PrintDate(string message,stDate date) {
        cout << message;
        cout << " " << date.Day << "/" << date.Month << "/" << date.Year << endl;
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
                date.Day = NumberOfDaysInMonth(date.Month, date.Year);
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
        short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.Month, date.Year);
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

    bool IsWeekEnd(stDate date) {
	    short day = DayOfWeekOrder(date);
	    return day == 5 || day == 6 ? 1 : 0;
    }
    bool IsEndOfWeek(stDate date) {
	    short day = DayOfWeekOrder(date);
	    return day == 6 ? 1 : 0;
    }

    bool IsBusinessDay(stDate date) {
	    return !IsWeekEnd(date) ;
    }

    short DaysUntilTheEndOfWeek(stDate date) {
	    return 6 - DayOfWeekOrder(date);
    }

    short DaysUntilTheEndOfMonth(stDate date) {
	    return NumberOfDaysInMonth(date.Month, date.Year) - date.Day;
    }

    short DaysUntilTheEndOfYear(stDate date) {
	    short days=0;
	    days += DaysUntilTheEndOfMonth(date);
	    for (int i = date.Month+1; i <=12; i++)
	    {
	    	days += NumberOfDaysInMonth(i,date.Year);
	    }
	    return days;
    }

    short ActionVactationDays(stDate date1, stDate date2) {
	    short DaysConut = 0;
	    while (ISDate1BeforeDate2(date1, date2)) {
		    if(IsBusinessDay(date1))
		    	DaysConut++;
		    date1 = IncreaseDateByOneDays(date1);
	    }
	    return DaysConut;
}

    stDate CalculateVacationReturnDate(stDate dateFrom,short VacationDays) {
	while (VacationDays != 0) {
		dateFrom = IncreaseDateByOneDays(dateFrom);
		if (IsBusinessDay(dateFrom))
			VacationDays--;
	}
	return dateFrom;
}

    enDateCompare CompareDates(stDate date1, stDate date2) {
	    if (ISDate1BeforeDate2(date1, date2))
	    	return enDateCompare::Before;
	    else if (IsDate1AfterDate2(date1, date2))
	    	return enDateCompare::After;
	    else 
	    	return enDateCompare::Equal;
    }

    bool IsPeriodOverlap(stPeriod Period1, stPeriod Period2) {
	    if (
	    	CompareDates(Period2.EndDate,Period1.StartDate)==Before
	    	||
	    	CompareDates(Period1.EndDate,Period2.StartDate)==Before
	        )
	    	return false;
	    return true;
    }
    
    int PeriodLength(stPeriod Period, bool IncludeEndDay ) {
	    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
    }
    
    bool IsDateWithinPeriod(stDate date, stPeriod Period) {
	    return !(ISDate1BeforeDate2(date, Period.StartDate) || IsDate1AfterDate2(date, Period.EndDate));
    }

    int OverlapDaysCount(stPeriod period1, stPeriod period2) {
	    int LengthPeriod1 = PeriodLength(period1);
	    int LengthPeriod2 = PeriodLength(period2);

	    int OverLapDays = 0;
	    if (!IsPeriodOverlap(period1, period2))
	    	return 0;
	    if (LengthPeriod1 < LengthPeriod2) {
	    	while (ISDate1BeforeDate2(period1.StartDate,period1.EndDate)) {
	    		if (IsDateWithinPeriod(period1.StartDate, period2))
	    			OverLapDays++;
	    		period1.StartDate = IncreaseDateByOneDays(period1.StartDate);
	    	}
	    }
	    else {
	    	while (ISDate1BeforeDate2(period2.StartDate, period2.EndDate)) {
	    		if (IsDateWithinPeriod(period2.StartDate, period1))
	    			OverLapDays++;
	    		period2.StartDate = IncreaseDateByOneDays(period2.StartDate);
	    	}
	    }
	    return OverLapDays;
    }

    bool IsValidDate(stDate date) {
	    if (date.Day > NumberOfDaysInMonth(date.Month, date.Year) || date.Day < 1 || date.Day>31 || date.Month < 1 || date.Month>12 || date.Year < 1)
	    	return false;
	    return true;
    }
}
