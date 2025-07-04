# 📚 Date Library – C++ Date Handling Library

## 💡 Overview

This library is designed to perform comprehensive and modular date and period operations in C++.  
All functions included have been collected from previously developed and tested problems and unified under this library with a clean and non-redundant structure.

## 🛠️ Scope & Features

* Basic date operations (increment, decrement, comparison)
* Period (start–end) analysis and overlap checking
* Workday, weekend, New Year’s Day, and other special day checks
* Calendar printing, day/week/year difference calculations
* Convenient read/write utility functions for ease of use

## 🧱 Structure

```

project/
│
├── main.cpp           # Usage examples of the library
├── Date.h             # Function prototypes, data structures, enums
└── Date.cpp           # Function implementations

```

All code is organized under the `Date` namespace, which avoids naming conflicts and ensures modular design.

## ⚙️ Usage

```cpp
#include "Date.h"

using namespace Date;

int main() {
    stDate today = GetTodayDate();
    PrintDate("Today's date:", today);
    return 0;
}
```

## 🧪 Verified Problem Set

This library has been compiled from over **50 previously solved and documented date-related problems**, each with its own dedicated `README.md`.
All functions have been thoroughly tested, optimized, and cleaned up to eliminate code duplication.

## 📌 Notes

* The code structure complies with modern C++ standards.
* It is extensible and ready for use in external projects.
* Everything needed is defined within `Date.h` and `Date.cpp` – there are **no external dependencies**.

---

