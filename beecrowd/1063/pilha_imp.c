#include"pilha.h"
#include<stdio.h>

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
    TPilha aux;
    iniciarPilha(&aux);
    while (!estaVazio(p))
    {
        transferir(p, &aux);
    }
    while (!estaVazio(&aux))
    {
        transferir(&aux, p);
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