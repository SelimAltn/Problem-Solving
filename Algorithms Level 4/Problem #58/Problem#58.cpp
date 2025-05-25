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
	period.EndDate   = ReadDate("Enter End Date :");
	return period;
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
int main()
{
	stPeriod Period1, Period2;
	Period1 = ReadPeriod("Enter Period 1 : ");
	Period2 = ReadPeriod("Enter Period 2 : ");
	IsPeriodOverlap(Period1, Period2) ? cout << "Yes, Period is Overlap"<<endl : cout << "No, Period is Not Overlap" << endl;
}

