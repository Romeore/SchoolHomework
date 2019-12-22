//AlonSparseMatrix.c
#pragma once

#include "AlonSparseMatirx.h"

void initSparseMatrix(sparseMatrix* manager, int row, int col)
{
	manager = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sparseMatrix* saveManager = manager;
	int counter;

	manager->nextRow = manager;
	manager->nextCol = manager;

	for (counter = ZERO; counter < row; counter++)
	{
		addRowSparseMatrix(manager);
	}

	for (counter = ZERO; counter < col; counter++)
	{
		addColSparseMatrix(manager);
	}

	return;
}

void addRowSparseMatrix(sparseMatrix* manager)
{
	sparseMatrix* ptrEOD = manager;
	sparseMatrix* newRow = (sparseMatrix*)malloc(sizeof(sparseMatrix));

	while (manager->nextRow != ptrEOD)
	{
		manager = manager->nextRow;
	}

	manager->nextRow = newRow;
	newRow->nextRow = ptrEOD;
	newRow->col = MANAGERMARK;
	newRow->row = manager->row + ONE;

	return;
}

void addColSparseMatrix(sparseMatrix* manager)
{
	sparseMatrix* ptrEOD = manager;
	sparseMatrix* newCol = (sparseMatrix*)malloc(sizeof(sparseMatrix));

	while (manager->nextCol != ptrEOD)
	{
		manager = manager->nextCol;
	}

	manager->nextCol = newCol;
	newCol->nextCol = ptrEOD;
	newCol->row = MANAGERMARK;
	newCol->col = manager->col + ONE;

	return;
}

sparseMatrix* findRowSparseMatrix(sparseMatrix* returnedRow, int row)
{
	int counter;

	for (counter = ZERO; counter < row; counter++)
	{
		returnedRow = returnedRow->nextRow;
	}

	return (returnedRow);
}

sparseMatrix* findColSparseMatrix(sparseMatrix* returnedCol, int col)
{
	int counter;

	for (counter = ZERO; counter < col; counter++)
	{
		returnedCol = returnedCol->nextCol;
	}

	return (returnedCol);
}

sparseMatrix* findAbove(sparseMatrix* manager,int col)
{
	sparseMatrix* ptrEOD = manager;
	manager = manager->nextCol;
	while (manager->nextCol != ptrEOD && manager->nextCol->col > col)
	{
		manager = manager->nextCol;
	}

	return (manager);
}

sparseMatrix* findBefore(sparseMatrix* manager, int row)
{
	sparseMatrix* ptrEOD = manager;
	manager = manager->nextRow;
	while (manager->nextRow != ptrEOD && manager->nextRow->row > row)
	{
		manager = manager->nextRow;
	}

	return (manager);
}

void insertAfterSparseMatrix(sparseMatrix* ptrBefore, sparseMatrix* ptrAbove)
{
	sparseMatrix* newSM = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	ptrBefore->nextCol = newSM;
	ptrAbove->nextRow = newSM;

	return;
}

void addItemSparseMatrix(int row, int col, TYPE info, sparseMatrix* manager)
{
	sparseMatrix* rowManager = findRowSparseMatrix(manager, row);
	sparseMatrix* colManager = findColSparseMatrix(manager, col);

	rowManager = findAbove(rowManager, col);
	colManager = findBefore(colManager, row);
	insertAfterSparseMatrix(colManager, rowManager);

	colManager->nextCol->col = colManager->col;
	rowManager->nextRow->row = rowManager->row + ONE;
	rowManager->nextRow->info = info;

	return;
}

void printSparseMatrixNode(sparseMatrix* sparseMatrixNode)
{
	printf("\nThe node is on row: %d\n", sparseMatrixNode->row);
	printf("\nThe node is on col: %d\n", sparseMatrixNode->col);
	printf("\nThe node info is: %d\n", sparseMatrixNode->info);

	return;
}

void mulColSparseMatrix(sparseMatrix* sm, int row, int number)
{
	sparseMatrix* ptrRow = findRowSparseMatrix(sm, row);
	sparseMatrix* ptrEOD = ptrRow;

	ptrRow = ptrRow->nextCol;

	while (ptrRow != ptrEOD)
	{
		ptrRow->info *= number;
	}

	return;
}

CLLL** makeCLLLFromRowSparseMatrix(sparseMatrix* rowManager)
{
	sparseMatrix* ptrEOD = rowManager;
	CLLL** clllManager = NULL; 
	CLLL* tempCLLL;
	
	rowManager = rowManager->nextRow;

	if (rowManager != ptrEOD)
	{
		insertLastCLLL(clllManager);
		(*clllManager)->info = rowManager->info;
	}

	rowManager = rowManager->nextRow;

	while (rowManager != ptrEOD)
	{
		insertEndCLLL(clllManager);
		(*clllManager)->info = rowManager->info;

		rowManager = rowManager->nextRow;
	}

	return (clllManager);
}

CLLL** makeCLLLFromColSparseMatrix(sparseMatrix* colManager)
{
	sparseMatrix* ptrEOD = colManager;
	CLLL* clllManager = NULL;
	CLLL* tempCLLL;

	colManager = colManager->nextCol;

	if (colManager != ptrEOD)
	{
		insertLastCLLL(&clllManager);
		clllManager->info = colManager->info;
	}

	colManager = colManager->nextCol;

	while (colManager != ptrEOD)
	{
		insertEndCLLL(&clllManager);
		clllManager->info = colManager->info;

		colManager = colManager->nextCol;
	}

	return (clllManager);
}

void exchangeRows(sparseMatrix* manager, int rowOne, int rowTwo)
{
	// In progress ! :)
}
