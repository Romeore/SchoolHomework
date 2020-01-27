//Atomic.h
#pragma once

#define BOOLEAN        unsigned short
#define TRUE           1
#define FALSE          0
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
#define MANAGERMARK    -1
#define LEFT           2
#define UP             3
#define DOWN           4
#define RIGHT          8
#define ATOM           100
#define EXPLOADINGATOM 200
#define ROWLENGTH      600
#define COLUMNLENGTH   500

#include <stdio.h>
#include <malloc.h>

typedef struct sparseMatrix {
	int                  row;
	int                  col;
	int                  info;
	int                  nextTurnInfo;
	struct sparseMatrix* nextCol;
	struct sparseMatrix* nextRow;
} sparseMatrix;

//////////////////////////
// Atomic game functions
//////////////////////////

void initBoard(sparseMatrix** manager);

void setNextValue(sparseMatrix* manager, sparseMatrix* tempNode,
			      int* numOfNeutrons);

void addNextValues(sparseMatrix* manager, int* numOfNeutrons);

void changeStates(sparseMatrix* manager, int* numOfNeutrons,
	              int* numOfExplodingAtom);

sparseMatrix* changeCurrectItemState(sparseMatrix* manager,
                                  	 sparseMatrix* tempNode,
									 int* numOfNeutrons,
									 int* numOfExplodingAtom);


//////////////////////////
// Sparse Matrix functions
//////////////////////////

void initSparseMatrix(sparseMatrix** manager, int rowLength, int colLength);

void addColSparseMatrix(sparseMatrix** manager);

void addRowSparseMatrix(sparseMatrix** manager);

void addNumOfColsSparseMatrix(sparseMatrix** manager, int numOfCols);

void addNumOfRowsSparseMatrix(sparseMatrix** manager, int numOfRows);

void addItemSparseMatrix(sparseMatrix* manager, int row, int col);


void deleteItemSparseMatrix(sparseMatrix* manager, int row, int col);

void insertAfterSparseMatrix(sparseMatrix** ptrBefore,
	                         sparseMatrix** ptrAbove);

void storeSparseMatrixInfo(sparseMatrix* manager, int row, int col, int info);

void storeSparseMatrixNextTurnInfo(sparseMatrix* manager, int row, int col,
	                               int infoNextTurn);

sparseMatrix* findRowSparseMatrix(sparseMatrix* returnedRow, int row);

sparseMatrix* findColSparseMatrix(sparseMatrix* returnedCol, int col);

sparseMatrix* findAbove(sparseMatrix* manager, int col);

sparseMatrix* findBefore(sparseMatrix* manager, int row);

sparseMatrix* findItemSparseMatrix(sparseMatrix* manager, int row, int col);
