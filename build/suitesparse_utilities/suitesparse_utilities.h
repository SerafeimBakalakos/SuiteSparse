#pragma once
#include "cholmod.h"

extern "C"
{
	/*
	 * Allocates in heap and returns a handle with matrix settings that must be passed to all CHOLMOD functions. Returns NULL if
	 * any failure occurs.
	 * param "factorization": 0 for for simplicial factorization, 1 for automatic decidion between supernodal/simplicial factorization,
	 *		2 for automatic decidion between supernodal/simplicial factorization and after factorization convert to simplicial.
	 *		Supernodal is usually faster, but to modify the factorized matrix it must be converted to simplicial, though this can be
	 *		done automatically.
	 * param "ordering": 0 for no reordering, 1 for automatic reordering (let suitesparse try some alternatives and keep the best).
	 */
	__declspec(dllexport) cholmod_common* util_create_common(int factorization, int ordering);

	/*
	 * Frees the memory for the matrix settings.
	 * param "common": The matrix settings. It will be freed.
	 */
	__declspec(dllexport) void util_destroy_common(cholmod_common** common);

	/*
	 * Frees the memory for the factorized matrix.
	 * param "factorized_matrix": The factorized matrix data. It will be freed.
	 * param "common": The matrix settings.
	 */
	__declspec(dllexport) void util_destroy_factor(cholmod_factor** factorized_matrix, cholmod_common* common);

	/*
	 * Factorize a symmetric matrix using cholesky algorithm. The matrix is in csc form, with only the upper triangle stored.
	 * If cholesky is successful -1 is returned and out_factorized_matrix points to the factorized upper triangle.
	 * If the matrix is not positive definite then the index (0-based) of the column where cholesky failed
	 * and out_factorized_matrix = NULL.
	 * If the something another failure occurs, such as memory not being sufficient due to excessive fill-in then -2 is returned
	 * and out_factorized_matrix = NULL.
	 * param "order": Number of rows = number of columns.
	 * param "nnz": Number of non zero entries in the upper triangle.
	 * param "values": Array containing the non zero entries of the upper triangle in column major order. Length = nnz.
	 * param "row_indices": Array containing the row indices of the non zero entries of the upper triangle. Length = nnz.
	 * param "col_offsets": Array containing the indices into values (and row_indices) of the first entry of each column. 
	 *		Length = order + 1. The last entry is col_offsets[order] = nnz.
	 * param "out_factorized_matrix": Out parameter - the factorized upper triangle of the symmetric CSC matrix.
	 * param "common": The matrix settings.
	 */
	__declspec(dllexport) int util_factorize_cscupper(int order, int nnz, double* values, int* row_indices,	int* col_offsets, 
		cholmod_factor** out_factorized_matrix, cholmod_common* common);

	/*
	 * Adds a row and column to an LDL' factorization. Before updating the kth row and column of L must be equal to the kth  
	 * row and column of the identity matrix. The row/column to add must be a sparse CSC matrix with dimensions n-by-1,  
	 * where n is the order of the matrix. Returns 1 if the method succeeds, 0 otherwise.
	 * param "order": Number of rows = number of columns.
	 * param "L": The data of the cholesky factorization of the matrix. It will be modified.
	 * param "k": Index of row/column to add.
	 * param "vector_nnz": Number of non zero entries of the row/column to add.
	 * param "vector_values": The CSC format values of the row/column to add.
	 * param "vector_row_indices": The CSC format row indices of the row/column to add.
	 * param "vector_col_offsets": The CSC format column offsets of the row/column to add.
	 * param "common": The matrix settings.
	 */
	_declspec(dllexport) int util_row_add(int order, cholmod_factor* L, int k, int vector_nnz, double* vector_values,
		int* vector_row_indices, int* vector_col_offsets, cholmod_common* common);

	/*
	 * Deletes a row and column from an cholesky factorization. After updating the kth row and column of L will be equal to the 
	 * kth row and column of the identity matrix. Returns 1 if the method succeeds, 0 otherwise.
	 * param "L": The LDL' factorization of the matrix. It will be modified.
	 * param "k": Index of row/column to delete.
	 * param "common": The matrix settings.
	 */
	_declspec(dllexport) int util_row_delete(cholmod_factor* L, int k, cholmod_common* common);

	/*
	 * Solves a linear system with a single right hand side vector.
	 * param "order: Number of matrix rows = number of matrix columns = length of right hand side vector.
	 * param "factorized_matrix": The data of the cholesky factorization of the matrix.
	 * param "rhs": The right hand side vector. Its length must be equal to the order of the matrix: factorized_matrix->n.
	 * param "out_solution": Buffer for the left hand side vector (unknown). Its length must be equal to the order of the matrix: 
			factorized_matrix->n
	 * param "common": The matrix settings.
	 */
	__declspec(dllexport) void util_solve(int order, cholmod_factor* factorized_matrix, double* rhs, double* out_solution,
		cholmod_common* common);
}