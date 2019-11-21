#pragma once

#define ARRAYLENGTH 7

#include "AlonDynamic.h"

void main(void)
{
	typedef char STRING[STRINGMAXSIZE];

	STRING string = { "ABC@KDJ@JDHH@A@\0" };
	char** maxWordPtr = malloc(sizeof(char));

	int checkTemp[ARRAYLENGTH] = { 1,1,8,4,10,1,5 };
	int  even = ZERO;
	int* ptrEven = &even;
	int* dynamicArray = evenSubArrayDynamic(checkTemp, ARRAYLENGTH, ptrEven);
	
	int testNum = 3421;

	searchLongestWordDynamic(string, maxWordPtr);

	printf("%s", *maxWordPtr);
	addNumberToArrayDynamic(dynamicArray, *ptrEven, testNum);
	printIntArrayDynamic(dynamicArray, *ptrEven + 4);
	free(dynamicArray);
	free(maxWordPtr);
	scanf("%d", &even);
}