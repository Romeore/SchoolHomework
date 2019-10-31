//TicTacToe.c
#pragma once

#include "AlonMatrizas.h"

void main(void)
{
	char           ticTacToeMat[DIM][DIM] = { 'A', 'A','A', 'A','A','A','A','A','A' };
	unsigned short matCounter[TEN] = { ZERO };
	BOOLEAN        isSymbol = FALSE;
	BOOLEAN        isWin = FALSE;
	unsigned short dimCounter = ZERO;
	unsigned short turn = ZERO;
	unsigned short column = 0;
	unsigned short row = 0;
	char           symbol;
	char           neededSymbol;

	printMat(ticTacToeMat);
	
	printf("\n");
	while (!isWin && turn != NINE)
	{
		printf("Player %hu write the place and symbol\n", turn % TWO + ONE);
		scanf(" %hu%hu %c", &row, &column, &symbol);

		neededSymbol = (turn % TWO == ZERO) ? 'X' : 'O';
		if (ticTacToeMat[row][column] == 'A' && neededSymbol == symbol)
		{
			ticTacToeMat[row][column] = symbol;
			(sumSymbolInColumn(ticTacToeMat, column, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInRow(ticTacToeMat, row, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInMainCross(ticTacToeMat, symbol) == DIM) ? isWin = TRUE : isWin;
			(sumSymbolInSecondCross(ticTacToeMat, symbol) == DIM) ? isWin = TRUE : isWin;
			printf("\n");
			printMat(ticTacToeMat);
			printf("\n");
			turn++;
		}
	}

	(turn == DIM * DIM) ? printf("Draw") : printf("Player %hu won", turn % TWO + ONE);
	scanf("%hu", &dimCounter);
}