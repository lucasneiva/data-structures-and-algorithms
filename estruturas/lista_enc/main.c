#include<stdlib.h>
#include "cabecalho.h"

int main() {

    TLista l1;

    iniciarLista(&l1);

    for (int i = 0; i < 10; i++)
        adicionarItem(&l1, i);

    removerItem(&l1, 5);
    removerItem(&l1, 0);
    removerItem(&l1, 9);

    adicionarItem(&l1, 10);
    
    mostrarLista(&l1, "Lista 1: ");
    
    return 0;
}