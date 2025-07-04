# ClientDB

**ClientDB** is a simple C++ module for managing client records in a file-based banking system.  
It includes utilities for reading and writing client data, updating and deleting records, and displaying formatted client information.

## 📚 Overview

This library is part of a larger system built for managing client data in a lightweight and educational context.  
It was compiled from more than **50 individually solved and documented problem cases**, each with a dedicated `README.md` file.  
All functions in this module were **tested**, **refined**, and **cleaned up** by removing repetitive code and applying the best practices derived from previous projects.

## ✨ Features

- Add, update, delete client records
- Read/write clients to/from plain text files
- Use of `StringLib` for string parsing and cleaning
- Convert between string line and client data structure
- Full console interaction
- Marking clients for logical deletion
- Well-formatted tabular display

## 💾 Dependencies

- [StringLib](../../Libraries/String%20Library/StringLib.h) (for string manipulation functions)

## 📦 Usage

Include the header and use the provided functions:

```cpp
#include "ClientDB.h"
using namespace ClientDB;
```

### Example:

```cpp
vector<sClientData> clients = LoadCleintsDataFromFileToVector();
ShowAllClientsFromFile(clients);
AddClients();
```

## 🧪 Tested & Proven

All components were tested in real-world exercises and university-level projects.
This module is part of an educational system simulating file-based banking operations.

---

© 2025 – Developed as part of structured programming practice and client database management training.

