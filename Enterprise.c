//Enterprise.c
#pragma once

#include "AlonStrings.h"

typedef struct Creature
{
	int  creatureCode;
	char creatureName[EIGHT];
	char bornPlanet[FIFTEEN];
	int  age;
} Creature;

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
	FILE* starShipFile = fopen("starship.dat", "rb");
	Creature tempCreature;

	while (fread(&tempCreature, sizeof(Creature), ONE, starShipFile))
	{
		printCreature(&tempCreature);
	}
	
	fclose(starShipFile);
	return;
}

//----------------------------------------------------------------------
//                         Seek To Creature By Code
//                         ------------------------
//
// General      : This function moves the file pointer to the creature
//                code.
//
// Parameters   : 
//			ptrStarShipFile - A pointer to the file (FILE**)		
//          creatureCode    - The code to search the creature.
//
// Return Value : None. 
//
//----------------------------------------------------------------------

void seekToCreatureByCode(FILE** ptrStarShipFile, int creatureCode)
{
	Creature tempCreature;
	BOOLEAN foundCode = FALSE;

	while (fread(&tempCreature, sizeof(Creature), ONE, *ptrStarShipFile) && !foundCode)
	{
		(tempCreature.creatureCode == creatureCode) ?
			(foundCode = TRUE) : (foundCode);
	}

	fseek(*ptrStarShipFile, (ftell(*ptrStarShipFile)) - sizeof(Creature), SEEK_SET);

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

BOOLEAN isCreatureCodeExist(int creatureCode)
{
	FILE* starShipFile = fopen("starship.dat", "rb");
	Creature tempCreature;
	BOOLEAN foundCode = FALSE;

	while (fread(&tempCreature, sizeof(Creature), ONE, starShipFile) && !foundCode)
	{
		(tempCreature.creatureCode == creatureCode) ?
			(foundCode = TRUE) : (foundCode);
	}

	fclose(starShipFile);

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

void addCreature()
{
	FILE* starShipFile = fopen("starship.dat", "ab");

	BOOLEAN foundCode;
	Creature addedCreature;
	
	printf("\nPlease write the creature code\n");
	scanf("%d", &addedCreature.creatureCode);

	foundCode = isCreatureCodeExist(addedCreature.creatureCode);

	while (foundCode)
	{
		printf("\nThe creature code already exists, please write another code.\n");
		scanf("%d", &addedCreature.creatureCode);
		foundCode = isCreatureCodeExist(addedCreature.creatureCode);
	}

	scanACreature(&addedCreature);
	fwrite(&addedCreature, sizeof(Creature), 1, starShipFile);

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
	FILE* starShipFile = fopen("starship.dat", "r+b");
	BOOLEAN success = FALSE;
	Creature updatedCreature;

	printf("\nWrite the creature code of a creature you want to change\n");
	scanf("%d", &(updatedCreature.creatureCode));
	success = isCreatureCodeExist(updatedCreature.creatureCode);

	while (!success)
	{
		printf("\nThe creature code is not found, please write a valid code.\n");
		scanf("%d", &(updatedCreature.creatureCode));
		success = isCreatureCodeExist(updatedCreature.creatureCode);
	}

	scanACreature(&updatedCreature);
	seekToCreatureByCode(&starShipFile, updatedCreature.creatureCode);
	fwrite(&updatedCreature, sizeof(Creature), 1, starShipFile);
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
		case TWO: addCreature();
			break;
		case THREE: updateACreature();
			break;

		default: isFinished = TRUE;
			break;
		}
	}

	// Print end
	printf("\nThank you for using !\n");
}
