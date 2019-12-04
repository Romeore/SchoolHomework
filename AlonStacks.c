//AlonStacks.c
#pragma once

#include "AlonStacks.h"

Item popStack(Stack* ptrStack) {
	return ptrStack->startStack[ptrStack->offset--];
}

void pushStack(Stack* ptrStack, Item* valuePtr) {
	(ptrStack->offset != MAXSIZE) ? (ptrStack->startStack[++ptrStack->offset] = *valuePtr) : *valuePtr;
}

BOOLEAN isStackEmpty(Stack* ptrStack) {
	return (ptrStack->offset == EMPTY);
}
