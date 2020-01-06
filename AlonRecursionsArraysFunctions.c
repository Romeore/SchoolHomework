//AlonRecursionsArray.c

#include "AlonRecursionsArraysFunctions.h"

//----------------------------------------------------------------------
//                     Mul All Numbers Array Recursion
//                     -------------------------------
//
// General      : This function calculates the multiplication of all
//                numbers in the array.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the multiplication of all numbers in the array
//
//----------------------------------------------------------------------

int mulAllNumbersArrayRecursion(int* ptrArray, int size)
{
	if (size == ZERO)
	{
		return (ONE);
	}

	return (*(ptrArray + size) 
		* mulAllNumbersArrayRecursion(ptrArray, --size));
}

//----------------------------------------------------------------------
//                     Min Value Array Recursion
//                     -------------------------
//
// General      : This function finds the minimum value of the array.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the minimum number in the array.
//
//----------------------------------------------------------------------

int minValueArrayRecursion(int* ptrArray, int size)
{
	if (size == ONE)
	{
		return (*ptrArray);
	}

	return (MIN(*(ptrArray + size),
		minValueArrayRecursion(ptrArray, --size)));
}

//----------------------------------------------------------------------
//                     sum Value Array Recursion
//                     -------------------------
//
// General      : This function calculates the sum of all numbers in 
//                the array.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the sum of all numbers in an array.
//
//----------------------------------------------------------------------

int sumValueArrayRecursion(int* ptrArray, int size)
{
	if (size == ZERO)
	{
		return (ZERO);
	}

	return (*(ptrArray + size) 
		+ sumValueArrayRecursion(ptrArray, --size));
}

//----------------------------------------------------------------------
//                  Sum Values Even Places Array Recursion
//                  --------------------------------------
//
// General      : This function calculates the sum of the even places in
//                the array.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the sum of the even places in the array.
//
//----------------------------------------------------------------------

int sumValuesEvenPlacesArrayRecursion(int* ptrArray, int size)
{
	if (size == ZERO)
	{
		return (ZERO);
	}

	if (size % TWO == ZERO)
	{
		return (*(ptrArray + size) 
			+ sumValuesEvenPlacesArrayRecursion(ptrArray, --size));
	}

	return (sumValuesEvenPlacesArrayRecursion(ptrArray, --size));
}

//----------------------------------------------------------------------
//                  Sum Values Odd Places Array Recursion
//                  --------------------------------------
//
// General      : This function calculates the sum of the odd places in
//                the array.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the sum of the odd places in the array.
//
//----------------------------------------------------------------------

int sumValuesOddPlacesArrayRecursion(int* ptrArray, int size)
{
	if (size == ZERO)
	{
		return (ZERO);
	}

	if (size % TWO != ZERO)
	{
		return (*(ptrArray + size)
			+ sumValuesOddPlacesArrayRecursion(ptrArray, --size));
	}
	
	return (sumValuesOddPlacesArrayRecursion(ptrArray, --size));
}

//----------------------------------------------------------------------
//                  Difference Odd And Even Array Recursion
//                  ---------------------------------------
//
// General      : This function calculates the difference between even
//                and odd places in the array.  
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the difference between even and odd places in
//                the array.
//
//----------------------------------------------------------------------

int differenceOddAndEvenArrayRecursion(int* ptrArray, int size)
{
	if (size == ZERO)
	{
		return (ZERO);
	}

	if (size % TWO == ZERO)
	{
		return (*(ptrArray + size)
			+ differenceOddAndEvenArrayRecursion(ptrArray, --size));
	}
	
	return (differenceOddAndEvenArrayRecursion(ptrArray, --size)
		- *(ptrArray + size));
}

//----------------------------------------------------------------------
//                         Average Array Recursion
//                         -----------------------
//
// General      : This function calculates the average of the array.  
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns the average of the array.
//
//----------------------------------------------------------------------

int averageArrayRecursion(int* ptrArray, int size)
{
	return (sumValueArrayRecursion(ptrArray, size) / size);
}

//----------------------------------------------------------------------
//                    Is Palindrome Array Recursion Helper
//                    ------------------------------------
//
// General      : This function checks if the array is palindrome.  
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns TRUE if the array is palindrome, else FALSE.
//

//----------------------------------------------------------------------
BOOLEAN isPalindromeArrayRecursionHelper(int* ptrArray, int* ptrEndArray)
{
	if (ptrArray > ptrEndArray)
	{
		return (TRUE);
	}

	return (*ptrArray == *ptrEndArray)
		&& isPalindromeArrayRecursionHelper(++ptrArray, --ptrEndArray);
}

//----------------------------------------------------------------------
//                      Is Palindrome Array Recursion
//                      -----------------------------
//
// General      : This function checks if the array is palindrome.  
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//
// Return Value : returns TRUE if the array is palindrome, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isPalindromeArrayRecursion(int* ptrArray, int size)
{
	int* ptrEndArray = ptrArray + --size;

	return (isPalindromeArrayRecursionHelper(ptrArray, ptrEndArray));
}

//----------------------------------------------------------------------
//                      Is Mirror Array Recursion Helper
//                      --------------------------------
//
// General      : This function checks if the array is a mirror array.  
//
// Parameters   : 
//			ptrArray    - a pointer to array. (Int*)
//          ptrEndArray - a pointer to the end of the array. (Int*) 
//          size        - the size of the array. (Int)
//
// Return Value : returns TRUE if the array is a mirror, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isMirrorArrayRecursionHelper(int* ptrArray, int* ptrEndArray, int size)
{
	if (ptrArray + size == ptrEndArray)
	{
		return (TRUE);
	}

	return (*ptrArray == *ptrEndArray)
		&& isMirrorArrayRecursionHelper(++ptrArray, ++ptrEndArray, --size);
}

//----------------------------------------------------------------------
//                      Is Mirror Array Recursion
//                      -------------------------
//
// General      : This function checks if the array is a mirror array.
//
// Parameters   : 
//			ptrArray    - a pointer to array. (Int*)
//          size        - the size of the array. (Int)
//
// Return Value : returns TRUE if the array is a mirror, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isMirrorArrayRecursion(int* ptrArray, int size)
{
	int* ptrEndArray = ptrArray + (size / TWO);

	return (isMirrorArrayRecursionHelper(ptrArray, ptrEndArray, size));
}

//----------------------------------------------------------------------
//                 Is Array Arithmetic Progression Recursion
//                 -----------------------------------------
//
// General      : This function checks if the array is a arithmetic
//                progression.
//
// Parameters   : 
//			ptrArray    - a pointer to array. (Int*)
//          size        - the size of the array. (Int)
//
// Return Value : returns TRUE if the array is a arithmetic progression, 
//                else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isArrayArithmeticProgressionRecursion(int* ptrArray, int size)
{
	if (size == TWO)
	{
		return (TRUE);
	}

	// The formula of arithmetic progression is 2(an+1) = (an) + (an + 2)
	return (((TWO * *(ptrArray + ONE)) == (*ptrArray + *(ptrArray + TWO))) 
		&& isArrayArithmeticProgressionRecursion(++ptrArray, --size));
}

//----------------------------------------------------------------------
//                 Is Exists Two Values Larger Than Distance
//                 -----------------------------------------
//
// General      : This function checks if two values that have larger
//                distance than a parameter.
//
// Parameters   : 
//			ptrArray - a pointer to array. (Int*)
//          size     - the size of the array. (Int)
//          distance - the distance between two values. (Int)
//
// Return Value : returns TRUE if the the two values exists, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isExistsTwoValuesLargerThanDistance(int* ptrArray, int size,
	                                        int distance)
{
	int counter;
	BOOLEAN isExists = FALSE;

	if (size == ONE)
	{
		return (FALSE);
	}
	
	for (counter = ZERO; (counter < size) * !isExists; counter++)
	{
		((ABS(*(ptrArray) - *(ptrArray + counter))) > TEN) ? 
			(isExists = TRUE) : (isExists);
	}

	return ((isExistsTwoValuesLargerThanDistance(++ptrArray, --size)) 
		|| (isExists));
}
