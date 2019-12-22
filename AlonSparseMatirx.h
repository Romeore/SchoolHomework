//AlonSpareMatrix.h
#pragma once

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
#define MANAGERMARK  -1
#define TYPE          int

#include <stdio.h>
#include <malloc.h>
#include "AlonCLLL.h"

typedef struct sparseMatrix {
	int                  row;
	int                  col;
	TYPE                 info;
	struct sparseMatrix* nextCol;
	struct sparseMatrix* nextRow;
} sparseMatrix;

void initSparseMatrix(sparseMatrix* manager, int row, int col);

void addColSparseMatrix(sparseMatrix* manager);

void addRowSparseMatrix(sparseMatrix* manager);

sparseMatrix* findRowSparseMatrix(sparseMatrix* returnedRow, int row);

sparseMatrix* findColSparseMatrix(sparseMatrix* returnedCol, int col);

sparseMatrix* findAbove(sparseMatrix* manager, int col);

sparseMatrix* findBefore(sparseMatrix* manager, int row);

void addItemSparseMatrix(int row, int col, TYPE info, sparseMatrix* manager);

void printSparseMatrixNode(sparseMatrix* sparseMatrixNode);

void mulColSparseMatrix(sparseMatrix* sm, int row, int number);