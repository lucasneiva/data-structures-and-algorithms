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
char verTopo(TPilha *);

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

char verTopo(TPilha *pilha) {
    return pilha->letras[pilha->final-1];
}