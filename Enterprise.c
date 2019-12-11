//Enterprise.c
#pragma once

#include "AlonStrings.h"
typedef struct creature
{
	int  creatureCode;
	char creatureName[EIGHT];
	char bornPlanet[FIFTEEN];
	int  age;
} creature;


void printCreature(creature* ptrCreature)
{
	printf("\nCreature code: %d\n", ptrCreature->creatureCode);
	printf("\nCreature name: %s\n", ptrCreature->creatureName);
	printf("\nBorn planet: %s\n", ptrCreature->bornPlanet);
	printf("\nAge: %d\n", ptrCreature->age);

	return;
}

void printAllCreatures(FILE** ptrFile)
{
	creature tempCreature;
	fseek(*ptrFile, ZERO, SEEK_SET);
	while (!feof(*ptrFile))
	{
		fread(&tempCreature, sizeof(creature), 1, *ptrFile);
		printCreature(&tempCreature);
	}
	
	return;
}
