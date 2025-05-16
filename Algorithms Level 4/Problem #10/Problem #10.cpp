#include <iostream>
using namespace std;

short ReadNumber(string mesage, int from, int to, string hataMesage) {
	short number;
	do {
		cout << mesage << endl;
		cin >> number;
		if (number<from || number>to)
			cout << hataMesage << endl;
	} while (number<from || number>to);

	return number;
}
bool IsLeapYear(int number) {

	return number % 400 == 0 || (number % 4 == 0 && number % 100 != 0);
}

short NumberOfDayesInMonth(short month, short year) {
	if (month < 0 || month>12)
		return 0;
	short arrDayys31[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDayys31[month - 1];

}

short Dey(short day, short month, short year) {
	short Total=0;
	for (int i = 1; i <= month - 1; i++) {
		Total += NumberOfDayesInMonth(i, year);
	}
	Total += day;
	return Total;
}

int main()
{
	short day = ReadNumber("Please enter a Day", 1, 31, "only 1-31");
	short month = ReadNumber("Please enter a month", 1, 12, "only 1-12");
	short year = ReadNumber("Please enter a year", 1, 3000, "1-3000");
	cout << "Number of days the begining of the year is " << Dey(day, month, year);
	return 0;
}
