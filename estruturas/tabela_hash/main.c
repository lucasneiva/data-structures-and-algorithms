#include "hashtable.h"
#include <stdio.h>

int main() {
    THashTable tabela;
    iniTHashTable(&tabela);
    insertItem(&tabela, 167, 'a');
    insertItem(&tabela, 169, 'b');
    insertItem(&tabela, 267, 'c');
    printf("%c", searchValue(&tabela, 267));
    return 0;
}