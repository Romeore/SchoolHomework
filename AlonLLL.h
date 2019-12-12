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
#include "AlonStrings.h"

typedef struct LLLChar {
	char     info;
	LLLChar* nextAddress;
} LLLChar;

typedef struct LLLString {
	char*      info;
	LLLString* nextAddress;
} LLLString;

typedef struct LLLInt {
	int     info;
	LLLInt* nextAddress;
} LLLInt;

//----------------------------------------------------------------------
// LLLChar
//----------------------------------------------------------------------

void initLLLChar(LLLChar** manager);

void pushLLLChar(LLLChar** manager);

void popLLLChar(LLLChar** manager);

void insertAfterLLLChar(LLLChar* ptrAddAfter);

void deleteAfterLLLChar(LLLChar* ptrDeleteAfter);

void deleteSymbolFromSecondNodeLLLChar(LLLChar* deleteAfterPtr, char symbol);

void deleteSymbolFromManagerLLLChar(LLLChar** manager, char symbol);

void deleteSymbolFromLLLChar(LLLChar** manager, char symbol);

void deleteDuplicateFromLLLChar(LLLChar* ptrDeleteNext);

LLLChar* longestLLLCharWord(LLLChar* manager);

//----------------------------------------------------------------------
// LLLInt
//----------------------------------------------------------------------

void sumNodesLLLInt(LLLInt* manager, int* ptrVector);

//----------------------------------------------------------------------
// LLLString
//----------------------------------------------------------------------

int longestStringPlaceLLLString(LLLString* manager);