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

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        cout << "| ";
        for (int j = 0; j < Cols; j++) {
            cout << setw(3) << arr[i][j] << "   ";
        }
        cout << "|\n";
    }
}

short ColSum(int arr[3][3], short Rows, short ColNumber) {
    short sum = 0;
    for (int i = 0; i < Rows; i++) {
        sum += arr[i][ColNumber];
    }
    return sum;
}

void SumMatrixColsInArry(int arr[3][3],short Rows, short Cols,int RowsSums[3]) {
    for (int i = 0; i < Rows; i++) {
        RowsSums[i] = ColSum(arr, Rows, i);
    }
}

void PrintColsSumArry(int arr[3]) {
    for (int i = 0; i < 3; i++) {
        cout << "Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}
int main() {
    srand(time(0));
    int arr[3][3];
    int RowsSums[3];
    FillMatrixWithRandomNumbers(arr, 1, 9,3,3);
    PrintMatrix(arr,3,3);
    SumMatrixColsInArry(arr,3,3,RowsSums);
    PrintColsSumArry(RowsSums);
    
}

