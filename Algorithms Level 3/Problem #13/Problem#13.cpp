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

bool IsdentityMatrix(int matrix[3][3],short Rows,short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if ((i == j && matrix[i][j] != 1)||i != j && matrix[i][j]!=0)
                return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));
    int arr1[3][3]= { {1,0,0},{0,1,0},{0,0,1} };
    PrintMatrix(arr1, 3, 3);
    IsdentityMatrix(arr1, 3, 3) ? cout << "\nYES: Matrix is identity." : cout << "\nNo: Matrix is NOT identity.";

}

