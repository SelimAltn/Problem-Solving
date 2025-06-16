#include <iostream>
#include <string>

using namespace std;

void name(const string& ad)
{
    cout << "your name is : " << ad << endl;
}

string readname()
{
    string name;
    cout << "enter your name : " << endl;
    getline(cin, name);
    return name;
}

void printname(const string& name)
{
    cout << "your name is : " << name << endl;
}

enum entur { tek = 1, cift = 2 };

int numara()
{
    int sayi;
    cout << "enter a number : " << endl;
    cin >> sayi;
    return sayi;
}

entur incele(int ensayi)
{
    return (ensayi % 2 == 0) ? entur::cift : entur::tek;
}

void print(entur votur)
{
    if (votur == entur::cift)
    {
        cout << "girdiniz sayi çifttir." << endl;
    }
    else
    {
        cout << "girdiniz sayi tektir." << endl;
    }
}

struct usingStruct
{
    short age;
    bool ehliyetVar;
    bool wastaVar;
};

usingStruct readBilgi()
{
    usingStruct info;
    cout << "enter your age : " << endl;
    cin >> info.age;

    do
    {
        cout << "ehliyetiniz var mı? (1 = var, 0 = yok): ";
        cin >> info.ehliyetVar;
        if (info.ehliyetVar == 0 || info.ehliyetVar == 1)
            break;
    } while (true);

    cout << "wasta var mı? (1 = var, 0 = yok): ";
    cin >> info.wastaVar;

    return info;
}

bool kosul(const usingStruct& info)
{
    return (info.age >= 18 && info.ehliyetVar) || info.wastaVar;
}

void printUsing(const usingStruct& info)
{
    if (kosul(info))
    {
        cout << "işe alındınız." << endl;
    }
    else
    {
        cout << "işe alınmadınız." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");

    name("selim");
    printname(readname());
    print(incele(numara()));
    printUsing(readBilgi());

    return 0;
}
