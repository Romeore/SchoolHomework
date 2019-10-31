//LatinSquare.c
#pragma once

#include "AlonMatrizas.h"

//-----------------------------------------------------------------------------
//                                 Tic Tac Toe
//                                 ------------
//
// General : This program checks if a matrix a latin square.
//
// Input   : None.
//
// Process : Checks each column and row the numbers are not the same.
//
// Output  : Prints TRUE if the matrix is latin square, else prints FALSE.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 30.10.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	unsigned short latinSquare[DIM][DIM] = { ONE, TWO, THREE, TWO, ONE, FOUR, THREE, FOUR, FIVE };
	unsigned short matCounter[TEN] = { ZERO };
	unsigned short dimCounter = ZERO;
	BOOLEAN        isLatinSquare = TRUE;

	// Code section

	// This loop runs on the main cross.
	for (dimCounter; dimCounter < DIM; dimCounter++)
	{
		// Check each row and column in the cross they're not the same.
		isTwoNumbersSameInColumn(latinSquare, dimCounter) ? isLatinSquare = FALSE : isLatinSquare;
		isTwoNumbersSameInRow(latinSquare, dimCounter) ? isLatinSquare = FALSE : isLatinSquare;
	}

	// Print if the matrix is latin square or not.
	printf("\n%hu", isLatinSquare);
}
