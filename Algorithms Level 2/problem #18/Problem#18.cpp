#include <iostream>
using namespace std;
string ReadName()
{
	string name;
	cout << "enter your name \n";
	cin >> name;
	return name;
}
string sifreleme (string name, short artis)
{
	for (int i = 0; i <= name.length(); i++)
	{
		name[i] = char((int)name[i] + artis);
	}
	return name;
}
string belirleme (string name, short artis)
{
	for (int i = 0; i <= name.length(); i++)
	{
		name[i] = char((int)name[i] - artis);
	}
	return name;
}
int main()
{
	const short ArtisMiktari = 3;
	string name = ReadName();
	string Yeni = sifreleme(name, ArtisMiktari);
	cout << sifreleme(name, ArtisMiktari)<<endl;
	cout << belirleme(Yeni, ArtisMiktari) << endl;



}
