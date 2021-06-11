#include <stdio.h>
#include <stdlib.h>
#define max 20
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

/*(Utilizar TDA N-ario) Dado un árbol N-Ario de enteros, verificar
mediante una funcion int, que existe al menos un nodo de grado G
(distinto de 0 y dato de entrada) que posea mas de la mitad de sus
hijos con clave negativa*/

int mitadNegativos(TNArio A, TPosicion p, int G){ //A, raiz(A),G
    int gradoLocal=0,negativos=0,flag=0;TPosicion aux;
    if (!nulo(p)){
        aux = hijoMasIzq(p,A);
        while (!nulo(aux) && gradoLocal<=G){
            gradoLocal++;
            if (info(aux,A)<0)
                negativos++;
            aux=hnoDer(aux,A);
        }
        if (gradoLocal==G && negativos>(float)gradoLocal/2)
            return 1;
        else
            return mitadNegativos(A,hijoMasIzq(p,A),G)||mitadNegativos(A,hnoDer(p,A),G);
    }else
        return 0;
}
/*Dado un digrafo de N vértices con aristas ponderadas almacenado
en una matriz de adyacencia, hallar el porcentaje de vertices que teniendo
bucle poseen el grado máximo de salida (RECORRIDO RECURSIVO)*/
void maxGradoBucle(int matriz[][max],int i,int j,int orden,int *gMax,int gAct,int *bucles){ //i y j entran con orden-1, gMax es una variable inicializada en 0, gAct entra con 0
    if (i>=0) //mientras no me salga por arriba de la matriz
        if (j!=0){ // si no estoy en el principio de la fila
            if (matriz[i][j])
                maxGradoBucle(matriz,i,j-1,orden,gMax,gAct+1,bucles);
            else
                maxGradoBucle(matriz,i,j-1,orden,gMax,gAct,bucles);
        }else{ //j==0 FIN DE FILA
            if (matriz[i][j] && gAct+1>*gMax){ //nuevo maximo con matriz[i][0]!=0
                (*gMax)=gAct+1; //entonces al gMax es igual al acumulado mas 1
                if (matriz[i][i]) //pregunto si existe el bucle para este nuevo maximo
                    (*bucles)=1;
                else
                    (*bucles)=0;
            }else{
                if ((matriz[i][j] && gAct+1==*gMax)||(gAct==*gMax)) //si el grado del vertice i == grMax 
                    if (matriz[i][i]) //esto se podria juntar en el if de arriba pero quita legibilidad
                        (*bucles++); //cuento el bucle
                if (gAct>*gMax){//nuevo maximo con matriz[i][0]==0
                    (*gMax)=gAct; //gMax es el acumulado
                    if (matriz[i][i])
                        (*bucles)=1;
                    else
                        (*bucles)=0;
                }
            }
            maxGradoBucle(matriz,i-1,orden-1,orden,gMax,gAct,bucles); //comienzo con la fila siguiente
        }
}