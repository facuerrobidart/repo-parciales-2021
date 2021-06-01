#define MAX 50
typedef struct{
    char cod[4];
    int id;
    int aut;
    float imp;}TElementoC;
typedef struct {
    TElementoC dato[MAX];
    int pri, ult; } TCola;

void iniciaC(TCola *C);
int vaciaC(TCola C);
void poneC(TCola *C,TElementoC X);
void sacaC(TCola *C,TElementoC *C);
TElementoC consultaC(TCola C);
