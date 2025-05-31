### 💡 Problem Description

This program demonstrates two different ways to replace a specific word in a sentence using C++:

1. **Manual replacement** via splitting, case handling, and joining.
2. **Built-in replacement** using `string::replace()` and `string::find()`.

The program supports both **case-sensitive** and **case-insensitive** replacements, allowing users to control matching behavior using the `MatchCase` flag.

---

### 📌 Program Behavior

* Defines a sentence containing duplicate instances of a target word.
* Replaces the word using:

  * A built-in method (`ReplaceWordInStringUsingBuiltInFunction`)
  * A manual method with and without case sensitivity (`ReplaceWordInString`)
* Outputs the results of all three approaches to compare outcomes.

---

### ✅ Sample Output

```
Welcome to Jordan , Jordan is a nice country


String After Replace (Using Built In Function):
Welcome to USA , USA is a nice country

String After Replace (with match case):
Welcome to Jordan , Jordan is a nice country

String After Replace (with dont match case):
Welcome to USA , USA is a nice country
```

---

### 🎯 Purpose

This program teaches:

* How to manipulate strings by splitting and joining.
* How to implement word-level replacement with optional case sensitivity.
* The difference between manual implementation and using built-in string functions.

It reinforces working with `vector<string>`, iterators, string casing (`tolower`), and string searching/replacing in C++.

---
