# 🧩 Split String Using Custom Delimiter

## 💡 Problem Description

This program reads a full string from the user and splits it into individual substrings using a **custom delimiter**. It then prints each substring on a new line.

## 📌 Program Features

* Uses `getline()` to safely read the full input line from the user.
* Uses a function `SplitString(string, string)` to split the input string by a given delimiter.
* Stores the resulting parts in a `vector<string>`.
* Uses a separate function `PrintVector()` to display each word on a new line.
* Supports different delimiters — for example: space `" "`, hash `"#"`, comma `","`, etc.

## ✅ Example Output

```
Please Enter Your String ?
apple#banana#cherry#grape

apple  
banana  
cherry  
grape  
```

## 🎯 Purpose

This task introduces vector usage in C++, along with basic string manipulation and custom delimiter-based text splitting. It is foundational for parsing structured data, such as CSV or user-defined input formats.
