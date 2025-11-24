#include <iostream>
using namespace std;

// Sudoku board (0 means empty)
int board[9][9] = {
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};

// Completed correct solution (used for hints and auto-correct)
int solutionBoard[9][9] = {
    {5,3,4, 6,7,8, 9,1,2},
    {6,7,2, 1,9,5, 3,4,8},
    {1,9,8, 3,4,2, 5,6,7},

    {8,5,9, 7,6,1, 4,2,3},
    {4,2,6, 8,5,3, 7,9,1},
    {7,1,3, 9,2,4, 8,5,6},

    {9,6,1, 5,3,7, 2,8,4},
    {2,8,7, 4,1,9, 6,3,5},
    {3,4,5, 2,8,6, 1,7,9}
};

int score = 100;

// Show the board
void displayBoard();

// Check if a number can be placed
bool isValidMove(int r, int c, int num);

// Check if board is fully solved
bool isBoardComplete();

// Give a hint (copy one cell from solution)
void giveHint();

// Auto-correct full solution
void autoSolve() ;

int main() {
    int choice;
    int row, col, num;

    cout << "WELCOME TO SUDOKU GAME\n";

    while (true) {
        displayBoard();

        cout << "\nMENU\n";
        cout << "1. Enter a number\n";
        cout << "2. Get a hint\n";
        cout << "3. Auto-correct solution\n";
        cout << "4. Check if board is complete\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice, try again.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter row (1-9): ";
            cin >> row;
            cout << "Enter column (1-9): ";
            cin >> col;
            cout << "Enter number (1-9): ";
            cin >> num;

            row--;
            col--;

            if (row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9) {
                cout << "Invalid input.\n";
                continue;
            }

            if (isValidMove(row, col, num)) {
                board[row][col] = num;
                score += 10;
                cout << "Correct move!\n";
            }
            else {
                score -= 5;
                cout << "Invalid move!\n";
            }
        }

        else if (choice == 2) {
            giveHint();
        }

        else if (choice == 3) {
            autoSolve();
        }

        else if (choice == 4) {
            if (isBoardComplete()) {
                cout << "\nCongratulations! You solved the Sudoku.\n";
                cout << "Final Score: " << score << endl;
                break;
            }
            else {
                cout << "Board is not complete yet.\n";
            }
        }

        else if (choice == 5) {
            cout << "Thank you for playing.\n";
            break;
        }
    }
    return 0;
}
void displayBoard() {
    cout << "\nSUDOKU BOARD\n";

    for (int r = 0; r < 9; r++) {

        // horizontal separator after every 3 rows
        if (r % 3 == 0) {
            cout << "+-------+-------+-------+\n";
        }

        for (int c = 0; c < 9; c++) {

            // vertical separator after every 3 columns
            if (c % 3 == 0) {
                cout << "| ";
            }

            if (board[r][c] == 0)
                cout << ". ";       // show empty as dot (clean look)
            else
                cout << board[r][c] << " ";
        }
        cout << "|\n";
    }

    cout << "+-------+-------+-------+\n";
}
bool isValidMove(int r, int c, int num) {

    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][c] == num) {
            return false;
        }
    }

    // Check subgrid
    int startRow = r - (r % 3);
    int startCol = c - (c % 3);

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}
bool isBoardComplete() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}
void giveHint() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 0) {
                board[r][c] = solutionBoard[r][c];
                cout << "\nHint given at (" << r + 1 << ", " << c + 1 << ")\n";
                score -= 10;
                return;
            }
        }
    }
    cout << "No empty cells left for hint.\n";
}
void autoSolve() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            board[r][c] = solutionBoard[r][c];
        }
    }
    cout << "\nThe full correct solution is filled.\n";
    score -= 20;
}