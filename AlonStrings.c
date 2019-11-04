#pragma once
#include "AlonStrings.h"

unsigned short stringLength(char string[])
{
	unsigned short countLength = ZERO;
	while (string[countLength])
	{
		countLength++;
	}

	return (countLength);
}

unsigned short sumSymbolOnString(char string[], char symbol)
{
	unsigned short position = ZERO;
	unsigned short symbolCounter = ZERO;

	while (string[position])
	{
		string[position] == symbol ? symbolCounter++ : symbolCounter;
		position++;
	}

	return (symbolCounter);
}

short firstSymbolPositionOnString(char string[], char symbol)
{
	unsigned short position = ZERO;

	while (string[position] && string[position] != symbol)
	{
		position++;
	}

	position = (string[position] == symbol) ? position : -ONE;

	return (position);
}

BOOLEAN isSymbolOnString(char string[], char symbol, unsigned short position)
{
	while (string[position] && string[position] != symbol)
	{
		position++;
	}

	return (string[position] == symbol);
}

BOOLEAN compare(char stringOne[], char stringTwo[])
{
	unsigned short position = ZERO;
	while (stringOne[position] != '\0' && stringOne[position] == stringTwo[position])
	{
		position++;
	}

	return (stringOne[position] == stringTwo[position]);
}

void concatenationStrings(char stringOne[], char stringTwo[])
{
	unsigned short position = ZERO;
	unsigned short firstStringLength = stringLength(stringOne);

	while (stringTwo[position])
	{
		stringOne[firstStringLength + position] = stringTwo[position];
		position++;
	}
}

void copyString(char stringOne[], char stringTwo[], unsigned short position)
{
	unsigned short stringTwoPosition = ZERO;
	while (stringOne[position] && stringTwo[stringTwoPosition])
	{
		stringOne[position] = stringTwo[stringTwoPosition++];
		position++;
	}
}

void cutString(char stringOne[], char cuttedString[], unsigned short startCutPosition)
{
	unsigned short position = ZERO;

	while (stringOne[startCutPosition] != '\0' && cuttedString[position])
	{
		cuttedString[position] = stringOne[startCutPosition];
		position++;
		startCutPosition++;
	}
}

void fillString(char string[], unsigned short numOfSymbols)
{
	unsigned short position = ZERO;
	while (string[position] && position < numOfSymbols)
	{
		string[position] = '@';
		position++;
	}
	string[position] = '\0';
}

BOOLEAN isSubStringOnString(char string[], char subString[])
{
	char           cuttedString[STRINGMAXLENGTH];
	unsigned short position = ZERO;
	unsigned short subStringsAmount = stringLength(string) - stringLength(subString);
	BOOLEAN        isSubStringOnString = FALSE;

	fillString(cuttedString, 4);
	while (string[position] && !isSubStringOnString && subStringsAmount)
	{
		cutString(string, cuttedString, position);
		printf("%s\n", cuttedString);
		isSubStringOnString = compare(cuttedString, subString);
		position++;
		subStringsAmount--;
	}

	return (isSubStringOnString);
}