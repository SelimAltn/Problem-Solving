 #include <iostream>
#include <string>
using namespace std;

//enum enSoruSeviyesi { kolay = 1, Orta = 2, Zor = 3, Mix = 4 };
//enum enSoruTuru { Toplama = 1, Çıkartma = 2, Çarpıma = 3, Bölme=4,Mix=5 };

void NumaraAl(short& numara, string message1, string HataMessage, short form, short to)
{
	do {
		cout << message1;
		cin >> numara;
		cout << endl;
		if (numara<form || numara>to) {
			cout << HataMessage << endl;
		}

	} while (numara<form || numara>to);
}
int RandumNamber(int form, int to)
{
	return rand() % (to - form + 1) + form;

}

void HesapMakinasi(short number1, short number2, char islem, short& sonuc)
{
	switch (islem)
	{
	case '+':
		sonuc = 0;
		sonuc = number1 + number2;
		break;
	case '-':
		sonuc = 0;
		sonuc = number1 - number2;
		break;
	case '*':
		sonuc = 0;
		sonuc = number1 * number2;
		break;
	case '/':
		sonuc = 0;
		sonuc = number1 / number2;
		break;
	}
}
void SoruyuSor(short Number1, short Number2, char İslem, short Sonuc, short SoruNumarasi,short &DogruSayisi)
{
	short cevab = 0;
	NumaraAl(cevab, to_string(SoruNumarasi) + ". SORU :    " + to_string(Number1) + İslem + to_string(Number2) + " ? ", "Yalnış Giriş Yaptınız", -10000, 10000);
	if (cevab == Sonuc) {
		cout << "Cevabınız Doğru \n";
		system("color 2F");
		DogruSayisi++;
	}
	else {
		cout << "Yalnış Cevab\n";
		system("color 4F");

	}
}


void OyunBilgilendirme()
{
	cout << "-----------------------------------------\n";
	cout << "       Math Oyunla Hoşgeldiniz \n";
	cout << "-----------------------------------------\n";

}
void MenuGosterme(short &SoruSecimi, short &SeviyeSecimi)
{
	cout << "{    1.KOLAY,  2.ORTA , 3.ZOR , 4.MİX        }\n";
	NumaraAl(SeviyeSecimi, "LUTFEN SORULARIN SEVİYESİNİ SEÇİNİZ : ", "Sdece 1-4 arasındaki sayıları girebilrisiniz ", 1, 4);
	cout << "{    1.TOPLAMA,  2.ÇIKARTMA , 3.ÇARPIMA , 4.BÖLME, 5.MİX        }\n";
	NumaraAl(SoruSecimi, "LUTFEN SORULARIN TİPİNİ SEÇİNİZ : ", "Sdece 1-5 arasındaki sayıları girebilrisiniz ", 1, 5);
}
void SoruSayisiniAl(short &SoruSayisi)
{
	NumaraAl(SoruSayisi, "Lutfen Cevablamak İstediniz Soruların Sayısını Giriniz ", "Sadece 1-1000 Arasındaki sayılar Girebilirsiniz", 1, 1000);
}
void SoruUret(short SoruSeviyesi,short SoruTipi,short SoruNumarasi,short &dogruSayisi)
{
	short Number1=0, Number2=0,Sonuc=0;
	switch (SoruSeviyesi)
	{
	case 1:
		Number1 = RandumNamber(0, 15);
		Number2 = RandumNamber(0, 15);
		break;
	case 2:
		Number1 = RandumNamber(16, 70);
		Number2 = RandumNamber(16, 70);
		break;
	case 3:
		Number1 = RandumNamber(70, 120);
		Number2 = RandumNamber(70, 120);
		break;
	case 4:
		Number1 = RandumNamber(0, 120);
		Number2 = RandumNamber(0, 120);
		break;
	}
	switch (SoruTipi)
	{
	case 1:
		HesapMakinasi(Number1, Number2, '+', Sonuc);
		SoruyuSor(Number1, Number2, '+', Sonuc, SoruNumarasi,dogruSayisi);
		
		break;
	case 2:
		HesapMakinasi(Number1, Number2, '-', Sonuc);
		SoruyuSor(Number1, Number2, '-', Sonuc, SoruNumarasi, dogruSayisi);

		break;
	case 3:
		HesapMakinasi(Number1, Number2, '*', Sonuc);
		SoruyuSor(Number1, Number2, '*', Sonuc, SoruNumarasi, dogruSayisi);
		break;
	case 4:
		HesapMakinasi(Number1, Number2, '/', Sonuc);
		SoruyuSor(Number1, Number2, '/', Sonuc, SoruNumarasi, dogruSayisi);
		break;
	case 5:
		char operations[] = { '+', '-', '*', '/' };
		char İslem = operations[RandumNamber(0, 3)];
		HesapMakinasi(Number1, Number2, İslem, Sonuc); //mix için (+,-,*,/) olabilir
		SoruyuSor(Number1, Number2, İslem, Sonuc, SoruNumarasi, dogruSayisi);
		break;
	}
}

void Sonuc(short SoruSayisi,short DogruSayisi)
{
	short YalnisSayisi = SoruSayisi - DogruSayisi;
	cout << "Sorulan Soruların Sayısı : " << SoruSayisi << endl;
	cout << "Sorulan DOğru Soruların Sayısı : " << DogruSayisi << endl;
	cout << "Sorulan Yalnış Soruların Sayısı : " << YalnisSayisi << endl;
	if (DogruSayisi >= YalnisSayisi) {
		cout << "Başardınız !\a\n";
		system("color 2F");
	}
	else {
		cout << "Başarsız Oldunuz !\n";
		system("color 4F");

	}

}


int main()
{
	srand((unsigned)time(NULL));
	short SoruTurunSecimi=0, SoruSeviyesiniSecimi = 0,SoruSayisi =0,DogruCevablananSorular=0;
	setlocale(LC_ALL, "Turkish");
	SoruSayisiniAl(SoruSayisi);
	OyunBilgilendirme();
	MenuGosterme(SoruTurunSecimi, SoruSeviyesiniSecimi);
	for (int i = 1; i <= SoruSayisi; i++)
	{
		
		SoruUret(SoruSeviyesiniSecimi, SoruTurunSecimi, i,DogruCevablananSorular);
	}
	Sonuc(SoruSayisi, DogruCevablananSorular);
	
}
 