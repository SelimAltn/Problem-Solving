### 🧮 Project: Math Quiz Game (Question Generator & Evaluator)

---

### 📌 Problem Description

This C++ console project dynamically generates mathematical questions for the user and evaluates their answers. The user is expected to solve randomly generated operations based on selected difficulty and question type. At the end, the program displays a summary including the number of correct/incorrect answers and an overall performance evaluation.

---

### 🛠️ Core Features of the Program

#### 🔹 Game Flow:

1. **Question Count Input**
   The user is asked how many questions they want to answer (between 1–1000).

2. **Difficulty and Question Type Selection**

   * **Difficulty Levels:**

     * 1: Easy (0–15)
     * 2: Medium (16–70)
     * 3: Hard (70–120)
     * 4: Mixed (0–120)
   * **Question Types:**

     * 1: Addition
     * 2: Subtraction
     * 3: Multiplication
     * 4: Division
     * 5: Mixed

3. **Question Generation and Evaluation**
   For each question:

   * Random numbers are generated.
   * The correct result is calculated.
   * User input is collected.
   * If the answer is correct, the score increases; if incorrect, the screen color changes as a warning.

4. **Result Screen**

   * Total number of questions
   * Number of correct answers
   * Number of incorrect answers
   * Success or failure evaluation (with color output)

---

### ✅ Sample Game Flow

```
Please enter how many questions you'd like to answer:  
> 3

-----------------------------------------
       Welcome to Math Game
-----------------------------------------
{    1.EASY,  2.MEDIUM , 3.HARD , 4.MIX        }
PLEASE SELECT DIFFICULTY LEVEL: 1

{    1.ADDITION,  2.SUBTRACTION , 3.MULTIPLICATION , 4.DIVISION, 5.MIX }
PLEASE SELECT QUESTION TYPE: 5

QUESTION 1: 12 * 4 ? 
> 48
Your answer is correct.

QUESTION 2: 8 - 14 ?
> -6
Your answer is correct.

QUESTION 3: 3 + 9 ?
> 13
Wrong answer.

Total Questions: 3  
Correct Answers: 2  
Incorrect Answers: 1  
You passed! ✅
```

---

### 🎯 Purpose

With this project, the user can:

* Practice basic arithmetic operations,
* Solve questions tailored by difficulty and type,
* Learn from their mistakes with immediate feedback.

Additionally, for the developer:

* Modular structure through separate functions,
* Input validation,
* Use of random number generation (`rand()`),
* Colorful output for better user experience (`system("color")`),
* Reinforcement of core C++ concepts like `switch-case`, `char` processing, etc.

---

### 🗂️ File Information

* **File Name**: `math_quiz_game.cpp`
* **Category**: Console Educational Game
* **Level**: Intermediate

---

### 🔧 Suggestions for Improvement

* Add **time limits** for reflex training.
* Save **score history** to a file for performance tracking.
* Visualize the **menu selection** (e.g., ASCII boxes).
* Add **division protection** to prevent errors (`number2 != 0`).
* Include **audio feedback** (beep sound or "Correct!" / "Wrong!" alerts).

---