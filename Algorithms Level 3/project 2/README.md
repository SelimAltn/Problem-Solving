# 🏦 C++ Console Bank Management System – Extended Version

This is the **extended version** of the original console-based bank client management system, developed in C++.  
This version introduces new features for **basic financial transactions**, such as deposit, withdrawal, and total balance calculation, alongside the existing functionality for managing client records.

---

## 🚀 What's New in This Version?

Compared to the previous version, this build includes a **Transactions Menu** with the following enhancements:

- ✅ Deposit funds into a client account
- ✅ Withdraw funds from a client account (with balance check)
- ✅ Display total balance of all clients in the system

These features are added to the existing menu-driven interface which already supported:

- Adding new clients
- Updating client data
- Deleting clients
- Searching for specific clients
- Listing all clients

---

## 📚 Features Overview

### 👥 Client Management
- Add, update, delete, and list clients
- Find clients by account number
- Validate uniqueness of account numbers
- Persistent file-based data storage (`clients.txt`)

### 💰 Financial Transactions
- Deposit and withdraw money with input validation
- Prevent withdrawals exceeding account balance
- Calculate and display the total balance across all accounts

---

## 💾 Dependencies
- [StringLib](../../Libraries/String%20Library/StringLib.h) (for string manipulation functions)
- [ClientDB](../../Libraries/Client%20Libaray/ClientDB.h) (for ClientDB manipulation functions)+

---

## 🖥️ Menu System

### 🧾 Main Menu:
```

\[1] Show Client List
\[2] Add New Client
\[3] Delete Client
\[4] Update Client Info
\[5] Find Client
\[6] Transactions
\[7] Exit

```

### 💳 Transactions Submenu:

```

\[1] Deposit
\[2] Withdraw
\[3] Total Balances
\[4] Back to Main Menu

```

---

## 💡 Example Usage

```cpp
int main() {
    Bank();  // Starts the banking system
}
```

Each operation includes clear input prompts, validation, screen clearing (`system("cls")`), and pausing (`system("pause")`) for better user interaction.

---

## 📌 Notes

* This application is designed for **Windows systems**.
* Uses custom libraries: `ClientDB` (for client data) and `StringLib` (for string utilities).
* No external dependencies required.

---

## 📁 Data Format

Each client record includes:

* `AccountNumber`
* `PinCode`
* `Name`
* `Phone`
* `AccountBalance`

Records are stored in a plain text file using a custom delimiter.

---

© 2025 – Extended version developed for enhanced C++ learning, modular system design, and file-based transaction simulation.

