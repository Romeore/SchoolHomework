//MagicSquare.c
#pragma once
#include "AlonMatrizas.h"

//-----------------------------------------------------------------------------
//                                 Magic Square
//                                 ------------
//
// General : This program checks if a matrix is a magic square.
//
// Input   : None.
//
// Process : Check if the sum is the same for each column, row and cross.
//
// Output  : Prints if the matrix is magic square or not.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 30.10.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	unsigned short magicSquare[DIM][DIM] = { FOUR, NINE, TWO, THREE, FIVE, SEVEN, EIGHT, ONE, SIX};
	BOOLEAN        isMagicSquare = TRUE;
	unsigned short dimCounter = ZERO;
	unsigned short magicSquareSum = sumColumnInMatriza(magicSquare, ZERO);

	// Code section

	// Check each column and row if they have the same magic square sum.
	while(isMagicSquare && dimCounter < DIM)
	{
		magicSquareSum != sumColumnInMatriza(magicSquare, dimCounter) ? isMagicSquare = FALSE : isMagicSquare;
		magicSquareSum != sumRowInMatriza(magicSquare, dimCounter) ? isMagicSquare = FALSE : isMagicSquare;
		dimCounter++;
	}

	// Check each cross if they have the same magic square sum.
	magicSquareSum != sumMainCrossInMatriza(magicSquare) ? isMagicSquare = FALSE : isMagicSquare;
	magicSquareSum != sumSecondCrossInMatriza(magicSquare) ? isMagicSquare = FALSE : isMagicSquare;

	// Print if the matrix is a magic square or not.
	printf("\n%hu", isMagicSquare);
}

// For number 4 : Check for each cell in the larger matrix how many zeros are
// in the smaller matrix that he is in, and save it on a vector, and check the
// max value in the vector.