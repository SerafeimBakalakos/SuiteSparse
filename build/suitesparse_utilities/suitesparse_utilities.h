#pragma once
#include "cholmod.h"

// In all these the sparse format is CSC with sorted rows and columns
// TODO: use const in parameters
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
	__declspec(dllexport) int util_factorize_cscupper(int order, int nnz, double* values, int* row_indices, int* col_offsets,
		cholmod_factor** out_factorized_matrix, cholmod_common* common);

	/*
	* Returns the number of non zero entries in the factorized matrix. If anything goes wrong -1 is returned.
	* param "factorization": The factorized matrix
	*/
	__declspec(dllexport) int util_get_factor_nonzeros(cholmod_factor* factorization);

	/*
	* Calculates a fill reducing ordering using the Approximate Minimum Degree algorithm for a symmetric sparse matrix. Returns
	* 1 if the reordering is successful, 0 if it failed (e.g. due to exceeding the available memory or invalid matrix pattern).
	* param "order": Number of rows = number of columns.
	* param "nnz": Number of non zero entries in the upper triangle.
	* param "row_indices": Array containing the row indices of the non zero entries of the upper triangle. Length = nnz.
	* param "col_offsets": Array containing the indices into values (and row_indices) of the first entry of each column.
	*		Length = order + 1. The last entry is col_offsets[order] = nnz.
	* param "out_permutation": Out parameter - buffer for the computed permutation vector. Length == order. This permutation
	*		vector is new-to-old; it can be intepreted as: original index = out_permutation[i], reordered index = i
	* param "out_factor_nnz": Out parameter - the number of non zero entries in a subsequent L*L^T factorization. Will be -1 if
	*		the ordering fails.
	*/
	__declspec(dllexport) int util_reorder_amd_upper(int order, int nnz, int* row_indices, int* col_offsets,
		int* out_permutation, int* out_factor_nnz, cholmod_common* common);

	/*
	* Calculates a fill reducing ordering using the Constrained Approximate Minimum Degree algorithm for a A + A^T, where A is a 
	* square sparse matrix. The pattern of A + A^T is formed first. The constrains enforce groups of indices to be ordered 
	* consecutively, before other groups.
	* Returns: 
	*	0 if the input was ok and the ordering is successful, 
	*	1 if the matrix had unsorted columns and/or duplicate entries, but was otherwise valid, 
	*	2 if input arguments order, col_offsets, row_indices are invalid, or if out_permutation is NULL,
	*	3 if not enough memory can be allocated
	* param "order": Number of rows = number of columns.
	* param "row_indices": Array containing the row indices of the non zero entries of the upper triangle. Length = nnz.
	* param "col_offsets": Array containing the indices into values (and row_indices) of the first entry of each column.
	*		Length = order + 1. The last entry is col_offsets[order] = nnz.
	* param "constraints:" Array of length = order with ordering constraints. Its values must be 0 <= constraints[i] < order.
	*		If constraints = NULL, no constraints will be enforced.
	*		Example: constraints = { 2, 0, 0, 0, 1 }. This means that indices 1, 2, 3 that have constraints[i] = 0, will be 
	*		ordered before index 4 with constraints[4] = 1, which will be ordered before index 0 with constraints[0] = 2.
	*		Indeed for a certain pattern, out_permutation = { 3, 2, 1, 4, 0 } (remember out_permutation is a new-to-old mapping).
	* param "dense_threshold": A dense row/column in A + A^T can cause CAMD to spend significant time in ordering the matrix.  
	*		If dense_threshold ≥ 0, rows/columns with more than dense_threshold * sqrt(order) entries are ignored during the 
	*		ordering, and placed last in the output order. The default value of dense_threshold is 10. If negative, no
	*		rows/columns are treated as dense. Rows/columns with 16 or fewer off-diagonal entries are never considered dense.
	*		WARNING: allowing dense rows/columns may violate the constraints.
	* param "aggressive_absorption": If non zero, aggressive absorption will be performed, which means that a prior element is 
	*		absorbed into the current element if it is a subset of the current element, even if it is not adjacent to the 
	*		current pivot element. This nearly always leads to a better ordering (because the approximate degrees are more 
	*		accurate) and a lower execution time. There are cases where it can lead to a slightly worse ordering, however. 
	*		The default value is nonzero. To turn it off, set aggressive_absorption to 0.
	* param "out_permutation": Out parameter - buffer for the computed permutation vector. Length == order. This permutation
	*		vector is new-to-old; it can be intepreted as: original index = out_permutation[i], reordered index = i.
	* param "out_factor_nnz": Out parameter - upper bound on the number of non zero entries in L of a subsequent L*L^T 
	*		factorization. Will be -1 if the ordering fails.
	* param "out_moved_dense": Out parameter - the number of dense rows/columns of A + A^T that were removed from A prior to
	*		ordering. These are placed last in the output order of out_permutation. Will be -1 if the ordering fails.
	*		WARNING: if out_moved_dense > 0, it indicates that the constraints are violated!
	*/
	__declspec(dllexport) int util_reorder_camd(int order, int* row_indices, int* col_offsets, int* constraints,
		int dense_threshold, int aggressive_absorption,	int* out_permutation, int* out_factor_nnz, int* out_moved_dense);

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