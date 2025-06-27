# ♟️ Chess Game with Bot (C Project)

This project is a simple **chess game coded in C**, developed as one of my first programming assignments during the first year of my undergraduate studies in Industrial Engineering.

The program features both **single-player (vs computer)** and **two-player** modes with basic logic for scoring and choosing the best move in bot mode.

## 🧠 Project Objective

To develop a working chess game with:
- A basic **bot opponent** that calculates scores for possible moves
- Support for **multiplayer mode**
- A **simple front-end interaction** with click and keyboard-based movement

## 🤖 Bot Logic

In single-player mode, the program evaluates:
- Piece safety and exposure
- Move consequences
- Basic prioritization rules (e.g., protect valuable pieces, capture threats)

It assigns a score to each possible move and selects the best-scoring move to play against the user.

## 🎮 How to Play

- Right-click a piece to select it, then press Enter.
- Select the destination square and press Enter again.
- To cancel a move selection, double-press Enter and try again.
- Choose between **single-player (bot)** or **two-player mode** at launch.

## 💻 Tech Stack

- Language: **C**
- Interface: **Basic GUI or CLI input**
- Environment: Written and run on early academic development tools

## 📂 Files

- `chess_game.cpp` – main program
- `README.md` – project description
- `Chess.exe` - exe file of the program

> Note: This was an early-stage project intended for learning logic structuring, game state handling, and working with basic user input systems.

---

