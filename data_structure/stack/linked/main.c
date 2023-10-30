#include "stack.h" 
#include <stdio.h>

int main() {
    TStack myStack;
    initStack(&myStack);

    printf("Pushing elements to the stack:\n");
    push(&myStack, 'A');
    push(&myStack, 'B');
    push(&myStack, 'C');

    printStack(&myStack, "Stack: \n");

    printf("\nPeeking top element: %c\n", peek(&myStack));

    printf("\nPopping elements from stack:\n");
    char popped = pop(&myStack);
    printf("Popped: %c\n", popped);

    printStack(&myStack, "Stack after popping: \n");

    return 0;
}