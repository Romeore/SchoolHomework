//AlonPointers.h
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
#define HUNDRED       100
#define STRINGMAXSIZE 100
#define GARBAGE       '@'

#include <stdio.h>

BOOLEAN* isNumberEven(int* ptrNum);

BOOLEAN* isNumberOdd(int* ptrNum);

BOOLEAN* isDigitOnNum(int* ptrNum, unsigned short* ptrDigit);

BOOLEAN* isNumberPrime(int* ptrNumber);

BOOLEAN compare(char* ptrStringOne, char* ptrStringTwo);

BOOLEAN isSubStringOnString(char* ptrString, char* ptrSubString);

BOOLEAN isSymbolOnString(char* ptrString, char symbol);

int* convertToBaseTen(int* ptrNum, int* ptrBase);

int* divideResult(int* ptrNum, int* ptrNumDivider);

int* sumTwoNumbers(int* ptrNumOne, int* ptrNumTwo);

int* digitsLength(int* ptrNum);

int* sumEvenDigits(int* ptrNum);

int* sumOddDigits(int* ptrNum);

int* makeOddDigitsNum(int* ptrNum);

int stringLength(char* ptrStartString);

int sumSymbolOnString(char* ptrString, char symbol);

int maxNumOfSymbolsOnString(char* ptrString);

int sumDeleteStringFromString(char* ptrString, char* ptrDeleteFromString);

unsigned short sumSubStringsOnString(char* ptrString, char* ptrSubString);

void swap(int* ptrNumOne, int* ptrNumTwo);

void concatenationNumbers(int* ptrNumOne, int* ptrNumTwo);

void flipNumber(int* ptrNum);

void power(double* ptrNumber, int* ptrNumberOfTimes, double* answer);

void cutString(char* ptrStringOne, char* cuttedString, unsigned short startPlace);

void fillString(char* ptrString, unsigned short garbageLength);

void clearString(char* ptrString);

void deleteStringFromString(char* ptrString, char* ptrDeleteFromString);

void deleteSymbolFromString(char* ptrString, char symbol);

char* stringLastAddress(char* ptrEndString);

char itoa(int* num);