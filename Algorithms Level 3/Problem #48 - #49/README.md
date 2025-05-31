### 💡 Problem Description

This program reads client records from a file, displays all clients in a formatted table, and allows the user to search for a specific client by account number. The records are stored in a text file, each line representing one client, with fields separated by the custom delimiter `#//#`.

The client data includes:

* Account Number
* PIN Code
* Name
* Phone
* Account Balance

---

### 📌 Program Behavior

* Loads client records from:

  ```
  D:\programing\Algorithms & Problem-Solving\Problem-Solving\Algorithms Level 3\Problem #48\file.txt
  ```
* Deserializes each line into a `sClientData` struct.
* Displays all clients in a well-formatted table using `iomanip`.
* Prompts the user to enter an account number to search.
* If the account number exists, displays the full details of the matching client.

---

### ✅ Sample Output

```
                                Client List (3) Client(s).
_______________________________________________________ _________________________________________

| Accout Number  | Pin Code  | Client Name                            | Phone       | Balance     
_______________________________________________________ _________________________________________

| 123456789      | 0000      | John Doe                               | 555-1234    | 1500.75     
| 987654321      | 1234      | Jane Smith                             | 555-5678    | 3200.00     
| 456789123      | 9999      | Ali Maher                              | 555-9012    | 220.10      

_______________________________________________________ _________________________________________



------------------------------------------------------------

Please enter AccountNumber?
987654321
Account Number : 987654321
Pin Code : 1234
Name : Jane Smith
Phone : 555-5678
Account Balance : 3200
```

---

### 🎯 Purpose

This program teaches how to:

* Load and parse structured data from a file.
* Use `struct` and `vector` to manage and manipulate records.
* Format tabular output using `iomanip`.
* Perform search functionality on data loaded from a file.
* Safely read strings from user input using `getline` and `cin >> ws`.

It’s an excellent example of file-based data storage, deserialization, and retrieval in C++.

---
