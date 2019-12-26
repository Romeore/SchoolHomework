//AlonSparseMatrix.c
#pragma once

#include "AlonSparseMatrix.h"

//----------------------------------------------------------------------
//                          Init Sparse Matrix
//                          ------------------
//
// General      : This function initilaizes sparse matrix.
//
// Parameters   : 
//			manager - A pointer to the manager(sparseMatrix**)
//          row     - The number of rows to add(int)
//          col     - The number of columns to add(int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initSparseMatrix(sparseMatrix** manager, int row, int col)
{
	*manager = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sparseMatrix* saveManager = *manager;
	int counter;

	(*manager)->nextRow = *manager;
	(*manager)->nextCol = *manager;
	(*manager)->col = -1;
	(*manager)->row = -1;

	for (counter = ZERO; counter < row; counter++)
	{
		addRowSparseMatrix(manager);
	}

	for (counter = ZERO; counter < col; counter++)
	{
		addColSparseMatrix(manager);
	}

	*manager = saveManager;

	return;
}

//----------------------------------------------------------------------
//                        Add Row Sparse Matrix
//                        ---------------------
//
// General      : This function adds a new row to the sparse matrix.
//
// Parameters   : 
//			manager - the pointer of the manager(sparseMatrix**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addRowSparseMatrix(sparseMatrix** manager)
{
	sparseMatrix* ptrEOD = *manager;
	sparseMatrix* newRow = (sparseMatrix*)malloc(sizeof(sparseMatrix));

	while ((*manager)->nextRow != ptrEOD)
	{
		(*manager) = (*manager)->nextRow;
	}

	(*manager)->nextRow = newRow;
	newRow->nextRow = ptrEOD;
	newRow->nextCol = newRow;
	newRow->col = MANAGERMARK;
	newRow->row = (*manager)->row + ONE;
	*manager = ptrEOD;

	return;
}

//----------------------------------------------------------------------
//                        Add Col Sparse Matrix
//                        ---------------------
//
// General      : This function adds a new column to the sparse matrix.
//
// Parameters   : 
//			manager - the pointer of the manager(sparseMatrix**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addColSparseMatrix(sparseMatrix** manager)
{
	sparseMatrix* ptrEOD = *manager;
	sparseMatrix* newCol = (sparseMatrix*)malloc(sizeof(sparseMatrix));

	while ((*manager)->nextCol != ptrEOD)
	{
		(*manager) = (*manager)->nextCol;
	}

	(*manager)->nextCol = newCol;
	newCol->nextCol = ptrEOD;
	newCol->nextRow = newCol;
	newCol->row = MANAGERMARK;
	newCol->col = (*manager)->col + ONE;
	*manager = ptrEOD;

	return;
}

//----------------------------------------------------------------------
//                        Find Row Sparse Matrix
//                        ----------------------
//
// General      : This function finds the row on the sparse matrix.
//
// Parameters   : 
//			manager - The value of the manager(sparseMatrix*)
//          row     - The number of the row(Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

sparseMatrix* findRowSparseMatrix(sparseMatrix* manager, int row)
{
	int counter;

	for (counter = -1; counter < row; counter++)
	{
		manager = manager->nextRow;
	}

	return (manager);
}

//----------------------------------------------------------------------
//                        Find Col Sparse Matrix
//                        ----------------------
//
// General      : This function finds the column on the sparse matrix.
//
// Parameters   : 
//			manager - The value of the manager(sparseMatrix*)
//          col     - The number of the column(Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

sparseMatrix* findColSparseMatrix(sparseMatrix* manager, int col)
{
	int counter;

	for (counter = -1; counter < col; counter++)
	{
		manager = manager->nextCol;
	}

	return (manager);
}

//----------------------------------------------------------------------
//                             Find Above
//                             ----------
//
// General      : This function finds the column above the wanted node.
//
// Parameters   : 
//			manager - The value of the manager(sparseMatrix*)
//          col     - The number of the column(Int)
//
// Return Value : The node that above the needed column.
//
//----------------------------------------------------------------------

sparseMatrix* findAbove(sparseMatrix* manager, int col)
{
	sparseMatrix* ptrEOD = manager;
	manager = manager->nextCol;
	while (manager->nextCol != ptrEOD && manager->nextCol->col < col)
	{
		manager = manager->nextCol;
	}

	return (manager);
}

//----------------------------------------------------------------------
//                             Find Before
//                             -----------
//
// General      : This function finds the row above the wanted node.
//
// Parameters   : 
//			manager - The value of the manager(sparseMatrix*)
//          row     - The number of the row(Int)
//
// Return Value : The node that above the needed row.
//
//----------------------------------------------------------------------

sparseMatrix* findBefore(sparseMatrix* manager, int row)
{
	sparseMatrix* ptrEOD = manager;
	manager = manager->nextRow;
	while (manager->nextRow != ptrEOD && manager->nextRow->row < row)
	{
		manager = manager->nextRow;
	}

	return (manager);
}

//----------------------------------------------------------------------
//                        Insert After Sparse Matrix
//                        --------------------------
//
// General      : This function inserts a new node to the sparse matrix.
//
// Parameters   : 
//			ptrBefore - pointer that before the new node(sparseMatrix**)
//          ptrAbove  - pointer that above the new node(sparseMatrix**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertAfterSparseMatrix(sparseMatrix** ptrBefore, sparseMatrix** ptrAbove)
{
	sparseMatrix* newSM = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sparseMatrix* temp;

	temp = (*ptrAbove)->nextCol;
	(*ptrAbove)->nextCol = newSM;
	newSM->nextCol = temp;

	temp = (*ptrBefore)->nextRow;
	(*ptrBefore)->nextRow = newSM;
	newSM->nextRow = temp;

	return;
}

//----------------------------------------------------------------------
//                        Add Item Sparse Matrix
//                        ----------------------
//
// General      : This function adds a new item to the sparse matrix.
//
// Parameters   : 
//          manager - The manager of the sparse matrix(sparseMatrix*)
//          row     - The row that the item will be added(int)
//          col     - The column that the item will be added(int)
//          info    - The info that will be in the item.(Any type)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addItemSparseMatrix(sparseMatrix* manager, int row, int col, TYPE info)
{
	sparseMatrix* rowManager = findRowSparseMatrix(manager, row);
	sparseMatrix* colManager = findColSparseMatrix(manager, col);

	rowManager = findAbove(rowManager, col);
	colManager = findBefore(colManager, row);
	insertAfterSparseMatrix(&colManager, &rowManager);

	rowManager->nextCol->col = col;
	colManager->nextRow->row = row;
	rowManager->nextCol->info = info;

	return;
}

//----------------------------------------------------------------------
//                        Print Sparse Matrix Node
//                        ------------------------
//
// General      : This function prints a sparse matrix node.
//
// Parameters   : 
//          sparseMatrixNode - The node to print(sparseMatrix*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printSparseMatrixNode(sparseMatrix* sparseMatrixNode)
{
	printf("\nThe node is on row: %d\n", sparseMatrixNode->row);
	printf("\nThe node is on col: %d\n", sparseMatrixNode->col);
	printf("\nThe node info is: %d\n", sparseMatrixNode->info);

	return;
}

//----------------------------------------------------------------------
//                        Mul Col Sparse Matrix
//                        ---------------------
//
// General      : This function multiplays specific column by number.
//
// Parameters   : 
//          manager - the manager of the sparseMatrix(sparseMatrix*)
//          row     - the number of the row to multiplay(Int)
//          number  - the number to multiplay(int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void mulColSparseMatrix(sparseMatrix* manager, int row, int number)
{
	sparseMatrix* ptrRow = findRowSparseMatrix(manager, row);
	sparseMatrix* ptrEOD = ptrRow;

	ptrRow = ptrRow->nextCol;

	while (ptrRow != ptrEOD)
	{
		ptrRow->info *= number;
	}

	return;
}

//----------------------------------------------------------------------
//                      Make CLLL From Row Sparse Matrix
//                      --------------------------------
//
// General      : This function makes CLLL from a row in sparse matrix.
//
// Parameters   : 
//          rowManager - the manager of a specific row(sparseMatrix*)
//
// Return Value : CLLL with the items in the specific row.
//
//----------------------------------------------------------------------

CLLL* makeCLLLFromRowSparseMatrix(sparseMatrix* rowManager)
{
	sparseMatrix* ptrEOD = rowManager;
	CLLL* clllManager = NULL;

	rowManager = rowManager->nextRow;

	if (rowManager != ptrEOD)
	{
		insertLastCLLL(&clllManager);
		clllManager->info = rowManager->info;
	}

	rowManager = rowManager->nextRow;

	while (rowManager != ptrEOD)
	{
		insertEndCLLL(&clllManager);
		clllManager->info = rowManager->info;

		rowManager = rowManager->nextRow;
	}

	return (clllManager);
}

//----------------------------------------------------------------------
//                      Make CLLL From Col Sparse Matrix
//                      --------------------------------
//
// General      : This function makes CLLL from a column in sparse 
//                matrix.
//
// Parameters   : 
//          colManager - the manager of a specific column(sparseMatrix*)
//
// Return Value : CLLL with the items in the specific column.
//
//----------------------------------------------------------------------

CLLL* makeCLLLFromColSparseMatrix(sparseMatrix* colManager)
{
	sparseMatrix* ptrEOD = colManager;
	CLLL* clllManager = NULL;

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

//----------------------------------------------------------------------
//                         Store Sparse Matrix
//                         -------------------
//
// General      : This function stores an info in a specific node.
//
// Parameters   : 
//          manager - the manager of the sparse matrix(sparseMatrix*)
//          row     - the row of the node to insert the info(int)
//          col     - the column of the node to insert the info(int)
//          info    - the info that wanted to be added(Any type).
//
// Return Value : None.
//
//----------------------------------------------------------------------

void storeSparseMatrix(sparseMatrix* manager, int row, int col, TYPE info)
{
	sparseMatrix* ptrCurrectNode = findColSparseMatrix(manager, col);
	ptrCurrectNode = findBefore(ptrCurrectNode, row);
	ptrCurrectNode->info = info;

	return;
}
