//AlonSparseMatrix.h
#pragma once

#define BOOLEAN     unsigned short
#define TRUE        1
#define FALSE       0
#define ZERO        0
#define ONE         1
#define TWO         2
#define THREE       3
#define FOUR        4
#define FIVE        5
#define SIX         6
#define SEVEN       7
#define EIGHT       8
#define NINE        9
#define TEN         10
#define FIFTEEN     15
#define TWENTY      20
#define TWENTYFIVE  25
#define THIRTY      30
#define FOURTY      40
#define FIFTY       50
#define HUNDRED     100
#define MANAGERMARK -1
#define EMPTYINFO   -999
#define TYPE        int

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

void initSparseMatrix(sparseMatrix** manager, int rowLength, int colLength);

void addColSparseMatrix(sparseMatrix** manager);

void addRowSparseMatrix(sparseMatrix** manager);

void addNumOfColsSparseMatrix(sparseMatrix** manager, int numOfCols);

void addNumOfRowsSparseMatrix(sparseMatrix** manager, int numOfRows);

void addItemSparseMatrix(sparseMatrix* manager, int row, int col);

void deleteColSparseMatrix(sparseMatrix** manager);

void deleteNumOfColsSparseMatrix(sparseMatrix** manager);

void deleteRowSparseMAtrix(sparseMatrix** manager);

void deleteNumOfRowsSparseMatrix(sparseMatrix** manager);

void printSparseMatrixNode(sparseMatrix* sparseMatrixNode);

void printSparseMatrix(sparseMatrix* manager, int rowLength, int colLength);

void insertAfterSparseMatrix(sparseMatrix** ptrBefore, sparseMatrix** ptrAbove);

void mulColSparseMatrix(sparseMatrix* sm, int row, int number);

void storeSparseMatrix(sparseMatrix* manager, int row, int col, TYPE info);

void freeSparseMatrix(sparseMatrix** manager);

BOOLEAN isItemExistsSparseMatrix(sparseMatrix* manager, int row, int col);

int countNodesSparseMatrix(sparseMatrix* manager);

int numOfCols(sparseMatrix* manager);

int numOfRows(sparseMatrix* manager);

sparseMatrix* findRowSparseMatrix(sparseMatrix* returnedRow, int row);

sparseMatrix* findColSparseMatrix(sparseMatrix* returnedCol, int col);

sparseMatrix* findAbove(sparseMatrix* manager, int col);

sparseMatrix* findBefore(sparseMatrix* manager, int row);

CLLL* makeCLLLFromColSparseMatrix(sparseMatrix* colManager);

CLLL* makeCLLLFromRowSparseMatrix(sparseMatrix* rowManager);
