#include <iostream>
#include <iomanip> 
using namespace std;

int RandomNamber(int from, int to) {
    return rand() % (to - from + 1) + from;
}
void FillMatrixWithRandomNumbers(int arr[3][3],short Rows ,short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNamber(1,9);
        }
    }
}
void MultiplyTowMatrix(int arr1[3][3],int arr2[3][3],int arrResult[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arrResult[i][j] = arr1[i][j] * arr2[i][j];
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

int main() {
    srand(time(0));
    int arr1[3][3] ,arr2[3][3],arrResult[3][3];
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    FillMatrixWithRandomNumbers(arr2,3,3);
    cout << "\nMatrix 1 : \n\n";
    PrintMatrix(arr1,3,3);
    cout << "\nMatrix 2 : \n\n";
    PrintMatrix(arr2, 3, 3);
    MultiplyTowMatrix(arr1, arr2, arrResult, 3, 3);
    cout << "\nResult :\n\n";
    PrintMatrix(arrResult, 3, 3);
}

