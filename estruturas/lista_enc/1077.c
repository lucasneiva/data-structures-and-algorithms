#include "cabecalho.h"
#include <stdio.h>

int main () {

    int N, aux;
    TLista lista;

    while (1)
    {
        scanf("%d", &N);

        if (N == 0) break;

        iniciarLista(&lista);
        for (int i = 1; i <= N; i++)
        {
            prepend(&lista, i);
        }

        printf("Discarded cards: ");
        while (lista.length >= 2)
        {
            mostrarLista(&lista, "Lisata");
            printf("%d, ", popFront(&lista));
            aux = popFront(&lista);
            prepend(&lista, aux);

            
        }

        printf("\nRemaining card: %d\n", popEnd(&lista));
        

    }
    
    return 0;
}