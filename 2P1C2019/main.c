#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
    char dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo * TArbol;
int main(){

    return 0;
}

/*Dado un ABB de caractere obtener la clave del nodo de grado 2 que se encuentre ubicado en el mayor nivel
si no hubiera ningun nodo de grado 2 en el arbol, retornar el caracter blanco*/


void claveMaxGr2(TArbol A,int nAct, int *nMax,int *clave){ //nAct entra con 1, nMax variable inicializada en 0, clave variable inicializada con caracter blanco
    if (A){
        if (A->der && A->izq && nAct>*nMax){ //nodo de grado 2 con mayor grado
            *nMax=nAct;
            *clave=A->dato;
        }
        claveMaxGr2(A->der,nAct+1,nMax,clave);
        claveMaxGr2(A->izq,nAct,nMax,clave);
    }
}