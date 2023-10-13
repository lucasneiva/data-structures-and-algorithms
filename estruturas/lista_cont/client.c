#include "interface.h"
#include <stdio.h>

int main() {
    TList myList;
    const size_t max_length = 5;

    if (!initList(&myList, max_length)) {
        printf("Error: Unable to initialize the list.\n");
        return 1;
    }

    printf("Testing List Functions:\n");

    printf("Appending values to the list:\n");
    for (int i = 1; i <= 5; i++) {
        if (append(&myList, i)) {
            printf("Appended: %d\n", i);
        } else {
            printf("Error: List is full. Unable to append %d.\n", i);
        }
    }

    printf("\nList Contents: ");
    printList(&myList, "List:");

    printf("\nPrepending values to the list:\n");
    for (int i = 6; i >= 1; i--) {
        if (prepend(&myList, i)) {
            printf("Prepended: %d\n", i);
        } else {
            printf("Error: List is full. Unable to prepend %d.\n", i);
        }
    }

    printf("\nList Contents: ");
    printList(&myList, "List:");

    printf("\nPopping values from the front of the list:\n");
    while (!isListEmpty(&myList)) {
        int value = popFront(&myList);
        printf("Popped: %d\n", value);
    }

    printf("\nList Contents: ");
    printList(&myList, "List:");

    printf("\nAppending more values to the list:\n");
    for (int i = 1; i <= 7; i++) {
        if (append(&myList, i)) {
            printf("Appended: %d\n", i);
        } else {
            printf("Error: List is full. Unable to append %d.\n", i);
        }
    }

    printf("\nRemoving a value from the list:\n");
    int valueToRemove = 3;
    if (removeValue(&myList, valueToRemove)) {
        printf("Removed: %d\n", valueToRemove);
    } else {
        printf("Error: Value %d not found in the list.\n", valueToRemove);
    }

    printf("\nList Contents: ");
    printList(&myList, "List:");

    printf("\nPopping values from the end of the list:\n");
    while (!isListEmpty(&myList)) {
        int value = popEnd(&myList);
        printf("Popped: %d\n", value);
    }

    freeList(&myList);

    return 0;
}
