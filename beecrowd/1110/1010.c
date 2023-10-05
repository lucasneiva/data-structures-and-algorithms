#include <stdio.h>

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




int main () {

    int N, aux;
    TLista lista;

    while (1)
    {
        scanf("%d", &N);

        if (N == 0) break;

        iniciarLista(&lista);
        for (int i = 1; i <= N; i++)
        {
            append(&lista, i);
        }

        printf("Discarded cards:");

        if (lista.length > 1)
        {
            printf(" %d", popFront(&lista));
            aux = popFront(&lista);
            append(&lista, aux);
        }
        
        while (lista.length > 1)
        {
            //mostrarLista(&lista, "Lista: ");
            printf(", %d", popFront(&lista));
            aux = popFront(&lista);
            append(&lista, aux);

            
        }

        printf("\nRemaining card: %d\n", popEnd(&lista));
        

    }
    
    return 0;
}

void iniciarLista(TLista *lista) {
    lista->inicio = NULL;
    lista->final = NULL;
    lista->length = 0;
}

void append(TLista *lista, int valor) {
    TItem *aux;
    aux = malloc(sizeof(TItem));
    lista->length++;
    aux->valor = valor;
    
    aux->prox = NULL;
    

    if (lista->inicio == NULL)
    {
        lista->inicio = aux;
    }
    else
    {
        lista->final->prox = aux;
    }
        
    lista->final = aux;
}

void prepend(TLista *lista, int valor) {
    TItem *aux;
    lista->length++;
    aux = malloc(sizeof(TItem));

    aux->valor = valor;
    
    aux->prox = lista->inicio;
    

    if (lista->inicio == NULL)
    {
        lista->inicio = aux;
        lista->final = aux;
    }
    else
    {
        lista->inicio = aux;
    }
}

void mostrarLista(TLista *lista, char *cabec) {
    TItem *aux;
    aux = lista->inicio;
    printf("%s", cabec);
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void removerItem(TLista *lista, int valor) {
    TItem *aux, *ant;

    aux = lista->inicio;
    ant = NULL;

    while (aux != NULL)
    {
        if (aux->valor == valor) {
            if (ant == NULL)
            {
                lista->inicio = aux->prox;
            }                
            else if (aux->prox == NULL)
            {
                lista->final = ant;
            }
            else
            {
                ant->prox = aux->prox;
            }
        }

        ant = aux;
        aux = aux->prox;
    }
}

int popFront(TLista *lista) {
    TItem *aux;
    if (lista->length > 0)
        lista->length--;
    else
        return -69;
    
    int valor;
    aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    valor = aux->valor;
    return valor;
}

int popEnd(TLista *lista) {
    TItem *aux;
    int valor;
    valor = lista->final->valor;
    if (lista->length > 0)
        lista->length--;
    else
        return -69;

    aux = lista->inicio;
    
    while (aux->prox != lista->final && aux->prox != NULL)
    {
        aux = aux->prox;
    }

    if (lista->length == 0)
    {
        iniciarLista(lista);

        
    }
    else {
        aux->prox = NULL;
        lista->final = aux;

        
    }
    
    return valor;
    
    
    
    
}




