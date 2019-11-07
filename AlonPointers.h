//AlonPointers.h
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN    unsigned short
#define TRUE       1
#define FALSE      0
#define ZERO       0
#define ONE        1
#define TWO        2
#define THREE      3
#define FOUR       4
#define FIVE       5
#define SIX        6
#define SEVEN      7
#define EIGHT      8
#define NINE       9
#define TEN        10
#define HUNDRED    100
#define MAX(a,b)   (a > b) ? (a) : (b)

#include <stdio.h>

int* sumTwoNumbers(int* ptrNumOne, int* ptrNumTwo);

unsigned short* digitsLength(int* ptrNum);

BOOLEAN* isNumberEven(int* ptrNum);

BOOLEAN* isNumberOdd(int* ptrNum);

BOOLEAN* isDigitOnNum(int* ptrNum, unsigned short* ptrDigit);

void swap(int* ptrNumOne, int* ptrNumTwo);

void concatenationNumbers(int* ptrNumOne, int* ptrNumTwo);

