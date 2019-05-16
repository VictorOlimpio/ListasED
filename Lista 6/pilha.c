#include<stdlib.h>
#include<stdio.h>
#include "pilha.h"

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

Pilha *inicializa_pilha(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int pilha_vazia(Pilha *p){
    return p->topo == NULL;
}

void push(Pilha *p, int info){
    No *novo = (No*)malloc(sizeof(No));
    novo-> info = info;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p){
    if(pilha_vazia(p)){
        exit(1);
    }
    No *q = p->topo;
    int resp = q->info;
    p->topo = q->prox;
    free(q);
    return resp;
}

void libera(Pilha *p){
    No *q = p->topo, *t;
    while(q){
        t = q;
        q = q->prox;
        free(t);
    }
    free(p);
}

void imprime_pilha(Pilha *p){
    No *q = p->topo;
    while(q){
        printf("%d ", q->info);
        q = q->prox;
    }
    printf("\n");
}