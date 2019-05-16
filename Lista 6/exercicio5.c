/* (e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p); */

#include<stdlib.h>
#include"pilha.h"

void retira_pares (Pilha *p){
    Pilha *impares = inicializa_pilha();
    int info;
    while(!pilha_vazia(p)){
        info = pop(p);
        if (info % 2 != 0)
            push(impares, info);
    }
    while(!pilha_vazia(impares)){
        push(p, pop(impares));
    }
}

int main(void){
    Pilha *p = inicializa_pilha();
    for(int i = 0; i < 10; i++){
        push(p, i);
    }
    imprime_pilha(p);
    retira_pares(p);
    imprime_pilha(p);
    return 1;
}