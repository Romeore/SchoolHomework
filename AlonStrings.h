//AlonStrings.h
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN         unsigned short
#define TRUE            1
#define FALSE           0
#define ZERO            0
#define ONE             1
#define TWO             2
#define THREE           3
#define FOUR            4
#define FIVE            5
#define SIX             6
#define SEVEN           7
#define EIGHT           8
#define NINE            9
#define TEN             10
#define STRINGMAXLENGTH 100
#define GARBAGE         '@'

#include <stdio.h>

BOOLEAN isSymbolOnString(char string[], char symbol, unsigned short position);

BOOLEAN isSubStringOnString(char string[], char subString[]);

BOOLEAN compare(char stringOne[], char stringTwo[]);

short sumSymbolOnString(char string[], char symbol);

short firstSymbolPositionOnString(char string[], char symbol);

void concatenationStrings(char stringOne[], char stringTwo[]);

void copyString(char oldString[], char copyString[], unsigned short position);

void cutString(char string[], char cuttedString[], unsigned short startCutPosition);

void fillString(char string[], unsigned short numOfSymbols);

void deleteSymbolOnString(char string[], char symbol);

unsigned short stringLength(char string[]);
