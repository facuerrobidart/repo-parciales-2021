#include "colaestatica.h"
#include <stdio.h>
#include <stdlib.h>

void iniciaC (TCola *C) {
    (*C).pri=-1;
    (*C).ult=-1;
}
int vaciaC(TCola C){
    return C.pri==-1;
}
void poneC (TCola *C, TElementoC X) {
    if ((*C).ult != MAX-1) {
        if ((*C).pri==-1)
            (*C).pri = 0;
    (*C).dato[++((*C).ult)]=X;
 }
}
void sacaC (TCola *C, TElementoC *X) {
    if ((*C).pri != -1) { // !vaciaC(*C)
        *X = (*C).dato[(*C).pri];
    if ((*C).pri == (*C).ult)
        iniciaC(C);
    else
        (*C).pri +=1;
 }
}
TElementoC consultaC (TCola C){
    if (C.pri !=-1)
        return C.dato[C.pri];
}
