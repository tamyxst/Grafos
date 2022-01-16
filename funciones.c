#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "estructuras.h"
/**
\file funciones.c
\brief Funciones del proyecto Boletín 4 Ejercicio 2.
\author Tamara Gascón Moreno
\version 1
\dat 2019
*/
/**
\brief Funciones
*/
char muestraMenu(){
    char op;
    printf("\n\***********PLANIFICACION DE RUTAS***********\n\n");
    printf("1.- Comprobar validez del fichero\n");
    printf("2.- Obtener ruta mas corta\n");;
    printf("3.- Salir");
    fflush(stdin);
    printf("\nOpcion: ");scanf("%c", &op);
    return op;
}

pNodo buscarNodo(pNodo n, char *nombre){
    pNodo pAux = n;
    while(pAux!=NULL){
        if(strcmp(pAux->nombre,nombre)==0){
            //printf("Encontrado %s\n", pAux->nombre);
            return pAux;
        }else{
            pAux=pAux->sgte;
        }
    }
    return NULL;
}

void mostrarNodos(pNodo n){
    pNodo nAux=n;
    while(nAux!=NULL){
        printf("Ciudad: %s\n", nAux->nombre);
        nAux = nAux->sgte;
    }
}

void mostrarArcos(pNodo n){
    char nombre[250];
    printf("Introduce nombre ciudad\n");
    fflush(stdin);
    scanf("%s",&nombre);
    pArco a;
    pNodo nAux = buscarNodo(n, nombre);
    if(nAux!=NULL){
        printf("Nodo encontrado: %s\n",nAux->nombre);
        a=nAux->apunta;
        while(a!=NULL){
            //printf("Origen %s\n",a->sgte->apunta->nombre);
            printf("Destino %s\n",a->apunta->nombre);
            a = a->sgte;
        }
    }else{
        printf("Error: No se ha encontrado coincidencias");
    }
}

void mostrarTodosArcos(pNodo n){
    pArco a;
    //pNodo nAux = buscarNodo(n, nombre);
    pNodo nAux = n;
    while(nAux!=NULL){
        printf("Origen: %s\n", nAux->nombre);
        a=nAux->apunta;
        while(a!=NULL){
            //printf("Origen %s\n",a->sgte->apunta->nombre);
            printf("\t---> %s ---> ",a->apunta->nombre);
            printf("%d km\n",a->km);
            a = a->sgte;
        }
        printf("\n");
        nAux= nAux->sgte;
    }

}



pNodo crearNodo(pNodo n, char *nombre){
    int tam;
    pNodo nAux =(struct nodo *)malloc(sizeof(struct nodo));
    if(nAux!=NULL){
        tam = strlen(nombre);
        nAux->nombre = (char *)malloc((tam+1)*sizeof(char));
        strncpy(nAux->nombre, nombre, tam+1);
        nAux->apunta=NULL;
    }
    if(n!=NULL){
        nAux->sgte = n;
    }else{
        nAux->sgte = NULL;
    }
    n = nAux;
    return n;
}

pNodo cargarCiudades(pNodo n){
    FILE *fc;
    char *nombre = (char*)malloc(sizeof(char)*200);
    printf("Cargando fichero de nodos...\n");
    fc = fopen("nodos.txt","r");
    if (fc == NULL){
        printf("Error: El fichero no puede abrirse\n");
    }else{
        while(fscanf(fc, "%s", nombre)!= EOF){
            n = crearNodo(n,nombre);
        }
    }
    free(nombre);
    return n;
}

pNodo crearArco(pNodo n, char *origen, char *destino, int km){
    pArco a = (struct arco *)malloc(sizeof(struct arco));
    pNodo pOrigen = NULL, pDestino =NULL;
    pOrigen = buscarNodo(n,origen);
    pDestino = buscarNodo(n,destino);

    a->apunta = pDestino; //Ciudad Destino
    a->sgte = pOrigen->apunta;
    pOrigen->apunta = a;
    a->km = km;

    return n;
}

pNodo cargarArcos(pNodo n){
    FILE *fc;
    char *origen = (char*)malloc(sizeof(char)*200);
    char *destino = (char*)malloc(sizeof(char)*200);
    int km;
    printf("Cargando fichero de arcos...\n");
    fc = fopen("arcos.txt","r");
    if (fc == NULL){
        printf("Error: El fichero no puede abrirse\n");
    }else{
        while(fscanf(fc, "%s %s %d", origen, destino, &km)!= EOF){
            crearArco(n,origen,destino,km);
        }
    }
    return n;
}

pNodo obtenerRutaCorta(pNodo n){
    pNodo pOrigen = NULL, pDestino =NULL;
    char *origen = (char*)malloc(sizeof(char)*200);
    char *destino = (char*)malloc(sizeof(char)*200);
    printf("Introduce una ciudad de origen:\n");
    fflush(stdin);
    scanf("%d",origen);
    printf("Introduce una ciudad destino:\n");
    fflush(stdin);
    scanf("%d",destino);

    pOrigen = buscarNodo(n,origen);
    pDestino = buscarNodo(n,destino);
    //Falta por terminar
}
