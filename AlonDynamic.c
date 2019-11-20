//AlonDynamic.c
#pragma once

#include "AlonDynamic.h"

int* evenSubArrayDynamic(int vec[], int len, int* ptrEven)
{
	int* ptrStartSubArray = (int)malloc(sizeof(int));
	int* ptrEvenSubArray = ptrStartSubArray;

	if (ptrStartSubArray == NULL)
	{
		return ptrEven;
	}

	for (; len; len--)
	{
		if (isNumberEven(vec[len]))
		{
			ptrStartSubArray = (int)realloc(++(*ptrEven), sizeof(int));
			*(ptrEvenSubArray++) = vec[len];
		}
	}
	free(ptrEvenSubArray);
	return (ptrStartSubArray);
}

int* oddSubArrayDynamic(int vec[], int len, int* ptrOdd)
{
	int* ptrStartSubArray = (int)malloc(sizeof(int));
	int* ptrOddSubArray = ptrStartSubArray;

	if (ptrStartSubArray == NULL)
	{
		return ptrOdd;
	}

	for (; len; len--)
	{
		if (!isNumberEven(vec[len]))
		{
			ptrStartSubArray = (int)realloc(++(*ptrOdd), sizeof(int));
			*(ptrOddSubArray++) = vec[len];
		}
	}
	free(ptrOddSubArray);
	return (ptrStartSubArray);
}

void oddEvenSubArraysDynamic(int vec[], int** even, int* evenSize, int** odd, int* oddSize, int arrayLength)
{
	even = evenSubArray(vec, arrayLength, evenSize);
	odd = oddSubArray(vec, arrayLength, oddSize);

	free(even);
	free(odd);
}

void addNumberToArrayDynamic(int* ptrArray, int arrayLength, int number)
{
	int numberLength = digitsLength(&number);

	ptrArray = (int)realloc(numberLength + arrayLength, sizeof(int));

	if (ptrArray == NULL)
	{
		return;
	}

	for (; numberLength; numberLength--)
	{
		*(++ptrArray) = number / (int)(power(TEN, numberLength));
	}

	free(ptrArray);
	return;
}

void cutStringDynamic(char* ptrCuttedString, char* ptrCutStringStart, int numToCut)
{
	int countCuttedString = ZERO;

	ptrCuttedString = (char)realloc(numToCut , sizeof(char));
	if (ptrCuttedString == NULL)
	{
		return;
	}

	for (; countCuttedString < numToCut; countCuttedString++)
	{
		*(ptrCuttedString++) = *(ptrCutStringStart++);
	}

	*(++ptrCuttedString) = '\0';

	free(ptrCuttedString);
}

void searchLongestWordDynamic(char string[], char* ptrMaxLen)
{
	int   maxWordLength = ZERO;
	char* ptrString = &(string[ZERO]);
	char* ptrTempLastWord;

	while (ptrString != '\0')
	{
		ptrTempLastWord = lastAddressWordFromString(ptrString);
		if (ptrTempLastWord - ptrString > maxWordLength)
		{
			maxWordLength = ptrTempLastWord - ptrString;
			cutStringDynamic(ptrMaxLen, ptrString, maxWordLength);
		}
		ptrString = ptrTempLastWord;
	}

	free(ptrMaxLen);
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