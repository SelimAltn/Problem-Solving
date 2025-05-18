#include <iostream>
using namespace std;

int ReadNumber(string messag)
{
	int number=0;
	cout << messag << endl;
	cin >> number;
	return number;
}

void Sqrt()
{
	float number = ReadNumber("Kokumu Almak İstediniz Sayi Giriniz : ");
	cout << " --> = " << pow(number,0.5)<<endl;
}
int main()
{
	while (true)
	{
		Sqrt();

	}

}

 