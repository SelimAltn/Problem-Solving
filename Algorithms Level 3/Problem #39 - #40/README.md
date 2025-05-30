### 💡 Problem Description

This program demonstrates how to manually join a series of strings using function overloading in C++. It defines two overloaded versions of the `JoinString` function to support both `vector<string>` and array-based string inputs. A custom delimiter can be provided, and the function handles the removal of the trailing delimiter.

Functions used:

* `JoinString(vector<string>, string)`: Joins elements of a `vector<string>` with a given delimiter.
* `JoinString(string[], short, string)`: Joins elements of a string array with a given delimiter.

---

### 📌 Program Behavior

* Creates a string vector and a string array.
* Applies the appropriate overloaded `JoinString` function for each container.
* Prints the joined string using `" | "` as the delimiter.

---

### ✅ Sample Output

```
Vector after join: 
Mohammed | Faid | Ali | Maher

Array after join: 
Mohammed | Faid | Ali | Maher
```

---

### 🎯 Purpose

This problem reinforces function overloading in C++ and teaches how to write flexible string joining logic for both vectors and arrays. It also highlights the importance of handling delimiters manually to avoid trailing characters.

---
