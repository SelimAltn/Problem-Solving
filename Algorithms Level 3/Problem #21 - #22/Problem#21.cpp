#include <iostream>
using namespace std;

void FibonacciSeriesOfNumber(short Number, int fibo[]) {
    short sum =1 ;
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i < Number; i++) {
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }
}
void PrintArr(int arr[3], short length) {
    for (int i = 0; i < length; i++) {
        printf(" %*d  ", 6, arr[i]);
    }
    cout << endl;
}
void FibonacciSeriesOfNumberRecursive(short Number, short prev1, short prev2) {
    int fibNumber = 0;
    if (Number > 0) {
        fibNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = fibNumber;
        cout << fibNumber<<"    ";
        FibonacciSeriesOfNumberRecursive(Number - 1, prev1, prev2);
    }
}
int main()
{
    int fibo[10];
    FibonacciSeriesOfNumber(10, fibo);
    PrintArr(fibo, 10);
    cout << endl<<endl;
    FibonacciSeriesOfNumberRecursive(10, 0, 1);
   
}
