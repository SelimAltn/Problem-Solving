### 💡 Problem Description

This program prompts the user to enter an array size, then generates an array filled with random numbers between 1 and 100. Afterward, it asks the user to input a number and checks whether that number **exists in the array**. If found, the **index and position** of the number are displayed. If not, the user is informed that the number was not found.

---

### 📌 Program Flow

1. Prompt the user to enter the size of the array (`1–100`).
2. Fill the array with random numbers in the range `1–100`.
3. Display the generated array.
4. Ask the user to input the number they want to search for.
5. Search for the number in the array:

   * If found → Display the index and position (1-based).
   * If not found → Display a warning message.

> Note: The `searchElement()` function returns only the **first occurrence** of the element.

---

### ✅ Sample Output

```
Enter desired array size:  
10  
[ 3, 56, 77, 25, 89, 43, 90, 17, 38, 10 ]  
Enter the number to search for:  
43  
Element found!  
Element index: 5  
Element position: 6  
```

---

### 🎯 Objective

To reinforce the concepts of:

* Random number generation
* Searching elements in arrays
* Interactive input/output with the user
* Understanding array indexing (0-based vs 1-based)

This exercise helps build essential algorithmic thinking and basic problem-solving skills.
