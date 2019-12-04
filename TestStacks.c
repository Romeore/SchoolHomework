//TestStacks.c
#pragma once

#include "AlonStacks.h"

void main(void) {

	// Variable definition
	Stack stackOne;
	int numberOne = 4;
	int numberTwo = 348;
	Item itemOne = { &numberOne,numberOne};
	Item itemTwo = { &numberTwo,numberTwo };

	// Code section for testing
	stackOne.startStack[ZERO] = itemOne;
	stackOne.offset = ZERO;
	popStack(&stackOne);
	pushStack(&stackOne, &itemTwo);

	// This part prints the tests
	printf("%d", popStack(&stackOne).value);
	scanf("%d", &numberOne);
}