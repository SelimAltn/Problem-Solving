#include <iostream>
using namespace std;
short DayOfWeekOrder(short day, short month, short year);

bool IsLeapYear(short year);

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

short NumberOfDayesInMonth(short month, short year) {
	if (month < 0 || month>12)
		return 0;
	short daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : daysInMonths[month - 1];
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

void PrintDate(string message, stDate date) {
	cout << message;
	cout << " " << date.Day << "/" << date.Month << "/" << date.Year << endl;

}

bool IsLeapYear(short year) {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate date1, stDate date2) {
	return date1.Year != date2.Year ? 0 : (date1.Month != date2.Month ? 0 : (date1.Day != date2.Day ? 0 : 1));
}

bool IsLastDayInMonth(short day, short month, short year) {
	return day == NumberOfDayesInMonth(month, year) ? 1 : 0;
}

bool IsLastMonthInYear(short month) {
	return month == 12 ? 1 : 0;
}

bool IsWeekEnd(stDate date) {
	short day = DayOfWeekOrder(date);
	return day == 5 || day == 6 ? 1 : 0;
}

bool IsBusinessDay(stDate date) {
	return !IsWeekEnd(date);
}

stDate ReadDate(string message) {
	stDate date;
	cout << message << endl;
	date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
	date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
	date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
	return date;
}

stDate IncreaseDateByOneDays(stDate date) {
	IsLastDayInMonth(date.Day, date.Month, date.Year) ? (IsLastMonthInYear(date.Month) ? (date.Day = 01, date.Month = 01, date.Year++) : (date.Day = 01, date.Month++)) : date.Day++;
	return date;
}

stDate CalculateVacationReturnDateFaster(stDate dateFrom,short VacationDays) {
	while (VacationDays != 0) {
		dateFrom = IncreaseDateByOneDays(dateFrom);
		if (IsBusinessDay(dateFrom))
			VacationDays--;
	}
	return dateFrom;
}

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
	while (IsWeekEnd(DateFrom)) {
		DateFrom = IncreaseDateByOneDays(DateFrom);
	}

	while (VacationDays > 0) {
		if (IsBusinessDay(DateFrom)) {
			VacationDays--;
		}
		if (VacationDays == 0) break; // Fazladan artmayı engeller
		DateFrom = IncreaseDateByOneDays(DateFrom);
	}

	while (IsWeekEnd(DateFrom)) {
		DateFrom = IncreaseDateByOneDays(DateFrom);
	}

	return DateFrom;
}

int main()
{
	stDate dateFrom,datefromFaster;
	dateFrom = ReadDate("Vacation Starts : ");
	datefromFaster = dateFrom;

	short VacationDays = ReadNumber("Please Enter vacation days ? ",1,365,"1-365");
	dateFrom = CalculateVacationReturnDate(dateFrom, VacationDays);
	cout << "Return date : "<< DayShortName(DayOfWeekOrder(dateFrom));
	PrintDate(",", dateFrom);

	datefromFaster = CalculateVacationReturnDateFaster(datefromFaster, VacationDays);
	cout << "Return date (faster): " << DayShortName(DayOfWeekOrder(datefromFaster));
	PrintDate(",", datefromFaster);

}

