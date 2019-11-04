//ArithmeticCheck.c
#pragma once

#include "AlonStrings.h"

//-----------------------------------------------------------------------------
//                                 Arthmetic Check
//                                 ---------------
//
// General : This program checks if a string is arthemtic expression.
//
// Input   : A string.
//
// Process : Counts the number of closing and opening brackets.
//
// Output  : Prints TRUE if the the closing and openings brackets the same,
//           else FALSE.
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
	STRING   arithemticExpression;
	short    numOfOpenBrackets;
	short    numOfCloseBrackets;
	BOOLEAN  isValid;

	// Code section

	// Gets the string input
	scanf("%s", &arithemticExpression);

	// Calculate the number of open or close brackets.
	numOfOpenBrackets = sumSymbolOnString(arithemticExpression, '(');
	numOfCloseBrackets = sumSymbolOnString(arithemticExpression, ')');

	isValid = (numOfOpenBrackets == numOfCloseBrackets) ? TRUE : FALSE;

	// Print if the expression is arithmetic or not.
	printf("%hu", isValid);
}