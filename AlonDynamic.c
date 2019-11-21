//AlonDynamic.c
#pragma once

#include "AlonDynamic.h"

//----------------------------------------------------------------------
//                          Print Int Array Dynamic
//                          -----------------------
//
// General      : This function prints an int dynamic array..
//
// Parameters   : 
//			ptrDynamicArrays - A pointer to dynamic array(In*)
//			length           - The length of the array (In) 
//
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void printIntArrayDynamic(int* ptrDynamicArray, int length)
{
	for (; length; length--)
	{
		printf("%d\n", *(ptrDynamicArray++));
	}
}

//----------------------------------------------------------------------
//                          Even Sub Array Dynamic
//                          -----------------------
//
// General      : This function makes dynamic even numbers array from
//                array.
//
// Parameters   : 
//			vec     - An array(In)
//			len     - The length of the array (In) 
//          ptrEven - the place to save the dynamic length. (int*)
//
//
// Return Value : A pointer to dynamic int array.
//
//----------------------------------------------------------------------

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
			ptrStartSubArray = (int)realloc(ptrStartSubArray, sizeof(int) * ++(*ptrEven));
			*(ptrStartSubArray + *ptrEven - ONE) = vec[len];
		}
	}
	return (ptrStartSubArray);
}

//----------------------------------------------------------------------
//                          Odd Sub Array Dynamic
//                          -----------------------
//
// General      : This function makes dynamic odd numbers array from
//                array.
//
// Parameters   : 
//			vec     - An array(In)
//			len     - The length of the array (In) 
//          ptrEven - the place to save the dynamic length. (int*)
//
//
// Return Value : A pointer to dynamic int array.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                         Odd Even Sub Arrays Dynamic
//                         ---------------------------
//
// General      : This function makes two dynamic arrays: from the even
//                and for the odd numbers.
//
// Parameters   : 
//			vec         - An array(In)
//			arrayLength - The length of the array (In) 
//          oddSize     - the size of the odd dynamic array. (In*)
//          evenSize    - the size of the even dynamic array.(In*)
//          even        - the dynamic array for even numbers(In**)
//          odd         - the dynamic array for odd numbers(In**)
//
//
// Return Value : None.
//
//----------------------------------------------------------------------

void oddEvenSubArraysDynamic(int vec[], int** even, int* evenSize, int** odd, int* oddSize, int arrayLength)
{
	even = evenSubArrayDynamic(vec, arrayLength, evenSize);
	odd = oddSubArrayDynamic(vec, arrayLength, oddSize);

	return;
}

//----------------------------------------------------------------------
//                          Odd Sub Array Dynamic
//                          -----------------------
//
// General      : This function adds a number to dynamic array.
//
// Parameters   : 
//			ptrArray    - pointer to dynamic array(In*)
//			arrayLength - the length of the currect dynamic array (In) 
//          number      - the number that needed to be added (In)
//
//
// Return Value : None.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                          Cut String Dynamic
//                          ------------------
//
// General      : This function cuts a dynamic string.
//
// Parameters   : 
//			ptrCuttedString    - pointer to dynamic cutted string(In*)
//			ptrCutStringStart  - the place to start to cut from the
//                               dynamic array. (char*) 
//          numToCut           - the number of cells to cut. (In)
//
//
// Return Value : None.
//
//----------------------------------------------------------------------

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


//----------------------------------------------------------------------
//                           Order Strings
//                           -------------
//
// General      : This function orders words by alphabet.
//
// Parameters   : 
//          names    - pointer to a strings in the array(char**)
//          namesLength - the length of the names.(char**)
//
//
// Return Value : None.
//
//----------------------------------------------------------------------

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
			if (**names > * currectSorttedString)
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

//----------------------------------------------------------------------
//                      Search Longest Word By Dynamic
//                          ------------------
//
// General      : This function finds the longest word from an array.
//
// Parameters   : 
//          string    - the string to check from (char)
//          ptrMaxLen - ptr to the max word(char**)
//
//
// Return Value : None.
//
//----------------------------------------------------------------------

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
// Idea for only 1 loop, have 3 pointers, 1 for max word, one for temp,
// one for switch, and have an if that if it reaches the "garbage", 
// check if temp is larger than max.