#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN        unsigned short
#define TRUE           1
#define FALSE          0
#define TEN            10
#define ZERO           0
#define ONE            1
#define TWO            2
#define THREE          3
#define FOUR           4
#define FIVE           5
#define SIX            6
#define SEVEN          7
#define EIGHT          8
#define NINE           9
#define TWENTY         20
#define TWENTYFIVE     25
#define THIRTY         30
#define FOURTY         40
#define ONEHUNDRED      100
#define ABS(a)         (a < 0) ? -(a) : (a)
#define STRINGMAXLENGTH 100

#include <stdio.h>

unsigned short stringLength(char string[]);

unsigned short sumSymbolOnString(char string[], char symbol);

short firstSymbolPositionOnString(char string[], char symbol);

void concatenationStrings(char stringOne[], char stringTwo[]);

void copyString(char stringOne[], char stringTwo[], unsigned short position);

void cutString(char stringOne[], char cuttedString[], unsigned short startCutPosition);

void fillString(char string[], unsigned short numOfSymbols);

BOOLEAN isSymbolOnString(char string[], char symbol, unsigned short position); 

BOOLEAN isSubStringOnString(char string[], char subString[]);

BOOLEAN compare(char stringOne[], char stringTwo[]);