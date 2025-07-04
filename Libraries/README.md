## 📚 Libraries

This folder contains libraries that centralize reusable functions extracted from individual problems.

### 📌 Why this structure?

Previously, each function used in the problems was written inside the corresponding problem file. While this made each file standalone, it also caused **code duplication**. Many functions—especially matrix operations—were being written again and again in different files.

To solve this and to keep the code **modular, maintainable, and clean**, all common functions are now collected here as libraries.


### 🧱 What's inside?

Currently, this folder includes two main libraries:

* `MatrixLib.h / MatrixLib.cpp`: Contains various matrix-related operations.
  ➤ Filling and printing matrices, matrix multiplication, transpose, row/column sums, sparse matrix checks, palindrome matrix checks, and more.

* `DateLib.h / DateLib.cpp`: Handles operations related to date manipulation.
  ➤ Date increment/decrement, day difference, day of the week, calendar generation, leave/vacation calculation, date comparison, and more.

As new problem topics are introduced (e.g., string, vector, file handling), more libraries will be added to this structure.


### 🧠 Benefits:

* 🔁 **No repetition**: functions are written once and reused.
* 🧩 **Modular**: easier to update or fix logic in one place.
* 📁 **Cleaner repo**: problem files now focus only on solving the problem, not the utility logic.

You can now simply include the library you need in your solution:

```cpp
#include "../Libraries/MatrixLib.h"
```

---

