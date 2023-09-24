#include<stdlib.h>
#include<stdio.h>

#define true 1
#define false 0

typedef struct {
    char vagoes[26];
    int final;
} Trilho;

void iniciarTrilho(Trilho*);
void insere(Trilho*, char);
char removeVagao(Trilho*);
int comparar(Trilho*, Trilho*);
int estaVazio(Trilho*);
void transferir(Trilho*, Trilho*);
void inverter(Trilho*);
void printTrilho(Trilho*);

int main() {
    int N;
    char vagao;
    Trilho a, b, aux, desejado;

    iniciarTrilho(&a);
    iniciarTrilho(&b);
    iniciarTrilho(&aux);
    iniciarTrilho(&desejado);

    while (true)
    {
        scanf("%d", &N);

        if (N <= 0)
            break;
        
        iniciarTrilho(&a);
        iniciarTrilho(&b);
        iniciarTrilho(&aux);
        iniciarTrilho(&desejado);

        for (int i = 0; i < N; i++)
        {
            getchar();
            scanf("%c", &vagao);
            insere(&a, vagao);
        }
        
        for (int i = 0; i < N; i++)
        {
            getchar();
            scanf("%c", &vagao);
            insere(&desejado, vagao);
        }
        
        inverter(&desejado);
        inverter(&a);

        while (!estaVazio(&a) || aux.final < N)
        {
            transferir(&a, &aux);
            if (comparar(&aux, &desejado))
            {
                transferir(&a, &b);
            }
        }
        

        printTrilho(&a);
        printTrilho(&aux);
        printTrilho(&b);
        printTrilho(&desejado);

    }
    
    return 0;
}

void iniciarTrilho(Trilho* trilho) {
    trilho->final = 0;
}

void insere(Trilho* trilho, char vagao) {
    trilho->vagoes[trilho->final++] = vagao; 
}

char removeVagao(Trilho* trilho) {
    return trilho->vagoes[--trilho->final];
}

int comparar(Trilho* trilho1, Trilho* trilho2) {
    if (estaVazio(trilho1) || estaVazio(trilho2))
        return false;
    
    if (trilho1->vagoes[trilho1->final-1] == trilho2->vagoes[trilho2->final-1])
        return true;
    else
        return false;
}

int estaVazio(Trilho* trilho) {
    if (trilho->final == 0)
        return true;
    else
        return false;
}

void transferir(Trilho* origem, Trilho* destino) {
    insere(destino, removeVagao(origem));
}

void inverter(Trilho* trilho) {
    Trilho aux;
    iniciarTrilho(&aux);
    while (!estaVazio(trilho))
    {
        transferir(trilho, &aux);
    }
    while (!estaVazio(&aux))
    {
        transferir(&aux, trilho);
    }
}

void printTrilho(Trilho* trilho) {
    printf("Trilho: ");
    while (!estaVazio(trilho))
    {
        printf("%c ", trilho->vagoes[--trilho->final]);   
    }
    printf("\n");
}

