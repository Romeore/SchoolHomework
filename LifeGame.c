//LifeGame.c

#include "AlonSparseMatrix.h"

//----------------------------------------------------------------------
//                              Check Cell
//                              ----------
//
// General      : This function adds to a new sparse matrix according
//                to the Life Game rules.
//
// Parameters   : 
//			manager    - the manager. (sparseMatrix*)
//          newManager - the new manager. (sparseMatrix*)
//          row        - the row of the cell. (Int)
//          col        - the column of the cell. (Int)
//          rowLength  - the length of the rows. (Int)
//          colLength  - the length of the columns. (Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void checkCell(sparseMatrix* manager, sparseMatrix* newManager, int row,
	int col, int rowLength, int colLength)
{
	int neighbors = countNeighborsCreatures(manager, row, col, rowLength, colLength);
	BOOLEAN isExists = isItemExistsSparseMatrix(manager, row, col);

	if (isExists && neighbors > ONE && neighbors < FOUR)
	{
		addItemSparseMatrix(newManager, row, col);
	}
	
	if (!isExists && neighbors == TWO)
	{
		addItemSparseMatrix(newManager, row, col);
	}

	return;
}

//----------------------------------------------------------------------
//                        Generate Next Generation
//                        ------------------------
//
// General      : This function generates a new generation.
//
// Parameters   : 
//			manager    - the pointer of the manager. (sparseMatrix**)
//          newManager - the new generation manager. (sparseMatrix*)
//          rowLength  - the length of the rows. (Int)
//          colLength  - the length of the columns. (Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void generateNextGeneration(sparseMatrix** manager, sparseMatrix* newManager, int rowLength, int columnLength)
{
	int rowCounter;
	int colCounter;

	for (rowCounter = ZERO; rowCounter < rowLength; rowCounter++) {
		for (colCounter = ZERO; colCounter < columnLength; colCounter++) {
			checkCell(*manager, newManager, rowCounter, colCounter, rowLength, columnLength);
		}
	}

	freeSparseMatrix(manager);
	*manager = newManager;
	worldRules(manager, rowLength, columnLength);

	return;
}

//----------------------------------------------------------------------
//                              World Rules
//                              -----------
//
// General      : This functions changes the world according to the 
//                world rules.
//
// Parameters   : 
//			manager    - the pointer of the manager. (sparseMatrix**)
//          rowLength  - the length of the rows. (Int)
//          colLength  - the length of the columns. (Int)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void worldRules(sparseMatrix** manager, int rowLength, int colLength)
{
	int countCreaturesPrecent = countNodesSparseMatrix(*manager) / (rowLength * colLength);

	// Earthquake
	if (countCreaturesPrecent > FIFTY)
	{
		deleteNumOfColsSparseMatrix(manager, (TEN / colLength) * HUNDRED);
		deleteNumOfRowsSparseMatrix(manager, (TEN / rowLength) * HUNDRED);
	}

	// Disease
	if(countCreaturesPrecent == THIRTY)
	{
		deleteNumOfRowsSparseMatrix(manager, 
			(FIFTEEN / (colLength + rowLength)) * HUNDRED);
	}
	
	// Drying Lakes
	if (countCreaturesPrecent == FOURTY)
	{
		addNumOfColsSparseMatrix(manager,
			(FIFTEEN / (colLength + rowLength)) * HUNDRED);
	}

	// Ocean warming
	if (countCreaturesPrecent < TWENTY)
	{
		addNumOfColsSparseMatrix(manager, (FIVE / colLength) * HUNDRED);
		addNumOfRowsSparseMatrix(manager, (FIVE / rowLength) * HUNDRED);
	}

	return;
}

//----------------------------------------------------------------------
//                      Count Neighbors Creatures
//                      -------------------------
//
// General      : This function counts the number of neighbors in the
//                sparse matrix.
//
// Parameters   : 
//			manager   - the manager. (sparseMatrix*)
//          row       - the row of the item. (Int)
//          col       - the column of the item. (Int)
//          rowLength - the row's length. (Int)
//          colLength - the column's length. (Int)
//
// Return Value : returns the amount of neighbors around the specific
//                square.
//
//----------------------------------------------------------------------

int countNeighborsCreatures(sparseMatrix* manager, int row, int col, int rowLength, int colLength)
{
	int counterNeighbors = ZERO;
	int rowFinish;
	int colFinish;
	int colCounter;
	int colStart;
	int rowCounter;

	(row == ZERO) ? (rowCounter = ZERO) : (rowCounter = row - ONE);

	(col == ZERO) ? (colStart = ZERO) : (colStart = col - ONE);

	(col == colLength) ? (colFinish = col + ONE) : (colFinish = col + TWO);

	(row == rowLength) ? (rowFinish = row + ONE) : (rowFinish = row + TWO);

	for (; rowCounter < rowFinish; rowCounter++) {
		for (colCounter = colStart; colCounter < colFinish; colCounter++) {
			if (isItemExistsSparseMatrix(manager, rowCounter, colCounter))
			{
				counterNeighbors++;
			}
		}
	}

	return (counterNeighbors);
}

//-----------------------------------------------------------------------------
//                                   Life Game
//                                   ---------
//
// General : This program manages the Life Game.
//
// Input   : number of generations. 
//
// Process : Make new generation according to the world and life game rules.
//
// Output  : prints each generation.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 27.12.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable defintion
	int           numOfGenerations = ZERO;
	int           counter;
	int           rowsNum = TWENTYFIVE;
	int           colsNum = TWENTYFIVE;
	sparseMatrix* manager = NULL;
	sparseMatrix* newManager = NULL;

	// Code section

	// Init the sparse matrices.
	initSparseMatrix(&manager, rowsNum, colsNum);
	initSparseMatrix(&newManager, rowsNum, colsNum);

	// Get the number of generations.
	printf("Write the number of generations \n");
	scanf("%d", &numOfGenerations);

	// Start making generations.
	for (counter = ZERO; counter < numOfGenerations; counter++)
	{
		// Generate a new generation.
		generateNextGeneration(&manager, newManager, numOfRows(manager), numOfCols(manager));
		rowsNum = numOfRows(manager);
		colsNum = numOfCols(manager);
		// Print the currect generation.
		printSparseMatrix(manager, rowsNum, colsNum);
		// Make a new matrix to save the next generation.
		freeSparseMatrix(&newManager);
		newManager = NULL;
		initSparseMatrix(&newManager, rowsNum, colsNum);
	}
	// Free the temp sparse matrix.
	freeSparseMatrix(&newManager);

	printf("\n Thank you for playing the Life Game. \n");
}
