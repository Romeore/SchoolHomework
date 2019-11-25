//BitsFunctions.c
#pragma once

#include "BitsFunctions.h"

//----------------------------------------------------------------------
//                          Is Num Even Bit
//                          ----------------
//
// General      : This function checks if a number is even.
//
// Parameters   : 
//			ptrNumber - A pointer. (In)
//
// Return Value : Returns TRUE if the number is even, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isNumEvenBit(int* ptrNumber)
{

	return (*ptrNumber & ONE);
}

//----------------------------------------------------------------------
//                          Is Num Odd Bit
//                          ----------------
//
// General      : This function checks if a number is odd.
//
// Parameters   : 
//			ptrNumber - A pointer. (In)
//
// Return Value : Returns TRUE if the number is odd, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isNumOddBit(int* ptrNumber)
{
	return (*ptrNumber & ONE);
}

//----------------------------------------------------------------------
//                          Calculate Bits
//                          --------------
//
// General      : This function calculates the bit placement in a number
//
// Parameters   : 
//			ptrNumber - The bit placement. (In)
//
// Return Value : Returns the placement of a bit in a number.
//
//----------------------------------------------------------------------

int calculateBits(int place)
{
	double two = TWO;
	return power(&two, place);
}

//----------------------------------------------------------------------
//                          Rotate Number
//                          -------------
//
// General      : This function rotates number's bits (like ROL).
//
// Parameters   : 
//			ptrNumber  - A pointer. (In)
//			numOfTimes - The number of times to rotate. (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void rotateNumber(unsigned int* ptrNumber, int numOfTimes)
{
	unsigned int saveDigit;

	for (; numOfTimes; numOfTimes--)
	{
		saveDigit = ((*ptrNumber >> (sizeof(int) * EIGHT - ONE))& ONE);
		*ptrNumber = *ptrNumber << ONE;

		*ptrNumber += saveDigit;
	}
	return;
}
