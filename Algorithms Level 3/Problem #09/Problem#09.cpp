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
void PrintArr(int arr[3], short length) {
    for (int i = 0; i < length; i++) {
        printf(" %0*d  ", 2, arr[i]);
    }
    cout << endl;
}
void MiddleRowOfMatrix(int matrix[3][3], int MiddleRow[3], short Rows, short Cols) {
    int MiddleIndex = Rows / 2;
    for (int i = 0; i < Cols; i++) {
        MiddleRow[i] = matrix[MiddleIndex][i];
    }
}
void MiddleColOfMatrix(int matrix[3][3], int MiddleCol[3], short Rows, short Cols) {
    int MiddleIndex = Cols / 2;
    for (int i = 0; i < Rows; i++) {
        MiddleCol[i] = matrix[i][MiddleIndex];
    }
}

int main() {
    srand(time(0));
    int arr1[3][3] ;
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    
    cout << "\nMatrix  : \n\n";
    PrintMatrix(arr1,3,3);
    int MiddleRow[3], MiddleCol[3];
    MiddleRowOfMatrix(arr1,MiddleRow,3,3);
    cout << "\nMiddle Row Of matrx 1 is : \n";
    PrintArr(MiddleRow, 3);

    MiddleColOfMatrix(arr1, MiddleCol, 3, 3);
    cout << "\nMiddle Col Of matrx 1 is : \n";
    PrintArr(MiddleCol, 3);

   
}

