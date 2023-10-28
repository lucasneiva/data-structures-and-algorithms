#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int initStack(TStack* p)
{    
    p->data = malloc( sizeof(char) * INITIAL_SIZE);

    if (p->data == NULL) {
        return false;
    }
    else {
        p->top = 0;
        p->maxSize = INITIAL_SIZE;

        return true;
    }
}

void push(TStack* p, char letra) {
    p->data[p->top++] = letra; 
}

char pop(TStack* p) {
    if (p->top > 0)
        return p->data[--p->top];
    else
        return 0;
}

int isEmpty(TStack* p) {
    if (p->top == 0)
        return true;
    else
        return false;
}

void prinTStack(TStack* p, char* cabec) {
    printf("%s", cabec);
    int aux = p->top;
    while (!isEmpty(p))
    {
        printf("%c ", p->data[--p->top]);   
    }
    p->top = aux;
    printf("\n");
}