
#ifndef FILA_H
#define FILA_H
typedef struct fila Fila;
int fila_vazia(Fila *f);
Fila *inicializa_fila(void);
void insere(Fila *f, int info);
int retira(Fila *f);
void libera_fila(Fila *f);
void imprime_fila(Fila *f);
#endif