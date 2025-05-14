#include <iostream>
using namespace std;

int ReadNumber(string message) {
    cout << message << endl;
    int number;
    cin >> number;
    return number;
}

bool IsLeapYear(int number) {

    return number % 400 == 0 || (number % 4 == 0 && number % 100 != 0);
}
short NumberOfDeysInYear(short year) {
	return IsLeapYear(year) ? 366 : 365;
}
short NumberOfHoersInYear(short year) {
	return NumberOfDeysInYear(year)*24;
}
short NumberOfMinInYear(short year) {
	return NumberOfHoersInYear(year) * 60;
}
short NumberOfSecInYear(short year) {
	return NumberOfMinInYear(year) * 60;
}



void yazdirSonuc(int year) {
    
    cout << "Number of deys  in year [ " << year << " ]is : "<< NumberOfDeysInYear(year) <<endl;
    cout << "Number of Hores in year [ " << year << " ]is : "<<NumberOfHoersInYear(year)<<endl;
    cout << "Number of min  in year [ " << year << " ]is : "<<NumberOfMinInYear(year)<<endl;
    cout << "Number of Sec  in year [ " <<year << " ]is : "<<NumberOfSecInYear(year)<<endl;
}

int main()
{
    while (1)
    {
        int year = ReadNumber("Enter a Year");
		yazdirSonuc(year);
		char ch;
		cout << "Do you want to continue? (y/n): ";
		cin >> ch;
		if (ch == 'n' || ch == 'N') {
			break;
		}   
    }
    
}

