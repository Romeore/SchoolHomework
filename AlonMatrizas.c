//AlonMatrizas.c
#pragma once

#include "AlonMatrizas.h"

//----------------------------------------------------------------------
//                            Sum Column In Matriza
//                            ---------------------
//
// General      : This function sums an column in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			column    - A column (In)					
//
// Return Value : The sum of a specific column in the matrix. 
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                            Sum Row In Matriza
//                            ---------------------
//
// General      : This function sums an row in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			column    - The number of the column (In)					
//
// Return Value : The sum of a specific row in the matrix. 
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Sum Main Cross In Matriza
//                          -------------------------
//
// General      : This function sums a main cross in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//
// Return Value : The sum of main cross in the matrix. 
//
//----------------------------------------------------------------------

int sumMainCrossInMatriza(short mat[][DIM])
{
	int sum = ZERO;
	unsigned short dimCounter;

	for (dimCounter = ZERO; dimCounter < DIM; dimCounter++)
	{
		sum += mat[dimCounter][dimCounter];
	}

	return (sum);
}

//----------------------------------------------------------------------
//                          Sum Second Cross In Matriza
//                          ---------------------------
//
// General      : This function sums a second cross in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//
// Return Value : The sum of second cross in the matrix. 
//
//----------------------------------------------------------------------

int sumSecondCrossInMatriza(short mat[][DIM])
{
	int sum = ZERO;
	unsigned short lastColumn = DIM - ONE;
	unsigned short dimCounter;

	for (dimCounter = ZERO; dimCounter < DIM; dimCounter++)
	{
		sum += mat[dimCounter][lastColumn - dimCounter];
	}

	return (sum);
}

//----------------------------------------------------------------------
//                          Sum Second Cross In Matriza
//                          ---------------------------
//
// General      : This function sums a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//
// Return Value : The sum of the matrix. 
//
//----------------------------------------------------------------------

int sumSecondCrossInMatriza(short mat[][DIM])
{
	int sum = ZERO;
	unsigned short matrizaSize = DIM * DIM;
	unsigned short dimCounter;
	unsigned short counter;

	for (counter = ZERO; counter < matrizaSize; counter++)
	{
		sum += mat[counter / SEVEN][counter % SEVEN];
	}

	return (sum);
}

//----------------------------------------------------------------------
//                          Print Mat Nums
//                          --------------
//
// General      : This function prints a numbers matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printMatNums(short mat[][DIM])
{
	unsigned short matLength = DIM * DIM;
	unsigned short lastColumn = DIM - ONE;
	unsigned short counter;
	unsigned short column;

	for (counter = ZERO; counter < matLength; counter++)
	{
		column = counter % DIM;
		printf("%hd ", mat[counter / DIM][column]);
		if (column == lastColumn)
			printf("\n");
	}
}

//----------------------------------------------------------------------
//                          Print Mat Chars
//                          --------------
//
// General      : This function prints a Chars matrix.
//
// Parameters   : 
//			mat	      - A matrix (Char)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printMatChars(char mat[][DIM])
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

//----------------------------------------------------------------------
//                          Is Two Numbers Same In Row
//                          ---------------------------
//
// General      : This function checks if there is two same numbers
//                in a row in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			row       - The num of the row (In)					
//          
// Return Value : Returns true if there is two same numbers, FALSE if
//                not.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Is Two Numbers Same In Column
//                          -----------------------------
//
// General      : This function checks if there is two same numbers
//                in a column in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			column    - The num of the column (In)					
//          
// Return Value : Returns true if there is two same numbers, FALSE if
//                not.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Is Symbol In Row
//                          ----------------
//
// General      : This function checks if there is a a symbol
//                in a row in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			row       - The num of the row (In)	
//          symbol    - The symbol (Char)
//          
// Return Value : Returns TRUE if the symbol is there, FALSE if not.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Is Symbol In Column
//                          -------------------
//
// General      : This function checks if there is a symbol
//                in a column in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			column    - The num of the column (In)	
//          symbol    - The symbol (Char)
//          
// Return Value : Returns TRUE if the symbol is there, FALSE if not.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Is Symbol In Cross
//                          -------------------
//
// General      : This function checks if there is a symbol
//                in a cross in a matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//          symbol    - The symbol (Char)
//          
// Return Value : Returns TRUE if the symbol is there, FALSE if not.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Sum Symbol In Column
//                          --------------------
//
// General      : This function counts the number of specific symbol
//                in a column
//
// Parameters   : 
//			mat	      - A matrix (In)
//			column    - The num of the column (In)	
//          symbol    - The symbol (Char)
//          
// Return Value : The number of times that the symbol is in the column.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Sum Symbol In Row
//                          --------------------
//
// General      : This function counts the number of specific symbol
//                in a row.
//
// Parameters   : 
//			mat	      - A matrix (In)
//			row       - The num of the rows (In)	
//          symbol    - The symbol (Char)
//          
// Return Value : The number of times that the symbol is in the row.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Sum Symbol In Main Cross
//                          ------------------------
//
// General      : This function counts the number of specific symbol
//                in the main cross.
//
// Parameters   : 
//			mat	      - A matrix (In)
//          symbol    - The symbol (Char)
//          
// Return Value : The number of times that the symbol is in main cross.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Sum Symbol In Second Cross
//                          --------------------------
//
// General      : This function counts the number of specific symbol
//                in the second cross.
//
// Parameters   : 
//			mat	      - A matrix (In)
//          symbol    - The symbol (Char)
//          
// Return Value : The number of times that the symbol is in second cross.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Max In Matriza
//                          --------------
//
// General      : This function calculates the max value in the matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//          
// Return Value : The max value of the matrix.
//
//----------------------------------------------------------------------

short maxInMatriza(short mat[][DIM])
{
	unsigned short max = mat[ZERO][ZERO];
	unsigned short numInMat = ZERO;
	unsigned short matrizaSize = DIM * DIM;
	unsigned short counter;

	for (counter = ZERO; counter < matrizaSize; counter++)
	{
		numInMat = mat[counter / SEVEN][counter % SEVEN];
		max = (numInMat > max) ? numInMat : max;
	}

	return (max);
}

//----------------------------------------------------------------------
//                          Min In Matriza
//                          --------------
//
// General      : This function calculates the min value in the matrix.
//
// Parameters   : 
//			mat	      - A matrix (In)
//          
// Return Value : The min value of the matrix.
//
//----------------------------------------------------------------------

short minInMatriza(short mat[][DIM])
{
	unsigned short min = mat[ZERO][ZERO];
	unsigned short numInMat = ZERO;
	unsigned short matrizaSize = DIM * DIM;
	unsigned short counter;

	for (counter = ZERO; counter < matrizaSize; counter++)
	{
		numInMat = mat[counter / SEVEN][counter % SEVEN];
		min = (numInMat < min) ? numInMat : min;
	}

	return (min);
}
