#pragma once
#include "cholmod.h"

// In all these the sparse format is CSC with sorted rows and columns
extern "C"
{
	/*
	 * Allocates in heap and returns a handle with matrix settings that must be passed to all CHOLMOD functions. Returns NULL if
	 * any failure occurs.
	 * param "factorization": 0 for for simplicial L^T*L or L^T*D*L factorization, 1 for supernodal L^T*L factorization,
	 *      2 for automatic decidion between supernodal/simplicial factorization,
	 *		3 for automatic decidion between supernodal/simplicial factorization and after factorization convert to simplicial.
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
	 * Returns the number of non zero entries in the factorized matrix. If anything goes wrong -1 is returned.
	 * param "factorization": The factorized matrix
	 */
	__declspec(dllexport) int util_get_factor_nonzeros(cholmod_factor* factorization);

	/*
	 * Caclulates a fill reducing ordering using the Approximate Minimum Degree algorithm for a symmetric sparse matrix. Returns  
	 * 1 if the reordering is successful, 0 if it failed (e.g. due to exceeding the available memory).
	 * param "order": Number of rows = number of columns.
	 * param "nnz": Number of non zero entries in the upper triangle.
	 * param "row_indices": Array containing the row indices of the non zero entries of the upper triangle. Length = nnz.
	 * param "col_offsets": Array containing the indices into values (and row_indices) of the first entry of each column.
	 *		Length = order + 1. The last entry is col_offsets[order] = nnz.
	 * param "out_permutation": Out parameter - buffer for the computed permutation vector. Length == order. This permutation 
	 *		vector can be intepreted as: original index = i, reordered index = out_permutation[i]
	 * param "out_factor_nnz": Out parameter - the number of non zero entries in a subsequent L*L^T factorization. Will be -1 if 
			the ordering fails.
	 */
	__declspec(dllexport) int util_reorder_amd_upper(int order, int nnz, int* row_indices, int* col_offsets,
		int* out_permutation, int* out_factor_nnz, cholmod_common* common);

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
	 * Solves a linear system or applies back substitution or forward substituiton to 1 ore more right hand sides.
	 * Returns 1 if the method succeeds, 0 otherwise.
	 * param "system": 0 for system solution (A*x=b), 4 for forward substitution (L*x=b), 5 for back substitution (L^T*x=b)
	 * param "num_rows": Number of matrix rows = number of matrix columns = number of rhs matrix rows.
	 * param "num_rhs": Number of rhs vectors = number of columns in rhs matrix.
	 * param "factorized_matrix": The data of the cholesky factorization of the matrix.
	 * param "rhs": The right hand side matrix. Column major array with dimensions = num_rows -by- num_rhs.
	 * param "out_solution": Buffer for the left hand side vector (unknown). Column major array with dimensions = 
	 *		num_rows -by- num_rhs.
	 * param "common": The matrix settings.
	*/
	__declspec(dllexport) int util_solve(int system, int num_rows, int num_rhs, cholmod_factor* factorized_matrix, double* rhs,
		double* out_solution, cholmod_common* common);
}