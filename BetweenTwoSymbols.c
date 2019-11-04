//BetweenTwoSymbols.c
#pragma once

#include "AlonStrings.h"

//-----------------------------------------------------------------------------
//                              Between Two Symbols
//                              -------------------
//
// General : This program calculates the number of sub strings that start with
//           one symbol and ends with another one.
//
// Input   : A string.
//
// Process : Check the whole string if there is sub strings that start with
//           'a' and finish with 'b' and counts them.
//
// Output  : Prints the number of sub strings that start with 'a' and 
//           finish with 'b'.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 3.11.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	typedef char STRING[STRINGMAXLENGTH];
	STRING         inputString;
	STRING         tempString;
	unsigned short numOfSubStrings = ZERO;
	unsigned short inputStringLength;
	short          position = ZERO;
	short          firstSymbolOnePosition;
	short          firstSymbolTwoPosition;
	char           symbolOne = 'A';
	char           symbolTwo = 'B';
	BOOLEAN        isThereTwoSymbols;

	// Code section

	// Gets the input
	printf("Write the string\n");
	scanf("%s", &inputString);

	// Move the input into a temp string.
	inputStringLength = stringLength(inputString);
	fillString(tempString, inputStringLength);
	copyString(inputString, tempString, ZERO);

	// Check if needed to get in the loop.
	firstSymbolOnePosition = firstSymbolPositionOnString(tempString, symbolOne);
	firstSymbolTwoPosition = firstSymbolPositionOnString(tempString, symbolTwo);
	isThereTwoSymbols = (firstSymbolOnePosition != -ONE && firstSymbolTwoPosition != -ONE);

	// Check if the string isn't empty and there is two symbols.
	while (tempString[position] && isThereTwoSymbols)
	{
		numOfSubStrings++;
		// Add garbage to get the next first symbols in the string.
		tempString[firstSymbolOnePosition] = GARBAGE;
		tempString[firstSymbolTwoPosition] = GARBAGE;
		// Find the place of this symbols.
		firstSymbolOnePosition = firstSymbolPositionOnString(tempString, symbolOne);
		firstSymbolTwoPosition = firstSymbolPositionOnString(tempString, symbolTwo);
		// Check if the program found those two symbols.
		isThereTwoSymbols = (firstSymbolOnePosition != -ONE && firstSymbolTwoPosition != -ONE);
		position++;
	}
	// Print the number of substrings.
	printf("Num of substrings are %hd", numOfSubStrings);
}
