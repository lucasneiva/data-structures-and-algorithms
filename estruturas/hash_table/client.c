#include <stdio.h>
#include "hash_table.h" // Include the header file for your hash table functions

int main() {
    THashTable hashTable;

    // Initialize the hash table
    if (initHashTable(&hashTable)) {
        printf("Hash table initialized successfully.\n");

        // Insert some elements into the hash table
        if (insert(&hashTable, 42, 'A')) {
            printf("Inserted element with key 42.\n");
        } else {
            printf("Failed to insert element.\n");
        }

        // Lookup an element
        char value = lookUp(&hashTable, 42);
        if (value != '\0') {
            printf("Value for key 42 is: %c\n", value);
        } else {
            printf("Key 42 not found.\n");
        }

        // Update an element
        if (update(&hashTable, 42, 'B')) {
            printf("Updated value for key 42.\n");
        } else {
            printf("Failed to update element.\n");
        }

        // Delete an element
        if (delete(&hashTable, 42)) {
            printf("Deleted element with key 42.\n");
        } else {
            printf("Failed to delete element.\n");
        }

        // Search for a key
        int keyExists = searchKey(&hashTable, 42);
        if (keyExists) {
            printf("Key 42 exists in the hash table.\n");
        } else {
            printf("Key 42 does not exist in the hash table.\n");
        }
    } else {
        printf("Failed to initialize the hash table.\n");
    }

    return 0;
}
