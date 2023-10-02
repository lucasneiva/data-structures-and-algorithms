#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct RegItem
{
   char valor;
   struct RegItem *prox;
} TItem;

typedef struct
{
    TItem *inicio, *final;
} TLista;

void mostrarLista(TLista *, char *);
void iniciarLista(TLista *);
void adicionarItem(TLista *, char);
int removerItem(TLista *, char);
int procDima(TLista *);

int main () {

    int N, cont;
    char input[1001];
    TLista lista;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cont = 0;
        scanf("%s", input);
        iniciarLista(&lista);
        for (int j = 0; j < strlen(input); j++) adicionarItem(&lista, input[j]);
        
        //printf("Input: %s\n", input);
        //mostrarLista(&lista, "Lista: ");
        while (removerItem(&lista, '.'));
        //mostrarLista(&lista, "Areia removida: ");
        while (procDima(&lista))
            cont++;
        //mostrarLista(&lista, "Final: ");
        printf("%d\n", cont);
    
    }
    

    return 0;
}

void iniciarLista(TLista *lista) {
    lista->inicio = NULL;
    lista->final = NULL;
}

void adicionarItem(TLista *lista, char valor) {
    TItem *aux;
    aux = malloc(sizeof(TItem));

    aux->valor = valor;
    aux->prox = NULL;

    if (lista->inicio == NULL)
        lista->inicio = aux;
    else
        lista->final->prox = aux;

    lista->final = aux;
}

void mostrarLista(TLista *lista, char *cabec) {
    TItem *aux;
    aux = lista->inicio;
    printf("%s", cabec);
    while (aux != NULL)
    {
        printf("%c ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}


int removerItem(TLista *lista, char valor) {
    TItem *aux, *ant;

    aux = lista->inicio;
    ant = NULL;

    while (aux != NULL)
    {
        if (aux->valor == valor) {
            if (ant == NULL)
                lista->inicio = aux->prox;
            else
            {
                if (aux == lista->final)
                    lista->final = ant;
                ant->prox = aux->prox;

            }
            return true;
        }
                 
        ant = aux;
        aux = aux->prox;
    }

    return false;
}

int procDima(TLista *lista) {
    TItem *aux, *ant;

    aux = lista->inicio;
    ant = NULL;

    
    if(aux == NULL) return false;
    while (aux->prox != NULL)
    {
        if (aux->valor == '<' && aux->prox->valor == '>') {
            if (ant == NULL)
                if(aux->prox->prox != NULL)
                    lista->inicio = aux->prox->prox;
                else
                    lista->inicio = NULL;
            else
            {
                if (aux == lista->final)
                    lista->final = ant;
                
                ant->prox = aux->prox->prox;

            }
            return true;
        }
                 
        ant = aux;
        aux = aux->prox;
    }

    return false;
}