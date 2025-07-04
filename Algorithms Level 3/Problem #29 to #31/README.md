## 🔡 Count Letters and Case-Insensitive Matching

This program analyzes a user-provided string and performs character-based statistics, including:

* Counting **uppercase** and **lowercase** letters.
* Calculating the **frequency** of a specific character with optional **case-insensitive** matching.
* Displaying the **total string length**.

---

### 💡 Problem Description

Given a string and a target character from the user:

* Count and display the number of **uppercase** and **lowercase** characters.
* Count how many times the character appears:

  * **With case sensitivity**
  * **Without case sensitivity**

---

### 📌 How the Program Works

1. The user enters a string.
2. The program displays:

   * String length
   * Count of capital and small letters
3. The user enters a single character.
4. The program displays:

   * Count of the exact character match
   * Count ignoring letter case (e.g., `A` matches both `A` and `a`)

---

### ✅ Sample Output

```
Please Enter Your String ? 
Hello World!

String Length is : 12
Capital Letters Count = 2
Small  Letters Count = 8

Please Enter Your Char ? 
l
Latter 'l' Count : 3
Latter 'l' Or 'L'Count : 4
```

---

### 🎯 Goal

To gain experience in handling string manipulation, case conversion, and flexible character matching logic in C++.

---

