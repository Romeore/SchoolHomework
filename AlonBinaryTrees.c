//AlonBinaryTrees.c
#pragma once

#include "AlonBinaryTrees.h"

//----------------------------------------------------------------------
//                           Make Binary Tree
//                           ----------------
//
// General      : This function makes a new binary tree.
//
// Parameters   : 
//			root - A pointer to the root (BinaryTree**)		
//
// Return Value : None.
//
//----------------------------------------------------------------------

void makeBinaryTree(BinaryTree** root)
{
	*root = (BinaryTree*)malloc(sizeof(BinaryTree));
	(*root)->left = NULL;
	(*root)->right = NULL;
}

//----------------------------------------------------------------------
//                       Set Right Binary Tree
//                       ---------------------
//
// General      : This function makes a new right node to a binary tree
//                node.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)		
//
// Return Value : None.
//
//----------------------------------------------------------------------

void setRightBinaryTree(BinaryTree* node)
{
	node->right = (BinaryTree*)malloc(sizeof(BinaryTree));
	node->right->left = NULL;
	node->right->right = NULL;
}

//----------------------------------------------------------------------
//                        Set Left Binary Tree
//                        --------------------
//
// General      : This function makes a new left node to a binary tree
//                node.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)		
//
// Return Value : None.
//
//----------------------------------------------------------------------

void setLeftBinaryTree(BinaryTree* node)
{
	node->left = (BinaryTree*)malloc(sizeof(BinaryTree));
	node->left->left = NULL;
	node->left->right = NULL;
}

//----------------------------------------------------------------------
//                         Is Empty Binary Tree
//                         --------------------
//
// General      : This function checks if the tree is empty.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns TRUE if the tree is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isEmptyBinaryTree(BinaryTree* node)
{
	return (node == NULL);
}

//----------------------------------------------------------------------
//                         Is Leaf Binary Tree
//                         -------------------
//
// General      : This function checks if a node is a leaf in a binary
//                tree.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns TRUE if the node is a leaf, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isLeafBinaryTree(BinaryTree* node)
{
	return (node->left == NULL && node->right == NULL);
}

//----------------------------------------------------------------------
//                       Print Preorder Binary Tree
//                       --------------------------
//
// General      : This function prints a binary tree with preorder.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)		
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printPreorderBinaryTree(BinaryTree* node)
{
	if (isEmptyBinaryTree(node))
	{
		return;
	}

	printf("%d", node->info);
	printPreorderBinaryTree(node->left);
	printPreorderBinaryTree(node->right);
}

//----------------------------------------------------------------------
//                       Print Inorder Binary Tree
//                       --------------------------
//
// General      : This function prints a binary tree with inorder.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)		
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printInorderBinaryTree(BinaryTree* node)
{
	if (isEmptyBinaryTree(node))
	{
		return;
	}

	printInorderBinaryTree(node->left);
	printf("%d", node->info);
	printInorderBinaryTree(node->right);
}

//----------------------------------------------------------------------
//                       Print Postorder Binary Tree
//                       ---------------------------
//
// General      : This function prints a binary tree with postorder.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printPostorderBinaryTree(BinaryTree* node)
{
	if (isEmptyBinaryTree(node))
	{
		return;
	}

	printPostorderBinaryTree(node->left);
	printPostorderBinaryTree(node->right);
	printf("%d", node->info);
}

//----------------------------------------------------------------------
//                       Count Nodes Binary Tree
//                       -----------------------
//
// General      : This function counts nodes in the binary tree.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns the number of nodes in the binary tree.
//
//----------------------------------------------------------------------

int countNodesBinaryTree(BinaryTree* node)
{
	if (isEmptyBinaryTree(node))
	{
		return (ZERO);
	}

	return (countNodesBinaryTree(node->right) 
		+ countNodesBinaryTree(node->left) + ONE);
}

//----------------------------------------------------------------------
//                       Count Leafs Binary Tree
//                       -----------------------
//
// General      : This function counts leafs in the binary tree.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns the number of leafs in the binary tree.
//
//----------------------------------------------------------------------

int countLeafsBinaryTree(BinaryTree* node)
{
	if (isLeafBinaryTree(node))
	{
		return (ONE);
	}

	return (countLeafsBinaryTree(node->right)
		+ countLeafsBinaryTree(node->left));
}

//----------------------------------------------------------------------
//                       Find Min Binary Tree
//                       --------------------
//
// General      : This function finds the min in a binary search tree.
//
// Parameters   : 
//			node - A node in a binary search tree (BinaryTree*)
//
// Return Value : Returns the min in a binary search tree.
//
//----------------------------------------------------------------------

int findMinBinaryTree(BinaryTree* node)
{
	if (isLeafBinaryTree(node))
	{
		return (node->info);
	}

	return (findMinBinaryTree(node->left));
}

//----------------------------------------------------------------------
//                       Find Max Binary Tree
//                       --------------------
//
// General      : This function finds the max in a binary search tree.
//
// Parameters   : 
//			node - A node in a binary search tree (BinaryTree*)
//
// Return Value : Returns the max in a binary search tree.
//
//----------------------------------------------------------------------

int findMaxBinaryTree(BinaryTree* node)
{
	if (isLeafBinaryTree(node))
	{
		return (node->info);
	}

	return (findMinBinaryTree(node->right));
}

//----------------------------------------------------------------------
//                         Binary Tree Depth
//                         -----------------
//
// General      : This function calculates the tree depth in a binary
//                tree.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns the tree depth.
//
//----------------------------------------------------------------------

int binaryTreeDepth(BinaryTree* node)
{
	if (isLeafBinaryTree(node))
	{
		return (ONE);
	}

	return (MAX(binaryTreeDepth(node->left),
		binaryTreeDepth(node->right)) + ONE);
}

//----------------------------------------------------------------------
//                       Sum Nodes Binary Tree
//                       ---------------------
//
// General      : This function calculates the nodes sum in a binary
//                tree.
//
// Parameters   : 
//			node - A node in a binary tree (BinaryTree*)
//
// Return Value : Returns the sum of the nodes in a binary tree.
//
//----------------------------------------------------------------------

int sumNodesBinaryTree(BinaryTree* node)
{
	if (isEmptyBinaryTree(node))
	{
		return (ZERO);
	}

	return (sumNodesBinaryTree(node->left)
		+ sumNodesBinaryTree(node->right) + node->info);
}

//----------------------------------------------------------------------
//                      Is Value Exists Binary Tree
//                      ---------------------------
//
// General      : This function checks if a value exists in a binary
//                tree.
//
// Parameters   : 
//			node  - A node in a binary tree (BinaryTree*)
//          value - The value to search (Int)
//
// Return Value : Returns the address of a binary tree node if 
//                the value exists, else NULL.
//
//----------------------------------------------------------------------

BinaryTree* isValueExistsBinaryTree(BinaryTree* node, int value)
{
	if (isEmptyBinaryTree(node))
	{
		return (FALSE);
	}

	if (node->info == value)
	{
		return (node);
	}

	return (isValueExistsBinaryTree(node->right, value)
		|| isValueExistsBinaryTree(node->left, value));
}
