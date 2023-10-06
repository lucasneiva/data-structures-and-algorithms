#include "hashtable.h"
#include <stdlib.h>



int calcHash(int key) {
    return key%TABLE_SIZE;
}

int isItemNull(TItem item) {
    if (item.key == NULL && item.key == NULL)
        return TRUE; 
    else
        return FALSE;
}

void insertItem(THashTable *hashtable, int key, char value) {
    int hashcode = calcHash(key);
    TItem newItem, *aux, *auxItem;

    newItem.key = key;
    newItem.value = value;
    newItem.next = NULL;

    if (isItemNull(hashtable->table[hashcode]))
    {
        hashtable->table[hashcode] = newItem;
    }
    else
    {
        auxItem = malloc(sizeof(TItem));
        *auxItem = newItem;
        aux = &hashtable->table[hashcode];
        while (aux->next != NULL)
        {
           aux = aux->next;
        }
        aux->next = auxItem;
    }
    
}

void iniTHashTable(THashTable *tabela) {
    TItem aux;
    aux.key = NULL;
    aux.value = NULL;
    aux.next = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
        tabela->table[i] = aux;
}

char searchValue(THashTable *tabela, int key) {
    int hashcode = calcHash(key);
    TItem *aux;

    if (tabela->table[hashcode].next == NULL)
    {
        return tabela->table[hashcode].value;
    }
    else
    {
        aux = &tabela->table[hashcode];
        while (aux != NULL)
        {
            if (aux->key == key)
            {
                return aux->value;
            }
            
            aux = aux->next;
        }
    }
    return '*';
}

void removeItem(THashTable *tabela, int key) {
}