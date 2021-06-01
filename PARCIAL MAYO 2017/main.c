#include <stdio.h>
#include <stdlib.h>
#include "colaestatica.h"
#include "colacircular.h"
#include <string.h>
typedef struct nodo{
    char sabor[20];
    TCola baldes;
    int gramos,fila,columna;
    struct nodo *sig;}nodo;
typedef nodo *TLista;
typedef struct{
    char sabor;
    int gramos;}THeladera;
int main()
{
    TLista L;
    THeladera M[20][20];
    int cMax,fMax,fila;
    TColaCC tirados;
    char fechaDescarte[8];
    cargaLista(&L);
    printf("Ingrese una fecha para borrar los baldes anteriores con este formato AAAAMMDD\n");
    scanf("%s",fechaDescarte);
    procesoSemanal(M,fechaDescarte,L,&fMax,&cMax,&tirados);
    estadistica(M,fMax,cMax);
    printf("Ingrese una fila a borrar menor a %d o 0 para salir\n");
    scanf("%d",&fila);
    if (fila){
        borraFila(&tirados,fila);
    }
    return 0;
}

void cargaLista(TLista *L){
    TLista aux,ant,act; ///variables para posicionar el nuevo sabor
    int cBaldes; TElementoC fecha; ///variables para la cola de baldes
    *L=NULL; //inicia lista
    FILE * arch = fopen("HELADERA.txt","rt");

    while(!feof(arch)){
        aux = (TLista)malloc(sizeof(nodo));
        fscanf(arch,"%s %d %d %d %d",aux->sabor,aux->gramos,aux->fila,aux->columna,cBaldes);
        iniciaC(&aux->baldes);
        for (int i=1;i<=cBaldes;i++){///LECTURA DE FECHAS
            fscanf(arch,"%s",fecha);
            poneC(&aux->baldes,fecha);
        }
        act=*L;ant=NULL; ///COMIENZA POSICIONAMIENTO
        while(act!=NULL && strcmp(aux->sabor,act->sabor)>0){
            ant=act;
            act=act->sig;
        }///DOS CASOS

        if (!ant){///MODIFICA CABECERA
            aux->sig=*L;
            *L=aux;
        }else{///MEDIO O FINAL
            aux->sig=act;
            ant->sig=aux;
        }
    }
}
void iniciaMatriz(THeladera M[20][20]){
    for(int i=0;i<20;i++){
        M[i][i].sabor=' ';
        M[i][i].gramos=0;
    }
}
void procesoSemanal(THeladera M[20][20],TElementoC fechaDescarte,TLista L,int *fMax,int *cMax,TColaCC *tirados){
    ///PRIMERO RECORRO LA LISTA PARA DETERMINAR LA POSICION
    TLista aux=L; fMax=0; cMax=0; TCola noTira; TElementoC saca;//cola para guardar los que no se tiran
    TElementoCC poneTirados;
    iniciaMatriz(M); iniciaCC(tirados);
    while (aux){
        ///PREGUNTO POR LA DIMENSION DE LA MATRIZ
        if (aux->fila>fMax)
            fMax=aux->fila;
        if (aux->columna>cMax)
            cMax=aux->columna;
        ///LA CARGO
        M[aux->fila-1][aux->columna-1].sabor = aux->sabor;
        M[aux->fila-1][aux->columna-1].gramos = aux->gramos;

        ///BORRADO DE BALDES
        iniciaC(&noTira);
        while(!vaciaC(aux->baldes)){
            sacaC(&aux->baldes,&saca);
            if (strcmp(saca,fechaDescarte)<0){ ///si la fecha es anterior
                poneTirados.columna=aux->columna;
                poneTirados.fila=aux->fila;
                strcpy(poneTirados.sabor,aux->sabor);
                strcpy(poneTirados.fecha,saca);
                poneCC(tirados,poneTirados); /// lo cargo en la cola circular
            }
            else{
                poneC(&noTira,saca); ///si no me lo quedo en la cola auxiliar
            }
        }///cuando me quedo sin baldes
        while (!vaciaC(noTira)){
            sacaC(&noTira,&saca);
            poneC(&aux->baldes,saca);
        } ///los que no se tiran los vuelvo a poner en la cola de la lista

        aux=aux->sig; ///paso al proximo sabor de la lista
    }
}

float promedioColumna(THeladera M[20][20],int i,int j){ ///esto va adentro de un for desde cMax-1 a 0,
    if (i==0)
        return (float) M[i][j].gramos;
    else
        return (float) (promedioColumna(M,i-1,j)*i+M[i][j].gramos)/(i+1);
}

void saborMax(THeladera M[20][20],int i,int j,int *grMax,char nMax[20]){ ///lo mismo con este, calculamos por la columna
    if (i==0){ ///no me gusta llevar las variables de arrastre, pero es la unica manera de salir con un string recursivamente que se me ocurrio
        *grMax = M[i][j].gramos;
        strcpy(nMax,M[i][j].sabor);
    }else{
        saborMax(M,i+1,j,grMax,nMax);
        if (M[i][j].gramos>*grMax){
            *grMax = M[i][j].gramos;
            strcpy(nMax,M[i][j].sabor);
        }
    }
}

void estadistica(THeladera M[20][20],int fMax,int cMax){
    char nMax[8];int grMax;
    for (int j=0;j<cMax;j++){ ///MUESTRO LOS RESULTADOS POR COLUMNA
        printf("El promedio de la columna %d es %6.2f\n",j+1,promedioColumna(M,fMax-1,j));
        saborMax(M,fMax-1,j,&grMax,nMax);
        printf("El sabor mas consumido es %s con %d gramos\n",nMax,grMax);
    }
}

void borraFila(TColaCC *C,int fila){
    TColaCC aux; iniciaCC(&aux);
    TElementoCC saca; int eliminados=0;
    while (!vaciaCC(*C)){
        sacaCC(C,&saca);
        if (saca.fila!=fila)
            poneCC(&aux,saca); ///si no es de la fila a borrar lo guardo en una cola auxiliar
        else
            eliminados++;
    }

    while (!vaciaCC(aux)){
        sacaCC(&aux,&saca);
        poneCC(C,saca);
    } ///los no eliminados vuelven a la cola

    printf("Se han eliminado %d baldes\n",eliminados);
}
