//AlonRecursions.c

#include "AlonRecursions.h"

//----------------------------------------------------------------------
//                          Find Max Digit
//                          --------------
//
// General      : This function finds the max digit in a number.
//
// Parameters   : 
//			num - a number(Int)
//
// Return Value : returns the max digit in the number.
//
//----------------------------------------------------------------------

int findMaxDigit(int num)
{
	if (num < TEN)
	{
		return (num);
	}

	return (MAX(findMaxDigit(num / TEN), num % TEN));
}

//----------------------------------------------------------------------
//                          Difference Length
//                          -----------------
//
// General      : This function calculates the difference between two
//                numbers length.
//
// Parameters   : 
//			numOne - a number(Int)
//          numTwo - a number(Int)
//
// Return Value : returns the difference between two numbers length.
//
//----------------------------------------------------------------------

int differenceLength(int numOne, int numTwo)
{
	if (!numOne && !numTwo)
	{
		return (ZERO);
	}

	return (differenceLength(numOne / TEN, numTwo / TEN) +
		((!numOne) || (!numTwo)));
}

//----------------------------------------------------------------------
//                        Difference Digits Values
//                        ------------------------
//
// General      : This function calculates the absolute difference
//                between two numbers digits.
//
// Parameters   : 
//			numOne - a number(Int)
//          numTwo - a number(Int)
//
// Return Value : returns absolute difference between two numbers digits.
//
//----------------------------------------------------------------------

int differenceDigitsValues(int numOne, int numTwo)
{
	if (!numOne && !numTwo)
	{
		return ZERO;
	}

	return (differenceDigitsValues(numOne / TEN, numTwo / TEN)
		+ (ABS(numOne % TEN - numTwo % TEN)));
}

//----------------------------------------------------------------------
//                          Sum Even Odd Difference
//                          -----------------------
//
// General      : This function sums the difference between odd and
//                even digits in a number.
//
// Parameters   : 
//			num - a number(Int)
//
// Return Value : returns difference between odd and even digits in 
//                a number
//
//----------------------------------------------------------------------

int sumEvenOddDifference(int num)
{
	if (num < TEN)
	{
		return ((isEven(num)) ? (num % TEN) : (-(num % TEN)));
	}

	return (sumEvenOddDifference(num / TEN) +
		((isEven(num)) ? (num % TEN) : (-(num % TEN))));
}

//----------------------------------------------------------------------
//                               Sum Digits
//                               ----------
//
// General      : This function calculates the sum of the digits in a
//                number.
//
// Parameters   : 
//			num - a number(Int)
//
// Return Value : returns the sum of the digits in a number.
//
//----------------------------------------------------------------------

int sumDigits(int num)
{
	if (num < TEN)
	{
		return num;
	}

	return (sumDigits(num / TEN) + num % TEN);
}

//----------------------------------------------------------------------
//                             Digits Length
//                             -------------
//
// General      : This function calculates the digits length in a number.
//
// Parameters   : 
//			num - a number(Int)
//
// Return Value : returns the digits length in a number.
//
//----------------------------------------------------------------------

int digitsLength(int num)
{
	if (num < TEN)
	{
		return ONE;
	}

	return (digitsLength(num / TEN) + ONE);
}

//----------------------------------------------------------------------
//                              Concatenation
//                              -------------
//
// General      : This function concatenate two numbers.
//
// Parameters   : 
//			numOne - the number to concatenate to(Int)
//          numTwo - the number to concatenate from(Int)
//
// Return Value : returns the concatenation between two numbers.
//
//----------------------------------------------------------------------

int concatenation(int numOne, int numTwo)
{
	if (numTwo < TEN)
	{
		return (numOne * TEN + numTwo);
	}

	return ((concatenation(numOne, numTwo / TEN) * TEN) + (numTwo % TEN));
}

//----------------------------------------------------------------------
//                             Average Digits
//                             --------------
//
// General      : This function calculates the average of digits in 
//                a number.
//
// Parameters   : 
//			num - a number(Int)
//
// Return Value : returns the average of the digits in a number.
//
//----------------------------------------------------------------------

double averageDigits(int num)
{
	double average = (sumDigits(num)) / (digitsLength(num));

	return (average);
}

//----------------------------------------------------------------------
//                             Is Prime Check
//                             --------------
//
// General      : This function checks if a number is a prime.
//
// Parameters   : 
//			num          - the number to check(Int)
//          primeChecker - the divider to check if its prime(Int)
//
// Return Value : returns TRUE if the number is prime, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isPrimeCheck(int num, int primeChecker)
{
	if (primeChecker * primeChecker > num)
	{
		return TRUE;
	}

	return ((num % primeChecker != ZERO) && isPrimeCheck(num, ++primeChecker));
}

//----------------------------------------------------------------------
//                                Is Prime
//                                --------
//
// General      : This function checks if a number is a prime.
//
// Parameters   : 
//			num - the number to check(Int)
//
// Return Value : returns TRUE if the number is prime, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isPrime(int num)
{
	if (num == ONE || num == TWO)
		return TRUE;
	return (isPrimeCheck(num, TWO));
}

//----------------------------------------------------------------------
//                        Print Prime Dividers Helper
//                        ---------------------------
//
// General      : This function prints prime dividers of a number
//
// Parameters   : 
//			num          - the number to check its prime dividers(Int)
//          primeDivider - the start of prime dividers to check(Int) 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printPrimeDividersHelper(int num, int primeDivider)
{
	if (primeDivider * TWO > num)
	{
		return;
	}

	if (isPrime(primeDivider) && num % primeDivider == ZERO)
	{
		printf("\n%d\n", primeDivider);
	}
	return (printPrimeDividersHelper(num, ++primeDivider));
}

//----------------------------------------------------------------------
//                        Print Prime Dividers
//                        --------------------
//
// General      : This function prints prime dividers of a number
//
// Parameters   : 
//			num          - the number to check its prime dividers(Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printPrimeDividers(int num)
{
	printf("\n1\n");
	return (printPrimeDividersHelper(num, TWO));
}
