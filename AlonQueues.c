//AlonQueues.c
#pragma once

#include "AlonQueues.h"
#include "AlonPointers.h"

//----------------------------------------------------------------------
// Static Queues
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//                              Init Queue
//                              ----------
//
// General      : This function initilaizes a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initQueue(Queue* ptrQueue)
{
	ptrQueue->amount = ZERO;
	ptrQueue->front = ZERO;
	ptrQueue->rear = ZERO;

	return;
}

//----------------------------------------------------------------------
//                             Is Queue Empty
//                             --------------
//
// General      : This function checks if the queue is empty.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)		
//
// Return Value : Returns TRUE if the queue is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isQueueEmpty(Queue* ptrQueue)
{
	return (ptrQueue->amount == ZERO);
}

//----------------------------------------------------------------------
//                             Insert Queue
//                             ------------
//
// General      : This function inserts a value into a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//          value    - A value (void*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertQueue(Queue* ptrQueue, void* value)
{
	ptrQueue->items[ptrQueue->rear++ % MAXSIZE] = value;
	ptrQueue->amount++;

	return;
}

//----------------------------------------------------------------------
//                             Remove Queue
//                             ------------
//
// General      : This function removes a value from a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : The value of the first value in the queue.
//
//----------------------------------------------------------------------

void* removeQueue(Queue* ptrQueue)
{
	void* returnedValue = NULL;
	if (!isQueueEmpty(ptrQueue))
	{
		returnedValue = ptrQueue->items[ptrQueue->front++ % MAXSIZE];
		ptrQueue->amount--;
	}

	return (returnedValue);
}

//----------------------------------------------------------------------
//                             Print Queue
//                             -----------
//
// General      : This function prints a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printQueue(Queue* ptrQueue)
{
	int numOfItems = ptrQueue->front % FIVE - ptrQueue->rear % FIVE;
	void* value;

	for(numOfItems; numOfItems; numOfItems--)
	{
		value = removeQueue(ptrQueue);
		insertQueue(ptrQueue, value);
		printf("%d", value);
	}

	return;
}

//----------------------------------------------------------------------
//                           Num Of Items Queue
//                           ------------------
//
// General      : This function calculates the number of items in queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : The number of items in a queue.
//
//----------------------------------------------------------------------

int numOfItemsQueue(Queue* ptrDQueue)
{
	int numOfItems = ptrDQueue->front % FIVE - ptrDQueue->rear % FIVE;

	return (numOfItems);
}

//----------------------------------------------------------------------
// Dynamic Queues
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//                              Init DQueue
//                              ----------
//
// General      : This function initilaizes a dynamic queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (DQueue*)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initDQueue(DQueue* ptrQueue)
{
	ptrQueue->items = (void**)malloc(sizeof(void*));
	ptrQueue->rear = ZERO;

	return;
}

//----------------------------------------------------------------------
//                             Is DQueue Empty
//                             ---------------
//
// General      : This function checks if the dynamic queue is empty.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : Returns TRUE if the queue is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isDQueueEmpty(DQueue* ptrDQueue)
{
	return (ptrDQueue->rear == ZERO);
}

//----------------------------------------------------------------------
//                             Insert DQueue
//                             ------------
//
// General      : This function inserts a value into a dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//          value     - A value (void*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertDQueue(DQueue* ptrDQueue, void* value)
{
	ptrDQueue->items = (void**)realloc(ptrDQueue->items, 
		sizeof(void*) * ++ptrDQueue->rear);
	ptrDQueue->items[ptrDQueue->rear - ONE] = value;

	return;
}

//----------------------------------------------------------------------
//                             Remove Queue
//                             ------------
//
// General      : This function removes a value from a dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : The value of the first value in the queue.
//
//----------------------------------------------------------------------

void* removeDQueue(DQueue* ptrDQueue)
{
	void* returnedValue = NULL;
	void** newItemsQueue = NULL;

	if (!isDQueueEmpty(ptrDQueue))
	{
		newItemsQueue = (void**)malloc(sizeof(void*));
		newItemsQueue = (void**)realloc(ptrDQueue->items + ONE, sizeof(void*) * ptrDQueue->rear--);
		returnedValue = ptrDQueue->items[ZERO];
		free(ptrDQueue->items);
		ptrDQueue->items = newItemsQueue;
	}

	return (returnedValue);
}

//----------------------------------------------------------------------
//                             Free DQueue
//                             -----------
//
// General      : This function frees a dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void  freeDQueue(DQueue* ptrQueue)
{
	for (; ptrQueue->rear - ONE; ptrQueue->rear--)
	{
		free(ptrQueue->items[ptrQueue->rear]);
	}

	free(ptrQueue);
	return;
}

//----------------------------------------------------------------------
//                           Num Of Items DQueue
//                           ------------------
//
// General      : This function calculates the number of items in
//                a dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : The number of items in a queue.
//
//----------------------------------------------------------------------

int numOfItemsDQueue(DQueue* ptrDQueue)
{
	return (ptrDQueue->rear);
}

//----------------------------------------------------------------------
//                             Print DQueue
//                             -----------
//
// General      : This function prints a dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printDQueue(DQueue* ptrDQueue)
{
	int amount = ptrDQueue->rear;
	void* value;

	for (amount; amount; amount--)
	{
		value = removeDQueue(ptrDQueue);
		insertDQueue(ptrDQueue,value);
		printf("%d", value);
	}

	return;
}

//----------------------------------------------------------------------
//                             Sum DQueue
//                             ----------
//
// General      : This function make number off digits in a 
//                dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//
// Return Value : The number that made from the digits in the queue.
//
//----------------------------------------------------------------------

int sumDQueue(DQueue* ptrDQueue)
{
	void* value;
	int amount = numOfItemsDQueue(ptrDQueue);
	int sumOfQueue = ZERO;

	for (amount; amount; amount--)
	{
		value = removeDQueue(ptrDQueue);
		sumOfQueue = sumOfQueue * TEN + (int)value;
		insertDQueue(ptrDQueue, value);
	}

	return (sumOfQueue);
}

//----------------------------------------------------------------------
//                           Split Digits In DQueue
//                           ----------------------
//
// General      : This function splits a number into digits in a 
//                dynamic queue.
//
// Parameters   : 
//			ptrDQueue - A pointer to queue (DQueue*)
//          number    - A number to split.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void splitDigitsInDQueue(DQueue* ptrDQueue, int number)
{
	int    numDigitsLength = digitsLength(&number);
	int    tempDigit; 
	int    powerSave;
	double ten = TEN;

	for (numDigitsLength; numDigitsLength; numDigitsLength--)
	{
		powerSave = (int)(power(&ten, numDigitsLength));
		tempDigit = (number % powerSave);
		insertDQueue(ptrDQueue, tempDigit);
		number -= tempDigit * powerSave;
	}

	return;
}

//----------------------------------------------------------------------
//                           Sum Two DQueues
//                           ---------------
//
// General      : This function sums two dynamic queues.
//
// Parameters   : 
//			ptrDQueueOne   - A pointer to queue (DQueue*)
//			ptrDQueueTwo   - A pointer to queue (DQueue*)
//			ptrResultQueue - A pointer to queue for the result (DQueue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void sumTwoDQueues(DQueue* ptrDQueueOne, DQueue* ptrDQueueTwo, DQueue* ptrResultQueue)
{
	int sumTwoQueues = sumDQueue(ptrDQueueOne) + sumDQueue(ptrDQueueTwo);
	splitDigitsInDQueue(ptrResultQueue, sumTwoQueues);

	return;
}
