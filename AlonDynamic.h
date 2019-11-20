//AlonDynamic.h
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
#define GARBAGE       '@'

#include <stdio.h>
#include <malloc.h>
#include "AlonPointers.h"

int* evenSubArrayDynamic(int vec[], int len, int* ptrEven);

int* oddSubArrayDynamic(int vec[], int len, int* ptrOdd);

void oddEvenSubArraysDynamic(int vec[], int** even, int* evenSize, int** odd, int* oddSize, int arrayLength);

void addNumberToArrayDynamic(int* ptrArray, int arrayLength, int number);

void cutStringDynamic(char* ptrCuttedString, char* ptrCutStringStart, int numToCut);

void searchLongestWordDynamic(char string[], char* ptrMaxLen);