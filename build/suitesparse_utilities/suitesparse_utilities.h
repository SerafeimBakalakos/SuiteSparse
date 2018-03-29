#pragma once
#include "cholmod.h"

extern "C"
{
	/*
	Allocates in heap and returns a handle that must be passed to all CHOLMOD functions.
	*/
	__declspec(dllexport) cholmod_common* util_create_common();

	/*
	Frees the memory for the handle.
	*/
	__declspec(dllexport) void util_destroy_common(cholmod_common** common);

	/*
	Frees the memory for the factorized matrix.
	*/
	__declspec(dllexport) void util_destroy_factor(cholmod_factor** factorized_matrix, cholmod_common* common);

	/*
	Factorize a symmetric matrix using cholesky algorithm. The matrix is in csc form, with only the upper triangle stored.
	If cholesky is successful -1 is returned and out_factorized_matrix points to the factorized upper triangle.
	If the matrix is not positive definite then the index (0-based) of the column where cholesky failed  
	and out_factorized_matrix = NULL.
	If the something another failure occurs, such as memory not being sufficient due to excessive fill-in then -2 is returned  
	and out_factorized_matrix = NULL.
	*/
	__declspec(dllexport) int util_factorize_cscupper(
		int order, /*Number of rows = number of columns*/
		int nnz, /*Number of non zero entries in the upper triangle.*/
		double* values, /*Array containing the non zero entries of the upper triangle in column major order. Length = nnz*/
		int* row_indices, /*Array containing the row indices of the non zero entries of the upper triangle. Length = nnz*/
		int*  col_offsets, /*Array containing the indices into values (and row_indices) of the first entry of each column. Length = order + 1. The last entry is col_offsets[order] = nnz*/
		cholmod_factor** out_factorized_matrix, /*Out parameter: the factorized upper triangle of the symmetric CSC matrix.*/
		cholmod_common* common);

	/*
	Solves a linear system with a single right hand side vector.
	*/
	__declspec(dllexport) void util_solve(
		int order /*Number of matrix rows = number of matrix columns = length of right hand side vector*/,
		cholmod_factor* factorized_matrix, /*The matrix after being factorized.*/
		double* rhs, /*The right hand side vector. Its length must be equal to the order of the matrix: factorized_matrix->n*/
		double* out_solution, /*Buffer for the left hand side vector (unknown). Its length must be equal to the order of the matrix: factorized_matrix->n*/
		cholmod_common* common);
}