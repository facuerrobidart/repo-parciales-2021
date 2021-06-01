#define MAX 20
typedef char TElementoC[8];
typedef struct {
    TElementoC dato[MAX];
    int pri, ult; } TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC X);
void sacaC(TCola *C,TElementoC *C);
TElementoC consultaC(TCola C);
