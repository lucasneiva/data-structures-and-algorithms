#define TABLE_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct item
{
    int key;
    char value;
    struct item *next;
} TItem;

typedef struct
{
    TItem table[TABLE_SIZE];
} THashTable;

int calcHash(int);
void insertItem(THashTable *, int, char);
char searchValue(THashTable *, int);
void removeItem(THashTable *, int);
void iniTHashTable(THashTable *);


    
