#include<stdlib.h>
#include "cabecalho.h"
#include<stdio.h>

int main() {

    TLista l1;

    iniciarLista(&l1);

    
    append(&l1, 1);
    append(&l1, 2);
    popFront(&l1);
    popFront(&l1);
    

    

    append(&l1, 10);
    prepend(&l1, -1);

    mostrarLista(&l1, "Lista 1: ");

    

    
    popFront(&l1);
    popEnd(&l1);

    mostrarLista(&l1, "Lista 1: ");

    return 0;
}