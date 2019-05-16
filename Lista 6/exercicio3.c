/* (c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f,
e modifique a fila original (f) para que ela possua somente os elementos ímpares, respeitando
a ordem de entrada em f. A função deve obedecer o seguinte protótipo: TFila* sep_fila (TFila
*f); */
#include<stdlib.h>
#include"fila.h"
#include"pilha.h"

Fila* sep_fila (Fila *f){
    int info;
    Fila *par = inicializa_fila(), *impar = inicializa_fila();
    while(!fila_vazia(f)){
        info = retira(f);
        if(info % 2 == 0){
            insere(par, info);
        }else{
            insere(impar, info);
        }
    }
    while(!fila_vazia(impar)){
        insere(f, retira(impar));
    }
    return par;
}
int main(void){
    Fila *f = inicializa_fila();
    Fila *f_par = inicializa_fila();

    insere(f, 1);
    insere(f, 10);
    insere(f, 3);
    insere(f, 4);
    insere(f, 50);
    insere(f, 6);
    insere(f, 7);
    insere(f, 8);

    imprime_fila(f);
    f_par = sep_fila(f);
    imprime_fila(f_par);
    imprime_fila(f);
    return 1;
}