### 💡 Problem Description

This program manages client information by converting between structured data and serialized string format. It defines a `struct` to store client data and implements two-way conversion between a record and a delimited string line. It mimics basic serialization/deserialization logic, commonly used in file storage.

Key operations:

* Reading client data from user input.
* Converting the struct to a single delimited line.
* Reconstructing the struct from the line using string parsing.

---

### 📌 Program Behavior

* Prompts the user to enter client details: name, account number, PIN code, phone, and balance.
* Converts the struct to a formatted string using `#//#` as the separator.
* Re-parses that string back into a struct.
* Prints the resulting reconstructed client data.

---

### ✅ Sample Output

```
Enter Client Name
John Doe
Enter Client Account Number
A123
Enter Client Pin Code
4567
Enter Client Phone
555-1234
Enter Client Account Balance
1500.75

A123#//#4567#//#John Doe#//#555-1234#//#1500.750000
Account Number : A123
Pin Code : 4567
Name : John Doe
Phone : 555-1234
Account Balance : 1500.75
```

---

### 🎯 Purpose

This program teaches:

* How to use structs to organize related data in C++.
* How to serialize and deserialize data using string splitting and joining techniques.
* How to convert between `string` and `double` using `stod()` and `to_string()`.

It is especially useful for scenarios involving file I/O, databases, or network protocols that require converting data to/from text-based formats.

---
