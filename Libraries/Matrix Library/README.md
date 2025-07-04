# MatrixLib

**MatrixLib** is a C++ library that provides a variety of matrix-related utility functions for educational and computational purposes.  
It supports common matrix operations such as random filling, multiplication, search, comparison, and analysis.

## 📚 Overview

This library was built from a collection of over **50 previously solved algorithmic problems**, each one carefully designed and documented with its own `README.md`.  
All functions in this module were thoroughly **tested**, **optimized**, and **refactored** to remove redundant logic and improve clarity and performance.

## ✨ Features

- Fill and print 2D matrices (3×3)
- Element-wise multiplication of two matrices
- Extract middle row/column of a matrix
- Matrix comparison and sum check
- Identity, scaler, sparse matrix detection
- Number counting, searching, and intersection
- Min/max value search
- Palindrome matrix detection
- Input validation and matrix number reading

## 🧪 Example Use

```cpp
#include "MatrixLib.h"
using namespace matrix;

int matrix[3][3];
FillMatrixWithRandomNumbers(matrix, 3, 3);
PrintMatrix(matrix, 3, 3);
cout << "Sum: " << SumAllNumerInMatrix(matrix, 3, 3) << endl;
```

## 🔧 Notes

* All matrix dimensions are assumed to be fixed at **3x3** in this version.
* Designed for educational usage and algorithm training.

## ✅ Tested & Verified

All functions are based on real use cases from university coursework and problem-solving platforms.
They were individually validated and cleaned up across multiple projects.

---

© 2025 – Created as part of structured algorithm training and matrix problem-solving modules.


