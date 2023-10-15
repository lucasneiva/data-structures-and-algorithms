#include "linked_list.h"
#include <stdio.h>

void initList(TList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void freeList(TList *list) {
    TNode *aux, *ant;

    aux = list->head;

    while (aux != NULL)
    {
        ant = aux;
        aux = aux->link;
        free(ant);
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

int append(TList *list, size_t key, char value) {
    TNode *aux;

    aux = malloc(sizeof(TNode));

    if (aux == NULL)
        return false;
    
    aux->value = value;
    aux->key = key;
    aux->link = NULL;
    

    if (isListEmpty(list))
    {
        list->head = aux;
    }
    else
    {
        list->tail->link = aux;
    }
        
    list->tail = aux;

    list->count++;
    return true;
}

void printList(TList *list, char *header) {
    TNode *aux;

    aux = list->head;

    printf("%s", header);
    while (aux != NULL)
    {
        printf(" - {%d, %c}", aux->key, aux->value);
        aux = aux->link;
    }
    printf("\n");
}

int removeValue(TList *list, size_t key) {
    TNode *aux, *ant;

    aux = list->head;
    ant = NULL;

    while (aux != NULL)
    {
        if (aux->key == key) {
            if (ant == NULL)
            {
                list->head = aux->link;
                list->tail = aux->link;
            }                
            else if (aux->link == NULL)
            {
                list->tail = ant;
            }
            else
            {
                ant->link = aux->link;
            }

            free(aux);
            list->count--;

            
            
            return true;
        }

        ant = aux;
        aux = aux->link;
    }

    return false;
}

int isListEmpty(TList * list) {
    if (list->count == 0)
        return true;
    else
        return false;
}

int isInList(TList *list, size_t key) {
    TNode *aux;

    aux = list->head;

    while (aux != NULL)
    {
        if (aux->key == key)
            return true;

        aux = aux->link;
    }
    
    return false;
}

TNode *retrieve(TList *list, size_t key) {
    TNode *aux;

    aux = list->head;

    while (aux != NULL)
    {
        if (aux->key == key)
            return aux;

        aux = aux->link;
    }
    
    return NULL;
}

TNode pop(TList *list) {
    TNode *aux, tail;

    tail = *list->tail;

    aux = list->head;
    
    list->count--;
    
    while (aux->link != list->tail && aux->link != NULL)
    {
        aux = aux->link;
    }

    if (list->count == 0)
    {
        initList(list);
    }
    else {
        free(aux->link);
        aux->link = NULL;
        list->tail = aux;
    }
    
    
    return tail;    
}
    