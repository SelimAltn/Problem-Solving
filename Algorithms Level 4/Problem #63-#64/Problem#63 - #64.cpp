#include <iostream>
#include <string>
#include <vector>
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


string ReadStringDate(string message) {
	cout << message << endl;
	string DateString;
	getline(cin >> ws, DateString);
	return DateString;
}
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

stDate StringDateToStructDate(string dateString) {
	stDate date;
	vector <string> vDate;
	vDate = SplitString(dateString, "/");
	date.Day = stoi(vDate[0]);
	date.Month = stoi(vDate[1]);
	date.Year = stoi(vDate[2]);
	return date;
}
string StructDateToStringDate(stDate date) {
	return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
}
int main()
{
	stDate  date;
	date = StringDateToStructDate(ReadStringDate("nPlease Enter Date dd / mm / yyyy"));
	cout << "\nDay:" << date.Day << endl;
	cout << "Month:" << date.Month << endl;
	cout << "Year:" << date.Year << endl;

	cout << "\nYou Entered: " << StructDateToStringDate(date)<<endl;
}

