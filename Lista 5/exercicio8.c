/* Q8) Considerando as seguintes declarações de uma lista encadeada:
typedef struct lista{
int mat;
char nome[81];
float cr;
struct lista *prox;
}TLista;
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 e l2
são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se as
listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
(TLista *l1, TLista *l2).
OBS: protótipo de função que pode ser útil: int strcmp (char *s, char *t). */

#include<stdlib.h>
#include<string.h>

typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TLista;

int listatam(TLista *l){
    int i = 0;
    TLista *p = l;
    while(p){
        i++;
        p = p->prox;
    }
    return i;
}

int igual(TLista *l1, TLista *l2){
    TLista *p = l1, *q = l2;
    if(listatam(l1) != listatam(l2)) return 0;
    while(p && q){
        if(p->mat != q->mat) return 0;
        if(!strcmp(p->nome, q->nome)) return 0;
        if(p->cr != p->cr) return 0;
        p = p->prox;
        q = q->prox;
    }
    return 1;
}

TLista* insere_inicio(int mat, char *nome, float cr, TLista* l){
    TLista* novo = (TLista*)malloc(sizeof(TLista));
    novo->mat = mat;
    novo->nome = nome;
    novo->cr = cr;
    novo->prox = l;
    return novo;
}

int main(void){
    return 1;
}

