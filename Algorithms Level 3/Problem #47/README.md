### 💡 Problem Description

This program allows the user to enter and store multiple clients’ financial data into a `.txt` file in a structured format. Each client’s information is serialized into a single string and appended to the file. The data is saved using a custom delimiter (`#//#`) to allow future parsing.

The program works with the following client fields:

* Account Number
* PIN Code
* Name
* Phone Number
* Account Balance

---

### 📌 Program Behavior

* Prompts the user to enter client information one by one.
* Converts each client record into a formatted line using `ConvertRecordToLine()`.
* Appends the line to the file located at:

  ```
  D:\programing\Algorithms & Problem-Solving\Problem-Solving\Algorithms Level 3\Problem #47\file.txt
  ```
* Asks the user if they want to add more clients after each entry.

---

### ✅ Sample Output

```
Adding New Client 
Enter Client Account Number
123
Enter Client Name
Ali Maher
Enter Client Pin Code
7890
Enter Client Phone
555-7890
Enter Client Account Balance
1000.5
Client Added Successfully do you want to add more clients ? Y / N ?
```

---

### 🎯 Purpose

This program demonstrates how to:

* Use `struct` to model real-world data.
* Take user input with proper handling of `cin` and `getline`.
* Serialize structured data into delimited strings.
* Write data persistently into a file using `fstream` in append mode.
* Perform repeated data entry with loop control.

It’s a foundational example of text-based database storage using file handling in C++.

---
