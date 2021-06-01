typedef char TElementoC[8];
typedef struct nodo{
    TElementoC dato;
    struct nodo * sig;}nodo;
typedef struct{
    nodo *pri,*ult;}TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC X);
void sacaC(TCola *C,TElementoC *X);
TElementoC consultaC(TCola C);
