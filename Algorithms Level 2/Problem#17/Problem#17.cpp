#include <iostream>
using namespace std;
string ReadSifre()
{
	string sifre ;
	cout << "enter a pasoord \n";
    cin >> sifre;
	return sifre;
}
void PrintSifreler(string sifre)
{
	string kelime;
	int DenemeSayisi = 0;
	for (int i = 65; i < 91; i++)
	{
		for (int j = 65; j < 91; j++)
		{
			for (int k = 65; k < 91; k++)
			{
				kelime += char(i);
				kelime += char(j);
				kelime += char(k);
				if (kelime == sifre)
				{
					cout << " sifre bulundu : " << sifre<<endl;
					cout << " DenemeSayisi : " << DenemeSayisi << endl;
					return;
				}
					
				else
				{
					DenemeSayisi++;
					cout <<"DENEME SAYI : " <<DenemeSayisi<<" kelime is : " << kelime << endl;

				}
					
				kelime = "";
			}
		}
	}
}
int main()
{
	string sifre = ReadSifre();
	PrintSifreler(sifre);
}