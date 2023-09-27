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

    if (lista->inicio == NULL)
        lista->inicio = aux;
    else
        lista->final->prox = aux;

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
    TItem *aux, *ant;

    aux = lista->inicio;
    ant = NULL;

    while (aux != NULL)
    {
        if (aux->valor == valor)
            if (ant == NULL)
                lista->inicio = aux->prox;
            else
            {
                if (aux == lista->final)
                    lista->final = ant;
                ant->prox = aux->prox;
            }
                
            
        ant = aux;
        aux = aux->prox;
    }
}


