#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

int main(){

    system("clear");
    //char delimiter = ',';
    FILE* fp = fopen("data.csv", "r");
    Matrix* myMatrix = m_matrix();

    if(fp != NULL){

        int rows = myMatrix->countRows(fp, DELIMITER);
        rewind(fp);
        int cols = myMatrix->countCols(fp,DELIMITER);
        rewind(fp);
        char*** matriz = loadDataFromFile(fp,rows,cols,DELIMITER);
        fclose(fp);




        if (!matriz) {
            EXIT_FAILURE;
        }

        // Mostrar los datos cargados
        myMatrix->printSeparador(cols);
        printf("Datos del archivo. Cantidas de Filas: %d y Columnas: %d \n", rows, cols);
        myMatrix->printSeparador(cols);
        myMatrix->printData(matriz,rows,cols);
        myMatrix->printSeparador(cols);



    }else{
        printf("Cannot open file");
        EXIT_FAILURE;
    }



    return 0;
}
