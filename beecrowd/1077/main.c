#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

int ehOperador(char);
int getPrio(char op);
int encProxOp(char *expr, int posAtual);
int proxTemPriori(char *expr, int pos1, int pos2);

int main () {

    int N;
    char aux;
    char expressao[301];
    TPilha pilha;

    scanf("%d", &N);

        
    for (int i = 0; i < N; i++)
    {
        iniciarPilha(&pilha);

        scanf("%s", expressao);

        printf("%s -> ", expressao);
        for (int j = 0; j < strlen(expressao) ; j++)
        {
            
            
            if (expressao[j] == '(')
            {
                push(&pilha, expressao[j]);
            }
            else if(expressao[j] == ')')
            {
                while (1)
                {
                    aux = pop(&pilha);
                    if (aux == '(' || estaVazio(&pilha))
                        break;
                    printf("%c", aux);
                }
            }
            else if(ehOperador(expressao[j]))
            {
                
                while (!estaVazio(&pilha) && getPrio(verTopo(&pilha)) >= getPrio(expressao[j])) {
                        printf("%c", pop(&pilha));
                }
                push(&pilha, expressao[j]);
            }
            else
            {
                printf("%c", expressao[j]);
            }            
            
        }
        while (!estaVazio(&pilha))
        {
            aux = pop(&pilha);
            if (ehOperador(aux))
                printf("%c", aux);
        }
        
        printf("\n");
    }
    
    return 0;
}

int ehOperador(char c) {
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
        break;
    default:
        return false;
        break;
    }
}

int getPrio(char op) {
    switch (op)
    {
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}