#include "piladim.h"


void poneP(TPila *P, TElementoP x) {
    TPila N;
    N = (TPila)malloc(sizeof(nodop));
    N->dato = x;
    N->sig = *P;
    *P=N;
}
void sacaP(TPila *P, TElementoP * x) {
    TPila N;
    if (*P) { // if (*P != NULL)
        N = *P;
    *x = (*P)->dato;
    *P = (*P)->sig;
    free(N);
 }
}
TElementoP consultaP(TPila P) {
    if (P) // if (P != NULL)
        return P->dato;
}
int vaciaP(TPila P) {
    return (P == NULL);
}
void iniciaP(TPila *P) {
    *P =NULL;
}
