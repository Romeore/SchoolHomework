//Enterprise.c
#pragma once

#include <stdio.h>

#define ZERO    0
#define ONE     1
#define TWO     2
#define THREE   3
#define EIGHT   8
#define FIFTEEN 15
#define BOOLEAN unsigned short
#define TRUE    1
#define FALSE   0
#define ABS(x)  (x > 0) ? (x) : (-x)

typedef struct Creature
{
	int  creatureCode;
	char creatureName[EIGHT];
	char bornPlanet[FIFTEEN];
	int  age;
} Creature;

//----------------------------------------------------------------------
//                         Binary Search File
//                         ------------------
//
// General      : This function moves the file pointer to the creature
//                code with binary search.
//
// Parameters   : 
//			ptrStarShipFile - A pointer to the file (FILE**)		
//          creatureCode    - The code to search the creature.
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void binarySearchFile (FILE** ptrStarShipFile, int creatureCode)
{
	Creature tempCreature;
	BOOLEAN foundCode = FALSE;
	int limitBottom = ZERO;
	int limitTop;
	int mid;

	// Find the amount of creatures.
	fseek(*ptrStarShipFile, 0, SEEK_END);
	limitTop = (ftell(*ptrStarShipFile) / sizeof(Creature)) - ONE;

	// Find the place of the code.
	while (limitTop >= limitBottom && (!foundCode))
	{
		mid = (limitTop + limitBottom) / TWO;
		fseek(*ptrStarShipFile, sizeof(Creature) * mid, SEEK_SET);
		fread(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile);

		if (tempCreature.creatureCode == creatureCode)
		{
			foundCode = TRUE;
		}

		(tempCreature.creatureCode > creatureCode) ?
			(limitTop = mid - ONE) : (limitBottom = mid + ONE);
	}

	// Move one place back to read the place again.
	fseek(*ptrStarShipFile, -(long)(sizeof(Creature)), SEEK_CUR);
	return;
}

//----------------------------------------------------------------------
//                         Binary Add To File
//                         ------------------
//
// General      : This function moves the file pointer to the creature
//                code with binary search to add to the file.
//
// Parameters   : 
//			ptrStarShipFile - A pointer to the file (FILE**)		
//          creatureCode    - The code to search the creature.
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void binaryAddToFile(FILE** ptrStarShipFile, int creatureCode)
{
	Creature tempCreature;
	BOOLEAN foundCode = FALSE;
	int limitBottom = ZERO;
	int limitTop;
	int mid;
	int size;

	// Find the amount of creatures.
	fseek(*ptrStarShipFile, 0, SEEK_END);
	size = (ftell(*ptrStarShipFile)) / sizeof(Creature) - ONE;
	limitTop = size;
	
	// Find the place of the closest code to the input code.
	while (limitTop >= limitBottom)
	{
		mid = (limitTop + limitBottom) / TWO;
		fseek(*ptrStarShipFile, sizeof(Creature) * mid, SEEK_SET);
		fread(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile);

		(tempCreature.creatureCode > creatureCode) ?
			(limitTop = mid - ONE) : (limitBottom = mid + ONE);
	}

	// If the limit top is minus, make it positive.
	limitTop = ABS(limitTop);
	// Check if the currect creature code is bigger than the new one
	fseek(*ptrStarShipFile, sizeof(Creature) * limitTop, SEEK_SET);
	fread(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile);
	// If its bigger, add it before the currect creature code.
	(tempCreature.creatureCode > creatureCode) ? limitTop-- : limitTop;

	// Move the creatures that above the creature code one place.
	for (; limitTop < size; size--)
	{
		fseek(*ptrStarShipFile, sizeof(Creature) * (size), SEEK_SET);
		fread(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile);
		fseek(*ptrStarShipFile, ZERO, SEEK_CUR);
		fwrite(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile);
	}

	// Place the file pointer to the writeable place.
	fseek(*ptrStarShipFile, sizeof(Creature) * (limitTop + ONE), SEEK_SET);

	return;
}

//----------------------------------------------------------------------
//                           Print Creature
//                           --------------
//
// General      : This function prints a creature.
//
// Parameters   : 
//			ptrCreature - A pointer to creature (creature*)
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void printCreature(Creature* ptrCreature)
{
	// Print the creature parameters.
	printf("\nCreature code: %d\n", ptrCreature->creatureCode);
	printf("\nCreature name: %s\n", ptrCreature->creatureName);
	printf("\nBorn planet: %s\n", ptrCreature->bornPlanet);
	printf("\nAge: %d\n", ptrCreature->age);

	return;
}

//----------------------------------------------------------------------
//                           Print All Creatures
//                           -------------------
//
// General      : This function prints all creatures in the file.
//
// Parameters   : None. 
//			
// Return Value : None. 
//
//----------------------------------------------------------------------

void printAllCreatures()
{
	// Open file
	FILE* starShipFile = fopen("starship.dat", "rb");
	Creature tempCreature;

	// Print each creature in the file
	while (fread(&tempCreature, sizeof(Creature), ONE, starShipFile))
	{
		printCreature(&tempCreature);
	}
	
	// Close file
	fclose(starShipFile);

	return;
}

//----------------------------------------------------------------------
//                         Is Creature Code Exist
//                         ----------------------
//
// General      : This function finds if a code is in the file.
//
// Parameters   : 
//          creatureCode - The code to search the creature.
//
// Return Value : returns TRUE if there is a creature with the code,
//                else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isCreatureCodeExist(FILE* starShipFile, int creatureCode)
{
	BOOLEAN foundCode;
	Creature tempCreature;

	// Find the place to read the creature that matches the code.
	binarySearchFile(&starShipFile, creatureCode);
	fread(&tempCreature, sizeof(Creature), ONE, starShipFile);

	// Check if the read is success.
	(tempCreature.creatureCode == creatureCode) ?
		(foundCode = TRUE) : (foundCode = FALSE);

	return (foundCode);
}

//----------------------------------------------------------------------
//                           Scan A Creature
//                           ---------------
//
// General      : This function scans a creature.
//
// Parameters   : 
//          inputCreature - A pointer to a creature to scan.
//
// Return Value : None.
//
//----------------------------------------------------------------------

void scanACreature(Creature* inputCreature)
{
	// Scan the creature parameters.
	printf("\nPlease write the creature name\n");
	scanf("%s", inputCreature->creatureName);

	printf("\nPlease write the born planet\n");
	scanf("%s", inputCreature->bornPlanet);

	printf("\nPlease write the creatures age\n");
	scanf("%d", &(inputCreature->age));

	return;
}

//----------------------------------------------------------------------
//                            Add A Creature
//                            --------------
//
// General      : This function adds a creature to the file.
//
// Parameters   : None. 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void addACreature()
{
	// Open file
	FILE* starShipFile = fopen("starship.dat", "r+b");
	Creature addedCreature;
	
	// Get the creature code.
	printf("\nPlease write the creature code\n");
	scanf("%d", &addedCreature.creatureCode);

	// Checks if the code already exists, and if it does, ask again.
	while (isCreatureCodeExist(starShipFile, addedCreature.creatureCode))
	{
		printf("\nThe creature code already exists, please write another code.\n");
		scanf("%d", &addedCreature.creatureCode);
	}

	// Scan the added creature.
	scanACreature(&addedCreature);
	// Find its place on the file and write it.
	binaryAddToFile(&starShipFile, addedCreature.creatureCode);
	fwrite(&addedCreature, sizeof(Creature), ONE, starShipFile);
	
	// Close file
	fclose(starShipFile);

	return;
}

//----------------------------------------------------------------------
//                            Update A Creature
//                            -----------------
//
// General      : This function updates a creature in the file.
//
// Parameters   : None. 
//
// Return Value : None.
//
//----------------------------------------------------------------------

void updateACreature()
{
	// Open file
	FILE* starShipFile = fopen("starship.dat", "r+b");
	Creature updatedCreature;

	// Get the creature code.
	printf("\nWrite the creature code of a creature you want to change\n");
	scanf("%d", &(updatedCreature.creatureCode));

	while (!isCreatureCodeExist(starShipFile, updatedCreature.creatureCode))
	{
		printf("\nThe creature code is not found, please write a valid code.\n");
		scanf("%d", &(updatedCreature.creatureCode));
	}

	// Scan the updated creature.
	scanACreature(&updatedCreature);
	// Find its place on the file and write it.
	binarySearchFile(&starShipFile, updatedCreature.creatureCode);
	fwrite(&updatedCreature, sizeof(Creature), ONE, starShipFile);

	// Close file
	fclose(starShipFile);

	return;
}

//-----------------------------------------------------------------------------
//                                   Enterprise
//                                   ----------
//
// General : This program manages creatures that the enterprise finds.
//
// Input   : Option.
//
// Process : Act like the option (add a creature, update a creature, print all
//                                creatures or finish).
//
// Output  : A file with the new changes that the user changed.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Vaisgur
// Student No : 322954694
// Date       : 18.12.2019
//-----------------------------------------------------------------------------

void main(void)
{
	// Variable definition
	BOOLEAN isFinished = FALSE;
	int option;

	// Code section

	while (!isFinished)
	{
		// Show options
		printf("\nPlease select an option:\n");
		printf("1. Print all creatures.\n");
		printf("2. Add a new creature.\n");
		printf("3. Update a creature\n");
		printf("4. Exit.\n");
		// Get the user's pick.
		scanf("%d", &option);
		
		// Act like user's pick.
		switch (option)
		{
		case ONE: printAllCreatures();
			break;
		case TWO: addACreature();
			break;
		case THREE: updateACreature();
			break;

		default: isFinished = TRUE;
			break;
		}
	}
	
	// End print
	printf("\nThank you for using !\n");
}
