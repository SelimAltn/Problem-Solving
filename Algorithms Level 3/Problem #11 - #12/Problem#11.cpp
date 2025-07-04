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

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        cout << "| ";
        for (int j = 0; j < Cols; j++) {
            printf("%0*d  ", 2, arr[i][j]);
        }
        cout << "|\n";
    }
}

short SumAllNumerInMatrix(int matrix[3][3], short Rows, short Cols) {
    short Sum = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            Sum += matrix[i][j];
        }
    }
    return Sum;
}
bool AreTypicalMatrices(int matrix1[3][3],int matrix2[3][3],short Rows,short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }
    return true;
}
bool AreMatricesSumEqual(int matrix1[3][3], int matrix2[3][3], short Rows, short Cols) {
    return SumAllNumerInMatrix(matrix1, Rows, Cols) == SumAllNumerInMatrix(matrix2, Rows, Cols) ? 1 : 0;
}

int main() {
    srand(time(0));
    int arr1[3][3],arr2[3][3] ;
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    FillMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    cout << "Matrix 2 : " << endl;
    PrintMatrix(arr2, 3, 3);

    AreTypicalMatrices(arr1, arr2, 3, 3) ? cout << "Yes matrices are Equal \n" : cout << "No Matrices Are Not Equal \n";
    AreMatricesSumEqual(arr1, arr2, 3, 3) ? cout << "Yes matrices sum are Equal \n" : cout << "No Matrices sum Are Not Equal \n";
}

