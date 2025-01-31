#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){

    system("clear");

    Matrix* myMatrix = m_matrix();
    //myMatrix->matrixParams(myMatrix,4,4);
    //Matrix* myMatrix = m_matrix();

    printf("Ingrese la cantidad de Filas: ");
    scanf("%d", &myMatrix->rows);

    printf("Ingrese la cantidad de Columnas: ");
    scanf("%d", &myMatrix->cols);

    printf("Cantidad Filas: %d\n", myMatrix->getNumRows(myMatrix));
    printf("Cantidad Columnas: %d\n", myMatrix->getNumCols(myMatrix));

    myMatrix->createMatrix(myMatrix,myMatrix->rows,myMatrix->cols);
    myMatrix->fillRandomMatrix(myMatrix);
    myMatrix->printMatrix(myMatrix);



    return 0;
}
