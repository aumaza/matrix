#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
        pMatrix->countCols = m_countCols;
        pMatrix->countRows = m_countRows;
        pMatrix->printSeparador = m_printSeparator;
        pMatrix->printData = m_printData;
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

// FILL MATRIX
void m_fillMatrix(Matrix* this,FILE* file, char delimiter){

    char line[MAX_LINE];
    //Matrix* matriz = this->createMatrix(this,row,col);

    if (this == NULL) {
        printf("Error al asignar memoria para la matriz.\n");

    }

    // Leer y almacenar los datos en la matriz
    for (int i = 0; i < this->rows; i++) {
        if (fgets(line, MAX_LINE, file) == NULL) {
            break;
        }


        // Tokenizar la línea
        char *token = strtok(line, &delimiter);
        int j = 0;
        while (token && j < this->cols) {
            this->data[i][j] = atoi(token);  // Copiar el valor
            printf("%d ", this->data[i][j]);
            token = strtok(NULL, &delimiter);
            j++;
        }
    }

    //return matriz;
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
    char delimiter = ',';
    char line[MAX_LINE];


    if(fp != NULL){

        this->cols = this->countCols(fp, delimiter);
        rewind(fp);
        this->rows = this->countRows(fp);

        if((this->rows > 0 ) && (this->cols > 0)){
            printf("Numero de Filas: %d. Número de Columnas: %d\n", this->rows, this->cols);
            //this->createMatrix(this,rows,cols);
            //this->matrixParams(this);
            //this->fillMatrix(this,fp,delimiter);
            // Tokenizar la línea
            // Leer y almacenar los datos en la matriz
           // for (int i = 0; i < this->rows; i++) {
                /*if (fgets(line, MAX_LINE, fp) == NULL) {
                    printf("Empty\n");
                    break;
                }*/

                char *token = strtok(line, &delimiter);
                printf("token: %s\n", token);
                /*int j, i = 0;
                while (token && i <this->cols && j < this->cols) {
                    this->data[i][j] = atoi(token);  // Copiar el valor
                    printf("Data: %d\n", this->data[i][j]);
                    token = strtok(NULL, &delimiter);
                    j++;
                    i++;
                }*/

            //}

            //this->printMatrix(this);

        }else{
            printf("Archivo sin contenido");
        }


    }else{
            printf("File is empty");
    }


}


char*** loadDataFromFile(FILE *file, int rows, int cols, char delimiter) {

    char line[MAX_LINE];
    char*** matriz = (char ***)malloc(rows * sizeof(char **));

    if (!matriz) {
        printf("Error al asignar memoria para la matriz.\n");
        return NULL;
    }

    // Leer y almacenar los datos en la matriz
    for (int i = 0; i < rows; i++) {
        if (fgets(line, MAX_LINE, file) == NULL) {
            break;
        }

        matriz[i] = (char **)malloc(cols * sizeof(char *));
        if (!matriz[i]) {
            printf("Error de memoria.\n");
            return NULL;
        }

        // Tokenizar la línea
        char *token = strtok(line, &delimiter);
        int j = 0;
        while (token && j < cols) {
            matriz[i][j] = strdup(token);  // Copiar el valor
            token = strtok(NULL, &delimiter);
            j++;
        }
    }

    return matriz;
}


// CONTAR COLUMNAS
int m_countCols(FILE* file, char delimiter){

    char line[MAX_LINE];
    int cols = 1; // Al menos una columna


    // Leer la primera línea del archivo
    if (fgets(line, MAX_LINE, file) == NULL) {
        return -1; // Error al leer
    }



    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == delimiter) {
            cols++;
        }
    }

    return cols;
}


// COUNT NUM ROWS FROM FILE
int m_countRows(FILE* file) {
    int rows = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            rows++;
        }
    }

    return rows;
}

// PRINT SEPARATOR
void m_printSeparator(int cols){
    int rule = 16 * cols;
        for(int x = 0; x < rule; x++){
            printf("-");
        }
    printf("\n");
}

// PRINT DATA
void m_printData(char*** mtrx, int rows, int cols){

    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("|\t%s\t", mtrx[i][j]);
            }
            printf("\n");
        }
}
