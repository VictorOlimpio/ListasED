/* Q2) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2) */

#include<stdlib.h>
#include<stdio.h>

int** cria_matriz(int m, int n){
    if(!m && !n)
        return NULL;
    int **matriz_retorno = (int**) malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++){
        matriz_retorno[i] = (int*) malloc(n * sizeof(int));
    }
    return matriz_retorno;
}

void libera_matriz(int m, int **mat){
    for(int i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
}

void preenche_matriz(int m, int n, int **mat){
    for(int i =0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = (i +1 ) + j;
        }
    }
}

int** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2){
    if(n1 != m2)
        return NULL;
    int **mat_resp = cria_matriz(m1, n2);
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++){
            mat_resp[i][j] = mat1[i][j] * mat2[j][i];
        }
    }
    return mat_resp;
}

void imprime(int m, int n, int **mat){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int m1, n1, m2, n2, **mat1, **mat2;
    printf("digite m1, n1, m2, n2\n");
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);

    mat1 = cria_matriz(m1, n1);
    mat2 = cria_matriz(m2, n2);

    preenche_matriz(m1, n1, mat1);
    preenche_matriz(m2, n2, mat2);

    printf("matriz mat1: \n");
    imprime(m1, n1, mat1);
    printf("matriz mat2: \n");
    imprime(m2, n2, mat2);

    int **resultado = mult(m1, n1, mat1, m2, n2, mat2);

    printf("mat1 x mat2: \n");
    imprime(m1, n2, resultado);
    libera_matriz(m1, mat1);
    libera_matriz(m1, mat2);
    libera_matriz(m1, resultado);
    return 0;
}