#include <stdlib.h>
#include <stdio.h>
#define max 20
typedef struct nodo
{
    char dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo * TArbol;
int main(){
    int ordenVector=0;
    return 0;
}


/*1- Dado un árbol binario de búsqueda (ABB) de caracteres, 
desarrollar un subprograma que genere un vector V con las claves ubicadas en 
niveles menores o iguales a N (N es dato).
Los elementos del vector deben insertarse ordenados descendentemente.*/

void generaVector(TArbol A, char vector[],int *ordenVector,char N){
    if (A){
        if (A->der->dato<N) //esta pregunta es para evitar invocaciones innecesarias de la función
            generaVector(A->der,vector,ordenVector,N);

        if (A->dato<N){ //para obtener un orden descendente el recorrido es inOrden
            vector[*ordenVector]=A->dato;
            (*ordenVector)++;
        }
        generaVector(A->izq,vector,ordenVector,N);
    }
}

/*2- (Utilizar TDA N-ario) Dado un árbol N-Ario de enteros, verificar mediante una función entera, 
que todos los nodos de grado K (K es dato) tienen al menos un hijo con clave igual a cero.*/

int alMenosCero(TNArio A,TPosicion p,int K){ //p entra con raiz(A)
    TPosicion aux; int gradoLocal=0,cero=0;

    if (!nulo(p)){
        aux=hijoMasIzq(p,A);
        while (!nulo(aux) && gradoLocal<=K){
            gradoLocal++;
            if (info(aux,A)==0)
                cero++;
            aux = hnoDer(aux,A);
        }
        if (gradoLocal==K && cero)
            return 1;
        else
            return alMenosCero(A,hijoMasIzq(p,A),K)||alMenosCero(A,hnoDer(p,A),K);
    }else
        return 1;
}

/*3- Dado un digrafo de N vértices con aristas ponderadas almacenado en una matriz de adyacencia, 
hallar cuántos nodos que tienen bucle tienen grado de entrada par.*/

void grEntradaPar(int matriz[][max],int orden,int i,int j,int *cumple){ //i,j entran en orden-1, cumple variable inicializada en cero
    if (j>=0)

}