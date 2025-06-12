# 👤 `UserDB` – User Management Library for C++ Console Applications

`UserDB` is a modular C++ library designed to manage **user authentication**, **permission control**, and **user data persistence** in console-based applications.

This library provides essential utilities for managing user records (username, password, permissions), enforcing access control, and reading/writing data to text files in a structured format.

---

## 📦 Features

### ✅ User Record Operations

* Add new user
* Update existing user information
* Delete users (with admin protection)
* Find users by username and/or password
* Display user data in a formatted table

### 🔐 Permission Management

* Bitwise permission system (`enum class Permissions`)
* FullAccess (admin-like) override
* Grant/Revoke specific permissions dynamically

### 📁 File I/O Support

* Custom text format using delimiter `"#//#"`
* Load/save user records to/from file
* Soft-delete support (`MarkForDelete` flag)

---

## 🗃️ Data Model

```cpp
struct sUser {
    std::string UserName;
    std::string Password;
    int permissions;          // bitwise flags
    bool MarkForDelete = false;
};
```

### `Permissions` Enum:

```cpp
enum class Permissions : unsigned int {
    None = 0,
    ShowClientList = 1 << 0,
    AddNewClient   = 1 << 1,
    DeleteClient   = 1 << 2,
    UpdateClient   = 1 << 3,
    FindClient     = 1 << 4,
    Transactions   = 1 << 5,
    ManageUsers    = 1 << 6,
    FullAccess     = static_cast<unsigned int>(-1)
};
```

---

## 🔍 Core Functions

| Function                                              | Purpose                                   |
| ----------------------------------------------------- | ----------------------------------------- |
| `HasUserPermission`                                   | Check if a user has a specific permission |
| `GrantPermission`                                     | Add a permission to a user                |
| `RevokePermission`                                    | Remove a permission from a user           |
| `FindUser`, `FindUserWithUserName`                    | Search for users in file or vector        |
| `ReadUserName`, `ReadUser`, `ReadPermission`          | Console input utilities                   |
| `ConvertUserRecordToLine` / `ConvertUserLineToRecord` | Format ↔ Object                           |
| `SaveUserDataToFile` / `LoadUserDataFromFileToVector` | File operations                           |
| `AccessDenied()`                                      | Displays a permission warning             |
| `PrintUserData`, `ListUser()`                         | Nicely formatted user output              |

---

## 🗂️ Folder Structure

```
Libraries/
└── User Library/
    ├── UserDB.h
    └── UserDB.cpp
```

---

## 📌 Usage Example

```cpp
#include "UserDB.h"
using namespace UserDB;

int main() {
    sUser newUser = ReadUser();
    PrintUserData(newUser);
}
```

---

## 📎 Dependencies

* 🔧 [ClientDB.h](../../Libraries/Client%20Libaray/ClientDB.h) – for input and file utilities
*- 🧰 [StringLib.h](../../Libraries/String%20Library/StringLib.h) – for case-insensitive string comparisons

---

## 🧩 Notes

* This library was created as part of a modular refactor of the **Project 1 ** application from `C++ Algoritma-4 Kursu`.
* The functionality here replaces and enhances the inline user logic with a reusable module.
* You must explicitly include both `UserDB.h` and compile `UserDB.cpp`.

---


© 2025 – Developed for educational and practical modularization in C++.
**Selim Altın**

---

