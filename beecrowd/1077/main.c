#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

int ehOperador(char);
int getGrauPrio(char op);
int encProxOp(char *expr, int posAtual);
int proxTemPriori(char *expr, int pos1, int pos2);

int main () {

    int N, cont;
    char expressao[301];
    TPilha operadores, parenteses;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        iniciarPilha(&operadores);
        iniciarPilha(&parenteses);

        scanf("%s", expressao);

        //printf("%d\n", proxTemPriori(expressao, 1, 5));
        //printf("%d\n", ehOperador(':'));

        cont = 0;
        printf("%s -> ", expressao);
        for (int j = 0; j < strlen(expressao) ; j++)
        {
            if (ehOperador(expressao[j]))
            {
                cont++;
                if(proxTemPriori(expressao, j, encProxOp(expressao, j))) {
                    if (!estaVazio(&operadores))
                        printf("%c", expressao[j-1]);
                    
                    push(&operadores, expressao[j]);
                }
                else {
                    
                    if (cont == 1)
                        printf("%c", expressao[j-1]);

                    if (!estaVazio(&operadores))
                    {
                        printf("%c%c%c", expressao[j-1], expressao[j+1], expressao[j]);
                    }
                    else {
                        printf("%c%c", expressao[j+1], expressao[j]);
                    }

                    while (!estaVazio(&operadores))
                        printf("%c", pop(&operadores));
                }
            }

            if (expressao[j] == '(')
                push(&parenteses, '(');
            
            if (expressao[j] == ')')
                pop(&parenteses);

            
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
    default:
        return false;
        break;
    }
}

int encProxOp(char *expr, int posAtual) {
    for (int i = posAtual+1; i < strlen(expr); i++)
        if (ehOperador(expr[i]))
            return i;
    return -1;
}

int proxTemPriori(char *expr, int pos1, int pos2) {
    if (pos2 == -1)
        return false;
    
    for (int i = pos1+1; i < pos2; i++)
    {
        if (expr[i] == '(')
            return true;
        if (expr[i] == ')')
            return false;
    }

    if (getGrauPrio(expr[pos1]) <= getGrauPrio(expr[pos2]))
        return false;
    else
        return true;
    
    
}

int getGrauPrio(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 1;
    case '^':
        return 0;
    default:
        return -1;
        break;
    }
}