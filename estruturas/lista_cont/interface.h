#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
    int *values;
    size_t length, max_length;

} TList;

int initList(TList *);
void freeList(TList *);
void printList(TList *, char *);
int append(TList *, int);
int prepend(TList *, int);
int insert(TList *, size_t, int);
int popFront(TList *);
int popEnd(TList *);
int removeValue(TList *, int);
int isListFull(TList *);
int isListEmpty(TList *);
int isInList(TList *, int);

