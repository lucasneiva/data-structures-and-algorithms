#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    size_t key;
    char value;
    struct node *link;
} TNode;

typedef struct 
{
    TNode *head, *tail;
    size_t count;
} TList;

void initList(TList *list);
void freeList(TList *);
void printList(TList *, char *);
int append(TList *, size_t, char);
int removeValue(TList *, size_t);
int isListEmpty(TList *);
int isInList(TList *, size_t);
TNode *retrieve(TList *, size_t);
