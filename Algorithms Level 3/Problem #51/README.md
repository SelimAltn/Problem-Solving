### 💡 Problem Description

This C++ program allows users to **view**, **update**, and **save** client data from a structured text file. Each client record includes the account number, PIN code, name, phone number, and account balance. Users can search for a client by account number and update their information interactively via the console.

All data is stored and processed using a delimiter-separated format (`#//#`) in a text file.

---

### 📌 Program Behavior

1. **Loads all client records** from the file:

   ```
   D:\programing\Algorithms & Problem-Solving\Problem-Solving\Algorithms Level 3\Problem #51\file.txt
   ```
2. **Displays** all clients in a tabular format.
3. **Prompts the user** to enter an account number.
4. If found:

   * Displays existing client info.
   * Asks for confirmation to update.
   * Allows the user to enter new values for all fields except account number.
   * Saves the updated client list back to the file.
5. **Displays the updated list** again after the update is complete.

---

### ✅ Sample Output

```
                                Client List (3) Client(s).
_______________________________________________________ _________________________________________
| Accout Number  | Pin Code  | Client Name                            | Phone       | Balance     
_______________________________________________________ _________________________________________
| 1001           | 1234      | John Doe                               | 555-1001    | 1500.00     
| 1002           | 2345      | Jane Smith                             | 555-1002    | 2000.00     
| 1003           | 3456      | Ali Maher                              | 555-1003    | 1750.00     
_______________________________________________________ _________________________________________



------------------------------------------------------------

Please enter AccountNumber?
1002
Account Number : 1002
Pin Code : 2345
Name : Jane Smith
Phone : 555-1002
Account Balance : 2000
Are you sure you want Update this client? y/n 
y

Enter PinCode? 9999
Enter Name? Jane Johnson
Enter Phone? 555-9999
Enter AccountBalance? 3300


Client Updated Successfully.



------------------------------------------------------------

                                Client List (3) Client(s).
_______________________________________________________ _________________________________________
| Accout Number  | Pin Code  | Client Name                            | Phone       | Balance     
_______________________________________________________ _________________________________________
| 1001           | 1234      | John Doe                               | 555-1001    | 1500.00     
| 1002           | 9999      | Jane Johnson                           | 555-9999    | 3300.00     
| 1003           | 3456      | Ali Maher                              | 555-1003    | 1750.00     
_______________________________________________________ _________________________________________

```


---

### 🎯 Purpose

This program demonstrates:

* Using `struct` and `vector` to manage and manipulate structured data.
* Reading and writing data from/to a file using `fstream`.
* Custom serialization and deserialization using a delimiter (`#//#`).
* Interactive updating of specific records based on user input.
* Real-world applications of searching, editing, and persisting changes to disk.

It simulates a simple file-based **client management system** with update functionality.

---
