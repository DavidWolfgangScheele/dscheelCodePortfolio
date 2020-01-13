/*David Scheele
Lab Project In Computer Science
Shell Pre-created but the code itself is my own
To Compile: gcc ticTacProg.c
To run: ./a.out

ticTacShell.c

Shell of the game 'TicTacToe' for CpSc 101
wdg 2005

Modified by Andy Dalton, 7/26/2007*/

#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()


// Size of the board (square)
const int  BOARD_SIZE     = 3;

// Symbols used for the board
const char BLANK_SYMBOL   = ' ';
const char COMP_SYMBOL    = 'O';
const char HUMAN_SYMBOL   = 'X';

// Human goes first
const int  HUMANS_TURN    = 0;
const int  COMPUTERS_TURN = 1;


// Function prototypes
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]);
int  hasWon(char board[BOARD_SIZE][BOARD_SIZE], char mark);
int  hasWonHorizontal(char board[BOARD_SIZE][BOARD_SIZE], char mark);
int  hasWonVertical(char board[BOARD_SIZE][BOARD_SIZE], char mark);
int  hasWonDiagonal(char board[BOARD_SIZE][BOARD_SIZE], char mark);
void getComputerMove(char board[BOARD_SIZE][BOARD_SIZE]);
void getHumanMove(char board[BOARD_SIZE][BOARD_SIZE]);
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]);
void clearScreen(void);


//
// The main function should not be changed
//
int main(void) {
    char board[BOARD_SIZE][BOARD_SIZE];
    int  humanWon    = 0; // boolean (0/1)
    int  computerWon = 0; // boolean (0/1)
    int  move        = 0;

    // Seed the random number generator
    srand(time(0));

    initializeBoard(board);

    while ((move < (BOARD_SIZE * BOARD_SIZE)) && !humanWon && !computerWon) {
        clearScreen();

        if ((move % 2) == COMPUTERS_TURN) {
            getComputerMove(board);
        } else {
            printBoard(board);
            getHumanMove(board);
        }

        computerWon = hasWon(board, COMP_SYMBOL);
        humanWon    = hasWon(board, HUMAN_SYMBOL);
        move++;
    }

    clearScreen();
    printBoard(board);

    if (humanWon) {
        printf(">>>> You won!\n");
    } else if (computerWon) {
        printf("<<<< I won!\n");
    } else { // move >= BOARD_SIZE * BOARD_SIZE
        printf("==== A Draw\n");  
    }

    return 0;
}


//
// Initialized the board to all BLANK_SYMBOL
//
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row;

    for (row = 0; row < BOARD_SIZE; row++) {
        int col;

        for (col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = BLANK_SYMBOL;
        }
    }
}


//
// Determines if the 'mark' completely fills a row, column, or diagonal
// returns 1 if yes, 0 if no
//
int hasWon(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    return    hasWonHorizontal(board, mark)
           || hasWonVertical(board, mark)
           || hasWonDiagonal(board, mark);
}


//
// Determines if the 'mark' completely fills a row
// returns 1 if yes, 0 if no
//
int hasWonHorizontal(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    int won = 0; // boolean (0/1).  Assume lost until proven true
    int row;

    for (row = 0; row < BOARD_SIZE && !won; row++) {
        int match = 1; // boolean (0/1)
        int col;

        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != mark) {
                match = 0;
            }
        }

        won = match;
    }

    return won;
}


//
// Determines if the 'mark' completely fills a column
// returns 1 if yes, 0 if no
//
int hasWonVertical(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    /* INSERT CODE HERE */
	int won = 0; // boolean (0/1).  Assume lost until proven true
    int col;

    for (col = 0; col < BOARD_SIZE && !won; col++) {
        int match = 1; // boolean (0/1)
        int row;

        for (row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] != mark) {
                match = 0;
            }
        }

        won = match;
    }

    return won;
    return 0; // Stub -- make this return the correct value
}


//
// Determines if the 'mark' completely fills a diagonal
// returns 1 if yes, 0 if no
//
int hasWonDiagonal(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    /* INSERT CODE HERE */
	int match1 = 1, match2 = 1;
	int won = 0; // boolean (0/1).  Assume lost until proven true
    int col;
	int row;
    for (row = 0; row < BOARD_SIZE; row++) {
		col = row;
        if (board[row][col] != mark) {
            match1 = 0;
        }
    }
	for (row = 0; row < BOARD_SIZE; row++) {
		col = BOARD_SIZE - 1 - row;
        if (board[row][col] != mark) {
            match2 = 0;
        }
    }
	if(match1 == 1 || match2 == 1)
	{
		won = 1;
	}
    return won;
    // Stub -- make this return the correct value
}


//
// Gets computer move by randomly picking an unoccupied cell
//
void getComputerMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row;
    int col;

    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != BLANK_SYMBOL);

    board[row][col] = COMP_SYMBOL;
}


//
// Gets human move by prompting user for row and column numbers
//
void getHumanMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    /* INSERT CODE HERE */
	int row;
	int col;
	do
	{
		printf("Please enter row number: ");
		scanf("%i", &row);
		printf("Please enter column number: ");
		scanf("%i", &col);
		printf("\n");
	} while (board[row][col] != BLANK_SYMBOL);
	board[row][col] = HUMAN_SYMBOL;
}


//
// Prints the board to the screen.  Example:
//
//       0   1   2
//     +---+---+---+
//   0 | X |   |   |
//     +---+---+---+
//   1 |   | O | O |
//     +---+---+---+
//   2 |   |   | X |
//     +---+---+---+
//
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    /* INSERT CODE HERE */
	int i, x, y;
	x = 0;
	printf("     %d   %d   %d  \n", x, x + 1, x + 2);
	printf(" ");
	printf("  +---+---+---");
	//nested for loop to make columns and rows
	for(y = 0; y < BOARD_SIZE; y++)
	{
		printf("+\n");
		printf(" %d", y);
		printf(" ");
		for(x = 0; x < BOARD_SIZE; x++)
		{
			printf("| %c ", board[y][x]);
		}
		printf("|");
		printf("\n");
		printf("   ");
		for(x = 0; x < BOARD_SIZE; x++)
		{
			printf("+---");
		}
	}
	printf("+\n");
}



//
// Clears the screen -- uses ANSI terminal control codes
//
void clearScreen(void) {
    const char ESC = 27;

    printf("%c[2J%c[H", ESC, ESC);
}
