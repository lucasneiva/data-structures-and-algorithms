#include<stdbool.h>
#include<stdlib.h>

typedef struct RegItem
{
   char valor;
   struct RegItem *prox;
} TItem;

typedef struct
{
    TItem *inicio, *final;
} TLista;

void mostrarLista(TLista *, char *);
void iniciarLista(TLista *);
void adicionarItem(TLista *, char);
int removerItem(TLista *, char);
int procDima(TLista *);


