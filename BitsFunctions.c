#pragma once
#include "BitsFunctions.h"


BOOLEAN isNumEvenBit(int* ptrNumber)
{

	return (*ptrNumber & ONE);
}

BOOLEAN isNumOddBit(int* ptrNumber)
{
	return (*ptrNumber & ONE);
}

int calculateBits(int place)
{
	double two = TWO;
	return power(&two, place);
}

void rotateNumber(unsigned int* ptrNumber, int numOfTimes)
{
	unsigned int saveDigit;

	for (; numOfTimes; numOfTimes--)
	{
		saveDigit = ((*ptrNumber >> (sizeof(int) * EIGHT - ONE)) & ONE);
		*ptrNumber = *ptrNumber << ONE;

		*ptrNumber += saveDigit;
	}
	return;
}
