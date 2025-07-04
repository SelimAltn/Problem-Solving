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
string MonthName(short month) {
	string arrMonth[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	return arrMonth[month - 1];
}
short DayOfWeekOrder(short day, short month, short year) {
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	return ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7 + 6) % 7;
}
short NumberOfDayesInMonth(short month, short year) {
	if (month < 0 || month>12)
		return 0;
	short arrDayys31[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : arrDayys31[month - 1];

}
void PrintMonthCalendar(short month, short year) {
	printf("\n----------- %s %d -----------\n", MonthName(month).c_str(), year);
	printf(" Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");

	short start = DayOfWeekOrder(1, month, year);
	short daysInMonth = NumberOfDayesInMonth(month, year);

	int dayCounter = 0;
	for (int i = 0; i < start; i++) {
		printf("     ");
		dayCounter++;
	}

	for (int day = 1; day <= daysInMonth; day++) {
		printf("%4d ", day);
		dayCounter++;
		if (dayCounter == 7) {
			printf("\n");
			dayCounter = 0;
		}
	}

	if (dayCounter != 0)
		printf("\n");
	printf("-------------------------------\n");
}
void PrintYearCalendar(short year) {
	printf("\n==============================\n");
	printf("        Calendar - %d\n", year);
	printf("==============================\n");
	for (int i = 1; i <= 12; i++)
		PrintMonthCalendar(i, year);
}
int main()
{
	short year = ReadNumber("Please enter a year", 1, 3000, "1-3000");
	PrintYearCalendar(year);
	
	return 0;
}
