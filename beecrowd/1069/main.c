#include <stdio.h>
#include <string.h>
#include "cabecalho.h"

int main () {

    int N, cont;
    char input[1001];
    TLista lista;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cont = 0;
        scanf("%s", input);
        iniciarLista(&lista);
        for (int j = 0; j < strlen(input); j++) adicionarItem(&lista, input[j]);
        
        //printf("Input: %s\n", input);
        //mostrarLista(&lista, "Lista: ");
        while (removerItem(&lista, '.'));
        //mostrarLista(&lista, "Areia removida: ");
        while (procDima(&lista))
            cont++;
        //mostrarLista(&lista, "Final: ");
        printf("%d\n", cont);
    
    }
    

    return 0;
}