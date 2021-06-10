#include <stdlib.h>
#include <stdio.h>
typedef struct nodo{
    int dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo *TArbol;
int main(){


    return 0;
}

/*1) Dado un árbol binario que proviene de la transformación de un árbol general,
desarrollar una función int que verifique si en el árbol general existía algún nodo de
grado 2 tal que las claves de sus hijos eran iguales u opuestas.*/

int grado2Opuestos(TArbol A){
    int ant,act=0,gradoLocal=0,flag=0; TArbol aux;
    if (A!=NULL){
        aux=A->izq; //el hijo a izquierda es el hijo mas a izquierda en el arbol gral
        while (aux && flag==0){
           gradoLocal++;
           ant=act;
           act=aux->dato; //me voy quedando con los numeros
           flag+=grado2Opuestos(aux); //invoco a la funcion para el nodo
           aux=aux->der; //me muevo al hermano a derecha
        }
        if ((gradoLocal==2 && ant==(-1)*act)||flag) //si cumple el padre o alguno de los hijos
            return 1;
        else //Si ni el padre cumple ni ninguno de los hijos
            return 0;
    }else
        return 0;
}