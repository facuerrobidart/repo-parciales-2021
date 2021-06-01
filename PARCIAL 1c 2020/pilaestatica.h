#define MAX 50
typedef struct{
    char zona[3];
    int cod,alto,largo;
    char destinatario[51];
    float peso;}TElementoP;
typedef struct {
TElementoP datos[MAX];
int tope; } TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP* x);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);
void iniciaP (TPila *P);
