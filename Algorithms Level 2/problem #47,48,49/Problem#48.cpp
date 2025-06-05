 #include <iostream>
using namespace std;

float ReadNumber(string message,int &Number)
{
	float number;
	cout << message << endl;
	cin >> number;
	Number = int(number);
	return number-int(number);
}

void Round()
{
	int Number=0;
	float number = ReadNumber("Enter A number",Number);
	if (Number > 0) {
		if (number < 0.5) {
			cout << "İn Rounbd : ";
			cout << " =" << Number << endl;
		}
		else if (number >= 0.5) {
			Number++;
			cout << "In Rounbd : ";
			cout << " =" << (Number) << endl;
		}
	}
	else if (Number < 0) {
		if (number <= -0.5) {
			cout << "In Rounbd : ";
			cout << " =" << Number-1 << endl;
		}
		else {
			cout << "In Rounbd : ";
			cout << " =" << Number << endl;
		}
	}
}
void Float()
{
	int Number = 0;
	float number = ReadNumber("Enter A number", Number);
	if (Number > 0) {
		cout << "In Float : ";
		cout << " =" << Number << endl;

	}
	else if (Number < 0) {
		cout << "In Float : ";
		cout << " =" << Number-1 << endl;


	}
}
void Ceil()
{
	int Number = 0;
	float number = ReadNumber("Enter A number", Number);
	if (number == 0) {
		cout << "In Ceil : ";
		cout << " =" << Number  << endl;
	}
	else if (Number > 0) {
		cout << "In Ceil : ";
		cout << " =" << Number+1 << endl;

	}
	else if (Number < 0) {
		cout << "In Ceil : ";
		cout << " =" << Number << endl;


	}
}

int main()
{
	while (true)
	{
		cout << "****************************************\n";
		cout << "MENU : " << endl;
		cout << "1.ROUND :  " << endl;
		cout << "2.FLOAT :  " << endl;
		cout << "3.CEİL :  " << endl;
		cout << "****************************************\n";



		int number;
		cin >> number;
		if (number == 1) {
			Round();
			cout << endl;
		}
		else if (number == 2) {
			Float();
			cout << endl;
		}
		else if (number==3) {
			Ceil();

		}
		else {
			cout << "You have made an invalid input, the program will now exit.\n\a";

			return 0;

		}
	}
}