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
            cout << setw(3) << arr[i][j]<<"   ";
        }
        cout << "|\n";
    }
}

int main() {
    srand(time(0));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 1, 9,3,3);
    PrintMatrix(arr,3,3);
}

