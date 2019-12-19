//AlonCLLL.h
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

#include <stdio.h>
#include <malloc.h>
#include "AlonStrings.h"

typedef struct CLLL {
	int   info;
	CLLL* nextAddress;
} CLLL;

typedef struct CLLLString {
	char* info;
	CLLL* nextAddress;
} CLLLString;

void insertLastCLLL(CLLL** manager);

void insertAfterCLLL(CLLL* ptrAddAfter);

void insertEndCLLL(CLLL** manager);

void deleteAfterCLLL(CLLL* ptrDeleteAfter);

void deleteLastCLLL(CLLL** manager);

void deleteEndCLLL(CLLL** manager, CLLL* ptrDeleteAfter);

void moveNumberOfTimesCLLL(CLLL** ptrToMove, int numToMove);

int sumInfoCLLL(CLLL* manager);

int lengthCLLL(CLLL* manager);

BOOLEAN isEmptyCLLL(CLLL* manager);

BOOLEAN findCLLL(CLLL** ptrNode, int info);

CLLL** sumTwoCLLL(CLLL* managerOne, CLLL* managerTwo);

CLLL** numOfSubStringsCLLLString(CLLLString* manager, char* string);