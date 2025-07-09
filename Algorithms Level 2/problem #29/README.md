### 💡 Problem Description

This program prompts the user to enter an array size and generates an array filled with random numbers between 1 and 100. It then **detects the prime numbers** in the array, copies them into a separate array, and prints both arrays.

📌 **Program Flow:**

1. The user enters the size of the array (between `1–100`).
2. The first array is filled with random numbers (between `1–100`).
3. The `kontrol()` function checks whether each number is a prime.
4. Prime numbers are copied into a second array.
5. Both arrays are printed to the screen.

📌 **Prime Number Check:**

A number is considered prime if it is divisible only by 1 and itself. The program checks primality by attempting to divide the number by all integers from 2 up to half of the number.

---

### ✅ Sample Output

```
enter a Arry size ? 
10
original array : 
56 13 9 23 44 17 20 89 7 38 
2nd array : 
13 23 17 89 7 
```

> Note: The numbers will be randomly generated on each execution.

---

### 🎯 Objective

To teach how to filter prime numbers from an array; reinforce the use of enums, functional decomposition, array copying, and dynamic processing based on user input.
