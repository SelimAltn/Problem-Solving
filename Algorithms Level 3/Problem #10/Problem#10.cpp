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

int main() {
    srand(time(0));
    int arr1[3][3] ;
    FillMatrixWithRandomNumbers(arr1, 3, 3); 
    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);
    cout << "Sum of Maatrix1 : " << SumAllNumerInMatrix(arr1, 3, 3)<<endl;
}

