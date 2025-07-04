#include <iostream>
#include <clocale>
using namespace std;

string NumarayiDonustur(int number) {
    if (number == 0) return "";

    // 1-19 arası
    if (number >= 1 && number <= 19) {
        string arr[] = {
            "", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz", "on",
            "on bir", "on iki", "on üç", "on dört", "on beş", "on altı", "on yedi", "on sekiz", "on dokuz"
        };
        return arr[number] + " ";
    }

    // 20-99 arası
    if (number >= 20 && number <= 99) {
        string arr[] = {
            "", "", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"
        };
        return arr[number / 10] + " " + NumarayiDonustur(number % 10);
    }

    // 100-199 arası
    if (number >= 100 && number <= 199) {
        return "yüz " + NumarayiDonustur(number % 100);
    }

    // 200-999 arası
    if (number >= 200 && number <= 999) {
        return NumarayiDonustur(number / 100) + "yüz " + NumarayiDonustur(number % 100);
    }

    // 1000-1999 arası
    if (number >= 1000 && number <= 1999) {
        return "bin " + NumarayiDonustur(number % 1000);
    }

    // 2000-999.999 arası
    if (number >= 2000 && number <= 999999) {
        return NumarayiDonustur(number / 1000) + "bin " + NumarayiDonustur(number % 1000);
    }

    // 1.000.000-1.999.999 arası
    if (number >= 1000000 && number <= 1999999) {
        return "bir milyon " + NumarayiDonustur(number % 1000000);
    }

    // 2.000.000-999.999.999 arası
    if (number >= 2000000 && number <= 999999999) {
        return NumarayiDonustur(number / 1000000) + "milyon " + NumarayiDonustur(number % 1000000);
    }

    // 1.000.000.000-1.999.999.999 arası
    if (number >= 1000000000 && number <= 1999999999) {
        return "bir milyar " + NumarayiDonustur(number % 1000000000);
    }

    // 2.000.000.000 ve üstü
    if (number >= 2000000000) {
        return NumarayiDonustur(number / 1000000000) + "milyar " 
        + NumarayiDonustur(number % 1000000000);
    }

    return "";
}

int ReadNumber(string message) {
    cout << message << endl;
    int number;
    cin >> number;
    return number;
}

int main() {
    setlocale(LC_ALL, "Turkish"); // Türkçe karakterler için locale ayarı
    while (1) {
        int number = ReadNumber("Bir sayı girin:");
        cout << NumarayiDonustur(number) << endl;
    }
    return 0;
}