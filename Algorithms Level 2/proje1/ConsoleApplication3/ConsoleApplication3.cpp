#include <iostream>
using namespace std;

void NumaraAl(short& number, string message1, string messageHata, short form, short to)
{
	cout << message1 ;
	do {
		cin >> number;
		cout << endl;
		if (number <form || number >to) {
			cout << messageHata << endl;
		}
	} while (number <form || number >to);
}

void Bilgilendirme(short &number)
{
	cout << "--------------------------------------------\n";
	cout << "Taş-Makas-Kağaıt Oyunla Hoşgeldiniz \n";
	cout << "--------------------------------------------\n";
	NumaraAl(number, "Lütfen Kaç Kere Oynamak İstediniz tur Sayısını Giriniz :", "En Fazla 10 Tür Oynayabilirisini \nLütfen Tekrar Giriniz", 1, 10);
		

}
void OyunMenusu(short &Secim)
{
	cout << "          { 1.TAŞ 2.KAĞIT 3.MAKAS }\n";
	NumaraAl(Secim, "Oynamak İstediniz Seçimi Numara Olarak Yazınız :", "Lutfen 1-3 Sayılarını Giriniz .", 1, 3);
}
void HarketlerYazdirma(short PlayerSecim, short Player2comSecim)
{
	cout << "1.Player :";
	switch (PlayerSecim)
	{
	case 1:
		cout << "TAŞ";
		break;
	case 2:
		cout << "KAĞIT";
		break;
	case 3:
		cout << "MAKAS";
		break;
	}
	cout << " ------  2.Player : ";
	switch (Player2comSecim)
	{

	case 1:
		cout << "TAŞ";
		break;
	case 2:
		cout << "KAĞIT";
		break;
	case 3:
		cout << "MAKAS";
		break;
	}
	cout << endl;
}

void Berabere(short& PlayerScor, short& ComScore,short player1Secim,short ikinciSecimi)
{
	
	system("color 6F");
	cout << "          (Berabere) \n";
	HarketlerYazdirma(player1Secim, ikinciSecimi);


}
void PlayerKazanma(short& PlayerScor, short player1Secim,short ikinciSecimi)
{
	cout << "          (1.Player Kazandı) \n";
	PlayerScor ++;
	system("color 2F");
	HarketlerYazdirma(player1Secim, ikinciSecimi);

	
}
void BilgisayarKazanma(short& ComScore,short birinciPlayerSecimi,short ikinciSecimi)
{
	ComScore ++;
	cout << "          (BİLGİSAYAR Kazandı) \n";
	system("color 4F");
	HarketlerYazdirma(birinciPlayerSecimi, ikinciSecimi);

}

int RandumNamber(int form, int to)
{
	return rand() % (to - form + 1) + form;

}

void Karsilasma(short Secim, short& PlayerScor, short& ComScore)
{
	short Player1 = Secim;
	short player2_Com = 0;
	player2_Com = RandumNamber(1, 3);
	if (Player1 == player2_Com) {
		Berabere(PlayerScor, ComScore,Player1, player2_Com);
	}
	else if ((Player1 == 1 && player2_Com == 3)||(Player1==3&&player2_Com==2)|| (Player1 == 2 && player2_Com == 1)) {
		PlayerKazanma(PlayerScor,Player1,player2_Com);
	}
	else if ((Player1 == 1 && player2_Com == 2) || (Player1 == 3 && player2_Com == 1) || (Player1 == 2 && player2_Com == 3)) {
		BilgisayarKazanma(ComScore,Player1, player2_Com);
	}

	
}

void OyununOzeti(short oyunSayisi,short player1KazanmaSayisi,short BilgisayarKazanmaSayisi)
{
	cout << "---------------------------------------------"<<endl;
	cout << "               Oyunun Özeti : " << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Tur  Sayısı :    " << oyunSayisi << endl;
	cout << "1.Player Oyun Kazanma Sayısı :   " << player1KazanmaSayisi << endl;
	cout << "2.Player Oyun Kazanma Sayısı :   " << BilgisayarKazanmaSayisi << endl;
	cout << "Berabere Oyun Sayısı :   " << oyunSayisi-(player1KazanmaSayisi+BilgisayarKazanmaSayisi) << endl;
	cout << "Son Kazanan :    ";
	if (BilgisayarKazanmaSayisi>player1KazanmaSayisi) {
		cout << "Bilgisayar Kazandı \n";
		system("color 4F");
	}
	else if (player1KazanmaSayisi>BilgisayarKazanmaSayisi) {
		cout << "SİZ Kazandınız .\a\n";
		system("color 2F");
	}


}

int main()
{
	setlocale(LC_ALL, "Turkish");
	short TurSayisi = 0,secim=0, PlayerScor=0, ComScore=0,  kontrol=0;

	do
	{
		TurSayisi = 0, secim = 0, PlayerScor = 0, ComScore = 0, kontrol = 0;
		Bilgilendirme(TurSayisi);
		for (int i = 1; i <= TurSayisi; i++) {
			cout << "-----------------------------------------------\n";
			cout << "                  " << i << ". TUR  \n";
			OyunMenusu(secim);
			Karsilasma(secim, PlayerScor, ComScore);
		}
		OyununOzeti(TurSayisi, PlayerScor, ComScore);
		cout << "Yeni Oyun Oynamak İstiyormusunuz ? (evet : 1 , Hayır :0 )";
		NumaraAl(kontrol, "Yeni Oyun Oynamak İstiyormusunuz ? ", "(evet : 1 , Hayır :0 ) ile giriniz ", 0, 1);
		
		if(kontrol==1) {
			system("cls");
			system("color 0F");

		}
	} while (kontrol==1);
	




}

 