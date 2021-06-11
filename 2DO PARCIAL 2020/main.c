#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
    unsigned int dato;
    struct nodo *izq,*der;
}nodo;
typedef nodo * TArbol;
int main(){

    return 0;
}

/*1) Dado un arbol binario de números naturales que proviene 
de la transformación de un arbol general, obtener la menor clave
de grado G ubicada en un nivel menor a N.(G y N son datos de entrada
y se refieren a grado y nivel en el arbol gral). En caso de no encontrar
ningun nodo retornar 999*/

int menorClave(TArbol A,int G,int N,int nAct){ //nAct entra con 1(nivel de la raiz)
    TArbol aux; int guarda,gradoLocal=0,menor=999; 
    if (A==NULL || nAct>=N)
        return 999;
    else{
        aux=A->izq;
        while (aux){ //recorro los hermanos a derecha
            gradoLocal++; //cuento el grado de A
            guarda=menorClave(aux,G,N,nAct+1);//esta asignacion evita ejecutar dos veces la función en el if
            if (guarda<menor)
                menor=guarda;
            aux=aux->der;
        }
        return (gradoLocal==G && A->dato<menor)? A->dato:menor;
    }
}


