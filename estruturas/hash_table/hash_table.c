#include "hash_table.h"
#include <stdlib.h>

void initHashTable(THashTable *table) {
    
}

int hash(int key) {
    return key%TABLE_SIZE;
}

int isItemNull(TNode item) {
    if (item.key == NULL && item.key == NULL)
        return true; 
    else
        return false;
}

void insert(THashTable *hashtable, int key, char value) {
    int hashcode = hash(key);
    TNode newItem, *aux, *auxItem;

    newItem.key = key;
    newItem.value = value;
    newItem.next = NULL;

    if (isItemNull(hashtable->table[hashcode]))
    {
        hashtable->table[hashcode] = newItem;
    }
    else
    {
        auxItem = malloc(sizeof(TNode));
        *auxItem = newItem;
        aux = &hashtable->table[hashcode];
        while (aux->next != NULL)
        {
           aux = aux->next;
        }
        aux->next = auxItem;
    }
    
}



char searchValue(THashTable *tabela, int key) {
    int hashcode = hash(key);
    TNode *aux;

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