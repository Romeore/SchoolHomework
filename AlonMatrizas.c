#pragma once

#include "AlonMatrizas.h"

int sumColumnInMatriza(int mat[][DIM], unsigned short row, unsigned short column)
{
	int sum = ZERO;
	for (column; column - ONE; column--)
	{
		sum += mat[column][row];
	}
	return (sum);
}

int sumRowInMatriza(int mat[][DIM], unsigned short row, unsigned short column)
{
	int sum = ZERO;
	for (row; row - ONE; row--)
	{
		sum += mat[column][row];
	}
	return (sum);
}
