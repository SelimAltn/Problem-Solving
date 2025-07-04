### 💡 Problem Description

This program takes a number between `0–100` from the user and generates an array of that length filled with random numbers. It then separately analyzes the **odd** and **even** numbers in the array:

* Separate sub-arrays are created for odd and even numbers.
* The total number of elements and the total sum for each group are calculated.
* All information is printed to the screen.

---

### 📌 Program Workflow

1. The user is prompted to enter the array length (between `0–100`).  
2. The array is filled with random numbers in the range `1–100`.  
3. The full array is printed.  
4. The `CountOddNumbers()` function:

   * Adds odd numbers to a separate array.
   * Calculates their total count and total sum.

5. The `CountEvenNumbers()` function:

   * Performs the same operations for even numbers.

---

### ✅ Example Output

```
Enter the number of elements for the array:
15
{ 27 14 91 62 33 70 8 9 55 99 10 38 67 12 81 }
Odd Numbers Array: { 27 91 33 9 55 99 67 81 }
Count of Odd Numbers: 8
Sum of Odd Numbers: 462


Even Numbers Array: { 14 62 70 8 10 38 12 }
Count of Even Numbers: 7
Sum of Even Numbers: 214
```

---

### 🎯 Purpose

This problem helps users gain practical experience in:

* Generating random numbers and creating arrays,
* Filtering odd and even numbers,
* Creating and analyzing sub-arrays,
* Structuring tasks with functions

It also emphasizes presenting output in a clear and informative way for the user.