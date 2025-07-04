#include <iostream>
#include <ctime>
#pragma warning(disable : 4996)

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

bool IsLeapYear(short year) {
	return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
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

stDate GetTodayDate() {
	stDate LocalDate;
	time_t t = time(0);
	tm* now = localtime(&t);

	LocalDate.Year = 1900 + now->tm_year;
	LocalDate.Month = 1 + now->tm_mon;
	LocalDate.Day = now->tm_mday;
	return LocalDate;
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
	return NumberOfDayesInMonth(date.Month, date.Year) - date.Day;
}

short DaysUntilTheEndOfYear(stDate date) {
	short days=0;
	days += DaysUntilTheEndOfMonth(date);
	for (int i = date.Month+1; i <=12; i++)
	{
		days += NumberOfDayesInMonth(i,date.Year);
	}
	return days;
}

int main()
{
	stDate date; 
	date = GetTodayDate();
	cout << "Today is : "<<DayShortName(DayOfWeekOrder(date));
	PrintDate(",", date);

	cout << "is it end of week ? " << endl;
	IsEndOfWeek(date) ? cout << "Yes it is a week end \n" : cout << "No it is not a week end \n";

	cout << "is it Weekend ? " << endl;
	IsWeekEnd(date) ? cout << "Yes it is Weekend \n" : cout << "No it is not Weekend \n";

	cout << "is it Business Day ? " << endl;
	IsBusinessDay(date) ? cout << "Yes it is Business Day \n" : cout << "No it is not Business Day \n";

	cout << "Days Until end of week : " << DaysUntilTheEndOfWeek(date) << endl;
	cout << "Days Until end of month : " << DaysUntilTheEndOfMonth(date) << endl;
	cout << "Days Until end of year : " << DaysUntilTheEndOfYear(date) << endl;
}