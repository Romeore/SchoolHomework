#pragma once

#include "AlonMatrizas.h"

int sumColumnInMatriza(short mat[][DIM], unsigned short column)
{
	int sum = ZERO;
	unsigned short row;

	for (row = ZERO; row < DIM; row++)
	{
		sum += mat[row][column];
	}
	return (sum);
}

int sumRowInMatriza(short mat[][DIM], unsigned short row)
{
	int sum = ZERO;
	unsigned short column;

	for (column = ZERO; column < DIM; column++)
	{
		sum += mat[row][column];
	}
	return (sum);
}

void printMat(short mat[][DIM])
{
	unsigned short matLength = DIM * DIM;
	unsigned short lastColumn = DIM - ONE;
	unsigned short counter;
	unsigned short column;

	for (counter = ZERO; counter < matLength; counter++)
	{
		column = counter % DIM;
		printf("%c ", mat[counter / DIM][column]);
		if (column == lastColumn)
			printf("\n");
	}
}


BOOLEAN isTwoNumbersSameInRow(short mat[][DIM], unsigned short row)
{
	BOOLEAN        isTwoNumbersSameInRow = FALSE;
	unsigned short counter = ZERO;
	unsigned short counterArray[TEN] = { ZERO };
	unsigned short column = ZERO;

	for (column; column < DIM; column++)
	{
		counterArray[mat[row][column]]++;
	}
	for (counter; counter < TEN; counter++)
	{
		(counterArray[counter] == TWO) ? isTwoNumbersSameInRow = TRUE : isTwoNumbersSameInRow;
	}
	return (isTwoNumbersSameInRow);
}

BOOLEAN isTwoNumbersSameInColumn(short mat[][DIM], unsigned short column)
{
	BOOLEAN        isTwoNumbersSameInColumn = FALSE;
	unsigned short counter = ZERO;
	unsigned short counterArray[TEN] = { ZERO };
	unsigned short row = ZERO;

	for (row; row < DIM; row++)
	{
		counterArray[mat[row][column]]++;
	}

	for (counter; counter < TEN; counter++)
	{
		(counterArray[counter] == TWO) ? isTwoNumbersSameInColumn = TRUE : isTwoNumbersSameInColumn;
	}
	return (isTwoNumbersSameInColumn);
}

BOOLEAN isSymbolInRow(short mat[][DIM], short row, char symbol)
{
	BOOLEAN        isSymbolInRow = FALSE;
	unsigned short counter = ZERO;
	unsigned short column = ZERO;

	for (column; column < DIM; column++)
	{
		mat[row][column] == symbol ? isSymbolInRow = TRUE : isSymbolInRow;
	}

	return (isSymbolInRow);
}

short sumSymbolInColumn(char mat[][DIM], short column, char symbol)
{
	unsigned short numOfSymbols = ZERO;
	unsigned short row = ZERO;

	for (row; row < DIM; row++)
	{
		mat[row][column] == symbol ? numOfSymbols++ : numOfSymbols;
	}

	return (numOfSymbols);
}


short sumSymbolInRow(char mat[][DIM], short row, char symbol)
{
	unsigned short numOfSymbols = ZERO;
	unsigned short column = ZERO;

	for (column; column < DIM; column++)
	{
		(mat[row][column] == symbol) ? numOfSymbols++ : numOfSymbols;
	}
	return (numOfSymbols);
}

short sumSymbolInMainCross(char mat[DIM][DIM], char symbol)
{
	unsigned short numOfSymbols = ZERO;
	unsigned short dimCounter = ZERO;

	for (dimCounter; dimCounter < DIM; dimCounter++)
	{
		(mat[dimCounter][dimCounter] == symbol) ? numOfSymbols++ : numOfSymbols;
	}
	return (numOfSymbols);
}

short sumSymbolInSecondCross(char mat[DIM][DIM], char symbol)
{
	unsigned short numOfSymbols = ZERO;
	unsigned short dimCounter = ZERO;

	for (dimCounter; dimCounter < DIM; dimCounter++)
	{
		(mat[dimCounter][DIM - ONE - dimCounter] == symbol) ? numOfSymbols++ : numOfSymbols;
	}
	return (numOfSymbols);
}

BOOLEAN isSymbolInColumn(short mat[][DIM], short column, char symbol)
{
	BOOLEAN        isSymbolInColumn = FALSE;
	unsigned short counter = ZERO;
	unsigned short row = ZERO;

	for (row; row < DIM; row++)
	{
		mat[row][column] == symbol ? isSymbolInColumn = TRUE : isSymbolInColumn;
	}

	return (isSymbolInColumn);
}

BOOLEAN isSymbolInCross(short mat[DIM][DIM], char symbol)
{
	BOOLEAN        isSymbolInCross = FALSE;
	unsigned short dimCounter = ZERO;

	for (dimCounter; dimCounter < DIM; dimCounter++)
	{
		mat[dimCounter][dimCounter] == symbol ? isSymbolInCross = TRUE : isSymbolInCross;
	}

	return (isSymbolInCross);
}