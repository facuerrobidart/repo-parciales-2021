#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colacircular.h"

typedef struct nodito{
    char tipo[3];
    float disp;
    struct nodito *sig;}nodito;
typedef nodito *TSublista;
typedef struct nodo{
    unsigned int num;
    TSublista comb;
    struct nodo *sig;}nodo;
typedef nodo *TLista;

/*typedef struct{
    char patente[8];
    char tipo[3];
    float litros;}TElementoC;*/ ///ELEMENTOS DE LA COLA

void cargaC(TCola *C);
void cargaL(TLista *L);
void asigna(TLista L,TCola *C);
void eliminaTC(TLista L,char TC[3]);
int main()
{
    TCola C; TLista L; char TC[3];
    iniciaC(&C); cargaC(&C);
    cargaL(&L); ///cargaL tambien inicializa la lista
    asigna(L,&C);
    printf("Ingrese un tipo de combustible a eliminar!\n");
    scanf("%s",TC);
    eliminaTC(L,TC);
    return 0;
}

void asigna(TLista L,TCola *C){ ///PUNTO 1)a)
    TLista auxL=L,ini; TSublista auxS; int noAtendidos=0; TElementoC saca; int colocado=1; ///colocado comienza en 1 pues en la primera iteracion saco de la cola

    while (!vaciaC(*C)){ ///controlo que no me quede sin autos en la cola, L viene cargada desde el main
        // OJO, la condicion del while está mal, deberia preguntar (!vaciaC(*C) || !colocado)
        //si no, el ultimo auto no se coloca
        if (colocado){ ///si pude colocar el anterior, saco uno nuevo de la cola
            sacaC(C,&saca);
            ini=auxL; ///ini guarda la posicion por la que empiezo a buscar
        }

        auxS=auxL->comb; ///me paro en la cabecera de la sublista
        while(auxS!=NULL && strcmp(saca.tipo,auxS->tipo)>0){ ///como esta ordenado por tipo de comb, puedo parar la busqueda cuando supere alfabeticamente
            auxS=auxS->sig;
        }
        if (auxS!=NULL && strcmp(saca.tipo,auxS->tipo)==0 && saca.litros<=auxS->disp){ ///si el tipo coincide y hay diponibilidad
            colocado=1;
            auxS->disp-=saca.litros;
        }else
            colocado=0;

        if (auxL->sig!=NULL)
            auxL=auxL->sig; ///coloque o no debo pasar al siguiente surtidor
        else ///si llego al final vuelvo a comenzar
            auxL=L;

        if (ini==auxL && !colocado){ ///si despues de moverme, llego a la posicion inicial y no pude colocar en ningun surtidor: saco un nuevo auto
            //en este if tambien hay que preguntar si la cola esta vacia
            sacaC(C,&saca);
            noAtendidos++;
        } ///ini no cambia porque si no coloque mi punto de partida para la busqueda es el mismo
        //en el else habria que poner colocado = 0 porque sino itera infinitamente, debido a la condicion del while
    }

    if (noAtendidos)
        printf("No se han podido atender %d autos!\n",noAtendidos);
    else
        printf("Se han atendido todos los autos!\n");
}

void eliminaTC(TLista L,char TC[3]){ ///PUNTO 1)b)
    TLista auxL=L; TSublista antS,actS,elim; float sumLt=0; int noTenian=0;

    while (auxL!=NULL){
        if (auxL->num%2==0){///si el numero de surtidor es par busco
            actS=auxL->comb;antS=NULL;
            while (actS!=NULL && strcmp(TC,actS->tipo)>0){ ///mientras no llego al final y el nombre del comb es menor al que busco
                antS=actS;
                actS=actS->sig;
            }

            if (actS!=NULL && strcmp(TC,actS->tipo)==0){ ///si encuentro el codigo, debo eliminar
                if (actS->disp>0)
                    sumLt+=actS->disp;
                else
                    noTenian++; ///si el tanque de TC estaba vacio cuento

                elim=actS;
                actS=actS->sig;
                if (antS==NULL) ///caso cabeza!
                    auxL->comb=actS;
                else
                    antS->sig=actS;
                free(elim);
            }else ///si el tanque no existe tambien cuento
                noTenian++;
        }
        auxL=auxL->sig; ///paso al siguiente surtidor
    }

    printf("Se han vaciado %f litros de los tanques\n",sumLt);
    printf("%d surtidores debian tener el combustible %s y no lo tenian\n",noTenian,TC);
}
