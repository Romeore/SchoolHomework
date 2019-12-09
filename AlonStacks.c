//AlonStacks.c
#pragma once

#include "AlonStacks.h"

//----------------------------------------------------------------------
// Static stacks
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//                              Init Stack
//                              ----------
//
// General      : This functions initilaizes a stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initStack(Stack* ptrStack)
{
	ptrStack->offset = ZERO;

	return;
}

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
// Return Value : The last value in stack.
//
//----------------------------------------------------------------------

void* popStack(Stack* ptrStack)
{
	void* value;
	(ptrStack->offset > EMPTY) ? (value = ptrStack->items[ptrStack->offset--])
		: (value = NULL);

	return (value);
}

//----------------------------------------------------------------------
//                              Push Stack
//                              ----------
//
// General      : This functions adds a value to the last place in stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)
//          value    - A value(void*)
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void pushStack(Stack* ptrStack, void* value)
{
	(ptrStack->offset < MAXSIZESTACK) ?
		(ptrStack->items[++ptrStack->offset] = value) : (value);
}

//----------------------------------------------------------------------
//                             Is Stack Empty
//                             --------------
//
// General      : This functions checks if the stack is empty.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)		
//
// Return Value : Returns TRUE if the stack is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isStackEmpty(Stack* ptrStack)
{
	return (ptrStack->offset == EMPTY);
}

//----------------------------------------------------------------------
//                           Flip Order In Stack
//                           -------------------
//
// General      : This functions finds the number that the order
//                of the values flips from up to down.
//
// Parameters   : 
//			stack - A  stack (Stack)
//
// Return Value : Returns the number that the order flips in the stack
//                from up to down.
//
//----------------------------------------------------------------------

int flipOrderInStack(Stack stack) {
	void* tempNum;
	void* returnedNum = popStack(&stack);
	BOOLEAN foundNumber = FALSE;
	
	while (!isStackEmpty(&stack) && foundNumber) {
		tempNum = popStack(&stack);
		(tempNum > returnedNum) ?
			(returnedNum = tempNum) : (foundNumber = TRUE);
	}

	return ((int)returnedNum);
}

//----------------------------------------------------------------------
//                       Flip Order Placement In Stack
//                       -----------------------------
//
// General      : This functions finds the place of the number that
//                the order flips from up to down.
//
// Parameters   : 
//			stack - A  stack (Stack)
//
// Return Value : Returns the place of the number that the order flips
//                from up to down.
//
//----------------------------------------------------------------------

int flipOrderPlacementInStack(Stack stack) {
	void*   tempNum;
	void*   maxNum = popStack(&stack);
	BOOLEAN foundNumber = FALSE;
	int     stackCounter = ZERO;

	while (!isStackEmpty(&stack) && !foundNumber) {
		tempNum = popStack(&stack);
		(tempNum > maxNum) ? stackCounter++ : (foundNumber = TRUE);
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
	while (!isStackEmpty(pushedStack))
	{
		pushStack(ptrStack, popStack(pushedStack));
	}

	return;
}

//----------------------------------------------------------------------
//                           Delete Values From Stack
//                           ------------------------
//
// General      : This functions deletes a value from a stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)
//          value    - A value.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteValuesFromStack(Stack* ptrStack, void* value)
{
	Stack tempStack;
	void* valueInStack;

	while (!isStackEmpty(ptrStack))
	{
		valueInStack = popStack(ptrStack);
		if (valueInStack == value)
		{
			pushStack(&tempStack, valueInStack);
		}
	}
	
	pushStackInStack(ptrStack, &tempStack);

	return;
}

//----------------------------------------------------------------------
//                      Delete Duplicate Values In Stack
//                      --------------------------------
//
// General      : This functions deletes duplicate values in stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (Stack*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteDuplicateValuesInStack(Stack* ptrStack)
{
	Stack saveStack;
	void* currectValue;

	while (!isStackEmpty(ptrStack))
	{
		currectValue = popStack(ptrStack);
		deleteNumsFromStack(ptrStack, &currectValue);
		pushStack(&saveStack, &currectValue);
	}

	pushStackInStack(ptrStack, &saveStack);

	return;
}

//----------------------------------------------------------------------
// Dynamic stacks
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//                              Init DStack
//                              ----------
//
// General      : This functions initilaizes a dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initDStack(DStack* ptrStack)
{
	ptrStack->items = (void**)malloc(sizeof(void*));
	ptrStack->amount = ZERO;

	return;
}

//----------------------------------------------------------------------
//                              Push DStack
//                              -----------
//
// General      : This functions pushes a value into dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)
//          value    - A value.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void pushDStack(DStack* ptrStack, void* value)
{
	ptrStack->items = (void**)realloc(ptrStack->items, 
		sizeof(void*) * ++ptrStack->amount);

	return;
}

//----------------------------------------------------------------------
//                              Pop DStack
//                              ----------
//
// General      : This functions pops a value from a dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)
//
// Return Value : The last value in the stack.
//
//----------------------------------------------------------------------

void* popDStack(DStack* ptrStack)
{
	void* value = NULL;
	if (ptrStack->amount)
	{
		value = ptrStack->items[ptrStack->amount--];
		ptrStack->items = (void**)realloc(ptrStack->items,
			sizeof(void*) * ptrStack->amount);
	}

	return (value);
}

//----------------------------------------------------------------------
//                             Is DStack Empty
//                             ---------------
//
// General      : This functions checks if the dynamic stack is empty
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)
//
// Return Value : Returns TRUE if the stack is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isDStackEmpty(DStack* ptrStack)
{
	return (ptrStack->amount == ZERO);
}

//----------------------------------------------------------------------
//                               Free DStack
//                               -----------
//
// General      : This functions frees the dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void freeDStack(DStack* ptrStack)
{
	for (; ptrStack->amount; ptrStack->amount--)
	{
		free(ptrStack->items[ptrStack->amount]);
	}

	return;
}

//----------------------------------------------------------------------
//                           Delete Values From DStack
//                           ----------------------
//
// General      : This functions deletes a value from a dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to dynamic stack (DStack*)
//          value    - A value.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteValuesFromDStack(DStack* ptrStack, void* value)
{
	DStack tempStack;
	void* valueInStack;

	initDStack(&tempStack);
	while (!isDStackEmpty(ptrStack))
	{
		valueInStack = popDStack(ptrStack);
		if (valueInStack == value)
		{
			pushDStack(&tempStack, valueInStack);
		}
	}

	pushDStackIntoDStack(ptrStack, &tempStack);
	freeDStack(&tempStack);

	return;
}

//----------------------------------------------------------------------
//                           Push DStack Into DStack
//                           -----------------------
//
// General      : This functions pushes the one dynamic stack into 
//                another dynamic stack.
//
// Parameters   : 
//			ptrStack    - A pointer to stack (Stack*)
//          pushedStack - A pointer to stack that is pushed into.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void pushDStackIntoDStack(DStack* ptrStack, DStack* ptrPushedStack) 
{

	while(!isDStackEmpty(ptrPushedStack))
	{
		pushDStack(ptrStack, popDStack(ptrPushedStack));
	}

	return;
}

//----------------------------------------------------------------------
//                       Delete Duplicate Values In DStack
//                       ---------------------------------
//
// General      : This functions deletes duplicate values in dynamic
//                stack.
//
// Parameters   : 
//			ptrStack    - A pointer to stack (Stack*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void deleteDuplicateValuesInDStack(DStack* ptrStack)
{
	DStack saveStack;
	void* tempValue;

	while (!isDStackEmpty(ptrStack))
	{
		tempValue = popDStack(ptrStack);
		deleteValuesFromDStack(ptrStack, tempValue);
		pushDStack(&saveStack, tempValue);
	}

	pushDStackIntoDStack(ptrStack, &saveStack);
	freeDStack(&saveStack);

	return;
}

//----------------------------------------------------------------------
//                               Copy DStack
//                               -----------
//
// General      : This functions copies a dynamic stack to another.
//
// Parameters   : 
//			ptrStack       - A pointer to stack (Stack*)
//          ptrCopiedStack - A pointer to a stack that will be copied.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void copyDStack(DStack* ptrStack, DStack* ptrCopiedDStack)
{
	int amount = ptrStack->amount;
	DStack tempOneStack;
	DStack tempTwoStack;
	void* tempValue;

	initDStack(&tempOneStack);
	initDStack(&tempTwoStack);

	tempOneStack.items = (void**)realloc(tempOneStack.items,
		sizeof(void*) * amount);

	tempTwoStack.items = (void**)realloc(tempTwoStack.items,
		sizeof(void*) * amount);

	ptrCopiedDStack->items = (void**)realloc(ptrCopiedDStack,
		sizeof(void*) * amount);

	for (; amount; amount--)
	{
		tempValue = popDStack(ptrStack);
		pushDStack(&tempTwoStack, tempValue);
		pushDStack(&tempOneStack, tempValue);
	}

	pushDStackIntoDStack(ptrStack, &tempOneStack);
	pushDStackIntoDStack(ptrCopiedDStack, &tempTwoStack);

	freeDStack(&tempTwoStack);
	freeDStack(&tempOneStack);

	return;
}

//----------------------------------------------------------------------
//                           Flip Order In DStack
//                           --------------------
//
// General      : This functions finds the number that the order
//                of the values flips from up to down.
//
// Parameters   : 
//			ptrStack - A pointer to stack (DStack*)
//
// Return Value : Returns the number that the order flips in the stack
//                from up to down.
//
//----------------------------------------------------------------------

int  flipOrderInDStack(DStack* ptrStack)
{
	DStack copiedStack;
	BOOLEAN isFound = FALSE;
	void* tempValue;
	void* maxValue;

	copyDStack(ptrStack, &copiedStack);
	maxValue = popDStack(&copiedStack);

	while (!isDStackEmpty(&copiedStack) && !isFound)
	{
		tempValue = popDStack(&copiedStack);
		(tempValue > maxValue) ? (isFound) : (isFound = TRUE);
		maxValue = tempValue;
	}

	freeDStack(&copiedStack);

	return ((int)maxValue);
}

//----------------------------------------------------------------------
//                       Flip Order Placement In DStack
//                       -----------------------------
//
// General      : This functions finds the place of the number that
//                the order flips from up to down.
//
// Parameters   : 
//			ptrStack - A pointer to stack(DStack*)
//
// Return Value : Returns the place of the number that the order flips
//                from up to down.
//
//----------------------------------------------------------------------

int flipOrderPlacementInDStack(DStack* ptrStack)
{
	DStack copiedStack;
	BOOLEAN isFound = FALSE;
	void* tempValue;
	void* maxValue;
	int counter = ZERO;

	copyDStack(ptrStack, &copiedStack);
	maxValue = popDStack(&copiedStack);

	while (!isDStackEmpty(&copiedStack) && !isFound)
	{
		tempValue = popDStack(&copiedStack);
		(tempValue > maxValue) ? (counter++) : (isFound = TRUE);
		maxValue = tempValue;
	}

	counter++;
	freeDStack(&copiedStack);

	return (counter);
}

//----------------------------------------------------------------------
//                           Calculate Post Fix
//                           ------------------
//
// General      : This function calculates post fix equation from string
//
// Parameters   : 
//			string - A string with equation.
//
// Return Value : Returns the result of the equation.
//
//----------------------------------------------------------------------

// BlackBox function that converts infix to postfix.
int calculatePostFix(char* string)
{
	DStack tempStack;
	BOOLEAN isNum;
	int result;

	initDStack(&tempStack);
	while (*(string++))
	{
		isCharNum(string) ? (pushDStack(&tempStack)) :
			(result += calculateTwoValuesInDStack(&tempStack, string));
	}

	return (result);
}

//----------------------------------------------------------------------
//                       Calculate Two Values In DStack
//                       ------------------------------
//
// General      : This function calculates a math equation with 
//                two values in the dynamic stack.
//
// Parameters   : 
//			ptrStack - A pointer to stack(DStack*)
//          symbpl   - A math symbol.
//
// Return Value : Returns the result of 2 values and the operator.
//
//----------------------------------------------------------------------

int calculateTwoValuesInDStack(DStack* ptrStack, char* symbol)
{
	int result = ZERO;
	int operandOne = popDStack(ptrStack);
	int operandTwo = popDStack(ptrStack);

	switch (*symbol)
	{
	case '*': result = operandTwo * operandOne;
		break;
	case '/': result = operandTwo / operandOne;
		break;
	case '+': result = operandTwo + operandOne;
		break;
	case '-': result = operandTwo - operandOne;
	}

	return (result);
}
