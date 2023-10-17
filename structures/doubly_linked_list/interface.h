#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
   int value;
   struct node *next, *prev;
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
int prepend(TList *, int);
int insert(TList *, size_t, int);
int popFront(TList *);
int popEnd(TList *);
int removeValue(TList *, int);
int isListEmpty(TList *);
int isInList(TList *, int);



