//AlonCLLL.c
#pragma once

#include "AlonCLLL.h"

//----------------------------------------------------------------------
//                          Insert Last CLLL
//                          ----------------
//
// General      : This function adds CLLL node (Nodes size = 1).
//
// Parameters   : 
//			manager - A pointer to the manager(CLLL**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertLastCLLL(CLLL** manager)
{
	CLLL* newNode = (CLLL*)malloc(sizeof(CLLL));
	
	(*manager) = newNode;
	(*manager)->nextAddress = newNode;

	return;
}

//----------------------------------------------------------------------
//                          Insert After CLLL
//                          -----------------
//
// General      : This function adds CLLL node.
//
// Parameters   : 
//			ptrAddAfter - A pointer to a CLL to add after it(CLLL*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertAfterCLLL(CLLL* ptrAddAfter)
{
	CLLL* newNode = (CLLL*)malloc(sizeof(CLLL));
	CLLL* temp = ptrAddAfter->nextAddress;
	ptrAddAfter->nextAddress = newNode;
	newNode->nextAddress = temp;

	return;
}

//----------------------------------------------------------------------
//                          Insert End CLLL
//                          ---------------
//
// General      : This function adds CLLL node to the end of CLLL.
//
// Parameters   : 
//			manager - A pointer to the manager(CLLL**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertEndCLLL(CLLL** manager)
{
	CLLL* newNode = (CLLL*)malloc(sizeof(CLLL));
	CLLL* temp = (*manager)->nextAddress;
	(*manager)->nextAddress = newNode;
	newNode->nextAddress = temp;
	
	return;
}

//----------------------------------------------------------------------
//                          Delete After CLLL
//                          -----------------
//
// General      : This function deletes CLLL node.
//
// Parameters   : 
//			ptrDeleteAfter - A pointer to a CLL to delete after it(CLLL*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteAfterCLLL(CLLL* ptrDeleteAfter)
{
	CLLL* temp = ptrDeleteAfter->nextAddress->nextAddress;
	free(ptrDeleteAfter->nextAddress);
	ptrDeleteAfter->nextAddress = temp;

	return;
}

//----------------------------------------------------------------------
//                          Deletes Last CLLL
//                          -----------------
//
// General      : This function deletes CLLL node (Nodes size = 1).
//
// Parameters   : 
//			manager - A pointer to the manager(CLLL**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteLastCLLL(CLLL** manager)
{
	free((*manager)->nextAddress);

	return;
}

//----------------------------------------------------------------------
//                          Delete End CLLL
//                          ---------------
//
// General      : This function delete CLLL node from the end of CLLL.
//
// Parameters   : 
//			manager        - A pointer to the manager(CLLL**)
//			ptrDeleteAfter - A pointer to a CLL to delete after it(CLLL*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteEndCLLL(CLLL** manager, CLLL* ptrDeleteAfter)
{
	CLLL* temp = ptrDeleteAfter->nextAddress->nextAddress;
	free(ptrDeleteAfter->nextAddress);
	ptrDeleteAfter->nextAddress = temp;
	(*manager) = ptrDeleteAfter;

	return;
}

//----------------------------------------------------------------------
//                          Is Empty CLLL
//                          -------------
//
// General      : This function checks if the CLL is empty.
//
// Parameters   : 
//			manager - the value of manager(CLLL*)
//
// Return Value : returns TRUE if the CLLL is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isEmptyCLLL(CLLL* manager)
{
	return (manager->nextAddress == manager);
}

//----------------------------------------------------------------------
//                          Find CLLL
//                          ---------
//
// General      : This function finds a CLLL node with specific info.
//
// Parameters   : 
//			ptrNode - A pointer to a node to change if found (CLLL**)
//          info    - A number to search (int)
//
// Return Value : returns TRUE if the info is found, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN findCLLL(CLLL** ptrNode, int info)
{
	CLLL* ptrSave = *ptrNode;
	BOOLEAN isFound = FALSE;

	(*ptrNode) = ((*ptrNode)->nextAddress);

	while ((*ptrNode) != ptrSave && !isFound)
	{
		((*ptrNode)->info == info) ? 
			(isFound = TRUE) : (*ptrNode = (*ptrNode)->nextAddress);
	}

	return (isFound);
}

//----------------------------------------------------------------------
//                          Sum Info CLLL
//                          -------------
//
// General      : This function sums CLLL info.
//
// Parameters   : 
//			manager - The value of manager (CLLL*)
//
// Return Value : returns the sum of the info of the CLL.
//
//----------------------------------------------------------------------

int sumInfoCLLL(CLLL* manager)
{
	int sumInfo = manager->info;
	CLLL* eodManager = manager;
	manager = manager->nextAddress;

	while (manager != eodManager)
	{
		sumInfo += manager->info;
		manager = manager->nextAddress;
	}

	return (sumInfo);
}

//----------------------------------------------------------------------
//                          Length CLLL
//                          -----------
//
// General      : This function calculates the length of CLLL.
//
// Parameters   : 
//			manager - The value of manager (CLLL*)
//
// Return Value : returns the length of the CLLL.
//
//----------------------------------------------------------------------

int lengthCLLL(CLLL* manager)
{
	int counter;
	CLLL* eodManager = manager;
	
	counter = (isEmptyCLLL(manager)) ? ZERO : ONE;
	manager = manager->nextAddress;

	while (manager != eodManager)
	{
		counter++;
		manager = manager->nextAddress;
	}

	return (counter);
}

//----------------------------------------------------------------------
//                       Num Of Info Appends CLL
//                       -----------------------
//
// General      : This function calculates the amount of times
//                specific info appends in the CLL.
//
// Parameters   : 
//			manager - The value of manager (CLLL*)
//          info    - The info to check(int).
//
// Return Value : returns the number of appends of the info in the CLLL.
//
//----------------------------------------------------------------------

int numOfInfoAppendsCLLL(CLLL* manager, int info)
{
	int numOfAppends;
	CLLL* eodManager = manager;

	numOfAppends = (manager->info == info) ? ONE : ZERO;
	manager = manager->nextAddress;

	while (manager != eodManager)
	{
		(manager->info == info) ? numOfAppends++ : numOfAppends;
	}

	return (numOfAppends);
}

//----------------------------------------------------------------------
//                       Move Number Of Times CLLL
//                       -------------------------
//
// General      : This function moves the pointer number of times in 
//                the CLLL.
//
// Parameters   : 
//			ptrToMove - A pointer to move number of times(CLLL**)
//          numToMove - number of times to move(int).
//
// Return Value : None.
//
//----------------------------------------------------------------------

void moveNumberOfTimesCLLL(CLLL** ptrToMove, int numToMove)
{
	for (; numToMove; numToMove--)
	{
		(*ptrToMove) = (*ptrToMove)->nextAddress;
	}

	return;
}

//----------------------------------------------------------------------
//                             Sum Two CLLL
//                             ------------
//
// General      : This function makes new CLLL from 2 CLL.
//
// Parameters   : 
//			managerOne - The value of the first CLLL manager(CLLL*)
//          managerTwo - The value of the second CLLL manager(CLLL*).
//
// Return Value : returns a new CLLL that each node contains the sum
//                of the managerOne and managerTwo as described in 
//                exercise number 1.
//
//----------------------------------------------------------------------

CLLL** sumTwoCLLL(CLLL* managerOne, CLLL* managerTwo)
{
	int length = lengthCLLL(managerOne);
	int numToMove = length - ONE;
	int numOfTimes;
	CLLL** managerThree;

	insertLastCLLL(managerThree);
	(*managerThree)->info = managerOne->info + managerTwo->nextAddress->info;

	managerOne = managerOne->nextAddress;
	moveNumberOfTimesCLLL(&managerOne, numToMove);

	for (numOfTimes = numToMove; numOfTimes; numOfTimes--)
	{
		insertEndCLLL(managerThree);
		(*managerThree)->info = managerOne->info + managerTwo->nextAddress->info;
		
		managerOne = managerOne->nextAddress;
		moveNumberOfTimesCLLL(&managerOne, numToMove);
	}

	return (managerThree);
}

//----------------------------------------------------------------------
//                        Num Of SubStrings CLLLString
//                        ----------------------------
//
// General      : This function makes new CLLString from CLLString
//                as described in execrise number two.
//
// Parameters   : 
//			manager - The value of the manager(CLLLString*)
//          subString  - The substring to sum (char*).
//
// Return Value : returns a new CLLL that each node contains the number
//                of substrings in the exact same place in the CLLString
//
//----------------------------------------------------------------------

CLLL** numOfSubStringsCLLLString(CLLLString* manager, char* subString)
{
	int countApperance;

	CLLLString* eod = manager;
	CLLL** newManager;

	countApperance = sumSubStringOnString(manager->info, subString);
	insertLastCLLL(newManager);
	(*newManager)->info = countApperance;

	manager = manager->nextAddress;

	while (manager != eod)
	{
		countApperance = sumSubStringOnString(manager->info, subString);
		insertEndCLLL(newManager);
		(*newManager)->info = countApperance;
		manager = manager->nextAddress;
	}

	return (newManager);
}
