#include <stddef.h>

#define INITIAL_SIZE 10

typedef struct 
{
    char *data;
    size_t top;
    size_t maxSize;    
} TStack;

int initStack(TStack*);
int isEmpty(TStack*);
void push(TStack*, char);
char pop(TStack*);
char peek(TStack*);
void printStack(TStack*, char*);
