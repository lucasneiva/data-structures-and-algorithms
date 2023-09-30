#include<stdio.h>
#include"pilha.h"

int main() {
    TPilha pilha1, pilha2;
    char entrada[] = "OlaMundo";
    
    iniciarPilha(&pilha1);
    iniciarPilha(&pilha2);
    
    // Coloque os caracteres da entrada na pilha1
    for (int i = 0; entrada[i] != '\0'; i++) {
        push(&pilha1, entrada[i]);
    }
    
    printf("Pilha 1: ");
    printPilha(&pilha1, "");
    
    // Transfira elementos da pilha1 para pilha2
    transferir(&pilha1, &pilha2);
    transferir(&pilha1, &pilha2);
    transferir(&pilha1, &pilha2);

    
    printf("Pilha 1 apos transferencia: ");
    printPilha(&pilha1, "");
    printf("Pilha 2 apos transferencia: ");
    printPilha(&pilha2, "");
    
    // Inverta a pilha2
    inverter(&pilha2);
    
    printf("Pilha 2 apos inversao: ");
    printPilha(&pilha2, "");
    
    return 0;
}