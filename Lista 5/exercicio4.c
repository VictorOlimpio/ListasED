/* Q4) Considere a existência de um tipo que representa um aluno numa universidade
hipotética:
                                typedef struct aluno {
                                    int mat;
                                    float cr;
                                    struct aluno *prox;
                                }TAluno;
Escreva uma função que copie uma lista. A lista original deve permanecer inalterada. O
protótipo da função é o seguinte: TAluno *copia (TAluno *l). */
#include<stdio.h>
#include<stdlib.h>
typedef struct aluno{
    int mat;
    float cr;
    struct aluno *prox;
}TAluno;

TAluno* insere_inicio(int mat, float cr, TAluno *aluno){
    TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
    novo->mat = mat;
    novo->cr = cr;
    novo->prox = aluno;
    return novo;
}

TAluno* insere_fim(int mat, float cr, TAluno *aluno){
    if(!aluno)
        return insere_inicio(mat, cr, aluno);
    aluno->prox = insere_fim(mat, cr, aluno->prox);
    return aluno;
}

void imprime(TAluno *aluno){
    TAluno *p = aluno;
    printf("----------\n");
    while(p){
        printf("mat: %d \n", p->mat);
        printf("cr: %0.2f \n", p->cr);
        p = p->prox;
        printf("----------\n");
    }
    printf("\n");
}

void libera(TAluno *aluno){
    TAluno *p = aluno, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
}

TAluno* inicializa(void){
    return NULL;
}

TAluno* copia(TAluno *aluno){
    TAluno *p = aluno, *q = inicializa();
    while(p){
        q = insere_fim(p->mat, p->cr, q);
        p = p->prox;
    }
    return q;
}

int main(void){
    TAluno *laluno = inicializa(), *copia_laluno = inicializa();
    laluno = insere_fim(1, 6, laluno);
    laluno = insere_fim(2, 9, laluno);
    laluno = insere_fim(3, 5, laluno);
    printf("original\n");
    imprime(laluno);
    printf("copiando\n");
    copia_laluno = copia(laluno);
    printf("copia\n");
    imprime(copia_laluno);
    printf("original\n");
    imprime(laluno);
    libera(laluno);
    libera(copia_laluno);
}