//AlonRecursionsStrings.h
#pragma once

#define BOOLEAN  unsigned short
#define TRUE     1
#define FALSE    0
#define ZERO     0
#define ONE      1
#define TWO      2
#define THREE    3
#define FOUR     4
#define FIVE     5
#define SIX      6
#define SEVEN    7
#define EIGHT    8
#define NINE     9
#define TEN      10
#define MAX(a,b) (a > b) ? (a) : (b)
#define ABS(a)   (a < 0) ? -(a) : (a)

#include <stdio.h>
#include "AlonStrings.h"
#include <string.h>
#include <malloc.h>


int numOfApperanceRecursion(char* string, char symbol);

int stringLengthRecursion(char* string);

BOOLEAN isCharDigit(char* symbol);

BOOLEAN isEvenPlacesDigitRecursion(char* string);

BOOLEAN compareStringsHelperRecursion(char* string, char* subString);

BOOLEAN isSubStringOnStringRecursion(char* string, char* subString);

void copyStringRecursion(char* string, char* copiedTo);

void reverseStringRecursion(char* string, char* reverseTo);

void printAkltoniHelper(char* string, int size);

void printAkltoni(char* string);

char* concatenationMirror(char* string);
