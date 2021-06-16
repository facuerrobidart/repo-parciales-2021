#include <stdio.h>
#include <stdlib.h>
#define max 25
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo *TArbol;

int main(){


    return 0;
}
/*EJ1 Dado un árbol binario que proviene de la transformación de un bosque, determinar cuántos árboles
del bosque tenían exactamente un nodo de grado K(k es dato) NO SE PERMITE USAR FUNCIONES VOID*/

int nodosGradoK(TArbol A,int K){
    TArbol aux; int cont=0;int hijosQueCumplen=0;
    if (A){
        aux=A->izq; // me paro en el hijo mas a izq
        while (aux){
            hijosQueCumplen+=nodosGradoK(aux,K); //llamo a la funcion para los hijos
            cont++;
            aux=aux->der;//me muevo entre hermanos
        }
        return (cont==K)+hijosQueCumplen;
    }
        return 0;
}

int cuantosTenianK(TArbol A,int K){
    TArbol aux; int cuantosK=0;
    if (A){
        aux=A;
        while (aux){
            if (cuantosTenianK(aux,K)==1) //busco los que tengan exactamente un solo nodo de grado K
                cuantosK++;
            aux=aux->der; //me muevo entre los arboles del bosque
        }
        return cuantosK;
    }else
        return 0;
}

/*EJ2 dado un arbol N-ario de caracteres, determinar si en todo los niveles hay al menos una vocal*/

void todosLosNiveles(TNArio A,TPosición p,int nAct, int tieneVocal[],int *n){
    if (!nulo(p)){
        if (info(p,A)=='a'||info(p,A)=='e'||info(p,A)=='e'||info(p,A)=='i'||info(p,A)=='u')
            tieneVocal[nAct-1]++;
        if (nAct>*n)
            (*n) = nAct;
        
        todosLosNiveles(A,hnoDer(p,A),nAct,tieneVocal,n);
        todosLosNiveles(A,hijoIzq(p,A),nAct+1,tieneVocal,n);
    }
}

int hayVocales(int tieneVocal[],int n){
    int i=0;

    while (i<n && tieneVocal[i])
        i++;

    return i==n;
}

/*EJ3 dado un digrafo con aristas ponderadas almacenado en una matriz de adyacencia, realizar una única
función recursiva que obtenga el vértice con mayor costo de entrada promedio (NO SE PERMITEN CICLOS)*/

void maxGradoProm(int mAdy[][max],int i,int j,int orden,int sum,float *promMax){ //i,j entran con orden-1, sum con 0, promMax inicializado en 0
    if (j>=0){
        if (i>=0){
            maxGradoProm(mAdy,i-1,j,orden,sum+mAdy[i][j],promMax);
        }else{ //i==-1 fin de linea
            if ((float)sum/orden>*promMax)
                (*promMax)=(float)sum/orden;
            maxGradoProm(mAdy,orden-1,j-1,orden,0,promMax);
        }
    }
}