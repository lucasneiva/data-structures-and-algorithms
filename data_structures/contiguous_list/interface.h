#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_LENGTH 10
#define GROWTH_FACTOR 2

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
int isListEmpty(TList *);
int isInList(TList *, int);

