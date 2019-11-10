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

BOOLEAN* isNumberEven(int* ptrNum)
{
	BOOLEAN isNumberEven = *ptrNum % TWO;

	return (&isNumberEven);
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
	BOOLEAN isEven = *isNumberEven(digitsLength(ptrNum));
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
	BOOLEAN isEven = *isNumberEven(digitsLength(ptrNum));
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

void power(double* ptrNumber, int* ptrNumberOfTimes, double* answer)
{
	*answer = ONE;
	int numberOfTimes = *ptrNumberOfTimes;

	for (numberOfTimes; numberOfTimes; numberOfTimes--)
	{
		*answer *= *ptrNumber;
	}

	return;
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
//                          isNumberOnNumber
//                          ----------------
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

void cutString(char* ptrStringOne, char* cuttedString, unsigned short startPlace)
{
	while (*cuttedString != '\0')
	{
		*(cuttedString++) = *(ptrStringOne++ + startPlace);
	}
}

void fillString(char* ptrString, unsigned short garbageLength)
{
	while (garbageLength--)
	{
		*ptrString = GARBAGE;
		ptrString++;
	}
	*ptrString = '\0';
}

char* stringLastAddress(char* ptrEndString)
{
	while (*(++ptrEndString) != '\0');
	return ptrEndString;
}

int stringLength(char* ptrStartString)
{
	char* ptrEndString = stringLastAddress(ptrStartString);
	return (ptrEndString - ptrStartString);
}

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

BOOLEAN isSymbolOnString(char* ptrString, char symbol)
{
	while (*ptrString != '\0' && *ptrString != symbol)
	{
		ptrString++;
	}
	
	return (*ptrString == symbol);
}

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

void clearString(char* ptrString){
	char cleanedString[STRINGMAXSIZE];
	char* ptrCleanedString = &(cleanedString[ZERO]);

	while(ptrString++ != '\0')
	{
		(*ptrString != GARBAGE) ? (*(ptrCleanedString++) = *ptrString) : ptrString;
	}
}


char itoa(int* num)
{
	return (char)(*num);
}

void main(void)
{
	typedef char STRING[STRINGMAXSIZE];

	STRING stringOne = { 'A','D','@', 'D', '@', '@','B', 'C', 'A', 'B', 'A', 'L'};
	STRING stringCutted = { 'A','B','C'};
	STRING testString;
	
	int testNum = 119;

	printf("%hu", isSymbolOnString(&stringOne, "L"));

	scanf("%hu", &testNum);
}