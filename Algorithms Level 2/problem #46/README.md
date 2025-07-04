### 💡 Problem Description

This program continuously takes an integer input from the user and calculates the **absolute value** of that number, displaying it on the screen. It runs inside an infinite loop and keeps accepting new input unless the user exits manually.

---

### 📌 Program Workflow

1. The `Input()` function takes an integer from the user.
2. The `AbsoluteValue()` function:

   * Calculates the absolute value using an `if` structure:

     * If the number is negative (`number < 0`), it is multiplied by `-1`.
     * If it's positive or zero, it is returned as-is.
   * Both the original number and the result are printed on the screen:
     `My abs : |original| = absolute value`
3. The `main()` function runs continuously in a `while (true)` loop.

---

### ✅ Example Output

```
Enter a Number : 
-42
My abs : |-42| = 42

Enter a Number : 
0
My abs : |0| = 0

Enter a Number : 
17
My abs : |17| = 17
```

---

### 🎯 Purpose

This problem teaches the user how to:

* Calculate absolute values using conditional statements (`if-else`),
* Handle input/output operations,
* Write interactive programs that run continuously using loops.

Additionally, it reinforces the mathematical concept **|x| = x or -x** through code.
