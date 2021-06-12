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

char claveMaxGr2Char(TArbol A){
    int izq,der;
    if (A){
        izq=claveMaxGr2Char(A->izq);
        der=claveMaxGr2Char(A->der);
        if (A->der && A->izq && izq==' ' && der==' ') //si es de grado 2 y no encontre uno mayor
            return A->dato;
        else{ //si es de grado 1 o encontre uno mayor
            if (izq!=' ')
                return izq;
            else
                if (der!=' ')
                    return der; //devuelvo el que haya sido mayor
                else //si es de grado 1 y no hay ninguno mayor devuelvo caracter vacio
                    return ' ';
        }
    }else
        return ' ';
}

/*TDA N-Ario: Dado un árbol N-Ario de enteros, desrrollar una funcion int
que obtenga la cantidad de nodos con grado mayor a 1 entre los niveles k1 y k2, 
que verifican que las claves del primer y ultimo hijo son mayores al nivel del nodo*/

int loco(TNArio A, TPosicion p,int k1,int k2,int nAct){
    int gradoLocal=0; TPosicion aux; int pri,ult;
    if (!nulo(p)&&nAct<=k2){
        if (nAct<k1)
            return loco(A,hijoIzq(p,A),k1,k2,nAct+1)+loco(A,hnoDer(p,A),k1,k2,nAct);
        else{
            aux = hijoIzq(p,A);
            pri = info(aux,A);
            while(!nulo(aux)){
                gradoLocal++;
                ult=info(aux,A);
                aux=hnoDer(aux,A);
            }
            if (gradoLocal>1 && pri>nAct && ult>nAct)
                return 1+loco(A,hijoIzq(p,A),k1,k2,nAct+1)+loco(A,hnoDer(p,A),k1,k2,nAct);
            else
                return loco(A,hijoIzq(p,A),k1,k2,nAct+1)+loco(A,hnoDer(p,A),k1,k2,nAct);
        }
    }else
        return 0;
}