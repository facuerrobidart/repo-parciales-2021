#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaestatica.h"

typedef struct nodito{
    int id;
    float imp;
    struct nodito *sig;}nodito;
typedef nodito *TSubLista;
typedef struct nodo{
    char cod[3];
    float comisiones;
    TSubLista pAut;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

int main()
{

    return 0;
}

void mueveAutorizados(TLista *L,TCola *C){
    TCola noAutorizados; TLista antL,actL,auxL;TSubLista antS,actS,auxS;
    TElementoC saca;
    iniciaC(&noAutorizados);

    while (!vaciaC(*C)){
        sacaC(C,&saca);
        if (saca.aut){
            antL=NULL; actL=*L;
            while (actL !=NULL && strcmp(saca.cod,anc)!=0){
                antL=actL;
                actL=actL->sig;
            }
            auxS = (TSubLista)malloc(sizeof(nodito)); ///creo el nodo de los pedidos del comercio
            auxS->id=saca.id; auxS->imp=saca.imp;

            if (actL==NULL){ ///se crea nuevo comercio, lista vacia o al final
                auxL = (TLista)malloc(sizeof(nodo));
                strcpy(auxL->cod,saca.cod);
                auxL->comisiones=saca.imp*0,07; ///inicio las comisiones con la primer comision
                auxL->pAut=auxS; auxL->sig=NULL; ///asigno la sublista a la lista
                    if (antL==NULL) ///significa que la lista esta vacia
                        *L=auxL;
                    else ///si no, llegue al final
                        antL->sig=auxL; ///añado el nuevo comercio al final de la lista
            }else{ ///si no me caigo de la lista, encontre un comercio existente
                antS=NULL; actS=actL->pAut;
                while (actS!=NULL && auxS->id>actS->id){
                    antS=actS;
                    actS=actS->sig;
                }
                if (antS==NULL){ ///si la sublista esta vacia o es anterior al primer elemento
                    auxS->sig=actL->pAut; ///esta asignacion puede ser null o el primer nodo de la sublista
                    actL->pAut=auxS;
                }else{ ///me movi en la lista
                    antS->sig=auxS;
                    auxS->sig=actS;
                }
                actL->comisiones+=saca.imp*0.07;
            }
        }else ///si el pedido no esta autorizado va a una cola auxiliar
            poneC(&noAutorizados,saca);
    }

    while (!vaciaC(noAutorizados)){
        sacaC(&noAutorizados,&saca);
        poneC(C,saca);
    } ///vuelvo a poner los NO autorizados en la cola
}

void eliminaImp(TLista *L){
    TLista antL,actL; char codComercio[4];float topeImporte;
    TSubLista antS,actS,elimS;
    int cuentaElim=0; float sumaElim=0;
    scanf("%s",codComercio);
    scanf("%f",&topeImporte);

    if (*L){
        actL=*L; antL=NULL;
        while (actL!=NULL && strcmp(actL->cod,codComercio!=0){
            antL=actL;
            actL=actL->sig;
        }
        if (actL!=NULL){///encontre el comercio
            actS=actL->pAut;antS=NULL;
            while (actS!=NULL){
                if (actS->imp<topeImporte){
                    elimS=actS;
                    actS=actS->sig;
                    actL->comisiones-=elimS->imp*0.07;
                    cuentaElim++; sumaElim+=elimS->imp;
                    free(elimS);
                    if (antS==NULL){///caso cabeza
                        actL->pAut=actS;
                    }else
                        antS->sig=actS;
                }else{
                    antS=actS;
                    actS=actS->sig;
                }
            }
            if (actL->pAut==NULL){ ///si el comercio se queda sin pedidos
                if (antL==NULL)
                    *L=actL->sig;
                else
                    antL->sig=actL->sig;
                free(actL);
            }
            printf("Se han eliminado %d pedidos\n",cuentaElim);
            printf("El promedio de los pedidos eliminados es %6.2f\n",(float)sumaElim/cuentaElim);
        }else
            printf("El comercio no existe\n");
    }else
        printf("La lista esta vacia\n");
}
