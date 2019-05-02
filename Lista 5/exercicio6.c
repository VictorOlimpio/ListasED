/* Q6) Considerando a definição de lista de Q1, escreva uma função em C que, dada uma
lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares
da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta
função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os
pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus
elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l). */

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

Lista* copia(Lista *l1, Lista *l2){
    Lista *p = l1;
    while(p){
        l2 = insere_fim(p->info, l2);
        p = p->prox;
    }
    return l2;
}

void libera(Lista *l){
    Lista *p = l, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}

Lista* i_p(Lista *l){
    Lista *p = l, *impar = inicializa(), *par = inicializa(), *retorno = inicializa();
    while(p){
        if(p->info % 2 != 0){
            impar = insere_fim(p->info, impar);
        }else{
            par = insere_fim(p->info, par);
        }
        p = p->prox;
    }
    retorno = copia(impar, retorno);
    retorno = copia(par, retorno);
    return retorno;
}

int main(void){
    Lista *l = inicializa(), *p = inicializa();
    l = insere_fim(1, l);
    l = insere_fim(2, l);
    l = insere_fim(3, l);
    l = insere_fim(5, l);
    l = insere_fim(8, l);
    imprime(l);
    p = i_p(l);
    imprime(p);
    libera(l);
    libera(p);
}