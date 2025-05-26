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
    return arrMonth[month-1];
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
void PrintMonthCalendar(short month,short year) {
	
	printf("------------------%s------------------\n\n", MonthName(month).c_str());
	printf("  Mon  Tue  Wed  Thu  Fri  Sat  Sun\n");
	short Start = DayOfWeekOrder(1,month,year);
	short NumberOfDayes = NumberOfDayesInMonth(month, year);
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
int main()
{
	short month = ReadNumber("Please enter a month", 1, 12, "only 1-12");
	short year = ReadNumber("Please enter a year", 1, 3000, "1-3000");
	PrintMonthCalendar(month, year);
	return 0;
}
