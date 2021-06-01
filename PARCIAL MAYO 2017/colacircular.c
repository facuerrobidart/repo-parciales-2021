#include "colacircular.h"
#include <stdio.h>
#include <stdlib.h>


void iniciaCC (TColaCC *C) {
    (*C).pri=-1;
    (*C).ult=-1;
}
int vaciaCC(TColaCC C){
    return C.pri==-1;
}

void poneCC(TColaCC *C,TElementoCC X){
    if (!((*C).ult==49 && (*C).pri==0 || (*C).ult+1==(*C).pri)) {
        if ((*C).pri==-1){
            (*C).pri = 0;
            (*C).ult = 0;
        }
        else
            if (*C).ult == 49)
                (*C).ult = 0;
            else
                (*C).ult += 1;
        (*C).dato[(*C).ult]=X;
    }
}
void sacaCC (TColaCC *C, TElementoCC *X) {
    if ((*C).pri != -1) {
        *X = (*C).dato[(*C).pri];
        if ((*C).pri == (*C).ult)
            iniciaC(C);
        else
            if (*C).pri == 49)
                (*C).pri = 0;
            else
                (*C).pri += 1;
    }
}

TElementoCC consultaCC (TColaCC C){
    if (C.pri !=-1)
        return C.dato[C.pri];
}
