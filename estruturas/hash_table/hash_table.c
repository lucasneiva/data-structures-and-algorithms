#include "hash_table.h"
#include <stdlib.h>

int initHashTable(THashTable *hashTable) {
    hashTable->tableSize = 10;

    hashTable->table = malloc(sizeof(TList)*hashTable->tableSize);

    if (hashTable->table == NULL)
        return false;
    
    for (size_t i = 0; i < hashTable->tableSize; i++)
        initList(&hashTable->table[i]);
    
    hashTable->count = 0;

    return true;
}

size_t hash(THashTable *hashTable, size_t key) {
    return key % hashTable->tableSize;
}

int insert(THashTable *hashtable, size_t key, char value) {
    if (searchKey(hashtable, key))
        return false;

    size_t hashcode = hash(hashtable, key);

    if (append(&hashtable->table[hashcode], key, value)) {
        hashtable->count++;
        return true;
    }
    else
        return false;
}



char lookUp(THashTable *hashTable, size_t key) {
    size_t hashcode = hash(hashTable, key);
    TNode *aux;
    aux = retrieve(&hashTable->table[hashcode], key);

    if (aux == NULL)
        return '\0';
    
    return aux->value;
}

int delete(THashTable *hashTable, size_t key) {
    size_t hashcode = hash(hashTable, key);
    
    if (removeValue(&hashTable->table[hashcode], key))
        return true;
    else
        return false;
}

int searchKey(THashTable *hashTable, size_t key) {
    for (size_t i = 0; i < hashTable->tableSize; i++)
    {
        if (isInList(&hashTable->table[i], key))
            return true;
    }
    
    return false;
}

int update(THashTable *hashTable, size_t key, char value) {
    size_t hashcode = hash(hashTable, key);
    TNode *aux;
    aux = retrieve(&hashTable->table[hashcode], key);

    if (aux == NULL)
        return false;
    
    aux->value = value;
    return true;
}

    