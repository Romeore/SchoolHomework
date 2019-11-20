//AlonPointers.c
#pragma once

#include "AlonPointers.h"

//----------------------------------------------------------------------
//                              Is Number Even
//                              --------------
//
// General      : This function checks if a number is even or not.
//
// Parameters   : 
//			ptrNum	- A pointer (In)
//					
//
// Return Value : A pointer with TRUE value if the number is even, else
//                value is FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isNumberEven(int* ptrNum)
{
	return (*ptrNum % TWO);
}

//----------------------------------------------------------------------
//                              Is Number Odd
//                              --------------
//
// General      : This function checks if a number is odd or not.
//
// Parameters   : 
//			ptrNum - A pointer (In)
//					
//
// Return Value : A pointer with TRUE value if the number is odd, else
//                value is FALSE.
//
//----------------------------------------------------------------------

BOOLEAN* isNumberOdd(int* ptrNum)
{
	BOOLEAN isNumberOdd = !(*ptrNum % TWO);

	return (&isNumberOdd);
}

//----------------------------------------------------------------------
//                              Sum Two Numbers
//                              ---------------
//
// General      : This function calculates the sum of two numbers.
//
// Parameters   : 
//			ptrNumOne - A pointer (In)
//			ptrNumTwo - A pointer (In)
//					
//
// Return Value : A pointer with the sum of the values of the pointers.
//
//----------------------------------------------------------------------

int* sumTwoNumbers(int* ptrNumOne, int* ptrNumTwo)
{
	int sum = *ptrNumOne + *ptrNumTwo;

	return (&sum);
}

//----------------------------------------------------------------------
//                              Digits Length
//                              -------------
//
// General      : This function calculates the length of a number.
//
// Parameters   : 
//			ptrNum - A pointer (In)
//					
//
// Return Value : A pointer with a value of the number's length.
//
//----------------------------------------------------------------------

int* digitsLength(int* ptrNum)
{
	int tempNumber = *ptrNum;
	int length = ZERO;

	for (; tempNumber; tempNumber /= TEN)
	{
		length++;
	}
	return (&length);
}

//----------------------------------------------------------------------
//                              Sum Digits
//                              ----------
//
// General      : This function calculates the sum of a number's digits
//
// Parameters   : 
//			ptrNum - A pointer (In)
//					
//
// Return Value : A pointer with a value of the number's digits.
//
//----------------------------------------------------------------------

int* sumDigits(int* ptrNum)
{
	int tempNumber = *ptrNum;
	int sum = ZERO;

	for (; tempNumber; tempNumber /= TEN)
	{
		sum += tempNumber % TEN;
	}
	return (&sum);
}

//----------------------------------------------------------------------
//                            Divide Result
//                            -------------
//
// General      : This function calculates the result of a divide.
//
// Parameters   : 
//			ptrNum       - A pointer (In)
//			ptrNumDivide - A pointer (In)		
//
// Return Value : A pointer with a value of the result of the divide,
//                if divider is 0, return -1.
//
//----------------------------------------------------------------------

int* divideResult(int* ptrNum, int* ptrNumDivider)
{
	int tempNumber = *ptrNum;
	int result = ZERO;

	for (; tempNumber >= *ptrNumDivider && *ptrNumDivider; ++result)
	{
		tempNumber -= *ptrNumDivider;
	}

	result = (*ptrNumDivider == ZERO) ? -1 : result;

	return (&result);
}

//----------------------------------------------------------------------
//                           Divide Left Over
//                           ----------------
//
// General      : This function calculates the left over of a divide.
//
// Parameters   : 
//			ptrNum       - A pointer (In)
//			ptrNumDivide - A pointer (In)		
//
// Return Value : A pointer with a value of the left over of the divide.
//
//----------------------------------------------------------------------

int* divideLeftOver(int* ptrNum, int* ptrNumDivider)
{
	int leftOver = *ptrNum % *ptrNumDivider;

	return (&leftOver);
}

//----------------------------------------------------------------------
//                        Convert To Base Ten
//                        -------------------
//
// General      : This function converts from any base to base ten.
//
// Parameters   : 
//			ptrNum  - A pointer with the number value. (In)
//			ptrBase - A pointer with the base value. (In)		
//
// Return Value : A pointer with a value of the number converted
//                to base 10.
//
//----------------------------------------------------------------------

int* convertToBaseTen(int* ptrNum, int* ptrBase)
{
	int baseTenNum = ZERO;
	int multiBaseCounter = ONE;
	int tempNum = *ptrNum;

	for (; tempNum; tempNum /= TEN)
	{
		baseTenNum = baseTenNum * TEN + (tempNum % TEN) * multiBaseCounter;
		multiBaseCounter *= *ptrBase;
	}

	return (&baseTenNum);
}

//----------------------------------------------------------------------
//                           Sum Even Digits
//                           ---------------
//
// General      : This function calculates the sum of even digits.
//
// Parameters   : 
//			ptrNum - A pointer. (In)
//
// Return Value : A pointer with the sum of all even digits on the num. 
//
//----------------------------------------------------------------------

int* sumEvenDigits(int* ptrNum)
{
	int sumEven = ZERO;
	BOOLEAN isEven = isNumberEven(digitsLength(ptrNum));
	int tempNumber = (isEven) ? *ptrNum : *ptrNum * TEN;

	for (; tempNumber; tempNumber /= HUNDRED)
	{
		sumEven += tempNumber % TEN;
	}

	return (&sumEven);
}

//----------------------------------------------------------------------
//                         Make Even Digit Num
//                         --------------------
//
// General      : This function makes an number from even digits in num.
//
// Parameters   : 
//			ptrNum  - A pointer. (In)
//
// Return Value : A pointer with value of a even digit num. 
//
//----------------------------------------------------------------------

int* makeEvenDigitsNum(int* ptrNum)
{
	int newNumber = ZERO;
	BOOLEAN isEven = isNumberEven(digitsLength(ptrNum));
	int tempNumber = *ptrNum;
	flipNumber(&tempNumber);
	(isEven) ? (tempNumber) : (tempNumber /= TEN);

	for (; tempNumber; tempNumber /= HUNDRED)
	{
		newNumber = newNumber * TEN + tempNumber % TEN;
	}

	return &newNumber;
}

//----------------------------------------------------------------------
//                           Sum Odd Digits
//                           ---------------
//
// General      : This function calculates the sum of odd digits.
//
// Parameters   : 
//			ptrNum  - A pointer. (In)
//
// Return Value : A pointer with the sum of all odd digits on the num. 
//
//----------------------------------------------------------------------

int* sumOddDigits(int* ptrNum)
{
	int sumOdd = ZERO;
	BOOLEAN isOdd = *isNumberOdd(digitsLength(ptrNum));
	int tempNumber = (isOdd) ? *ptrNum : *ptrNum / TEN;

	for (; tempNumber; tempNumber /= HUNDRED)
	{
		sumOdd += tempNumber % TEN;
	}

	return (&sumOdd);
}

//----------------------------------------------------------------------
//                         Make Odd Digit Num
//                         --------------------
//
// General      : This function makes an number from odd digits in num.
//
// Parameters   : 
//			ptrNum  - A pointer. (In)
//
// Return Value : A pointer with value of a number made of its odd digit 
//
//----------------------------------------------------------------------

int* makeOddDigitsNum(int* ptrNum)
{
	int newNumber = ZERO;
	int tempNumber = *ptrNum;

	flipNumber(&tempNumber);

	for (; tempNumber; tempNumber /= HUNDRED)
	{
		newNumber = newNumber * TEN + tempNumber % TEN;
	}

	return (&newNumber);
}

//----------------------------------------------------------------------
//                               Power
//                               -----
//
// General      : This function calculates power.
//
// Parameters   : 
//			ptrNumber        - A pointer. (In)
//			ptrNumberOfTimes - A pointer with value of repeats. (In)
//          ptrAnswer        - A pointer to save the answer.    
//
// Return Value : None.
//
//----------------------------------------------------------------------

double power(double* ptrNumber, int numberOfTimes)
{
	double answer = ONE;
	int numberOfTimes = numberOfTimes;

	for (; numberOfTimes; numberOfTimes--)
	{
		answer *= *ptrNumber;
	}

	return (answer);
}

//----------------------------------------------------------------------
//                        Concatenation Numbers
//                        ---------------------
//
// General      : This function combines two numbers into one.
//
// Parameters   : 
//			ptrNumOne - A pointer. (In)
//			ptrNumTwo - A pointer. (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void concatenationNumbers(int* ptrNumOne, int* ptrNumTwo)
{
	int numTwoLength = *digitsLength(ptrNumTwo);
	int flippedNumber = *ptrNumTwo;
	flipNumber(&flippedNumber);

	for (; flippedNumber; flippedNumber /= TEN)
	{
		*ptrNumOne = (*ptrNumOne) * (TEN)+(flippedNumber % TEN);
	}

	return;
}

//----------------------------------------------------------------------
//                                 Copy
//                                 ----
//
// General      : This function copies two strings into one.
//
// Parameters   : 
//			ptrNumOne - A pointer. (In)
//			ptrNumTwo - A pointer. (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void copy(char* ptrNumOne, char* ptrNumTwo)
{
	int numTwoLength = *digitsLength(ptrNumTwo);
	int flippedNumber = *ptrNumTwo;
	flipNumber(&flippedNumber);

	for (; flippedNumber; flippedNumber /= TEN)
	{
		*ptrNumOne = (*ptrNumOne) * (TEN)+(flippedNumber % TEN);
	}

	return;
}

//----------------------------------------------------------------------
//                          Flip Number
//                          -----------
//
// General      : This function flips a number.
//
// Parameters   : 
//			ptrNum - A pointer. (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------


void flipNumber(int* ptrNum)
{
	int flippedNumber = ZERO;

	for (; (*ptrNum); (*ptrNum) /= TEN)
	{
		flippedNumber = flippedNumber * (TEN)+(*ptrNum) % (TEN);
	}
	*ptrNum = flippedNumber;

	return;
}

//----------------------------------------------------------------------
//                             Swap
//                             ----
//
// General      : This function swaps between two places of numbers.
//
// Parameters   : 
//			ptrNumOne - A pointer. (In)
//			ptrNumTwo - A pointer. (In)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void swap(int* ptrNumOne, int* ptrNumTwo)
{
	int tempNumber = *ptrNumOne;
	*ptrNumOne = *ptrNumTwo;
	*ptrNumTwo = tempNumber;

	return;
}

//----------------------------------------------------------------------
//                             isDigitOnNum
//                             ------------
//
// General      : This function checks if there is a digit in a number.
//
// Parameters   : 
//			ptrNum   - A pointer. (In)
//			ptrDigit - The check digit number. (In)
//
// Return Value : Returns a pointer with a value of TRUE if 
//                there is a digit in the numer, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN* isDigitOnNum(int* ptrNum, unsigned short* ptrDigit)
{
	int tempNumber = *ptrNum;
	BOOLEAN isDigitOnNumber = FALSE;

	for (; tempNumber && !isDigitOnNumber; tempNumber /= TEN)
	{
		isDigitOnNumber = (tempNumber % TEN == *ptrDigit) ? TRUE : FALSE;
	}

	return (&isDigitOnNumber);
}


//----------------------------------------------------------------------
//                          Is Number On Number
//                          -------------------
//
// General      : This function checks if there is any similliar digits
//
// Parameters   : 
//			ptrNumOne   - A pointer. (In)
//			ptrNumTwo - The check digit number. (In)
//
// Return Value : Returns a pointer with a value of TRUE if 
//                there is a digit in the numer, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN* isNumberOnNumber(int* ptrNumOne, int* ptrNumTwo)
{
	int            tempNumber = *ptrNumOne;
	BOOLEAN        isNumOnNum = FALSE;
	unsigned short digit;

	for (; tempNumber && !(isNumOnNum); tempNumber /= TEN)
	{
		digit = tempNumber % TEN;
		isNumOnNum = *(isDigitOnNum(ptrNumTwo, &digit));
	}

	return (&isNumOnNum);
}

//----------------------------------------------------------------------
//                          Is Number Prime
//                          ----------------
//
// General      : This function checks if a number is prime.
//
// Parameters   : 
//			ptrNumber   - A pointer. (In)
//
// Return Value : Returns a pointer with a value of TRUE if 
//                the number is prime, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN* isNumberPrime(int* ptrNumber)
{
	int tempNumber = *ptrNumber;
	int primeCounter = sqrt(&tempNumber); // sqrt is a blackbox.
	BOOLEAN isNumPrime = TRUE;

	for (; (primeCounter - ONE) && isNumPrime; primeCounter--)
	{
		isNumPrime = (tempNumber % primeCounter == ZERO) ? FALSE : TRUE;
	}

	return (&isNumPrime);
}

//----------------------------------------------------------------------
//                             Compare
//                             -------
//
// General      : This function compares two strings.
//
// Parameters   : 
//			stringOne - A pointer to string (char*)
//          stringTwo - A pointer to string (char*)
//
// Return Value : TRUE if the strings are the same, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN compare(char* ptrStringOne, char* ptrStringTwo)
{
	while ((*ptrStringOne) == (*ptrStringTwo) && *ptrStringOne != '\0')
	{
		ptrStringOne++;
		ptrStringTwo++;
	}

	return (*ptrStringOne == *ptrStringTwo);
}

//----------------------------------------------------------------------
//                             Cut String
//                             ----------
//
// General      : This function cuts a string into a smaller one.
//
// Parameters   : 
//			ptrStringOne - A pointer to string (char*)
//          cuttedString - A pointer to save the cutted string (char*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void cutString(char* ptrStringOne, char* cuttedString, unsigned short startPlace)
{
	while (*cuttedString != '\0')
	{
		*(cuttedString++) = *(ptrStringOne++ + startPlace);
	}
}

//----------------------------------------------------------------------
//                             Fill String
//                             ----------
//
// General      : This function fills a string with garbage.
//
// Parameters   : 
//			ptrString     - A pointer to string (char*)
//          garbageLength - The number of times to fill the garabage. 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void fillString(char* ptrString, unsigned short garbageLength)
{
	while (garbageLength--)
	{
		*ptrString = GARBAGE;
		ptrString++;
	}
	*ptrString = '\0';
}

//----------------------------------------------------------------------
//                          String Last Address
//                          -------------------
//
// General      : This function calculates the last address of string.
//
// Parameters   : 
//			ptrEndString - A pointer to string (char*)
//
// Return Value : The pointer with an address of the last string.
//
//----------------------------------------------------------------------

char* stringLastAddress(char* ptrEndString)
{
	while (*(++ptrEndString) != '\0');
	return ptrEndString;
}

//----------------------------------------------------------------------
//                          String Length
//                          -------------
//
// General      : This function calculates length of an string.
//
// Parameters   : 
//			ptrStartString - A pointer to string (char*)
//
// Return Value : The length of the string.
//
//----------------------------------------------------------------------

int stringLength(char* ptrStartString)
{
	char* ptrEndString = stringLastAddress(ptrStartString);
	return (ptrEndString - ptrStartString);
}

//----------------------------------------------------------------------
//                      Is Sub String On String
//                      -----------------------
//
// General      : This function checks if an substring on a string.
//
// Parameters   : 
//			ptrString    - A pointer to a string (char*)
//          ptrSubString - A pointer to a substring (char*)
//
// Return Value : Returns TRUE if the substring is on a string,
//                else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSubStringOnString(char* ptrString, char* ptrSubString)
{
	int subStringLength = stringLength(ptrSubString);
	int length = stringLength(ptrString);
	int numOfLoops = length - subStringLength + ONE;
	int position = ZERO;
	BOOLEAN isTrue = FALSE;

	char cuttedString[STRINGMAXSIZE];
	char* ptrCuttedString = &(cuttedString[ZERO]);
	fillString(&cuttedString, subStringLength);

	while (numOfLoops-- && !isTrue)
	{
		cutString(ptrString, ptrCuttedString, position);
		isTrue = compare(ptrSubString, ptrCuttedString);
		position++;
	}

	return (isTrue);
}

//----------------------------------------------------------------------
//                      Sum Sub String On String
//                      -----------------------
//
// General      : This function calcualtes the num of sub strings 
//                on string.
//
// Parameters   : 
//			ptrString    - A pointer to a string (char*)
//          ptrSubString - A pointer to a substring (char*)
//
// Return Value : Returns the sum of sub strings that fit to the string.
//
//----------------------------------------------------------------------

unsigned short sumSubStringsOnString(char* ptrString, char* ptrSubString)
{
	unsigned short subStringLength = stringLength(ptrSubString);
	unsigned short length = stringLength(ptrString);
	unsigned short numOfLoops = length - subStringLength + ONE;
	unsigned short position = ZERO;
	unsigned short sumOfSubStrings = ZERO;

	char cuttedString[STRINGMAXSIZE];
	char* ptrCuttedString = &(cuttedString[ZERO]);
	fillString(&cuttedString, subStringLength);

	while (numOfLoops--)
	{
		cutString(ptrString, ptrCuttedString, position);
		compare(ptrSubString, ptrCuttedString) ? sumOfSubStrings++ : sumOfSubStrings;
		position++;
	}

	return (sumOfSubStrings);
}

//----------------------------------------------------------------------
//                      Is Symbol On String
//                      -------------------
//
// General      : This function checks if an symbol is on a string.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//          symbol    - A symbol (char)
//
// Return Value : Returns TRUE if the symbol is on the string, 
//                else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isSymbolOnString(char* ptrString, char symbol)
{
	while (*ptrString != '\0' && *ptrString != symbol)
	{
		ptrString++;
	}

	return (*ptrString == symbol);
}

//----------------------------------------------------------------------
//                      Sum Symbol On String
//                      --------------------
//
// General      : This function sums a symbol on a string.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//          symbol    - A symbol (char)
//
// Return Value : Returns the number of parmaeter symbol on the string.
//
//----------------------------------------------------------------------

int sumSymbolOnString(char* ptrString, char symbol)
{
	int countSymbols = ZERO;

	while (*ptrString != '\0')
	{
		(*ptrString == symbol) ? countSymbols++ : countSymbols;
		ptrString++;
	}
	return (countSymbols);
}

//----------------------------------------------------------------------
//                    Max Num Of Symbols On String
//                    ----------------------------
//
// General      : This function finds the maximum of a repeating symbol.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//
// Return Value : Returns the number of max repeating symbol.
//
//----------------------------------------------------------------------

int maxNumOfSymbolsOnString(char* ptrString)
{
	int tempNumber = ZERO;
	int maxNumOfSymbols = sumSymbolOnString(ptrString, *ptrString);

	while (*ptrString != '\0')
	{
		tempNumber = sumSymbolOnString(ptrString, *ptrString);
		maxNumOfSymbols = (maxNumOfSymbols > tempNumber) ? maxNumOfSymbols : tempNumber;
		ptrString++;
	}

	return (maxNumOfSymbols);
}

//----------------------------------------------------------------------
//                            Clear String
//                            ------------
//
// General      : This function clears a string.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void clearString(char* ptrString) {
	char cleanedString[STRINGMAXSIZE];
	char* ptrCleanedString = &(cleanedString[ZERO]);

	while (ptrString++ != '\0')
	{
		(*ptrString != GARBAGE) ? (*(ptrCleanedString++) = *ptrString) : ptrString;
	}
}

//----------------------------------------------------------------------
//                      Delete Symbol From String
//                      -------------------------
//
// General      : This function deletes a symbol on a string.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//          symbol    - A symbol to delete (char)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteSymbolFromString(char* ptrString, char symbol)
{
	while (*ptrString != '\0')
	{
		(*ptrString) = (*ptrString == symbol) ? GARBAGE : *ptrString;
		ptrString++;
	}
	return;
}

//----------------------------------------------------------------------
//                      Delete String From String
//                      -------------------------
//
// General      : This function deletes a string on a string.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//          ptrDeleteFromString  - A pointer ot a string to delete
//                                 from the string. (char)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteStringFromString(char* ptrString, char* ptrDeleteFromString)
{
	while (*ptrDeleteFromString != '\0')
	{
		deleteSymbolFromString(ptrString, *ptrDeleteFromString);
		ptrDeleteFromString++;
	}
	return;
}

//----------------------------------------------------------------------
//                    Sum Delete String From String
//                    -----------------------------
//
// General      : This function deletes a string from a string and sums
//                the amount that have been deleted.
//
// Parameters   : 
//			ptrString - A pointer to a string (char*)
//          ptrDeleteFromString  - A pointer ot a string to delete
//                                 from the string. (char)
//
// Return Value : The num of symbols that have been deleted.
//
//----------------------------------------------------------------------

int sumDeleteStringFromString(char* ptrString, char* ptrDeleteFromString)
{
	deleteStringFromString(ptrString, ptrDeleteFromString);
	return (sumSymbolOnString(ptrString, GARBAGE));
}

//----------------------------------------------------------------------
//                                itoa
//                                ----
//
// General      : This function converts from int to ascii code.
//
// Parameters   : 
//			num - A pointer to a number (int*)
//
// Return Value : The char in ascii code.
//
//----------------------------------------------------------------------

char itoa(int* num)
{
	return (char)(*num);
}

//----------------------------------------------------------------------
//                          isStringAsSubStringOnMatriza
//                          ----------------------------
//
// General      : This function checks if a string on matriza is a 
//                sub string of another string on the matriza.
//
// Parameters   : 
//			ptrMatriza - A pointer to matriza of strings (char*)
//
// Return Value : Returns TRUE if there is a string that is another 
//                string's substring, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isStringASubStringOnMatriza(char* ptrMatriza)
{
	char* ptrMatLastAddress = ptrMatriza + MAXSIZECOL * MAXSIZEROW;
	char* tempPointer;
	char* tempString = ptrMatriza;
	BOOLEAN isTrue = FALSE;

	while (ptrMatriza++ != ptrMatLastAddress && !isTrue)
	{
		*tempString = *ptrMatriza;
		tempPointer = ptrMatriza + ONE;
		while (tempPointer++ != ptrMatLastAddress && !isTrue)
		{
			isTrue = isSubStringOnString(tempString, tempPointer) ? TRUE : isTrue;
		}
	}

	return (isTrue);
}

char* lastAddressWordFromString(char* ptrLastAddressWord)
{
	while (*(ptrLastAddressWord++) != GARBAGE);
	return ptrLastAddressWord;
}
