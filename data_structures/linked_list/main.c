#include<stdlib.h>
#include "cabecalho.h"
#include<stdio.h>

int main() {

    TLista l1;

    iniciarLista(&l1);

    
    append(&l1, 1);
    append(&l1, 2);
    prepend(&l1, -1);
    prepend(&l1, -2);

    mostrarLista(&l1, "Lista 1: ");

    printf("%d\n", popEnd(&l1));
    printf("%d\n", popEnd(&l1));
    printf("%d\n", popFront(&l1));
    printf("%d\n", popFront(&l1));

    printf("%d\n", popFront(&l1));
    printf("%d\n", popEnd(&l1));

    mostrarLista(&l1, "Lista 1: ");

    return 0;
}