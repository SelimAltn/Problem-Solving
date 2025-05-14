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
short NumberOfDayesInMonth(short year,short month) {
	if (month < 0 || month>12)
		return 0;
	if (month == 2)
		return IsLeapYear(year) ? 29 : 28;
	short arrDayys31[7] = { 1,3,5,7,8,10,12 };
	for (int i = 0; i < 7; i++) {
		if (arrDayys31[i] == month)
			return 31;
	}
	//else : 
	return 30;	
}
short NumberOfHouresInMonth(short year,short month) {
	return NumberOfDayesInMonth(year, month) * 24;
}
int NumberOfMinInMonth(short year, short month) {
	return NumberOfHouresInMonth(year, month) * 60;
}
int NumberOfSecInMonth(short year, short month) {
	return NumberOfMinInMonth(year,month) * 60;
}


void SonucYazdir(short year , short month) {
	cout << "Number of deys  in Month [ " << month << " ]is : " << NumberOfDayesInMonth(year,month) << endl;
	cout << "Number of Hores in Month [ " << month << " ]is : " << NumberOfHouresInMonth(year,month) << endl;
	cout << "Number of min  in Month [ "  << month << " ]is : " << NumberOfMinInMonth(year, month) << endl;
	cout << "Number of Sec  in Month [ "  << month << " ]is : " << NumberOfSecInMonth(year,month) << endl;
}


int main()
{
	while (1) {
		SonucYazdir(EnterAnumber("Enter a year"), EnterAnumber("Enter a Month"));
	}
}
