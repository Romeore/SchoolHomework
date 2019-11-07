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

int* digitsLength(int* ptrNum)
{
	int tempNumber = *ptrNum;
	int length = ZERO;
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

void isDigitOnNum(int* ptrNum, unsigned short* ptrDigit, BOOLEAN* isDigitOnNumber)
{
	int tempNumber = *ptrNum;

	for (; tempNumber && !(*isDigitOnNumber); tempNumber /= TEN)
	{
		*isDigitOnNumber = (tempNumber == *ptrDigit) ? TRUE : FALSE;
	}
	return;
}

void power(double *ptrNumber, int* ptrNumberOfTimes, double* answer)
{
	*answer = ONE;
	int numberOfTimes = *ptrNumberOfTimes;
	
	for (numberOfTimes; numberOfTimes; numberOfTimes--)
	{
		*answer *= *ptrNumber;
	}
	
	return;
}

void concatenationNumbers(int* ptrNumOne, int* ptrNumTwo)
{
	int numTwoLength = *digitsLength(ptrNumTwo);
	int flippedNumber = *ptrNumTwo;
	flipNumber(&flippedNumber);

	for (; flippedNumber; flippedNumber /= TEN)
	{
		*ptrNumOne = (*ptrNumOne) * (TEN) + (flippedNumber % TEN);
	}

	return;
}

void flipNumber(int* ptrNum)
{
	int flippedNumber = ZERO;

	for (; (*ptrNum); (*ptrNum) /= TEN)
	{
		flippedNumber = flippedNumber * (TEN) + (*ptrNum) % (TEN);
	}
	*ptrNum = flippedNumber;

	return;
}

void isNumberOnNumber(int* ptrNumOne, int* ptrNumTwo, BOOLEAN* isNumOnNum)
{
	BOOLEAN isTrue = *isNumOnNum;
	int tempNumber = *ptrNumOne;
	unsigned short digit;

	for (;tempNumber  && !isTrue ; tempNumber /= TEN)
	{
		isDigitOnNum(*ptrNumOne, &digit, &isTrue);
		isDigitOnNum(*ptrNumTwo, &digit, &isTrue);
	}

	return;
}



void main(void)
{
	int number = 3817;
	int numberTwo = 918;

	BOOLEAN isNumberOnNum = FALSE;

	double answer;
	
	isNumberOnNumber(&number, &numberTwo, &isNumberOnNum);

	printf("%hu", isNumberOnNum);
	scanf("%d", &number);
}
