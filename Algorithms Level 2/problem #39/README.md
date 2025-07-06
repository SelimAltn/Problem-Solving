### 💡 Problem Description

This program creates an array (`arri1`) filled with random numbers between 1 and 100, based on a size provided by the user. Then, it copies all **prime numbers** from this array into a second array (`arri2`). Finally, both arrays are printed to the screen.

---

### 📌 Program Workflow

1. The user is prompted to enter the array size (between `1–100`).
2. The `arri1` array is filled with random numbers ranging from `1–100`.
3. Each element is checked to determine if it is a prime number:

   * If the number is prime, it is added to the `arri2` array.
4. Both the original array (`arri1`) and the filtered prime number array (`arri2`) are printed.

---

### ✅ Sample Output

```
enter arri size : 
10
Arri 1 :{ 6,13,55,29,12,41,38,2,77,17}
Arri 2 :{ 13,29,41,2,17}
```

---

### 🎯 Objective

This problem aims to teach the user:

* Prime number checking algorithm,
* Random array generation,
* Creating a new array using filtering logic,
* Functional and modular programming (including the use of enums),

It especially focuses on **prime number filtering**, which is a common logical task in programming applications.
