//AlonStacks.h
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
#define MAXSIZESTACK  5

#include <stdio.h>
#include <malloc.h>

typedef struct Stack{
	void* items[MAXSIZESTACK];
	int   offset;
} Stack;

typedef struct DStack {
	void** items;
	int    amount;
} DStack;

//----------------------------------------------------------------------
// Static Stack
//----------------------------------------------------------------------

void initStack(Stack* ptrStack);

void* popStack(Stack* ptrStack);

BOOLEAN isStackEmpty(Stack* ptrStack);

void pushStack(Stack* ptrStack, void* value);

void pushStackInStack(Stack* ptrStack, Stack* pushedStack);

void deleteValuesFromStack(Stack* ptrStack, void* value);

void deleteDuplicateValuesInStack(Stack* ptrStack);

int flipOrderInStack(Stack stack);

int flipOrderPlacementInStack(Stack stack);

//----------------------------------------------------------------------
// Dynamic Stack
//----------------------------------------------------------------------

void  initDStack(DStack* ptrStack);

void  pushDStack(DStack* ptrStack, void* value);

void* popDStack(DStack* ptrStack);

BOOLEAN isDStackEmpty(DStack* ptrStack);

void freeDStack(DStack* ptrStack);

void deleteValuesFromDStack(DStack* ptrStack, void* value);

void pushDStackIntoDStack(DStack* ptrStack, DStack* pushedStack);

void deleteDuplicateValuesInDStack(DStack* ptrStack);

void copyDStack(DStack* ptrStack, DStack* copyDStack);

int  flipOrderInDStack(DStack* ptrStack);

int  flipOrderPlacementInDStack(DStack* ptrStack);

int  calculatePostFix(char* string);