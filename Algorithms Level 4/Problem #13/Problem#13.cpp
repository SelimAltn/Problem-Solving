#include <iostream>
using namespace std;

short ReadNumber(string message, short from, short to, string Error_message) {
    short number;
    do {
        cout << message << endl;
        cin >> number;
        if (number<from || number>to)
            cout << Error_message << endl;
    } while (number<from || number>to);

    return number;
}


struct Sdate
{
    short day, month, year;
};
Sdate ReadFullDate() {
    Sdate Date;
    Date.day = ReadNumber("Please enter a Day", 1, 31, "Day must be between 1 and 31. Please try again.");
    Date.month = ReadNumber("Please enter a month", 1, 12, "month must be between 1 and 12. Please try again.");
    Date.year = ReadNumber("Please enter a year", 1, 3000, "year must be between 1 and 3000. Please try again.");
    return Date;
}



bool IsDate1AfterDate2(Sdate date1,Sdate date2) {
    return date1.year > date2.year ? 1 : (date1.month > date2.month ? 1 : (date1.day > date2.day ? 1 : 0));
}



int main()
{
    Sdate Date1,Date2;
    Date1 = ReadFullDate();
    Date2 = ReadFullDate();
    IsDate1AfterDate2(Date1, Date2) ? cout << "\nyes Date 2 is less than Date 1 " : cout <<"\nNo, Date 2 is NOT Less than Date1.";

}

