#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>


#define SIZE 8

// Possible knight moves
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

// Prints the numbers and letters of the board 
void printBoard(int board[SIZE][SIZE]);

int main() {
    int board[SIZE][SIZE] = {0};
    char startCol = '\0';
    int startRow = 0;
    char choice = '\0';

    srand(time(NULL));

    printf("Welcome to Knight's Move Program!\n");
    printf("Let's see if the knight can move around the whole board without touching a square twice.\n");

    do {    
        // Displays the possible positions on the board
        for(int i = 0; i < SIZE; i++) // rows
            for(int j = 0; j < SIZE; j++) // columns
                board[i][j] = 0;
        
        // Option for playing
        printf("\nWould you like to begin? (Y/N): ");
        scanf(" %c", &choice);
        if (toupper(choice) == 'N') {
            break;
        }


        // Choose starting position
        printf("Choose starting position (e.g., E4): ");
        scanf(" %c%d", &startCol, &startRow);
        int x = startRow - 1;
        int y = startCol - 'A';
        if (y < 0 || y >= SIZE || x < 0 || x >= SIZE) {
            printf("Invalid start position.\n");
            continue;
        }

        int moveCount = 1;
        board[x][y] = moveCount;

        // Clear screen before animation to avoid several board displays
        printf("\033[2J\033[H"); 
        // \033 escape character & [2J clears the entire screen 
        // [H moves the writing position back to start
        printBoard(board);

        int stuck = 0;

        // Keep moving while possible
        while (!stuck) {
            int possibleMoves[8][2];
            int numMoves = 0;

            // Find all valid moves
            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < SIZE && newY >= 0 && 
                    newY < SIZE && board[newX][newY] == 0) {
                    possibleMoves[numMoves][0] = newX;
                    possibleMoves[numMoves][1] = newY;
                    numMoves++;
                }
            }

            if (numMoves == 0) {
                printf("\nThe knight could not make another move.\n");
                stuck = 1;
                break;
            }

            // Choose a random valid move
            int randomMove = rand() % numMoves;
            x = possibleMoves[randomMove][0];
            y = possibleMoves[randomMove][1];

            moveCount++;
            board[x][y] = moveCount;

            // Move cursor to top and redraw board (no new lines)
            printf("\033[H");
            printBoard(board);
            printf("\nMove count: %d\n", moveCount);

            Sleep(100); // 1000 ms delay between moves
        }

        printf("\nWould you like to try again? (Y/N): ");
        scanf(" %c", &choice);

    } while (toupper(choice) == 'Y');
    
    printf("\nThanks for playing!\n");
    return 0;

}

void printBoard(int board[SIZE][SIZE]) {
    printf("   A  B  C  D  E  F  G  H\n");
    printf("  --------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d| ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%02d ", board[i][j]);
        }
        printf("\n");
    }
}