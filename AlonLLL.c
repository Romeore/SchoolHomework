//AlonLLL.c
#pragma once

#include "AlonLLL.h"

//----------------------------------------------------------------------
//                            Init LLLChar
//                            -------------
//
// General      : This function initilaizes LLLChar.
//
// Parameters   : 
//			manager - A pointer to the manager (LLLChar**)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initLLLChar(LLLChar** manager)
{
	(*manager)->nextAddress = NULL;

	return;
}

//----------------------------------------------------------------------
//                          Insert After LLLChar
//                          --------------------
//
// General      : This function adds LLLChar node to the LLLChar.
//
// Parameters   : 
//			ptrAddAfter - A pointer to a node that after it, the node
//                        will be added (LLLChar*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertAfterLLLChar(LLLChar* ptrAddAfter)
{
	LLLChar* temp = ptrAddAfter->nextAddress;
	LLLChar* newCharLLL = (LLLChar*)malloc(sizeof(LLLChar));
	ptrAddAfter->nextAddress = newCharLLL->nextAddress;
	newCharLLL->nextAddress = temp;

	return;
}

//----------------------------------------------------------------------
//                          Delete After LLLChar
//                          --------------------
//
// General      : This function deletes LLLChar node from the LLLChar.
//
// Parameters   : 
//			ptrDeleteAfter - A pointer to a node that after it, the node
//                        will be removed (LLLChar*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteAfterLLLChar(LLLChar* ptrDeleteAfter)
{
	LLLChar* temp = ptrDeleteAfter->nextAddress->nextAddress;
	free(ptrDeleteAfter->nextAddress);
	ptrDeleteAfter->nextAddress = temp;
	
	return;
}

//----------------------------------------------------------------------
//                              Pop LLLChar
//                              -----------
//
// General      : This function deletes the manager from the LLLChar.
//
// Parameters   : 
//			manager - A pointer to the manager (LLLChar**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void popLLLChar(LLLChar** manager)
{
	LLLChar*  saveManager = *manager;
	LLLChar*  newManager = (*manager)->nextAddress;
	free(saveManager);

	return;
}

//----------------------------------------------------------------------
//                              Push LLLChar
//                              ------------
//
// General      : This function adds a new manager to the LLLChar.
//
// Parameters   : 
//			manager - A pointer to the manager (LLLChar**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void pushLLLChar(LLLChar** manager)
{
	LLLChar* oldManager = (LLLChar*)malloc(sizeof(LLLChar));
	oldManager = *manager;
	(*manager)->nextAddress = oldManager;

	return;
}

//----------------------------------------------------------------------
//                          Longest LLLChar Word
//                          --------------------
//
// General      : This function finds the longest word in the LLLChar.
//
// Parameters   : 
//			lllCharPtr - A pointer to a node (LLLChar*) 
//
// Return Value : The node that the longest word starts from.
//
//----------------------------------------------------------------------

LLLChar* longestLLLCharWord(LLLChar* lllCharPtr)
{
	LLLChar* longestLLLCharWord = lllCharPtr;
	LLLChar* tempLLLCharWordStart = lllCharPtr;

	int      tempWordLength = ONE;
	int      maxWordLength = ONE;

	while (lllCharPtr != NULL)
	{
		if (lllCharPtr->info == '*')
		{
			if (tempWordLength > maxWordLength)
			{
				longestLLLCharWord = tempLLLCharWordStart;
			}
			tempLLLCharWordStart = lllCharPtr->nextAddress;
			tempWordLength = ZERO;
		}
		tempWordLength++;
		lllCharPtr = lllCharPtr->nextAddress;
	}

	return (longestLLLCharWord);
}

//----------------------------------------------------------------------
//                         Delete Symbol From LLLChar
//                         --------------------------
//
// General      : This function finds deletes symbols from LLLChar
//
// Parameters   : 
//			deleteAfterPtr - A pointer to a node (LLLChar*)
//          symbol         - the symbol to delete from the LLLChar.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteSymbolFromLLLChar(LLLChar* deleteAfterPtr, char symbol)
{
	while (deleteAfterPtr != NULL)
	{
		(deleteAfterPtr->nextAddress->info == symbol) ?
			(deleteAfterLLLChar(deleteAfterPtr)) :
			(deleteAfterPtr = deleteAfterPtr->nextAddress);
	}

	return;
}
