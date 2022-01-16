#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h">
/**
\file main.c
\brief Main del proyecto Boletín 4 Ejercicio 2.
\author Tamara Gascón Moreno
\version 1
\dat 2019
*/
/**
\brief Main
*/
int main()
{
    pNodo n = NULL;
    char op;
    for(;;){
        op=muestraMenu();
        switch(op){
            case '1':
                n = cargarCiudades(n);
                n = cargarArcos(n);
                //mostrarNodos(n);
                mostrarTodosArcos(n);
                break;
            case '2':
                obtenerRutaCorta(n);
                break;
            case '3':
                printf("Fin del programa");
                return 1;
            default:
                printf("Error!");
                break;
        }
    }

}
