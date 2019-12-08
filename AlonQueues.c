//AlonQueues.c
#pragma once

#include "AlonQueues.h"
#include "AlonPointers.h"

//----------------------------------------------------------------------
// Static Queues
//----------------------------------------------------------------------
void initQueue(Queue* ptrQueue)
{
	ptrQueue->amount = ZERO;
	ptrQueue->front = ZERO;
	ptrQueue->rear = ZERO;
}

BOOLEAN isQueueEmpty(Queue* ptrQueue)
{
	return (ptrQueue->amount == ZERO);
}

void insertQueue(Queue* ptrQueue, void* value)
{
	ptrQueue->items[ptrQueue->rear++ % MAXSIZE] = value;
	ptrQueue->amount++;
}

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
}

int numOfItemsQueue(Queue* ptrQueue)
{
	int numOfItems = ptrQueue->front % FIVE - ptrQueue->rear % FIVE;

	return (numOfItems);
}

//----------------------------------------------------------------------
// Dynamic Queues
//----------------------------------------------------------------------

void initDQueue(DQueue* ptrDQueue)
{
	ptrDQueue->items = (void**)malloc(sizeof(void*));
	ptrDQueue->rear = ZERO;
}

BOOLEAN isDQueueEmpty(DQueue* ptrDQueue)
{
	return (ptrDQueue->rear == ZERO);
}

void insertDQueue(DQueue* ptrDQueue, void* item)
{
	ptrDQueue->items = (void**)realloc(ptrDQueue->items, 
		sizeof(void*) * ++ptrDQueue->rear);
	ptrDQueue->items[ptrDQueue->rear - ONE] = item;
}

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


int numOfItemsDQueue(DQueue* ptrDQueue)
{
	return (ptrDQueue->rear);
}

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

void sumTwoDQueues(DQueue* ptrDQueueOne, DQueue* ptrDQueueTwo, DQueue* ptrResultQueue)
{
	int sumTwoQueues = sumDQueue(ptrDQueueOne) + sumDQueue(ptrDQueueTwo);
	splitDigitsInDQueue(ptrResultQueue, sumTwoQueues);

	return;
}
