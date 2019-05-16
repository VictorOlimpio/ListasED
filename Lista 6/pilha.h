#ifndef PILHA_H
#define PILHAH
typedef struct pilha Pilha;
Pilha *inicializa_pilha(void);
int pilha_vazia(Pilha *p);
void push(Pilha *p, int info);
int pop(Pilha *p);
void libera(Pilha *p);
void imprime_pilha(Pilha *p);
#endif