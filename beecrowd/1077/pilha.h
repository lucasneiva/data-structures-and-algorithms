#define true 1
#define false 0

typedef struct {
    char letras[26];
    int final;
} TPilha;

void iniciarPilha(TPilha*);
void push(TPilha*, char);
char pop(TPilha*);
int compTop(TPilha*, TPilha*);
void descarregar(TPilha *, TPilha *);
int estaVazio(TPilha*);
void transferir(TPilha*, TPilha*);
void inverter(TPilha*);
void printPilha(TPilha*, char*);
char verTopo(TPilha *);