//AlonPointers.c
#pragma once

#include "AlonPointers.h"

BOOLEAN* isNumberEven(int* ptrNum)
{
	BOOLEAN isNumberEven = *ptrNum % TWO;
	return &isNumberEven;
}

BOOLEAN* isNumberOdd(int* ptrNum)
{
	BOOLEAN isNumberOdd = !(*ptrNum % TWO);
	return &isNumberOdd;
}

void swap(int* ptrNumOne, int* ptrNumTwo)
{
	int tempNumber = *ptrNumOne;
	*ptrNumOne = *ptrNumTwo;
	*ptrNumTwo = tempNumber;
}

int* sumTwoNumbers(int* ptrNumOne, int* ptrNumTwo)
{
	int sum = *ptrNumOne + *ptrNumTwo;
	return &sum;
}

unsigned short* digitsLength(int* ptrNum)
{
	int tempNumber = *ptrNum;
	unsigned short length = ZERO;
	for (; tempNumber; tempNumber /= TEN)
	{
		length++;
	}
	return &length;
}

int* sumDigits(int* ptrNum)
{
	int tempNumber = *ptrNum;
	int sum = ZERO;

	for (; tempNumber; tempNumber /= TEN)
	{
		sum += tempNumber % TEN;
	}
	return &sum;
}

BOOLEAN* isDigitOnNum(int* ptrNum, unsigned short* ptrDigit)
{
	int tempNumber = *ptrNum;
	BOOLEAN isDigitOnNum = FALSE;

	for (; tempNumber && !isDigitOnNum; tempNumber /= TEN)
	{
		isDigitOnNum = (tempNumber == *ptrDigit) ? TRUE : FALSE;
	}
	return &isDigitOnNum;
}

void concatentionNumbers(int* ptrNumOne, int* ptrNumTwo)
{
	int tempNumberTwo = *ptrNumTwo;
}


void main(void)
{
	int number = 2184;
	int numberTwo = 8;
	printf("%d", *isDigitOnNum(&number, &numberTwo));
}