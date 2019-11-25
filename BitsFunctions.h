//BitsFunctions.h
#pragma once

#include "AlonPointers.h"

#define BITSINBYTE    EIGHT
#define CHARNUMOFBITS sizeof(char) * BITSINBYTE
#define INTNUMOFBITS  sizeof(int)  * BITSINBYTE
#define LONGNUMOFBITS sizeof(long) * BITSINBYTE

BOOLEAN isNumEvenBit(int* ptrNumber);

BOOLEAN isNumOddBit(int* ptrNumber);

BOOLEAN isNumberHasEvenBits(int* ptrNumber);

void rotateNumberBit(unsigned int* ptrNumber, int numOfTimes);

int calculateBits(int place);
