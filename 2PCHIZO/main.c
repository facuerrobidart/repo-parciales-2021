#include <stdio.h>
#include <stdlib.h>
#define max 20
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){


    return 0;
}

/*1) Dado un ABB generar un vector con las claves ubicadas en niveles mayores o iguales a N (N dato) 
ordenadas descendentemente*/

void generaVector(TArbol A,int vector[],int *dim,int nAct,int N){ //dim variable inicializada en cero, nAct entra con cero
    if (A){
        generaVector(A->izq,vector,dim,nAct+1,N);
        if (nAct>=N){
            vector[*dim]=A->dato;
            (*dim)++;
        }
        generaVector(A->der,vector,dim,nAct+1,N);
    }
}

/*2) Dado un N-ario verificar si cumple que para todos los nodos con grado N tienen al menos dos hijos con clave par*/

int gradoNhijosPares(TNArio A,TPosicion p,int N){ //p entra con raiz(A)
    int gradoLocal=0,clavesPares=0; TPosicion aux;
    if (!nulo(A)){
        aux=hijoMasIzq(p,A);
        while (!nulo(aux)){
            gradoLocal++;
            if (info(aux,A)%2==0)
                clavesPares++;
            aux = hnoDer(aux,A);
        }

        if (gradoLocal==N && clavesPares<2)
            return 0;
        else
            return gradoNhijosPares(A,hijoMasIzq(p,A),N)&&gradoNhijosPares(A,hnoDer(p,A),N);
    }else
        return 1;
}

/*3) Dado un digrafo con aristas ponderadas almacenado en una matriz de adyacencia contar la cantidad
 d vertices que tengan grado de entrada par y no tengan bucle*/

void entradaParSinBucle(int matriz[][max],int i,int j,int orden,int grAct,int *cumple){//i,j entran con orden-1, grAct con 0, *cumple var inicializada en 0
    if (j>=0)
        if (i>=0){
            if (matriz[i][j])
                entradaParSinBucle(matriz,i-1,j,orden,grAct+1,cumple);
            else
                entradaParSinBucle(matriz,i-1,j,orden,grAct,cumple);
        }else{ //i==-1 fin de columna
            if (matriz[j][j]==0 && grAct%2)
                (*cumple)++;
            entradaParSinBucle(matriz,orden-1,j-1,orden,0,cumple); //comienzo por la columna de la izquierda
        }
}