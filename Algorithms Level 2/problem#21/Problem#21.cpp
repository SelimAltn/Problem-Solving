#include <iostream>
using namespace std;
short ReadNumber(string messaj)
{
    short number;
    cout << messaj << endl;
    cin >> number;
    return number;
}
int NumberRandum(int form ,int to)
{
    return rand() % (to - form + 1) + form;
}
void PrintWindosAnahtar(short number )
{
    for (int i = 1; i <= number; i++)
    {
        cout << i << ". anahtar : ";
             for (int j = 1; j <= 4; j++)
             {
                      for (int k = 1; k <= 4; k++)
                      {
                          cout << char(NumberRandum(65, 90));
                      }
                      if (j == 4)
                          break;
                      cout << "-";
             }
             cout << endl;
    }
}
int main()
{
    srand(time(0));
    short number = ReadNumber("Enter a number ");
    PrintWindosAnahtar(number);
}

