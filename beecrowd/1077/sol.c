#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define true 1
#define false 0

typedef struct {
    char letras[26];
    int final;
} TPilha;

void iniciarPilha(TPilha*);
void push(TPilha*, char);
char pop(TPilha*);
int compTop(TPilha*, TPilha*);
void descarregar(TPilha *, TPilha *);
int estaVazio(TPilha*);
void transferir(TPilha*, TPilha*);
void inverter(TPilha*);
void printPilha(TPilha*, char*);

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
        //printf("%s -> ", expressao);
        for (int j = 0; j < strlen(expressao) ; j++)
        {
            if (ehOperador(expressao[j]))
            {
                cont++;
                if(proxTemPriori(expressao, j, encProxOp(expressao, j))) {
                    if (!estaVazio(&operadores) || cont == 1)
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

void iniciarPilha(TPilha* p) {
    p->final = 0;
}

void push(TPilha* p, char letra) {
    p->letras[p->final++] = letra; 
}

char pop(TPilha* p) {
    if (p->final > 0)
        return p->letras[--p->final];
    else
        return 0;
}

int compTop(TPilha* p1, TPilha* p2) {
    if (estaVazio(p1) && estaVazio(p2))
        return true;
    else if(estaVazio(p1) || estaVazio(p2))
        return false;
    else if (p1->letras[p1->final-1] == p2->letras[p2->final-1])
        return true;
    else
        return false;
}

int estaVazio(TPilha* p) {
    if (p->final == 0)
        return true;
    else
        return false;
}

void transferir(TPilha* pOri, TPilha* pDest) {
    if (!estaVazio(pOri))
        push(pDest, pop(pOri));
}

void inverter(TPilha* p) {
    TPilha aux1, aux2;
    iniciarPilha(&aux1);
    iniciarPilha(&aux2);
    descarregar(p, &aux1);
    descarregar(&aux1, &aux2);
    descarregar(&aux2, p);
}

void descarregar(TPilha *pOrig, TPilha *pDest) {
    while (!estaVazio(pOrig))
    {
        transferir(pOrig, pDest);
    }
}

void printPilha(TPilha* p, char* cabec) {
    printf("%s", cabec);
    int aux = p->final;
    while (!estaVazio(p))
    {
        printf("%c ", p->letras[--p->final]);   
    }
    p->final = aux;
    printf("\n");
}