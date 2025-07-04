#include <iostream>
#include <iomanip> 
using namespace std;

int RandomNamber(int from, int to) {
    return rand() % (to - from + 1) + from;
}
void FillMatrixWithRandomNumbers(int arr[3][3],short Rows ,short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = RandomNamber(-30,30);
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

short MinimumNumberInMatrix(int Matrix[3][3],short Rows,short Cols) {
    short MinNumber=Matrix[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            //6 5 7 8
            if (MinNumber > Matrix[i][j])
                MinNumber = Matrix[i][j];
        }
    }
    return  MinNumber;
}
short MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {
    short MaxNumber = Matrix[0][0];
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (MaxNumber < Matrix[i][j])
                MaxNumber = Matrix[i][j];
        }
    }
    return MaxNumber;
}


int main() {
    srand(time(0));
    int arr1[3][3], arr2[3][3];
    cout << "Matrix 1 : " << endl;
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    PrintMatrix(arr1, 3, 3);
    cout << endl<<endl;
    cout << "Min Number is : " << MinimumNumberInMatrix(arr1, 3, 3)<<endl;
    cout << "Max Number is : " << MaxNumberInMatrix(arr1, 3, 3)<<endl;
}

