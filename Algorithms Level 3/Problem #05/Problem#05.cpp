#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std; 
void PrintSums(vector<int>vSum);
int RandumNamber(int form, int to)
{
    return rand() % (to - form + 1) + form;

}
void FillMatrixWithRandomNumbers(int arr[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = RandumNamber(1, 100);
        }
    }
}
void PrintMatris(int arr[3][3])
{
    for (int i = 0; i < 3; i++) {
        cout << "| ";  
        for (int j = 0; j < 3; j++) {
            cout << setw(3) << arr[i][j] << "       ";
        }
        cout << "|\n"; 
    }
}
void ColSums(vector<int>&vSum,int arr[3][3])
{
    short sum =0; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[j][i];
        }
        vSum.push_back(sum);
        sum = 0;
    }
    PrintSums(vSum);
}
void PrintSums(vector<int>vSum)
{
    cout << endl << endl << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Col " << i + 1 << ".      " << vSum[i] << endl;
    }
}
int main()
{
    vector<int>vSums;
    srand(time(0));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr);
    PrintMatris(arr);
    ColSums(vSums,arr);
}

  