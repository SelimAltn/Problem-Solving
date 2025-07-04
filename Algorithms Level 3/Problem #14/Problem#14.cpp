#include <iostream>
#include <iomanip> 
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        cout << "| ";
        for (int j = 0; j < Cols; j++) {
            printf("%0*d  ", 2, arr[i][j]);
        }
        cout << "|\n";
    }
}

bool IsScalerMatrix(int matrix[3][3],short Rows,short Cols) {
    int scalarValue = matrix[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i != j && matrix[i][j] != 0)
                return false;
            if (i == j && matrix[i][j] != scalarValue)
                return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    int arr1[3][3]= { {9,0,0},{0,9,0},{0,0,9} };
    PrintMatrix(arr1, 3, 3);
    IsScalerMatrix(arr1, 3, 3) ? cout << "\nYES: Matrix is Scaler." : cout << "\nNo: Matrix is NOT Scaler.";

}

