# 🏦 Console Bank Management System – C++

This is a simple **console-based banking system** written in C++ that allows managing client records such as adding, updating, deleting, listing, and searching clients by their account numbers.

The program uses two custom libraries:

- **StringLib** – for string handling and text utilities
- **ClientDB** – for managing client data with file-based persistence

---
## 💾 Dependencies
- [StringLib](../../Libraries/String%20Library/StringLib.h) (for string manipulation functions)
- [ClientDB](../../Libraries/Client%20Libaray/ClientDB.h) (for ClientDB manipulation functions)

---

## 📚 Features

- Show all registered clients
- Add new client(s) with validation
- Delete clients by account number
- Update client information
- Find and display a specific client
- Console interface with input validation and clear screen control

---
## 🚀 Usage Example

```cpp
#include "ClientDB.h"

int main() {
    Bank(); // Starts the client management menu
}
```

When the program runs, it shows a menu where the user can interact with client data:

```
========================================
        Main Menue Scre
========================================
     [1] Show Client List.
     [2] Add New Client.
     [3] Delete Client.
     [4] Update Client Info.
     [5] Find Client.
     [6] Exit.
========================================
```

---

## 💾 Data Handling

Client data is saved and loaded from a text file (`clients.txt`) using the `ClientDB` module.
Each client record contains:

* Account Number
* PIN Code
* Name
* Phone Number
* Account Balance

Duplicate account numbers are not allowed. The program validates input and provides clear error messages.

---

## 📌 Notes

* Only works on **Windows** (due to `system("cls")` and `system("pause")`)
* Built using standard C++ and custom header files
* No external dependencies

---

© 2025 – Developed for learning file I/O, modular programming, and basic data management in C++




