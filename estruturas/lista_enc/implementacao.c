#include "cabecalho.h"
#include <stdio.h>

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

    int valor;
    aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    valor = aux->valor;
    return valor;
}

int popEnd(TLista *lista) {
    TItem *aux, *ant;
    if (lista->length > 0)
        lista->length--;
    
    if (lista->length == 0)
    {
        lista->final = NULL;
        lista->inicio = NULL;
        return 0;
    }
    else 
    {
        aux = lista->inicio;
        ant = NULL;
        while (aux->prox != NULL)
        {
            ant = aux;
            aux = aux->prox;
        }


        ant->prox = NULL;
        lista->final = ant;
        
        return lista->final->valor;
    }
    
    
}




