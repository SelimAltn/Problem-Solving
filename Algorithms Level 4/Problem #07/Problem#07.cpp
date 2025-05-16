#include <iostream>
using namespace std;


short ReadNumber(string mesage,int from,int to,string hataMesage) {
	short number;
	do {
		cout << mesage << endl;
		cin >> number;
		if (number<from || number>to)
			cout << hataMesage << endl;
	} while (number<from || number>to);

	return number;
}
short DayOfWeekOrder(short day,short month,short year) {
	short a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}
string DayShortName(short day) {
	string days[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	return days[day];
}
void TarihAl() {
	short day, month, year;
	day = ReadNumber("Please enter a day ? ",1,31,"Only 1-31 ");
	month = ReadNumber("Please enter a Month ? ",1,12,"Only 1-12");
	year = ReadNumber("Please enter a year ? ",1,3000,"1-3000");
	cout << "Date : " << day << "/" << month << "/" << year << endl;
	short Order = DayOfWeekOrder(day, month, year);	 
	cout << "Day Order : " << Order << endl;
	cout << "Day Name : " << DayShortName(Order)<<endl;
}
int main()
{
	TarihAl();
}