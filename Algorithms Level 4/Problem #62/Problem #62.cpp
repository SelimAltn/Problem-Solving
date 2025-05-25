#include <iostream>
using namespace std;

struct stDate {
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

stDate ReadDate(string message) {
	stDate date;
	cout << message << endl;
	date.Day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
	date.Month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
	date.Year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
	return date;
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

bool IsValidDate(stDate date) {
	if (date.Day > NumberOfDayesInMonth(date.Month, date.Year) || date.Day < 1 || date.Day>31 || date.Month < 1 || date.Month>12 || date.Year < 1)
		return false;
	return true;
}

int main()
{
	stDate date;
	date = ReadDate("Enter A date : ");
	IsValidDate(date) ? cout << "Yes date is a Valid Date \n" : cout << "No date is not a valid date \n";
}

