#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

#include <iostream>
#include "ctime"
#include <iomanip> 
using namespace std;

namespace matrix {
    const short MATRIX_SIZE = 3;

    int RandomNamber(int from, int to);
    void FillMatrixWithRandomNumbers(int arr[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    void MultiplyTowMatrix(int arr1[MATRIX_SIZE][MATRIX_SIZE], int arr2[MATRIX_SIZE][MATRIX_SIZE], int arrResult[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    void PrintMatrix(int arr[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    void PrintArr(int arr[MATRIX_SIZE], short length);
    void MiddleRowOfMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int MiddleRow[MATRIX_SIZE], short Rows, short Cols);
    void MiddleColOfMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int MiddleCol[MATRIX_SIZE], short Rows, short Cols);
    short SumAllNumerInMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool AreEqualMatrices(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool AreMatricesSumEqual(int matrix1[MATRIX_SIZE][MATRIX_SIZE], int matrix2[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool IsdentityMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool IsScalerMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    short ReadNumber(string message, string ErorMessage, short from = -10000, short to = 10000);
    short CountNumerInMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Number, short Rows, short Cols);
    bool IsSparceMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool IsSparceMatrixFaster(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool IsNumberInMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Number, short Rows, short Cols);
    bool IsNumberInMatrix2XFaster(int matrix[MATRIX_SIZE][MATRIX_SIZE], short Number, short Rows, short Cols);
    void IntercsectedNumber(int Matrix1[MATRIX_SIZE][MATRIX_SIZE], int Matrix2[MATRIX_SIZE][MATRIX_SIZE], int arrIntercsectedNumber[], short Rows, short Cols, short &arrIntercsectedNumberLength);
    short MinimumNumberInMatrix(int Matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    short MaxNumberInMatrix(int Matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
    bool IsPalindromeMatrix(int Matrix[MATRIX_SIZE][MATRIX_SIZE], short Rows, short Cols);
}

#endif // MATRIX_LIB_H
