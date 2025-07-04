#include <iostream>
#include <iomanip> 
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        cout << "| ";
        for (int j = 0; j < Cols; j++) {
            printf("%*d  ", 2, arr[i][j]);
        }
        cout << "|\n";
    }
}


short CountNumerInMatrix(int matrix[3][3], short Number, short Rows, short Cols) {
    short Count = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (matrix[i][j] == Number)
                Count++;
        }
    }
    return Count;
}
bool IsSparceMatrix(int matrix[3][3], short Rows, short Cols) {
    short ZeroCounter = 0,NumberCounter=0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (matrix[i][j] == 0)
                ZeroCounter++;
            else
                NumberCounter++;
        }
    }
    return ZeroCounter > NumberCounter;
}
bool IsSparceMatrixFaster(int matrix[3][3], short Rows, short Cols) {
    short MatrixSize = Rows * Cols;
    return CountNumerInMatrix(matrix, 0, 3, 3) > (MatrixSize/2);
}


int main() {
    srand(time(0));
    int arr1[3][3] = {{10,0,12},{20,15,1},{0,0,9}}
      , arr2[3][3] = { {0,0,12},{0,0,1},{0,0,9}};
      cout << "Matrix 1 : " << endl;
      PrintMatrix(arr1, 3, 3);
      IsSparceMatrix(arr1, 3, 3) ? cout << "Yes It Is sparce \n" : cout << "No It Is Not Sparce \n";
      cout << endl << endl;
      cout << "Matrix 2 : " << endl;
      PrintMatrix(arr2, 3, 3);
      IsSparceMatrixFaster(arr2, 3, 3) ? cout << "Yes It Is sparce \n" : cout << "No It Is Not Sparce \n";
}

