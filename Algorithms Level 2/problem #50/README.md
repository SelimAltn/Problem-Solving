### 💡 Problem Description

This program continuously takes a number from the user and calculates its **square root (√)**, displaying the result on the screen. It runs in an infinite loop and keeps calculating square roots as long as the user provides input.

---

### 📌 Program Workflow

1. The `ReadNumber()` function gets a number from the user.
2. The `Sqrt()` function:

   * Calculates the square root using the expression `pow(number, 0.5)`.
   * Prints the result to the screen.
3. The `main()` function continuously calls the `Sqrt()` function using a `while (true)` loop.

> Note: `pow(a, 0.5)` → represents the operation `√a`.

---

### ✅ Example Output

```
Enter the number you want to find the root of: 
25
 --> = 5

Enter the number you want to find the root of: 
2
 --> = 1.41421
```

---

### 🎯 Purpose

This problem aims to teach the user:

* How to calculate square roots using mathematical functions (`pow`),
* How to build an interactive system that runs continuously,
* How to perform numeric operations using basic `float` and `cin` usage.

