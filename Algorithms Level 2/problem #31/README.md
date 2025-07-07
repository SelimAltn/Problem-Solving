

### 💡 Problem Description

This program takes a number from the user and creates an array containing numbers from 1 to that number. Then, it **shuffles** the array randomly and prints both the original and the shuffled versions to the screen.

---

### 📌 Program Flow

1. The program gets the array size from the user (`1–100`).
2. The `Arry1Sayileri` function creates a sequential array starting from 1.
3. The `Arry2` function randomly swaps elements in the array to shuffle it.
4. The `PrintMatris` function prints both the original and the shuffled arrays.

> Note: The shuffle is done using `swap(a, b)` between two random indices.

---

### ✅ Sample Output

```
enter a number 
10
Arri1 :
1 2 3 4 5 6 7 8 9 10 
Arri2 :
5 3 10 1 8 9 2 7 6 4 
```

> Note: The output will vary with each run because the shuffle is random.

---

### 🎯 Purpose

* To gain understanding of array creation and sequencing,
* To learn the shuffle algorithm using random numbers,
* To understand how values in memory change using functions and references (`swap`).
