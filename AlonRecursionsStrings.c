//AlonRecursionsStrings.c

#include "AlonRecursionsStrings.h"

//----------------------------------------------------------------------
//                          Is Char Digit
//                          --------------
//
// General      : This function checks if a symbol is a digit.
//
// Parameters   : 
//			symbol - A pointer to symbol. (char*)
//
// Return Value : returns TRUE if the symbol is a digit, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isCharDigit(char* symbol)
{
	return ((*symbol >= '0') && (*symbol <= '9'));
}

//----------------------------------------------------------------------
//                       String Length Recursion
//                       -----------------------
//
// General      : This function calculates the string length.
//
// Parameters   : 
//			string - a pointer to string. (char*)
//
// Return Value : returns the string length.
//
//----------------------------------------------------------------------

int stringLengthRecursion(char* string)
{
	if (*string == '\0')
	{
		return (ZERO);
	}

	return (stringLengthRecursion(++string) + ONE);
}


//----------------------------------------------------------------------
//                   Is Even Places Digit Recursion
//                   ------------------------------
//
// General      : This function checks if even places in a string is
//                digits.
//
// Parameters   : 
//			string - a string. (char*)
//
// Return Value : returns TRUE if the places that the even places are
//                digits, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isEvenPlacesDigitRecursion(char* string)
{
	if (*string == '\0' || *(++string) == '\0')
	{
		return (TRUE);
	}

	return (isCharDigit(string) && isEvenPlacesDigitRecursion(++string));
}

//----------------------------------------------------------------------
//						Num Of Apperance Recursion
//					    --------------------------
//
// General		: This function sums the amount of specific symbol on
//				  a string.
//
// Parameters   : 
//			string - a string. (char*)
//		    symbol - a symbol. (char)
//
// Return Value : returns the sum of a specific symbol on a string.
//
//----------------------------------------------------------------------

int numOfApperanceRecursion(char* string, char symbol)
{
	if (*string == '\0')
	{
		return (ZERO);
	}

	return ((symbol == *string)
		+ numOfApperanceRecursion(++string, symbol));
}

//----------------------------------------------------------------------
//					Compare Strings Helper Recursion
//					--------------------------------
//
// General      : This function checks if a sub string equals to a
//				  specific part in the string.
//
// Parameters   :
//			string    - a string. (char*)
//			subString - a subString that smaller than the string. (char*)
//
// Return Value : returns TRUE if the subStrings are equal, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN compareStringsHelperRecursion(char* string, char* subString)
{
	if (*subString == '\0')
	{
		return (TRUE);
	}

	if (*string == '\0')
	{
		return (FALSE);
	}

	return ((*string == *subString) 
		&& compareStringsHelperRecursion(++string, ++subString));
}

//----------------------------------------------------------------------
//				    Is Sub String On String Recursion
//                  ---------------------------------
//
// General      : This function checks if a sub string apperance
//		          in the string.
//
// Parameters   :
//			string   - a string. (char*)
//			subString - a subString that smaller than the string. (char*)
//
// Return Value : returns TRUE if the sub string is on a string,
//				  else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSubStringOnStringRecursion(char* string, char* subString)
{
	if (*string == '\0')
	{
		return (FALSE);
	}

	return (compareStringsHelperRecursion(string, subString) 
		|| isSubStringOnStringRecursion(++string, subString));
}

//----------------------------------------------------------------------
//							Copy String Recursion
//							---------------------
//
// General	    : This function copies a string in recursion.
//
// Parameters   :
//			string   - a string. (char*)
//			copiedTo - the string to copy to (char*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void copyStringRecursion(char* string, char* copiedTo)
{
	if (*(string) == '\0')
	{
		*copiedTo = *string;
		return;
	}

	*copiedTo = *string;

	return (copyStringRecursion(++string, ++copiedTo));
}

//----------------------------------------------------------------------
//					    Reverses String Recursion
//					    -------------------------
//
// General      : This function reverses a string in recursion.
//
// Parameters   :
//			string    - a string. (char*)
//			reverseTo - the string to save the result(char*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void reverseStringRecursion(char* string, char* reverseTo)
{
	char ptrString[TWO] = { *string, '\0' };

	if (*string == '\0')
	{
		return;
	}

	reverseStringRecursion(++string, reverseTo);
	strcat(reverseTo, ptrString);

	return;
}

//----------------------------------------------------------------------
//							Concatenation Mirror
//							--------------------
//
// General      : This function concate a reveresed string to a string.
//
// Parameters   :
//			string - a string. (char*)
//
// Return Value : returns the string that has its reversed side
//                concatenated.
//
//----------------------------------------------------------------------

char* concatenationMirror(char* string)
{
	int length = stringLengthRecursion(string);
	char* stringHelper = malloc(sizeof(char) * length * TWO);

	reverseStringRecursion(string, stringHelper);
	strcat(stringHelper, string);

	return (stringHelper);
}


//----------------------------------------------------------------------
//								Print Akltoni Helper
//							    --------------------
//
// General      : This function prints a string like akltoni.
//
// Parameters   :
//			string - a string. (char*)
//			size - the size of the string. (int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printAkltoniHelper(char* string, int size)
{
	if (size == ZERO)
	{
		printf("%c", *string);
		return;
	}

	printf("%c", *string);
	string += size;
	size = ((size < ZERO) ? (-ONE) : (ONE)) + size * -ONE;
	return printAkltoniHelper(string, size);
}

//----------------------------------------------------------------------
//								Print Akltoni Helper
//							    --------------------
//
// General      : This function prints a string like akltoni.
//
// Parameters   :
//			string - a string. (char*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printAkltoni(char* string)
{
	return (printAkltoniHelper(string, stringLengthRecursion(string) - ONE));
}
