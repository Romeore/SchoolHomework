#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN    unsigned short
#define TRUE       1
#define FALSE      0
#define TEN        10
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
#define TWENTY     (unsigned short)(20)
#define TWENTYFIVE 25
#define THIRTY     30
#define FOURTY     40
#define MONTH      30
#define YEAR       365
#define ONEHUNDRED 100
#define ABS(a)     (a < 0) ? -(a) : (a)
#define MAX(a,b)   (a > b) ? (a) : (b)
#define DIM        3
#define DIMONE     10
#define DIMTWO     8

#include <stdio.h>

int sumRowInMatriza(short mat[][DIM], unsigned short row);

int sumColumnInMatriza(short mat[][DIM], unsigned short column);

int sumMainCrossInMatriza(short mat[][DIM]);

int sumSecondCrossInMatriza(short mat[][DIM]);

short maxInMatriza(short mat[][DIM]);

short minInMatriza(short mat[][DIM]);

short sumSymbolInSecondCross(char mat[DIM][DIM], char symbol);

short sumSymbolInMainCross(char mat[DIM][DIM], char symbol);

short sumSymbolInRow(char mat[][DIM], short row, char symbol);

short sumSymbolInColumn(char mat[][DIM], short column, char symbol);

void printMatNums(short mat[][DIM]);

void printMatChars(char mat[][DIM]);

BOOLEAN isTwoNumbersSameInRow(short mat[][DIM], unsigned short row);

BOOLEAN isTwoNumbersSameInColumn(short mat[][DIM], unsigned short column);