# 🧮 Math Quiz Game (C++)

An interactive, educational console-based **Math Quiz Game** developed in C++. Designed as part of the **Programming Advices - Algorithms & Problem Solving Level 2** roadmap.

**Author:** Eng. Abanoub Reda

---

## 📸 Overview & Features

- **Custom Question Count:** Choose as many questions as you wish to challenge yourself.
- **Multiple Difficulty Levels:**
  - 🟢 **Easy:** Numbers from 1 to 10
  - 🟡 **Medium:** Numbers from 10 to 50
  - 🔴 **Hard:** Numbers from 50 to 100
  - 🎲 **Mix:** Random level per question
- **Supported Math Operations:**
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
  - 🔀 **Mix:** Random operation per question
- **Immediate Visual & Audio Feedback:**
  - 🟢 **Green Screen:** Correct answer!
  - 🔴 **Red Screen + Audio Beep (`\a`):** Wrong answer! Shows the correct answer immediately.
- **End-of-Quiz Summary Card:**
  - Overall Status (`PASS` / `FAIL`)
  - Number of Questions
  - Question Level & Operation Type selected
  - Total Correct vs. Wrong Answers
- **Play Again Option:** Start a new quiz session directly from the console.

---

## 🚀 How to Run

### Prerequisites
Make sure you have a C++ compiler installed (such as GCC/MinGW, Clang, or MSVC).

### Compile and Execute (Terminal / Command Prompt)

```bash
# Compile using G++
g++ Math-Game.cpp -o MathGame.exe

# Run the game
./MathGame.exe
```

### Visual Studio / Code::Blocks / CLion
Open `Math-Game.cpp` in your preferred IDE, compile, and press `Ctrl + F5` to run.

---

## 📂 Project Structure

```
Math-Game/
├── Math-Game.cpp          # Main quiz source code
├── README.md              # Project documentation
└── .gitignore             # Git ignore rules for compiled binaries
```

---

## 📜 License
This project is open-source under the MIT license. Feel free to use and learn from it!
