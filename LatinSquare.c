#pragma once

#include "AlonMatrizas.h"

void mainAD(void)
{
	unsigned short latinSquare[DIM][DIM] = { ONE, TWO, THREE, TWO, ONE, FOUR, THREE, FOUR, FIVE };
	unsigned short matCounter[TEN] = { ZERO };

	BOOLEAN        isLatinSquare = TRUE;
	unsigned short dimCounter = ZERO;

	printMat(latinSquare);
	for (dimCounter; dimCounter < DIM; dimCounter++)
	{
		isTwoNumbersSameInColumn(latinSquare, dimCounter) ? isLatinSquare = FALSE : isLatinSquare;
		isTwoNumbersSameInRow(latinSquare, dimCounter) ? isLatinSquare = FALSE : isLatinSquare;
	}

	printf("\n%hu", isLatinSquare);
	scanf("%hu", &dimCounter);
}