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
#define MAXSIZE       5

#include <stdio.h>

typedef struct Item {
	void* address;
	void* value;
} Item;

typedef struct Stack{
	Item  startStack[MAXSIZE];
	int   offset;
} Stack;

Item popStack(Stack* ptrStack);

void pushStack(Stack* ptrStack, Item* value);

BOOLEAN isStackEmpty(Stack* ptrStack);
