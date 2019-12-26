//AlonRecursions.h
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
#include "AlonPointers.h"

int findMaxDigit(int num);

int differenceLength(int numOne, int numTwo);

int differenceDigitsValues(int numOne, int numTwo);

int sumEvenOddDifference(int num);

int sumDigits(int num);

int digitsLength(int num);

int concatenation(int numOne, int numTwo);

double averageDigits(int num);

BOOLEAN isPrime(int num);

void printPrimeDividers(int num);
