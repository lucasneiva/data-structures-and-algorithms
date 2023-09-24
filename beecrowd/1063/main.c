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
char remove(Trilho*);
int comparar(Trilho*, Trilho*);
int testarVazio(Trilho*);

int main() {
    int N;
    char vagao;
    Trilho a, b, aux;
    iniciarTrilho(&a);
    iniciarTrilho(&b);
    iniciarTrilho(&aux);

    while (true)
    {
        scanf("%d", &N);

        if (N <= 0)
            break;
        
        for (int i = 0; i < N; i++)
        {
            scanf("%c", &vagao);
            insere(&a, vagao);
        }
        
        for (int i = 0; i < N; i++)
        {
            scanf("%c", &vagao);
            insere(&b, vagao);
        }

        while (!testarVazio(&a))
        {
            remove(&a);
        }
        

    }
    
    return 0;
}

void iniciarTrilho(Trilho* trilho) {
    trilho->final = 0;
}

void insere(Trilho* trilho, char vagao) {
    trilho->vagoes[trilho->final++] = vagao; 
}

char remove(Trilho* trilho) {
    return trilho->vagoes[--trilho->final];
}

int comparar(Trilho* trilho1, Trilho* trilho2) {
    if (testarVazio(&trilho1) || testarVazio(&trilho2))
        return false;
    
    if (trilho1->vagoes[trilho1->final-1] == trilho2->vagoes[trilho2->final-1])
        return true;
    else
        return false;
}

int testarVazio(Trilho* trilho) {
    if (trilho->final == 0)
        return true;
    else
        return false;
}

