/* (f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p); */

#include<stdlib.h>
#include"pilha.h"
#include"fila.h"

Fila* p2f (Pilha *p){
    Fila *f = inicializa_fila();
    Pilha *aux = inicializa_pilha();
    int info;
    while(!pilha_vazia(p)){
        info = pop(p);
        insere(f, info);
        push(aux, info);
    }
    while(!pilha_vazia(aux)){
        push(p, pop(aux));
    }
    return f;
}

int main(void){
    Pilha *p = inicializa_pilha();
    Fila *f = inicializa_fila();
    for(int i = 0; i < 10; i++){
        push(p, i);
    }
    imprime_pilha(p);
    f = p2f(p);
    imprime_fila(f);
    imprime_pilha(p);
    return 1;
}