#include <stdio.h>
#include <stdlib.h> //For Exit function
#define SIZE 3

void printWelcome();
void drawBoard(char board[][SIZE]);
char EvaluateBoard(char board[][SIZE]);
void getUserInput(char board[][SIZE], char player);

void printWelcome()
{
    printf("\n\nWelcome to TicTacToe\n\n");
    printf("Choose a cell numbered from 1 to 9\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void drawBoard(char board[][SIZE]){
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0],
           board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0],
           board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n\n", board[2][0],
           board[2][1], board[2][2]);
}

char EvaluateBoard(char board[][SIZE]) {
    // Check rows and columns for a win
    for (int i = 0; i < SIZE; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0]; // Return 'X' or 'O'
        }

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i]; // Return 'X' or 'O'
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return board[1][1]; // Return 'X' or 'O'
    }

    // Check for draw (only if no empty spaces remain)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return ' '; // The game is still ongoing
            }
        }
    }

    return 'D'; // If no empty cells and no winner, it's a draw
}

void getUserInput(char board[][SIZE], char player) {
    int cell;
    
    while (1) { // Keep asking until valid input
        printf("Player %c - Which square? [1-9] or 0 to quit: ", player);
        if (scanf("%d", &cell) != 1) { //THIS IS TO AVOID INFINE LOOPS
            // Invalid input
            while (getchar() != '\n'){  // discard input until newline
                printf("Invalid input. Try again.\n");
                continue;
            }
        }
        //If user quits the game
        if (cell == 0) {
            printf("Exiting the game. Goodbye!\n");
            exit(0);
        }
        
        // Check if the input is within the valid range
        if (cell >= 1 && cell <= 9) {
            int row = (cell - 1) / SIZE;
            int col = (cell - 1) % SIZE;

            if (board[row][col] == ' ') {
                board[row][col] = player;
                return;
            }else {
                printf("Cell %d is already occupied. Try another cell.\n", cell);
            }
        }else{
            printf("Invalid cell number. Try again.\n");
        }
    }
}
   
int main() {

    printWelcome();//print the welcome message

    //initialize the game board
    char board[SIZE][SIZE] = {  {' ', ' ', ' '}, 
                                {' ', ' ', ' '}, 
                                {' ', ' ', ' '} };
    char winner = ' '; // Initialize winner to empty
    int moveCounter = 0;

    //main game loop
    while (winner == ' ') {
        drawBoard(board);

        if (moveCounter % 2 == 0)
            getUserInput(board, 'X'); // Player X's turn
        else
            getUserInput(board, 'O'); // Player O's turn

        moveCounter++;
        winner = EvaluateBoard(board);
    }

    // Game over, show final board and result
    drawBoard(board); 

    //Decide if its a tie or a win
    if (winner == 'D')
        printf("Cat Game\n");
    else
        printf("Player %c wins!\n", winner);

    return 0;
}