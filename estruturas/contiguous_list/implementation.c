#include "interface.h"
#include <stdio.h>

int isListFull(TList *);
int resizeList(TList *);

int initList(TList *list) {
    list->max_length = 10;
    list->values = (int *) malloc(sizeof(int)*list->max_length);

    if (list->values == NULL)
        return false;
    
    list->length = 0;
    
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
    if (isListFull(list) && !resizeList(list)) {
        return false;
    }
        
    
    list->values[list->length] = value;
    list->length++;

    return true;
}

int prepend(TList *list, int value) {
    if (isListFull(list) && !resizeList(list)) {
        return false;
    }

    if (!isListEmpty(list))
        for (size_t i = list->length; i > 0; i--)
            list->values[i] = list->values[i-1];
    
    list->values[0] = value;

    list->length++;

    return true;
}

int insert(TList *list, size_t index, int value) {
    if (isListFull(list) && !resizeList(list)) {
        return false;
    }

    if (index >= list->length)
        return false;
    
    for (size_t i = list->length; i > index; i--)
            list->values[i] = list->values[i-1];
    
    list->values[index] = value;
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

int isInList(TList *list, int value) {
    for (size_t i = 0; i < list->length; i++)
        if (list->values[i] == value)
            return true;

    return false;
}

int resizeList(TList *list) {
    int *new_block = realloc(list->values, sizeof(int)* list->max_length*2);

    if (new_block != NULL)
    {
        list->values = new_block;
        list->max_length *= 2;
        return true;
    }
    else
    {
        return false;
    }
}

