
# Sudoku-Game
This repository contains a simple C++ implementation of a Sudoku game, allowing users to fill numbers in a 9×9 grid...
Sudoku Game in C++ 
A simple console-based Sudoku game developed using basic C++ concepts. 
--- 
Team Members & Roles:<br>
Khizer Hayyat-Logic Designer + Coder<br> 
Mudassir Azam- Git Manager + Documentation<br>
M Rayyan Bilal-Tester + Logic Designer<br>
--- 
Overview
This project is a 9×9 Sudoku game designed for beginners learning C++ programming. 
It demonstrates: 
- 2D array handling 
- simple logic checks 
- user interaction through menus 
- scoring system 
- input validation 
- hint and auto-solve features 
--- 
Design & Logic
 1. Grid Representation 
- `board[9][9]` stores the current game state 
- `solutionBoard[9][9]` stores the complete correct Sudoku answer 
- Empty cells are stored as 0 , printed as dots (`.`) 
 2. Main Functions 
`displayBoard()` | Shows the Sudoku grid with lines and formatting 
`isValidMove(r, c, num)` | Checks row, column, and 3×3 block 
`isBoardComplete()` | Returns true if no empty cells (0s) 
`giveHint()` | Fills one empty cell from the solution 
`autoSolve()` | Copies complete solution into the board 
`main()` | Menu, scoring, gameplay loop 
 3. Hint Logic 
The program finds the first empty cell (0) and replaces it with the correct answer from `solutionBoard`. 
Each hint reduces score by 10 points . 
 4. Auto-Solve Logic 
Copies all values from `solutionBoard` into `board`, reducing score by 20 points . 
--- 
 Execution Instructions 
 1. How to Compile 
Use any C++ compiler (g++, MinGW, Dev-C++, Visual Studio Code, etc.): 
 2. Sample Use 
- Choose 1 to enter a number 
- Choose 2 to get a hint 
- Choose 3 to auto-solve 
- Choose 4 to check whether the Sudoku is complete 
- Choose 5 to exit 
Example input: 
Enter row (1-9): 3 
Enter column (1-9): 4 
Enter number (1-9): 6 
--- 
 
AI Tool Reflection
AI assistance (ChatGPT) was used for: 
- Proofreading code 
- Improving formatting 
--- 
 
Future Enhancements
- Add timer, leaderboard, save/load game 
- Add difficulty levels (Easy / Medium / Hard) 
- Add random puzzle generator 
- Add sound effects and colored grid

