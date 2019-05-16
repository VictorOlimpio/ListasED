/* (d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2); */
#include<stdlib.h>
#include"fila.h"

Fila *junta_filas(Fila *f1, Fila *f2){
    Fila *concat = inicializa_fila(), *f1_aux = inicializa_fila(), *f2_aux = inicializa_fila();
    int info;
    while(!fila_vazia(f1)){
        info = retira(f1);
        insere(concat, info);
        insere(f1_aux, info);
    }
    while(!fila_vazia(f2)){
        info = retira(f2);
        insere(concat, info);
        insere(f2_aux, info);
    }
    while(!fila_vazia(f1_aux)){
        insere(f1, retira(f1_aux));
    }
    while(!fila_vazia(f2_aux)){
        insere(f2, retira(f2_aux));
    }
    return concat;
}

int main(void){
    Fila *f1 = inicializa_fila();
    Fila *f2 = inicializa_fila();
    Fila *concat = inicializa_fila();
    for(int i = 0; i < 5; i++){
        insere(f1, i);
        insere(f2, i);
    }
    imprime_fila(f1);
    imprime_fila(f2);
    concat = junta_filas(f1, f2);
    imprime_fila(concat);
    imprime_fila(f1);
    imprime_fila(f2);
    return 1;
}