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

//----------------------------------------------------------------------
//                             Search Name
//                             -----------
//
// General      : This function searches a book name.
//
// Parameters   : 
//			booksPtr    - Array of books. (Book)
//          booksLength - The length of the array. (In) 
//          namePtr     - The wanted name to search.
//
// Return Value : Returns the address of the wanted book, if there is
//                no books that match, return NULL.
//
//----------------------------------------------------------------------

struct Book* searchName(struct Book* booksPtr,int booksLength, char* namePtr)
{
	struct Book* foundBookPtr = NULL;
	struct Book* booksEndPtr = (booksPtr + booksLength);

	while ((booksPtr)++ < booksEndPtr && foundBookPtr == NULL)
	{
		((namePtr == booksPtr -> bookName) || (namePtr == booksPtr -> authorName)) ?
			foundBookPtr = booksPtr : foundBookPtr;
	}

	return (foundBookPtr);
}

//----------------------------------------------------------------------
//                               Size Of Book
//                               ------------
//
// General      : This function calculates the size of book.
//
// Parameters   : 
//			bookPtr - A pointer to a book. (Book)
//
// Return Value : Returns the size (in bits) of a book.
//
//----------------------------------------------------------------------

int sizeOfBook(struct Book* bookPtr) {

	return (stringLength(bookPtr -> authorName) + stringLength(bookPtr -> bookName)
		+ stringLength(bookPtr -> publisherName) + TWO * sizeof(int) + sizeof(float));
}

//----------------------------------------------------------------------
//                         Make Book Array From Years
//                         --------------------------
//
// General      : This function makes dynamic array of books from
//                1900 - 2000.
//
// Parameters   : 
//			bookPtr - Array of books. (Book)
//          booksLength - The length of the books array.
//
// Return Value : Returns a pointer to a dynamic array of books from
//                1900 - 2000.
//
//----------------------------------------------------------------------

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