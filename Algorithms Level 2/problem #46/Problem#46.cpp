 #include <iostream>
using namespace std;

int İnput(string message)
{
	int number;
	cout << message<<endl;
	
	cin >> number;
	return number;
}

void MutlakDiger()
{
	int number = İnput("Enter a Number : ");
	int eskiNumber = number;
	if (number < 0)
		number *= -1;
	else if (number > 0)
		number = number;
	else
		number = 0;

	cout << "My abs : |" << eskiNumber<<"| = " << number << endl;
}



int main()
{
	while (true)
	{
		MutlakDiger();

	}
}

 