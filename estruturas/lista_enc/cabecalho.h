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
    int length;
} TLista;

void mostrarLista(TLista *, char *);
void iniciarLista(TLista *);
void append(TLista *, int);
void prepend(TLista *, int);
int popFront(TLista *);
int popEnd(TLista *);
void removerItem(TLista *, int);



