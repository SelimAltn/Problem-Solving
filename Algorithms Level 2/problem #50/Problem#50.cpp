#include <iostream>
using namespace std;

int ReadNumber(string message)
{
	int Number=0;
	cout << message << endl;
	cin >> Number;
	return Number;
}

void Sqrt()
{
	float Number = ReadNumber("Enter the number you want to find the root of");
	cout << " --> = " << pow(Number,0.5)<<endl;
}
int main()
{
	while (true)
	{
		Sqrt();

	}

}

 