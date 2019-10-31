//TicTacToe.c
#pragma once

#include "AlonMatrizas.h"

//-----------------------------------------------------------------------------
//                                 Tic Tac Toe
//                                 ------------
//
// General : This program process the game tic tac toe.
//
// Input   : three chars of 'X', and three chars of 'O'
//
// Process : Checks if the game is ended after a row, column or cross is
//           full.
//
// Output  : Prints if a player managed to win or draw.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 30.10.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	char           ticTacToeMat[DIM][DIM] = { 'A', 'A','A', 'A','A','A','A','A','A' };
	char           symbol;
	char           neededSymbol;
	BOOLEAN        isSymbol = FALSE;
	BOOLEAN        isWin = FALSE;
	unsigned short matCounter[TEN] = { ZERO };
	unsigned short dimCounter = ZERO;
	unsigned short turn = ZERO;
	unsigned short column = ZERO;
	unsigned short row = ZERO;
	unsigned short drawTurn = DIM * DIM;

	// Code section

	printMat(ticTacToeMat);
	printf("\n");

	// Check each time that the game is not over.
	while (!isWin && turn != drawTurn)
	{
		// Gets the players symbol.
		printf("Player %hu write the place and symbol\n", turn % TWO + ONE);
		scanf(" %hu%hu %c", &row, &column, &symbol);

		// Check what input do the program needs to get.
		neededSymbol = (turn % TWO == ZERO) ? 'X' : 'O';
		// Check if the place is empty and the input is correct.
		if (ticTacToeMat[row][column] == 'A' && neededSymbol == symbol)
		{
			ticTacToeMat[row][column] = symbol;
			// Check if after the player putted the symbol, the game is over.
			(sumSymbolInColumn(ticTacToeMat, column, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInRow(ticTacToeMat, row, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInMainCross(ticTacToeMat, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInSecondCross(ticTacToeMat, symbol) == DIM) ? isWin = TRUE : isWin;
			// Print the Tic Tac Toe game again.
			printf("\n");
			printMat(ticTacToeMat);
			printf("\n");
			// Add another turn to the game.
			turn++;
		}
	}
	// Print if the game is won or drawn.
	(turn == drawTurn) ? printf("Draw") : printf("Player %hu won", turn % TWO + ONE);
}