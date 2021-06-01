#define MAX 50
typedef struct{
    char fecha[8];
    char sabor[20];
    int fila,columna;} TElementoCC;
typedef struct {
    TElementoCC dato[MAX];
    int pri, ult; } TColaCC;

void iniciaCC(TColaCC *C);
int vaciaCC(TColaCC C);
void poneCC(TColaCC *C,TElementoCC X);
void sacaCC(TColaCC *C,TElementoCC *C);
TElementoCC consultaCC(TColaCC C);

