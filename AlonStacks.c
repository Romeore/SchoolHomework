//AlonStacks.c
#pragma once

#include "AlonStacks.h"

//----------------------------------------------------------------------
//                              Pop Stack
//                              ---------
//
// General      : This functions removes a item from the stack and
//                returns its value.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)					
//
// Return Value : The last item in stack. 
//
//----------------------------------------------------------------------

Item popStack(Stack* ptrStack) {
	Item value = ptrStack->startStack[ptrStack->offset];
	ptrStack->startStack->address = EMPTY;
	ptrStack->startStack->value = EMPTY;
	// blackbox change offset.
	// Binary that if its zero, stay in zero.
	ptrStack->offset = (ptrStack->offset == ZERO) ? ptrStack->offset : ptrStack->offset-- ;
	return value;
}

//----------------------------------------------------------------------
//                              Pop Stack
//                              ---------
//
// General      : This functions adds a item to the last place in stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)		
//          valuePtr - A pointer to item  (Item*)
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void pushStack(Stack* ptrStack, Item* valuePtr) {
	(ptrStack->offset != MAXSIZE) ? 
		(ptrStack->startStack[++ptrStack->offset] = *valuePtr) : *valuePtr;
}

//----------------------------------------------------------------------
//                             Is Stack Empty
//                              ---------
//
// General      : This functions checks if the stack is empty.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)		
//
// Return Value : Returns TRUE if the stack is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isStackEmpty(Stack* ptrStack) {
	return (ptrStack->startStack[ZERO].address == EMPTY);
}


//----------------------------------------------------------------------
//                             Num That Flips Stack
//                             --------------------
//
// General      : This functions solves exercise number one.
//
// Parameters   : 
//			stack - A  stack (Stack)		
//
// Return Value : Returns the number that flips between order up
//                and order down.
//
//----------------------------------------------------------------------

int numThatFlipsStack(Stack stack) {
	Item tempNum;
	Item returnedNum = popStack(&stack);
	BOOLEAN foundNumber = FALSE;
	
	while (!isStackEmpty(&stack) && foundNumber) {
		tempNum = popStack(&stack);
		(tempNum.value > returnedNum.value) ?
			(returnedNum.value = tempNum.value) : (foundNumber = TRUE);
	}

	return (returnedNum.value);
}

//----------------------------------------------------------------------
//                             Num That Flips Stack
//                             --------------------
//
// General      : This functions solves exercise number one.
//
// Parameters   : 
//			stack - A  stack (Stack)		
//
// Return Value : Returns the place of the number that flips between 
//                order up and order down.
//
//----------------------------------------------------------------------

int placementThatFlipsStack(Stack stack) {
	Item    tempNum;
	Item    maxNum = popStack(&stack);
	BOOLEAN foundNumber = FALSE;
	int  stackCounter = ZERO;

	while (!isStackEmpty(&stack) && !foundNumber) {
		tempNum = popStack(&stack);
		(tempNum.value > maxNum.value) ?
			stackCounter++ : (foundNumber = TRUE);
		maxNum = tempNum;
	}

	return (stackCounter);
}

//----------------------------------------------------------------------
//                             Push Stack In Stack
//                             --------------------
//
// General      : This functions pushes the one stack into another.
//
// Parameters   : 
//			ptrStack    - A pointer to stack (Stack*)
//          pushedStack - A pointer to stack that pushing into the stack
//
// Return Value : None.
//
//----------------------------------------------------------------------

void pushStackInStack(Stack* ptrStack, Stack* pushedStack) {
	Item tempItem;

	while (!isStackEmpty(pushedStack))
	{
		tempItem = popStack(pushedStack);
		pushStack(ptrStack, &tempItem);
	}
}

//----------------------------------------------------------------------
//                           Delete Nums From Stack
//                           ----------------------
//
// General      : This functions deletes a number from a stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)
//          value    - A pointer to a value that needed to delete.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteNumsFromStack(Stack* ptrStack, int* value) {
	Stack saveStack;
	Item  numberInStack;

	while (!isStackEmpty(ptrStack))
	{
		numberInStack = popStack(ptrStack);
		(numberInStack.value == value) ? numberInStack : pushStack(&saveStack, &numberInStack);
	}

	pushStackInStack(ptrStack, &saveStack);
}

//----------------------------------------------------------------------
//                         Delete Duplicate In Stack
//                         -------------------------
//
// General      : This functions deletes duplicate numbers in stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteDuplicateInStack(Stack* ptrStack) {
	Stack saveStack;
	Item  currectItem;

	while (!isStackEmpty(ptrStack))
	{
		currectItem = popStack(ptrStack);
		deleteNumsFromStack(ptrStack, &currectItem.value);
		pushStack(&saveStack, &currectItem);
	}

	pushStackInStack(ptrStack, &saveStack);
}