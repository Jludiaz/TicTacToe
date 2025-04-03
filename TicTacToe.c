#include <stdio.h>
#define SIZE 3

void printWelcome();
void drawBoard(char[][]);
void EvaluateBoard();
char[][] getUserInput(char board[][SIZE], char player);

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

char EvaluateBoard(char board[][]) {
    // Check rows and columns for a win
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return board[i][0]; // Return the winning player ('X' or 'O')
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return board[1][1]; // Return the winning player ('X' or 'O')
    }

    // Check for draw
    int draw = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                draw = 0;
                break;
            }
        }
    }
    if (draw) {
        return 'D'; // Return 'D' for draw
    }
}

char[][] getUserInput(char[][] board, char player) {
    int cell;
    //check for moves
    if (player == 'X') { 
        printf("Player %c - Which square? [1-9] or 0 to quit: ", player);
        scanf("%d", &cell);
    }else if (player == 'O') {
        printf("Player %c - Which square? [1-9] or 0 to quit: ", player);
        scanf("%d", &cell);
    }else {
        printf("Invalid player. Exiting.\n");
        return board; // Return the current board state
    }

    // Check if the user wants to quit
    if (cell == 0) {
        printf("Exiting the game. Goodbye!\n");
        return board; // Exit the game without modifying the board
    }

    // Convert cell number to row and column
    int row = (cell - 1) / SIZE;
    int col = (cell - 1) % SIZE;

    // Check for valid input
    if (cell < 1 || cell > 9 || board[row][col] != ' ') {
        printf("Invalid input. Try again.\n");
        return getUserInput(board, player); // Recursive call for valid input
    }

    // Update the board with the player's move
    board[row][col] = player;
    return board;
}


int main() {
    // Input: 'X - [1-9]' OR 'O - [1-9]'
    // Output: "X wins!"
    //         "O wins!"
    //         "Draw!"
    // Step 1: Print welcome message
    // Step 2: Draw Board
    // Step 3: Evaluate Board 
    // Step 4: Check if game is over
    //     Step A: Jump to Step 12
    // Step 5: Get valid input
    // Step 6: Check if user wants to quit
    // Step 7: If user wants to quit
    //     Step A: Jump to 13
    // Step 8: Update Board
    // Step 9: Draw Board
    // Step 10: Evaluate Board
    // Step 11: Jump to Step 4

    // Step 12: Print Outcome 
    // Step 13: Print goodbye message
    // Step 14: Exit (Halt)


    printWelcome();

    char board[SIZE][SIZE];
    char winner = ' '; // Initialize winner to empty

    while(winner!=' '){
        drawBoard(board);
        getUserInput(board, 'X'); // Player X's turn
        EvaluateBoard(board, winner);
    }







}

// Function to display the game board
// void showBoard(char board[][])
// {
//     printf("\n\n");
//     printf("\t\t\t %c | %c | %c \n", board[0][0],
//            board[0][1], board[0][2]);
//     printf("\t\t\t--------------\n");
//     printf("\t\t\t %c | %c | %c \n", board[1][0],
//            board[1][1], board[1][2]);
//     printf("\t\t\t--------------\n");
//     printf("\t\t\t %c | %c | %c \n\n", board[2][0],
//            board[2][1], board[2][2]);
// }

// Function to show the instructions
// void printWelcome()
// {
//     printf("\t\t\t  Welcome to TicTacToe\n\n");
//     printf("\t\t\t Tic-Tac-Toe\n\n");
//     printf("Choose a cell numbered from 1 to 9 as below "
//            "and play\n\n");

//     printf("\t\t\t 1 | 2 | 3 \n");
//     printf("\t\t\t--------------\n");
//     printf("\t\t\t 4 | 5 | 6 \n");
//     printf("\t\t\t--------------\n");
//     printf("\t\t\t 7 | 8 | 9 \n\n");

//     printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
// }

// void ExaluateBoard(){
    
// }