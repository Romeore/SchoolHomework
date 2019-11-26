#pragma once

#include "AlonDynamic.h"

struct Book
{
	char* bookName;
	char* authorName;
	char* publisherName;
	int year;
	float price;
	int bookID;
};

struct Book* searchName(struct Book* booksPtr,int booksLength, char* namePtr)
{
	struct Book* foundBookPtr = NULL;
	struct Book* booksEndPtr = (booksPtr + booksLength);

	while ((booksPtr)++ < booksEndPtr && foundBookPtr == NULL)
	{
		namePtr == booksPtr->bookName || namePtr == booksPtr->authorName ?
			foundBookPtr = booksPtr : foundBookPtr;
	}

	return (foundBookPtr);
}

int sizeOfBook(struct Book* book) {

	return (stringLength(book -> authorName) + stringLength(book -> bookName)
		+ stringLength(book -> publisherName) + TWO * sizeof(int) + sizeof(float));
}

struct Book* makeBookArrayFromYears(struct Book* booksPtr, int booksLength)
{
	int          sizeBook = sizeOfBook(booksPtr);
	int          arrayLength = ONE;
	struct Book* betweenYearsBooksPtr = malloc(sizeBook);
	struct Book* booksPtrEnd = booksPtr + booksLength;

	while (booksPtr++ < booksPtrEnd)
	{
		if (booksPtr -> year < TWOTHOUSENED && booksPtr -> year > NINETEENHUNDRED)
		{
			betweenYearsBooksPtr = (struct Book*)realloc(betweenYearsBooksPtr, ++arrayLength * sizeBook);
			*(betweenYearsBooksPtr + arrayLength) = *booksPtr;
		}
	}

	return (betweenYearsBooksPtr);
}