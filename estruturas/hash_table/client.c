#include "hash_table.h"
#include <stdio.h>

int main() {

    THashTable hashTable;
    initHashTable(&hashTable);
    
    // Test insert
    insert(&hashTable, 1, 'a');
    insert(&hashTable, 2, 'b');
    
    // Test lookup
    char value = lookUp(&hashTable, 1);
    printf("Value for key 1: %c\n", value);
    
    // Test update
    update(&hashTable, 1, 'z');
    value = lookUp(&hashTable, 1);
    printf("Updated value for key 1: %c\n", value);

    // Test delete
    delete(&hashTable, 2);
    
    // Test search
    int keyExists = searchKey(&hashTable, 1);
    printf("Key 1 exists: %d\n", keyExists);

    keyExists = searchKey(&hashTable, 2);
    printf("Key 2 exists: %d\n", keyExists);

    // Test print
    printHashTable(&hashTable);
    
    // Test resize
    for(int i=0; i<100; i++) {
        insert(&hashTable, i, 'a'+i); 
    }
    
    printHashTable(&hashTable);
    printf("%d", hashTable.size);

    // Test clear
    clearTable(&hashTable);

    return 0;
}