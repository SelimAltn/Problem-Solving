### 💡 Problem Definition

This program checks whether a given 3x3 matrix is an **identity matrix**.

An identity matrix is a square matrix in which:

* All the diagonal elements are `1`.
* All the non-diagonal elements are `0`.

---

### 📌 Program Workflow

1. A predefined 3x3 matrix is used (you can modify it).
2. `PrintMatrix` prints the matrix with formatting.
3. `IsdentityMatrix` checks if the matrix is an identity matrix by iterating through all elements:

   * It verifies `matrix[i][j] == 1` when `i == j` (diagonal),
   * and `matrix[i][j] == 0` when `i != j` (off-diagonal).

---

### ✅ Sample Output

```
| 01  00  00  |
| 00  01  00  |
| 00  00  01  |

YES: Matrix is identity.
```

---

### 🎯 Purpose

To understand identity matrix structure and how to validate it in C++ using nested loops and conditional checks.
