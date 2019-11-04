//DeleteStringSymbols.c
#pragma once

#include "AlonStrings.h"

//-----------------------------------------------------------------------------
//                             Delete String Symbols
//                             ---------------------
//
// General : This program deletes symbols that are repeated in two strings
//           from the second one.
//
// Input   : Two strings.
//
// Process : Check every symbol and delete it from the second string.
//
// Output  : Prints the input string, the new string and the num of deleted
//           symbols.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 3.11.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	typedef char   STRING[STRINGMAXLENGTH];
	STRING         firstString;
	STRING         secondString;
	unsigned short numOfDeleted;
	unsigned short position = ZERO;

	// Code section

	printf("Write the first string\n");
	scanf("%s", &firstString);
	printf("Write the second string\n");
	scanf("%s", &secondString);
	
	// Print the second string before deleting.
	printf("%s", secondString);
	while (firstString[position])
	{
		deleteSymbolOnString(secondString, firstString[position]);
		position++;
	}

	numOfDeleted = sumSymbolOnString(secondString, GARBAGE);
	// Print the new string and the number of symbols that have been deleted.
	printf("The new string is: %s\n", secondString);
	printf("The num that deleted is: %hu", numOfDeleted);
}