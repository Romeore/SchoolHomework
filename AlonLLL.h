//AlonLLL.h
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

typedef struct LLLChar {
	char     info;
	LLLChar* nextAddress;
} LLLChar;

void initLLLChar(LLLChar** manager);

void pushLLLChar(LLLChar** manager);

void popLLLChar(LLLChar** manager);

void insertAfterLLLChar(LLLChar* ptrAddAfter);

void deleteAfterLLLChar(LLLChar* ptrDeleteAfter);

LLLChar* longestLLLCharWord(LLLChar* manager);

void deleteSymbolFromLLLChar(LLLChar* deleteAfterPtr, char symbol);
