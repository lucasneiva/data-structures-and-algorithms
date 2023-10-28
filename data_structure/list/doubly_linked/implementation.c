#include "interface.h"
#include <stdio.h>


void initList(TList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

void freeList(TList *list) {
    while (!isListEmpty(list))
        popEnd(list);
}

void printList(TList *list, char *header) {
    TNode *aux;
    aux = list->head;

    printf("%s", header);

    while (aux != NULL) {
        printf(" %d", aux->value);
        aux = aux->next;
    }

    printf("\n");
}

int append(TList *list, int value) {
    TNode *aux;

    aux = malloc(sizeof(TNode));

    if (aux == NULL)
        return false;
     
    aux->value = value;
    aux->next = NULL;
    aux->prev = NULL;

    if (isListEmpty(list))
    {
        list->head = aux;
    }
    else
    {
        list->tail->next = aux;
        aux->prev = list->tail;
    }
        
    list->tail = aux;

    list->count++;
    return true;
}

int prepend(TList *list, int value) {
    TNode *aux;

    aux = malloc(sizeof(TNode));

    if (aux == NULL)
        return false;

    aux->value = value;
    aux->next = NULL;
    aux->prev = NULL;

    if (isListEmpty(list))
    {
        list->tail = aux;
    }
    else
    {
        list->head->prev = aux;
        aux->next = list->head;
    }

    list->head = aux;
    
    list->count++;
    return true;
}

int insert(TList *list, size_t index, int value) {
    TNode *newNode, *aux;

    newNode = malloc(sizeof(TNode));

    newNode->value = value;

    if (newNode == NULL || index > list->count)
        return false;

    aux = list->head;

    for (size_t i = 0; i < index; i++)
        aux = aux->next;
    
    newNode->prev = aux->prev;
    newNode->next = aux;
    aux->prev->next = newNode;
    aux->prev = newNode;
    
    list->count++;
    return true;
}

int popFront(TList *list) {
    TNode *aux;
    int value;

    if (isListEmpty(list))
        return 0;
    
    aux = list->head;

    value = aux->value;

    if (list->count > 1)
    {
        list->head->next->prev = NULL;
        list->head = list->head->next;
    }
    else
    {
        list->head = NULL;
        list->tail = NULL;
    }
    
    free(aux);
    
    list->count--;
    return value;
}

int popEnd(TList *list) {
    TNode *aux;
    int value;

    if (isListEmpty(list))
        return 0;
    
    aux = list->tail;

    value = aux->value;
    
    if (list->count > 1)
    {
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
    }
    else
    {
        list->head = NULL;
        list->tail = NULL;
    }

    free(aux);
    
    list->count--;
    return value;
}

int removeValue(TList *list, int value) {
    TNode *aux;

    aux = list->head;

    while (aux != NULL)
    {
        if (aux->value == value) {
            if (aux->prev == NULL)
            {
                list->head = aux->next;
                aux->next->prev = NULL;
            }  
            else if (aux->next == NULL)
            {
                list->tail = aux->prev;
                aux->prev->next = NULL;
            }
            else
            {
                aux->next->prev = aux->prev;
                aux->prev->next = aux->next;
            }
            value = aux->value;
            free(aux);
            list->count--;
            return true;
        }
        aux = aux->next;
    }
    return false;
}

int isInList(TList *list, int value) {
    TNode *aux;
    aux = list->head;

    for (size_t i = 0; i < list->count; i++)
    {
        if (aux->value == value)
            return true;
        aux = aux->next;
    }
        
    
    return false;
}

int isListEmpty(TList *list) {
    if (list->count == 0)
        return true;
    else
        return false;
}
