#include <stdio.h>
#include <stdlib.h>
#define max 20

typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;
typedef struct nodoL{
    int etiqueta;
    int costo;
    struct nodoL *sig;
}nodoL;
typedef nodo *TArbol;
typedef nodoL *TLista;
int main(){



    return 0;
}

/*EJ1 Dado un árbol binario que proviene de la transformación de un árbol general de claves enteras,
desarrollar una FUNCIÓN ENTERA que cuente cuántas claves de nodos NO HOJA, eran menores a la suma
de las claves de sus hijos (en el árbol general)*/

int menoresALaSuma(TArbol A){
    TArbol aux; int acum=0;
    if (A)
        if (A->izq){ // no es hoja
            aux=A->izq;
            while (aux){
                acum+=aux->dato;
                aux=aux->der;
            }

            return (A->dato<acum)+menoresALaSuma(A->izq)+menoresALaSuma(A->der); //invoco para el hermano y el hijo
        }else //si es hoja
            return menoresALaSuma(A->der); //solo retorno los hermanos que cumplen
    else
        return 0;
}



/*EJ2 Dado un árbol N-Ario de enteros, verificar que exista algún nodo NO HOJA con clave K en el nivel K
(K dato)*/

int claveKnivelK(TNArio A,TPosicion p,int nAct,int K){
    if (!nulo(p))
        if (nAct<K) //hasta que no llegue al nivel k
            return (claveKnivelK(A,hijoMasIzq(p,A),nAct+1,K)||claveKnivelK(A,hnoDer(p,A),nAct,K)); //invoco hijo y hermano
        else //nAct==K
            if (info(p,A)==K && nAct==K && !nulo(hijoMasIzq(p,A)))
                return 1;
            else
                return claveKnivelK(A,hnoDer(p,A),nAct,K);
    else
        return 0;
}

/*EJ3 Dado G un digrafo con N vértices con aristas ponderadas, almacenado en una lista de adyacencia,
determinar cuál es el vértice que, conteniendo bucle tiene el mayor costo promedio de las aristas
que llegan a él desde otros vértices. EL GRAFO NO DEBE RECORRERSE MAS DE UNA VEZ*/

int iniciaVector(int vector[],int N){
    for (int i=0;i<N;i++)
        vector[i]=0;
}
int mayorCostoPromedio(TLista L[],int N){
    TLista aux;
    int costos[N]; int bucles[N]; int contAristas[N];
    float maxProm=0; int maxVertice=-1;
    iniciaVector(costos,N);iniciaVector(bucles,N);iniciaVector(contAristas,N);
    for(int i=0;i<N;i++){
        aux = L[i]->sig; //El primer elemento es el nombre del vertice
        while (aux){
            contAristas[aux->etiqueta-1]++; //cuento la arista que entra
            costos[aux->etiqueta-1]+=aux->costo; //sumo el costo
            if (L[i]->etiqueta==aux->etiqueta){ //pregunto si es bucle
                bucles[aux->etiqueta-1]=1;
            }
        }
    }
    for(int j=0;j<N;j++){
        if (bucles[j] && (float)costos[j]/contAristas[j]>maxProm){
            maxProm=(float)costos[j]/contAristas[j];
            maxVertice=j+1;
        }
    }

    return maxVertice;
}