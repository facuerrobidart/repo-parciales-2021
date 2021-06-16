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

            return (A->dato<acum)+menoresALaSuma(A->izq)+menoresALaSuma(A->der);
        }else
            return menoresALaSuma(A->der); //solo retorno los hemanos que cumplen
    else
        return 0;
}



/*EJ2 Dado un árbol N-Ario de enteros, verificar que exista algún nodo NO HOJA con clave K en el nivel K
(K dato)*/

/*EJ3 Dado G un digrafo con N vértices con aristas ponderadas, almacenado en una lista de adyacencia,
determinar cuál es el vértice que, conteniendo bucle tiene el mayor costo promedio de las aristas
que llegan a él desde otros vértices. EL GRAFO NO DEBE RECORRERSE MAS DE UNA VEZ*/

