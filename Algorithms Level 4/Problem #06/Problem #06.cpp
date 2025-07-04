#include <iostream>
using namespace std;


short EnterAnumber(string message) {

	short number;
	cout << message << endl;
	cin >> number;
	return number;
}
bool IsLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
short NumberOfDayesInMonth(short year, short month) {
	if (month < 0 || month>12)
		return 0;
	
	short arrDayys31[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDayys31[month - 1];
		
}
short NumberOfHouresInMonth(short year, short month) {
	return NumberOfDayesInMonth(year, month) * 24;
}
int NumberOfMinInMonth(short year, short month) {
	return NumberOfHouresInMonth(year, month) * 60;
}
int NumberOfSecInMonth(short year, short month) {
	return NumberOfMinInMonth(year, month) * 60;
}


void SonucYazdir(short year, short month) {
	cout << "Number of deys  in Month [ " << month << " ]is : " << NumberOfDayesInMonth(year, month) << endl;
	cout << "Number of Hores in Month [ " << month << " ]is : " << NumberOfHouresInMonth(year, month) << endl;
	cout << "Number of min  in Month [ " << month << " ]is : " << NumberOfMinInMonth(year, month) << endl;
	cout << "Number of Sec  in Month [ " << month << " ]is : " << NumberOfSecInMonth(year, month) << endl;
}


int main()
{
	while (1) {
		SonucYazdir(EnterAnumber("Enter a year"), EnterAnumber("Enter a Month"));
	}
}
