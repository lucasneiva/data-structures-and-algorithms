#include<stdlib.h>
#include<stdio.h>
#include"pilha.h"


int main() {
    int N;
    char vagao;
    TPilha a, b, aux, desejado;

    iniciarPilha(&a);
    iniciarPilha(&b);
    iniciarPilha(&aux);
    iniciarPilha(&desejado);

    while (true)
    {
        scanf("%d", &N);

        if (N <= 0)
            break;
        
        iniciarPilha(&a);
        iniciarPilha(&b);
        iniciarPilha(&aux);
        iniciarPilha(&desejado);

        for (int i = 0; i < N; i++)
        {
            getchar();
            scanf("%c", &vagao);
            push(&a, vagao);
        }
        
        for (int i = 0; i < N; i++)
        {
            getchar();
            scanf("%c", &vagao);
            push(&desejado, vagao);
        }
        
        inverter(&desejado);
        inverter(&a);

        
        
        while (1)
        {    
            if (compTop(&aux, &desejado))
            {
                transferir(&aux, &b);
                pop(&desejado);
                printf("R");
            }
            else
            {
                transferir(&a, &aux);
                printf("I");
            }

            if (estaVazio(&a) && !compTop(&aux, &b))
            {
                printf(" Impossible\n");
                break;
            }
                
        }

        printf("\n");
        printPilha(&a, "A: ");
        printPilha(&aux, "Aux: ");
        printPilha(&b, "B: ");
        printPilha(&desejado, "Desejado: ");
        
        

    }
    
    return 0;
}



