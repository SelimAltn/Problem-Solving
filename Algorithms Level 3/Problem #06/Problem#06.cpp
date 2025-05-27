#include <iostream>
#include <iomanip> 
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3],short Rows ,short Cols) {
    short OrderedNumber = 1;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            arr[i][j] = OrderedNumber;
            OrderedNumber++;
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
    int arr[3][3] , RowsSums[3];
    FillMatrixWithOrderedNumbers(arr,3,3);
    cout << "\nThe following is a 3x3 ordered matrix:\n\n";
    PrintMatrix(arr,3,3);   
}