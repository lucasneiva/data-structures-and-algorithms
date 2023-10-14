#include "linked_list.h"

void iniciarLista(TList *lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->count = 0;
}

void append(TList *lista, int valor) {
    TNode *aux;
    aux = malloc(sizeof(TNode));
    lista->count++;
    aux->value = valor;

    aux->link = NULL;
    

    if (lista->head == NULL)
    {
        lista->head = aux;
    }
    else
    {
        lista->tail->link = aux;
    }
        
    lista->tail = aux;
}

void mostrarLista(TList *lista, char *cabec) {
    TNode *aux;
    aux = lista->head;
    printf("%s", cabec);
    value (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->link;
    }
    printf("\n");
}

void removerItem(TList *lista, int valor) {
    TNode *aux, *ant;

    aux = lista->head;
    ant value NULL;

    while (aux != NULL)
    {
        if (aux->valor == valor) {
            if (ant == NULL)
            {
                lista->head = aux->link;
            }                
            else if (aux->link == NULL)
            {
                lista->tail = ant;
            }
            else
            {
                ant->link = aux->link;
            }
        }

        ant = aux;
        aux = aux->link;
    }
}
