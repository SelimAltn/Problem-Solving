
# 🏧 Console ATM System – C++

This project is the continuation of the **bank management system series** created in **Algorithms Course 3**.
The previous projects focused on **bank employees and user permissions**.
👉 This **4th project** introduces an **ATM system for clients**, allowing them to interact with their own accounts.

---

## 📌 Background

* **Project 1 & 2:** Bank employees could add, update, delete, and search clients.  &emsp; [Project1](../../Algorithms%20Level%203/project%201/README.md)  &emsp; [Project2](../../Algorithms%20Level%203/project%202/README.md)

* **Project 3:** User system with permissions for bank employees.&emsp; [Project3](../../Algorithms%20Level%204/Project%201/README.md)

* **Project 4 (this project):** A full **ATM system** where bank clients can log in with their account number + PIN and perform transactions.

---

## 🚀 Features

✅ **Client login with PIN validation (3 attempts)**
✅ **ATM Main Menu:**

* Quick withdraw (predefined amounts)
* Normal withdraw (user-entered amounts)
* Deposit money (with input validation)
* Check account balance
* Logout

✅ **Validations:**

* Max ATM withdrawal limit enforced
* Withdrawals in multiples of 50
* Input checks for amount limits

✅ **File-based data persistence** (via `ClientDB` library)

---

## 💾 Dependencies

* [StringLib](../../Libraries/String%20Library/StringLib.h) – string handling functions
* [ClientDB](../../Libraries/Client%20Libaray/ClientDB.h) – client data and transaction functions



---

## 🖥️ Menu Flow

### 🏧 ATM Main Menu Example:

```
========================================
        ATM main menu screen
========================================
[1] Quick Withdraw
[2] Normal Withdraw
[3] Deposit
[4] Check Balance
[5] Logout
========================================
```

### 💸 Quick Withdraw Options:

```
[1]: 50       [2]: 100
[3]: 150      [4]: 200
[5]: 300      [6]: 400
[7]: 500      [8]: 1000
[9]: Back to main menu
[10]: Logout
```

---

## 📝 Example Run

```cpp
int main() {
    RunApp();  // Starts the ATM system
}
```

The client logs in → accesses ATM features → logs out.

---

## ⚙ Data Handling

Each client record:

* `AccountNumber`
* `PinCode`
* `Name`
* `Phone`
* `AccountBalance`

Data is stored in a text file and managed by `ClientDB`.

---

## 📌 Notes

* This project is designed for **Windows systems** (due to `system("cls")`, `system("pause")`)
* Built in **standard C++** with modular libraries
* This ATM project extends **Project 3** and builds on our bank system series

---

© 2025 – ATM system designed for learning modular design, file-based persistence, and user interaction in C++.

---
