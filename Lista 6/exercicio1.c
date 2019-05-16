/* (a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f); */
#include<stdlib.h>
#include<stdio.h>
#include "pilha.h"
#include "fila.h"

Pilha *f2p(Fila *f){
    Pilha *p = inicializa_pilha(), *resp = inicializa_pilha();
    while(!fila_vazia(f)){
        push(p, retira(f));
    }
    while(!pilha_vazia(p)){
        push(resp, pop(p));
    }
    return resp;
}

int main(void){
    Pilha *pilha = inicializa_pilha();
    Fila *fila = inicializa_fila();
    insere(fila, 1);
    insere(fila, 2);
    insere(fila, 3);
    insere(fila, 4);
    insere(fila, 5);
    imprime_fila(fila);
    pilha = f2p(fila);
    imprime_pilha(pilha);
    libera_fila(fila);
    libera(pilha);
    return 1;
}



