### 💡 Problem Description

This program takes a decimal (float) number from the user and simulates three different **rounding operations** on it:

1. **Round (Mathematical Rounding)**
2. **Floor (Rounding Down)**
3. **Ceil (Rounding Up)**

The user selects an operation from the menu, and the result is calculated and printed accordingly. The rules are correctly applied whether the number is negative or positive.
Note: This problem represents the combination of #47 + #48 + #49.

---

### 📌 Program Workflow:

* A decimal number is taken from the user (e.g., `-2.7`, `3.14`, `5.5`).
* The number is separated into its integer and fractional parts.
* The user selects one of the following operations:

  1. **Round:**

     * Values of `x.5` and above are rounded up to the next integer, values below `x.5` are rounded down.
     * Example: `3.7` → `4`, `2.3` → `2`, `-2.5` → `-3`
  2. **Floor (Referred to as "Float"):**

     * The number is always rounded down (towards the nearest smaller integer).
     * Example: `3.7` → `3`, `-2.3` → `-3`
  3. **Ceil:**

     * The number is always rounded up (towards the nearest greater integer).
     * Example: `3.1` → `4`, `-2.8` → `-2`

---

### ✅ Example Output

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
1
Enter A number
-3.6
In Round :  = -4
```

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
2
Enter A number
3.7
In Float :  = 3
```

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
3
Enter A number
-2.2
In Ceil :  = -2
```

---

### 🎯 Purpose

To work with floating-point numbers, separate a number into its integer and decimal parts, apply different rounding rules, and improve control over conditional structures. The main objective is to teach the logic of **manually implementing mathematical rounding operations**.
