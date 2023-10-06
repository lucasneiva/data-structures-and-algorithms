#define true 1
#define false 0

typedef struct {
    int valores[1000];
    int final;
} TPilha;

void iniciarPilha(TPilha*);
void push(TPilha*, int);
int pop(TPilha*);
int compTop(TPilha*, TPilha*);
void descarregar(TPilha *, TPilha *);
int estaVazio(TPilha*);
void transferir(TPilha*, TPilha*);
void inverter(TPilha*);
void printPilha(TPilha*, char*);