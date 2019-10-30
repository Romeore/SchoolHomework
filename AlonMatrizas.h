#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN    unsigned short
#define TRUE       1
#define FALSE      0
#define TEN        10
#define ZERO       0
#define ONE        1
#define TWO        2
#define THREE      3
#define FOUR       4
#define FIVE       5
#define SIX        6
#define SEVEN      7
#define TWENTY     (unsigned short)(20)
#define TWENTYFIVE 25
#define THIRTY     30
#define FOURTY     40
#define MONTH      30
#define YEAR       365
#define ONEHUNDRED 100
#define ABS(a)     (a < 0) ? -(a) : (a)
#define MAX(a,b)   (a > b) ? (a) : (b)
#define DIM        4
#include <stdio.h>

int sumRowInMatriza(int mat[][DIM], unsigned short row, unsigned short column);

int sumColumnInMatriza(int mat[][DIM], unsigned short row, unsigned short column);