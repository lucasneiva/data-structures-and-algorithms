#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

#define INITIAL_SIZE 10
#define LOAD_FACTOR_THRESHOLD 0.8

typedef struct
{
    TList *table;
    size_t size, count;
    float loadFactor;
} THashTable;

int initHashTable(THashTable *);
size_t hash(THashTable *, int);
int insert(THashTable *, int, char);
int delete(THashTable *, int);
char lookUp(THashTable *, int);
int update(THashTable *, int, char);
int searchKey(THashTable *, int);
void printHashTable(THashTable *);
int resize(THashTable *);
void clearTable(THashTable *);
void updateLoadFactor(THashTable *);




    
