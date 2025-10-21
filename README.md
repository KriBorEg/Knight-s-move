Knight's Move Program

This is a small C program that simulates the movement of a knight on a chessboard.
The knight tries to move around an 8x8 board without landing on the same square twice.

Each move follows the L-shaped pattern that a knight makes in chess.
The program randomly chooses valid moves until the knight gets stuck and can’t move anymore.

How t works:
1. When you start the program, you’ll be asked if you want to begin.
2. If you say Y, you choose a starting position (like E4).
3. The knight starts there and begins jumping around the board.
4. You’ll see the board update after every move with a short delay.
5. The knight stops when there are no more possible moves left.
6. Then, you can choose to play again or exit.

How it is made:
The program uses a 2D array (board[8][8]) to represent the chessboard.
Each move number is stored in the board, starting from 1 at the knight’s starting square.
It uses random numbers (rand()) to pick which valid move the knight makes next.
It uses Sleep() to create a short animation effect between moves.
\033[2J\033[H is used to clear and refresh the screen (works in most terminals).
