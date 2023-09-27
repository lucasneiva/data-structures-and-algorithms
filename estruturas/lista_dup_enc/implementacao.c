#include "cabecalho.h"
#include <stdio.h>

void iniciarLista(TLista *lista) {
    lista->inicio = NULL;
    lista->final = NULL;
}

void adicionarItem(TLista *lista, int valor) {
    TItem *aux;
    aux = malloc(sizeof(TItem));

    aux->valor = valor;
    aux->prox = NULL;
    aux->ant = NULL;

    if (lista->inicio == NULL)
    {
        lista->inicio = aux;
    }
    else
    {
        lista->final->prox = aux;
        aux->ant = lista->final;
    }
        
    lista->final = aux;
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
    TItem *aux;

    aux = lista->inicio;

    while (aux != NULL)
    {
        if (aux->valor == valor) {
            if (aux->ant == NULL)
            {
                lista->inicio = aux->prox;
                aux->prox->ant = NULL;
            }                
            else if (aux->prox == NULL)
            {
                lista->final = aux->ant;
                aux->ant->prox = NULL;
            }
            else
            {
                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;
            }
        }

        aux = aux->prox;
    }
}


