#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct {
int valores[1000];
int final;
} TPilha;

void iniciarPilha(TPilha*);
void push(TPilha*, int);
int pop(TPilha*);
int compTop(TPilha*, TPilha*);
void descarregar(TPilha *, TPilha *);
int estaVazio(TPilha*);
void transferir(TPilha*, TPilha*);
void inverter(TPilha*);
void printPilha(TPilha*, char*);

int main() {

TPilha a, b, aux, desejado;
int N, temInput, inAux, ehPossivel, ehPrimeiro;

ehPrimeiro = 1;

while (1)
{
    scanf("%d", &N);

    if (N == 0)
        break;

    temInput = 1;
    
    // if (!ehPrimeiro)
    // {
    //     printf("\n");
        
    // }
    // else
    // {
    //     ehPrimeiro = 0;
    // }
    
    while (temInput)
    {
        iniciarPilha(&a);
        iniciarPilha(&b);
        iniciarPilha(&aux);
        iniciarPilha(&desejado);

        

        for (size_t i = 0; i < N; i++)
        {
            scanf("%d", &inAux);
            if (inAux == 0)
            {
                temInput = 0;
                break;
            }
    
            push(&a, inAux);
        }

        if (!temInput)
            break;

        for (size_t i = N; i > 0; i--)
            push(&desejado, i);

        // inverter(&a);
        inverter(&desejado);
        ehPossivel = 1;
        while (1)
        {    
            if (compTop(&aux, &desejado))
            {
                transferir(&aux, &b);
                pop(&desejado);
                
            }
            else
            {
                transferir(&a, &aux);
            }

            if (estaVazio(&a) && (!compTop(&aux, &desejado) || estaVazio(&aux)))
            {
                if (!estaVazio(&aux))
                {
                    ehPossivel = 0;    
                }
                break;
            }
            
        }
        
        if (ehPossivel)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    
    printf("\n");        
}
    
return 0;
}


void iniciarPilha(TPilha* p) {
p->final = 0;
}

void push(TPilha* p, int valor) {
p->valores[p->final++] = valor; 
}

int pop(TPilha* p) {
if (p->final > 0)
    return p->valores[--p->final];
else
    return 0;
}

int compTop(TPilha* p1, TPilha* p2) {
if (estaVazio(p1) && estaVazio(p2))
    return true;
else if(estaVazio(p1) || estaVazio(p2))
    return false;
else if (p1->valores[p1->final-1] == p2->valores[p2->final-1])
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
while (!estaVazio(p))
{
    printf("%d ", p->valores[--p->final]);   
}
printf("\n");
}

