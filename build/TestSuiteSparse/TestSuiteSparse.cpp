// TestSuiteSparse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <cmath>
#include "suitesparse_utilities.h"

void run();
bool check_same(int length, double* array1, double* array2, double tolerance);
void print_array(int length, double* arry);

int main()
{
	run();
    return 0;
}

void run()
{
	// Define linear system
	int n = 4;
	int nnz = 7;
	int *col_offsets = new int[n + 1]{ 0, 1, 2, 5, nnz };
	int *row_indices = new int[nnz]{ 0, 1, 0, 1, 2, 1, 3 };
	double *values = new double[nnz]{ 4.0, 10.0, 2.0, 1.0, 8.0, 3.0, 9.0 };
	double *b = new double[n]{ 6.0, 14.0, 11.0, 12.0 };
	double *x = new double[n];

	//Use the library to solve the system
	cholmod_common *common = util_create_common();
	cholmod_factor *factor = NULL;
	util_factorize_cscupper(n, nnz, values, row_indices, col_offsets, &factor, common);
	util_solve(n, factor, b, x, common);
	util_destroy_factor(&factor, common);
	util_destroy_common(&common);

	//Check solution
	double *expected = new double[4] { 1.0, 1.0, 1.0, 1.0 };
	if (check_same(n, x, expected, 1e-6))
	{
		printf("The linear system has been solved correctly.\n");
		printf("expected solution = ");
		print_array(n, expected);
		printf("computeded solution = ");
		print_array(n, x);
	}
	else
	{
		printf("ERROR in solving the linear system.\n");
		printf("expected solution = ");
		print_array(n, expected);
		printf("computeded solution = ");
		print_array(n, x);
	}

	//Clean up
	delete[] col_offsets;
	delete[] row_indices;
	delete[] values;
	delete[] b;
	delete[] x;
	delete[] expected;
}

bool check_same(int length, double* array1, double* array2, double tolerance)
{
	for (int i = 0; i < length; ++i)
	{
		if (abs(array1[i] - array2[i]) > tolerance) return false;
	}
	return true;
}

void print_array(int length, double* arry)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%f", arry[i]);
		printf(" ");
	}
	printf("\n");
}