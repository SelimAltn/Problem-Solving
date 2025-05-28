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

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols/2; j++) {
            if (Matrix[i][j] != Matrix[i][Cols-1-j])
                return false;
        }
    }
    return true;
}


int main() {
    srand(time(0));
    int arr1[3][3] = { {1,2,1},{5,6,5},{7,8,7} };
    int arr2[3][3] = { {6,2,1},{5,6,5},{7,8,7} };
    PrintMatrix(arr1, 3, 3);
    IsPalindromeMatrix(arr1,3,3) ? cout << "Matrix is Palindrome Matrix" << endl : cout << "Matrix is Not Palindrome Matrix" << endl;

    PrintMatrix(arr2, 3, 3);
    IsPalindromeMatrix(arr2, 3, 3) ? cout << "Matrix is Palindrome Matrix" << endl : cout << "Matrix is Not Palindrome Matrix" << endl;

}

