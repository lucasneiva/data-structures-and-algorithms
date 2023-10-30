#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initStack(TStack *stack)
{
    stack->top = NULL;
}

int isEmpty(TStack *stack)
{
    return stack->top == NULL ? 1 : 0;
}

int push(TStack *stack, char data)
{
    TItem *newItem = malloc(sizeof(TItem));

    if (newItem == NULL)
        return false;
    
    newItem->data = data;

    if (stack->top == NULL) {
        stack->top = newItem;
    }
    else {
        newItem->link = stack->top;
        stack->top = newItem;   
    }
    
    return true;
}

char pop(TStack *stack) {
    char data;
    
    if (isEmpty(stack)) {
        return  '\0';
    }

    data = stack->top->data;
    TItem *newTop = stack->top->link;
    
    free(stack->top);

    stack->top = newTop;
     
    return data;
}

char peek(TStack *stack) {
    return stack->top->data;
}

void printStack(TStack *stack, char *header) {
    printf("%s", header);

    TItem *aux;

    aux = stack->top;

    while (aux != NULL) {
        printf("%c\n", aux->data);
        aux = aux->link;
    }
}