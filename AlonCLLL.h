//AlonCLLL.h
#pragma once

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
	struct CLLL* nextAddress;
} CLLL;

typedef struct CLLLString {
	char* info;
	struct CLLLString* nextAddress;
} CLLLString;

void freeCLLL(CLLL** manager);

void insertLastCLLL(CLLL** manager);

void insertAfterCLLL(CLLL* ptrAddAfter);

void insertEndCLLL(CLLL** manager);

void deleteAfterCLLL(CLLL* ptrDeleteAfter);

void deleteLastCLLL(CLLL** manager);

void deleteEndCLLL(CLLL** manager);

void moveNumberOfTimesCLLL(CLLL** ptrToMove, int numToMove);

void printCLLL(CLLL* ptrNode);

int numOfInfoAppendsCLLL(CLLL* manager, int info);

int sumInfoCLLL(CLLL* manager);

int lengthCLLL(CLLL* manager);

BOOLEAN isEmptyCLLL(CLLL* manager);

BOOLEAN findCLLL(CLLL** ptrNode, int info);

CLLL* sumTwoCLLL(CLLL* managerOne, CLLL* managerTwo);

CLLL* numOfSubStringsCLLLString(CLLLString* manager, char* string);
