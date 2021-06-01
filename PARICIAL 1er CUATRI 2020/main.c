#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piladim.h"

typedef struct nodo{
    char legajo[6];
    char facultad[5];
    TPila materias;
    struct nodo *ant,* sig;} nodo;
typedef nodo * Pnodo;
typedef struct{
    Pnodo pri, ult;} TListaD;

int main()
{
    return 0;
}


void eliminaAprobadas(TListaD *L){
    Pnodo aux=L->pri; char legajo[6];char facultad[5];char cod[5];
    TPila pAux; iniciaP(&pAux);TElementoP saca;
    scanf("%s",legajo);
    scanf("%s",facultad);
    scanf("%s",cod);

    if (L->pri!=NULL){
        while(aux!=NULL && strcmp(legajo,aux->legajo)!=0 && strcmp(facultad,aux->facultad)!=0){
            aux=aux->sig;
        }
        if (aux!=NULL){ ///encontre legajo y facultad
            if (!vaciaP(aux->materias)){ ///aca valido porque es un do y no un while
                do{
                    sacaP(&aux->materias,&saca); ///saco de la píla hasta que encontre o me quedo sin elementos en la pila
                    poneP(&pAux,saca);
                }while(!vaciaP(aux->materias) && strcmp(cod,saca.cod)>0); ///ojo, la materia en el tope de pAux es la aprobada o la ultima
            }
            if (!vaciaP(pAux) && strcmp(cod,saca.cod)==0){ ///q la pila auxiliar no este vacia implica que la original tampoco lo estaba
                sacaP(&pAux,&saca); ///saco la aprobada
            }

            while (!vaciaP(pAux)){ ///vuelvo a poner el resto de las materias en la pila original
                sacaP(&pAux,&saca);
                poneP(aux->materias,saca);
            }

            if (!vaciaP(aux->materias)){ ///si queda la pila vacia
                if (aux->sig==NULL && aux->ant==NULL){///solo hay un elemento en la lista
                    L->pri=NULL;
                    L->ult=NULL;
                    }else{
                        if (aux->ant==NULL){ ///si elimino el primero
                            L->pri=aux->sig;
                            aux->sig->ant=NULL;
                        }else{
                            if(aux->sig==NULL){ ///si elimino el ultimo
                                L->ult=aux->ant;
                                aux->ant->sig=NULL;
                            }else{ ///si elimino un intermedio
                                aux->ant->sig=aux->sig;
                                aux->sig->ant = aux->ant;}}
                }
                free(aux);
            }
        }
    }
}

void masMaterias(TListaD L){
    Pnodo aux=L.pri;char l1[6],l2[6];int max1=0;int max2=0;int pendiente;
    TPila pAux;TElementoP saca;
    if (L.pri){
        while(aux!=NULL){
            pendiente=0;
            while(!vaciaP(aux->materias)){
                sacaP(&aux->materias,&saca);
                poneP(&pAux,saca)
                pendiente++;
            }
            if (pendiente>max1){ ///si es mayor a todos
                if (strcmp(aux->legajo,l1)=!0){ ///si la persona que ocupa el primer puesto es distinta a la que ya esta
                    max2=max1; ///muevo maximo al segundo puesto
                    strcpy(l2,l1);
                    strcpy(l1,aux->legajo);
                }
                max1=pendiente;
            }else
                if(pendiente>max2){ ///si solo es mayor al segundo puesto
                    if (strcmp(aux->legajo,l2)!=0)///si es una persona distinta, cambio valor y nombre
                        strcpy(l2,aux->legajo);
                    max2=pendiente; /// en todos los casos, actualizo el valor max 2
                }
            while(!vaciaP(pAux)){ ///vuelvo a meter las materias en la pila
                sacaP(&pAux,&saca);
                poneP(&aux->materias,saca);
            }
            aux=aux->sig;
        }
        printf("Los dos legajos con mas materias adeudadas son %s y %s con %d y %d materias respectivamente\n",l1,l2,max1,max2);
    }
}

void cuantosAlumnos(TListaD L,char fac[5],char mat[5]){
    Pnodo aux=L.pri; int cuenta=0;
    TPila pAux; TElementoP saca;

    if (L.pri){
        while (aux!=NULL){
            if (strcmp(aux->facultad,fac)==0){
                if (!vaciaP(aux->materias)){
                    do{
                        sacaP(&aux->materias,&saca);
                        poneP(&pAux,saca);
                    }while (!vaciaP(aux->materias && strcmp(mat,saca.cod)>0));}

                if (!vaciaP(pAux) && strcmp(mat,saca.cod)==0){ ///controlo que la pila original no haya estado vacia
                    cuenta++;
                }
                while(!vaciaP(pAux)){ ///vuelvo a llenar la pila
                    sacaP(&pAux,&saca);
                    poneP(&aux->materias,saca);
                }
                }
            aux=aux->sig;
        }
        printf("Hay %d alumnos de la facultad %s que deben la materia %s\n",cuenta,fac,mat);
        }
    }
}
