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
//                           Is Num Odd Bit
//                        ss   --------------
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
	return (power(&two, place));
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

void rotateNumberBit(unsigned int* ptrNumber, int numOfTimes)
{
	unsigned int saveDigit;

	for (; numOfTimes; numOfTimes--)
	{
		saveDigit = ((*ptrNumber >> (INTNUMOFBITS - ONE))& ONE);
		*ptrNumber = *ptrNumber << ONE;

		*ptrNumber += saveDigit;
	}
	return;
}

//----------------------------------------------------------------------
//                       Is Number Has Even Bits
//                       -----------------------
//
// General      : This function checks if a number has even bits.
//
// Parameters   : 
//			ptrNumber - A pointer. (In)
//
// Return Value : Returns TRUE if the bits are even, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isNumberHasEvenBits(int* ptrNumber)
{
	int counter = ZERO;
	int numOfOnes = ZERO;

	for (counter; counter < INTNUMOFBITS; counter++)
	{
		isNumberEven(ptrNumber) ? numOfOnes++ : numOfOnes;
		rotateNumberBit(ptrNumber, ONE);
	}

	return isNumberEven(&numOfOnes);
}
