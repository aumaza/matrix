#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024  // Tamaño máximo de línea
#define DELIMITER ','

struct Matrix{

    int rows;
    int cols;
    int** data;

    int (* getNumRows)();
    int (* getNumCols)();
    struct Matrix* (* matrixParams)();
    struct Matrix* (* createMatrix)();
    void (* fillRandomMatrix)();
    void (* fillMatrix)();
    void (* printMatrix)();
    void (* loadFile)();
    int  (* countCols)();
    int  (* countRows)();
    void  (* printSeparador)();
    void (* printData)();


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

// FILL MATRIX
void m_fillMatrix(Matrix* matrix, FILE* file, char delimiter);

// PRINT MATRIX
void m_printMatrix(Matrix* matrix);

// LOAD FILE
void m_loadFile(Matrix* matrix, char* file);

// COUNT CANT COLS FROM FILE
int m_countCols(FILE* file, char delimiter);

// COUNT CANT ROWS FROM FILE
int m_countRows(FILE* file);

// LOAD DATA FROM FILE
char*** loadDataFromFile(FILE *file, int rows, int cols, char delimiter);

// PRINT SEPARATOR
void m_printSeparator(int cols);

// PRINT DATA
void m_printData(char*** mtrx, int rows, int cols);
