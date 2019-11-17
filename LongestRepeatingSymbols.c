#pragma once

#include "AlonPointers.h"

void main(void)
{
	typedef char STRING[STRINGMAXSIZE];
	STRING stringMat[MAXSIZEROW];

	char *stringPointer = &stringMat;
	char *stringLastPointer = stringLastAddress(stringPointer) - STRINGMAXSIZE;

	int maxRepeatingArrayNum = ZERO;
	int maxRepeatingSymbols = ZERO;
	int tempRepeatingSymbols = ZERO;
	int counter = ZERO;

	for (; stringPointer < stringLastPointer; stringPointer += STRINGMAXSIZE)
	{
		printf("Write the string ");
		scanf("%s", stringPointer);

		tempRepeatingSymbols = maxNumOfSymbolsOnString(stringPointer);
		if (tempRepeatingSymbols > maxRepeatingSymbols)
		{
			maxRepeatingSymbols = tempRepeatingSymbols;
			maxRepeatingArrayNum = (stringLastPointer - stringPointer) / STRINGMAXSIZE;
		}
	}

	printf("%s", stringLastPointer - (maxRepeatingArrayNum) * STRINGMAXSIZE);
	printf("%d\n\n", MAXSIZEROW - maxRepeatingArrayNum);
}
