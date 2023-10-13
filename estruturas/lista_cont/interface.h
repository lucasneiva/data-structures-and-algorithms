#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
    int *values;
    size_t length, max_length;

} TList;

int initList(TList *, size_t max_length);
void freeList(TList *);
void printList(TList *, char *);
int append(TList *, int);
int prepend(TList *, int);
int popFront(TList *);
int popEnd(TList *);
int removeValue(TList *, int);
int isListFull(TList *);
int isListEmpty(TList *);