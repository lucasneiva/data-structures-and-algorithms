#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int key;
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
int append(TList *, int, char);
TNode pop(TList *);
int removeValue(TList *, int);
int isListEmpty(TList *);
int isInList(TList *, int);
TNode *retrieve(TList *, int);
