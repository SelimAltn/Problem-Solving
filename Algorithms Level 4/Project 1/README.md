# 🏦 C++ Console Bank Management System – **Advanced Multi-User Edition**

This project is an **advanced and modular evolution** of **Project 1** and **Project 2** from the *Algorithms III* course.
It includes significant improvements and new modules like **user management** and **permission-based access control**, in addition to the previously implemented banking and transaction operations.

> 📝 **Note:** This project builds upon the previous versions and adds robust features such as user roles, permission flags, and admin security enhancements.

---

## 🚀 What's New in This Version?

This version introduces a **multi-user login system** with a flexible **permission management module** that controls access to various operations based on user roles. Key additions include:

* 👤 **User Account Management**

  * Add, update, delete, and search user accounts
  * Store users with encrypted access level values
  * Prevent unauthorized deletion of the admin account
  * File-based persistent user storage

* 🔐 **Permissions System**

  * Fine-grained access rights using `bit flags` and `enum class`
  * `FullAccess` mode for admins
  * Runtime permission checks for all menu actions

* 📊 **Improved Interface**

  * Dynamic screens with contextual feedback
  * Permission-based visibility for transaction and user panels
  * Cleaner and more maintainable structure

---
## 🔗 Related Projects

This project is a continuation of the following earlier work:

- 📁 [Project 1 – Console Bank Management System](../../Algorithms%20Level%203/project%201/README.md)
- 📁 [Project 2 – Console Bank Management System – Transactions Upgrade](../../Algorithms%20Level%203/project%202/README.md)

## 📚 Used Libraries

- 🔧 [ClientDB.h](../../Libraries/Client%20Libaray/ClientDB.h)
- 🧰 [StringLib.h](../../Libraries/String%20Library/StringLib.h)


## 📚 Features Overview

### 👥 Client Management

* Add / Update / Delete clients
* Find clients by account number
* View all clients with formatted list
* Persistent storage in `clients.txt`

### 💳 Financial Transactions

* Deposit and withdraw money
* Display total balances across all accounts
* Balance validation for safe withdrawal

### 👤 User Management (NEW)

* Add, delete, and update user accounts
* Full control over assigned permissions
* Admin account is protected from unauthorized changes
* Permissions stored as integer bit flags in `User.txt`

### 🔐 Permission Flags

All permissions are encoded as powers of two and can be combined via bitwise operations:

```cpp
enum class Permissions : unsigned int {
    None             = 0,
    ShowClientList   = 1 << 0,
    AddNewClient     = 1 << 1,
    DeleteClient     = 1 << 2,
    UpdateClient     = 1 << 3,
    FindClient       = 1 << 4,
    Transactions     = 1 << 5,
    ManageUsers      = 1 << 6,
    FullAccess       = static_cast<unsigned int>(-1)
};
```

---

## 🖥️ Menu Structure

### 🧾 Main Menu:

```
[1] Show Client List
[2] Add New Client
[3] Delete Client
[4] Update Client Info
[5] Find Client
[6] Transactions
[7] Manage Users
[8] Logout
```

### 💰 Transactions Submenu:

```
[1] Deposit
[2] Withdraw
[3] Total Balances
[4] Main Menu
```

### 🧑‍💼 Manage Users Submenu:

```
[1] List Users
[2] Add New User
[3] Delete User
[4] Update User
[5] Find User
[6] Back to Main Menu
```

---

## 💾 Data Format

### `clients.txt`

Stores client records in the format:

```
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```

### `User.txt`

Stores user records in the format:

```
UserName#//#Password#//#Permissions
```

---

## 🔧 Dependencies

* `ClientDB.h/.cpp` – Client data handling
* `StringLib.h/.cpp` – String manipulation utilities
* C++ Standard Library (`<iostream>`, `<fstream>`, etc.)

---

## 💡 Example Usage

```cpp
int main() {
    RunApp(); // Starts login and menu loop
}
```

Each operation includes input validation, dynamic screen clearing (`system("cls")`), and pause prompts for better UX.

---

## 🛡️ Security Notes

* Admin account (`Selim`) is protected from unauthorized deletion or full updates.
* All actions are checked via permission system.
* Users cannot update or delete their own accounts while logged in.

---

## 🧠 Educational Purpose

This program demonstrates:

* File I/O handling in C++
* Menu-driven UI design
* Bitwise permission control
* Object structuring and modularity
* Real-world console app architecture

---

## © 2025 – Developed as a capstone enhancement to **Project 1 & 2** in the *Algorithms III* course.

Ready to expand with database support or GUI in future upgrades.

---
