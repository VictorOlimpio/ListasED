/* (b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f); */

#include<stdlib.h>
#include"pilha.h"
#include"fila.h"

Fila *inv_fila(Fila *f){
    Pilha *p = inicializa_pilha();
    Fila *resp = inicializa_fila(), *aux = f;
    while(!fila_vazia(aux)){
        push(p, retira(aux));
    }
    while(!pilha_vazia(p)){
        insere(resp, pop(p));
    }
    return resp;
}

int main(void){
    Fila *fila = inicializa_fila(), *fila_invertida = inicializa_fila();
    insere(fila, 1);
    insere(fila, 2);
    insere(fila, 3);
    insere(fila, 4);
    insere(fila, 5);
    imprime_fila(fila);
    fila_invertida = inv_fila(fila);
    imprime_fila(fila_invertida);
    imprime_fila(fila);
    return 1;
}