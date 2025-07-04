### 💡 Problem Description

This C++ program manages a list of bank clients stored in a `.txt` file. It supports loading all clients, displaying them in a formatted table, and deleting a specific client by account number. Instead of deleting directly, a `MarkForDelete` flag is used to skip writing the marked record back to the file — effectively removing it on the next save.

Each client record includes:

* Account Number
* PIN Code
* Name
* Phone Number
* Account Balance

---

### 📌 Program Behavior

1. **Load all clients** from the file:
   Located at:
   `D:\programing\c++\programing kurslar\c++ kurs 8\ConsoleApplication4\file.txt`

2. **Display clients** in a well-formatted table using `setw()` and `left` alignment.

3. **Prompt the user** for an account number.

4. If found:

   * Display the client details.
   * Ask for deletion confirmation.
   * Mark the client as deleted.
   * Save the updated list to the file, excluding deleted clients.

5. **Refresh the list** and show the updated client list after deletion.

---

### ✅ Sample Output

```
                                Client List (3) Client(s).
_______________________________________________________ _________________________________________
| Accout Number  | Pin Code  | Client Name                            | Phone       | Balance     
_______________________________________________________ _________________________________________
| 123456         | 0000      | John Doe                               | 555-1234    | 1200.00     
| 456789         | 1234      | Jane Smith                             | 555-5678    | 3400.50     
| 987654         | 8888      | Ali Maher                              | 555-9090    | 800.00      
_______________________________________________________ _________________________________________

------------------------------------------------------------

Please enter AccountNumber?
456789
Account Number : 456789
Pin Code : 1234
Name : Jane Smith
Phone : 555-5678
Account Balance : 3400.5
Are you sure you want delete this client? y/n ?
y

Client Deleted Successfully.

------------------------------------------------------------
                                Client List (2) Client(s).
...
```

---

### 🎯 Purpose

This program teaches key file and data handling concepts in C++:

* Working with `struct` and `vector` to store and manipulate complex data.
* Using file I/O (`fstream`) to persistently store data.
* Serializing and deserializing data with a custom delimiter (`#//#`).
* Implementing logical deletion via a flag (`MarkForDelete`) instead of immediate removal.
* Formatting tabular output using `iomanip`.

This is a foundational console-based example of simple CRUD operations (Read, Delete) for record-based file systems.

---
