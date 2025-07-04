### 💡 Problem Description

This program takes a number between 0 and 100 from the user and creates a **random array** of that length, which can contain both **positive and negative values**. It then analyzes the array to:

* Create a sub-array of the positive numbers,
* Create a sub-array of the negative numbers,
* Calculate and display the count and sum of each group.

---

### 📌 Program Workflow

1. **Input**:

   * The user is prompted to enter an array length between `0–100`.

2. **Array Generation**:

   * The `FillArray()` function generates random numbers between `-100` and `100`.
   * The number `0` is excluded from generation (via control).

3. **Positive Number Analysis**:

   * The `CountPositiveNumbers()` function:

     * Transfers all positive elements into a new array.
     * Calculates the total count and total sum of the values.

4. **Negative Number Analysis**:

   * The `CountNegativeNumbers()` function:

     * Transfers all negative elements into a new array.
     * Calculates the total count and total sum of the values.

5. **Output**:

   * The entire randomly generated array and the sub-arrays are displayed in a formatted manner.

---

### ✅ Example Output

```
Enter desired array length:
15
{ 50 -22 18 74 -61 99 -13 87 -4 -98 1 62 41 -17 8 }

Positive Numbers: { 50 18 74 99 87 1 62 41 8 }
Count of Positive Numbers: 9
Sum of Positive Numbers: 440

Negative Numbers: { -22 -61 -13 -4 -98 -17 }
Count of Negative Numbers: 6
Sum of Negative Numbers: -215
```

---

### 🎯 Purpose

This problem helps the user develop skills in:

* Differentiating between positive and negative numbers,
* Creating sub-arrays and filtering data,
* Performing counting and summing operations,
* Functional design and clean output formatting,

while also practicing **conditional array splitting** and **basic statistical data analysis**.