//LongestRepeatString.c
#pragma once

#include "AlonStrings.h"

//-----------------------------------------------------------------------------
//                             Longest Repeat String
//                             ---------------------
//
// General : This program finds the longest repeat symbols in a string array.
//
// Input   : Ten strings.
//
// Process : Check each string for the longest repeat symbols.
//
// Output  : Prints the longest repeating symbols string and its position.
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
	STRING stringArray[TEN];
	unsigned short longestRepeatSymbol = ZERO;
	unsigned short maxRepeatStringNum = ZERO;
	unsigned short repeatingSymbolsCounter = ZERO;
	unsigned short stringArrayLength = TEN;
	unsigned short stringNumber;
	unsigned short position;

	// Code section

	for (stringNumber = ZERO; stringNumber < stringArrayLength; stringNumber++)
	{
		position = ZERO;
		// Check the next string
		while (stringArray[stringNumber][position])
		{
			// If there is repeating symbol, add to the counter.
			if (stringArray[stringNumber][position] == stringArray[stringNumber][position + ONE])
			{
				repeatingSymbolsCounter++;
			}
			// Else, initilaize the counter to zero and check if it is the max.
			else
			{
				longestRepeatSymbol = MAX(longestRepeatSymbol, repeatingSymbolsCounter);
				// If the repeating symbols counter is the longest, save the string position.
				maxRepeatStringNum = longestRepeatSymbol == repeatingSymbolsCounter ?
					stringNumber : repeatingSymbolsCounter;
				repeatingSymbolsCounter = ZERO;
			}
			// Move to the next string on the array.
			position++;
		}
	}

	// Print the longest repeated string and its position on the array.
	printf("The longest repeated string array is: %s\n", stringArray[maxRepeatStringNum]);
	printf("The position on the string array is : %hu", maxRepeatStringNum);
}