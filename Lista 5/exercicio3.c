/* Q3) Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l
qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o
elemento que está na última posição passa a ser o primeiro quando a lista é deslocada.
Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta
função é o seguinte: TLSE* desloca (TLSE* l, int n). */

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}LISTA;

LISTA* inicializa(void){
    return NULL;
}

LISTA* insere_inicio(int info, LISTA *l){
    LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
    novo->info = info;
    novo->prox = l;
    return novo;
}

LISTA* insere_fim(int info, LISTA *l){
    if(!l)
        return insere_inicio(info, l);
    l->prox = insere_fim(info, l->prox);
    return l;
}

void imprime(LISTA *l){
    LISTA *p = l;
    while(p){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void libera(LISTA *l){
    LISTA *p = l, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}

LISTA* desloca(LISTA* l, int n){
    LISTA *p = l, *q;
    int info;
    if(n%2 == 0){
        info = p->info;
        p = insere_fim(info, p->prox);
        return p;
    }else{
        q = p;
        while(q->prox->prox){
            q = q->prox;
        }
        info = q->prox->info;
        q->prox = NULL;
        p = insere_inicio(info, p);
        return p;
    }
    return NULL;
}

int main(void){
    int n = 0;
    LISTA *lista = inicializa();
    lista = insere_inicio(1, lista);
    lista = insere_inicio(2, lista);
    lista = insere_inicio(3, lista);
    lista = insere_inicio(4, lista);
    lista = insere_inicio(5, lista);
    imprime(lista);
    printf("digite n \n");
    scanf("%d", &n);
    
    while(n != 0){
        imprime(lista);
        printf("deslocou\n");
        lista = desloca(lista, n);
        imprime(lista);
        printf("digite n \n");
        scanf("%d", &n);
    }
    libera(lista);
}