//AlonStrings.c
#pragma once

#include "AlonStrings.h"

//----------------------------------------------------------------------
//                           String Length
//                           -------------
//
// General      : This function calculates the length of string.
//
// Parameters   : 
//			string    - A string (char[])
//
// Return Value : The length of the string. 
//
//----------------------------------------------------------------------

unsigned short stringLength(char string[])
{
	unsigned short countLength = ZERO;

	while (string[countLength])
	{
		countLength++;
	}
	return (countLength);
}

//----------------------------------------------------------------------
//                        Sum Symbol On String
//                        --------------------
//
// General      : This function sums the amount of specific symbol on
//                a string.
//
// Parameters   : 
//			string    - A string (char[])
//          symbol    - A symbol (char)
//
// Return Value : The amount of specific symbol on a string.
//
//----------------------------------------------------------------------

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

//----------------------------------------------------------------------
//                     First Symbol Position On String
//                     -------------------------------
//
// General      : This function calculates the position of the first
//                desired symbol on a string. 
//
// Parameters   : 
//			string    - A string (char[])
//          symbol    - A symbol (char)
//
// Return Value : If the symbol is there, return the first apperance,
//                else return -1.
//
//----------------------------------------------------------------------


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

//----------------------------------------------------------------------
//                     Concatenation Strings
//                     ---------------------
//
// General      : This function makes concatenation between two strings. 
//
// Parameters   : 
//			stringOne - The string the function adds into (char[])
//          stringTwo - The string you want to add (char[])
//
// Return Value : None.
//
//----------------------------------------------------------------------

void concatenationStrings(char stringOne[], char stringTwo[])
{
	unsigned short position = ZERO;
	unsigned short firstStringLength = stringLength(stringOne);

	while (stringTwo[position])
	{
		stringOne[firstStringLength + position] = stringTwo[position];
		position++;
	}
	return;
}

//----------------------------------------------------------------------
//                          Copy String
//                          -----------
//
// General      : This function makes copies a string into another one. 
//
// Parameters   : 
//			oldString  - The string the function copies into (char[])
//          copyString - The string you want to copy (char[])
//
// Return Value : None.
//
//----------------------------------------------------------------------

void copyString(char oldString[], char copyString[], unsigned short position)
{
	unsigned short stringTwoPosition = ZERO;

	while (copyString[position] && oldString[stringTwoPosition])
	{
		copyString[position] = oldString[stringTwoPosition++];
		position++;
	}
	return;
}

//----------------------------------------------------------------------
//                     Delete Symbol On String
//                     -----------------------
//
// General      : This function deletes specific symbol on string.
//
// Parameters   : 
//			string    - A string (char[])
//          symbol    - A symbol (char)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteSymbolOnString(char string[], char symbol)
{
	unsigned short position = ZERO;

	while (string[position])
	{
		string[position] = (string[position] == symbol) ? GARBAGE : string[position];
		position++;
	}
	return;
}

//----------------------------------------------------------------------
//                          Cut String
//                          ----------
//
// General      : This function cuts a string into a smaller one. 
//
// Parameters   : 
//			string           - The string function cuts from (char[])
//          cuttedString     - The string to get the cut (char[])
//          startCutPosition - The start position to start cutting(In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void cutString(char string[], char cuttedString[], unsigned short startCutPosition)
{
	unsigned short position = ZERO;

	while (string[startCutPosition] != '\0' && cuttedString[position])
	{
		cuttedString[position] = string[startCutPosition];
		position++;
		startCutPosition++;
	}
	return;
}

//----------------------------------------------------------------------
//                          Fill String
//                          -----------
//
// General      : This function fills garbage into strings. 
//
// Parameters   : 
//			string       - The string you want to fill (char[])
//          numOfSymbols - The num of garbage(In).
//
// Return Value : None.
//
//----------------------------------------------------------------------

void fillString(char string[], unsigned short numOfSymbols)
{
	unsigned short position = ZERO;

	while (string[position] && position < numOfSymbols)
	{
		string[position] = GARBAGE;
		position++;
	}
	string[position] = '\0';
	return;
}

//----------------------------------------------------------------------
//                         Is Symbol On String
//                         -------------------
//
// General      : This function checks if a symbol is on a string.
//
// Parameters   : 
//			string   - A string (char[])
//          symbol   - A symbol (char)
//          position - The starting position to check from (In)
//
// Return Value : TRUE if the symbol is on the range, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSymbolOnString(char string[], char symbol, unsigned short position)
{
	while (string[position] && string[position] != symbol)
	{
		position++;
	}
	return (string[position] == symbol);
}

//----------------------------------------------------------------------
//                             Compare
//                             -------
//
// General      : This function compares two strings.
//
// Parameters   : 
//			stringOne - A string (char[])
//          stringTwo - A symbol (char)
//
// Return Value : TRUE if the strings are the same, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN compare(char stringOne[], char stringTwo[])
{
	unsigned short position = ZERO;

	while (stringOne[position] != '\0' && stringOne[position] == stringTwo[position])
	{
		position++;
	}
	return (stringOne[position] == stringTwo[position]);
}

//----------------------------------------------------------------------
//                         Is Sub String On String
//                         -----------------------
//
// General      : This function checks sub strings on a string.
//
// Parameters   : 
//			string    - A string (char[])
//          subString - A smaller string (char[])
//
// Return Value : TRUE if there is a sub string, else FALSE.
//
//----------------------------------------------------------------------

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
		isSubStringOnString = compare(cuttedString, subString);
		position++;
		subStringsAmount--;
	}
	return (isSubStringOnString);
}
