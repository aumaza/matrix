#!/bin/bash

clear

echo "================================================================="
echo "COMPILANDO APLICACION..."
echo "================================================================="

gcc -Wall -g -std=c2x -o bin/app \
    main.c matrix.h matrix.c

cd bin/

if [ -f app ]; then
    echo "Desea ejecutar la aplicación? [s | n]"
    read resp

    if [[ $resp == 's' ]]; then
    ./app
    elif [[ $resp == 'n' ]]; then
    echo "Sólo se deja el archivo compilado..."
    else
    echo "Debe seleccionar s ó n..."
    fi
else
    echo "Archivo ejecutable no encontrado..."
fi
