 #include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int number;
	cout << message<<endl;
	
	cin >> number;
	return number;
}

void Abs()
{
	int number = ReadNumber("Enter a Number : ");
	int Temp = number;
	if (number < 0)
		number *= -1;
	else if (number > 0)
		number = number;
	else
		number = 0;

	cout << "My abs : |" << Temp<<"| = " << number << endl;
}



int main()
{
	while (true)
	{
		Abs();

	}
}

 