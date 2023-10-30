typedef struct item
{
    char data;
    struct item *link;
} TItem;

typedef struct
{
    TItem *top;
} TStack;

void initStack(TStack *);
int isEmpty(TStack *);
int push(TStack *, char);
char pop(TStack *);
char peek(TStack *);
void printStack(TStack *, char *);
