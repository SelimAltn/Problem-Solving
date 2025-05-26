#include <iostream>
#include <iomanip> 
using namespace std;

int RandumNamber(int from, int to) {
    return rand() % (to - from + 1) + from;
}
void FillMatrixWithRandomNumbers(int arr[3][3],int from ,int to,short Rows ,short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandumNamber(from, to);
        }
    }
}
short RowSum(int arr[3][3], short RowNumber, short Cols) {
    short Sum = 0;
    for (int i = 0; i < Cols; i++) {
        Sum += arr[RowNumber][i];
    }
    return Sum;
}
void SumMatrixRowsInArry(int arr[3][3],short Rows, short Cols,int RowsSums[3]) {
    for (int i = 0; i < Rows; i++) {
        RowsSums[i] = RowSum(arr, i, Cols);
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        cout << "| ";
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j]<<"   ";
        }
        cout << "|\n";
    }
}
void PrintRowsSumArry(int arr[3]) {
    for (int i = 0; i < 3; i++) {
        cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}
int main() {
    srand(time(0));
    int arr[3][3];
    int RowsSums[3];
    FillMatrixWithRandomNumbers(arr, 1, 9,3,3);
    PrintMatrix(arr,3,3);
    SumMatrixRowsInArry(arr,3,3,RowsSums);
    PrintRowsSumArry(RowsSums);    
}

