#include <stdlib.h>

typedef struct
{
    size_t key;
    char value;
    TNode *link;
} TNode;

typedef struct 
{
    TNode *head, *tail;
    size_t count;
} TList;

void initList(TList *list);
void freeList(TList *);
void printList(TList *, char *);
int append(TList *, int);
int removeValue(TList *, int);
int isListEmpty(TList *);
int isInList(TList *, int);
