#include "coladim.h"
#include <stdio.h>
#include <stdlib.h>


void iniciaC (TCola *C){
    (*C).pri=NULL;
    (*C).ult=NULL;
}
int vaciaC(TCola C){
    return C.pri==NULL;
}
void poneC (TCola *C, TElementoC X) {
    nodo * aux;
    aux = (nodo *) malloc (sizeof(nodo));
    aux->dato = X;
    aux->sig = NULL;
    if ((*C).pri==NULL)
        (*C).pri=aux;
    else
        (*C).ult->sig=aux;
    (*C).ult=aux;
}
void sacaC (TCola *C, TElementoC *X){
    nodo * aux;
    if ((*C).pri !=NULL) {
        aux = (*C).pri;
        *X = aux->dato;
        (*C).pri = (*C).pri->sig;
        if ((*C).pri == NULL)
            (*C).ult = NULL;
        free(aux);
    }
}
TElementoC consultaC (TCola C){
    if (C.pri !=NULL)
        return C.pri-> dato;
}
