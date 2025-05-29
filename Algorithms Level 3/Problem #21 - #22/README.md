## 💡 Problem Description

This program generates the Fibonacci sequence using **two different approaches**:

1. **Iterative Method:** The sequence is stored in an array and printed afterward.
2. **Recursive Method:** The sequence is printed directly using recursive calls.

---

### 📌 Program Behavior

* **`FibonacciSeriesOfNumber(short Number, int fibo[])`**
  Fills an array with the Fibonacci numbers up to the specified number of terms. Starts with `1, 1`, and each term is the sum of the previous two.

* **`FibonacciSeriesOfNumberRecursive(short Number, short prev1, short prev2)`**
  Recursively prints the Fibonacci numbers starting from given previous values. Prints the result directly instead of storing it.

* **`PrintArr(int arr[], short length)`**
  Prints the array elements in formatted style.

---

### ✅ Example Output

```
     1      1      2      3      5      8     13     21     34     55


1    2    3    5    8    13    21    34    55    89
```

---

### 🎯 Purpose

To demonstrate how the Fibonacci sequence can be calculated both iteratively and recursively. The example helps reinforce understanding of loops, arrays, recursion, and how data can be either stored or processed on the fly.
