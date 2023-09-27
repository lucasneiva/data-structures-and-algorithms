#include<stdbool.h>
#include<stdlib.h>

typedef struct RegItem
{
   int valor;
   struct RegItem *prox;
} TItem;

typedef struct
{
    TItem *inicio, *final;
} TLista;

void mostrarLista(TLista *, char *);
void iniciarLista(TLista *);
void adicionarItem(TLista *, int);
void removerItem(TLista *, int);



