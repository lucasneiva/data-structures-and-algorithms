#include<stdlib.h>
#include<stdio.h>

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


int main() {
    int N;
    char vagao[2];
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
            
            scanf("%s", vagao);
            push(&a, vagao[0]);
        }
        
        for (int i = 0; i < N; i++)
        {
            
            scanf("%s", vagao);
            push(&desejado, vagao[0]);
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

            if (estaVazio(&a) && (!compTop(&aux, &desejado) || estaVazio(&aux)))
            {
                if (!estaVazio(&aux))
                {
                    printf(" Impossible");    
                }
                break;
            }
            
        }
        
        printf("\n");
        
        

    }
    
    return 0;
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
    while (!estaVazio(p))
    {
        printf("%c ", p->letras[--p->final]);   
    }
    printf("\n");
}

