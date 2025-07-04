İşte metnin İngilizce çevirisi:

---

### 🎮 Project: Rock-Paper-Scissors Game (Console Version)

---

### 📌 Problem Description

This project is a simple console-based application where the user can play **"Rock-Paper-Scissors"** against the computer. The game begins by asking how many rounds will be played. In each round, both the user and the computer make a choice, results are compared, and a detailed summary screen is shown at the end.

---

### 🛠️ Core Features of the Program

#### 🔸 Introduction and Greeting:

* A welcome message is displayed to the player.
* The player is asked to enter the **number of rounds (between 1 and 10)**.

#### 🔸 Game Mechanics:

* In each round, the user makes a selection:

  * `1 = Rock`
  * `2 = Paper`
  * `3 = Scissors`
* The computer makes a random selection (using the `rand()` function).
* Selections are compared and the result is shown immediately.
* Scores are updated based on the winner of each round.
* Screen color feedback:

  * Green: User wins
  * Red: Computer wins
  * Yellow: Draw

#### 🔸 End-of-Game Summary:

* Total number of rounds
* Number of rounds the user won
* Number of rounds the computer won
* Number of draws
* Final winner (whoever won more rounds)

#### 🔸 Play Again Option:

* After the game ends, the user is asked whether they want to play again.
* If yes, the screen is cleared (`system("cls")`) and a new game begins.

---

### ✅ Sample Game Flow

```
--------------------------------------------
Welcome to the Rock-Paper-Scissors Game
--------------------------------------------
Please enter the number of rounds you want to play: 3

----------- ROUND 1 --------------
{ 1.ROCK 2.PAPER 3.SCISSORS }
Enter your choice as a number: 1
          (Player 1 Won)
Player 1: ROCK ------  Player 2: SCISSORS

----------- ROUND 2 --------------
{ 1.ROCK 2.PAPER 3.SCISSORS }
Enter your choice as a number: 2
          (COMPUTER Won)
Player 1: PAPER ------  Player 2: SCISSORS

----------- ROUND 3 --------------
{ 1.ROCK 2.PAPER 3.SCISSORS }
Enter your choice as a number: 2
          (Draw)
Player 1: PAPER ------  Player 2: PAPER

---------------------------------------------
               Game Summary:
---------------------------------------------
Total Rounds:    3
Player 1 Wins:   1
Player 2 Wins:   1
Draws:           1
Final Winner:    Draw
Do you want to play again? (yes: 1 , no: 0)
```

---

### 🎯 Objective

This project aims to reinforce the following concepts:

* Conditional structures (`if-else`)
* Random number generation (`rand`)
* Loops and user interaction
* Functional programming (separation of concerns)
* Colored console output (`system("color")`)
* Console clearing and replay logic (`system("cls")`)
* Basic AI-driven game logic

---

### 🧠 Potential Improvements

* Saving scores to a file
* Logging in with the user’s name
* Advanced graphics or GUI version (SFML, SDL, etc.)
* Character animation or sound effect support

---

### 🗂️ File Info

* **File Name**: `tas_kagit_makas.cpp`
* **Category**: Console Game Project
* **Level**: Beginner–Intermediate

---

> This project is both fun and comprehensive for beginners learning C++. It is highly educational in terms of logic, conditions, randomness, and user interface experience.
