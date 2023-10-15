#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct
{
    TList *table;
    size_t tableSize, count;
} THashTable;

int initHashTable(THashTable *);
size_t hash(THashTable *, size_t);
int insert(THashTable *, size_t, char);
int delete(THashTable *, size_t);
char lookUp(THashTable *, size_t);
int update(THashTable *, size_t, char);
int searchKey(THashTable *, size_t);
// int resize(THashTable *);
// int clearTable(THashTable *);




    
