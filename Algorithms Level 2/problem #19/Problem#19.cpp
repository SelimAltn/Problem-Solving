#include <iostream>
#include<cstdlib>
#include <ctime>
using namespace std;
int ReadNumber(int form , int to)
{
   
    int RastgeleNumber = rand() % (to - form + 1) + form;
    return RastgeleNumber;

}
void Print1_10RastgeleSayiler()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << i << ". number : " << ReadNumber(1, 10) << endl;
    }  
}
int main()
{
    srand(time(0));
    Print1_10RastgeleSayiler();
}

