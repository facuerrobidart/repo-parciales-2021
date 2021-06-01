#include <stdio.h>
#include <stdlib.h>
#include "pilaestatica.h"


void poneP(TPila *P, TElementoP x) {
    if ( ((*P).tope)!= MAX-1)
        (*P).datos[++((*P).tope)] = x;
}
void sacaP(TPila *P, TElementoP* x) {
    if (((*P).tope) != -1)
        (*x) = (*P).datos[((*P).tope)--];
}
TElementoP consultaP(TPila P) {
    if ((P.tope) != -1)
        return P.datos[P.tope];
}
int vaciaP(TPila P) {
    return (P.tope == -1);
}
void iniciaP (TPila *P) {
    (*P).tope=-1;
}
