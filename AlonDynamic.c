//AlonDynamic.c
#pragma once

#include "AlonDynamic.h"

void printIntArrayDynamic(int* ptrDynamicArray, int length)
{
	for (; length; length--)
	{
		printf("%d\n", *(ptrDynamicArray++));
	}
}

int* evenSubArrayDynamic(int vec[], int len, int* ptrEven)
{
	int* ptrStartSubArray = (int)malloc(sizeof(int));

	if (ptrStartSubArray == NULL)
	{
		return ptrEven;
	}

	for (len--; len; len--)
	{
		if (vec[len] % TWO == ZERO)
		{
			ptrStartSubArray = (int)realloc(ptrStartSubArray,sizeof(int) * ++(*ptrEven));
			*(ptrStartSubArray+ *ptrEven - ONE) = vec[len];
		}
	}
	return (ptrStartSubArray);
}

int* oddSubArrayDynamic(int vec[], int len, int* ptrOdd)
{
	int* ptrStartSubArray = (int)malloc(sizeof(int));
	
	if (ptrStartSubArray == NULL)
	{
		return ptrOdd;
	}

	for (len--; len; len--)
	{
		if (vec[len] % TWO != ZERO)
		{
			ptrStartSubArray = (int)realloc(ptrStartSubArray, sizeof(int) * ++(*ptrOdd));
			*(ptrStartSubArray + *ptrOdd - ONE) = vec[len];
		}
	}
	return (ptrStartSubArray);
}

void oddEvenSubArraysDynamic(int vec[], int** even, int* evenSize, int** odd, int* oddSize, int arrayLength)
{
	even = evenSubArrayDynamic(vec, arrayLength, evenSize);
	odd = oddSubArrayDynamic(vec, arrayLength, oddSize);

	return;
}

void addNumberToArrayDynamic(int* ptrArray, int arrayLength, int number)
{
	int numberLength = digitsLength(&number);
	int tempNumber = number;
	int powerNum;
	double tenNumber = TEN;
	ptrArray = (int)realloc(ptrArray, (numberLength + arrayLength) * sizeof(int));

	if (ptrArray == NULL)
	{
		return;
	}

	for (; numberLength; numberLength--)
	{
		powerNum = (power(&tenNumber, numberLength - ONE));
		tempNumber = number / powerNum;
		*(ptrArray++ + arrayLength) = tempNumber;
		number -= tempNumber * powerNum;
	}

	return;
}

void cutStringDynamic(char* ptrCuttedString, char* ptrCutStringStart, int numToCut)
{
	int countCuttedString = ZERO;

	ptrCuttedString = (char)realloc(ptrCuttedString, (3 * sizeof(char)));

	if (ptrCuttedString == NULL)
	{
		return;
	}

	for (; countCuttedString < numToCut; countCuttedString++)
	{
		*(ptrCuttedString + countCuttedString) = *(ptrCutStringStart + countCuttedString);
	}

	*(ptrCuttedString) = '\0';

	return;
}

void searchLongestWordDynamic(char string[], char** ptrMaxLen)
{
	int   maxWordLength = ZERO;
	char* ptrString = &(string[ZERO]);
	char* ptrTempLastWord;
	char* ptrMaxWord;

	while ((*ptrString) != '\0')
	{
		ptrTempLastWord = lastAddressWordFromString(ptrString);
		if ((ptrTempLastWord - ptrString - ONE) > maxWordLength)
		{
			maxWordLength = ptrTempLastWord - ptrString - ONE;
			ptrMaxWord = ptrString;
		}
		ptrString = ptrTempLastWord;
	}
	
	return;
}

void orderStrings(char** names, int namesLength)
{
	char** startPlace = names;
	char* currectSorttedString = *names;
	char* tempString = *names;
	int numOfNames = ZERO;
	int counter = ZERO;
	BOOLEAN isFoundPlace = FALSE;

	for (; namesLength; namesLength--)
	{
		names = startPlace;
		currectSorttedString = *(names + numOfNames);
		for (counter = ZERO; counter < numOfNames && !isFoundPlace; counter++)
		{
			if (**names > *currectSorttedString)
			{
				tempString = currectSorttedString;
				**names = tempString;
				currectSorttedString = *names;
				isFoundPlace = TRUE;
			}
		}

		numOfNames++;
		isFoundPlace = FALSE;
	}
}
