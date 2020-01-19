//AlonBinaryTrees.h
#pragma once

#define BOOLEAN  unsigned short
#define TRUE     1
#define FALSE    0
#define ZERO     0
#define ONE      1
#define TWO      2
#define THREE    3
#define FOUR     4
#define FIVE     5
#define SIX      6
#define SEVEN    7
#define EIGHT    8
#define NINE     9
#define TEN      10
#define MIN(a,b) ((a) < (b)) ? (a) : (b)
#define MAX(a,b) ((a) > (b)) ? (a) : (b)

#include <malloc.h>

typedef struct BinaryTree {
	int info;
	struct BinaryTree* left;
	struct BinaryTree* right;
} BinaryTree;

void makeBinaryTree(BinaryTree** root);

void setRightBinaryTree(BinaryTree* node);

void setLeftBinaryTree(BinaryTree* node);

BOOLEAN isEmptyBinaryTree(BinaryTree* node);

BOOLEAN isLeafBinaryTree(BinaryTree* node);

void printPreorderBinaryTree(BinaryTree* node);

void printInorderBinaryTree(BinaryTree* node);

void printPostorderBinaryTree(BinaryTree* node);

int countNodesBinaryTree(BinaryTree* manager);

int countLeafsBinaryTree(BinaryTree* node);

int findMinBinaryTree(BinaryTree* node);

int findMaxBinaryTree(BinaryTree* node);

int binaryTreeDepth(BinaryTree* node);

int sumNodesBinaryTree(BinaryTree* node);

BinaryTree* isValueExistsBinaryTree(BinaryTree* node, int num);
