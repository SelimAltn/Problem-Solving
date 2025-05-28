#include "MatrixLib.h"

namespace matrix {
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
    
    void MultiplyTowMatrix(int arr1[3][3],int arr2[3][3],int arrResult[3][3], short Rows, short Cols) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                arrResult[i][j] = arr1[i][j] * arr2[i][j];
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
    
    short SumAllNumerInMatrix(int matrix[3][3], short Rows, short Cols) {
        short Sum = 0;
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                Sum += matrix[i][j];
            }
        }
        return Sum;
    }
    
    bool AreEqualMatrices(int matrix1[3][3],int matrix2[3][3],short Rows,short Cols) {
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
    
    bool IsdentityMatrix(int matrix[3][3],short Rows,short Cols) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                if ((i == j && matrix[i][j] != 1)||i != j && matrix[i][j]!=0)
                    return false;
            }
        }
        return true;
    }
    
    bool IsScalerMatrix(int matrix[3][3],short Rows,short Cols) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                if (i != j && matrix[i][j] != 0)
                    return false;
            }
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
    
    bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols/2; j++) {
                if (Matrix[i][j] != Matrix[i][Cols-1-j])
                    return false;
            }
        }
        return true;
    }
}
