#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

int initHashTable(THashTable *hashTable) {
    hashTable->table = malloc(sizeof(TList) * INITIAL_SIZE);

    if (hashTable->table == NULL)
        return 0;
    
    hashTable->count = 0;
    hashTable->loadFactor = 0;
    hashTable->size = INITIAL_SIZE;
    
    for (size_t i = 0; i < hashTable->size; i++)
        initList(&hashTable->table[i]);
    
    return 1;
}

size_t hash(THashTable *hashTable, int key) {
    return key % hashTable->size;
}

int insert(THashTable *hashtable, int key, char value) {
    if (searchKey(hashtable, key))
        return 0;

    updateLoadFactor(hashtable);

    if (hashtable->loadFactor >= LOAD_FACTOR_THRESHOLD)
        resize(hashtable);

    size_t hashcode = hash(hashtable, key);
    
    if (append(&hashtable->table[hashcode], key, value) == 0)
        return 0;
    
    hashtable->count++;
    return 1;
}



char lookUp(THashTable *hashTable, int key) {
    TNode *aux;

    size_t hashcode = hash(hashTable, key);
    
    aux = retrieve(&hashTable->table[hashcode], key);

    if (aux == NULL)
        return '\0';
    
    return aux->value;
}

int delete(THashTable *hashTable, int key) {
    size_t hashcode = hash(hashTable, key);
    
    if (removeValue(&hashTable->table[hashcode], key) == 0)
        return 0;
        
    hashTable->count--;
    return 1;
}

int searchKey(THashTable *hashTable, int key) {
    size_t hashcode = hash(hashTable, key);

    if (isInList(&hashTable->table[hashcode], key) == 0)
        return false;
    
    return true;
}

int update(THashTable *hashTable, int key, char value) {
    TNode *aux;

    size_t hashcode = hash(hashTable, key);
    
    aux = retrieve(&hashTable->table[hashcode], key);

    if (aux == NULL)
        return 0;
    
    aux->value = value;
    return 1;
}

void printHashTable(THashTable *hashTable) {
    printf("\n\nSize: %d | Count: %d | Load Factor: %f\n\n", hashTable->size, hashTable->count, hashTable->loadFactor);
    for (size_t i = 0; i < hashTable->size; i++)
    {
        char header[6];
        sprintf(header, "[%d]", i);
        printList(&hashTable->table[i], header);
    }
}

void clearTable(THashTable *hashTable) {
    for (size_t i = 0; i < hashTable->size; i++)
        freeList(&hashTable->table[i]);
    
}

void updateLoadFactor(THashTable *hashTable) {
    hashTable->loadFactor = (float) hashTable->count / hashTable->size;
}

int resize(THashTable *hashTable) {
    TNode node;

    size_t newSize, hashcode;

    newSize = hashTable->size*2;

    TList *newTable = (TList *) malloc(sizeof(TList) * newSize);
    
    if (newTable == NULL)
        return 0;

    for (size_t i = 0; i < newSize; i++)
        initList(&newTable[i]);

    for  (size_t i = 0; i < hashTable->size; i++) {
        while (isListEmpty(&hashTable->table[i]) == 0)
        {
            node = pop(&hashTable->table[i]);
            hashcode = node.key%newSize;
            append(&newTable[hashcode], node.key, node.value); 
        }
    }

    free(hashTable->table);
    hashTable->table = newTable;
    hashTable->size = newSize;
    return 1;
}
