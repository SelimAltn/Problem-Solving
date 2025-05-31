#include <iostream>
#include <string>
using namespace std;

string RemoveAllOunctuationsFromString(string Str) {
    string S2 = "";
    for (int i = 0; i < Str.length(); i++) {
        if (!ispunct(Str[i])) {
            S2 += Str[i];
        }
    }
    return S2;
}
int main()
{
    string S1 = "Welcome ! to Jordan , Jordan is a nice country.";  
    cout << S1 << endl;
    cout << "\n\nPauncuations Removed:\n" << RemoveAllOunctuationsFromString(S1);


}