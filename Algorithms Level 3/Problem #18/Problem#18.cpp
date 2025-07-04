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
            printf("%*d  ", 2, arr[i][j]);
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

bool IsNumberInMatrix2XFaster(int matrix[3][3], short Number, short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (Number == matrix[i][j])
                return true;
        }
    }
    return  false;
}
void IntercsectedNumber(int Matrix1[3][3],int Matrix2[3][3],int arrIntercsectedNumber[],short Rows,short Cols,short &arrIntercsectedNumberLength) {
    arrIntercsectedNumberLength = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (IsNumberInMatrix2XFaster(Matrix1,Matrix2[i][j],3,3)) {
                arrIntercsectedNumber[arrIntercsectedNumberLength] = Matrix2[i][j];
                arrIntercsectedNumberLength++;
            }
        }
    }

}


int main() {
    srand(time(0));
    int arr1[3][3], arr2[3][3];
    cout << "Matrix 1 : " << endl;
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
    cout << endl<<endl;

    cout << "Matrix 2 : " << endl;
    FillMatrixWithRandomNumbers(arr2, 3, 3);
    PrintMatrix(arr2, 3, 3);
    cout << endl << endl;
    cout << "Intercsected Number are : " << endl;
    int arrIntercsectedNumber[18];
    short length;
    IntercsectedNumber(arr1, arr2, arrIntercsectedNumber, 3, 3,length);
    PrintArr(arrIntercsectedNumber, length);
}

