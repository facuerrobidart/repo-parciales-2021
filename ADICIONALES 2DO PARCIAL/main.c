#include <stdlib.h>
#include <stdio.h>
#define max 20
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
/*2) Dado un grafo almacenado en media matriz de adyacencia (triángulo inferior)
generar, mediante una función void recursiva, un arreglo con el grado de cada uno
de sus vértices.*/
void arreglo(int matriz[][max],int grados[],int i, int j,int orden){ //i,j entran con 0
    if (i<orden){ //mientras no me "caiga" por la parte inferior de la matriz
        if (matriz[i][j]){
            grados[i];
            grados[j];
        }
        if (i==j) //parado en la diagonal principal
            arreglo(matriz,grados,i+1,0,orden); //comienzo la fila siguiente
        else  //si no
            arreglo(matriz,grados,i,j+1,orden); //me muevo hacia la derecha
    }
}

/*3) Dado un árbol N-ario determinar cuántas nodos no hoja cumplen que su valor
numérico es igual a su grado.*/

int valorIgualGrado(TNArio A,TPosicion p){ //p entra con raiz(A)
    TPosicion aux; int gradoLocal=0; int acum=0;
    if (!nulo(p)){
        aux=hijoMasIzq(p,A);
        if (!nulo(aux)){ //si no es hoja
            while (!nulo(aux)){ 
                gradoLocal++; //cuento grado del nodo
                acum+=valorIgualGrado(A,aux); //ejecuto la funcion para los hijos de ese nodo 
                aux=hnoDer(p,A); //muevo a la derecha
            }
            if (gradoLocal==info(p,A)){ //si cumple la condicion retorno 1+los hijos que cumplen
                return 1+acum;
            }else //sino retorno solo los hijos que cumplen
                return acum;
        }else //es hoja, asi que no suma
            return 0;
    }else //arbol vacio
        return 0;
}