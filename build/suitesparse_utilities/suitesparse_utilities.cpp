// suitesparse_utilities.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <string.h>
#include <algorithm>
#include "cholmod.h"
#include "suitesparse_utilities.h"

/*
Allocates in heap and returns a handle that must be passed to all CHOLMOD functions.
*/
cholmod_common* util_create_common()
{
	cholmod_common *common = new cholmod_common;
	cholmod_start(common);
	return common;
}

/*
Frees the memory for the handle.
*/
void util_destroy_common(cholmod_common** common)
{
	cholmod_finish(*common);
	*common = NULL;
}

/*
Frees the memory for the factorized matrix.
*/
void util_destroy_factor(cholmod_factor** factorized_matrix, cholmod_common* common)
{
	cholmod_free_factor(factorized_matrix, common);
	*factorized_matrix = NULL;
}

/*
Factorize a symmetric matrix using cholesky algorithm. The matrix is in csc form, with only the upper triangle stored.
Returns: 0 when the factorization is successfull, i>0 when the matrix is not positive definite with i being the column at which failure occured, -1 for other failures, such as a too large matrix
*/
int util_factorize_cscupper(
	int order, /*Number of rows = number of columns*/
	int nnz, /*Number of non zero entries in the upper triangle.*/
	double* values, /*Array containing the non zero entries of the upper triangle in column major order. Length = nnz*/
	int* row_indices, /*Array containing the row indices of the non zero entries of the upper triangle. Length = nnz*/
	int*  col_offsets, /*Array containing the indices into values (and row_indices) of the first entry of each column. Length = order + 1. The last entry is col_offsets[order] = nnz*/
	cholmod_factor** out_factorized_matrix, /*Out parameter: the factorized upper triangle of the symmetric CSC matrix.*/
	cholmod_common* common)
{
	// Create temp sparse matrix object
	cholmod_sparse *A = (cholmod_sparse*)cholmod_malloc(1, sizeof(cholmod_sparse), common);
	A->nrow = order;
	A->ncol = order;
	A->nzmax = nnz;
	A->p = col_offsets;
	A->nz = NULL; // Column indices if the matrix is unpacked.
	A->i = row_indices;
	A->x = values;
	A->z = NULL; //imaginary parts if the matrix is complex
	A->stype = 1; // >0: upper triangle is stored, <0: lower triangle is stored, 0: unsymmetric matrix
	A->itype = CHOLMOD_INT; //type of the void index arrays (p,i,nz). Options: CHOLMOD_INT, CHOLMOD_INTLONG, CHOLMOD_LONG
	A->xtype = CHOLMOD_REAL; //type of the value arrays (x, z). Options: CHOLMOD_PATTERN, CHOLMOD_REAL, CHOLMOD_COMPLEX, CHPLMOD_ZOMPLEX
	A->dtype = CHOLMOD_DOUBLE; //precision of value arrays. Options: CHOLMOD_REAL, CHOLMOD_FLOAT
	A->sorted = 1; // TRUE (1) if the columns are sorted, FALSE(0) otherwise
	A->packed = 1; // FALSE (0) if the column indexes are stored excplicitly in nz, TRUE(1) otherwise (nz = NULL)

	// Factorize
	cholmod_factor *L = cholmod_analyze(A, common);
	int status = cholmod_factorize(A, L, common);

	// Free temp sparse matrix object. 
	A->p = NULL; //The CSC arrays belong to the caller and should not be freed by cholmod_free_sparse().
	A->i = NULL;
	A->x = NULL;
	cholmod_free_sparse(&A, common);

	// Inspect the result of the factorization
	if (status == 0) //FALSE=0 (not sure)
	{
		cholmod_free_factor(&L, common);
		out_factorized_matrix = NULL;
		return -2;
	}
	else if (common->status == CHOLMOD_NOT_POSDEF) //In this case cholmod_factorize() returns TRUE 
	{
		cholmod_free_factor(&L, common);
		out_factorized_matrix = NULL;
		return L->minor;
	}
	else
	{
		*out_factorized_matrix = L;
		return -1;
	}
}

/*
Solves a linear system with a single right hand side vector.
*/
void util_solve(
	int order /*Number of matrix rows = number of matrix columns = length of right hand side vector*/,
	cholmod_factor* factorized_matrix, /*The matrix after being factorized.*/
	double* rhs, /*The right hand side vector. Its length must be equal to the order of the matrix: factorized_matrix->n*/
	double* out_solution, /*Buffer for the left hand side vector (unknown). Its length must be equal to the order of the matrix: factorized_matrix->n*/
	cholmod_common* common)
{
	// Create temp dense matrix object
	cholmod_dense *b = (cholmod_dense*)cholmod_malloc(1, sizeof(cholmod_dense), common);
	b->nrow = order;
	b->ncol = order;
	b->nzmax = order;
	b->d = order;
	b->x = rhs;
	b->z = NULL; //imaginary parts if the matrix is complex
	b->xtype = CHOLMOD_REAL; //type of the value arrays (x, z). Options: CHOLMOD_PATTERN, CHOLMOD_REAL, CHOLMOD_COMPLEX, CHPLMOD_ZOMPLEX
	b->dtype = CHOLMOD_DOUBLE; //precision of value arrays. Options: CHOLMOD_REAL, CHOLMOD_FLOAT

	//Solve the system
	cholmod_dense *solution = cholmod_solve(CHOLMOD_A, factorized_matrix, b, common);

	//Copy the solution to the out buffer
	memcpy(out_solution, solution->x, order * sizeof(double));

	//Free the temp dense matrix objects
	b->x = NULL; //The rhs array belongs to the caller and should not be freed by cholmod_free_dense().
	cholmod_free_dense(&b, common);
	cholmod_free_dense(&solution, common);
}
