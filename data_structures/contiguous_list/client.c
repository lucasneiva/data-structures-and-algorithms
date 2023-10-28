#include "interface.h"
#include <stdio.h>

void testListOperations(TList *list) {
    printf("Testing List Operations:\n");

    // Append some values
    for (int i = 1; i <= 5; i++) {
        append(list, i);
    }

    printf("List Contents after Appending: ");
    printList(list, "List:");

    // Prepend some values
    for (int i = 6; i <= 10; i++) {
        prepend(list, i);
    }

    printf("List Contents after Prepending: ");
    printList(list, "List:");

    // Insert a value at a specific index
    int indexToInsert = 5;
    int valueToInsert = 42;
    insert(list, indexToInsert, valueToInsert);

    printf("List Contents after Insertion: ");
    printList(list, "List:");

    // Remove a specific value
    int valueToRemove = 5;
    removeValue(list, valueToRemove);

    printf("List Contents after Removing %d: ", valueToRemove);
    printList(list, "List:");

    // Pop values from the front
    while (!isListEmpty(list)) {
        int frontValue = popFront(list);
        printf("Popped from Front: %d\n", frontValue);
    }

    // Check if the list is empty
    printf("Is the list empty? %s\n", isListEmpty(list) ? "Yes" : "No");

    freeList(list);
}

int main() {
    TList myList;

    if (!initList(&myList)) {
        printf("Error: Unable to initialize the list.\n");
        return 1;
    }

    testListOperations(&myList);

    return 0;
}
