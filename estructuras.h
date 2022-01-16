#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct arco{
    int km;
    struct arco *sgte;
    struct nodo *apunta;
}arco, *pArco;

typedef struct nodo{
    char *nombre;
    struct nodo *sgte;
    struct arco *apunta;
}nodo, *pNodo;
#endif
