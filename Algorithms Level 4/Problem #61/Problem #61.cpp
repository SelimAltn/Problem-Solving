#include <iostream>
using namespace std;


struct stDate {
	short Day, Month, Year;
};
struct stPeriod {
	stDate StartDate, EndDate;
};
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

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
bool IsDate1EqualDate2(stDate date1, stDate date2) {
	return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day == date2.Day ? 1 : 0));
}
bool IsDate1AfterDate2(stDate date1, stDate date2) {
	return date1.Year > date2.Year ? 1 : (date1.Month > date2.Month ? 1 : date1.Day > date2.Day ? 1 : 0);
}
bool ISDate1BeforeDate2(stDate date1, stDate date2) {
	return !IsDate1AfterDate2(date1, date2) && !IsDate1EqualDate2(date1, date2);

}

stDate ReadDate(string message) {
	stDate date;
	cout << message << endl;
	date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
	date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
	date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
	return date;
}

stPeriod ReadPeriod(string message) {
	stPeriod period;
	cout << message << endl;
	period.StartDate = ReadDate("Enter Start Date :");
	period.EndDate = ReadDate("Enter End Date :");
	return period;
}

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

stDate IncreaseDateByOneDays(stDate date) {
	IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
	return date;
}
void SwapDates(stDate& date1, stDate& date2) {
	stDate TempDate;

	TempDate.Day = date1.Day;
	TempDate.Month = date1.Month;
	TempDate.Year = date1.Year;

	date1.Day = date2.Day;
	date1.Month = date2.Month;
	date1.Year = date2.Year;

	date2.Day = TempDate.Day;
	date2.Month = TempDate.Month;
	date2.Year = TempDate.Year;
}
int GetDifferenceInDays(stDate date1, stDate date2, bool IncludeEndDay = false) {
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
enDateCompare CompareDates(stDate date1, stDate date2) {
	if (ISDate1BeforeDate2(date1, date2))
		return enDateCompare::Before;
	else if (IsDate1AfterDate2(date1, date2))
		return enDateCompare::After;
	else
		return enDateCompare::Equal;
}
int PeriodLength(stPeriod Period, bool IncludeEndDay = false) {
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}
bool IsDateWithinPeriod(stDate date, stPeriod Period) {
	return !(ISDate1BeforeDate2(date, Period.StartDate) || IsDate1AfterDate2(date, Period.EndDate));
}
bool IsPeriodOverlap(stPeriod Period1, stPeriod Period2) {

	if (
		CompareDates(Period2.EndDate, Period1.StartDate) == Before
		||
		CompareDates(Period1.EndDate, Period2.StartDate) == Before
		)
		return false;
	return true;
}
int OverlapDaysCount(stPeriod period1, stPeriod period2) {
	int OverLapDays = 0;
	if (!IsPeriodOverlap(period1, period2))
		return 0;
	int LengthPeriod1 = PeriodLength(period1);

	for (int i = 0; i < LengthPeriod1; i++) {
		if (IsDateWithinPeriod(period1.StartDate, period2))
			OverLapDays++;
		period1.StartDate = IncreaseDateByOneDays(period1.StartDate);
	}
	return OverLapDays;
}
int OverlapDaysCountFaster(stPeriod period1, stPeriod period2) {
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
int main()
{
	stPeriod Period1,Period2;
	Period1 = ReadPeriod("Enter Period 1 : ");
	Period2 = ReadPeriod("Enter Period 2 : ");
	
	cout << "OverLap Days is : " << OverlapDaysCount(Period1, Period2) << endl;
	cout << "OverLap Days is (faster) : " << OverlapDaysCountFaster(Period1,Period2) << endl;

}

