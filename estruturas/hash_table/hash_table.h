#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct
{
    TList *table;
    size_t tableSize, count;
} THashTable;

void initHashTable(THashTable *);
int hash(int);
int insert(THashTable *, size_t, char);
int delete(THashTable *, size_t);
char lookUp(THashTable *, size_t);
int update(THashTable *, size_t, char);
int searchKey(THashTable *, size_t);
int resize(THashTable *);
int clearTable(THashTable *);




    
