# StringLib

**StringLib** is a custom C++ header-only library that provides a collection of string-related utility functions, as well as basic tools for input handling, text transformation, and simple array operations (such as Fibonacci series generation).

## 📚 Overview

This library was compiled from solutions to over **50 distinct historical programming problems**, each previously documented with its own dedicated `README.md` file.  
All functions in this library have been **tested**, **optimized**, and **refactored** to remove redundant code.

## ✨ Features

- String splitting and joining
- Text trimming (left, right, both)
- Case conversion (upper/lower/invert)
- Character and vowel analysis
- Word counting and parsing
- Simple input functions
- Fibonacci series (iterative and recursive)
- Punctuation removal and basic replacements

## 🔧 Usage

Simply include the header file in your C++ project:

```cpp
#include "stringlib.h"
using namespace StringLib;
```


You can then call any of the functions directly, e.g.:

```cpp
string input = ReadString("Enter a sentence:");
cout << UpperFirstLetterOfEachWord(input) << endl;
```

## 🧪 Tested & Proven

All utilities in this library have been stress-tested and refined through real-world usage in competitive and academic programming exercises.

---

© 2025 – Compiled and maintained as part of algorithm and problem-solving practice.


