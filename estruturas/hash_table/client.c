#include "hash_table.h"
#include <stdio.h>

int main() {

    THashTable table;
    // Test init
    if(!initHashTable(&table)) {
        printf("Init failed!\n");
        return 1;
    }

    // Test resize
    for(int i=1; i<=20; i++) {
        
        printf("Inserting %d\n", i);
        insert(&table, i, 'A'+i);

        if (i%5 == 0)
        {
            printf("Table contents:\n");
            printHashTable(&table); 
        }
        
    }
    
    

    // Insert some keys
    int keys[] = {99, 25, 32, 65, 77};
    for(int i=0; i<5; i++) {
        if(!insert(&table, keys[i], 'A'+i)) {
        printf("Insert %d failed!\n", keys[i]);
        return 1; 
        }
    }

    // Duplicate insert
    if(insert(&table, 12, 'Z')) {
        printf("Inserted duplicate key!\n");
        return 1;
    }

    // Lookup
    for(int i=0; i<5; i++) {
        char val = lookUp(&table, keys[i]);
        if(val != 'A'+i) {
        printf("Lookup %d failed!\n", keys[i]);
        return 1;
        }
    }

    // Lookup non-existing
    if(lookUp(&table, 100) != '\0') {
        printf("Lookup non-existing key failed!\n");
        return 1;
    }

    // Delete 
    if(!delete(&table, 25)) {
        printf("Delete failed!\n");
        return 1;
    }

    // Delete non-existing
    if(delete(&table, 25)) {
        printf("Deleted non-existing key!\n");
        return 1;
    }

    // Search 
    if(!searchKey(&table, 19)) {
        printf("Search failed!\n");
        return 1; 
    }

    if(searchKey(&table, 25)) {
        printf("Searched deleted key!\n");
        return 1;
    }

    // Update
    if(!update(&table, 32, 'X')) {
        printf("Update failed!\n");
        return 1;
    }

    // Update non-existing
    if(update(&table, 25, 'Y')) {
        printf("Updated non-existing key!\n");
        return 1;
    }
    printf("Table contents:\n");
    printHashTable(&table); 
    printf("Tests passed!\n");
    
    return 0;


}