//AlonQueues.h
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN       unsigned short
#define TRUE          1
#define FALSE         0
#define ZERO          0
#define ONE           1
#define TWO           2
#define THREE         3
#define FOUR          4
#define FIVE          5
#define SIX           6
#define SEVEN         7
#define EIGHT         8
#define NINE          9
#define TEN           10
#define EMPTY         -1
#define MAXSIZE       5

#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	void* items[MAXSIZE];
	int   front;
	int   rear;
	int   amount;
} Queue;

typedef struct DQueue {
	void** items;
	int    rear;
} DQueue;

//----------------------------------------------------------------------
// Static Queue
//----------------------------------------------------------------------

void  initQueue(Queue* ptrQueue);

void  insertQueue(Queue* ptrQueue, void* value);

void* removeQueue(Queue* ptrQueue);

//----------------------------------------------------------------------
// Dynamic Queue
//----------------------------------------------------------------------

void  initDQueue(DQueue* ptrDQueue);

void  insertDQueue(DQueue* ptrDQueue, void* value);

void  freeDQueue(DQueue* ptrQueue);

void  printDQueue(DQueue* ptrDQueue);

void* removeDQueue(DQueue* ptrDQueue);

int   numOfItemsDQueue(DQueue* ptrDQueue);

int   sumDQueue(DQueue* ptrDQueue);
