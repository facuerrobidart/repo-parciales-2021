#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaestatica.h"
typedef struct nodito{
    int cod;
    float peso;
    char destinatario[51];
    struct nodito *sig;}nodito;
typedef nodito *TSubLista;
typedef struct nodo{
    char idDock[6];
    char zona[3];
    int pesoMax;
    TSubLista paquetes;
    struct nodo *sig;}nodo;
typedef nodo *TLista;
int main()
{
    printf("Hello world!\n");
    return 0;
}
/*Dadas la lista y la pila, localice un paquete en la pila pendiente de reparto y cárguelo en la lista, para cargar el paquete
debe verificarse no sólo la zona, sino que el dock no supere su peso máximo permitido.
El paquete irá al final de la sublista correspondiente y será retirado de la pila. Los paquetes que se hayan revisado previo a
encontrar alguno que se haya podido cargar en la lista quedarán en la misma pila (en el mismo orden que tenían).*/

void ponePedido(TLista L,TPila *pendientes,int cod){
    TLista auxL; TElementoP saca; TPila pAux;
    iniciaP(&pAux);float sumapeso;
    TSubLista antS,actS,nuevo;

    while (!vaciaP(*pendientes)){
        sacaP(pendientes,&saca);
        auxL=L;
        while (auxL!=NULL && strcmp(saca.zona,auxL->zona)!=0){
            auxL=auxL->sig;
        }
        if (auxL!=NULL){///si aux!=NULL significa que encontre la zona
            sumapeso=0;
            actS=auxL->paquetes;
            antS=NULL;
            while (actS!=NULL){
                sumapeso+=actS->peso;
                antS=actS;
                actS=actS->sig;
            }
            if ((sumapeso+saca.peso)/1000<=auxL->pesoMax){ ///si no supero el peso
                nuevo=(TSubLista)malloc(sizeof(nodito)); ///nuevo nodo en la sublista
                nuevo->cod=saca.cod;
                nuevo->peso=saca.peso;
                nuevo->sig=NULL;
                if (antS)
                    antS->sig=nuevo;
                else
                    auxL->paquetes=nuevo;
            }else ///los que no entran van a la pila auxiliar
                poneP(&pAux,saca);
        }else
            poneP(&pAux,saca); ///si no encuentro la zona tambien va a pila auxiliar
    }

    while (!vaciaP(pAux)){ ///vuelvo a poner en la pila original
        sacaP(&pAux,&saca);
        poneP(pendientes,saca);
    }
}

/* A partir de la lista, eliminar el paquete codP que se sabe puede estar en las zonas Z1 o Z2.
	Hallar e informar el peso promedio de los paquetes que permanecieron en la zona en la que estaba codP
	(codP, Z1 y Z2 son datos solicitados al operador).*/

void eliminaCod(TLista L){
    char z1[3],z2[3]; int codP;int eliminado=0; ///bandera
    TLista auxL=L; TSubLista antS,actS,elim;
    float sumapeso; int cuenta;
    scanf("%s",z1); scanf("%s",z2); scanf("%d",&codP);

    while (auxL!=NULL && !eliminado){
        if (strcmp(z1,auxL->zona)==0 || strcmp(z2,auxL->zona)==0){ ///si es una de las dos zonas
            antS=NULL; actS=auxL->paquetes;
            sumapeso=0;cuenta=0;
            while (actS!=NULL){
                if (codP!=actS){ ///si no encuentro, sumo y cuento
                    cuenta++;
                    sumapeso+=actS->peso;
                    antS=actS;
                    actS=actS->sig;
                }else{ /// si encuentro elimino
                    eliminado=1;
                    elim=actS;
                    actS=actS->sig;
                    if (antS==NULL) ///caso que elimino cabecera
                        auxL->pedidos=actS;
                    else
                        antS->sig=actS;
                    free(elim);
                }
                if (!eliminado) ///si encontre la zona pero el paquete no esta ahi tengo que pasar al proximo nodo de la lista
                    auxL=auxL->sig;
            }
        }else
            auxL=auxL->sig;
    }

    if (!eliminado)
        printf("No se ha encontrado el codigo en las zonas informadas\n");
    else
        printf("Paquete eliminado, peso promedio de los paquetes restantes en zona %s: %f\n",auxL->zona,(float)sumapeso/cuenta);
}
