## 🔠 Capitalize or Lowercase First Letter of Each Word

This program processes a given string by converting the **first letter of each word** to either **uppercase** or **lowercase**, based on the selected function.

---

### 💡 Problem Description

Given a full sentence, the program provides two functionalities:

* Capitalize the first letter of every word (`UpperFirstLetterOfEachWord`)
* Lowercase the first letter of every word (`LowerFirstLetterOfEachWord`)

All other letters remain unchanged.

---

### 📌 How the Program Works

* A boolean flag `IsFirstLetter` checks whether the current character is the beginning of a word.
* If it is, the character is converted using `toupper` or `tolower`.
* The process continues through the entire string character by character.

---

### ✅ Sample Output

```
mohammed saqer abu-Hahdoud

String after conversion:
Mohammed Saqer Abu-Hahdoud
mohammed saqer abu-hahdoud
```

---

### 🎯 Goal

To practice C++ string manipulation by detecting word boundaries and modifying only the first letter of each word while preserving the rest of the text.

---
