//AlonRecursionsArray.c

#include "AlonRecursionsArray.h"

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
		return ZERO;
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
		return TRUE;
	}

	return (isCharDigit(string) && isEvenPlacesDigitRecursion(++string));
}

int numOfApperanceRecursion(char* string, char symbol)
{
	if (*string == '\0')
	{
		return ZERO;
	}

	return (symbol == *string) + numOfApperanceRecursion(++string, symbol);
}

BOOLEAN compareStringsHelperRecursion(char* string, char* subString)
{
	if (*subString == '\0')
	{
		return TRUE;
	}

	if (*string == '\0')
	{
		return FALSE;
	}

	return (*string == *subString) && compareStringsHelperRecursion(++string, ++subString);
}


BOOLEAN isSubStringOnStringRecursion(char* string, char* subString)
{
	if (*string == '\0')
	{
		return FALSE;
	}

	return compareStringsHelperRecursion(string, subString) || isSubStringOnStringRecursion(++string, subString);
}

void copyStringRecursion(char* string, char* copiedTo)
{
	if (*(string) == '\0')
	{
		*copiedTo = *string;
		return;
	}
	
	*copiedTo = *string;
	return copyStringRecursion(++string, ++copiedTo);
}

char* reverseStringRecursion(char* string, char* reverseTo)
{
	if (*string == '\0')
	{
		return;
	}

	char ptrString[TWO] = { *string, '\0' };
	reverseStringRecursion(++string, reverseTo);

	return strcat(reverseTo, ptrString);
}

char* copyMirror(char* string)
{
	int length = stringLengthRecursion(string);
	char* stringHelper = malloc(sizeof(char) * length * TWO);
	stringHelper = reverseStringRecursion(string, stringHelper);

	return (strcat(stringHelper, string));
}

void printAkltoniHelper(char* string, int size)
{
	if (size == ZERO)
	{
		printf("%c", *string);
		return;
	}

	printf("%c", *string);
	string += size;
	size =  ((size < ZERO) ? (-ONE) : (ONE)) + size * -ONE;
	return printAkltoniHelper(string, size);
}

void printAkltoni(char* string)
{
	return printAkltoniHelper(string, stringLengthRecursion(string) - ONE);
}

void main(void)
{
	typedef char STRING[10];
	STRING stringOne = { 'A','B','C','D','E','F','G','H'};

	STRING stringTwo = {""};

	char* stringOnePtr = &stringOne;
	char* stringTwoPtr = &stringTwo;

	printAkltoni(stringOne);

	BOOLEAN test = isSubStringOnStringRecursion(stringOnePtr, stringTwoPtr);
	scanf("%hu", &test);
}