/* Q5) Considerando a definição de lista de Q1, escreva uma função em C que remova
todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é
o seguinte: TLSE* rto (TLSE* l, int elem). */
#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* insere_inicio(int info, Lista *l){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = info;
    novo->prox = l;
    return novo;
}

Lista* insere_fim(int info, Lista *l){
    if(!l)
        return insere_inicio(info, l);
    l->prox = insere_fim(info, l->prox);
    return l;
}

Lista* inicializa(void){
    return NULL;
}

void imprime(Lista *l){
    Lista *p = l;
    while(p){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("\n");
}

void libera(Lista *l){
    Lista *p = l, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}

Lista* rto(Lista *l, int elem){
    Lista *anterior = NULL, *p = l, *atual = p;
    while(atual){
        if(atual->info == elem){
            anterior->prox = atual->prox;
        }else{
            anterior = atual;
        }
        atual = atual->prox;
    }
    return p;
}

int main(void){
    Lista *l = inicializa();
    l = insere_fim(1, l);
    l = insere_fim(2, l);
    l = insere_fim(3, l);
    l = insere_fim(2, l);
    l = insere_fim(2, l);
    imprime(l);
    l = rto(l, 2);
    imprime(l);
    libera(l);
}