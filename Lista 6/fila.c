#include<stdlib.h>
#include<stdio.h>
#include "fila.h"

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct fila{
    No *inicio, *fim;
}Fila;

int fila_vazia(Fila *f){
    return f->inicio == NULL;
}

Fila *inicializa_fila(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void insere(Fila *f, int info){
    No *novo = (No*)malloc(sizeof(No));
    novo->info = info;
    novo->prox = NULL;

    if(fila_vazia(f)){
        f-> inicio = f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int retira(Fila *f){
    if(fila_vazia(f)){
        exit(1);
    }
    No *q = f->inicio;
    int resp = q->info;
    f->inicio = f->inicio->prox;
    free(q);
    return resp;
}

void libera_fila(Fila *f){
    No *q = f->inicio, *t;
    while(q){
        t = q;
        q = q->prox;
        free(t);
    }
    free(f);
}

void imprime_fila(Fila *f){
    No *q = f->inicio;
    while(q){
        printf("%d ", q->info);
        q = q->prox;
    }
    printf("\n");
}