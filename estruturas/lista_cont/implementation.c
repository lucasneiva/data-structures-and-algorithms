#include "interface.h"
#include <stdio.h>

int initList(TList *list, size_t max_length) {
    list->values = (int *) malloc(sizeof(int)*max_length);

    if (list->values == NULL)
        return false;
    
    list->length = 0;
    list->max_length = max_length;
    
    return true;
}

void freeList(TList * list) {
    free(list->values);
    list->length = 0;
    list->max_length = 0;
}

void printList(TList *list, char *header) {
    printf("\n%s", header);

    for (size_t i = 0; i < list->length; i++)
        printf(" %d", list->values[i]);

    printf("\n");    
}

int append(TList *list, int value) {
    if (isListFull(list))
        return false;
    
    list->values[list->length] = value;
    list->length++;

    return true;
}

int prepend(TList *list, int value) {
    if (isListFull(list))
        return false;

    if (!isListEmpty(list))
        for (size_t i = list->length; i > 0; i--)
            list->values[i] = list->values[i-1];
    
    list->values[0] = value;

    list->length++;

    return true;
}

int popFront(TList *list) {
    if (isListEmpty(list))
        return 0;
    
    int aux = list->values[0];

    for (size_t i = 1; i < list->length; i++)
        list->values[i-1] = list->values[i]; 
    
    list->length--;
    return aux;
}

int popEnd(TList *list) {
    if (isListEmpty(list))
        return 0;

    return list->values[--list->length];
}

int removeValue(TList *list, int value) {
    if (isListEmpty(list))
        return false;
    
    int index = -1;

    for (size_t i = 0; i < list->length; i++)
        if (list->values[i] == value) {
            index = i;
            break;
        }

    if (index == -1)
        return false;
            
    for (size_t i = index; i < list->length; i++)
        list->values[i] = list->values[i+1];
    
    list->length--;

    return true;
}

int isListFull(TList *list) {  
    if (list->length == list->max_length)
        return true;
    else 
        return false;
}

int isListEmpty(TList *list) {
    if (list->length == 0)
        return true;
    else
        return false;
}

