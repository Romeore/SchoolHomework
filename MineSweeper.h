//MineSweeper.h
#pragma once

#define BOOLEAN   unsigned short
#define TRUE      1
#define FALSE     0
#define ZERO      0
#define ONE       1
#define TWO       2
#define THREE     3
#define FOUR      4
#define FIVE      5
#define SIX       6
#define SEVEN     7
#define EIGHT     8
#define NINE      9
#define TEN       10
#define BOARDSIZE 12

#include <stdio.h>

typedef struct Mine
{
	char symbol;
	BOOLEAN isActive;
} Mine;

int convertCharToDigit(char* symbol);

int makeNumberFromString(char** string);

int numOfMinesAroundSquare(Mine board[][BOARDSIZE], int row, int col);

int startNumOfMines(Mine board[][BOARDSIZE]);

char convertDigitToChar(int number);

void initBoardMines(Mine board[][BOARDSIZE]);

void printBoard(Mine board[][BOARDSIZE]);

void putMinesOnBoard(Mine board[][BOARDSIZE]);

void discoverSquare(Mine board[][BOARDSIZE], int row, int col);

BOOLEAN isSquareMine(Mine board[][BOARDSIZE], int row, int col);

BOOLEAN isSquareGuessed(Mine board[][BOARDSIZE], int row, int col);