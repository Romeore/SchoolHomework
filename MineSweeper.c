//MineSweeper.c

#include "MineSweeper.h"

//----------------------------------------------------------------------
//                          Convert Char To Digit
//                          ---------------------
//
// General      : This function converts char to digit. (0-9)
//
// Parameters   : 
//			symbol - the pointer of the symbol. (char*)
//
// Return Value : returns the digit in int value.
//
//----------------------------------------------------------------------

int convertCharToDigit(char* symbol)
{
	return (*symbol - '0');
}

//----------------------------------------------------------------------
//                          Convert Digit To Char
//                          ---------------------
//
// General      : This function converts digit to a char. (0-9)
//
// Parameters   : 
//			digit - the digit to convert to char. (Int)
//
// Return Value : returns the char that represents the digit.
//
//----------------------------------------------------------------------

char convertDigitToChar(int digit)
{
	return (digit + '0');
}

//----------------------------------------------------------------------
//                         Make Number From String
//                         -----------------------
//
// General      : This function makes a number from string.
//
// Parameters   : 
//			string - the pointer of the string. (char**)
//
// Return Value : returns the number value from the string.
//
//----------------------------------------------------------------------

int makeNumberFromString(char** string)
{
	int number = ZERO;

	while ((**string) != ' ' && (**string) != '\0')
	{
		number = number * TEN + convertCharToDigit(*string);
		(*string)++;
	}

	if (**string == ' ')
	{
		(*string)++;
	}

	return (number);
}

//----------------------------------------------------------------------
//                          Init Board Mines
//                          ----------------
//
// General      : This function initilaizes Mine Sweeper game.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initBoardMines(Mine board[][BOARDSIZE])
{
	int counter;
	int stopLoop = BOARDSIZE * BOARDSIZE;

	for (counter = ZERO; counter < stopLoop; counter++)
	{
		board[counter / BOARDSIZE][counter % BOARDSIZE].isActive = FALSE;
		board[counter / BOARDSIZE][counter % BOARDSIZE].symbol = '.';
	}

	return;
}

//----------------------------------------------------------------------
//                            Print Board
//                            -----------
//
// General      : This function prints the board.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printBoard(Mine board[][BOARDSIZE])
{
	int counter;
	int stopLoop = BOARDSIZE * BOARDSIZE;

	for (counter = ZERO; counter < stopLoop; counter++)
	{
		(board[counter / BOARDSIZE][counter % BOARDSIZE].isActive) ?
			printf("%c", board[counter / BOARDSIZE][counter % BOARDSIZE].symbol) :
			printf(".");
		(counter % BOARDSIZE == BOARDSIZE - 1) ? printf("\n") : printf(" ");
	}

	return;
}

//----------------------------------------------------------------------
//                           Put Mines Of Board
//                           ------------------
//
// General      : This function puts the mines on the board.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void putMinesOnBoard(Mine board[][BOARDSIZE])
{
	int row;
	int col;
	char inputString[BOARDSIZE * BOARDSIZE * FIVE];
	char* ptrInputString = &inputString;

	gets(inputString);

	while (*(ptrInputString) != '\0')
	{
		row = makeNumberFromString(&ptrInputString);
		col = makeNumberFromString(&ptrInputString);
		board[row - ONE][col - ONE].symbol = '#';
	}

	return;
}

//----------------------------------------------------------------------
//                           Num Of Mines
//                           ------------
//
// General      : This function calculates the number of mines around
//                a square.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//          row   - the row of the square. (Int)
//          col   - the column of the square. (Int)
//
// Return Value : returns the number of mines around a square.
//
//----------------------------------------------------------------------

int numOfMinesAroundSquare(Mine board[][BOARDSIZE], int row, int col)
{
	int counterMines = ZERO;
	int rowFinish;
	int colFinish;
	int colCounter;
	int colStart;
	int rowCounter;

	(row == ZERO) ? (rowCounter = ZERO) : (rowCounter = row - ONE);

	(col == ZERO) ? (colStart = ZERO) : (colStart = col - ONE);

	(col == BOARDSIZE) ? (colFinish = col + ONE) : (colFinish = col + TWO);

	(row == BOARDSIZE) ? (rowFinish = row + ONE) : (rowFinish = row + TWO);

	for (; rowCounter < rowFinish; rowCounter++) {
		for (colCounter = colStart; colCounter < colFinish; colCounter++) {
			if (board[rowCounter][colCounter].symbol == '#') {
				counterMines++;
			}
		}
	}

	return (counterMines);
}

//----------------------------------------------------------------------
//                           Discover Square
//                           ---------------
//
// General      : This function discoveres a square in Mine Sweeper.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//          row   - the row of the square. (Int)
//          col   - the column of the square. (Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void discoverSquare(Mine board[][BOARDSIZE], int row, int col)
{	
	numOfMinesAroundSquare(board, row, col);
	board[row][col].symbol = 
		convertDigitToChar(numOfMinesAroundSquare(board, row, col));
	board[row][col].isActive = TRUE;
	printBoard(board);
}

//----------------------------------------------------------------------
//                           Is Square Mine
//                           --------------
//
// General      : This function checks if a square is a mine.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//          row   - the row of the square. (Int)
//          col   - the column of the square. (Int)
//
// Return Value : returns TRUE if the square is a mine, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSquareMine(Mine board[][BOARDSIZE], int row, int col)
{
	return (board[row][col].symbol == '#');
}

//----------------------------------------------------------------------
//                           Start Num Of Mines
//                           ------------------
//
// General      : This function calculates the number of mines.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//
// Return Value : returns the number of mines in the Mine Sweeper game.
//
//----------------------------------------------------------------------

int startNumOfMines(Mine board[][BOARDSIZE])
{
	int counter;
	int stopLoop = BOARDSIZE * BOARDSIZE;
	int minesCounter = ZERO;

	for (counter = ZERO; counter < stopLoop; counter++)
	{
		if (board[counter / BOARDSIZE][counter % BOARDSIZE].symbol == '#')
		{
			minesCounter++;
		}
	}

	return (minesCounter);
}

//----------------------------------------------------------------------
//                           Is Square Guessed
//                           -----------------
//
// General      : This function checks if a square already guessed.
//
// Parameters   : 
//			board - the board of the game. (Mine)
//          row   - the row of the square. (Int)
//          col   - the column of the square. (Int)
//
// Return Value : returns TRUE if the square already guessed, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSquareGuessed(Mine board[][BOARDSIZE], int row, int col)
{
	return (board[row][col].isActive);
}

//-----------------------------------------------------------------------------
//                                   Mine Sweeper
//                                   ------------
//
// General : This program manages the Mine Sweeper game.
//
// Input   : Placement of mines, guesses of a player. 
//
// Process : Discover a square. if its a bomb, end the game, else continue.
//
// Output  : Messages reflected to the state that accours.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 27.12.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	Mine board[BOARDSIZE][BOARDSIZE];
	BOOLEAN hitMine = FALSE;
	int row;
	int col;
	int numOfTurnsTillVictory;

	// Code section

	// Start the game
	initBoardMines(board);
	// Get the miness placement
	printf("Please write the mines placement: \n");
	putMinesOnBoard(board);
	// Calculate the number of turns till victory (boardsize - number of mines)
	numOfTurnsTillVictory = BOARDSIZE * BOARDSIZE - startNumOfMines(board);

	// Play the game
	printf("\nPlease write the row\n");
	scanf("%d", &row);

	while (row != 999 && numOfTurnsTillVictory && !hitMine)
	{
		printf("Please write the column\n");
		scanf("%d", &col);
		// Check if guessed
		if (isSquareGuessed(board, row - ONE, col - ONE))
		{
			printf("You have already discovered it, guess again\n");
			printf("\nPlease write the row\n");
			scanf("%d", &row);
		}
		// If not guessed, check if the player didn't hit a mine
		else if (!isSquareMine(board, row - ONE, col - ONE))
		{
			discoverSquare(board, row - ONE, col - ONE);
			numOfTurnsTillVictory--;
			printf("Please write the row\n");
			scanf("%d", &row);
		}
		// Hitted a mine, game is over.
		else {
			printf("\nGame over, you hit a mine\n");
			hitMine = TRUE;
		}
	}
	
	// If the player guessed all places right.
	if (numOfTurnsTillVictory == ZERO)
	{
		printf("Congratulations! You won");
	}

	// If the player ended the game too early.
	if (row == 999)
	{
		printf("\nYou ended this game too early, good luck next time !\n");
	}

	// Finish game
	printf("\nThank you for playing !\n");
}
