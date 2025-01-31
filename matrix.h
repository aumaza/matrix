#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

struct Matrix{

    int rows;
    int cols;
    int** data;

    int (* getNumRows)();
    int (* getNumCols)();
    struct Matrix* (* matrixParams)();
    struct Matrix* (* createMatrix)();
    void (* fillRandomMatrix)();
    void (* printMatrix)();
    void (* loadFile)();

}typedef Matrix;

#endif

// CONSTRUCTOR DESPARAMETRIZADO
Matrix* m_matrix(void);

// CONSTRUCTOR PARAMETRIZADO
Matrix* m_matrixParams(Matrix* matrix, int row, int col);

// GET LENGTH ROWS
int m_getNumRows(Matrix* matrix);
// GET LENGTH COLS
int m_getNumCols(Matrix* matrix);

// CREATE MATRIX
Matrix* m_createMatrix(Matrix* matrix,int row, int col);

// FILL RANDOM MATRIX
void m_fillRandomMatrix(Matrix* matrix);

// PRINT MATRIX
void m_printMatrix(Matrix* matrix);

// LOAD FILE
void m_loadFile(Matrix* matrix, char* file);
