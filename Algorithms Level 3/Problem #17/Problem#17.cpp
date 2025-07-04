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

short ReadNumber(string message, string ErorMessage, short from=-10000, short to=10000) {
    short Number=0;
    do {
        cout << message << endl;
        cin >> Number;
        if (Number<from || Number>to)
            cout << ErorMessage << endl;
    } while (Number<from||Number>to);
    return  Number;
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

bool IsNumberInMatrix(int matrix[3][3],short Number, short Rows, short Cols) {
    return CountNumerInMatrix(matrix, Number, Rows, Cols) > 0;
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


int main() {
    srand(time(0));
    int arr[3][3];
    FillMatrixWithRandomNumbers(arr, 3, 3);
    PrintMatrix(arr, 3, 3);
    short Number = ReadNumber("Pleace Enter the Number to lock for in matirx ", "");
    IsNumberInMatrix(arr, Number, 3, 3) ? cout << "Yes it is ther \n" : cout << "No it is not ther \n";
    IsNumberInMatrix2XFaster(arr, Number, 3, 3) ? cout << "Yes it is ther \n" : cout << "No it is not ther \n";
}

