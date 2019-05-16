/* Q1) Considerando as seguintes declarações de lista encadeada:
        typedef struct lista{
            int info;
            struct lista *prox;
        }TLSE;
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLSE* l); */

#include<stdlib.h>
#include<stdio.h>

typedef struct lista{
    int info;
    struct lista *prox;
}TSLE;

TSLE* inicia_lista(void){
    return NULL;
}
TSLE* insere_inicio(int info, TSLE* l){
    TSLE* novo = (TSLE*)malloc(sizeof(TSLE));
    novo->info = info;
    novo->prox = l;
    return novo;
}

TSLE* insere_fim(int info, TSLE* l){
    if(!l)
        return insere_inicio(info, l);
    l->prox = insere_fim(info, l->prox);
    return l;
}

void imprime(TSLE *l){
    TSLE *p = l;
    while(p){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}
void libera(TSLE *l);
void inverte(TSLE *l){
    TSLE *p = l, *q;
    while(p){
        q = insere_inicio(p->info, q);
        p = p->prox;
    }
    libera(l);
    *l = *q;
}
void libera(TSLE *l){
    TSLE *p = l, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}

int main(void){
    TSLE *lista = inicia_lista();
    lista = insere_fim(1, lista);
    lista = insere_inicio(1, lista);
    lista = insere_inicio(2, lista);
    lista = insere_inicio(3, lista);
    imprime(lista);
    inverte(lista);
    imprime(lista);
    libera(lista);
}