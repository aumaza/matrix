#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matrix.h"

// CONSTRUCTOR DESPARAMETRIZADO
Matrix* m_matrix(void){

    Matrix* pMatrix;
    Matrix* returnAux = NULL;
    pMatrix = (Matrix*)malloc(sizeof(Matrix));

    if(pMatrix != NULL){
        pMatrix->rows = 0;
        pMatrix->cols = 0;
        pMatrix->getNumRows = m_getNumRows;
        pMatrix->getNumCols = m_getNumCols;
        pMatrix->matrixParams = m_matrixParams;
        pMatrix->createMatrix = m_createMatrix;
        pMatrix->fillRandomMatrix = m_fillRandomMatrix;
        pMatrix->printMatrix = m_printMatrix;
        pMatrix->loadFile = m_loadFile;
        returnAux = pMatrix;
    }else{
        free(pMatrix);
    }

    return returnAux;
}

// CONSTRUCTOR PARAMETRIZADO
Matrix* m_matrixParams(Matrix* this, int row, int col){


    if(this != NULL){
        this->rows = row;
        this->cols = col;
    }

    return this;
}

// GET NUM ROWS
int m_getNumRows(Matrix* this){
    return this->rows;
}

// GET NUM COLS
int m_getNumCols(Matrix* this){
    return this->cols;
}

// CREATE MATRIX
Matrix* m_createMatrix(Matrix* this, int row, int col){

    // Reservar memoria para las filas
    this->data = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        this->data[i] = (int *)malloc(col * sizeof(int));
    }

    return this;

}

// FILL RANDOM MATRIX
void m_fillRandomMatrix(Matrix* this){

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->data[i][j] = i * this->cols + j + 1;
        }
    }

}


// PRINT MATRIX
void m_printMatrix(Matrix* this){
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            printf("%d ", this->data[i][j]);
        }
        printf("\n");
    }
}

// LOAD FILE
void m_loadFile(Matrix* this, char* path){

    FILE* fp = fopen(path, "r");


}
