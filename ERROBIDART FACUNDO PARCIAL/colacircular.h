#define MAX 50
typedef struct{
    char patente[8];
    char tipo[3];
    float litros;}TElementoC;
typedef struct {
    TElementoC dato[MAX];
    int pri, ult; } TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC X);
void sacaC(TCola *C,TElementoC *X);
TElementoC consultaC(TCola C);

