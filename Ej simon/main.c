#include <stdio.h>
#include <stdlib.h>

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