#pragma once

#include "Atomic.h"

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

void initSparseMatrix(sparseMatrix** manager, int rowLength, int colLength)
{
	*(manager) = (sparseMatrix*)malloc(sizeof(sparseMatrix));
	sparseMatrix* saveManager = *manager;

	// Init the manager
	(*manager)->nextRow = *manager;
	(*manager)->nextCol = *manager;
	(*manager)->col = MANAGERMARK;
	(*manager)->row = MANAGERMARK;

	// Init rows
	addNumOfRowsSparseMatrix(manager, rowLength);
	*manager = saveManager;
	// Init columns
	addNumOfColsSparseMatrix(manager, colLength);
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
//                      Add Num Of Rows Sparse Matrix
//                      -----------------------------
//
// General      : This function adds num of new rows to the sparse 
//                matrix.
//
// Parameters   : 
//			manager   - the pointer of the manager. (sparseMatrix**)
//          numOfRows - number of rows to add. 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addNumOfRowsSparseMatrix(sparseMatrix** manager, int numOfRows)
{
	int counter;

	for (counter = ZERO; counter < numOfRows; counter++)
	{
		addRowSparseMatrix(manager);
	}

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
//                      Add Num Of Cols Sparse Matrix
//                      -----------------------------
//
// General      : This function adds num of new columns to the 
//                sparse matrix.
//
// Parameters   : 
//			manager   - the pointer of the manager. (sparseMatrix**)
//          numOfCols - number of columns to add. 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addNumOfColsSparseMatrix(sparseMatrix** manager, int numOfCols)
{
	int counter;

	for (counter = ZERO; counter < numOfCols; counter++)
	{
		addColSparseMatrix(manager);
	}

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
//                        Add Item Sparse Matrix
//                        ----------------------
//
// General      : This function adds a new item to the sparse matrix.
//
// Parameters   : 
//          manager - The manager of the sparse matrix(sparseMatrix*)
//          row     - The row that the item will be added(int)
//          col     - The column that the item will be added(int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addItemSparseMatrix(sparseMatrix* manager, int row, int col)
{
	sparseMatrix* rowManager = findRowSparseMatrix(manager, row);
	sparseMatrix* colManager = findColSparseMatrix(manager, col);

	rowManager = findAbove(rowManager, col);
	colManager = findBefore(colManager, row);
	insertAfterSparseMatrix(&colManager, &rowManager);

	rowManager->nextCol->col = col;
	colManager->nextRow->row = row;

	return;
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

void storeSparseMatrixInfo(sparseMatrix* manager, int row, int col, int info)
{
	sparseMatrix* ptrCurrectNode = findColSparseMatrix(manager, col);
	ptrCurrectNode = findBefore(ptrCurrectNode, row);
	ptrCurrectNode->info = info;

	return;
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

void storeSparseMatrixNextTurnInfo(sparseMatrix* manager, int row, int col, int nextTurnInfo)
{
	sparseMatrix* ptrCurrectNode = findColSparseMatrix(manager, col);
	ptrCurrectNode = findBefore(ptrCurrectNode, row);
	ptrCurrectNode->nextTurnInfo = nextTurnInfo;

	return;
}

//----------------------------------------------------------------------
//                         Delete Item Sparse Matrix
//                         -------------------------
//
// General      : This function removes an item from the sparse matrix.
//
// Parameters   : 
//			manager - the manager. (sparseMatrix*)
//          row     - the row number of the item. (int)
//          col     - the column number of the item. (int)
//
// Return Value : None.
//
//----------------------------------------------------------------------



void deleteItemSparseMatrix(sparseMatrix* manager, int row, int col)
{
	sparseMatrix* temp;
	sparseMatrix* rowManager = findRowSparseMatrix(manager, row);
	sparseMatrix* colManager = findColSparseMatrix(manager, col);
	sparseMatrix* abovePtr = findAbove(rowManager, col);
	sparseMatrix* beforePtr = findBefore(colManager, row);

	printf("Reached to delete \n\n\n\n");
	if (abovePtr->nextRow == beforePtr->nextCol)
	{
		temp = abovePtr->nextRow;
		abovePtr->nextRow = temp->nextRow;
		beforePtr->nextCol = temp->nextCol;
		free(temp);
	}
}

//----------------------------------------------------------------------
//                      Find Item Sparse Matrix
//                      -----------------------
//
// General      : This function finds an item in the sparse matrix.
//
// Parameters   : 
//			manager - the manager. (sparseMatrix*)
//          row     - the number of row to check. (Int)
//          col     - the number of column to check. (Int)
//
// Return Value : returns the address of the item if it exists, else
//                NULL.
//
//----------------------------------------------------------------------

sparseMatrix* findItemSparseMatrix(sparseMatrix* manager, int row, int col)
{
	sparseMatrix* neededItem = NULL;
	sparseMatrix* rowManager = findRowSparseMatrix(manager, row);
	sparseMatrix* ptrEOD = rowManager;

	rowManager = rowManager->nextCol;

	while (rowManager != ptrEOD)
	{
		if (rowManager->col == col)
		{
			neededItem = rowManager;
		}
		rowManager = rowManager->nextCol;
	}

	return (neededItem);
}



//----------------------------------------------------------------------
//                            Init Board
//                            ----------
//
// General      : This function initializes the board of the atomic
//                bombs.
//
// Parameters   : 
//			manager - the pointer of the manager(sparseMatrix**)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initBoard(sparseMatrix** manager)
{
	// Open file
	FILE* atomicFile = fopen("atomicBombs.dat", "rb");
	int row;
	int column;
	int numOfBombs;
	int counter;

	// Init sparse matrix board
	initSparseMatrix(manager, ROWLENGTH, COLUMNLENGTH);

	// Read number of bombs.
	fread(&numOfBombs, sizeof(int), ONE, atomicFile);

	// Add bombs to the board.
	for (counter = ZERO; counter < numOfBombs; counter++)
	{
		fread(&column, sizeof(int), ONE, atomicFile);
		fread(&row, sizeof(int), ONE, atomicFile);
		addItemSparseMatrix((*manager), row, column);
		// Store into the item its an atom.
		storeSparseMatrixInfo((*manager), row, column, ATOM);
		storeSparseMatrixNextTurnInfo((*manager), row, column, ATOM);
	}

	// Close file
	fclose(atomicFile);
}













//----------------------------------------------------------------------
//                            Set Next Value
//                            --------------
//
// General      : This function sets the next value of an item.
//
// Parameters   : 
//			manager       - the manager (sparseMatrix*)
//          tempNode      - a specific item. (sparseMatrix*)
//          numOfNeutrons - the pointer to the number of neutrons (int*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void setNextValue(sparseMatrix* manager, sparseMatrix* tempNode,
	              int* numOfNeutrons)
{
	switch (tempNode->info)
	{
	case UP:
		if (tempNode->col != ZERO)
		{
			addItemSparseMatrix(manager, tempNode->row, tempNode->col - ONE);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row,
				                          tempNode->col - ONE, tempNode->info);
			(*numOfNeutrons)++;
		}
		break;
	case DOWN: 
		if (tempNode->col != COLUMNLENGTH - ONE)
		{
			addItemSparseMatrix(manager, tempNode->row, tempNode->col + ONE);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row,
				                          tempNode->col + ONE, tempNode->info);
			(*numOfNeutrons)++;
		}
		break;

	case LEFT:
		if (tempNode->row != ZERO)
		{
			addItemSparseMatrix(manager, tempNode->row - ONE, tempNode->col);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row - ONE, 
				                          tempNode->col, tempNode->info);
			(*numOfNeutrons)++;
		}
		break;

	case RIGHT:
		if (tempNode->row != ROWLENGTH - ONE)
		{
			addItemSparseMatrix(manager, tempNode->row + ONE, tempNode->col);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row + ONE,
				                          tempNode->col, tempNode->info);
			(*numOfNeutrons)++;
		}
		break;

	case EXPLOADINGATOM:
		if (tempNode->row != ROWLENGTH - ONE)
		{
			addItemSparseMatrix(manager, tempNode->row + ONE, tempNode->col);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row + ONE,
				                          tempNode->col, tempNode->info);
			(*numOfNeutrons)++;
		}
		if (tempNode->row != ZERO)
		{
			addItemSparseMatrix(manager, tempNode->row - ONE, tempNode->col);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row - ONE, 
				                          tempNode->col, tempNode->info);
			(*numOfNeutrons)++;
		}
		if (tempNode->col != COLUMNLENGTH - ONE)
		{
			addItemSparseMatrix(manager, tempNode->row, tempNode->col + ONE);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row,
				                          tempNode->col + ONE, tempNode->info);
			(*numOfNeutrons)++;
		}
		if (tempNode->col != ZERO)
		{
			addItemSparseMatrix(manager, tempNode->row, tempNode->col - ONE);
			storeSparseMatrixNextTurnInfo(manager, tempNode->row,
				                          tempNode->col - ONE, tempNode->info);
			(*numOfNeutrons)++;
		}
		break;

	default: break;
	}
}











//----------------------------------------------------------------------
//                          Add Next Values
//                          ---------------
//
// General      : This function sets the next value in the sparse
//                matrix items.
//
// Parameters   : 
//			manager       - the manager (sparseMatrix*)
//          numOfNeutrons - the pointer to the number of neutrons (int*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addNextValues(sparseMatrix* manager, int* numOfNeutrons)
{
	sparseMatrix* lastRowPtr = findRowSparseMatrix(manager, ROWLENGTH);
	sparseMatrix* rowManager = manager->nextRow;
	sparseMatrix* tempNode = rowManager->nextCol;

	while (tempNode != lastRowPtr)
	{
		if (rowManager == tempNode)
		{
			rowManager = rowManager->nextRow;
			tempNode = rowManager->nextCol;
		}
		else
		{
			setNextValue(manager, tempNode, &numOfNeutrons);
			tempNode = tempNode->nextCol;
		}
	}
}

//----------------------------------------------------------------------
//                    Change Currect Item State
//                    -------------------------
//
// General      : This function changes specific item state in the 
//                sparse matrix.
//
// Parameters   : 
//			manager       - the manager (sparseMatrix*)
//          tempNode      - the currect item (sparseMatrix*)
//          numOfNeutrons      - the pointer to the neutrons count(int*)
//          numOfExplodingAtom - the pointer to the exploded atoms
//                               count (int*)
//
// Return Value : Returns the next address of an item in the sparse
//                matrix.
//
//----------------------------------------------------------------------

sparseMatrix* changeCurrectItemState(sparseMatrix* manager,
	                                 sparseMatrix* tempNode,
                                     int* numOfNeutrons,
                                 	 int* numOfExplodingAtom)
{
	sparseMatrix* nextItemPtr = tempNode;
	// If nothing is changing in the node, or two or more neutrons have
	// reached the same spot, delete this spot.
	if (tempNode->nextTurnInfo == ZERO ||
		(tempNode->nextTurnInfo >= DOWN && tempNode->nextTurnInfo != RIGHT
			&& tempNode->nextTurnInfo < ATOM))
	{
		// Save before deleting
		nextItemPtr = nextItemPtr->nextCol;
		// Increace the amount of atoms that exploded.
		(tempNode->info == EXPLOADINGATOM) ? 
			(*numOfExplodingAtom)++ : numOfExplodingAtom;
		// Delete the item.
		deleteItemSparseMatrix(manager, tempNode->row, tempNode->col);
	}

	else {
		// Change currect state to the neutron value.
		if (tempNode->nextTurnInfo <= DOWN 
			|| tempNode->nextTurnInfo == RIGHT)
		{
			tempNode->info = tempNode->nextTurnInfo;
		}
		// If one or more neturons have reached an atom explode it,
		// else change currect spot to the next spot value.
		(tempNode->info == ATOM && tempNode->nextTurnInfo > ATOM) ?
			(tempNode->info = EXPLOADINGATOM) : 
			(tempNode->info = tempNode->nextTurnInfo);

		// Reset the next turn value.
		(tempNode->info == ATOM) ?
			(tempNode->nextTurnInfo = ATOM) : (tempNode->nextTurnInfo = ZERO);
		// Move to the next item.
		nextItemPtr = nextItemPtr->nextCol;
	}

	return (nextItemPtr);
}

















//----------------------------------------------------------------------
//                           Change States
//                           -------------
//
// General      : This function changes the sparse matrix items state
//                from currect turn to the next turn.
//
// Parameters   : 
//			manager            - the manager (sparseMatrix*)
//          numOfNeutrons      - the pointer to the neutrons count(int*)
//          numOfExplodingAtom - the pointer to the exploded atoms
//                               count (int*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void changeStates(sparseMatrix* manager, int* numOfNeutrons,
	              int* numOfExplodingAtom)
{
	sparseMatrix* lastRowPtr = findRowSparseMatrix(manager, ROWLENGTH);
	sparseMatrix* rowManager = manager->nextRow;
	sparseMatrix* tempNode = rowManager->nextCol;
	
	while (tempNode != lastRowPtr)
	{
		// If the pointer value is a manager, move to the next row.
		if (rowManager == tempNode)
		{
			rowManager = rowManager->nextRow;
			tempNode = rowManager->nextCol;
		}
		// else, change the currect item state.
		else
		{
			tempNode = changeCurrectItemState(manager, tempNode, 
				                              numOfNeutrons,
				                              numOfExplodingAtom);
		}
	}
}










//----------------------------------------------------------------------------
//                                    Atomic
//                                    ------
//
// General : This program manages the Atomic game.
//
// Input   : The atom to explode.
//
// Process : Add next value turns for the items in the sparse matrix, and then
//           change the currect state according to the next value turns.
//
// Output  : The number of atoms that exploded during the process.
//
//----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 28.01.2020
//----------------------------------------------------------------------------

void main(void)
{
	// Variable defintion
	sparseMatrix* manager;
	int numOfNeutrons = ZERO;
	int numOfExplodingAtoms = ZERO;
	int rowToExplode;
	int columnToExplode;
	sparseMatrix* startingAtom;

	// Code section

	// Init the board.
	initBoard(&manager);
	// Get the atom to explode.
	printf("Please select a atom to explode\n");
	printf("Write the row of the atom:\n");
	scanf("%d", &rowToExplode);
	printf("Write the column of the atom: \n");
	scanf("%d", &columnToExplode);

	// Explode the atom.
	startingAtom = findItemSparseMatrix(manager, rowToExplode, columnToExplode);
	startingAtom->info = EXPLOADINGATOM;
	setNextValue(manager, startingAtom, &numOfNeutrons);
	changeCurrectItemState(manager, startingAtom, &numOfNeutrons, &numOfExplodingAtoms);
	
	// Start moving neutrons.
	while (numOfNeutrons != ZERO)
	{
		// Add next value turns.
		addNextValues(manager, &numOfNeutrons);
		// Change states according to next value turns.
		changeStates(manager, &numOfNeutrons, &numOfExplodingAtoms);
	}

	// Game is over.
	printf("There is no exploding anymore !\n");
	printf("The number of atoms that exploded is : %d", numOfExplodingAtoms);
}
